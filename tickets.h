/*
 * Proyecto Email Gestioner
 * Jose Manuel Lemus Gomez
 * A01707194
 * 05/12/2025
 */

/*
 * Clase Tickets, contiene la informacion del concierto y el artista,
 * formatea fecha y hora y construye un texto con encabezado, asunto, cuerpo y remitente.
 */

#ifndef TICKETS_H
#define TICKETS_H

#include <string>
#include <sstream>
#include "email.h"

class Tickets: public Email{

    private:
    // Declaracion de variables de instancia
    std::string concertName;
    std::string artistName;
    std::string ticketCode;
    bool isValid;

    // Procesamiento del Subject y Body
    std::string bodyDateFormat();

    std::string updateSubject();
    std::string updateBody(); 

    void setSubject();
    void setBody();

    public:

    // Constructores

    /**
     * Constructor por default
     * @param
     * @return Objeto Tickets
     **/
    Tickets(): Email("", "", 23, 31, 12, 1999), concertName(""), artistName(""), ticketCode(""), isValid(false){
        setSubject();
        setBody();
    }

    /**
     * Constructor con parametros
     * Inicializa objeto con nombre del concierto, nombre del artista, receptor, prioridad y fecha
     * 
     * @param concert nombre del concierto
     * @param artist nombre del artista
     * @param code codigo del ticket
     * @param receiver receptor
     * @param h hora
     * @param d dia
     * @param m mes
     * @param y año
     * @return Objeto Date
     */
    Tickets(std::string concert, std::string artist, std::string code, std::string receiver,  short h, short d, short m, short y): Email(receiver, "Spam", h, d, m, y){
        concertName = concert;
        artistName = artist;
        ticketCode = code;
        isValid = false;

        setSubject();
        setBody();
    }

    // Declaracion de miembros de la clase (Setters)
    void setValid(bool state);
    void punishment();

    // Declaracion de miembros de la clase (Getters)
    std::string getConcertName();
    std::string getArtistName();
    std::string getCode();
    bool getValidStatus();
};


// Procesamiento de fecha

/**
 * Construye la fecha con formato (dia de mes)
 *
 * @param
 * @return string: fecha formateada
 */
std::string Tickets::bodyDateFormat(){
    std::stringstream aux;
    aux << sendTime.getDay() << " de " << sendTime.getMonthName();
    return aux.str();
}


// Construccion de asunto y cuerpo actualizados

/**
 * Construye el asunto basado en el nombre del artista y el concierto
 *
 * @param
 * @return string: asunto
 */
std::string Tickets::updateSubject(){
    std::stringstream aux;
    aux << "Tus Tickets para " << artistName << " en " << concertName;
    return aux.str();
}

/**
 * Construye el cuerpo basado en el nombre del artista, fecha y validez de los tickets
 *
 * @param
 * @return string: cuerpo
 */
std::string Tickets::updateBody(){
    std::stringstream aux;
    if (isValid == false){
        aux << "\nEstimado Fan: \nRecuerda que no tienes que descargar tus boletos SafeTix con codigo "
        << ticketCode 
        << " para "
        << artistName 
        << " este "
        << bodyDateFormat() 
        << " porque son invalidos\nNo es necesario agregarlos a tu Wallet. Byeeeee";
    } else{
        aux << "\nEstimado Fan: \nRecuerda descargar tus boletos SafeTix con codigo "
        << ticketCode 
        << " para " 
        << artistName 
        << " este " 
        << bodyDateFormat()
        << "\nRecuerda agregarlos a tu Wallet y de esta forma estaran disponibles aun sin conexion a internet";
    }
    return aux.str();
}


// Aplicacion de las actualizaciones al asunto y cuerpo

/**
 * Setter interno de asunto
 *
 * @param
 * @return void
 */
void Tickets::setSubject(){
    subject = updateSubject();
}

/**
 * Setter interno de cuerpo
 *
 * @param
 * @return void
 */
void Tickets::setBody(){
    body = updateBody();
}

// Setter de estatus de validez

/**
 * Cambia la validez del ticket y actualiza el cuerpo.
 *
 * @param state: validez
 * @return
 */
void Tickets::setValid(bool state){
    isValid = state;
    punishment();
    setBody();
}

/**
 * Cambia la prioridad y el metodo de entrega del email.
 *
 * @param
 * @return
 */
void Tickets::punishment(){
    emailPriority = "Ninguno. No te toca recibir nada. Byeeeee";
    deliveryMethod = "Paloma";
}


// Getters del concierto, artista, codigo y validez

/**
 * Regresa el nombre del concierto.
 *
 * @param
 * @return string: nombre del concierto
 */
std::string Tickets::getConcertName(){
    return concertName;
}

/**
 * Regresa el nombre del artista.
 *
 * @param
 * @return string: nombre del artista
 */
std::string Tickets::getArtistName(){
    return artistName;
}

/**
 * Regresa el codigo del ticket.
 *
 * @param
 * @return string: codigo
 */
std::string Tickets::getCode(){
    return ticketCode;
}

/**
 * Regresa la validez del ticket.
 *
 * @param
 * @return bool: validez
 */
bool Tickets::getValidStatus(){
    return isValid;
}

#endif
