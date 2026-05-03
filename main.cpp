#include <iostream>
#include <string>

using namespace std;

struct Person {
    string name;
    int day, month, year;
};


bool isValidDate(int d, int m, int y) {
    if (y > 2026 || y < 1900) return false;
    if (m < 1 || m > 12) return false;

    int daysInMonth;
    if (m == 2) {
        
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
            daysInMonth = 29;
        else
            daysInMonth = 28;
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11)
        daysInMonth = 30;
    else
        daysInMonth = 31;

    if (d < 1 || d > daysInMonth) return false;

    return true;
}


void calculateAge(int d, int m, int y) {
    int currentDay = 4, currentMonth = 5, currentYear = 2026;

    int years = currentYear - y;
    int months = currentMonth - m;
    int days = currentDay - d;

    if (days < 0) {
        months--;
        days += 30; 
    }

    if (months < 0) {
        years--;
        months += 12;
    }

    
    long totalDays = (years * 365) + (months * 30) + days;
    long hours = totalDays * 24;
    long minutes = hours * 60;
    long seconds = minutes * 60;

    cout << "\n--- Result ---\n";
    cout << "Age: " << years << " years, " << months << " months, " << days << " days\n";
    cout << "Total days: " << totalDays << endl;
    cout << "In Seconds: " << seconds << endl;
}

int main() {
    Person p;

    cout << "Enter name: ";
    cin >> p.name; 

    do {
        cout << "Enter birth date (Day Month Year): ";
        
    
        if (!(cin >> p.day >> p.month >> p.year)) {
            cout << "Invalid input! Use numbers only.\n";
            return 0; 
        }

        if (!isValidDate(p.day, p.month, p.year)) {
            cout << "Invalid date! Try again.\n";
        }

    } while (!isValidDate(p.day, p.month, p.year));

    calculateAge(p.day, p.month, p.year);

    return 0;
}

    
