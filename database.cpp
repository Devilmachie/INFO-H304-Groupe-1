#include "database.h"
#define GAP_PENALTY 11;
#define EXTENSION_PENALTY 1;

short BLOSUM[25*25] = {4,-1,-2,-2,0,-1,-1,0,-2,-1,-1,-1,-1,-2,-1,1,0,-3,-2,0,-2,-1,-1,-1,-4,-1,5,0,-2,-3,1,0,-2,0,-3,-2,2,-1,-3,-2,-1,-1,-3,-2,-3,-1,-2,0,-1,-4,-2,0,6,1,-3,0,0,0,1,-3,-3,0,-2,-3,-2,1,0,-4,-2,-3,4,-3,0,-1,-4,-2,-2,1,6,-3,0,2,-1,-1,-3,-4,-1,-3,-3,-1,0,-1,-4,-3,-3,4,-3,1,-1,-4,0,-3,-3,-3,9,-3,-4,-3,-3,-1,-1,-3,-1,-2,-3,-1,-1,-2,-2,-1,-3,-1,-3,-1,-4,-1,1,0,0,-3,5,2,-2,0,-3,-2,1,0,-3,-1,0,-1,-2,-1,-2,0,-2,4,-1,-4,-1,0,0,2,-4,2,5,-2,0,-3,-3,1,-2,-3,-1,0,-1,-3,-2,-2,1,-3,4,-1,-4,0,-2,0,-1,-3,-2,-2,6,-2,-4,-4,-2,-3,-3,-2,0,-2,-2,-3,-3,-1,-4,-2,-1,-4,-2,0,1,-1,-3,0,0,-2,8,-3,-3,-1,-2,-1,-2,-1,-2,-2,2,-3,0,-3,0,-1,-4,-1,-3,-3,-3,-1,-3,-3,-4,-3,4,2,-3,1,0,-3,-2,-1,-3,-1,3,-3,3,-3,-1,-4,-1,-2,-3,-4,-1,-2,-3,-4,-3,2,4,-2,2,0,-3,-2,-1,-2,-1,1,-4,3,-3,-1,-4,-1,2,0,-1,-3,1,1,-2,-1,-3,-2,5,-1,-3,-1,0,-1,-3,-2,-2,0,-3,1,-1,-4,-1,-1,-2,-3,-1,0,-2,-3,-2,1,2,-1,5,0,-2,-1,-1,-1,-1,1,-3,2,-1,-1,-4,-2,-3,-3,-3,-2,-3,-3,-3,-1,0,0,-3,0,6,-4,-2,-2,1,3,-1,-3,0,-3,-1,-4,-1,-2,-2,-1,-3,-1,-1,-2,-2,-3,-3,-1,-2,-4,7,-1,-1,-4,-3,-2,-2,-3,-1,-1,-4,1,-1,1,0,-1,0,0,0,-1,-2,-2,0,-1,-2,-1,4,1,-3,-2,-2,0,-2,0,-1,-4,0,-1,0,-1,-1,-1,-1,-2,-2,-1,-1,-1,-1,-2,-1,1,5,-2,-2,0,-1,-1,-1,-1,-4,-3,-3,-4,-4,-2,-2,-3,-2,-2,-3,-2,-3,-1,1,-4,-3,-2,11,2,-3,-4,-2,-2,-1,-4,-2,-2,-2,-3,-2,-1,-2,-3,2,-1,-1,-2,-1,3,-3,-2,-2,2,7,-1,-3,-1,-2,-1,-4,0,-3,-3,-3,-1,-2,-2,-3,-3,3,1,-2,1,-1,-2,-2,0,-3,-1,4,-3,2,-2,-1,-4,-2,-1,4,4,-3,0,1,-1,0,-3,-4,0,-3,-3,-2,0,-1,-4,-3,-3,4,-3,0,-1,-4,-1,-2,-3,-3,-1,-2,-3,-4,-3,3,3,-3,2,0,-3,-2,-1,-2,-1,2,-3,3,-3,-1,-4,-1,0,0,1,-3,4,4,-2,0,-3,-3,1,-1,-3,-1,0,-1,-2,-2,-2,0,-3,4,-1,-4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-4,-4,-4,-4,-4,-4,-4,-4,-4,-4,-4,-4,-4,-4,-4,-4,-4,-4,-4,-4,-4,-4,-4,-4,-4,1};


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
		//std::cout<<"Closed DB with extension : "<<mode<<std::endl;
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

