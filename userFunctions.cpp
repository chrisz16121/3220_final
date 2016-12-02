#include "head.h"

User::User(){//default constructor for the guest user class
	score = 0;
	tokens = 10;
	accountType = 1;
	MakeSimon();
}
User::~User(){//destructor for the guest user class
	cout << "Goodbye!" << endl;
}
userAccount::userAccount(){//constructor for the userAccount class
	accountType = 2;
}
superAccount::superAccount(){//constructor for the superUser class
	char userPass[20];
	FILE* fp;
	char fileString[50];
	cout << "Please enter your password:" << endl;
	cin >> userPass;
	if(strcmp(userPass,CHRISPASS) != 0 && strcmp(userPass,IANPASS) != 0){//checks the password, otherwise throws an error and will return to the main menu
		cout << "ERROR ERROR ERROR that is not the correct password!" << endl;
	}
	else if(strcmp(userPass,CHRISPASS) == 0){
		cout << "HELLO CHRIS!!! SO GREAT TO SEE YOU!" << endl;
		sprintf(fileString,"SAVEFILES/chris.txt");
		fp = fopen(fileString,"r");
		fscanf(fp,"%s\n%lf\n%lf",username,&score,&tokens);
		fclose(fp);
	}
	else{
		cout << "Oh... hey Ian" << endl;
		sprintf(fileString,"SAVEFILES/ian.txt");
		fp = fopen(fileString,"r");
		fscanf(fp,"%s\n%lf\n%lf",username,&score,&tokens);
		fclose(fp);
	}
	scoreMultiplier = 1;
	scoreAdder = 0;	
	accountType = 3;
	
}
void User::displayInfo(void){
	cout << "You currently have "<< tokens << " tokens, and your current score is " << score << endl;
}
void userAccount::displayInfo(void){
	cout << "Hello there, " << username << " You currently have " << tokens << " tokens, and your current score is " << score << endl;
}
void superAccount::displayInfo(void){
	cout << "Hello there, " << username << " You currently have " << tokens << " tokens, and your current score is " << score << endl;
	cout << "Your current score multiplier is " << scoreMultiplier << "\n" << scoreAdder << " points will be added to every score you recieve in games" << endl;
	//cout << "HEY THERE! Your a super user aren't you?!?! That means your either the cool dude or the lame one\nPlease, enter your name so we can tell which user you are!!!\nDon't worry, nothing bad will happen if you enter the wrong name!" << endl;//HERES ONE PLACE WE COULD IMPLEMENT EXCEPTION HANDLING
}
void userAccount::saveFile(void){//this allows access to the 5 save files available for normal users
 	fileHandler();
	int userOpt;
	int option;
	char fileString[50];
	while(1){
		cout << "Where do you want your file to be stored?" << endl;	
		cin >> option;
		sprintf(fileString,"SAVEFILES/save%d.txt",option);
		FILE* testFile = fopen(fileString,"r");
		if(testFile != NULL){
			cout << "There already exists a file here, would you like to overwrite it? (1) Yes (2) No" << endl;
			cin >> userOpt;
			while(userOpt != 1 && userOpt != 2){
				cout << "Please try that again user!" << endl;
				cin >> userOpt;
			}
			if(userOpt == 1) break;
			fclose(testFile);
		}
		else break;
	}
	FILE* fp = fopen(fileString,"w");
	fprintf(fp,"%s\n%lf\n%lf",username,score,tokens);	
	fclose(fp); 
}
void superAccount::saveFile(void){//save files for the super account, THERE CAN ONLY BE TWO SUPER ACCOUNTS AND THE FILES ALWAYS EXIST
				//YOU CANNOT DELETE THE SUPER ACCOUNTS OR THE FILES WHERE THE DATA IS STORED OR THE PROGRAM WILL SEGFAULT
	FILE* fp;
	char fileString[50];
	if(strcmp(username,"Ian") == 1) sprintf(fileString,"SAVEFILES/ian.txt");
	else sprintf(fileString,"SAVEFILES/chris.txt");
	fp = fopen(fileString,"w");
	fprintf(fp,"%s\n%lf\n%lf",username,score,tokens);
	fclose(fp);
	cout << "\nYour progress was saved!" << endl;
}
void fileHandler(void){//void function that checks all of the files present in the directory, and will display the usernames in those files
	int num = 5;
	int i = 1;
	char user[50];
	char fileString[10];
	while(i <= num){		
		sprintf(fileString,"SAVEFILES/save%d.txt",i);
		FILE* fp = fopen(fileString,"r");
		if(fp == NULL){
			cout << "Save File " << i << ": Empty file" << endl;
		}
		else{
			fscanf(fp,"%s",user);
			cout << "Save File " << i << ": Saved data present - "<< user << endl;
		}
		i++;
	}
}
void superAccount::modify(void){//this allows the super users to do whatever they wish to their scores and tokens, it also allows them to DELETE other peoples save files just because we are assholes like that sometimes
	int terminator = 0;//another terminator value that gets us out of our menu loop
	int userInput = 1;
	cout << "Hello there super user\nYou are here because you want to change SOMETHING, here's a menu to show what you can do" << endl;
	while(terminator != 1){ //keeps going until the user specifies
		cout << "What do you want to do now?\n1: Set the multiplier\n2: Set the adder\n3: Change your token balance\n4: Change your point total\n5: Delete someone else's account!\n6: Return to the program" << endl;
		cin >> userInput;
		switch(userInput){
			case 1:
				double num1;
				cout << "What do you want your scores to be multiplied by?" << endl;
				cin >> num1;
				scoreMultiplier = num1;
				cout << "Your scores that you recieve in games will now be multiplied by " << scoreMultiplier << endl;
				break;
			case 2: 
				double num2;
				cout << "What do you want to have added to your scores?" << endl;
				cin >> num2;
				scoreAdder = num2;
				cout << "Your scores will now have " << scoreAdder << "points appended after each game" << endl;
				break;
			case 3: 
				double num3;
				cout << "You currently have " << tokens << "how many would you like to add?" << endl;
				cin >> num3;
				tokens = tokens + num3;
				cout << "You now have " << tokens << "tokens" << endl;
				break;
			case 4: 
				double num4;
				cout << "You currently have " << score << "points how many would you like to add?" << endl;
				cin >> num4;
				score = score + num4;
				cout << "You now have " << score << "points" << endl;
				break;
			case 5:
				int num5;
				int fileOption;
				char fileString[20];
				cout << "Are you sure you want to delete someone else's account?!?!?! (1) yes (2) no" << endl;
				cin >> num5;
				while(num5 != 1 && num5 != 2){
					cout << "Please try that again user!" << endl;
					cin >> num5;
				}
				if(num5 == 1){
					fileHandler();
					cout << "Which file would you like to delete?" << endl;
					cin >> fileOption;
					while(fileOption < 1 || fileOption > 5){
						cout << "Please try that again user!" << endl;
						cin >> fileOption;
					}
					sprintf(fileString,"SAVEFILES/save%d.txt",fileOption);
					FILE* fp = fopen(fileString,"r");
					if(fp == NULL){
						cout << "There is no file there!!!" << endl;
						break;
					}
					char deletedUser[50];
					fscanf(fp,"%s",deletedUser);
					fclose(fp);
					remove(fileString);
					cout << "File " << fileOption << "was deleted from the directory, sorry " << deletedUser << "!!!" << endl;
				}
				else{
					break;
				}
				break;
			case 6:
				terminator = 1;
				break;
		}
	}
}

