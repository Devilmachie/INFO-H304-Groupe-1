#include <fstream>
#include <string>
#include <iostream>
#include "bdata.h"
#include "sequence.h"
#include <cstring>
#include <map>
#include "header.h"

#define IS_PROTEIN 1
#define IS_DNA 0

#define  GENERAL ".pin"
#define  HEADER ".phr"
#define  SEQUENCE ".psq"

using std::string;
using std::ifstream;
using std::ios;
using std::streamsize;




class DataBase
{
private:
	char* path_to_db;
	ifstream read_in_db;
	std::map<char*,bool> is_open;	
	
	//DB information begin
	BinaryData<uint32_t> db_type;
	BinaryData<uint32_t> version;
	BinaryData<uint32_t> title_len;
	BinaryData<uint32_t> t_stamp_len;
	BinaryData<uint32_t> N;
	BinaryData<uint32_t> max_s_len;
	
	BinaryData<uint64_t> res_n;

	BinaryData<uint32_t> offset_h;
	BinaryData<uint32_t> offset_r;

	BinaryData<char> title;
	BinaryData<char> t_stamp;
	//DB information end
	

	void openDB(char* mode);
	void closeDB(char* mode);
	bool anotherDBAlreadyOpen();
	void readb_data(ifstream & db,void* buffer,streamsize n_info);
	void init_db();
public:
	DataBase(char* db_name);
	~DataBase();
	
	void showDBInfo();
	bool searchSequence(Sequence* new_sequence);
	void fishData(ifstream & fp, char* buffer, uint32_t offset,uint32_t size);
    	void readHeader (ifstream & fp, char* buffer, uint32_t,uint32_t size);
};
