#ifndef PROMOSPAM_H
#define PROMOSPAM_H

# include <string>
# include <sstream>
# include "email.h"

class PromoSpam: public Email{
    private:
    // Atributos
    std::string promoCode;
    int discountPercentage;
    bool isUnsubscribeFunctional;
    
    // Procesamiento del Subject y Body
    std::string updateSubject();
    std::string updateBody(); 

    void setSubject();
    void setBody();

    public:
    // Constructors
    PromoSpam(): Email("", "", ""), promoCode(""), discountPercentage(0), isUnsubscribeFunctional(false){
        setSubject();
        setBody();
    }
    PromoSpam(std::string code, std::string receiver, std::string time): Email(receiver, time, "Importante"){
        promoCode = code;
        discountPercentage = 100; // Corregir a Random
        isUnsubscribeFunctional = false;

       // Actualizar subject y body
       setSubject();
       setBody();
    }

    // Setters
    void setCode(std::string code);
    void rollDiscount();
    void setUnsubscribe(bool state);

    // Getters
    std::string getCode();
    int getDiscount();
    bool unsubscriberState();
};


// Definiciones (updaters)
std::string PromoSpam::updateSubject(){
    std::stringstream aux;
    aux << "Se acaba el Ofertón ¡Aprovecha hasta " << discountPercentage << " porciento dcto!";
    return aux.str();
}
std::string PromoSpam::updateBody(){
    std::stringstream aux;
    aux << "¡Apurate! Aprovacha el siguiente codigo: " << promoCode << " para obtener " 
<< discountPercentage << " porciento de descuento en tu siguiente compra!!!";
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
void PromoSpam::rollDiscount(){
    discountPercentage = 100; // Corregir a Random
    setSubject();
    setBody();
}
void PromoSpam::setUnsubscribe(bool state){
    state = false;
    isUnsubscribeFunctional = state;
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