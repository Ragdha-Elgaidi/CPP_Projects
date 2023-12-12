#include<iostream>
using namespace std;

//Global variables
const int MAX_SPEACIALIZATION = 20;
const int MAX_QUEUE = 5;

struct hospital_queue
{
	string names[MAX_QUEUE]; //array to store patient name
	int status[MAX_QUEUE]; //array to carry the status of the patients (0 for regular and 1 for urgent)
	int len;//current number of patient in queue
	int spe; //speacilaization index

	hospital_queue()
	{
		len = 0;
		spe = -1;
	}

	hospital_queue(int _spe)
	{
		len = 0;
		spe = _spe;
	}

	bool add_end(string name, int st)
	{
		if (len == MAX_QUEUE)
		{
			return false;
		}

		names[len] = name, status[len] = st, len++;

		return true;
	}

	bool add_front(string name, int st)
	{
		if (len == MAX_QUEUE)
		{
			return false;
		}

		//shift right
		for (int i = len - 1; i >= 0; i--)
		{
			names[i + 1] = names[i];
			status[i + 1] = status[i];
		}

		names[0] = name, status[0] = st, len++;

		return true;
	}

	void remove_front()
	{
		if (len == 0)
		{
			cout << "NO patients at that time have rest DR!";
			return;
		}

		cout << names[0] << "please, go to the doctor!";

		//shift left
		for (int i = 1; i < len; i++)
		{
			names[i - 1] = names[i];
			status[i - 1] = status[i];
		}

		len--;
	}

	void print()
	{
		if (len == 0)
		{
			return;
		}

		cout << "There are : " << len << " patients in specialization " << spe << endl;

		for (int i = 0; i < len; i++)
		{
			cout << names[i] << " ";
			if (status[i])
				cout << "urgent" << endl;
			else
				cout << "regular" << endl;
		}

		cout << endl;
	}
};

struct hospital_system
{
	hospital_queue queues[MAX_SPEACIALIZATION+1];

	hospital_system()
	{
		for (int i = 0; i < MAX_SPEACIALIZATION; i++)
			queues[i] = hospital_queue(i);
	}

	void run() 
	{
		while (true)
		{
			int choice = menu();

			if (choice == 1)
				add_patient();
			else if (choice == 2)
				print_patients();
			else if (choice == 3)
				get_next_patients();
			else
				break;
		}
	}

	int menu()
	{
		int choice = -1;
		while (choice == -1) 
		{
			cout << "\nEnter your choice:\n";
			cout << "1) Add new patient\n";
			cout << "2) Print all patients\n";
			cout << "3) Get next patient\n";
			cout << "4) Exit\n";

			cin >> choice;

			if (!(1 <= choice && choice <= 4))
			{
				cout << "Invalid choice. Try again\n";
				choice = -1;	// loop keep working
			}
		}
		return choice;
	}

	bool add_patient() 
	{
		int spec, st;
		string name;

		cout << "Enter specialization, name, status: ";
		cin >> spec >> name >> st;

		bool status;
		if (st == 0)
			status = queues[spec].add_end(name, st);
		else
			status = queues[spec].add_front(name, st);

		if (status == false) //Check Addition Status
		{
			cout << "Sorry we can't add more patients for this specialization\n";
			return false;
		}

		return true;
	}

	void print_patients()
	{
		cout << "****************************\n";
		for (int spec = 0; spec < MAX_SPEACIALIZATION; ++spec)
			queues[spec].print();
	}

	void get_next_patients() 
	{
		int spec;
		cout << "Enter specialization: ";
		cin >> spec;

		queues[spec].remove_front();
	}
};

int main()
{
	hospital_system hospital = hospital_system();
	hospital.run();

	return 0;
}
