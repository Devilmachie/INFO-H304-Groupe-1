#include <fstream>
#include <string>
#include <iostream>
//#include "database.h"
using namespace std;

class test
{
	private:
		char* name;
	public:
		void initialize(string str,int length)
		{
			const char* s = str.c_str();
			this->name = new char[length];
			for(int i=0;i<length;i++)
				*(this->name+i)=*(s+i);
		}
};
	

#define NAME "/home/devilmachie/Desktop/swipe-master/uniprot_sprot.fasta.pin"
void print(string string_to_print);
int main()
{
	
	//DataBase db(NAME);
	test t;
	t.initialize("Hello",6);

	return 0;
}
void print(string string_to_print)
{
	cout<<string_to_print<<endl;
}
