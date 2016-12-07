#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
using namespace std;
//#include "head.h"

class memory
{
	private:
	public:
		char array[4][4]; 
		char display[4][4];
		int points;
		memory( void );
		~memory( void );
		void MakeArrays( void );
		int playMemory( void ); 
		void printFullArray( void ); 
		void printHiddenArray( void ); 
		void ClearScreen( void ); 
};

memory::memory( void )
{
	points = 0;
	MakeArrays();
}

memory::~memory( void )
{
	
}

void memory::MakeArrays( void )
{	
	array[0][0] = (const)'!';
	array[0][1] = (const)'@';
	array[0][2] = (const)'#';
	array[0][3] = (const)'%';
	array[1][0] = (const)'?';
	array[1][1] = (const)'%';
	array[1][2] = (const)'!';
	array[1][3] = (const)'$';
	array[2][0] = (const)'&';
	array[2][1] = (const)'~';
	array[2][2] = (const)'~';
	array[2][3] = (const)'?';
	array[3][0] = (const)'#';
	array[3][1] = (const)'&';
	array[3][2] = (const)'@';
	array[3][3] = (const)'$';
	
	display[0][0] = (const)'O';
	display[0][1] = (const)'O';
	display[0][2] = (const)'O';
	display[0][3] = (const)'O';
	display[1][0] = (const)'O';
	display[1][1] = (const)'O';
	display[1][2] = (const)'O';
	display[1][3] = (const)'O';
	display[2][0] = (const)'O';
	display[2][1] = (const)'O';
	display[2][2] = (const)'O';
	display[2][3] = (const)'O';
	display[3][0] = (const)'O';
	display[3][1] = (const)'O';
	display[3][2] = (const)'O';
	display[3][3] = (const)'O';
	
//	int c , d;
//	srand (time(NULL));	
/*	for( c=0; c<4; c++ )
	{
		for( d=0; d<4; d++ )
		{
			array[c][d] = ( rand() % 8 ); 
		}
	}
*/
}

void memory::printFullArray( void )
{
	cout<<" "<<" "<<"1"<<" "<<"2"<<" "<<"3"<<" "<<"4"<<endl
		<<"1"<<" "<<array[0][0]<<" "<<array[0][1]<<" "<<array[0][2]<<" "<<array[0][3]<<endl
		<<"2"<<" "<<array[1][0]<<" "<<array[1][1]<<" "<<array[1][2]<<" "<<array[1][3]<<endl
		<<"3"<<" "<<array[2][0]<<" "<<array[2][1]<<" "<<array[2][2]<<" "<<array[2][3]<<endl
		<<"4"<<" "<<array[3][0]<<" "<<array[3][1]<<" "<<array[3][2]<<" "<<array[3][3]<<endl;
}

void memory::printHiddenArray( void )
{
	cout<<" "<<" "<<"1"<<" "<<"2"<<" "<<"3"<<" "<<"4"<<endl
		<<"1"<<" "<<display[0][0]<<" "<<display[0][1]<<" "<<display[0][2]<<" "<<display[0][3]<<endl
		<<"2"<<" "<<display[1][0]<<" "<<display[1][1]<<" "<<display[1][2]<<" "<<display[1][3]<<endl
		<<"3"<<" "<<display[2][0]<<" "<<display[2][1]<<" "<<display[2][2]<<" "<<display[2][3]<<endl
		<<"4"<<" "<<display[3][0]<<" "<<display[3][1]<<" "<<display[3][2]<<" "<<display[3][3]<<endl;
}

void memory::ClearScreen( void )
{
	int n;
	for( n=0; n < 10; n++ )
	{
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	}
}

int memory::playMemory( void )
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
		cin>>ChoiceRowA;
		cin>>ChoiceColumnA;
		ChoiceRowA = ChoiceRowA - 1;
		ChoiceColumnA = ChoiceColumnA - 1;
		while( display[ChoiceRowA][ChoiceColumnA] == (const)'X' || ChoiceRowA > 3 || ChoiceRowA < 0 || ChoiceColumnA > 3 || ChoiceColumnA < 0 )
		{
			cout<<"INVALID CHOICE!!! Please re-enter coordinates. (Row, then Column)"<<endl;
			cin>>ChoiceRowA;
			cin>>ChoiceColumnA;
			ChoiceRowA = ChoiceRowA - 1;
			ChoiceColumnA = ChoiceColumnA - 1;
		}
		
		cout<<"Now enter the coordinates of the second 'card'. (Row, then Column)"<<endl;
		cin>>ChoiceRowB;
		cin>>ChoiceColumnB;
		ChoiceRowB = ChoiceRowB - 1;
		ChoiceColumnB = ChoiceColumnB - 1; 
		while( display[ChoiceRowB][ChoiceColumnB] == (const)'X' || ChoiceRowB > 3 || ChoiceRowB < 0 || ChoiceColumnB > 3 || ChoiceColumnB < 0 || (ChoiceRowB == ChoiceRowA && ChoiceColumnB == ChoiceColumnA) )
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
			display[ChoiceRowA][ChoiceColumnA] = (const)'X';
			display[ChoiceRowB][ChoiceColumnB] = (const)'X';
		}
		else
		{
			cout<<"Incorrect Match!!!"<<endl
				<<"GAME OVER"<<endl
				<<"You scored "<<points<<" points"<<endl
				<<"Thank you for playing!"<<endl;
				
			cout<<"Correct matches were: "<<endl;
			printFullArray();
			
			error = 1;
			return points;
		}
		if( correct == 8)
		{
			cout<<"Congratulations!!!"<<endl
				<<"You have won the game!!!"<<endl
				<<"You scored "<<points<<" points"<<endl
				<<"Thank you for playing!"<<endl;
				
			return points;
		}
	}
	
	return points;
}



int main( void )
{
	int score;
	memory game1;
	//int WinVsLose = 0;
	cout<<"Welcome to the Memory Matching Game!!!"<<endl
		<<"How to play: "<<endl
		<<"Input coordinates of two matching 'cards' as prompted"<<endl
		<<"Remember the postion of the 'cards'!"<<endl
		<<"Game begins in 5 seconds!!!"<<endl;
	sleep(5);
	score = game1.playMemory();
	return 0;
}








