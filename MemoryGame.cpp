#include "head.h"
//lol this game is the longest source file
void User::MakeArrays( void )
{
	
	array[0][0] = '!';
	array[0][1] = '@';
	array[0][2] = '#';
	array[0][3] = '%';
	array[1][0] = '?';
	array[1][1] = '%';
	array[1][2] = '!';
	array[1][3] = '$';
	array[2][0] = '&';
	array[2][1] = '~';
	array[2][2] = '~';
	array[2][3] = '?';
	array[3][0] = '#';
	array[3][1] = '&';
	array[3][2] = '@';
	array[3][3] = '$';
	
	display[0][0] = 'O';
	display[0][1] = 'O';
	display[0][2] = 'O';
	display[0][3] = 'O';
	display[1][0] = 'O';
	display[1][1] = 'O';
	display[1][2] = 'O';
	display[1][3] = 'O';
	display[2][0] = 'O';
	display[2][1] = 'O';
	display[2][2] = 'O';
	display[2][3] = 'O';
	display[3][0] = 'O';
	display[3][1] = 'O';
	display[3][2] = 'O';
	display[3][3] = 'O';
}

void User::printFullArray( void )
{
	cout<<" "<<" "<<"1"<<" "<<"2"<<" "<<"3"<<" "<<"4"<<endl
		<<"1"<<" "<<array[0][0]<<" "<<array[0][1]<<" "<<array[0][2]<<" "<<array[0][3]<<endl
		<<"2"<<" "<<array[1][0]<<" "<<array[1][1]<<" "<<array[1][2]<<" "<<array[1][3]<<endl
		<<"3"<<" "<<array[2][0]<<" "<<array[2][1]<<" "<<array[2][2]<<" "<<array[2][3]<<endl
		<<"4"<<" "<<array[3][0]<<" "<<array[3][1]<<" "<<array[3][2]<<" "<<array[3][3]<<endl;
}

