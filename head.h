//HEADER FILE FOR FINAL PROJECT 
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
using namespace std;
class User 
{
	private:
	public:
		double score;
		double tokens;
		int accountType; //1 for guest, 2 for user, 3 for superuser
		virtual void displayInfo(void);
		void deleteAccount(void);
		void saveFile(void);
		void loadFine(void);
		User();
		//~User();
};
class userAccount : public User
{
	private:
	public:
		virtual void displayInfo(void);
		char username[50];
		userAccount();
};
class superAccount : public userAccount
{
	private:
		string password;
	public:
		//void displayInfo(void);
};

class Game 
{
	private:
	
	public:
		int SimonOutput[100];
		int UserInput[100];
		int rnd;
		Game(void);
		~Game( void );
		virtual void Play( User* );
		int Compare( void ); 
		void MakeSimon( void );
		void ClearScreen( void );
};



		
