#ifndef TICKETS_H
#define TICKETS_H

#include <string>
#include <sstream>
#include "email.h"

class Tickets: public Email{
    private:
    // Atributos
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
    Tickets(): Email("", "", 23, 31, 12, 1999), concertName(""), artistName(""), ticketCode(""), isValid(false){
        setSubject();
        setBody();
    }
    Tickets(std::string concert, std::string artist, std::string code, std::string receiver,  short h, short d, short m, short y): Email(receiver, "Spam", h, d, m, y){
        concertName = concert;
        artistName = artist;
        ticketCode = code;
        isValid = false;

       // Actualizar subject y body
       setSubject();
       setBody();
    }

    // Setters
    void setConcert(std::string concert);
    void setArtist(std::string artist);
    void setCode(std::string code);
    void setValid(bool state);

    // Getters
    std::string getConcertName();
    std::string getArtistName();
    std::string getCode();
    bool getValidStatus();

    void punishment();
};

// Definiciones (updaters)
std::string Tickets::bodyDateFormat(){
    std::stringstream aux;
    aux << sendTime.getDay() << " de " << sendTime.getMonthName();
    return aux.str();
}

std::string Tickets::updateSubject(){
    std::stringstream aux;
    aux << "Tus Tickets para " << artistName << " en " << concertName;
    return aux.str();
}

std::string Tickets::updateBody(){
    std::stringstream aux;
    if (isValid == false){
        aux << "\nEstimado Fan: \nRecuerda que no tienes que descargar tus boletos SafeTix con codigo "
        << ticketCode << " para " << artistName << " este " << bodyDateFormat() << " porque son invalidos\nNo es necesario agregarlos a tu Wallet. Byeeeee";
    } else{
        aux << "\nEstimado Fan: \nRecuerda descargar tus boletos SafeTix con codigo " << ticketCode 
        << " para " << artistName << " este " << bodyDateFormat() << "\nRecuerda agregarlos a tu Wallet y de esta forma estaran disponibles aun sin conexion a internet";
    }
    return aux.str();
}

// Definiciones (setters)
void Tickets::setSubject(){
    subject = updateSubject();
}

void Tickets::setBody(){
    body = updateBody();
}

void Tickets::setConcert(std::string concert){
    concertName = concert;
    setSubject();
}

void Tickets::setArtist(std::string artist){
    artistName = artist;
    setSubject();
}

void Tickets::setCode(std::string code){
    ticketCode = code;
    setBody();
}

void Tickets::setValid(bool state){
    isValid = state;
    punishment();
    setBody();
}


// Definiciones (getters)
std::string Tickets::getConcertName(){
    return concertName;
}

std::string Tickets::getArtistName(){
    return artistName;
}

std::string Tickets::getCode(){
    return ticketCode;
}

bool Tickets::getValidStatus(){
    return isValid;
}

void Tickets::punishment(){
    emailPriority = "Ninguno. No te toca recibir nada. Byeeeee";
    deliveryMethod = "Paloma";
}

#endif
