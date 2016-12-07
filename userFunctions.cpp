#include "head.h"

User::User(){//default constructor for the guest user class
	score = 0;
	tokens = 10;
	accountType = 1;
	MakeSimon();
	MakeArrays();
	points = 0;
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
	while(true){
		cin >> userPass;
		if(strcmp(userPass,CHRISPASS) == 0 || strcmp(userPass,IANPASS) ==0){//checks the password, otherwise throws an error and will return to the main menu
			break;
		}
		else{
			cout << "ERROR ERROR ERROR that is not the correct password!" << endl;
		}
	}
	if(strcmp(userPass,CHRISPASS) == 0){
		cout << "HELLO CHRIS!!! SO GREAT TO SEE YOU!" << endl;//beacuse the program actually enjoys chris using it
		sprintf(fileString,"SAVEFILES/chris.txt");
		fp = fopen(fileString,"r");
		fscanf(fp,"%s\n%lf\n%lf\n%lf\n%lf",username,&score,&tokens,&simonHigh,&matchingHigh);
		fclose(fp);
	}
	else{
		cout << "Oh... hey Ian" << endl;//ian and the program are no longer on speaking terms, will be in a bad mood if ian accesses it
		sprintf(fileString,"SAVEFILES/ian.txt");
		fp = fopen(fileString,"r");
		fscanf(fp,"%s\n%lf\n%lf\n%lf\n%lf",username,&score,&tokens,&simonHigh,&matchingHigh);
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
 	int dummy = fileHandler();
	int userOpt;
	int option;
	char fileString[50];
	while(1){
		cout << "Where do you want your file to be stored?" << endl;	
		while(true){
			cin >> option;
			if(option == 1 || option == 2 || option == 3 || option == 4 || option == 5){
				break;
			}
			else if(cin.fail()){
				cin.clear();
				cin.ignore();
				cout << "Please try that again user!" << endl;
			}
			else if(option < 1 || option > 5){
				cout << "Please try that again user!" << endl;
			}
		}
		sprintf(fileString,"SAVEFILES/save%d.txt",option);
		FILE* testFile = fopen(fileString,"r");
		if(testFile != NULL){
			cout << "There already exists a file here, would you like to overwrite it? (1) Yes (2) No" << endl;
			while(true){
				cin >> userOpt;
				if(userOpt == 1 || userOpt == 2){
					break;
				}
				else if(cin.fail()){
					cin.clear();
					cin.ignore();
					cout << "Please try that again user!" << endl;
				}
				else if(userOpt < 1 || userOpt > 2){
					cout << "Please try that again user!" << endl;
				}
			}
			if(userOpt == 1) break;
			fclose(testFile);
		}
		else break;
	}
	FILE* fp = fopen(fileString,"w");
	fprintf(fp,"%s\n%lf\n%lf\n%lf\n%lf",username,score,tokens,simonHigh,matchingHigh);	
	fclose(fp); 
}
void superAccount::saveFile(void){//save files for the super account, THERE CAN ONLY BE TWO SUPER ACCOUNTS AND THE FILES ALWAYS EXIST
				//YOU CANNOT DELETE THE SUPER ACCOUNTS OR THE FILES WHERE THE DATA IS STORED OR THE PROGRAM WILL SEGFAULT
	FILE* fp;
	char fileString[50];
	if(strcmp(username,"Ian") == 1) sprintf(fileString,"SAVEFILES/ian.txt");
	else sprintf(fileString,"SAVEFILES/chris.txt");
	fp = fopen(fileString,"w");
	fprintf(fp,"%s\n%lf\n%lf\n%lf\n%lf",username,score,tokens,simonHigh,matchingHigh);
	fclose(fp);
	cout << "\nYour progress was saved!" << endl;
}
int fileHandler(void){//void function that checks all of the files present in the directory, and will display the usernames in those files
	int num = 5;
	int numfiles = 0;
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
			numfiles++;
		}
		i++;
	}
	return numfiles;
}
void superAccount::modify(void){//this allows the super users to do whatever they wish to their scores and tokens, it also allows them to DELETE other peoples save files just because we are assholes like that sometimes
	int terminator = 0;//another terminator value that gets us out of our menu loop
	int userInput = 1;
	cout << "Hello there super user\nYou are here because you want to change SOMETHING, here's a menu to show what you can do" << endl;
	while(terminator != 1){ //keeps going until the user specifies
		cout << "What do you want to do now?\n1: Set the multiplier\n2: Set the adder\n3: Change your token balance\n4: Change your point total\n5: Delete someone else's account!\n6: Return to the program" << endl;
		while(true){
			cin >> userInput;
			if(userInput == 1 || userInput == 2 || userInput == 3 || userInput == 4 || userInput == 5 || userInput == 6){
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
				cout << "Your scores will now have " << scoreAdder << " points appended after each game" << endl;
				break;
			case 3: 
				double num3;
				cout << "You currently have " << tokens << " how many would you like to add?" << endl;
				cin >> num3;
				tokens = tokens + num3;
				cout << "You now have " << tokens << " tokens" << endl;
				break;
			case 4: 
				double num4;
				cout << "You currently have " << score << " points how many would you like to add?" << endl;
				cin >> num4;
				score = score + num4;
				cout << "You now have " << score << " points" << endl;
				break;
			case 5:
				int userOpt;
				int fileOption;
				char fileString[20];
				cout << "Are you sure you want to delete someone else's account?!?!?! (1) yes (2) no" << endl;
				while(true){
					cin >> userOpt;
					if(userOpt == 1 || userOpt == 2){
						break;			
					}	
					else if(cin.fail()){
						cin.clear();
						cin.ignore();
						cout << "Please try that again user!" << endl;
					}
					else if(userOpt < 1 || userOpt > 2){
						cout << "Please try that again user!" << endl;
					}
				}
				if(userOpt == 1){
					int dummy;
					dummy = fileHandler();
					cout << "Which file would you like to delete?" << endl;
					while(true){
						cin >> fileOption;
						if(fileOption == 1 || fileOption == 2 || fileOption == 3 || fileOption == 4 || fileOption == 5 || fileOption == 6){
							break;
						}
						else if(cin.fail()){
							cin.clear();
							cin.ignore();
							cout << "Please try that again user!" << endl;
						}
						else if(fileOption < 1 || fileOption > 5){
							cout << "Please try that again user!" << endl;
						}
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
void userAccount::scoreboard(void){//void function that will create a score class, sort it and then display the resulting score board
	int terminator =2;
	int i = 0;		
	int userOpt;
	scoreEntry entry;//function allows the user to sort according to three different choices
		cout << "How do you want to sort the scoreboard?\n1:By total score\n2:By highest Simon Says score\n3:By highest Matching score" << endl;
		while(true){
			cin >> userOpt;
			if(userOpt == 1 || userOpt == 2 || userOpt == 3){
				break;			
			}	
			else if(cin.fail()){
				cin.clear();
				cin.ignore();
				cout << "Please try that again user!" << endl;
			}
			else if(userOpt < 1 || userOpt > 3){
				cout << "Please try that again user!" << endl;
			}
		}
		switch(userOpt){
			case 1: 	
			//	entry.displayBoard();
				entry.sortByScore();//using the member functions of the score entry class 
				entry.displayBoard();//all void functions
				break;
			case 2:
				entry.sortBySimon();
				entry.displayBoard();
				break;
			case 3:
				entry.sortByMatching();
				entry.displayBoard();
				break;
			default:
				break;
		}
	

}
scoreEntry::~scoreEntry(){
	//delete userarray;//this is giving me a compile error... pretty sure it is the only memory i have allocated
}
void User::scoreboard(void){//void function, same as the useraAccount one but it warns the user that guests cannot save their scores. 
	cout << "PLEASE NOTE: Since you are a guest, your scores will not be displayed on this board, to save your scores and have them displayed, you must create an account first!" << endl;
	int terminator =2;
	int i = 0;		
	int userOpt;
	scoreEntry entry;//function allows the user to sort according to three different choices
		cout << "How do you want to sort the scoreboard?\n1:By total score\n2:By highest Simon Says score\n3:By highest Matching score" << endl;
		while(true){
			cin >> userOpt;
			if(userOpt == 1 || userOpt == 2 || userOpt == 3){
				break;			
			}	
			else if(cin.fail()){
				cin.clear();
				cin.ignore();
				cout << "Please try that again user!" << endl;
			}
			else if(userOpt < 1 || userOpt > 3){
				cout << "Please try that again user!" << endl;
			}
		}
		switch(userOpt){
			case 1: 	
			//	entry.displayBoard();
				entry.sortByScore();//using the member functions of the score entry class 
				entry.displayBoard();//all void functions
				break;
			case 2:
				entry.sortBySimon();
				entry.displayBoard();
				break;
			case 3:
				entry.sortByMatching();
				entry.displayBoard();
				break;
			default:
				break;
		}
}
scoreEntry::scoreEntry(){//this is the constructor for the score entry class. It creates an array of all possible users in the memory of the game in order to display their scores publicly
	userarray = new userAccount[NUMSAVES+2];//creates an ARRAY of user accounts that will be sorted and used to display a scoreboard
	int i = 0;
	savefiles=0;
	while(i < NUMSAVES){//first reads all of the possible save files, then later checks for the two super user accounts
		char fileString[20];
		FILE* fp;
		sprintf(fileString,"SAVEFILES/save%d.txt",i+1);
		fp = fopen(fileString,"r");
		if(fp == NULL){
			/*strcpy(userarray[i].username,"NOFILE");//had to use the string copy function instead of directing pointers
			userarray[i].score = 0;
			userarray[i].simonHigh = 0;
			userarray[i].matchingHigh = 0;
			*/
			//cout << "no file" << endl;
		}
		else{
			double dummy;
			fscanf(fp,"%s\n%lf\n%lf\n%lf\n%lf",userarray[savefiles].username,&userarray[savefiles].score,&dummy,&userarray[savefiles].simonHigh,&userarray[savefiles].matchingHigh);//reads in the data from each file 
			//cout << "DATA FOUND: " << userarray[i].username << userarray[i].score << userarray[i].simonHigh << userarray[i].matchingHigh << endl;
	//		fclose(fp);
			savefiles++;
		}
		i++;
	}
	char fileString[50];//now we get the data for the two super users
	FILE* fp;//this data will be handled along with the rest, as well as sorted with everything else.
	double dummy;
	sprintf(fileString,"SAVEFILES/chris.txt");
	fp = fopen(fileString,"r");
	fscanf(fp,"%s\n%lf\n%lf\n%lf\n%lf",userarray[savefiles].username,&userarray[savefiles].score,&dummy,&userarray[savefiles].simonHigh,&userarray[savefiles].matchingHigh);
	//cout << "DATA FOUND: " << userarray[i].username << userarray[i].score << userarray[i].simonHigh << userarray[i].matchingHigh << endl;
	fclose(fp);
	savefiles++;
	sprintf(fileString,"SAVEFILES/ian.txt");
	fp = fopen(fileString,"r");
	fscanf(fp,"%s\n%lf\n%lf\n%lf\n%lf",userarray[savefiles].username,&userarray[savefiles].score,&dummy,&userarray[savefiles].simonHigh,&userarray[savefiles].matchingHigh);
	//cout << "DATA FOUND: " << userarray[i].username << userarray[i].score << userarray[i].simonHigh << userarray[i].matchingHigh << endl;
	fclose(fp);
	
}
void scoreEntry::sortByScore(void){
	int i;
	int j;
	int k;
	userAccount temp;
	/*cout << "BEFORE" << endl;//these were here to check the inputs and outputs of the sorting function
	for(k=0;k<NUMSAVES+2;k++){
		cout << "Score: " << userarray[k].score << endl;
	}
	*/
	for(i=0;i<((savefiles+2)-1);i++){
		for(j=0;j<((savefiles+2)-i-1);j++){
			if(userarray[j].score < userarray[j+1].score){//sorts the data in descending order
				temp = userarray[j];
				userarray[j] = userarray[j+1];
				userarray[j+1] = temp;
				
			}
		}
	}
	/*cout << "AFTER" << endl;
	for(k=0;k<NUMSAVES+2;k++){
		cout << "Score: " << userarray[k].score << endl;
	}
	*/
}
void scoreEntry::sortBySimon(void){
	int i;
	int j;
	int k;
	userAccount temp;
	/*cout << "BEFORE" << endl;
	for(k=0;k<NUMSAVES+2;k++){
		cout << "Score: " << userarray[k].score << endl;
	}
	*/
	for(i=0;i<((savefiles+2)-1);i++){
		for(j=0;j<((savefiles+2)-i-1);j++){
			if(userarray[j].simonHigh < userarray[j+1].simonHigh){
				temp = userarray[j];
				userarray[j] = userarray[j+1];
				userarray[j+1] = temp;
			}
		}
	}
	/*
	cout << "AFTER" << endl;
	for(k=0;k<NUMSAVES+2;k++){
		cout << "Score: " << userarray[k].score << endl;
	}
	*/
}
void scoreEntry::sortByMatching(void){//identical to the other two sorts, this sorts according to the high score in the matching game
	int i;
	int j;
	int k;
	userAccount temp;
	/*cout << "BEFORE" << endl;
	for(k=0;k<NUMSAVES+2;k++){
		cout << "Score: " << userarray[k].score << endl;
	}
	*/
	for(i=0;i<((savefiles+2)-1);i++){
		for(j=0;j<((savefiles+2)-i-1);j++){
			if(userarray[j].matchingHigh < userarray[j+1].matchingHigh){
				temp = userarray[j];
				userarray[j] = userarray[j+1];
				userarray[j+1] = temp;
			}
		}
	}
	/*cout << "AFTER" << endl;
	for(k=0;k<NUMSAVES+2;k++){
		cout << "Score: " << userarray[k].score << endl;
	}
	*/
}
void scoreEntry::displayBoard(void){//void function that displays the members of the array that has been sorted
	int i;
	cout << "\n\n\t\t\t\t\t\t\tSCOREBOARD\n" << endl;
	cout << "\t\tScore\t\tSimon high score\t\tMatching high score\t\tUsername\n" << endl;
	for(i=0;i<(savefiles+1);i++){
		cout << i + 1 << ": " << "\t\t" << userarray[i].score << "\t\t" << userarray[i].simonHigh << "\t\t\t\t" << userarray[i].matchingHigh << "\t\t\t\t" << userarray[i].username << endl;
	}
}
