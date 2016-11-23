#include "head.h"

//Game class, has everything you need for a great time!

Game::Game( void )
{
	MakeSimon();
}
//Constructs the class, fills Simon's Output

Game::~Game( void )
{
	
}
//Deconstructs nothing, because it doesn't have to

void Game::MakeSimon( void )
{
	int c; 
	srand (time(NULL));
	
	for( c=0; c<100; c++ )
	{
		SimonOutput[c] = (rand() % 4) + 1; 	
	}
}
//Fills Simon's Output with random numbers based on time

void Game::Play( User* user )
{
	user->tokens--;
	rnd = 0; 
	int error = 0;
	int k, j;
	
	while( error != 1 )
	{
		rnd++;
		if( rnd >= 101 )
		{
			break;
		}
		cout<<"Round "<<rnd<<endl<<"Simon says:"<<endl;
		
		for( k=0; k<rnd; k++)
		{
			cout<<SimonOutput[k]<<endl;
			sleep(2);
			ClearScreen();
		}
		
		cout<<"Enter what Simon said one number at a time:"<<endl;
		
		for( j=0; j<rnd; j++)
		{
			cin>>UserInput[j];
		}
		
		error = Compare();
	}
//Plays Simon by displaying	the output and having the user enter what was displayed
//Which is then compared to the output and if correct the game continues
//If incorrect, the game ends
	if( rnd == 100 )
	{
		cout<<"CONGRATULATIONS!!!"<<endl<<"You beat the game!!!"<<endl
			<<"You weren't supposed to do that..."<<endl;
	}
	else
	{
		cout<<"GAME OVER!!!"<<endl<<"You made it to round "<<rnd<<"!"<<endl
		<<"Better luck next time!"<<endl;
		user->score = user->score + (rnd -1) * 3;//gives them points, 3 points for every round they get through
		cout << "You were awarded " << (rnd -1) * 3 << " points, way to go!" << endl;
		if((rnd -1) > 5){
			cout << "You have earned your token back!" << endl;
			user->tokens++;
		}
	}
	cout<<"Simon Said: "<<endl;
	int l;
	for(l=0; l<rnd; l++)
	{
		cout<<SimonOutput[l]<<"  ";
	}
	cout<<endl;
// The game then displays the correct message and Simon's Output up to the round the user made it	
}

int Game::Compare( void )
{
	int i;
	
	for( i=0; i<rnd; i++ )
	{ 
		if( UserInput[i] != SimonOutput[i] )
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
// Compares the user's input and Simon's output and returns a 0 on success and 1 on failure

void Game::ClearScreen( void )
{
	int n;
	for( n=0; n < 10; n++ )
	{
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	}
} //Bass-Ackward way to clear the screen, but it works for now


