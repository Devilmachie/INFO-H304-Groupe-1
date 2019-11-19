#include <iostream>
#include <fstream>

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
		BinaryData (std::ifstream & bfile,bool isTable=false,int sizeTable=1);
		~BinaryData();

		binfo getData() const;
		void changeEndianess();
};


