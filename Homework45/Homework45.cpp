#include <iostream>
using namespace std;
class MyString
{
	friend MyString operator +(int delta, MyString right)
	{
		char mas[1000];
		for (int i = 0; i < delta; i++)
		{
			mas[i] = 'x';
		}
		for (int i = 0; i < right.size; i++)
		{
			mas[delta + i] = right.str[i];
		}
		mas[delta + right.size] = 0;
		return MyString(mas);
	}
	int size = 0;
	char* str = nullptr;
public:

	static int count;
	MyString()
	{
		Clear();
		str = new char[80];
		size = 80;
		for (int i = 0; i < size; i++) str[i] = '*';
		str[size - 1] = 0;
		count++;
	}
	MyString(const MyString& r)
	{
		SetStr(r.str);
		count++;
	}
	MyString(int size)
	{
		Clear();
		str = new char[size + 1];
		this->size = size;
		str[size - 1] = 0;
		for (int i = 0; i < size; i++) str[i] = '*';
		count++;
	}
	MyString(const char* str)
	{
		SetStr(str);
		count++;
	}
	~MyString()
	{
		Clear();
		count--;
	}
	void SetStr(const char* str)
	{
		Clear();
		int length = strlen(str);
		this->str = new char[length + 1];
		this->size = length;
		for (int i = 0; i <= length; i++)
		{
			this->str[i] = str[i];
		}
	}
	char* GetStr()
	{
		return str;
	}
	void Clear()
	{
		if (str != nullptr)
		{
			delete[] str;
		}
	}
	void Print()
	{
		cout << str << endl;
	}
	static int GetCount()
	{
		return count;
	}
	void Read(const char* mesagge)
	{
		char mas[250];
		cout << mesagge << ": ";
		cin.getline(mas, 250);
		SetStr(mas);
	}
	MyString operator +(int delta)
	{
		if (delta < 0) return *this - (-delta);
		char mas[1000];
		for (int i = 0; i < size; i++)
			mas[i] = str[i];
		for (int i = 0; i < delta; i++)
			mas[size + i] = 'x';
		mas[size + delta] = 0;
		return MyString(mas);
	}
	MyString operator -(int delta)
	{
		if (delta < 0) return *this + (-delta);
		char mas[1000];
		int newsize = size - delta;
		if (newsize < 0) newsize = 0;
		for (int i = 0; i < newsize; i++)
			mas[i] = str[i];
		mas[newsize] = 0;
		return MyString(mas);
	}
	void Plus(int delta)
	{
		if (delta < 0) return Minus(-delta);
		char mas[1000];
		for (int i = 0; i < size; i++)
			mas[i] = str[i];
		for (int i = 0; i < delta; i++)
			mas[size + i] = 'x';
		mas[size + delta] = 0;
		SetStr(mas);
	}
	void Minus(int delta)
	{
		if (delta < 0) return Plus(-delta);
		char mas[1000];
		int newsize = size - delta;
		if (newsize < 0) newsize = 0;
		for (int i = 0; i < newsize; i++)
			mas[i] = str[i];
		mas[newsize] = 0;
		SetStr(mas);
	}
	//2
	MyString operator++(int) 
	{
		MyString x(*this);
		x.Plus(1);
		return x;
	}

	MyString operator--(int) 
	{
		MyString x(*this);
		x.Minus(1);
		return x;
	}

	MyString operator ++()
	{
		Plus(1);
		return MyString(*this);

	}

	MyString operator --()
	{
		Minus(1);
		return MyString(*this);
	}

	MyString operator =(MyString& x)
	{
		SetStr(x.GetStr());
		return *this;
	}
};
int MyString::count = 0;

int main()
{

	int k = 2;
	MyString str1;
	str1.Read("Введите 1 строку");
	//str1.Print();
	MyString str2 = str1 + (-4);
	//str2.Print();

	//MyString str3 =  str1 + 3;
	//str3.Print();
	//MyString str4 = ++str3;
	//str3.Print();
	//str4.Print();
	//MyString str5 = --str4;
	//str4.Print();
	//str5.Print();
	MyString str6 = ++str1;
	str1.Print();
	str6.Print();
	MyString str7 = str1++;
	str1.Print();
	str7.Print();
	MyString str8 = --str1;
	str1.Print();
	str8.Print();
	MyString str9 = str1--;
	str1.Print();
	str9.Print();
	str9 = str1;
	str1.Print();
	str9.Print();

	
}