#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

unsigned long read32(ifstream& file) //reads 4 bytes and stiches them together
{
	char bytes[4]={0,0,0,0};
	file.read(bytes, 4);
	unsigned long int32 = 0;
	for(int i=0; i<4; i++)
	{
		if(bytes[3-i]<0)
			int32 += (unsigned long)((unsigned char) bytes[3-i]) * (unsigned long) pow(2, i*8);
		else
			int32 += (unsigned long) bytes[3-i] * (unsigned long) pow(2, i*8);
	}
	return int32;
}

unsigned long long read64(ifstream& file) //will read 64 bits in little endian, but doesn't for now
{
	read32(file); read32(file);
	return 0;
}

vector<char> read_hex(ifstream& file,unsigned long length)
{	
	char sequence_array[length];
	file.read(sequence_array, length);
	vector<char> sequence_vector;
	for(int i=0; i< length; i++)
		sequence_vector.push_back(sequence_array[i]);
	return sequence_vector;
}

int main(int argc, char *argv[])
{
	if(argc==3)
	{
		//opening files
		ifstream pin_file ((string) argv[1] + ".pin", ios::in|ios::binary|ios::ate);
		ifstream psq_file ((string) argv[1] + ".psq", ios::in|ios::binary|ios::ate);
		ifstream phr_file ((string) argv[1] + ".phr", ios::in|ios::binary|ios::ate);

		ifstream pin_ref_file ((string) argv[2] + ".pin", ios::in|ios::binary|ios::ate);
		ifstream psq_ref_file ((string) argv[2] + ".psq", ios::in|ios::binary|ios::ate);
		ifstream phr_ref_file ((string) argv[2] + ".phr", ios::in|ios::binary|ios::ate);

		//guud sequences
		vector<unsigned long> ids;
		vector<vector<char>> sequences; vector<vector<char>> headers; 
		vector<char> sequence; vector<char> header;

		//reference index
		unsigned long ref_version;
		unsigned long ref_title_length;
		char* ref_title;
		unsigned long ref_timestamp_length;
		char* ref_timestamp;
		
		unsigned long ref_header_length;
		vector<char> ref_header;
		unsigned long ref_seq_length;
		vector<char> ref_sequence;

		//index
		unsigned long version;
		unsigned long title_length;
		char* title;
		unsigned long timestamp_length;
		char* timestamp;
		unsigned long n_sequences;
		unsigned long long residue_count;
		unsigned long max_sequence;

		unsigned long sequence_length;
		unsigned long s_offset; //sequence offset
		unsigned long ns_offset; //next sequence offset
		unsigned long header_length;
		unsigned long h_offset; //header offset 
		unsigned long nh_offset; //next header offset

		unsigned short filler;

		if(pin_file.is_open() && psq_file.is_open() && phr_file.is_open() && pin_ref_file.is_open() && psq_ref_file.is_open() && phr_ref_file.is_open() )
		{
			//start at beginning of file
			pin_ref_file.seekg (0, ios::beg);
			psq_ref_file.seekg (0, ios::beg);
			phr_ref_file.seekg (0, ios::beg);

			//reference index building
			ref_version = read32(pin_ref_file); 
			read32(pin_ref_file);  //it's a protein sequence, balekouilles
			ref_title_length = read32(pin_ref_file); 
			char ref_title[ref_title_length]; 
			pin_ref_file.read(ref_title, ref_title_length);
			ref_timestamp_length = read32(pin_ref_file); 
			char ref_timestamp[ref_timestamp_length];
			pin_ref_file.read(ref_timestamp, ref_timestamp_length); 
			filler = 8 - ((ref_title_length + ref_timestamp_length) %8);
			if(filler!=8)
				read_hex(pin_ref_file, filler);
			read32(pin_ref_file); //there is only 1 sequence
			read64(pin_ref_file); //same, balek
			ref_seq_length = read32(pin_ref_file); 
			read_hex(psq_ref_file, 1);
			ref_sequence = read_hex(psq_ref_file, ref_seq_length);
			read32(pin_ref_file);
			ref_header_length = read32(pin_ref_file); 
			ref_header = read_hex(phr_ref_file, ref_header_length);
		
			//start at beginning of file
			pin_file.seekg (0, ios::beg);
			psq_file.seekg (0, ios::beg);
			phr_file.seekg (0, ios::beg);
			
			//index building
			version = read32(pin_file); 
			read32(pin_file);  //it's a protein sequence, balekouilles
			title_length = read32(pin_file);
			char title[title_length]; 
			pin_file.read(title, title_length); 
			timestamp_length = read32(pin_file);
			char timestamp[timestamp_length]; 
			pin_file.read(timestamp, timestamp_length);
			filler = 8 - ((title_length + timestamp_length) %8);
			if(filler!=8)
				read_hex(pin_file, filler);
			n_sequences = read32(pin_file); 
			residue_count = read64(pin_file);
			max_sequence = read32(pin_file); 

			ns_offset = read32(pin_file); 
			
			//header reading loop (first loop doesn't actually read, just skips)
			for(unsigned long i=0; i<n_sequences; i++)
				read32(pin_file);

			ns_offset = read32(pin_file);
			
			//sequence reading loop
			for(unsigned long i=0; i<n_sequences; i++)
			{
				s_offset = ns_offset;
				ns_offset = read32(pin_file); 
				sequence_length = ns_offset - s_offset -1;
				read_hex(psq_file, 1);
				sequence = read_hex(psq_file, sequence_length);
				if(sequence == ref_sequence)
				{
					cout << "weeeeeee "<< i << endl;
					ids.push_back(i);
					sequences.push_back(sequence);
				}
			
			}

			//header reading loop (second one)
			pin_ref_file.close();
			ifstream pin_ref_file ((string) argv[2] + ".pin", ios::in|ios::binary|ios::ate);
			pin_ref_file.seekg (0, ios::beg); 
			
			read32(pin_file); read32(pin_file); read32(pin_file); 
			pin_file.read(title, title_length); 
			read32(pin_file);
			pin_file.read(timestamp, timestamp_length);
			filler = 8 - ((ref_title_length + ref_timestamp_length) %8);
			if(filler!=8)
				read_hex(pin_ref_file, filler);
			read32(pin_file);read64(pin_file); read32(pin_file);

			nh_offset = read32(pin_file);
			unsigned int j = 0; //counter in ids
			for(unsigned long i=0; i<n_sequences; i++)
			{
				h_offset = nh_offset;
				nh_offset = read32(pin_file); 
				header_length = nh_offset - h_offset;
				header = read_hex(psq_file, header_length);
				if(ids[j]==i)
				{
					j++;
					headers.push_back(header);
				}			
			}
		
		}

		pin_file.close();
		psq_file.close();
		phr_file.close();

		pin_ref_file.close();
		psq_ref_file.close();
		phr_ref_file.close();
	}
	return 0;
}









