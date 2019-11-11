#include <fstream>
#include <string>
#include <iostream>
#include "sequence.h"
#include "templates.h"
using std::string;
using std::ifstream;

class DataBase
{
private:
	string path_to_db;
	ifstream read_in_db;
	Sequence* actual_sequence;
	bool is_open;	
	

	uint32_t db_type;
	uint32_t version;
	uint32_t title_len;
	uint32_t t_stamp_len;
	uint32_t N;
	uint32_t max_s_len;

	uint64_t res_n;

	uint32_t* offset_h;
	uint32_t* offset_r;
	uint32_t* offset_a;

	char* title;
	char* t_stamp;
	//DB information end
	

	void openDB();
	void closeDB();
	b_info readb_data(b_info buffer,int n_info);
	void init_db();
	void initialize_table(table new_table,int size);
public:
	DataBase(string db_name);
	~DataBase();
	
	//int searchSequence(const Sequence & searched_sequence);

};
