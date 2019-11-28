#include "header.h"

Header::Header(ifstream & header_file,unsigned long int offset,unsigned long int header_size)
{
	std::cout<<"Header size is : "<<header_size<<std::endl;
	obj_arr = new char[header_size];
	memory_allocated.push_back(obj_arr);
	size_to_parse=header_size;
	header_file.seekg(offset,header_file.beg);
	header_file.read(obj_arr,header_size);
	current_obj=obj_arr;
	last_obj=obj_arr + header_size ;
	for (int i = 0; i<header_size;i++)
		std::cout<<std::hex<<(int)obj_arr[i]<<"|";
	std::cout<<""<<std::endl;


	next=*(current_obj);
	nextObj();
	

	
}
Header::Header(std::string & name)
{
	parsed_string=new char[name.length()+1];
	for(int i = 0;i<name.length();i++)
		parsed_string[i]=name[i];
	parsed_string[name.length()]='\0';
	std::cout<<"Still Ok"<<std::endl;
	memory_allocated.push_back(parsed_string);
}

Header::~Header()
{
	for (int i = 0; i < memory_allocated.size(); i++) 
        	delete memory_allocated[i];
}

char* Header::getName()
{
	return parsed_string;
}
void Header::nextCh()
{
	if (current_obj < last_obj)
		next = *(current_obj)++;
	else
	{
    		next = 0;
		std::cout<<"Setted to 0"<<std::endl;
	}
}

void Header::nextObj()
{
	obj = next;
 	nextCh();
	len = next;
	nextCh( );
}
void Header::matchObj(unsigned short match)
{
	if (obj != match)
    	{
		std::cout<<"Error expected : "<< match << "and got :"<< obj<<std::endl;
    	}
  	nextObj();
}

void Header::parseInteger()
{
	parsed_integer=0;
	unsigned long length = len;
	std::cout<<"Obj type is : "<<obj<<" and len is : "<<len<<std::endl;
	if( length > 0 && length <= INT_SIZE)
	{
		for(int i = 0 ; i<length ; i++)
		{
			parsed_integer = (parsed_integer << 8) | next;
			nextCh();
		}
	}
	else
		std::cout<<"Couldn't parse integer because size isn't is of a int"<<std::endl;
	
	nextObj();
}

void Header::parseVisibleString(char* container)
{
	unsigned long length = len;
	if (len == 0x81)
	{
        	len = next;
        	nextCh();
        }
	else if ( len == 0x82 )
	{
		length = next;
		nextCh();
		length = (length << 8) | next;
      		nextCh();
	}
	else if (len > 0x82)
	{
		std::cout<<"Couldn't parse visible string because size isn't is of a string"<<std::endl;
	}
	container = new char[length];
	memory_allocated.push_back(container);

	for(int i = 0;i<length;i++)
	{
		parsed_string[i]=next;
		nextCh();
	}

	nextObj();
}

/*void Header::parseChoice()
{
	if (next==0x80)
	{
		nextCh();
		nextObj();
		std::cout<<"Begin of the choice"<<std::endl;
		parseIdentifier();
		if(next == 0 && len == 0)
		{
			std::cout<<"End of the choice"<<std::endl;
			nextCh();
			nextObj();
		}
		else
			std::cout<<"Couldn't Read Choice"<<std::endl;
	}
	else 
		std::cout<<"Wrong Choice identifier"<<std::endl;
}*/
