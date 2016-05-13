#include <iostream>
#include <memory.h>
#include <string>
#include <windows.h>
#include <assert.h>
using namespace std;

class String
{
public:
	String(const char* str = "")
	{
		int len = strlen(str);
		_size = len;
		_capacity = len + 1;
		_str = new char [_capacity];
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

	String& operator = (String s)  //copy
	{
		_Swap(s);
		return *this;
	}

	void Display(String& s)
	{
		char* str = s._str;
		int i = 0;
		while (*str)
		{
			cout << str[i];
			++i;
		}
		cout << endl;
	}

	//模拟string的部分功能
	void PushBack(char ch);
	void Insert(size_t pos, const char ch);
	void Insert(size_t pos, const char* str);
	char& operator[](size_t index);
	int Find(const char ch);
	int Find(const char* str);  //hello wor->6("wor")
	bool Erase(size_t pos);
	bool Erase(size_t pos, size_t n);

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = NULL;
		}
	}
private:
	void _checkCapacity(size_t size)
	{
		if (size > _capacity)
		{
			_capacity = ((size > 2 * _capacity) ? size : 2 * _capacity);
		}
		_str = (char*)realloc(_str, _capacity);
	}

	
private:
	char* _str;
	size_t _size;
	size_t _capacity;
};

void String::PushBack(char ch)
{
	_checkCapacity(_size + 2);
	_str[_size++] = ch;
	_str[_size] = '\0';
}

void String::Insert(size_t pos,const char ch)
{
	assert(pos <= _size);
	_checkCapacity(_size + 2);
	size_t end = _size;
	while (end >= pos)
	{
		_str[end + 1] = _str[end];
		--end;
	}
	_str[pos] = ch;
	_size++;
}

void String::Insert(size_t pos,const char* str)
{
	assert(pos <= _size);
	int len = strlen(str);
	_checkCapacity(_size + 1 + len);

	size_t end = _size;
	while (end >= pos)
	{
		_str[end + len] = _str[end];
		--end;
	}
	while (*str)
	{
		_str[pos++] = *str++;
	}
	_size += len;
}

char& String::operator[](size_t index)
{
	assert(index >= 0 && index <= _size);
	return _str[index];
}

int String::Find(const char ch)
{
	char* str(_str);
	while (*str)
	{
		if (*str == ch)
		{
			return (str - _str + 1);
		}
		str++;
	}
	return -1;
}

int String::Find(const char* str)
{
	//一个是this .另一个是str
	//两个比较
	char* str1 = _str;
	char* str2 = _str;
	int flag = 1;   //标记下标
	const char* str3 = str;
	while (*str2 && *str3)
	{
		if (*str2 == *str3)
		{
			str2++;
			str3++;
		}
		if (*str2 != *str3)
		{
			if (*str3 == '\0' && *str2)
			{
				return flag;
			}
			else if (*str3 != '\0')
			{
				str3 = str;
				str1++;
				flag++;
				str2 = str1;
			}
		}

	}
	if (*str2 == '\0' && *str3 == '\0')
	{
		return flag;
	}
	else
	{
		return -1;
	}
}

bool String::Erase(size_t pos)
{
	if (pos > _size)
	{
		return false;
	}
	size_t end = pos;
	while (end <= _size)
	{
		_str[end - 1] = _str[end];
		++end;
	}
	_size--;
	return true;
}

bool String::Erase(size_t pos, size_t n)
{
	if ((pos > _size) || ((pos + n) >_size))
	{
		return false;
	}
	while (n > 0)
	{
		Erase(pos);
		n--;
	}
	return true;
}

void test_string()
{
	string s1("1232435");
	s1.push_back('s');
	cout << s1 << endl;
	//cout << s1.c_str[]
}

void test1()
{
	String s1("hello world");
	//s1.PushBack('6');

	s1.Insert(6, 2);
	//s1.Display(s1);
	s1.Insert(6,"1234");

	s1[2] = 'x';

	cout << s1.Find('h') << endl;

	String s2("hello");
	cout << s2.Find("hello") << endl;
	//s2.Erase(1);
	s2.Erase(1, 2);
}

int main()
{
	//test_string();
	test1();
	system("pause");
	return 0;

}