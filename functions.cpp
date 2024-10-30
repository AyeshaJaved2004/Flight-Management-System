#include "functions.h"
#include <iostream>
#include <fstream>
using namespace std;
#include<string>
#include <cstdlib>

void flightDetails()
{
    cout<<"\nYou are currently located in Lahore, Pakistan. \nYour departure country is registered as Pakistan."<<endl;
    int date, month, year;
    int price=127000;
    int passenger, trackingid;
    string name;
    int age;
    int flightids;
    int limit = 100;
    int * flightnum=new int [limit]{};
    for (int i = 0; i < limit; i++)
        flightnum[i] = rand();
    cout<<"\n\nPlease enter your name: ";
    cin.ignore();
    getline(cin, name);
    cout<<"\nPlease enter the number of passenger(s): ";
    cin>>passenger;
    if (passenger<=0)
    {
        cout << "Number of passengers cannot be less than 1." << endl;
        return;
    }
    if (passenger>1)
        price=price*passenger;
    cout<<"\nPlease enter your age: ";
    cin>>age;
    if (age <= 17 || age >= 100)
    {
        cout << "Invalid age. Please enter a valid age within a range of 18 to 99." << endl;
        return;
    }
    cout<<"\nEnter desired date for flight...\nOnly date: ";
    cin>>date;
    if (date>31 || date<0)
    {
        cout<<"\nPlease re-enter the valid date."<<endl;
        return;
    }
    cout<<"\nEnter month in number: ";
    cin>>month;
    if (month>12 || month<0)
    {
        cout<<"\nPlease re-enter month. It cannot be greater than 12\nor smaller than 0."<<endl;
        return;
    }
    cout<<"\nEnter year: ";
    cin>>year;
    if (year<2023 || year>2024)
    {
        cout<<"\nPlease re enter the year. It must be either in 2023 or 2024."<<endl;
        return;
    }
    cout<<"\nEnter your country of arrival: ";
    flight f;
    cin.ignore();
    getline(cin, f.arrival_country);
    cout<<"\nEnter your city of arrival: ";
    getline(cin, f.arrival_city);
    cout<<"\nEnter your flight type [economy/business] (small letters only): ";
    cin>>f.flightype;
    if (f.flightype!="economy" && f.flightype!="business")
    {
        cout<<"Please enter valid data"<<endl;
        return;
    }

    cout<<"\n\n\n\nYour tracking ID is: ";
    trackingid=flightnum[age%100]/10000;
    cout<<trackingid;
    int seatnum=(age+month+30)/2;
    cout<<"\nYour seat number(s) is/are: ";
    int i=1;
    while(i<=passenger)
    {
        i++;
        seatnum++;
        cout<<seatnum<<", ";
    }
    cout<<endl;

    ofstream outfile;
    outfile.open(to_string(trackingid)+".txt");

    if (!outfile.is_open())
    {
        cout << "Error opening file " << to_string(trackingid) << ".txt for saving receipt." << endl;
        return;
    }

    outfile << "=== Booking Receipt ===\n";
    outfile << "Airlines: Pakistan International Airlines (PIA)\n";
    outfile << "Passenger: " << name << "\n";
    outfile << "Number of passengers: " << passenger << "\n";
    outfile << "Flight Tracking ID: " << trackingid << "\n";
    outfile << "Destination Country: " << f.arrival_country << "\n";
    outfile << "Destination City: " << f.arrival_city << "\n";
    outfile << "Flight Type: " << f.flightype << "\n";
    outfile << "Date: " << date << "/" << month << "/" << year << "\n";
    outfile << "Flight Price: Rs " << price << "\n";
    outfile << "=== End of Receipt ===\n\n";
    outfile.close();
    cout << "Booking successful. Receipt has been saved to " << trackingid << ".txt\n";



    cout<<"\nYour flight has been booked successfully!"<<endl;
    cout<<"\n\n=== Booking Receipt ==="<<endl;
    cout<<"\n Airlines: Pakistan International Airlines (PIA)"<<endl;
    cout<<"\nName: "<<name<<endl;
    cout<<"\nNumber of passengers: "<<passenger<<endl;
    cout<<"\nFlight Tracking ID: "<<trackingid<<endl;
    cout<<"\nSeat(s): ";
    int j=1;
    int s=(age+month+30)/2;
    while(j<=passenger)
    {
        j++;
        s++;
        cout<<s<<", ";
    }
    cout<<endl;
    cout<<"\nDestination Country: "<<f.arrival_country<<endl;
    cout<<"\nDestination City: "<<f.arrival_city<<endl;
    cout<<"\nFlight Type: "<<f.flightype<<endl;
    cout<<"\nFlight Price: Rs "<<price<<endl;
    cout<<"\nFlight Date: "<<date<<"/"<<month<<"/"<<year<<endl;
    cout<<"\n=== End of Receipt ==="<<endl;
    cout<<"\n\nThank you for booking with us! Have a nice flight."<<endl;
    delete[]flightnum;
}

void trackFlight()
{
    int trackingid;
    cout<<"\n\nEnter tracking ID for the flight that you want to track: ";
    cin>>trackingid;

    ifstream openFile(to_string(trackingid)+".txt");
    string line;
    if (openFile.is_open() && openFile.good())
    {
        while (getline(openFile, line))
        {
            cout << line << endl;
        }
        openFile.close();
    } else {
        cout << "Invalid tracking ID entered. No data found." << endl;
    }
}

