#include <iostream>
using namespace std;

class Botany
{
public:
	Botany()
	{}
	Botany(const string& name)
		:_name(name)
	{
		cout << "Botany()" << endl;
	}
	virtual void Display()
	{
		cout << "Botany::Display()" << endl;
	}
protected:
	string _name;
};

class Tree : public Botany
{
	Tree(const string& name = "", float hight = 0)
	    :Botany(name)
	    , _hight(hight)
	{
		cout << "Tree()" << endl;
	}
	Tree(const Tree& t)
		:Botany(t)
		, _hight(t._hight)
	{
		cout << "Tree(const Tree& t)" << endl;
	}
	void operator = (const Tree& t)
	{
		if (this != &t)
		{
			_hight = t._hight;
			*((Botany*)this) = t;
		}
	}
	~Tree()
	{
		cout << "~Tree()" << endl;
	}
public:
	virtual void Display()
	{
		cout << "Tree::Display()" << endl;
	}
protected:
	float _hight;
};

