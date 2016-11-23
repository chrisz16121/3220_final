#include "head.h"
int main( void ){
	int userORguest;
	int returnORnew;
	int userInput = 0;
	char* usernameString[50];

	cout << "HELLO USER!!!\n And welcome to our arcade!!! Would you like to play as a guest today? (1) yes (2) no" << endl;
	cin >> userORguest;
	while(userORguest != 1 && userORguest != 2){
		cout << "Please try that again user!" << endl;
		cin >> userORguest;
	}
	Game game1;
		
	if(userORguest == 1){
		User guestUser;
		User* user = &guestUser;
		
		cout << "So, you are a guest now, you can choose to play either of our two games or leave the program" << endl;
		while(1){
			cout << "What would you like to do now?\n1: Play Simon Says\n2: Play OTHERGAME\n3: Leave the program\n4: Display your score and tokens" << endl;
			cin >> userInput;
			while(userInput != 1 && userInput != 2 && userInput != 3 && userInput != 4 && userInput != 5){
				cout << "Please try that again user!" << endl;
				cin >> userInput;
			}
			switch(userInput){
				case 1:
					cout <<"Today we will be playing Simon!"<<endl
					<<"How to play:"<<endl<<"Input the numbers in the order they appeared"<<endl
					<<"The game will begin in 3 seconds"<<endl;
					sleep(3);
					game1.Play(user);
					break;
				case 2: 
					cout << "NEED TO IMPLEMENT A SECOND GAME HERE" << endl;
					break;
				case 3:
					cout << "Goodbye and thanks for using our arcade today!" << endl;
					return 1;
					break;
				case 4: 
					guestUser.displayInfo();
					break;
				default: 
					cout << "This is the default case which should not happen, check the code" << endl;
					break;
			}
		}
					
	}
	else{
		userAccount user1;
		//user1.displayInfo();
		cout << "Are you a returning user? (1) yes (2) no" << endl;
		cin >> returnORnew;
		while(returnORnew != 1 && returnORnew != 2){
			cout << "Please try that again user!" <<endl;
			cin >> returnORnew;
		}
		if(returnORnew == 2){
			cout << "Please enter a username for yourself" << endl;
			cin >> user1.username;
			user1.tokens = 10;
			user1.score = 0;
			user1.displayInfo();
		}
		else{	
			char fileString[50];
			string fileString1;			
			cout << "Enter in the file where your data is stored" << endl;
			cin >> fileString;
			FILE* fp = fopen(fileString,"r");
			while(fp == NULL){
				cout << "Could not open the specified file, please try again or enter -1 to quit" << endl;
				cin >> fileString;
				fp = fopen(fileString,"r");
			//	if(fileString == -1) return 1;
			}
			fscanf(fp,"%s\n%lf\n%lf",user1.username,&user1.score,&user1.tokens);
			user1.displayInfo();			 
		}
		
		while(1){
			cout << "What would you like to do now?\n1: Play Simon Says\n2: Play OTHERGAME\n3: Leave the program\n4: Display your score and tokens\n5: Save your progress and exit" << endl;
			cin >> userInput;
			while(userInput != 1 && userInput != 2 && userInput != 3 && userInput != 4){
				cout << "Please try that again user!" << endl;
				cin >> userInput;
			}
			switch(userInput){
				case 1:
					cout <<"Today we will be playing Simon!"<<endl
					<<"How to play:"<<endl<<"Input the numbers in the order they appeared"<<endl
					<<"The game will begin in 3 seconds"<<endl;
					sleep(3);
					//game1.Play(user1);
					break;
				case 2: 
					cout << "NEED TO IMPLEMENT A SECOND GAME HERE" << endl;
					break;
				case 3:
					cout << "Goodbye and thanks for using our arcade today!" << endl;
					return 1;
					break;
				case 4: 
					user1.displayInfo();
					break;
				case 5: 	
					cout << "Sorry, we cannot save files at this time" << endl;
					return 1;	
				default: 
					cout << "This is the default case which should not happen, check the code" << endl;
					break;
			}
		}
	}
	
	//userAccount user1;
	//user1.displayInfo();
	return 0;
}
//Shows the startup screen and plays the game to completion, then shows an exit message
User::User(){
	score = 0;
	tokens = 10;
	accountType = 1;
}
//~User::User(){
//	cout << "Goodbye guest!" << endl;
//}
userAccount::userAccount(){
	accountType = 2;
}
void userAccount::displayInfo(void){
	cout << "Hello there, " << username << " You currently have " << tokens << " tokens, and your current score is " << score << endl;
}
void User::displayInfo(void){
	cout << "You currently have " << tokens << " tokens, and your current score is " << score << endl;
}

