#include <fstream>
#include <string>
#include <iostream>
#include "database.h"
#include "sequence.h"
using namespace std;




int main(int argc,char** argv)
{
	if(argc != 3)
		std::cout<<"The correct use of this program is : "<<argv[0]<<" "<<"db_name.fasta "<<"protein_sequence.fasta"<<std::endl;
	else
	{
		DataBase* db = new DataBase(argv[1]);
		db->showDBInfo();
		Sequence* seq = new Sequence(argv[2]);
		db->searchSequence(seq);
		
		delete seq;
		delete db;
	}

	
	return 0;
}




