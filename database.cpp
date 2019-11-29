#include "database.h"

DataBase::DataBase(char* db_name)
{
	is_open.insert(std::pair<char*,bool>(GENERAL,false));
	is_open.insert(std::pair<char*,bool>(HEADER,false));
	is_open.insert(std::pair<char*,bool>(SEQUENCE,false));
	path_to_db=db_name;
	init_db();
}

DataBase::~DataBase()
{
	std::map<char*, bool>::iterator it;
	for (it = is_open.begin(); it != is_open.end() ; it++)
	{
		if(it->second)
			closeDB(it->first);
	}
	
}

bool DataBase::anotherDBAlreadyOpen()
{
	bool isAlreadyOpen=false;
	std::map<char*, bool>::iterator it;
	for (it = is_open.begin(); it != is_open.end() && !isAlreadyOpen; it++)
        {
        	if(it->second)
		{
			isAlreadyOpen=true;
			std::cout<<"DB file is already opened with extension : "<<it->first<<std::endl;
		}
        }
	return isAlreadyOpen;
}
void DataBase::openDB(char* mode)
{
	if(!anotherDBAlreadyOpen())
	{
		string db_path = (string) path_to_db + mode;
		read_in_db.open(db_path,ios::in|ios::binary);	
		if(read_in_db)	
			is_open[mode]=true;
		else 
			std::cout<<"problem with opening file with extension : "<<mode<<std::endl;
	}

}

void DataBase::closeDB(char* mode)
{
	if(is_open[mode])
	{
		read_in_db.close();
		is_open[mode]=false;	
		std::cout<<"Closed DB with extension : "<<mode<<std::endl;
	}
}


void DataBase::init_db()
{
	openDB(GENERAL);
	if(is_open[GENERAL])
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

		closeDB(GENERAL);
	}
	else
		std::cout<<"DB couldn't be open"<<std::endl;
	
}

void DataBase::showDBInfo()
{
	std::cout<<"____________________________________________________________________________"<<std::endl;
	std::cout<<"---NAME_Len : "<< (title).getData() <<std::endl; // recoit un pointeur vers 
	std::cout<<"\n---version : "<< *(version).getData() <<std::endl;
	std::cout<<"\n---db_type : "<< *(db_type).getData() <<std::endl;
	std::cout<<"\n---time_stamp : "<< (t_stamp).getData() <<std::endl;
	std::cout<<"\n---nbr_of_sequences in DB : "<<*(N).getData() <<std::endl;
	std::cout<<"\n---longest sequence in DB : "<<*(max_s_len).getData() <<std::endl;
	std::cout<<"____________________________________________________________________________"<<std::endl;
}

void DataBase::fishData(ifstream & fp,char* buffer,uint32_t offset,uint32_t size)
{
	fp.seekg(offset,fp.beg);
	fp.read(buffer,size);
}

bool DataBase::searchSequence(Sequence* searched_sequence)
{
        openDB(SEQUENCE);
	bool hasBeenFound = false;
	char* read_data = new char[*(max_s_len).getData()];
	uint32_t i_max = *(N).getData(),actual_offset=0,actual_size=0;
	uint32_t* offset_residue= (offset_r).getData();
	uint32_t* offset_header = (offset_h).getData();
    	if(!is_open[SEQUENCE])
    	{
        	std::cout<<"DB couldn't be opened"<<std::endl;
        	return hasBeenFound;
    	}
	std::cout<<"Entering loop"<<std::endl;
	for(int i=0; i<i_max && !hasBeenFound; i++)
	{
		actual_offset=*(offset_residue+i);
		actual_size=*(offset_residue+i+1)-*(offset_residue+i);
		if(searched_sequence->getDataLen() == actual_size-1) // cause character 0 counts
		{

			fishData(read_in_db,read_data,actual_offset,actual_size);				
			if(*searched_sequence==read_data)
			{
		    		closeDB(SEQUENCE);
				openDB(HEADER);
				hasBeenFound=true;
				actual_offset=*(offset_header+i);
				actual_size=*(offset_header+i+1)-*(offset_header+i);
				char* header_name=new char[actual_size];	
				std::cout<<"Sequence has been found at pos : "<<i<<" with offset : "<<actual_offset<<std::endl;	
				fishData(read_in_db,header_name,actual_offset,actual_size);
				std::cout<<header_name<<std::endl;
				delete header_name;
			}
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


