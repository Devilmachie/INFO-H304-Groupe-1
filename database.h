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

#define GENERAL ".pin"
#define HEADER ".phr"
#define SEQUENCE ".psq"

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
	int* scores;
	uint32_t* offsets;
	int* sizes;

	bool reading = false;
	bool hasBeenFound;
	
	int gap_penalty;
	int extension_penalty;
	int results;
	int thread_count;
	int blosum_number;

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
    	void main_loop(Sequence* searched_sequence, short t_offset);

	
public:
	DataBase(char* db_name, int go, int ge, int blos, int n, int t);
	~DataBase();
	
	void showDBInfo();
	bool searchSequence(Sequence* new_sequence);
	int fill_matrix(unsigned short*** scoring_m, char* found_sequence, int found_length, char* searched_sequence, int searched_length);
	void fishData(ifstream & fp, char* buffer, uint32_t offset,uint32_t size);
    	void readHeader (ifstream & fp, char* buffer, uint32_t,uint32_t size);
};