void User::printHiddenArray( void )
{
	cout<<" "<<" "<<"1"<<" "<<"2"<<" "<<"3"<<" "<<"4"<<endl
		<<"1"<<" "<<display[0][0]<<" "<<display[0][1]<<" "<<display[0][2]<<" "<<display[0][3]<<endl
		<<"2"<<" "<<display[1][0]<<" "<<display[1][1]<<" "<<display[1][2]<<" "<<display[1][3]<<endl
		<<"3"<<" "<<display[2][0]<<" "<<display[2][1]<<" "<<display[2][2]<<" "<<display[2][3]<<endl
		<<"4"<<" "<<display[3][0]<<" "<<display[3][1]<<" "<<display[3][2]<<" "<<display[3][3]<<endl;
}
void User::playMemory( void )
{
	int ChoiceRowA;
	int ChoiceColumnA;
	int ChoiceRowB;
	int ChoiceColumnB;
	int error = 0;
	int correct = 0; 
	printFullArray();
	sleep(3);
	ClearScreen(); 
	
	while( error != 1 )
	{
		printHiddenArray();
		
		cout<<"Enter the coordinates of the first 'card'. (Row, then Column)"<<endl;
		while(true){
			cin >> ChoiceRowA;
			if(ChoiceRowA == 1 || ChoiceRowA == 2 || ChoiceRowA == 3 || ChoiceRowA == 4){
				break;
			}
			else if(cin.fail()){
				cin.clear();
				cin.ignore();
				cout << "Please try that again user!" << endl;
			}
			else if(ChoiceRowA < 1 || ChoiceRowA > 4){
				cout << "Please try that again user!" << endl;
			}
		}
		while(true){
			cin >> ChoiceColumnA;
			if(ChoiceColumnA == 1 || ChoiceColumnA == 2 || ChoiceColumnA == 3 || ChoiceColumnA == 4){
				break;
			}
			else if(cin.fail()){
				cin.clear();
				cin.ignore();
				cout << "Please try that again user!" << endl;
			}
			else if(ChoiceColumnA < 1 || ChoiceColumnA > 4){
				cout << "Please try that again user!" << endl;
			}
		}
		ChoiceRowA = ChoiceRowA - 1;
		ChoiceColumnA = ChoiceColumnA - 1;
		while( display[ChoiceRowA][ChoiceColumnA] == 'X' || ChoiceRowA > 3 || ChoiceRowA < 0 || ChoiceColumnA > 3 || ChoiceColumnA < 0 )
		{
			cout<<"INVALID CHOICE!!! Please re-enter coordinates. (Row, then Column)"<<endl;
			while(true){
				cin >> ChoiceRowA;
				if(ChoiceRowA == 1 || ChoiceRowA == 2 || ChoiceRowA == 3 || ChoiceRowA == 4){
					break;
				}
				else if(cin.fail()){
					cin.clear();
					cin.ignore();
					cout << "Please try that again user!" << endl;
				}
				else if(ChoiceRowA < 1 || ChoiceRowA > 4){
					cout << "Please try that again user!" << endl;
				}
			}
			while(true){
				cin >> ChoiceColumnA;
				if(ChoiceColumnA == 1 || ChoiceColumnA == 2 || ChoiceColumnA == 3 || ChoiceColumnA == 4){
					break;
				}
				else if(cin.fail()){
					cin.clear();
					cin.ignore();
					cout << "Please try that again user!" << endl;
				}
				else if(ChoiceColumnA < 1 || ChoiceColumnA > 4){
					cout << "Please try that again user!" << endl;
				}
			}
			ChoiceRowA = ChoiceRowA - 1;
			ChoiceColumnA = ChoiceColumnA - 1;
		}
		
		cout<<"Now enter the coordinates of the second 'card'. (Row, then Column)"<<endl;
		while(true){
			cin >> ChoiceRowB;
			if(ChoiceRowB == 1 || ChoiceRowB == 2 || ChoiceRowB == 3 || ChoiceRowB == 4){
				break;
			}
			else if(cin.fail()){
				cin.clear();
				cin.ignore();
				cout << "Please try that again user!" << endl;
			}
			else if(ChoiceRowB < 1 || ChoiceRowB > 4){
				cout << "Please try that again user!" << endl;
			}
		}
		while(true){
			cin >> ChoiceColumnB;
			if(ChoiceColumnB == 1 || ChoiceColumnB == 2 || ChoiceColumnB == 3 || ChoiceColumnB == 4){
				break;
			}
			else if(cin.fail()){
				cin.clear();
				cin.ignore();
				cout << "Please try that again user!" << endl;
			}
			else if(ChoiceColumnB < 1 || ChoiceColumnB > 4){
				cout << "Please try that again user!" << endl;
			}
		}
		ChoiceRowB = ChoiceRowB - 1;
		ChoiceColumnB = ChoiceColumnB - 1; 
		while( display[ChoiceRowB][ChoiceColumnB] == 'X' || ChoiceRowB > 3 || ChoiceRowB < 0 || ChoiceColumnB > 3 || ChoiceColumnB < 0 || (ChoiceRowB == ChoiceRowA && ChoiceColumnB == ChoiceColumnA) )
		{
			
		/*	while( !(cin>>ChoiceRowB) || !(cin>>ChoiceColumnB)) 
			{
				cin.clear(); 
				cin.ignore(256, '\n'); 
				cout << "Invalid input! Please re-enter.\n";
			}
		*/	
			cout<<"INVALID CHOICE!!! Please re-enter coordinates. (Row, then Column)"<<endl;
			cin>>ChoiceRowB;
			cin>>ChoiceColumnB;
			ChoiceRowB = ChoiceRowB - 1;
			ChoiceColumnB = ChoiceColumnB - 1; 
		}
		
		if( array[ChoiceRowA][ChoiceColumnA] == array[ChoiceRowB][ChoiceColumnB] )
		{
			cout<<"Correct Match!!!"<<endl;
			points = points + 5;
			correct++;
			display[ChoiceRowA][ChoiceColumnA] = 'X';
			display[ChoiceRowB][ChoiceColumnB] = 'X';
		}
		else
		{
			cout<<"Incorrect Match!!!"<<endl
				<<"GAME OVER"<<endl
				<<"You scored "<<points<<" points"<<endl
				<<"Thank you for playing!"<<endl;
				
			cout<<"Correct matches were: "<<endl;
			printFullArray();
			score = score + points;
			error = 1;
		}
		if( correct == 8)
		{
			cout<<"Congratulations!!!"<<endl
				<<"You have won the game!!!"<<endl
				<<"You scored "<<points<<" points"<<endl
				<<"Thank you for playing!"<<endl;
				score = score+(points + 10);
		}
	}
}
void userAccount::playMemory( void )
{
	int ChoiceRowA;
	int ChoiceColumnA;
	int ChoiceRowB;
	int ChoiceColumnB;
	int error = 0;
	int correct = 0; 
	printFullArray();
	sleep(3);
	ClearScreen(); 
	
	while( error != 1 )
	{
		printHiddenArray();
		
		cout<<"Enter the coordinates of the first 'card'. (Row, then Column)"<<endl;
		while(true){
			cin >> ChoiceRowA;
			if(ChoiceRowA == 1 || ChoiceRowA == 2 || ChoiceRowA == 3 || ChoiceRowA == 4){
				break;
			}
			else if(cin.fail()){
				cin.clear();
				cin.ignore();
				cout << "Please try that again user!" << endl;
			}
			else if(ChoiceRowA < 1 || ChoiceRowA > 4){
				cout << "Please try that again user!" << endl;
			}
		}
		while(true){
			cin >> ChoiceColumnA;
			if(ChoiceColumnA == 1 || ChoiceColumnA == 2 || ChoiceColumnA == 3 || ChoiceColumnA == 4){
				break;
			}
			else if(cin.fail()){
				cin.clear();
				cin.ignore();
				cout << "Please try that again user!" << endl;
			}
			else if(ChoiceColumnA < 1 || ChoiceColumnA > 4){
				cout << "Please try that again user!" << endl;
			}
		}
		ChoiceRowA = ChoiceRowA - 1;
		ChoiceColumnA = ChoiceColumnA - 1;
		while( display[ChoiceRowA][ChoiceColumnA] == 'X' || ChoiceRowA > 3 || ChoiceRowA < 0 || ChoiceColumnA > 3 || ChoiceColumnA < 0 )
		{
			cout<<"INVALID CHOICE!!! Please re-enter coordinates. (Row, then Column)"<<endl;
			while(true){
				cin >> ChoiceRowA;
				if(ChoiceRowA == 1 || ChoiceRowA == 2 || ChoiceRowA == 3 || ChoiceRowA == 4){
					break;
				}
				else if(cin.fail()){
					cin.clear();
					cin.ignore();
					cout << "Please try that again user!" << endl;
				}
				else if(ChoiceRowA < 1 || ChoiceRowA > 4){
					cout << "Please try that again user!" << endl;
				}
			}
			while(true){
				cin >> ChoiceColumnA;
				if(ChoiceColumnA == 1 || ChoiceColumnA == 2 || ChoiceColumnA == 3 || ChoiceColumnA == 4){
					break;
				}
				else if(cin.fail()){
					cin.clear();
					cin.ignore();
					cout << "Please try that again user!" << endl;
				}
				else if(ChoiceColumnA < 1 || ChoiceColumnA > 4){
					cout << "Please try that again user!" << endl;
				}
			}
			ChoiceRowA = ChoiceRowA - 1;
			ChoiceColumnA = ChoiceColumnA - 1;
		}
		
		cout<<"Now enter the coordinates of the second 'card'. (Row, then Column)"<<endl;
		while(true){
			cin >> ChoiceRowB;
			if(ChoiceRowB == 1 || ChoiceRowB == 2 || ChoiceRowB == 3 || ChoiceRowB == 4){
				break;
			}
			else if(cin.fail()){
				cin.clear();
				cin.ignore();
				cout << "Please try that again user!" << endl;
			}
			else if(ChoiceRowB < 1 || ChoiceRowB > 4){
				cout << "Please try that again user!" << endl;
			}
		}
		while(true){
			cin >> ChoiceColumnB;
			if(ChoiceColumnB == 1 || ChoiceColumnB == 2 || ChoiceColumnB == 3 || ChoiceColumnB == 4){
				break;
			}
			else if(cin.fail()){
				cin.clear();
				cin.ignore();
				cout << "Please try that again user!" << endl;
			}
			else if(ChoiceColumnB < 1 || ChoiceColumnB > 4){
				cout << "Please try that again user!" << endl;
			}
		}
		ChoiceRowB = ChoiceRowB - 1;
		ChoiceColumnB = ChoiceColumnB - 1; 
		while( display[ChoiceRowB][ChoiceColumnB] == 'X' || ChoiceRowB > 3 || ChoiceRowB < 0 || ChoiceColumnB > 3 || ChoiceColumnB < 0 || (ChoiceRowB == ChoiceRowA && ChoiceColumnB == ChoiceColumnA) )
		{
			
		/*	while( !(cin>>ChoiceRowB) || !(cin>>ChoiceColumnB)) 
			{
				cin.clear(); 
				cin.ignore(256, '\n'); 
				cout << "Invalid input! Please re-enter.\n";
			}
		*/	
			cout<<"INVALID CHOICE!!! Please re-enter coordinates. (Row, then Column)"<<endl;
			while(true){
				cin >> ChoiceRowB;
				if(ChoiceRowB == 1 || ChoiceRowB == 2 || ChoiceRowB == 3 || ChoiceRowB == 4){
					break;
				}
				else if(cin.fail()){
					cin.clear();
					cin.ignore();
					cout << "Please try that again user!" << endl;
				}
				else if(ChoiceRowB < 1 || ChoiceRowB > 4){
					cout << "Please try that again user!" << endl;
				}
			}
			while(true){
				cin >> ChoiceColumnB;
				if(ChoiceColumnB == 1 || ChoiceColumnB == 2 || ChoiceColumnB == 3 || ChoiceColumnB == 4){
					break;
				}
				else if(cin.fail()){
					cin.clear();
					cin.ignore();
					cout << "Please try that again user!" << endl;
				}
				else if(ChoiceColumnB < 1 || ChoiceColumnB > 4){
					cout << "Please try that again user!" << endl;
				}
			}
			ChoiceRowB = ChoiceRowB - 1;
			ChoiceColumnB = ChoiceColumnB - 1; 
		}
		
		if( array[ChoiceRowA][ChoiceColumnA] == array[ChoiceRowB][ChoiceColumnB] )
		{
			cout<<"Correct Match!!!"<<endl;
			points = points + 5;
			correct++;
			display[ChoiceRowA][ChoiceColumnA] = 'X';
			display[ChoiceRowB][ChoiceColumnB] = 'X';
		}
		else
		{
			cout<<"Incorrect Match!!!"<<endl
				<<"GAME OVER"<<endl
				<<"You scored "<<points<<" points"<<endl
				<<"Thank you for playing!"<<endl;
				
			cout<<"Correct matches were: "<<endl;
			printFullArray();
			score = score + points;
			if(points > matchingHigh){
				cout << "Congratulations! you set a new memory high score!" << endl;
				matchingHigh = points;
			}
			error = 1;
		}
		if( correct == 8)
		{
			cout<<"Congratulations!!!"<<endl
				<<"You have won the game!!!"<<endl
				<<"You scored "<<points<<" points"<<endl
				<<"Thank you for playing!"<<endl;
				score = score+(points + 10);
				if(points > matchingHigh){
					cout << "Congratulations! you set a new memory high score!" << endl;
					matchingHigh = points;
				}
		}
	}
}
void superAccount::playMemory( void )
{
	int ChoiceRowA;
	int ChoiceColumnA;
	int ChoiceRowB;
	int ChoiceColumnB;
	int error = 0;
	int correct = 0; 
	printFullArray();
	sleep(3);
	ClearScreen(); 
	
	while( error != 1 )
	{
		printHiddenArray();
		
		cout<<"Enter the coordinates of the first 'card'. (Row, then Column)"<<endl;
		while(true){
			cin >> ChoiceRowA;
			if(ChoiceRowA == 1 || ChoiceRowA == 2 || ChoiceRowA == 3 || ChoiceRowA == 4){
				break;
			}
			else if(cin.fail()){
				cin.clear();
				cin.ignore();
				cout << "Please try that again user!" << endl;
			}
			else if(ChoiceRowA < 1 || ChoiceRowA > 4){
				cout << "Please try that again user!" << endl;
			}
		}
		while(true){
			cin >> ChoiceColumnA;
			if(ChoiceColumnA == 1 || ChoiceColumnA == 2 || ChoiceColumnA == 3 || ChoiceColumnA == 4){
				break;
			}
			else if(cin.fail()){
				cin.clear();
				cin.ignore();
				cout << "Please try that again user!" << endl;
			}
			else if(ChoiceColumnA < 1 || ChoiceColumnA > 4){
				cout << "Please try that again user!" << endl;
			}
		}
		ChoiceRowA = ChoiceRowA - 1;
		ChoiceColumnA = ChoiceColumnA - 1;
		while( display[ChoiceRowA][ChoiceColumnA] == 'X' || ChoiceRowA > 3 || ChoiceRowA < 0 || ChoiceColumnA > 3 || ChoiceColumnA < 0 )
		{
			cout<<"INVALID CHOICE!!! Please re-enter coordinates. (Row, then Column)"<<endl;
			while(true){
				cin >> ChoiceRowA;
				if(ChoiceRowA == 1 || ChoiceRowA == 2 || ChoiceRowA == 3 || ChoiceRowA == 4){
					break;
				}
				else if(cin.fail()){
					cin.clear();
					cin.ignore();
					cout << "Please try that again user!" << endl;
				}
				else if(ChoiceRowA < 1 || ChoiceRowA > 4){
					cout << "Please try that again user!" << endl;
				}
			}
			while(true){
				cin >> ChoiceColumnA;
				if(ChoiceColumnA == 1 || ChoiceColumnA == 2 || ChoiceColumnA == 3 || ChoiceColumnA == 4){
					break;
				}
				else if(cin.fail()){
					cin.clear();
					cin.ignore();
					cout << "Please try that again user!" << endl;
				}
				else if(ChoiceColumnA < 1 || ChoiceColumnA > 4){
					cout << "Please try that again user!" << endl;
				}
			}
			ChoiceRowA = ChoiceRowA - 1;
			ChoiceColumnA = ChoiceColumnA - 1;
		}
		
		cout<<"Now enter the coordinates of the second 'card'. (Row, then Column)"<<endl;
		while(true){
			cin >> ChoiceRowB;
			if(ChoiceRowB == 1 || ChoiceRowB == 2 || ChoiceRowB == 3 || ChoiceRowB == 4){
				break;
			}
			else if(cin.fail()){
				cin.clear();
				cin.ignore();
				cout << "Please try that again user!" << endl;
			}
			else if(ChoiceRowB < 1 || ChoiceRowB > 4){
				cout << "Please try that again user!" << endl;
			}
		}
		while(true){
			cin >> ChoiceColumnB;
			if(ChoiceColumnB == 1 || ChoiceColumnB == 2 || ChoiceColumnB == 3 || ChoiceColumnB == 4){
				break;
			}
			else if(cin.fail()){
				cin.clear();
				cin.ignore();
				cout << "Please try that again user!" << endl;
			}
			else if(ChoiceColumnB < 1 || ChoiceColumnB > 4){
				cout << "Please try that again user!" << endl;
			}
		}
		ChoiceRowB = ChoiceRowB - 1;
		ChoiceColumnB = ChoiceColumnB - 1; 
		while( display[ChoiceRowB][ChoiceColumnB] == 'X' || ChoiceRowB > 3 || ChoiceRowB < 0 || ChoiceColumnB > 3 || ChoiceColumnB < 0 || (ChoiceRowB == ChoiceRowA && ChoiceColumnB == ChoiceColumnA) )
		{
			
		/*	while( !(cin>>ChoiceRowB) || !(cin>>ChoiceColumnB)) 
			{
				cin.clear(); 
				cin.ignore(256, '\n'); 
				cout << "Invalid input! Please re-enter.\n";
			}
		*/	
			cout<<"INVALID CHOICE!!! Please re-enter coordinates. (Row, then Column)"<<endl;
			while(true){
				cin >> ChoiceRowB;
				if(ChoiceRowB == 1 || ChoiceRowB == 2 || ChoiceRowB == 3 || ChoiceRowB == 4){
					break;
				}
				else if(cin.fail()){
					cin.clear();
					cin.ignore();
					cout << "Please try that again user!" << endl;
				}
				else if(ChoiceRowB < 1 || ChoiceRowB > 4){
					cout << "Please try that again user!" << endl;
				}
			}
			while(true){
				cin >> ChoiceColumnB;
				if(ChoiceColumnB == 1 || ChoiceColumnB == 2 || ChoiceColumnB == 3 || ChoiceColumnB == 4){
					break;
				}
				else if(cin.fail()){
					cin.clear();
					cin.ignore();
					cout << "Please try that again user!" << endl;
				}
				else if(ChoiceColumnB < 1 || ChoiceColumnB > 4){
					cout << "Please try that again user!" << endl;
				}
			}
			ChoiceRowB = ChoiceRowB - 1;
			ChoiceColumnB = ChoiceColumnB - 1; 
		}
		
		if( array[ChoiceRowA][ChoiceColumnA] == array[ChoiceRowB][ChoiceColumnB] )
		{
			cout<<"Correct Match!!!"<<endl;
			points = points + 5;
			correct++;
			display[ChoiceRowA][ChoiceColumnA] = 'X';
			display[ChoiceRowB][ChoiceColumnB] = 'X';
		}
		else
		{
			cout<<"Incorrect Match!!!"<<endl
				<<"GAME OVER"<<endl
				<<"You scored "<<points<<" points"<<endl
				<<"Thank you for playing!"<<endl;
				
			cout<<"Correct matches were: "<<endl;
			printFullArray();
			score = score+((points*scoreMultiplier)+scoreAdder);
			if(points > matchingHigh){
				cout << "Congratulations! you set a new memory high score!" << endl;
				matchingHigh = points;
			}
			error = 1;
		}
		if( correct == 8)
		{
			cout<<"Congratulations!!!"<<endl
				<<"You have won the game!!!"<<endl
				<<"You scored "<<points<<" points"<<endl
				<<"Thank you for playing!"<<endl;
				score = score+((points*scoreMultiplier + 10)+scoreAdder);
				if(points > matchingHigh){
					cout << "Congratulations! you set a new memory high score!" << endl;
					matchingHigh = points;
				}
		}
	}
}

