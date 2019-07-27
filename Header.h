#include<iostream>
#include<string>
using namespace std;

struct Student
{
	string name;
	int marks;
	Student()
	{
		name = "EMPTY";
		marks = -1;
	}
	Student(string name, int marks)
	{
		this->name = name;
		this->marks = marks;
	}
	void initialSet(string name, int marks)
	{
		this->name = name;
		this->marks = marks;
	}
	void set(string name, int marks)
	{
		if (marks >= 0)
		{
			this->name = name;
			this->marks = marks;
		}
		else
			cout << "INVALID VALUES\n";
	}
};
class HashTable
{
private:
	Student *table; //Dynamic array of Student to hold records
	int size; //Total number of slots in the table
	int curSize; //Current number of records present in the table
public:
	HashTable(int size)
	{
		this->size = size;
		this->curSize = 0;
		table = new Student[size];
		for (int i = 0; i < size; i++)
			table[i].initialSet("EMPTY", -1);
	}
	bool isEmpty() //Checks whether hash table is empty or not
	{
		return curSize == 0;
	}
	bool isFull()
	{
		return curSize == size;
	}
	double loadFactor()
	{
		if (size > 0)
			return (curSize / size);
		else
			return -1;
	}

	bool insert(Student record)
	{
		if (!isFull())
		{
			int index = 0;
			while (true)
			{
				if (table[index].name == "EMPTY" && table[index].marks == -1)
				{
					table[index] = record;
					curSize++;
					return true;
				}
				else
					index = (index + 1) % size;
			}
		}
		else
			cout << "NO enough space....\n";
		return false;
	}
	int search(Student record)
	{
		if (!isEmpty())
		{
			int index = 0;
			for (int i = 0; i < size; i++)
			{
				if (table[index].name == record.name && table[index].marks == record.marks)
				{
					cout << "Student exists......\n";
					return index;
				}
				else
					index = (index + 1) % size;
			}
		}
		else
			cout << "EMPTY_table\n";
		return -1;
	}
	bool remove(Student record)
	{
		int check = search(record);
		if (check != -1)
		{
			curSize--;
			table[check].name = "EMPTY";
			table[check].marks = -1;
			cout << "Successfully removed\n";
			return true;
		}
		else
			cout << "No such student exists\n";
		return false;
	}
	void display()
	{
		if (!isEmpty())
		{
			for (int i = 0; i < size; i++)
			{
				cout << "Index " << i;
				if (table[i].name == "EMPTY" && table[i].marks == -1)
					cout << " is Empty\n";
				else
				{
					cout << "\nName : " << table[i].name;
					cout << "\nMarks : " << table[i].marks << endl;
				}
			}
		}
		else
			cout << "TABLE IS EMPTY\n";
	}
	~HashTable() //Destructor
	{
		if (table != NULL)
			delete[] table;
	}
};
