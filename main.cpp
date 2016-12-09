#include "head.h"

int main( void ){
	int newuser = 0;
	int noFiles = 0;
	int userORguest;
	int returnORnew;
	int userInput = 0;
	int userFileOpt;
	char* usernameString[50];
	int terminator;//for when the user is done using the program, otherwise the main menu will keep loading
	int loopterm = 0;//these two are to get out of the loops in the two cases below
	int loopterm2 = 0;
	while(terminator != 1){
	loopterm = 0;
	loopterm2 = 0;
	cout << "HELLO USER!!!\nAnd welcome to our arcade!!! Would you like to play as a guest today? (1) yes (2) no\nPSST try entering (3) to see what happens!" << endl;
	while(true){
		cin >> userORguest;
		if(userORguest == 1 || userORguest == 2 || userORguest == 3){
			break;
		}
		else if(cin.fail()){
			cin.clear();
			cin.ignore();
			cout << "Please try that again user!" << endl;
		}
		else if(userORguest < 1 || userORguest > 3){
			cout << "Please try that again user!" << endl;
		}
	}
	if(userORguest == 1){
		User guestUser;
		cout << "So, you are a guest now, you can choose to play either of our two games or leave the program" << endl;
		while(loopterm != 1){
			cout << "What would you like to do now?\n1: Play Simon Says\n2: Play Matching Game\n3: Leave the program\n4: Display your score and tokens\n5: Display the high score board\n6: Return to the main menu" << endl;
			while(true){
		 		cin >> userInput;
				if(userInput == 1 || userInput == 2 || userInput ==3 || userInput == 4 || userInput == 5 || userInput == 6){
				break;
				}
				else if(cin.fail()){
					cin.clear();
					cin.ignore();
					cout << "Please try that again user!" << endl;
				}
				else if(userInput < 1 || userInput > 6){
					cout << "Please try that again user!" << endl;
				}
			}
			switch(userInput){
				case 1:
					cout <<"Today we will be playing Simon!"<<endl
					<<"How to play:"<<endl<<"Input the numbers in the order they appeared"<<endl
					<<"The game will begin in 3 seconds"<<endl;
					sleep(3);
					guestUser.Play();//calling the first of the play methods that we have
					break;
				case 2: 
					cout<<"Welcome to the Memory Matching Game!!!"<<endl
					<<"How to play: "<<endl
					<<"Input coordinates of two matching 'cards' as prompted"<<endl
					<<"Remember the postion of the 'cards'!"<<endl
					<<"Game begins in 5 seconds!!!"<<endl;
					sleep(5);
					guestUser.playMemory();
					break;
				case 3:
					cout << "Goodbye and thanks for using our arcade today!" << endl;
					return 1;
					break;
				case 4: 
					guestUser.displayInfo();//calls the first displayInfo, only the scores and tokens will be printed
					break;
				case 5: 
					guestUser.scoreboard();
					break;
				case 6:
					loopterm = 1;
				default: 
					cout << "This is the default case which should not happen, check the code" << endl;
					break;
			}
		}
					
	}
	else if(userORguest == 2){//the user wants to play as a user account
		userAccount user1;
		cout << "Are you a returning user? (1) yes (2) no" << endl;
		while(true){
			cin >> returnORnew;	
			if(returnORnew == 1 || returnORnew == 2){
				break;
			}
			else if(cin.fail()){
				cin.clear();
				cin.ignore();
				cout << "Please try that again user!" << endl;
			}
			else if(returnORnew < 1 || returnORnew > 2){
				cout << "Please try that again user!" << endl;
			}
		}
		loopterm = 0;
		if(returnORnew == 2){
			newuser = 1;
			try{
				cout << "Please enter a username for yourself" << endl;
				cin >> user1.username;
				if(strcmp(user1.username,"bob") == 0){
					throw 1;
				}
				user1.tokens = 10;
				user1.score = 0;
				user1.displayInfo();
			}
			catch(int){
				cout << "Hey! no ****in' bobs allowed to play!!! you ruined your chances!!!\n**** YOU" << endl;
				return 1;
			}
			catch(...){
				cout << "catch all, terminating" << endl;
				return 1;
			}
		}
		else{	
			try{
				int dummy;
				if((dummy = fileHandler()) == 0){
					throw "ERROR";
				}
				char fileString[50];		
				cout << "Please enter the file you want to open:" << endl;			
				cin >> userFileOpt;
				sprintf(fileString,"SAVEFILES/save%d.txt",userFileOpt);
				FILE* fp = fopen(fileString,"r");
				while(fp == NULL){
					cout << "There is not file present here! Try specfying the file again (-1) to return" << endl;
					cin >> userFileOpt;
					sprintf(fileString,"SAVEFILES/save%d.txt",userFileOpt);
					FILE* fp = fopen(fileString,"r");			
				}
				fscanf(fp,"%s\n%lf\n%lf\n%lf\n%lf",user1.username,&user1.score,&user1.tokens,&user1.simonHigh,&user1.matchingHigh);
				user1.displayInfo();
				fclose(fp);
			}
			catch(...){
				cout << "It appears there are no files in the current directory, you can always make a new account!" << endl;
				noFiles = 1;
			}			 
		}		
		while(loopterm != 1){
			if(noFiles == 1 && newuser != 1){ loopterm = 1; break;}
			cout << "What would you like to do now?\n1: Play Simon Says\n2: Play Matching Game\n3: Leave the program\n4: Display your score and tokens\n5: Display the high score board\n6: Save your progress\n7: Return to the main menu" << endl;
			while(true){
		 		cin >> userInput;
				if(userInput == 1 || userInput == 2 || userInput ==3 || userInput == 4 || userInput == 5 || userInput == 6 || userInput ==7){
				break;
				}
				else if(cin.fail()){
					cin.clear();
					cin.ignore();
					cout << "Please try that again user!" << endl;
				}
				else if(userInput < 1 || userInput > 7){
					cout << "Please try that again user!" << endl;
				}
			}
			switch(userInput){
				case 1:
					cout <<"Today we will be playing Simon!"<<endl
					<<"How to play:"<<endl<<"Input the numbers in the order they appeared"<<endl
					<<"The game will begin in 3 seconds"<<endl;
					sleep(3);
					user1.Play();
					break;
				case 2: 
					cout<<"Welcome to the Memory Matching Game!!!"<<endl
					<<"How to play: "<<endl
					<<"Input coordinates of two matching 'cards' as prompted"<<endl
					<<"Remember the postion of the 'cards'!"<<endl
					<<"Game begins in 5 seconds!!!"<<endl;
					sleep(5);
					user1.playMemory();
					break;
				case 3:
					cout << "Goodbye and thanks for using our arcade today!" << endl;
					return 1;
					break;
				case 4: 
					user1.displayInfo();
					break;
				case 5:
					user1.scoreboard();
					break;
				case 6: 	
					user1.saveFile();
					break;	
				case 7: 
					loopterm = 1;
					break;
				default: 
					cout << "This is the default case which should not happen, check the code" << endl;
					break;
			}
		}
	}
	else{//entering into the domain of the super users... 
		superAccount user2;
		while(loopterm2 != 1){
			cout << "What would you like to do now?\n1: Play Simon Says\n2: Play Matching Game\n3: Leave the program\n4: Display your score and tokens\n5: Display the high score board\n6: Save your progress\n7: Return to the main menu\n8: Edit your account (including scores and tokens)" << endl;
			while(true){
		 		cin >> userInput;
				if(userInput == 1 || userInput == 2 || userInput ==3 || userInput == 4 || userInput == 5 || userInput == 6 || userInput ==7 || userInput == 8){
				break;
				}
				else if(cin.fail()){
					cin.clear();
					cin.ignore();
					cout << "Please try that again user!" << endl;
				}
				else if(userInput < 1 || userInput > 8){
					cout << "Please try that again user!" << endl;
				}
			}
			switch(userInput){
				case 1:
					cout <<"Today we will be playing Simon!"<<endl
					<<"How to play:"<<endl<<"Input the numbers in the order they appeared"<<endl
					<<"The game will begin in 3 seconds"<<endl;
					sleep(3);
					user2.Play();
					break;
				case 2: 
					cout<<"Welcome to the Memory Matching Game!!!"<<endl
					<<"How to play: "<<endl
					<<"Input coordinates of two matching 'cards' as prompted"<<endl
					<<"Remember the postion of the 'cards'!"<<endl
					<<"Game begins in 5 seconds!!!"<<endl;
					sleep(5);
					user2.playMemory();
					break;
				case 3:
					cout << "Goodbye and thanks for using our arcade today!" << endl;
					return 1;
					break;
				case 4: 
					user2.displayInfo();
					break;
				case 5: 
					user2.scoreboard();
					break;
				case 6: 	
					user2.saveFile();
					break;	
				case 7: 
					loopterm2 = 1;
					break;
				case 8:
					user2.modify();//allows us to do whatever we want to the scores and tokens
					break;
				default: 
					cout << "This is the default case which should not happen, check the code" << endl;
					break;
			}
		}
			
	}	
	}
	return 0;
}
