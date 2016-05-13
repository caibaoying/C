#include <iostream>
#include <windows.h>
#include <memory.h>
using namespace std;

class String
{
public:
	String(const char* str)
		:_str(new char(strlen(str) + 5))//"\0 和 写时拷贝的计数器 共计五个字节"
	{
		_str += 4;
		memcpy(_str, str, strlen(str) + 5);
		_GetRefCount(_str) = 1;
	}

	String(const String& s)
		:_str(s._str)
	{
		++_GetRefCount(_str);
	}

	String& operator = (const String& s)
	{
		if (_str != s._str)
		{
			_Release();
			_str = s._str;
			++_GetRefCount(_str);
		}
		return *this;
	}

	char& operator[] (size_t pos)
	{
		if (--_GetRefCount(_str) == 0)
		{
			return _str[pos];
		}
		//实现写时拷贝
		else
		{
			char* ptr = new char(strlen(_str) + 5);
			ptr += 4;
			memcpy(ptr, _str, strlen(ptr) + 5);
			_GetRefCount(_str) = 1;
			_str = ptr;
			--_GetRefCount(_str);
			return _str[pos];
		}
	}

	~String()
	{
		_Release();
	}
private:
	int& _GetRefCount(char* str)
	{
		return *((int *)str - 1);
	}
	void _Release()
	{
		if (--_GetRefCount(_str) == 0)
		{
			_str -= 4;
			delete[] _str;
			_str = NULL;
		}
	}
private:
	char* _str;
};
int main()
{
	String s1("hello");
	String s2(s1);
	String s3 = s2;
	cout << s3[0] << endl;
	s3[0] = 'x';
	cout << s3[0] << endl;
	cout << s2[0] << endl;
	cout << s1[0] << endl;
	system("pause");
	return 0;
}