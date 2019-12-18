#include "sequence.h"

std::map<char,int> Sequence::transcript;


Sequence::~Sequence()
{
    if(data!=NULL)
        delete data;
    if(name!=NULL)
        delete name;
}
Sequence::Sequence(char* sequence_path)
{
	string line,id,sequence;
	init_map();
	std::ifstream sequence_file;
	sequence_file.open(sequence_path);
	if(sequence_file)
	{	
		/*char c;
		int header_len = 0;
		bool notFinished = true;
		while(sequence_file>>c && notFinished)
		{
			if(c=='\n')
				notFinished=false;
			else
			{
				header_len++;
			}
		}
		header_len++;
		*/
		while(std::getline(sequence_file,line))
		{
			if(line.empty())
				continue;
			if(line[0]=='>')	
				id=line;
			else
				sequence += line;
		}
		name = new Header(id);	
		data = new char[sequence.length()+1];
		for(int i = 0;i<sequence.length();i++)
		{
			if(sequence[i]=='*')
				data[i]=25;
			else if(sequence[i]=='J')
				data[i]=27;
			else if(sequence[i]=='O')
				data[i]=26;
			else if(sequence[i]=='U')
				data[i]=24;
			else if(sequence[i]<74)
				data[i]=sequence[i]-64;
			else if(sequence[i]>85)
				data[i]=sequence[i]-67;
			else if(sequence[i]<79)
				data[i]=sequence[i]-65;
			else
				data[i]=sequence[i]-66;
		}
		data[sequence.length()]=0;
		/*cout <<"Still Ok2"<< endl;			
		for(int i = 0;i<size;i++)
		{
			sequence_file.read(&c,1);
			if(c!='\n')
			{
				data[pos]=c;
				pos++;
				
			}
		}
		data[pos]='\0'*/;
		//sequence_file.read(data,size);			
		tr_data = new uint8_t[sequence.length()+1];
		data_len=strlen(data);	
		transcriptSequence();
		cout << endl << name->getName() << endl;
		cout << "____________________________________________________________________________" << endl << endl;		
	}
	else
	{
		cout << "Couldn't open sequence file" << endl;
		data=NULL;
		data_len=0;
		name=NULL;
	}
	sequence_file.close();
	
}

void Sequence::setName(Header* new_name)
{
	delete name;
	name=new_name;
}
void Sequence::setData(char* new_data)
{
	data=new_data;
}

string Sequence::getName() const
{
	return name->getName();
}
char* Sequence::getData() const
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
	while(i<data_len && isSame) // si tr_data[i]==0 or 
	{
		if(tr_data[i]!=sequence[i])
		{
			isSame=false;

		}
		i++;
	}

	return isSame;
}

void Sequence::transcriptSequence()
{
	char c;
	for(int i=0; data[i]; i++)
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


