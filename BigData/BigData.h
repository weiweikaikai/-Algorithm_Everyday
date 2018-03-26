
#include <string>
#include <iostream>
#include<string.h>
using namespace std;

#define UN_INIT 0xcccccccccccccccc
#define MAX_INT64 0x7fffffffffffffff
#define MIN_INT64 0x8000000000000000

typedef long long INT64;

class BigData
{
public:
	BigData(INT64 data = UN_INIT);
	BigData(const char *pData);

	BigData operator+(BigData& bigData);
	BigData operator-(const BigData& bigData);

	bool operator<(const BigData& bigData);
	bool operator>(const BigData& bigData);
	bool operator==(const BigData& bigData);
	
	friend std::ostream& operator<<(std::ostream& _cout, const BigData& bigData);
	friend std::istream& operator>>(std::istream& _cin, BigData bigData);
	
private:
	std::string Add(std::string left, std::string right);
	std::string Sub(std::string left, std::string right);

	void INT64ToString();
	bool IsINT64Owerflow()const;
private:
	long long m_llValue;
	std::string m_strData;
};



