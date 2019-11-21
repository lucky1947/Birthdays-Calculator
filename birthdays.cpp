/**
 * birthdays.cpp
 *
 * <#Name#> Lucky Chowdhury
 * <#Uniqname#> lmchow@umich.edu
 *
 * EECS 183: Project 2
 *
 * <#description#> This program allows a user to choose from a menu to calculates 
 the user's birthday and print the next ten leap years based on any year input.
 .
 */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;


/**
 * Requires: nothing
 * Modifies: cout
 * Effects: prints out the initial heading for the program
 */
void printHeading();


/**
 * Requires: nothing
 * Modifies: cout
 * Effects:  prints out the final greeting for the program
 */
void printCloser();


/**
 * Requires: nothing
 * Modifies: cout
 * Effects: prints the menu
 */
void printMenu();


/**
 * Note:  write your test cases in main() BEFORE you implement this function
 *
 * Requires: nothing
 * Modifies: cout, cin
 * Effects:  prints the menu
 *           reads the input from the user
 *           checks to make sure the input is within range for the menu
 *           If not prints "Invalid menu choice"
 *           continues to print the menu and read an input until a valid one is
 *               entered
 *           returns the users choice of menu options
 
 */
int getMenuChoice();


/**
 * Note:  write your test cases in main() BEFORE you implement this function
 *
 * Requires: month, day, year may represent a date
 * Modifies: nothing
 * Effects: returns 'true' if the date is in the limits
 *          of the Gregorian calendar otherwise returns 'false'
 */
bool isGregorianDate(int month, int day, int year);


/**
 * Note:  write your test cases in main() BEFORE you implement this function
 *
 * Requires: year is a Gregorian year
 * Modifies: nothing
 * Effects: Returns 'true' if the year is a leap year
 *          otherwise returns 'false'
 */
bool isLeapYear(int year);


/**
 * Note:  write your test cases in main() BEFORE you implement this function
 *
 * Requires: month, day, year may represent a date
 * Modifies: nothing
 * Effects:  Returns 'true' if the date is valid
 *           otherwise returns 'false'
 *           see the spec for definition of "valid"
 */
bool isValidDate(int month, int day, int year);


/**
 * Note:  write your test cases in main() BEFORE you implement this function
 *
 * Requires: month, day, year is a valid date
 *           i.e., the date passed to this function has already passed
 *               isValidDate()
 * Modifies: nothing
 * Effects:  Returns the value that Zeller's formula calculates
 */
int determineDay(int month, int day, int year);


/**
 * Note:  write your test cases in main() BEFORE you implement this function
 *
 * Requires: day (0 represents Saturday, 1 Sunday, 2 Monday, 3 Tuesday, etc)
 * Modifies: cout
 * Effects:  prints the day you were born on
 *           Sunday, Monday, ..., Saturday
 */
void printDayOfBirth(int day);


/**
 * Note:  write your test cases in main() BEFORE you implement this function
 *
 * Requires: nothing
 * Modifies: cout, cin
 * Effects:  Asks for the Month/day/year of their birth
 *           If the date is valid, it will print the day
 *               of the week you were born on
 *           Otherwise, it will print "Invalid date" prompt
 */
void determineDayOfBirth();


/**
 * Note:  write your test cases in main() BEFORE you implement this function
 *
 * Base Project
 * Requires: nothing
 * Modifies: cout
 * Effects: prints "Under Construction"
 *
 * S'more version of this function
 * Requires: nothing
 * Modifies: cout, cin
 * Effects:  reads the month and day of birthday
 *           loops through 10 years printing the day of the week
 *               the birthday falls on
 *           If the month/day is not valid, it prints nothing
 */
void print10Birthdays();


/**
 * Note:  write your test cases in main() BEFORE you implement this function
 *
 * Requires: nothing
 * Modifies: cin, cout
 * Effects:  Asks for a Gregorian year and prints the
 *           10 leap years after (not including) the year entered.
 *           If the year is invalid, it prints nothing.
 */
void print10LeapYears();


int main() {
    int input = 0;
    
    printHeading();
    
    input = getMenuChoice();
    
    while (input !=4) {
        if (input == 1) {
            determineDayOfBirth();
        }
        if (input == 2) {
            print10LeapYears();
        }
        if (input == 3) {
            print10Birthdays();
        }
        
        input = getMenuChoice();
    }
    
    printCloser();
    
    return 0;
}


void printHeading() {
    cout << "*******************************" << endl
    << "      Birthday Calculator      " << endl
    << "*******************************" << endl << endl;
}


void printCloser() {
    cout << endl;
    cout << "****************************************************" << endl
    << "      Thanks for using the Birthday Calculator      " << endl
    << "****************************************************" << endl
    << endl;
}


void printMenu() {
    cout << endl << endl;
    cout << "Menu Options" << endl
    << "------------" << endl;
    cout << "1) Determine day of birth" << endl;
    cout << "2) Print the next 10 leap years" << endl;
    cout << "3) Determine birthdays for the next 10 years" << endl;
    cout << "4) Finished" << endl << endl;
    
    cout << "Choice --> ";
}


int getMenuChoice() {
   
    int input = 0;
    printMenu();
    cin >> input;
    
    // Prompts user to pick an option from 1 to 4
    // Notifies user if choice is invalid
    while (input < 1 || input > 4) {
        cout << "Invalid menu choice" << endl;
        printMenu();
        cin >> input;
    }
    return input;
}


