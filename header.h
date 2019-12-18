#ifndef HEADER_DEFINITION
#define HEADER_DEFINITION
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::ifstream;
using namespace std;

#define INT_SIZE 4
#define BYTE_SIZE 8
#define MAX_FREE 8
class Header
{
	private:
		std::vector<void*> memory_allocated;
		char* current_obj;
		char* last_obj;

		char* format;
		char* obj_arr;
		unsigned long int size_to_parse;
		unsigned char obj;
		unsigned char next;
		unsigned char len;
		
		unsigned long parsed_integer;
		char* parsed_string;

		void nextObj();
		void matchObj(unsigned short match);
		void nextCh();
		
		void parse();
		void parseIdentifier();

		void parseInteger();
		void parseVisibleString(char* container);
		void parseChoice();
		//void parseSequence();
		//void parseSequenceOf();
	public:
		Header(ifstream & header_file,unsigned long int offset,unsigned long int header_size);
		Header(std::string & name);
		~Header();

		char* getName();
};

#endif
