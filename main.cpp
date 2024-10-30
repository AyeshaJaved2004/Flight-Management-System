#include <iostream>
#include "functions.h"
using namespace std;

int main()
{
    int choice;
    do{
        cout << "\n\n\n\n=== Flight Booking System ===\n";
        cout << "1. Book a Flight\n";
        cout << "2. Track a Flight\n";
        cout << "3. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
       case 1:
           flightDetails();
           break;
       case 2:
           trackFlight();
           break;
       case 3:
           cout << "Exiting program. Thank you!\n\tYou may close this window now...";
           break;
       default:
           cout << "Invalid choice. Please try again.\n";
    }
} while (choice != 3);



    return 0;
}