int DataBase::fill_matrix(short*** scoring_m, char* found_sequence, int found_length, char* searched_sequence, int searched_length)
{
	short up_score;
	short left_score;
	short diag_score;
	//int min;
	short score;
	short highest_score=0;
	
	short h_gap;
	short v_gap[searched_length];
	
	//first NULL lines
	for (short i=0; i<=searched_length; i++)
		(*scoring_m)[0][i]=0;
	for (short i=1; i<=found_length; i++)
		(*scoring_m)[i][0]=0;
		
	for (short i=0; i<searched_length; i++)
		v_gap[i]=0;
		
	
	//fills the scoring matrix
	for (short i=1; i<=found_length; i++)
	{
		h_gap=0;
		
		for (short j=1; j<=searched_length; j++)
		{
			if ( !v_gap[j-1] ) 
				{ up_score = (*scoring_m)[i-1][j] - GAP_PENALTY; }
			else
				up_score = (*scoring_m)[i-1][j] - EXTENSION_PENALTY;
				
			if ( !h_gap )
				{ left_score = (int) (*scoring_m)[i][j-1] - GAP_PENALTY; }
			else
				left_score = (int) (*scoring_m)[i][j-1] - EXTENSION_PENALTY;
				
			diag_score = (int) (*scoring_m)[i-1][j-1] +  BLOSUM[25*(found_sequence[i-1]-1)+searched_sequence[j-1]-1];
			
			//max
			if(up_score<left_score)
			{
				if(diag_score<left_score)
					score=left_score;
				else
					score=diag_score;
			}
			else
			{
				if(diag_score<up_score)
					score=up_score;
				else
					score=diag_score;
			}
			
			
			if(score==up_score)
				v_gap[j-1]++;
			else
				v_gap[j-1]=0;
			
			if(score==left_score)
				h_gap++;
			else
				h_gap=0;
			
			
			(*scoring_m)[i][j]=score;
			
			if(score>highest_score)
				highest_score=score;
			 
		}
	}
		
	return highest_score;
	
}

bool DataBase::searchSequence(Sequence* searched_sequence)
{
        openDB(SEQUENCE);
	bool hasBeenFound = false, found_header = false;
	char* read_data = new char[*(max_s_len).getData()];
	uint32_t i_max = *(N).getData(),actual_offset=0,actual_size=0;
	uint32_t* offset_residue= (offset_r).getData();
	uint32_t* offset_header = (offset_h).getData();
	int score, header_size;
    	if(!is_open[SEQUENCE])
    	{
        	std::cout<<"DB couldn't be opened"<<std::endl;
        	return hasBeenFound;
    	}
	std::cout<<"Entering loop"<<std::endl;
	for(int i=0; i<i_max; i++)
	{
		actual_offset=*(offset_residue+i);
		actual_size=*(offset_residue+i+1)-*(offset_residue+i);
		fishData(read_in_db,read_data,actual_offset,actual_size);
		
		short** scoring_m = new short*[(actual_size+1)];
		for (short i=0; i<=actual_size; i++)
			scoring_m[i]=new short[(searched_sequence->getDataLen()+1)];
		
		score = fill_matrix(&scoring_m, read_data, actual_size-2, searched_sequence->getData(), searched_sequence->getDataLen()-1);
					
		if(score>50)
		{
			closeDB(SEQUENCE);
			openDB(HEADER);
			
			hasBeenFound=true;
			
			//finds header size and offset
			actual_offset=*(offset_header+i);
			header_size=*(offset_header+i+1)-actual_offset;
			char* full_header_name=new char[header_size];	
			std::cout<<"Sequence has been found at pos : "<<i<<" with offset : "<<actual_offset<< " and score : "<<score<<std::endl;	
			fishData(read_in_db,full_header_name,actual_offset,header_size);
			
			//only keeps clean string
			found_header=false;
			for (int j=0; !found_header; j++)
			{
				//find beginning of sequence
				if( full_header_name[j]==0x1A ){
					//find length
					header_size = (int) full_header_name[j+1];
					actual_offset = j+2;
					
					//if long header TO DO !!!!!!!
					if ( header_size < 0x00)
					{
						if (header_size != -127 )
							std::cout << "name too long : "<< header_size << std::endl;
						actual_offset++;
						header_size = (int) full_header_name[j+2]+256;
					}
					
					//makes sure next isn't another string/sequence/choice
					if (full_header_name[actual_offset]!=0x30 && full_header_name[actual_offset]!=0xA1 && full_header_name[actual_offset]!=0xA0 && full_header_name[actual_offset]!=0x1A )
					{
						found_header=true;
						char* header_name=new char[header_size]; 
						for (int k=0; k<header_size; k++)
							header_name[k]=full_header_name[actual_offset+k];
						delete full_header_name;
						std::cout<<header_name<<std::endl;
						delete header_name; 
					}
					
				}
			}
			
			//std::cout<<full_header_name<<std::endl;
			//delete full_header_name; 
			
			closeDB(HEADER);
			openDB(SEQUENCE);
		}
		
		for (int i=0; i<=actual_size; i++)
			delete scoring_m[i];
		delete scoring_m;
		
	}
	
	
	if(!hasBeenFound)
	{
		std::cout<<"No equivalence founded to : -> "<<std::endl;
		//std::cout<<searched_sequence->getData()<<std::endl;
	}
	delete read_data;
	return hasBeenFound;
	closeDB(SEQUENCE);
}


