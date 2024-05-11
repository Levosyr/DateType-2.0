#include <iostream>
#include "dateType.h"

int main() {
    dateType date1;
    dateType date2(12, 31, 2023);

    // Test date1 default constructor and print function
    std::cout << "Default date: ";
    date1.print();
    std::cout << std::endl;

    // Test date2 parameterized constructor and print function
    std::cout << "Custom date: ";
    date2.print();
    std::cout << std::endl;

    // Test setting and getting functions
    date1.setMonth(2);
    date1.setDay(15);
    date1.setYear(2022);

    std::cout << "Updated date: ";
    date1.print();
    std::cout << std::endl;

    // Test isLeapYear function
    std::cout << "Is 2024 a leap year? " << std::boolalpha << dateType(1, 1, 2024).isLeapYear() << std::endl;

    // Test daysInMonth function
    std::cout << "Days in February 2023: " << dateType().daysInMonth(2, 2023) << std::endl;

    // Test daysPassed and daysRemaining functions
    std::cout << "Days passed since beginning of year: " << date1.daysPassed() << std::endl;
    std::cout << "Days remaining in year: " << date1.daysRemaining() << std::endl;

    // Test setDateFromDays function
    dateType date3;
    date3.setDateFromDays(365);
    std::cout << "Date after 365 days: ";
    date3.print();
    std::cout << std::endl;

    return 0;
}
