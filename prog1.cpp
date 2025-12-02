#include <iostream>

using namespace std;

class Train
{
private:
    int trainNumber;
    string trainName;
    string source;
    string destination;
    string trainTime;

public:

    Train()
    {
        trainNumber = 0;
        trainName = "";
        source = "";
        destination = "";
        trainTime = "";
    }

    Train(int number, string name, string src, string dest, string time)
    {
        trainNumber = number;
        trainName = name;
        source = src;
        destination = dest;
        trainTime = time;
    }

    void setdetails()
    {
        cout << "Enter Train Number: ";
        cin >> trainNumber;

        cin.ignore();
        cout << "Enter Train Name: ";
        getline(cin, trainName);

        cout << "Enter Source: ";
        getline(cin, source);

        cout << "Enter Destination: ";
        getline(cin, destination);

        cout << "Enter Train Time: ";
        getline(cin, trainTime);
    }

    void getdetails()
    {
        cout << "Train Number : " << trainNumber << endl;
        cout << "Train Name : " << trainName << endl;
        cout << "Source : " << source << endl;
        cout << "Destination : " << destination << endl;
        cout << "Train Time : " << trainTime << endl;
    }

    int gettrainnumber()
    {
        return trainNumber;
    }
};

class Railwaysystem
{
private:
    Train trains[100];
    int totalTrains;

public:

    Railwaysystem()
    {
        totalTrains = 0;
    }

    void addtrain()
    {
        cout << "Enter details for Train " << totalTrains + 1 <<endl;
        trains[totalTrains].setdetails();
        totalTrains++;
    }

    void displayalltrain()
    {
        if (totalTrains == 0)
        {
            cout << "No train records available!\n";
            return;
        }

        for (int i = 0; i < totalTrains; i++)
        {
            cout << "\nTrain " << i + 1 << " details:\n";
            trains[i].getdetails();
        }
    }

    void searchtrainbynumber(int number)
    {
        bool found = false;

        for (int i = 0; i < totalTrains; i++)
        {
            if (trains[i].gettrainnumber() == number)
            {
                cout << "\nTrain Found!\n";
                trains[i].getdetails();
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Train with number " << number << " not found!\n";
        }
    }
};

int main()
{
    Railwaysystem obj;
    int choice;

    cout << "Enter at least 3 train records initially:" <<endl;
    for (int i = 0; i < 3; i++)
    {
        obj.addtrain();
    }

    do
    {
        cout << "Railway Reservation System Menu :"<<endl;
        cout << "1. Add New Train Record "<<endl;
        cout << "2. Display All Train Records"<<endl;
        cout << "3. Search Train by Number"<<endl;
        cout << "4. Exit"<<endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            obj.addtrain();
            break;

        case 2:
            obj.displayalltrain();
            break;

        case 3:
        {
            int num;
            cout << "Enter Train Number to search: ";
            cin >> num;
            obj.searchtrainbynumber(num);
            break;
        }

        case 4:
            cout << "Exiting ."<<endl;
            break;

        default:
            cout << "Invalid choice."<<endl;
        }

    } while (choice != 4);

    return 0;
}
