#ifndef EMAIL_H
#define EMAIL_H

#include <string>

class Email{
protected:
    // Atributos
    std::string subject;
    std::string body;
    std::string senderEmail;
    std::string receiverEmail;
    std::string sendTime;
    std::string emailPriority;
    std::string deliveryMethod;

public:
    // Constructors
    Email(){}
    Email(std::string receiver, std::string time){
        subject = "";
        body = "";
        senderEmail = "noreply@ticketmaster.com.mx";
        receiverEmail = receiver;
        sendTime = time;
        emailPriority = "IMPORTANTE";
        deliveryMethod = "Correo electronico";
    }

    // Setters
    void setReceiver(std::string address);
    void setTime(std::string date);
    void setPriority(std::string priority);

    // Getters
    std::string getSender();
    std::string getReceiver();
    std::string getTime();
    std::string getPriority();
    std::string getDelivery();

    // Boceto de Email
    std::string emailDraft();
};


// Definiciones (Setters)
void Email::setReceiver(std::string address){
    receiverEmail = address;
}
void Email::setTime(std::string date){
    sendTime = date;
}
void Email:: setPriority(std::string priority){
    emailPriority = priority;
}

// Definiciones (Getters)
std::string Email::getSender(){
    return senderEmail;
}
std::string Email::getReceiver(){
    return receiverEmail;
}
std::string Email::getTime(){
    return sendTime;
}
std::string Email::getPriority(){
    return emailPriority;
}
std::string Email::getDelivery(){
    return deliveryMethod;
}


// Definicion (Boceto de Email)
std::string Email::emailDraft(){
    std::string generalInfo = "Para: " + receiverEmail + "   Enviado:  " + sendTime; 
    return generalInfo + "\n" + subject + "\n" + body;
}

#endif