#include <fstream>
#include <string>
#include <iostream>
#include "bdata.h"
#include "sequence.h"
#include <cstring> // check si stdlib
#include <map>
#include <thread>

#define IS_PROTEIN 1
#define IS_DNA 0

#define  GENERAL ".pin"
#define  HEADER ".phr"
#define  SEQUENCE ".psq"

#define GAP_PENALTY 11
#define EXTENSION_PENALTY 1
#define RESULTS 20
#define THREAD_COUNT 4

using namespace std;

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
	
	int min_score = 0;
	int scores[RESULTS] = {0};
	uint32_t offsets[RESULTS] = {0};
	int sizes[RESULTS] = {0};

	bool reading = false;

	bool hasBeenFound;

	int BLOSUM[625] = {0};
	
	void openDB(char* mode);
	void closeDB(char* mode);
	bool anotherDBAlreadyOpen();
	void readb_data(ifstream & db,void* buffer,streamsize n_info);
	void init_db();
	
	int getvalue(char c);
	void create_subst_mat(const char* blosum, size_t blosumsize, int *matrix, size_t matrixsize);
    	void find_blosum();
    	void print_header(uint32_t offset, int size);
    	void *main_loop(Sequence* searched_sequence, short t_offset);

	
public:
	DataBase(char* db_name);
	~DataBase();
	
	void showDBInfo();
	bool searchSequence(Sequence* new_sequence);
	int fill_matrix(short*** scoring_m, char* found_sequence, int found_length, char* searched_sequence, int searched_length);
	void fishData(ifstream & fp, char* buffer, uint32_t offset,uint32_t size);
    	void readHeader (ifstream & fp, char* buffer, uint32_t,uint32_t size);
};
