/*Consider a scenario for Hospital to cater services to different kinds of patients as Serious (top
priority), b) non-serious (medium priority), c) General Checkup (Least priority). Implement the
priority queue to cater services to the patients.*/

//Name: Abhishek Mali
//Roll No: 2102074
//SITS, Narhe

#include <iostream>
#include <string.h>

using namespace std;
#define MAX 25

class Priority_Queue
{
    string Patient_name[MAX];
    int Pri[MAX];
    int pos, front, rear;

public:
    Priority_Queue()
    {
        front = -1;
        rear = -1;
    }
    void enQueue(string, int);
    void deQueue();
    void display();
    int isEmpty();
};
void Priority_Queue ::enQueue(string name, int p)
{
    if (rear == MAX - 1)
        cout << "\nHospital's capacity is full";
    else
    {
        pos = rear;
        rear = rear + 1;
        while (pos >= 0 && Pri[pos] > p)
        {
            Patient_name[pos + 1] = Patient_name[pos];
            Pri[pos + 1] = Pri[pos];
            pos = pos - 1;
        }
        Patient_name[pos + 1] = name;
        Pri[pos + 1] = p;
        if (front == -1)
            front++;
    }
}
void Priority_Queue ::deQueue()
{
    cout << "Patient Treated : " << Patient_name[front];
    cout << "\nPatients's Priority : " << Pri[front] << endl;
    if (front == rear)
        front = rear = -1;
    else
        front++;
}
int Priority_Queue ::isEmpty()
{
    if (front == -1)
        return 1;
    return 0;
}
void Priority_Queue ::display()
{
    for (int i = front; i < rear + 1; i++)
    {
        cout << endl;
        cout << Patient_name[i] << " " << Pri[i];
    }
}
int main()
{
    Priority_Queue obj;
    int ch;
    do
    {
        cout << "\n----------- *Welcome to Jeevan Hospital* ------------" << endl;
        cout << "Enter 1 to Add New Patient " << endl;
        cout << "Enter 2 to Delete Patient " << endl;
        cout << "Enter 3 to Display All Patients " << endl;
        cout << "Enter 4 to Exit " << endl;
        cout << "Enter Your Choice : ";
        cin >> ch;
        cout << endl;
        if (ch == 1)
        {
            string patient;
            int prior;
            cout << "Enter Patient's Name : ";
            cin >> patient;
            cout << "Category of Pateint : \n\tEnter 1 for Serious Patient"
                 << "\n\tEnter 2 for Non serious Patient"
                 << "\n\tEnter 3 for General Checkup"
                 << "\n\tPriority of Patient - ";
            cin >> prior;
            obj.enQueue(patient, prior);
        }
        else if (ch == 2)
        {
            if (!obj.isEmpty())
            {
                obj.deQueue();
            }
            else
            {
                cout << "Queue is Empty" << endl
                     << endl;
            }
        }
        else if (ch == 3)
        {
            if (!obj.isEmpty())
            {
                cout << "Displaying all Patient's -\n";
                obj.display();
                cout << endl;
            }
            else
            {
                cout << "Queue is Empty" << endl
                     << endl;
            }
        }
        else if (ch == 4)
        {
            cout << "****** Exiting ******" << endl;
        }
        else
            cout << "Invalid Choice" << endl;
    } while (ch != 4);
    return 0;
}