//HEADER FILE FOR FINAL PROJECT 
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define NUMSAVES 5//set as the maximum number of files that we allow the users to save at the moment
#define IANPASS	"iamnotthecoolone"//password to get to ians account
#define CHRISPASS "iamthecoolone"//password for chris's account

using namespace std;

int fileHandler(void);
class User //this class handles just about everything, i got rid of the game class so that the game could access members of the user such as the scores and the number of tokens.
{
	private:
	public:
		double simonHigh;//highest score achieved in the simon game
		double matchingHigh;//highest score achieved in the matching game
		double score;//the total score that the user has accumulated
		double tokens;//number of tokens, user cannot play a game if they run out of tokens
		int accountType; //1 for guest, 2 for user, 3 for superuser
		virtual void displayInfo(void);//overloaded function that displays information for the user, depending on what type of user it is
		User();//constructor for the guest user class
		~User();//destructor, does not do anything at the moment
		virtual void Play();//plays the game for each user
		int Compare( void );//function to help the functionality of the game 
		void MakeSimon( void );
		void ClearScreen( void );//clears the output screen so the users cant cheat!
		int SimonOutput[100];//make it so that there is only 100 rounds playable by the user
		int UserInput[100];
		int rnd;//keeps track of the round the user is on
		virtual void scoreboard(void);//void function that calls the scoreboard handler
		char array[4][4]; 
		char display[4][4];
		int points;
		void MakeArrays( void );
		void playMemory( void ); 
		void printFullArray( void ); 
		void printHiddenArray( void );
};
class userAccount : public User
{
	private:
	public:
		void scoreboard(void);//overloaded..
		void saveFile(void);//allows the user account access to the file system so they can save their progress
		userAccount();//constructor for the user account class
		void Play( void );//also overloaded so the game can access the members that guest users do not have
		virtual void displayInfo(void);//displays the info.. overloaded
		char username[50];
		void playMemory();
};
class superAccount : public userAccount
{
	private:
		string password;

	public:
		void modify(void);//only function that super user have unique
		void saveFile(void);//different from the user account saveFile..
		void Play( void );//again, different
		void displayInfo(void);
		superAccount();//constructor
		double scoreMultiplier;
		double scoreAdder;
		void playMemory();
};
class scoreEntry
{
	private:
	public:
		int savefiles;//keeps track of the number of save files present in the directory
		void displayBoard(void);//displays the board regardless of how it is sorted
		void sortByScore(void);//sorts according to the "score" parameter loacted in the user class
		void sortBySimon(void); //sorts according to the "simonHigh" parameter loacted in the user class
		void sortByMatching(void);//sorts according to the "matchingHigh" parameter loacted in the user class
		scoreEntry();//constructs the scoreboard class, this constructor allocates the memory needed and checks the file repository
		~scoreEntry();//destructor that will deallocate the memory we needed
		userAccount* userarray;//an ARRAY of user accounts that we will use to sort, and then display the scoreboard
};
