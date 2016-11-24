#include "head.h"

User::User(){
	score = 0;
	tokens = 10;
	accountType = 1;
}
User::~User(){
	cout << "Goodbye!" << endl;
}
userAccount::userAccount(){
	accountType = 2;
}
void userAccount::displayInfo(void){
	cout << "Hello there, " << username << " You currently have " << tokens << " tokens, and your current score is " << score << endl;
}
void User::displayInfo(void){
	cout << "You currently have " << tokens << " tokens, and your current score is " << score << endl;
}
void userAccount::saveFile(void){
	int userOpt;
	char fileString[50];
	while(1){
		cout << "Where do you want your file to be stored?" << endl;	
		cin >> fileString;
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
	
