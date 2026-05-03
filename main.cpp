#include <iostream>
#include <string>
using namespace std;

struct Person {
    string name;
    int day, month, year;
};

// وظيفة للتحقق من صحة التاريخ
bool isValidDate(int d, int m, int y) {
    // نعتبر السنة الحالية 2026 كمثال
    if (y > 2026 || y < 1900) return false;
    if (m < 1 || m > 12) return false;

    int daysInMonth;
    if (m == 2) {
        // حساب بسيط للسنة الكبيسة حتى يكون البرنامج دقيق
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

// وظيفة حساب العمر بدقة
void calculateAge(int d, int m, int y) {
    // التاريخ الحالي (افتراضي)
    int currentDay = 3, currentMonth = 5, currentYear = 2026;

    int years = currentYear - y;
    int months = currentMonth - m;
    int days = currentDay - d;

    if (days < 0) {
        months--;
        days += 30; // تقريب لأيام الشهر
    }

    if (months < 0) {
        years--;
        months += 12;
    }

    // حسابات إضافية
    long totalDays = (years * 365) + (months * 30) + days;
    long hours = totalDays * 24;
    long long minutes = hours * 60;
    long long seconds = minutes * 60;

    cout << "\n--- Age Analysis for the User ---\n";
    cout << "Age: " << years << " years, " << months << " months, and " << days << " days." << endl;
    cout << "Total days lived: " << totalDays << " days" << endl;
    cout << "In Hours: " << hours << " hrs" << endl;
    cout << "In Minutes: " << minutes << " mins" << endl;
    cout << "In Seconds: " << seconds << " secs" << endl;
}

int main() {
    Person p;

    cout << "Enter name: ";
    getline(cin, p.name); // استخدمت getline عشان لو الاسم ثنائي

    do {
        cout << "Enter birth date (Day Month Year): ";
        
        // فحص إذا كان المدخل رقم أو حرف
        if (!(cin >> p.day >> p.month >> p.year)) {
            cout << "Error: Please enter numbers only for the date!\n";
            cin.clear(); // تنظيف حالة الخطأ
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // مسح النص الغلط من الذاكرة
            continue; 
        }

        if (!isValidDate(p.day, p.month, p.year)) {
            cout << "Invalid date or year out of range! Try again.\n";
        }

    } while (!isValidDate(p.day, p.month, p.year));

    calculateAge(p.day, p.month, p.year);

    return 0;
}
