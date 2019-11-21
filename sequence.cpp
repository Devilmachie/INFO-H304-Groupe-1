#include "sequence.h"
#include <cstring>
bool intcmp(uint8_t* data,const char* seq);
Sequence::Sequence()
{
	data=NULL;
	name=NULL;
	data_len=0;
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
			data_len=std::strlen(data);
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
	bool isSame=intcmp(tr_data,sequence);
	return isSame;
}
bool intcmp(uint8_t* data, const char* seq)
{
	bool isSame = true;
	int i = 0;
	while(data[i]&&seq[i]&&isSame)
	{
		if(data[i]!=seq[i])
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
		tr_data[i]=transcript->find(c)->second;
		//std::cout<<"i is : "<<i<<" and c is : "<<c<<" corresponding to : "<<tr_data[i]<<std::endl;
	}	
}
void Sequence::init_map()
{
	transcript = new std::map<char,int>();
	std::map<char,int> & tmp = *transcript;
	tmp['A']=1;
	tmp['B']=2;
	tmp['C']=3;
	tmp['D']=4;
	tmp['E']=5;
	tmp['F']=6;
	tmp['G']=7;
	tmp['H']=8;
	tmp['I']=9;
	tmp['J']=27;
	tmp['K']=10;
	tmp['L']=11;
	tmp['M']=12;
	tmp['N']=13;
	tmp['O']=26;
	tmp['P']=14;
	tmp['Q']=15;
	tmp['R']=16;
	tmp['S']=17;
	tmp['T']=18;
	tmp['U']=24;
	tmp['V']=19;
	tmp['W']=20;
	tmp['X']=21;
	tmp['Y']=22;
	tmp['Z']=23;
	tmp['*']=25; 	
	tmp['\0']=0;
	
}
