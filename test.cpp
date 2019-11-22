#include <fstream>
#include <string>
#include <iostream>
#include "database.h"
#include "sequence.h"
using namespace std;
#define NAME "uniprot_sprot.fasta.pin"
#define NAME_H "uniprot_sprot.fasta.phr"
#define NAME_R "uniprot_sprot.fasta.psq"
#define NAME_S "P00533.fasta"	



int main()
{
	DataBase* db = new DataBase(NAME);
	db->showDBInfo();
	Sequence* seq = new Sequence(NAME_S);
	db->searchSequence(seq,NAME_H,NAME_R);
	
	delete seq;
	delete db;

	
	return 0;
}




