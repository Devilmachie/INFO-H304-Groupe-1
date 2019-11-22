#include "sequence.h"

std::map<char,int> Sequence::transcript;

Sequence::Sequence()
{
	data=NULL;
	name=NULL;
	data_len=0;
}
Sequence::~Sequence()
{
    if(data!=NULL)
        delete data;
    if(name!=NULL)
        delete name;
}
Sequence::Sequence(char* information,bool isDBPath)
{
	//std::cout<<"TEST"<<std::endl;
	init_map();
	if(isDBPath)
	{
		std::ifstream sequence_file;
		sequence_file.open(information);
		if(sequence_file)
		{
			//std::cout<<"TEST2"<<std::endl;			
			sequence_file.seekg(0,sequence_file.end);
			int size = sequence_file.tellg();
			sequence_file.seekg(0,sequence_file.beg);
			data = new char[size];
			//std::cout<<"TEST1"<<std::endl;			
			tr_data = new uint8_t[size];
			//std::cout<<"STILL OK"<<std::endl;
			sequence_file.read(data,size);
			data_len=strlen(data);
			name=NULL;
			
		}
		else
		{
			std::cout<<"Couldn't open sequence file"<<std::endl;
			data=NULL;
			data_len=0;
			name=NULL;
		}
	}
	else
	{
		data_len=std::strlen(information);		
		data=new char[data_len];
		data=information;
		name=NULL;
	}
	
	transcriptSequence();
}

void Sequence::setName(char* new_name)
{
	name=new_name;
}
void Sequence::setData(char* new_data)
{
	data=new_data;
}

string Sequence::getName() const
{
	return name;
}
string Sequence::getData() const
{
	return data;
}
int Sequence::getDataLen() const
{
	return data_len;
}

bool Sequence::operator==(const char* sequence)
{
	bool isSame = true;
	int i = 0;
	while(tr_data[i]&&sequence[i]&&isSame)
	{
		if(tr_data[i]!=sequence[i])
			isSame=false;
		i++;
	}

	return isSame;
}

void Sequence::transcriptSequence()
{
	char c;
	for(int i=0; c; i++)
	{
		c=data[i];
		tr_data[i]=this->transcript.find(c)->second;
	}	
}
void Sequence::init_map()
{
    transcript.insert( std::pair<char,int> ('A',1));
    transcript.insert( std::pair<char,int> ('B',2));
    transcript.insert( std::pair<char,int> ('C',3));
    transcript.insert( std::pair<char,int> ('D',4));
    transcript.insert( std::pair<char,int> ('E',5));
    transcript.insert( std::pair<char,int> ('F',6));
    transcript.insert( std::pair<char,int> ('G',7));
    transcript.insert( std::pair<char,int> ('H',8));
    transcript.insert( std::pair<char,int> ('I',9));
    transcript.insert( std::pair<char,int> ('J',27));
    transcript.insert( std::pair<char,int> ('K',10));
    transcript.insert( std::pair<char,int> ('L',11));
    transcript.insert( std::pair<char,int> ('M',12));
    transcript.insert( std::pair<char,int> ('N',13));
    transcript.insert( std::pair<char,int> ('O',26));
    transcript.insert( std::pair<char,int> ('P',14));
    transcript.insert( std::pair<char,int> ('Q',15));
    transcript.insert( std::pair<char,int> ('R',16));
    transcript.insert( std::pair<char,int> ('S',17));
    transcript.insert( std::pair<char,int> ('T',18));
    transcript.insert( std::pair<char,int> ('U',24));
    transcript.insert( std::pair<char,int> ('V',19));
    transcript.insert( std::pair<char,int> ('W',20));
    transcript.insert( std::pair<char,int> ('X',21));
    transcript.insert( std::pair<char,int> ('Y',22));
    transcript.insert( std::pair<char,int> ('Z',23));
    transcript.insert( std::pair<char,int> ('*',25));
    transcript.insert( std::pair<char,int> ('\0',0));
}
