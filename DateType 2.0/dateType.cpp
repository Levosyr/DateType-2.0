#include "dateType.h"
#include <stdexcept>

dateType::dateType() {
    month = 1;
    day = 1;
    year = 1900;
}

dateType::dateType(int m, int d, int y) {
    if (m < 1 || m > 12)
        throw std::invalid_argument("Invalid month");

    if (d < 1 || d > daysInMonth(m, y))
        throw std::invalid_argument("Invalid day");

    if (y < 1900)
        throw std::invalid_argument("Year must be >= 1900");

    month = m;
    day = d;
    year = y;
}

void dateType::setMonth(int m) {
    if (m < 1 || m > 12)
        throw std::invalid_argument("Invalid month");

    month = m;
}

void dateType::setDay(int d) {
    if (d < 1 || d > daysInMonth(month, year))
        throw std::invalid_argument("Invalid day");

    day = d;
}

void dateType::setYear(int y) {
    if (y < 1900)
        throw std::invalid_argument("Year must be >= 1900");

    year = y;
}

int dateType::getMonth() const {
    return month;
}

int dateType::getDay() const {
    return day;
}

int dateType::getYear() const {
    return year;
}

bool dateType::isLeapYear() const {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int dateType::daysInMonth(int m, int y) const {
    if (m == 2)
        return isLeapYear() ? 29 : 28;
    else if (m == 4 || m == 6 || m == 9 || m == 11)
        return 30;
    else
        return 31;
}

void dateType::print() const {
    std::cout << month << "-" << day << "-" << year;
}

int dateType::daysPassed() const {
    int days = day;
    for (int i = 1; i < month; ++i)
        days += daysInMonth(i, year);
    return days;
}

int dateType::daysRemaining() const {
    return isLeapYear() ? 366 - daysPassed() : 365 - daysPassed();
}

void dateType::setDateFromDays(int days) {
    int m = 1;
    int totalDays = days;
    while (totalDays > daysInMonth(m, year)) {
        totalDays -= daysInMonth(m, year);
        m++;
    }
    month = m;
    day = totalDays;
}
