/*
 * Proyecto Email Gestioner
 * Jose Manuel Lemus Gomez
 * A01707194
 * 05/12/2025
 */

/*
 * Clase PurchaseConfirmation, hija de Email dedicada a correos de confirmación de compra.
 * Genera asunto y cuerpo basados en monto pagado, ID de orden, fecha y cargos adicionales calculados.
 */

#ifndef PURCHASECONFIRMATION_H
#define PURCHASECONFIRMATION_H

#include <string>
#include <sstream>
#include "email.h"

// Declaración de objeto PurchaseConfirmation que hereda de Email
class PurchaseConfirmation: public Email{

    private:

    // Declaración de variables de instancia
    float moneySpent;
    float moneyOwed;
    std::string orderID;
    bool isRefundable;

    // Procesamiento del asunto y cuerpo
    std::string bodyDateFormat();
    std::string updateSubject();
    std::string updateBody(); 

    // Setters internos
    void setSubject();
    void setBody();
    void addMadeUpFees();
    
    public:
    
     // Constructores

    /**
     * Constructor por default
     *
     * @param
     * @return Objeto PurchaseConfirmation
     */
    PurchaseConfirmation(): Email("", "", 23, 31, 12, 1999), moneySpent(0), moneyOwed(0), isRefundable(false){
        addMadeUpFees();
        setSubject();
        setBody();
    }

     /**
     * Constructor con parametros
     * Inicializa objeto con monto, ID de orden, receptor, prioridad y fecha
     *
     * @param money monto gastado
     * @param ID oID de orden
     * @param receiver receptor
     * @param h hora
     * @param d dia
     * @param m mes
     * @param y año
     * @return Objeto PurchaseConfirmation
     */
    PurchaseConfirmation(float money, std::string ID, std::string receiver, short h, short d, short m, short y): Email(receiver, "Main Inbox", h, d, m, y){
        moneySpent = money;
        moneyOwed = 0;
        orderID = ID;
        isRefundable = false;

        // Apicar cargos adicionales
        addMadeUpFees();

       // Actualizar subject y body
       setSubject();
       setBody();
    }

    // Declaracion de miembros de la clase (Setters)
    void setRefundable(bool state);

    // Declaracion de miembros de la clase (Getters)
    float getMoneySpent();
    float getMoneyOwed();
    std::string getOrderID();
    bool getRefundableStatus();
};


// Procesamiento de fecha

/**
 * Construye la fecha con formato (dia/mes/año)
 *
 * @param
 * @return string: fecha formateada
 */
std::string PurchaseConfirmation::bodyDateFormat(){
    std::stringstream aux;
    aux << sendTime.getDay() << "/" << sendTime.getMonth() << "/" << sendTime.getYear();
    return aux.str();
}


// Construccion de asunto y cuerpo actualizados

/**
 * Construye el asunto basado en el ID de la orden
 *
 * @param
 * @return string: asunto
 */
std::string PurchaseConfirmation::updateSubject(){
    std::stringstream aux;
    aux << "Resumen de tu compra " << orderID << " en Ticketmaster" ;
    return aux.str();
}

/**
 * Construye el cuerpo basado en monto, cargos adicionales y fecha
 *
 * @param
 * @return string: cuerpo
 */
std::string PurchaseConfirmation::updateBody(){
    std::stringstream aux;
    aux << "Informacion del pago: \nDetalle de Cargos: $" << moneySpent << "\nService charge a pagar adicional: $" << moneyOwed << " (Acumulan intereses a partir de " << bodyDateFormat()
    << ")\n\nTu Telefono es Tu Boleto. La opcion mas rapida y sencilla para tener tus boletos! Podras visualizarlos en tu celular desde la app Ticketmaster" ;
    return aux.str();
}


// Aplicacion de las actualizaciones al asunto y cuerpo

/**
 * Setter interno de asunto
 *
 * @param
 * @return void
 */
void PurchaseConfirmation::setSubject(){
    subject = updateSubject();
}

/**
 * Setter interno de cuerpo
 *
 * @param
 * @return void
 */
void PurchaseConfirmation::setBody(){
    body = updateBody();
}


// Setter de reembolso

/**
 * Setter de habilidad de reembolsar
 *
 * @param state
 * @return void
 */
void PurchaseConfirmation::setRefundable(bool state){
    if(state != false){
        exit(0);
    }
}


// Getters de monto, cargos adicionales, ID, y reembolso

/**
 * Getter de monto
 *
 * @param
 * @return float: dinero gastado
 */
float PurchaseConfirmation::getMoneySpent(){
    return moneySpent;
}

/**
 * Getter de cargos adicionales
 *
 * @param
 * @return float: cargos adicionales
 */
float PurchaseConfirmation::getMoneyOwed(){
    return moneyOwed;
}

/**
 * Getter de ID
 *
 * @param
 * @return string: ID de la orden
 */
std::string PurchaseConfirmation::getOrderID(){
    return orderID;
}

/**
 * Getter de habilidad de reembolsar
 *
 * @param
 * @return bool: habilidad de reembolsar
 */
bool PurchaseConfirmation::getRefundableStatus(){
    return isRefundable;
}


// Calculo de cargos adicionales

/**
 * @param
 * @return void
 */
void PurchaseConfirmation::addMadeUpFees(){
    moneyOwed = moneySpent * 2;
}


#endif
