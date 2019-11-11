#include "database.h"


DataBase::DataBase(string db_name)
{
	this->path_to_db=db_name;
	init_db();
}

DataBase::~DataBase()
{

}


void DataBase::openDB()
{
	ifstream & db = this->read_in_db;
	char* db_path = (this->path_to_db).c_str();
	db.open(db_path,ios::in||ios::binary);	
	if(db)	this->is_open=true;
		
}

bool DataBase::closeDB()
{
	ifstream & db = this->read_in_db;
	if(db)
	{
		db_close();
		is_open=false;	
	}
}

void DataBase::readb_data(ifstream & db,b_info* buffer,streamsize n_info)
{
	db.read(reinterpret_cast<char *>(buffer),n_info);
}

void DataBase::init_db()
{
	openDB();
	if(this->is_open)
	{
		ifstream & db = this->read_in_db;
		readb_data(db,this.version,sizeof(this->version));
		readb_data(db,this.db_type,sizeof(this->db_type));
		readb_data(db,this.title_len,sizeof(this->title_len));
		initialize_table(this->title,this->title_len);
		readb_data(db,this.title,this->title_len*sizeof(this->title));
		readb_data(db,this.t_stamp_len,sizeof(this->t_stamp_len));
		initialize_table(this->t_stamp,this->t_stamp_len);
		readb_data(db,this.t_stamp,this->t_stamp_len*sizeof(this->t_stamp));
		readb_data(db,this.N,sizeof(this->N));
		readb_data(db,this.res_n,sizeof(this->res_n));
		readb_data(db,this.max_s_len,sizeof(this->max_s_len));
		initialize_table(this->offset_h,this->N+1);
		initialize_table(this->offset_s,this->N+1);
		readb_data(db,this.offset_h,(this->N+1)*sizeof(this->offset_h));
		readb_data(db,this.offset_s,(this->N+1)*sizeof(this->offset_s));
	}
	else
		std::cout<<"DB couldn't be open"<<std::endl;

}

void DataBase::initialize_table(table new_table,int size)
{
	new_table = new table[size];
}
