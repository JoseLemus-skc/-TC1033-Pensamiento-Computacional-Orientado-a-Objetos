/*
 * Proyecto Email Gestioner
 * Jose Manuel Lemus Gomez
 * A01707194
 * 05/12/2025
 */

/*
 * Clase PromoSpam, hija de Email dedicada a correos de descuentos. 
 * Genera asunto y cuerpo basados en código de oferta,
 * porcentaje de descuento y fecha.
 */

#ifndef PROMOSPAM_H
#define PROMOSPAM_H

#include <string>
#include <sstream>
#include "email.h"

// Declaracion de objeto PromoSpam que hereda de Email
class PromoSpam: public Email{

    private:
    // Declaracion de variables de instancia
    std::string promoCode;
    int discountPercentage;
    bool isUnsubscribeFunctional;

    // Procesamiento del asunto y cuerpo
    std::string bodyDateFormat();
    std::string updateSubject();
    std::string updateBody(); 

    // Setters internos
    void setSubject();
    void setBody();

    public:

     // Constructores

    /**
     * Constructor por default
     *
     * @param
     * @return Objeto PromoSpam
     */
    PromoSpam(): Email("", "", 23, 31, 12, 1999), promoCode(""), discountPercentage(0), isUnsubscribeFunctional(false){
        setSubject();
        setBody();
    }

    /**
     * Constructor con parametros
     * Inicializa objecto con codigo, receptor, prioridad y fecha
     *
     * @param code codigo promocional
     * @param receiver receptor
     * @param h hora
     * @param d dia
     * @param m mes
     * @param y año
     * @return Objeto PromoSpam
     */
    PromoSpam(std::string code, std::string receiver, short h, short d, short m, short y): Email(receiver, "Importante", h, d, m, y){
        promoCode = code;
        discountPercentage = -100;
        isUnsubscribeFunctional = false;

       // Actualizar subject y body
       setSubject();
       setBody();
    }

    // Declaracion de miembros de la clase (Setters)
    void setDiscount(int discount);

    // Declaracion de miembros de la clase (Getters)
    std::string getCode();
    int getDiscount();
    bool unsubscriberState();
};


// Procesamiento de la fecha

/**
 * Formatea fecha usando nombre de mes y año para el cuerpo del correo
 *
 * @param
 * @return string: mes y año formateados
 */
std::string PromoSpam::bodyDateFormat(){
    std::stringstream aux;
    aux << sendTime.getMonthName() << " " << sendTime.getYear();
    return aux.str();
}


// Construccion de asunto y cuerpo actualizados

/**
 * Construye el asunto en base al descuento
 *
 * @param
 * @return string: asunto
 */
std::string PromoSpam::updateSubject(){
    std::stringstream aux;
    aux << "Se acaba el Oferton! Aprovecha hasta " << discountPercentage << "% de descuento!";
    return aux.str();
}

/**
 * Construye el cuerpo en base al codigo promocional, el descuento y la fecha
 *
 * @param
 * @return string: cuerpo
 */
std::string PromoSpam::updateBody(){
    std::stringstream aux;
    aux << "Apurate! Aprovacha el siguiente codigo: " << promoCode << " para obtener " 
<< discountPercentage << "% de descuento en tu siguiente compra!!! \n\nDisponible hasta " << bodyDateFormat();
    return aux.str();
}


// Aplicacion de las actualizaciones al asunto y cuerpo

/**
 * Setter interno de asunto
 *
 * @param
 * @return void
 */
void PromoSpam::setSubject(){
    subject = updateSubject();
}

/**
 * Setter interno de cuerpo
 *
 * @param
 * @return void
 */
void PromoSpam::setBody(){
    body = updateBody();
}


// Setters de codigo promocional, descuento y habilidad de desuscribirse

/**
 * Setter de descuento
 *
 * @param discount
 * @return void
 */
void PromoSpam::setDiscount(int discount){
    discountPercentage = discount;
    setSubject();
    setBody();
}



// Getters de codigo promocional, descuento y habilidad de desuscribirse

/**
 * Getter de código promocional
 *
 * @param
 * @return string: codigo
 */
std::string PromoSpam::getCode(){
    return promoCode;
}

/**
 * Getter de descuento
 *
 * @param
 * @return int: descuento
 */
int PromoSpam::getDiscount(){
    return discountPercentage;
}

#endif
