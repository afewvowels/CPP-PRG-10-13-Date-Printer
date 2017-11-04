//
//  main.cpp
//  CPP-PRG-10-13-Date-Printer
//
//  Created by Keith Smith on 11/4/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a program that reads a string from the user containing a date in the form mm/
//  dd/yyy. It should print the date in the form March 12, 2018.
//

#include <iostream>
#include <cctype>

using namespace std;

string *getDate(string *);
string *convertDate(string *);
void outputDate(string *);

int main()
{
    string *strDateString = nullptr;
    strDateString = new string;
    
    strDateString = getDate(strDateString);
    
    strDateString = convertDate(strDateString);
    
    outputDate(strDateString);
    
    return 0;
}

string *getDate(string *strDate)
{
    bool *booIsValidDate = nullptr;
    booIsValidDate = new bool;
    *booIsValidDate = false;
    
    string *strMonth = nullptr;
    strMonth = new string;
    int *intMonth = nullptr;
    intMonth = new int;
    
    string *strDay = nullptr;
    strDay = new string;
    int *intDay = nullptr;
    intDay = new int;
    
    string *strYear = nullptr;
    strYear = new string;
    int *intYear = nullptr;
    intYear = new int;
    
    while (*booIsValidDate == false)
    {
        cout << "Please enter a day in mm/dd/yyyy format:\n";
        getline(cin, *strDate);
        
        while (!isdigit(strDate->at(0)) || !isdigit(strDate->at(1)) || !isdigit(strDate->at(3)) ||
               !isdigit(strDate->at(4)) || !isdigit(strDate->at(6)) || !isdigit(strDate->at(7)) ||
               !isdigit(strDate->at(8)) || !isdigit(strDate->at(9)))
        {
            cout << "Please enter a valid date in mm/dd/yyyy format:\n";
            getline(cin, *strDate);
        }
        
        strMonth->assign(*strDate, 0, 2);
        *intMonth = stoi(*strMonth);
        
        strDay->assign(*strDate, 3, 2);
        *intDay = stoi(*strDay);
        
        strYear->assign(*strDate, 6, strDate->length());
        *intYear = stoi(*strYear);
        
        while(*intMonth < 1 || *intMonth > 12 || *intDay < 1 || *intDay > 31 || *intYear < 1000 || *intYear > 9999)
        {
            cout << "Please enter a valid date in mm/dd/yyyy format:\n";
            getline(cin, *strDate);
            
            strMonth->assign(*strDate, 0, 2);
            *intMonth = stoi(*strMonth);
            
            strDay->assign(*strDate, 3, 2);
            *intDay = stoi(*strDay);
            
            strYear->assign(*strDate, 6, 4);
            *intYear = stoi(*strYear);
        }
        
        *booIsValidDate = true;
    }
    
    return strDate;
}

string *convertDate(string *strDate)
{
    string *strMonth = nullptr;
    strMonth = new string;
    int *intMonth = nullptr;
    intMonth = new int;
    
    string *strDay = nullptr;
    strDay = new string;
    int *intDay = nullptr;
    intDay = new int;
    
    string *strYear = nullptr;
    strYear = new string;
    int *intYear = nullptr;
    intYear = new int;
    
    strMonth->assign(*strDate, 0, 2);
    *intMonth = stoi(*strMonth);
    
    strDay->assign(*strDate, 3, 2);
    *intDay = stoi(*strDay);
    
    strYear->assign(*strDate, 6, 4);
    *intYear = stoi(*strYear);
    
    switch(*intMonth)
    {
        case 1:
            *strMonth = "January";
            break;
        case 2:
            *strMonth = "February";
            break;
        case 3:
            *strMonth = "March";
            break;
        case 4:
            *strMonth = "April";
            break;
        case 5:
            *strMonth = "May";
            break;
        case 6:
            *strMonth = "June";
            break;
        case 7:
            *strMonth = "July";
            break;
        case 8:
            *strMonth = "August";
            break;
        case 9:
            *strMonth = "September";
            break;
        case 10:
            *strMonth = "October";
            break;
        case 11:
            *strMonth = "November";
            break;
        case 12:
            *strMonth = "December";
            break;
        default:
            cout << "ERROR ASSIGNING MONTH STRING\n";
            exit(1);
            break;
    }
    
    strDate->clear();
    
    strDate->insert(strDate->length(), *strMonth);
    strDate->insert(strDate->length(), " ");
    strDate->insert(strDate->length(), *strDay);
    strDate->insert(strDate->length(), ", ");
    strDate->insert(strDate->length(), *strYear);
    
    return strDate;
}

void outputDate(string *strDate)
{
    cout << "That day is " << *strDate << endl;
}
