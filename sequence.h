#include <string>
using std::string;

class Sequence
{
private:
	string name;
	string data;
	int data_len;
public:
	Sequence();
	Sequence(string information);

	void setName(string name);
	void setData(string data);

	string getName() const;
	string getData() const;
	int getDataLen() const;
	bool operator== (const Sequence & other_sequence);
};
