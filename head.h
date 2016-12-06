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

void fileHandler(void);
class User //this class handles just about everything, i got rid of the game class so that the game could access members of the user such as the scores and the number of tokens.
{
	private:
	public:
		//virtual void Play( void );
		double simonHigh;
		double matchingHigh;
		double score;
		double tokens;
		int accountType; //1 for guest, 2 for user, 3 for superuser
		virtual void displayInfo(void);
		User();
		~User();
		virtual void Play();
		int Compare( void ); 
		void MakeSimon( void );
		void ClearScreen( void );
		int SimonOutput[100];
		int UserInput[100];
		int rnd;
		virtual void scoreboard(void);
};
class userAccount : public User
{
	private:
	public:
		void scoreboard(void);
		void saveFile(void);
		void loadFile(void);
		userAccount();
		void Play( void );
		virtual void displayInfo(void);
		char username[50];
};
class superAccount : public userAccount
{
	private:
		string password;

	public:
		void modify(void);
		void saveFile(void);
		void Play( void );
		void displayInfo(void);
		superAccount();
		double scoreMultiplier;
		double scoreAdder;
};
class scoreEntry
{
	private:
	public:
		int savefiles;
		void displayBoard(void);
		void sortByScore(void);
		void sortBySimon(void);
		void sortByMatching(void);
		scoreEntry();
		~scoreEntry();//destructor that will deallocate the memory we needed
		userAccount* userarray;
};

		
