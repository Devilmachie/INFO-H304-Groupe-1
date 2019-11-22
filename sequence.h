#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <map>

using std::string;

class Sequence
{
private:
	char* name;
	char* data;
	int data_len;
	uint8_t* tr_data;
	std::map<char,int>* transcript;
public:
	Sequence();
	Sequence(char* information,bool isDBPath=true);
	void init_map();
	void transcriptSequence();
	
	void setName(char* name);
	void setData(char* data);

	string getName() const;
	string getData() const;
	int getDataLen() const;
	bool operator== (const char* sequence);
};
