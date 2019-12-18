#ifndef SEQUENCE_DEFINITION
#define SEQUENCE_DEFINITION

#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <map>
#include <string.h>
#include <set>
#include "header.h"

using std::string;
using namespace std;

class Sequence
{
private:
	Header* name;
	char* data;
	int data_len;
	uint8_t* tr_data;
	static std::map<char,int> transcript;

	void init_map();
	void transcriptSequence();
public:
	Sequence(char* sequence_path);
        ~Sequence();

	
	
	void setName(Header* name);
	void setData(char* data);

	string getName() const;
	char* getData() const;
	int getDataLen() const;
	bool operator== (const char* sequence);
};
#endif
