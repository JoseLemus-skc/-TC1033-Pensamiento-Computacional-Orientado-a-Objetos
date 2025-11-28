#ifndef PURCHASECONFIRMATION_H
#define PURCHASECONFIRMATION_H

#include <string>
#include <sstream>
#include "email.h"

class PurchaseConfirmation: public Email{
    private:
    float moneySpent;
    float moneyOwed;
    std::string orderID;
    bool isRefundable;

    // Procesamiento del Subject y Body
    std::string updateSubject();
    std::string updateBody(); 

    void setSubject();
    void setBody();

    void addMadeUpFees();
    
    public:
    // Constructors
    PurchaseConfirmation(): Email("", "", ""), moneySpent(0), moneyOwed(0), isRefundable(false){
        addMadeUpFees();
        setSubject();
        setBody();
    }
    PurchaseConfirmation(float money, std::string ID, std::string receiver, std::string time): Email(receiver, time, "Main Inbox"){
        moneySpent = money;
        moneyOwed = 0;
        orderID = ID;
        isRefundable = false;

        // Setup moneyOwed
        addMadeUpFees();

       // Actualizar subject y body
       setSubject();
       setBody();
    }

    // Setters
    void setMoneySpent(float money);
    void setOrderID(std::string ID);
    void setRefundable(bool state);

    // Getters
    float getMoneySpent();
    float getMoneyOwed();
    std::string getOrderID();
    bool getRefundableStatus();
};


// Definiciones (updaters)
std::string PurchaseConfirmation::updateSubject(){
    std::stringstream aux;
    aux << "Resumen de tu compra " << orderID << " en Ticketmaster" ;
    return aux.str();
}
std::string PurchaseConfirmation::updateBody(){
    std::stringstream aux;
    aux << "Informacion del pago: \nDetalle de Cargos: " << moneySpent << "\nService charge a pagar adicional: " << moneyOwed
    << "\nTu Telefono es Tu Boleto ¡La opcion mas rapida y sencilla para tener tus boletos! Podras visualizarlos en tu celular desde la app Ticketmaster" ;
    return aux.str();
}


// Definiciones (setters)
void PurchaseConfirmation::setSubject(){
    subject = updateSubject();
}
void PurchaseConfirmation::setBody(){
    body = updateBody();
}
void PurchaseConfirmation::setMoneySpent(float money){
    moneySpent = money;
    addMadeUpFees();
    setBody();
}
void PurchaseConfirmation::setOrderID(std::string ID){
    orderID = ID;
    setSubject();
}
void PurchaseConfirmation::setRefundable(bool state){
    if(state != false){
        exit(0);
    }
}
void PurchaseConfirmation::addMadeUpFees(){
    moneyOwed = moneySpent * 2;
}


// Definiciones (Getters)
float PurchaseConfirmation::getMoneySpent(){
    return moneySpent;
}
float PurchaseConfirmation::getMoneyOwed(){
    return moneyOwed;
}
std::string PurchaseConfirmation::getOrderID(){
    return orderID;
}
bool PurchaseConfirmation::getRefundableStatus(){
    return isRefundable;
}


#endif
