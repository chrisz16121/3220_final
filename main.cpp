#include "head.h"
int main( void ){
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
	cin >> userORguest;
	while(userORguest != 1 && userORguest != 2 && userORguest != 3){
		cout << "Please try that again user!" << endl;
		cin >> userORguest;
	}
	//Game game1;
		
	if(userORguest == 1){
		User guestUser;
		//User* user = &guestUser;
		
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
					guestUser.Play();//calling the first of the play methods that we have
					break;
				case 2: 
					cout << "NEED TO IMPLEMENT A SECOND GAME HERE" << endl;
					break;
				case 3:
					cout << "Goodbye and thanks for using our arcade today!" << endl;
					return 1;
					break;
				case 4: 
					guestUser.displayInfo();//calls the first displayInfo, only the scores and tokens will be printed
					break;
				case 5: 
					break;
				default: 
					cout << "This is the default case which should not happen, check the code" << endl;
					break;
			}
		}
					
	}
	else if(userORguest == 2){
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
			cout << "Please enter the file you want to open:" << endl;			
			fileHandler();
			cin >> userFileOpt;
			sprintf(fileString,"SAVEFILES/save%d.txt",userFileOpt);
			FILE* fp = fopen(fileString,"r");
			fscanf(fp,"%s\n%lf\n%lf",user1.username,&user1.score,&user1.tokens);
			user1.displayInfo();
			fclose(fp);			 
		}
		
		while(loopterm != 1){
			cout << "What would you like to do now?\n1: Play Simon Says\n2: Play OTHERGAME\n3: Leave the program\n4: Display your score and tokens\n5: Save your progress\n6:Return to the main menu" << endl;
			cin >> userInput;
			while(userInput != 1 && userInput != 2 && userInput != 3 && userInput != 4 && userInput != 5 && userInput != 6){
				cout << "Please try that again user!" << endl;
				cin >> userInput;
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
					user1.saveFile();
					break;	
				case 6: 
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
			cout << "What would you like to do now?\n1: Play Simon Says\n2: Play OTHERGAME\n3: Leave the program\n4: Display your score and tokens\n5: Save your progress\n6: Return to the main menu\n7: Edit your account (including scores and tokens)" << endl;
			cin >> userInput;
			while(userInput != 1 && userInput != 2 && userInput != 3 && userInput != 4 && userInput != 5 && userInput != 6){
				cout << "Please try that again user!" << endl;
				cin >> userInput;
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
					cout << "NEED TO IMPLEMENT A SECOND GAME HERE" << endl;
					break;
				case 3:
					cout << "Goodbye and thanks for using our arcade today!" << endl;
					return 1;
					break;
				case 4: 
					user2.displayInfo();
					break;
				case 5: 	
					user2.saveFile();
					break;	
				case 6: 
					loopterm2 = 1;
					break;
				case 7:
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
//Shows the startup screen and plays the game to completion, then shows an exit message
