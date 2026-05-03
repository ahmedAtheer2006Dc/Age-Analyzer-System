#include <iostream>
using namespace std;

struct Person {
    string name;
    int day, month, year;
};

// تحقق من صحة التاريخ
bool isValidDate(int d, int m, int y) {
    if (y > 2026 || y < 1900) return false;
    if (m < 1 || m > 12) return false;

    int daysInMonth;
    if (m == 2)
        daysInMonth = 28; // نبسطها بدون leap year
    else if (m == 4 || m == 6 || m == 9 || m == 11)
        daysInMonth = 30;
    else
        daysInMonth = 31;

    if (d < 1 || d > daysInMonth) return false;

    return true;
}

// حساب العمر بدقة
void calculateAge(int d, int m, int y) {
    int currentDay = 1, currentMonth = 1, currentYear = 2026;

    int years = currentYear - y;
    int months = currentMonth - m;
    int days = currentDay - d;

    if (days < 0) {
        months--;
        days += 30; // تقريب
    }

    if (months < 0) {
        years--;
        months += 12;
    }

    int totalDays = years * 365 + months * 30 + days;
    int hours = totalDays * 24;
    int minutes = hours * 60;
    int seconds = minutes * 60;

    cout << "Age: " << years << " years, "
         << months << " months, "
         << days << " days\n";

    cout << "Total days: " << totalDays << endl;
    cout << "Hours: " << hours << endl;
    cout << "Minutes: " << minutes << endl;
    cout << "Seconds: " << seconds << endl;
}

int main() {
    Person p;

    cout << "Enter name: ";
    cin >> p.name;

    // إعادة إدخال التاريخ إذا غلط
    do {
        cout << "Enter day month year: ";
        cin >> p.day >> p.month >> p.year;

        if (!isValidDate(p.day, p.month, p.year)) {
            cout << "Invalid date! Try again.\n";
        }

    } while (!isValidDate(p.day, p.month, p.year));

    calculateAge(p.day, p.month, p.year);

    return 0;
}
