/*
 * Proyecto Email Gestioner
 * Jose Manuel Lemus Gomez
 * A01707194
 * 05/12/2025
 */

/*
 * Clase Date, maneja hora, día, mes y año, un arreglo que incluye nombres de meses
 * y un metodo getMonthName() que devuelve el nombre del mes basado en su valor numerico.
 */

#ifndef DATE_H
#define DATE_H

#include <string>

class Date{

    private:
    // Declaracion de variables de instancia.
    short hour;
    short day;
    short month;
    short year;

    // Arreglo que almacena los nombres de los meses
    std::string months[12];

    public:
    // Constructores.

    /**
     * Constructor por default
     *
     * @param
     * @return Objeto Date
     */
    Date(): hour(23), day(31), month(12), year(1999), 
        months{"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
            "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"}{}

    /**
     * Constructor con parametros
     * 
     * @param h hora
     * @param d dia
     * @param m mes
     * @param y año
     * @return Objeto Date
     */
    Date(short h, short d, short m, short y):
        months{"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
            "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"}{

        hour = h;
        day = d;
        month = m;
        year = y;

    }

    // Declaracion de miembros de la clase.
    short getHour();
    short getDay();
    short getMonth();
    short getYear();
    std::string getMonthName();
};

// Getters de hora, dia, mes y año

/**
 * getter hora
 *
 * @param
 * @return short: hora 
*/
short Date::getHour(){
    return hour;
}

/**
 * getter dia
*
 * @param
 * @return short: dia
 */
short Date::getDay(){
    return day;
}

/**
 * getter mes
 * 
 * @param
 * @return short: mes
 */
short Date::getMonth(){
    return month;
}

/**
 * getter año
 * 
 * @param
 * @return short: año
 */
short Date::getYear(){
    return year;
}

/**
 * 
 * Devuelve el nombre del mes a partir del arreglo de meses
 * Ajusta el indice (mes 1 = posición 0)
 * 
 * @param
 * @return string: nombre de mes
 */
std::string Date::getMonthName(){
    return months[month - 1];
}

#endif

