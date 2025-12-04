#ifndef EMAIL_H
#define EMAIL_H

#include <string>
#include <sstream>
#include "date.h"

class Email{
private:
    std::string dateFormat();

protected:
    // Atributos
    std::string subject;
    std::string body;
    std::string senderEmail;
    std::string receiverEmail;
    Date sendTime;
    std::string emailPriority;
    std::string deliveryMethod;

public:
    // Constructores
    Email(){}
    Email(std::string receiver, std::string priority, short h, short d, short m, short y){
        subject = "";
        body = "";
        senderEmail = "noreply@ticketmaster.com.mx";
        receiverEmail = receiver;
        sendTime = Date(h, d, m, y);
        emailPriority = priority;
        deliveryMethod = "Correo electronico";
    }

    // Setters
    void setReceiver(std::string address);
    void setPriority(std::string priority);

    // Getters
    std::string getPriority();
    std::string getDelivery();
    std::string getDate();
    std::string getReceiver();

    std::string getSubject();
    std::string getBody();

    // Boceto de Email
    std::string emailDraft();
};


// Definiciones (Setters)
void Email::setReceiver(std::string address){
    receiverEmail = address;
}
void Email:: setPriority(std::string priority){
    emailPriority = priority;
}

// Definiciones (Getters)
std::string Email::getPriority(){
    return emailPriority;
}
std::string Email::getDelivery(){
    return deliveryMethod;
}
std::string Email::getSubject(){
    return subject;
}
std::string Email::getBody(){
    return body;
}
std::string Email::getReceiver(){
    return receiverEmail;
}
std::string Email::getDate(){
    return dateFormat();
}

// Definicion (dateFormat)
std::string Email::dateFormat(){
    std::stringstream aux;
    aux << sendTime.getHour() << " - " << sendTime.getDay() << "/" << sendTime.getMonth() << "/" << sendTime.getYear();  
    return aux.str();
}

// Definicion (Boceto de Email)
std::string Email::emailDraft(){
    std::string header = "Para: " + receiverEmail + "       Enviado: " + dateFormat(); 
    return header + "\n\n" + subject + "\n" + body  + "\n\n" + senderEmail;
}

#endif
