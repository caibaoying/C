#include <iostream>
#include <memory.h>
#include <string>
using namespace std;

class String
{
public:
	String(const char* str = "")
	{
		int len = strlen(str);
		_size = len;
		_capacity = len + 1;
		_str = new char[_capacity];
		memcpy(_str, str, _capacity);
	}

	void _Swap(String& s)
	{
		swap(_str, s._str);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}

	String(const String& s) 
		:_str(NULL)
	{
		String tmp(s);
		_Swap(tmp);
	}

	String& operate = (String s)
	{
		_Swap(s);
		return *this;
	}
	~String()
	{

	}
private:
	size_t _size;
	size_t _capacity;
	char* _str;
};

int main()
{

	return 0;
}