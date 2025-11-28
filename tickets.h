#ifndef TICKETS_H
#define TICKETS_H

#include <string>
#include <sstream>
#include "email.h"

class Tickets: public Email{
    private:
    std::string concertName;
    std::string artistName;
    std::string ticketCode;
    bool isValid;

    // Procesamiento del Subject y Body
    std::string updateSubject();
    std::string updateBody(); 

    void setSubject();
    void setBody();

    public:
    // Constructors
    Tickets(): Email("", "", ""), concertName(""), artistName(""), ticketCode(""), isValid(false){
        setSubject();
        setBody();
    }
    Tickets(std::string concert, std::string artist, std::string code, std::string receiver, std::string time): Email(receiver, time, "Spam Inbox"){
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
    void setValid(bool state); // Corregir a Random

    // Getters
    std::string getConcertName();
    std::string getArtistName();
    std::string getCode();
    bool getValidStatus();
};

// Definiciones (updaters)
std::string Tickets::updateSubject(){
    std::stringstream aux;
    aux << artistName << " en " << concertName;
    return aux.str();
}
std::string Tickets::updateBody(){
    std::stringstream aux;
    if (isValid == false){
        aux << "Fecha del concierto: " << sendTime << "\n Estimado Fan: \n Recuerda descargar tus boletos [INVALIDOS] SafeTix con codigo "
        << ticketCode << " agregalos a tu Wallet y de esta forma estaran disponibles aun sin conexion a internet";
    } else{
        aux << "Fecha del concierto: " << sendTime << "\n Estimado Fan: \n Recuerda descargar tus boletos safeTix con codigo "
        << ticketCode << " agregalos a tu Wallet y de esta forma estaran disponibles aun sin conexion a internet";
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

#endif
