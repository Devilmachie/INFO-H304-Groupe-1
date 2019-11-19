#include <fstream>
#include <string>
#include <iostream>
#include "bdata.h"

using std::string;
using std::ifstream;
using std::ios;
using std::streamsize;
using std::int32_t;



class DataBase
{
private:
	string path_to_db;
	ifstream read_in_db;
	bool is_open;	
	
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
	BinaryData<uint32_t> offset_a;

	BinaryData<char> title;
	BinaryData<char> t_stamp;
	//DB information end
	

	void openDB();
	void closeDB();
	void readb_data(ifstream & db,void* buffer,streamsize n_info);
	void init_db();
public:
	DataBase(string db_name);
	~DataBase();
	
	void showDBInfo();
	
	//int searchSequence(const Sequence & searched_sequence);

};
