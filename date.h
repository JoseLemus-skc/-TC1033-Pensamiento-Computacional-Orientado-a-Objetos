#ifndef DATE_H
#define DATE_H

#include <string>

class Date{
    private:
    short hour;
    short day;
    short month;
    short year;

    std::string months[12];

    public:
    // Constructores
    Date(): hour(23), day(31), month(12), year(1999), months{"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"}{};
    Date(short h, short d, short m, short y): months{"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"}{
        hour = h;
        day = d;
        month = m;
        year = y;
    };

    short getHour();
    short getDay();
    short getMonth();
    short getYear();
    std::string getMonthName();
};

// Definicion (getters)
short Date::getHour(){
    return hour;
}
short Date::getDay(){
    return day;
}
short Date::getMonth(){
    return month;
}
short Date::getYear(){
    return year;
}
std::string Date::getMonthName(){
    return months[month - 1];
}

#endif