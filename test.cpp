#include <fstream>
#include <string>
#include <iostream>
#include "database.h"
#include "sequence.h"
using namespace std;




int main(int argc,char** argv)
{
	string argv_i;
	int go=11, ge=1, blos=62, n=20, t=4, value, temp;
	
	if(argc == 2)
	{
		argv_i = argv[1];
		
		if(argv_i == "--help")
		{
			cout << "Welcome to " << argv[0] <<". This program will find the best allignments for a given protein sequence, using the Smith-Waterman algorithm." << endl;
			cout << "To use the program, you will need the following arguments : " << endl << endl;
			cout << argv[0] << " [DATABASE] [SEQUENCE] [OPTIONS]" << endl << endl;
			cout << "Possible options are :                                                 DEFAULT :" << endl;
			cout << " -go [GAP_OPEN_PENALTY]         Sets the penalty for opening a gap     11" << endl;
			cout << " -ge [GAP_EXTENSION_PENALTY]    Sets the penalty for extending a gap   1" << endl;
			cout << " -blosum [BLOSUM]               Sets the used type of blosum matrix    BLOSUM62" << endl;
			cout << " -n [NUMBER_OF_RESULTS]         Sets the quantity of returned results  20" << endl;
			cout << " -t [THREAD_COUNT]              Sets the number of threads used        4" << endl << endl;
			cout << "The DATABASE has to be in BLAST format, and the SEQUENCE has to be in FASTA format" << endl;
			
			return 1;
		}
	}
	
	if(argc < 3 || (argc % 2) == 0)
	{
		cout << "Incorrect use of " << argv[0] << "." << endl << "For more information, type \"" << argv[0] << " --help\"" << endl;

		return 1;
	}
	else
	{
		//sets the arguments
		for (int i=3; i<argc; i+=2)
		{
			argv_i = argv[i];
			
			if (argv_i != "-go" && argv_i != "-ge" && argv_i != "-blosum" && argv_i != "-n" && argv_i != "-t")
			{
				cout << "Incorrect use of " << argv[0] << "." << endl << "For more information, type \"" << argv[0] << " --help\"" << endl;
				
				return 1;
			}
			else if (argv_i == "-blosum")
			{
				argv_i = argv[i+1];
				
				if(argv_i=="BLOSUM45" || argv_i=="blosum45")
					blos = 45;
				else if(argv_i=="BLOSUM50" || argv_i=="blosum50")
					blos = 50;
				else if(argv_i=="BLOSUM80" || argv_i=="blosum80")
					blos = 80;
				else if(argv_i=="BLOSUM90" || argv_i=="blosum90")
					blos = 90;
				else if(argv_i=="BLOSUM62" || argv_i=="blosum62")
					;
				else 
				{
					cout << "Error : wrong blosum matrix : " << argv_i << endl << "Correct notation is : \"BLOSUMXX\" ." << endl;
					return 2;
				}
			}
			else
			{
				value = 0 ;
				temp = ((string) argv[i+1]).length();
				
				for (int j=0; j<temp; j++)
					value = value * 10 + argv[i+1][j] - '0';
					
				if(argv_i == "-go")
					go = value;
				else if(argv_i == "-ge")
					ge = value;
				else if(argv_i == "-n")
					n = value;
				else if(argv_i == "-t")
					t = value;
			}
		}
		
		DataBase* db = new DataBase(argv[1], go, ge, blos, n, t);
		db->showDBInfo();
		Sequence* seq = new Sequence(argv[2]);
		db->searchSequence(seq);
		
		delete seq;
		delete db;
	}

	
	return 0;
}




