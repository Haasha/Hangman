#include <iostream>
#include<fstream>
#include<cstdlib>
#include<time.h>
using namespace std;
// function for reading the text file
void fread(string fname, string words[], const int & nwords)
{
	ifstream ifile(fname.c_str(), ios::in);
	if (!ifile)
	{
		cout<<" Couldn’t read the file " << fname;
		exit(-1);
	}

	int count = 0;
	while(ifile && count < nwords)
		ifile >> words[count++];
	ifile.close();
}
int main() {
	srand(time(NULL));
	const int nwords=4342;
	int RandIndex;
	string Dict[nwords];
	char* Word;
	char* Guess;
	int * Array;
	bool Check=false;
	int Disclosed, Options,Display;
	char x,Play;
	char* Hangman[19]=
	{" 								  ___________.._______",
	"								| .__________))______|",
	"								| | / /      ||",
	"								| |/ /       ||",
	"								| | /        ||.-’’.",
	"								| |/         |/  _  \\",
	"								| |          ||  `/,|",
	"								| |          (\\\\`_.’",
	"								| |         .-`--’.",
	"								| |        /Y . . Y\\",
	"								| |       //|    | \\\\",
	"								| |      // |  . | \\\\",
	"								| |      ’) |    | (`",
	"								| |         || ’||",
	"								| |         ||  ||",
	"								| |         ||  ||",
	"								| |         ||  ||",
	"								| |        / |  | \\",
	"								         |_`-’  `-’ | |"};
	//Path of the File Named 1-400.txt
	Path=""
	fread(Path, Dict , nwords);

	char* Name=new char[50];
	cout<<"Enter your Name : ";
	cin.getline(Name,50);

	for(int i=0,j ,Score=0; ; i++)
	{
		cout<<"GUESS THE WORD : "<<endl;
		//Taking and printing Random Value
		RandIndex=rand()%4342;

		//Loop for finding length of the Word
		for( j=0 ; Dict[RandIndex][j]!='\0' ; j++);

		//Allocating memory dynamically to the actual word and guessing word
		Word=new char [j];
		Guess=new char [j];

		//Finding the number of Disclosed and Options of letters to be provided
		Disclosed=j/3;
		Options=(j-j/3)*2;

		//Fixing the Options to a Maximum size of 18
		if (Options>18)
			Options=18;


		//Loop for storing characters on the both character array
		for(int k=0 ; k<j ; k++)
		{
			Word[k]=Dict[RandIndex][k];
			Guess[k]='_';
		}

		//Loop for disclosing 1/3 letters of the length of whole word
		for(int k=0,l ; k<Disclosed ; k++)
		{
			l=rand()%j;
			Guess[l]=Word[l];
		}


		Display=19/Options;
		//Main loop for running the Game
		for(int k=0,l,Count ;;)
		{
			for(int m=0 ; m<j; m++)
				cout<<Guess[m]<<' ';
			Count=0;
			cout<<"\nEnter the character : ";
			cin>>x;

			//Loop for counting that how many times a letter exists in the word
			for(l=0 ; l<j ; l++)
				if (Word[l]==x || Word[l]-32==x)
					Count++;
			if(Count==0)
			{
				for(int m=0 ; m<Display*(k+1) ; m++)
					cout<<Hangman[m]<<endl;
				cout<<"\n************WRONG GUESS************"<<endl;
				cout<<"You have "<<Options-k-1<<" options left"<<endl;
				k++;
			}
			else
			{
				Array=new int [Count];
				for(l=0,Count=0 ; l<j ; l++)
				{
					if (Word[l]==x || Word[l]-32==x)
					{
						Array[Count]=l;
						Count++;
					}
				}
				for(int m=0 ; m<Count ; m++)
				{
					if(Guess[Array[m]]=='_')
					{
						if (x>64 && x<91)
							Guess[Array[m]]=x+32;
						else
							Guess[Array[m]]=x;
					}
				}
				delete [] Array;

			}
			Check=true;
			for(int m=0 ; m<j ; m++)
				{
				if(Guess[m]=='_')
					{
						Check=false;
						break;
					}
				}
			if(Check==true)
			{
				Score++;
				cout<<"\n************CONGRATULATIONS************"<<endl;
				cout<<"YOU GUESSED THE WORD CORRECTLY"<<endl;
				for(int m=0 ; m<j; m++)
					cout<<Guess[m]<<' ';
				cout<<endl;
				break;

			}
			else if (k==Options)
			{
				cout<<"\n**********YOU FAILED TO GUESS THE WORD**********"<<endl;
				for(int m=0 ; m<19 ; m++)
					cout<<Hangman[m]<<endl;
				cout<<"The correct Word was ";
				for(int m=0 ; m<j ; m++)
					cout<<Word[m];
				cout<<endl;
				break;
			}
		}





		delete [] Word;
		delete [] Guess;
		Word=NULL;
		Guess=NULL;
		Play='y';
		do
		{
			cout<<"\nIF YOU WANT TO PLAY\nPLEASE ENTER P ELSE Q : ";
			cin>>Play;
		}
		while(Play!='p' && Play!='P' && Play=='q' && Play=='Q');
		if(Play=='q' || Play=='Q')
		{
			cout<<"\nThanks for playing "<<Name<<endl;
			cout<<"\nYOU GUESSED "<<Score<<" WORDS CORRECTLY OUT OF "<<i+1<<endl;
			break;
		}


	}
}

