#include"Header.h"

int main()
{
	int size = 0;
	cout << "HASH_table SIZE : : ";
	cin >> size;

	if (size > 0)
	{
		HashTable table(size);
		Student temp;
		string name = " ";
		int marks = 0;
	again1:
		cout << "Select any of the following : \n\n";
		cout << "1. Insert Record.\n2. Search for a record.\n3. Remove a record.\n";
		cout << "4. Display the table\n5. Display the load factor of the table\n";
		char option = '\0';
	again:
		cout << "Option : ";
		cin >> option;
		switch (option)
		{
		case '1':
			cout << "Enter student name : ";
			cin >> name;
			cout << "Enter marks : ";
			cin >> marks;
			temp.set(name, marks);
			table.insert(temp);
			break;
		case '2':
			cout << "Enter student name : ";
			cin >> name;
			cout << "Enter marks : ";
			cin >> marks;
			temp.set(name, marks);
			if (table.search(temp) == -1)
				cout << "No such student\n";
			break;
		case '3':
			cout << "Enter student name : ";
			cin >> name;
			cout << "Enter marks : ";
			cin >> marks;
			temp.set(name, marks);
			table.remove(temp);
			break;
		case '4':
			table.display();
			break;
		case '5':
			cout << "LOAD FACTOR : ";
			cout << table.loadFactor() << endl;
			break;
		case '6':
			exit(0);
			break;
		default:
			cout << "Invalid value enter again\n";
			goto again;
		}
		system("pause");
		cout << "Would you like to do something else?(y/n) : ";
		cin >> option;
		if (option == 'y' || option == 'Y')
			goto again1;
	}
	else
		cout << "INVAlID SIZE\n";
return 0;
}
