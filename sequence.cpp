#include "sequence.h"

Sequence::Sequence()
{
	data="";
	name="";
	data_len=0;
}

Sequence::Sequence(string information)
{
	data=information;
	data_len=data.length();
	name="";
}

void Sequence::setName(string new_name)
{
	name=new_name;
}
void Sequence::setData(string new_data)
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
bool Sequence::operator==(const Sequence & other_sequence)
{
	bool isSame=false;
	if(data_len==other_sequence.getDataLen())
		if(data==other_sequence.getData())
			isSame=true;
	return isSame;
}
