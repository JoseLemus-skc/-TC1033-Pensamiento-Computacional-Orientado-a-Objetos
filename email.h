/*
 * Proyecto Email Gestioner
 * Jose Manuel Lemus Gomez
 * A01707194
 * 05/12/2025
 */

/*
 * Clase Email, contiene los métodos genericos para gestionar correos,
 * formatea fecha y hora y construye un texto con encabezado, asunto, cuerpo y remitente.
 * Sirve como base para clases hijas: Spam Promocional, Confirmaciones de compra y Tickets.
 */

#ifndef EMAIL_H
#define EMAIL_H

#include <string>
#include <sstream>
#include "date.h"

// Declaracion de la clase abstracta
class Email{

private:
    // Devuelve la fecha del correo con formato
    std::string dateFormat();

protected:
    // Declaracion de variables de instancia
    std::string subject;
    std::string body;
    std::string senderEmail;
    std::string receiverEmail;
    Date sendTime;
    std::string emailPriority;
    std::string deliveryMethod;

public:
    // Constructores

    /**
    * Constructor por default
    *
    * @param
    * @return Objeto Email
    */
    Email(){}

    /**
    * Constructor con parámetros
    * Inicializa objeto con receptor, prioridad y fecha
    *
    * @param receiver receptor
    * @param priority prioridad
    * @param h hora
    * @param d dia
    * @param m mes
    * @param y año
    * @return Objeto Email
    */
    Email(std::string receiver, std::string priority, short h, short d, short m, short y){
        subject = "";
        body = "";
        senderEmail = "noreply@ticketmaster.com.mx";
        receiverEmail = receiver;
        sendTime = Date(h, d, m, y);
        emailPriority = priority;
        deliveryMethod = "Correo electronico";
    }

    // Declaracion de miembros de la clase (Setters)
    void setReceiver(std::string address);
    void setPriority(std::string priority);

    // Declaracion de miembros de la clase (Getters)
    std::string getPriority();
    std::string getDelivery();
    std::string getDate();
    std::string getReceiver();
    std::string getSubject();
    std::string getBody();

    // Devuelve el correo con formato
    std::string emailDraft();
};


// Setters de receptor y prioridad

/**
 * Setter de receptor.
 *
 * @param address
 * @return void
 */
void Email::setReceiver(std::string address){
    receiverEmail = address;
}

/**
 * Setter de prioridad
 *
 * @param priority
 * @return void
 */
void Email:: setPriority(std::string priority){
    emailPriority = priority;
}


// Getters de prioridad, metodo de entrega, asunto, cuerpo, receptor y fecha

/**
 * Getter de prioridad
 *
 * @param
 * @return string: prioridad
 */
std::string Email::getPriority(){
    return emailPriority;
}

/**
 * Getter de metodo de entrega
 *
 * @param
 * @return string: metodo de entrega
 */
std::string Email::getDelivery(){
    return deliveryMethod;
}

/**
 * Getter de asunto
 *
 * @param
 * @return string: asunto
 */
std::string Email::getSubject(){
    return subject;
}

/**
 * Getter de cuerpo
 *
 * @param
 * @return string: cuerpo
 */
std::string Email::getBody(){
    return body;
}

/**
 * Getter de receptor
 *
 * @param
 * @return string: receptor
 */
std::string Email::getReceiver(){
    return receiverEmail;
}

/**
 * Getter de fecha con formato
 *
 * @param
 * @return string: fecha formateada
 */
std::string Email::getDate(){
    return dateFormat();
}


// Procesamiento de la fecha y hora

/**
 * Construye la fecha con formato (hora - dia/mes/año)
 *
 * @param
 * @return string: fecha formateada
 */
std::string Email::dateFormat(){
    std::stringstream aux;
    aux << sendTime.getHour() << ":00 - " 
    << sendTime.getDay() << "/" 
    << sendTime.getMonth() << "/" 
    << sendTime.getYear();  
    return aux.str();
}


// Procesamiento del texto de email

/**
 * Construye el correo con encabezado, asunto, cuerpo y remitente
 *
 * @param
 * @return string: email formateado
 */
std::string Email::emailDraft(){
    std::string header = "Para: " 
                + receiverEmail 
                + "       Enviado: " 
                + dateFormat(); 
    return header + "\n\n" + subject + "\n" + body  + "\n\n" + senderEmail;
}

#endif
