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
	const char* db_path = (this->path_to_db).c_str();
	db.open(db_path,ios::in|ios::binary);	
	if(db)	this->is_open=true;
		
}

void DataBase::closeDB()
{
	ifstream & db = this->read_in_db;
	if(db)
	{
		db.close();
		is_open=false;	
	}
}


void DataBase::init_db()
{
	openDB();
	if(this->is_open)
	{
		this->version = new BinaryData<unsigned int>(this->read_in_db);
		this->db_type = new BinaryData<unsigned int>(this->read_in_db);
		this->title_len = new BinaryData<unsigned int>(this->read_in_db);
	}
	else
		std::cout<<"DB couldn't be open"<<std::endl;

}

void DataBase::showDBInfo()
{
	std::cout<<"____________________________________________________________________________"<<std::endl;
	std::cout<<"---NAME_Len : "<< (this->title_len).getData() <<std::endl;
	std::cout<<"\n---version : "<< (this->version).getData() <<std::endl;
	std::cout<<"\n---db_type : "<< (this->db_type).getData() <<std::endl;
	//std::cout<<"\n---time_stamp : "<< this->t_stamp <<std::endl;
	//std::cout<<"\n---nbr_of_sequences in DB : "<<this->N<<std::endl;
	//std::cout<<"\n---nbr_of_sequences in DB : "<<this->res_n<<std::endl;
	std::cout<<"____________________________________________________________________________"<<std::endl;
}