bool isGregorianDate(int month, int day, int year) {
    
    // Date is valid if it is after 9/13/1752
    bool isGregorian = false;
    if (year > 1752) {
        isGregorian = true;
    } else if (year == 1752) {
        if (month > 9) {
            isGregorian = true;
        } else if (month == 9) {
            if (day > 13) {
                isGregorian = true;
            } else {
                isGregorian = false;
            }
        }
    }
 
    return isGregorian;
}


bool isLeapYear(int year) {
    
    // Calculates and returns true or false based on leap year
    bool isLeapYear = false;
    
    if ((year % 4 == 0) && (year % 400 == 0 || year % 100 !=0)) {
        isLeapYear = true;
    } else {
        isLeapYear = false;
    }
    return isLeapYear;
}


bool isValidDate(int month, int day, int year) {
    
    // Validates the conditions of the correct number of days in each month
    // Ensures user's input is a real date
    bool validDate = true;
    bool Gregorian = true;
    bool leapYear = true;
    
    Gregorian = isGregorianDate(month, day, year);
    if (!(Gregorian)) {
            return false;
        }
  
    leapYear = isLeapYear(year);
    
    if (month < 1 || month > 12) {
            return false;
        }
    if (day < 1) {
            return false;
        }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
            if (day > 30) {
                return false;
            }
        } else if (month == 1 || month == 3 || month == 5 || month == 7 ||
            month == 8 || month == 10 || month == 12) {
            if (day > 0 && day < 32){
                return true;
        } else {
                return false;
            }
        } else if (month == 2) {
            if (day > 28 && !leapYear) {
                return false;
        }
            if (day > 29 && leapYear) {
                return false;
        }
        } else {
            if (leapYear == true) {
                if (day > 0 && day < 30) {
                    return true;
        } else {
                return false;
        }
        } else if (day > 0 && day < 29) {
                return true;
        } else {
                return false;
            }
    }
    return validDate;
}

int determineDay(int month, int day, int year) {
    
    if (month == 1 || month == 2) {
        month = month + 12;
        year = year - 1;
    }
    
    int century = (year / 100); // Gives the first two digits of the year
    int yearNum = (year % 100); // Gives the last two digits of the year
    int dayOfTheWeek; // Day of the week
    
    // Zeller's Forumula is used to calculate day of birth
    dayOfTheWeek = (day + floor(13 * (month + 1) / 5) + (yearNum) +
    floor(double(yearNum) / 4) + floor(century / 4) + (5 * century));
    int day_of_the_week = dayOfTheWeek % 7;
    
    return day_of_the_week;
}


void printDayOfBirth(int day) {
    
    // Assigns weekdays to numbers 0 to 6
    string bDay = " ";
    if (day == 0) {
            bDay = "Saturday";
    } else if (day == 1) {
            bDay = "Sunday";
    } else if (day == 2) {
            bDay = "Monday";
    } else if (day == 3) {
            bDay = "Tuesday";
    } else if (day == 4) {
            bDay = "Wednesday";
    } else if (day == 5) {
            bDay = "Thursday";
    } else if (day == 6) {
            bDay = "Friday";
    }
    cout << bDay << endl;
    
    return;
}


void determineDayOfBirth() {
    
    // Menu option 1
    // Asks user to input a date then outputs a weekday between 0 to 6
    char extra = ' ';
    int month = 0;
    int day = 0;
    int year = 0;
    
    cout << "Enter your date of birth" << endl;
    cout << "format: month / day / year  -->" << endl;
    cin >> month;
    cin >> extra;
    cin >> day;
    cin >> extra;
    cin >> year;
    
    if (!(isValidDate(month, day, year))) {
            cout << "Invalid date" << endl;
                return;
        }

    cout << "You were born on a: ";
    printDayOfBirth(determineDay(month, day, year));
    cout << endl;
    cout << "Have a great birthday!!!" << endl;
    
    return;
}


void print10Birthdays() {
    
    // Menu option 3
    // Does not calulate anything
    cout << "Under Construction" << endl;
    
    return;
}


void print10LeapYears() {
    
    // Menu option 2
    // Prints the next 10 leap years when user enters any year
        int year = 0;
        cout << "Enter year -->" << endl;
        cin >> year;
    
    if (year > 1752) {
        if (isLeapYear(year)) {
            for(int i = 0; i < 10; i++) {
                year += 4;
                cout << "Leap year is " << year << endl;
            }
        } else if  (isLeapYear(year + 1)) {
                year = year + 1;
                cout << "Leap year is " << year << endl;
            for(int i = 0; i < 9; i++) {
                year += 4;
                cout << "Leap year is " << year << endl;
            }
        } else if  (isLeapYear(year + 2)) {
                year = year + 2;
                cout << "Leap year is " << year << endl;
            for(int i = 0; i < 9; i++) {
                year += 4;
                cout << "Leap year is " << year << endl;
            }
        } else if  (isLeapYear(year + 3)) {
                year = year + 3;
                cout << "Leap year is " << year << endl;
            for(int i = 0; i < 9; i++) {
                year += 4;
                cout << "Leap year is " << year << endl;
            }
        } else if  (isLeapYear(year + 4)) {
                year = year + 4;
                cout << "Leap year is " << year << endl;
            for(int i = 0; i < 9; i++) {
                year += 4;
                cout << "Leap year is " << year << endl;
            }
        }
    }
    return;
}
