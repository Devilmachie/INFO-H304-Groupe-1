#include <iostream>
#include <fstream>
#include <typeinfo>

template <class binfo>

class BinaryData
{
	private:
		bool isTable;
		int sizeTable;
		int size_binfo;
		binfo* bdata; //pointeur qui pointe vers un type const (!= binfo* const bdata qui est un pointeur constant)
		
		
	public:
		BinaryData ();
		void setData(std::ifstream & bfile,bool isTable=false,int sizeTable=1);
		~BinaryData();

		binfo* getData() ;
		void changeEndianess();
};

template <class binfo>
BinaryData<binfo>::BinaryData()
{
	this->isTable=false;
	this->sizeTable=0;
	this->size_binfo=0;
	this->bdata=NULL; 
}

template <class binfo>
void BinaryData<binfo>::setData(std::ifstream & bfile,bool isTable,int sizeTable)
{
	this->isTable=isTable;
	this->sizeTable=sizeTable;
	this->size_binfo=sizeof(binfo);
	this->bdata = new binfo[sizeTable];
	bfile.read((char*)(this->bdata), (this->sizeTable)*(this->size_binfo));
	changeEndianess();
	//std::cout<<"Read data are : "<< this->bdata <<" of the type "<<" and is of size : "<<this->sizeTable<<std::endl;
	
}

template <class binfo>
BinaryData<binfo>::~BinaryData()
{
	std::cout<<"DESTRUCTEUR BDATA APPELE"<<std::endl;
	delete (this->bdata) ;
}

template <class binfo>
binfo* BinaryData<binfo>::getData() 
{
	return (this->bdata);
}

template <class binfo>
void BinaryData<binfo>::changeEndianess()
{
	if(typeid(*this->bdata)==typeid(uint32_t))
		{
			for(int i = 0;i<this->sizeTable;i++)
				*(this->bdata + i) = __builtin_bswap32(*(this->bdata + i));
			//std::cout<<"Endianess changé : "<<this->sizeTable<<"fois"<<std::endl;
		}
	
}
