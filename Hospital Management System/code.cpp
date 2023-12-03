#include<iostream>

using namespace std;

const int Max_Specialization = 20;
const int Max_Queue = 5;

string names[Max_Specialization + 1][Max_Queue + 1];
int status[Max_Specialization + 1][Max_Queue + 1];// 0 regular, 1 urgent
int queue_length[Max_Specialization + 1];// for each specialization: how many patients so far


void ShiftLeft(int specialization, string names[], int status[]) 
{
    int len = queue_length[specialization];

    for (int i = 1; i < len; ++i)
    {
        names[i - 1] = names[i];
        status[i - 1] = status[i];
    }
    queue_length[specialization]--;
}

void GetNextPatient()
{
    int specialization;
    cout << "Enter specialization: ";
    cin >> specialization;

    int len = queue_length[specialization];

    if (len == 0)
    {
        cout << "No patients at the moment. Have rest, Dr\n";
        return;
    }

    cout << names[specialization][0] << " please go with the Dr\n";
    ShiftLeft(specialization, names[specialization], status[specialization]);
}

void PrintPatient(int specialization, string names[], int status[]) 
{
    int len = queue_length[specialization];

    if (len == 0)
        return;

    cout << "There are " << len << " patients in specialization " << specialization << "\n";

    for (int i = 0; i < len; ++i) 
    {
        cout << names[i] << " ";
        if (status[i])
            cout << "urgent\n";
        else
            cout << "regular\n";
    }
    cout << "\n";
}

void PrintPatients() 
{
    cout << "****************************\n";
    for (int specialization = 0; specialization < Max_Specialization; ++specialization)
    {
        PrintPatient(specialization, names[specialization], status[specialization]);
    }
}

void ShiftRight(int specialization, string names[], int status[])
{
    int len = queue_length[specialization];

    for (int i = len - 1; i >= 0; i--) 
    {
        names[i + 1] = names[i];
        status[i + 1] = status[i];
    }
    queue_length[specialization]++;
}

bool AddNewPatient()
{
    int specialization;
    string name;
    int st;

    cout << "Enter specialization, name, status: ";
    cin >> specialization >> name >> st;

    int pos = queue_length[specialization];
    if (pos >= Max_Queue)
    {
        cout << "Sorry, we can't add more patients for this specialization\n";
        return false;
    }

    if (st == 0)
    {
        names[specialization][pos] = name;
        status[specialization][pos] = st;
        queue_length[specialization]++;
    }
    else
    {
        ShiftRight(specialization, names[specialization], status[specialization]);
        names[specialization][0] = name;
        status[specialization][0] = st;
    }

    return true;
}

int Menu()
{
    int choice = -1;

    while (choice == -1) 
    {
        cout << "Enter your choice:\n";
        cout << "1) Add new patient\n";
        cout << "2) Print all patients\n";
        cout << "3) Get Next Patient\n";
        cout << "4) Exit\n";

        cin >> choice;

        if (!(choice >= 1 && choice <= 4))
        {
            cout << "Invalid choice. Try again\n";
            choice = -1;
        }
    }

    return choice;
}

void HospitalManagementSystem()
{
    while (true)
    {
        int choice = Menu();

        switch (choice) 
        {
        case 1:
            AddNewPatient();
            break;
        case 2:
            PrintPatients();
            break;
        case 3:
            GetNextPatient();
            break;
        case 4:
            return;
        default:
            cout << "Invalid choice. Try again\n";
            choice = -1;
        }
    }
}

int main()
{
    HospitalManagementSystem();

    return 0;
}
