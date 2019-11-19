#include "bdata.h"

template <class binfo>
BinaryData<binfo>::BinaryData()
{
	this->isTable=false;
	this->sizeTable=0;
	this->size_binfo=0;
	this->bdata=NULL; 
}

template <class binfo>
BinaryData<binfo>::BinaryData(std::ifstream & bfile,bool isTable,int sizeTable)
{
	this->isTable=isTable;
	this->sizeTable=sizeTable;
	this->size_binfo=sizeof(binfo);
	this->bdata = new binfo[sizeTable];
	bfile.read((char*)(this->bdata), (this->sizeTable)*(this->size_binfo));
	this->changeEndianness();
}

template <class binfo>
BinaryData<binfo>::~BinaryData()
{
	delete (this->bdata) ;
}

template <class binfo>
binfo BinaryData<binfo>::getData() const
{
	return (this->bdata);
}

template <class binfo>
void BinaryData<binfo>::changeEndianess()
{
	if(typeid(*this->bdata).name()=="uint32_t")
		for(int i = 0;i<this->sizeTable;i++)
			*(this->bdata + i) = __builtin_bswap32(*(this->bdata + i));
	
}
