#ifndef PROMOSPAM_H
#define PROMOSPAM_H

#include <string>
#include <sstream>
#include "email.h"

class PromoSpam: public Email{
    private:
    // Atributos
    std::string promoCode;
    int discountPercentage;
    bool isUnsubscribeFunctional;
    
    // Procesamiento del Subject y Body
    std::string bodyDateFormat();

    std::string updateSubject();
    std::string updateBody(); 

    void setSubject();
    void setBody();

    public:
    // Constructores
    PromoSpam(): Email("", "", 23, 31, 12, 1999), promoCode(""), discountPercentage(0), isUnsubscribeFunctional(false){
        setSubject();
        setBody();
    }
    PromoSpam(std::string code, std::string receiver, short h, short d, short m, short y): Email(receiver, "Importante", h, d, m, y){
        promoCode = code;
        discountPercentage = -100;
        isUnsubscribeFunctional = false;

       // Actualizar subject y body
       setSubject();
       setBody();
    }

    // Setters
    void setCode(std::string code);
    void setDiscount(int discount);
    void setUnsubscribe();

    // Getters
    std::string getCode();
    int getDiscount();
    bool unsubscriberState();
};


// Definiciones (updaters)
std::string PromoSpam::bodyDateFormat(){
    std::stringstream aux;
    aux << sendTime.getMonthName() << " " << sendTime.getYear();
    return aux.str();
}

std::string PromoSpam::updateSubject(){
    std::stringstream aux;
    aux << "Se acaba el Oferton ¡Aprovecha hasta " << discountPercentage << "% de descuento!";
    return aux.str();
}

std::string PromoSpam::updateBody(){
    std::stringstream aux;
    aux << "¡Apurate! Aprovacha el siguiente codigo: " << promoCode << " para obtener " 
<< discountPercentage << "% de descuento en tu siguiente compra!!! \n\n Disponible hasta " << bodyDateFormat();
    return aux.str();
}


// Definiciones (setters)
void PromoSpam::setSubject(){
    subject = updateSubject();
}

void PromoSpam::setBody(){
    body = updateBody();
}

void PromoSpam::setCode(std::string code){
    promoCode = code;
    setSubject();

}

void PromoSpam::setDiscount(int discount){
    discountPercentage = discount;
    setSubject();
    setBody();
}

void PromoSpam::setUnsubscribe(){
    return;
}


// Definiciones (getters)
std::string PromoSpam::getCode(){
    return promoCode;
}

int PromoSpam::getDiscount(){
    return discountPercentage;
}

bool PromoSpam::unsubscriberState(){
    return isUnsubscribeFunctional;
}

#endif
