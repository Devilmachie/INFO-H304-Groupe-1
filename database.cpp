#include "database.h"


DataBase::DataBase(string db_name)
{
	this->path_to_db=db_name;
	init_db();
}

DataBase::~DataBase()
{
	closeDB();
	
}


void DataBase::openDB()
{
	ifstream & db = this->read_in_db;
	const char* db_path = (this->path_to_db).c_str();
	db.open(db_path,ios::in|ios::binary);	
	if(db.is_open())	
		this->is_open=true;
	else 
		std::cout<<"problem with opening file"<<std::endl;
		
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
		this->version.setData(this->read_in_db);
		this->db_type.setData(this->read_in_db);
		this->title_len.setData(this->read_in_db);
		this->title.setData(this->read_in_db, true, *(this->title_len).getData());
		this->t_stamp_len.setData(this->read_in_db);
		this->t_stamp.setData(this->read_in_db, true, *(this->t_stamp_len).getData());
		this->N.setData(this->read_in_db);
		this->res_n.setData(this->read_in_db);
		this->max_s_len.setData(this->read_in_db);
		this->offset_h.setData(this->read_in_db, true, *(this->N).getData() + 1);
		this->offset_r.setData(this->read_in_db, true, *(this->N).getData() + 1);

		if(*(this->db_type).getData() == IS_DNA)
			this->offset_a.setData(this->read_in_db, true, *(this->N).getData() + 1);
		
	}
	else
		std::cout<<"DB couldn't be open"<<std::endl;
	
}

void DataBase::showDBInfo()
{
	std::cout<<"____________________________________________________________________________"<<std::endl;
	std::cout<<"---NAME_Len : "<< (this->title).getData() <<std::endl; // recoit un pointeur vers 
	std::cout<<"\n---version : "<< *(this->version).getData() <<std::endl;
	std::cout<<"\n---db_type : "<< *(this->db_type).getData() <<std::endl;
	std::cout<<"\n---time_stamp : "<< (this->t_stamp).getData() <<std::endl;
	std::cout<<"\n---nbr_of_sequences in DB : "<<*(this->N).getData() <<std::endl;
	std::cout<<"\n---longest sequence in DB : "<<*(this->max_s_len).getData() <<std::endl;
	std::cout<<"____________________________________________________________________________"<<std::endl;
}

void DataBase::fishData(ifstream & fp,char* buffer,uint32_t offset,uint32_t size)
{
	fp.seekg(offset,fp.beg);
	fp.read(buffer,size);
}

bool DataBase::searchSequence(Sequence* searched_sequence, char* header_path, char* residue_path)
{
    ifstream fp;
    fp.open(residue_path,ios::in|ios::binary);
	bool hasBeenFound = false;
	char* read_data = new char[*(this->max_s_len).getData()];
	uint32_t i_max = *(this->N).getData(),actual_offset=0,actual_size=0;
	uint32_t* offset_residue= (this->offset_r).getData();
	uint32_t* offset_header = (this->offset_h).getData();
    if(!fp)
    {
        std::cout<<"DB couldn't be opened"<<std::endl;
        return hasBeenFound;
    }
	std::cout<<"Entering loop"<<std::endl;
	for(int i=0; i<i_max && !hasBeenFound; i++)
	{
        if(i%10 ==0)
            std::cout<<i<<std::endl;
		actual_offset=*(offset_residue+i);
		actual_size=*(offset_residue+i+1)-*(offset_residue+i);
		fishData(fp,read_data,actual_offset,actual_size);
		if(*searched_sequence==read_data)
		{
            fp.close();
            fp.open(header_path,ios::in|ios::binary);
			std::cout<<"Sequence has been found : "<<std::endl;
			hasBeenFound=true;
			actual_offset=*(offset_header+i);
			actual_size=*(offset_header+i+1)-*(offset_header+i);		
			char* header_sequence = new char[actual_size];
			fishData(fp, header_sequence,actual_offset,actual_size);
			searched_sequence->setName(header_sequence);
			std::cout<<(searched_sequence->getName())<<std::endl;
			
		}
		
	}
	if(!hasBeenFound)
	{
		std::cout<<"No equivalence founded to : -> "<<std::endl;
		std::cout<<searched_sequence->getData()<<std::endl;
	}
	delete read_data;
	return hasBeenFound;
}
