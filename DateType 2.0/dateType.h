#ifndef DATE_TYPE_H
#define DATE_TYPE_H

#include <iostream>

class dateType {
private:
    int month;
    int day;
    int year;

public:
    dateType();
    dateType(int m, int d, int y);

    void setMonth(int m);
    void setDay(int d);
    void setYear(int y);

    int getMonth() const;
    int getDay() const;
    int getYear() const;

    bool isLeapYear() const;
    int daysInMonth(int m, int y) const;

    void print() const;

    int daysPassed() const;
    int daysRemaining() const;

    void setDateFromDays(int days);
};

#endif
#pragma once
