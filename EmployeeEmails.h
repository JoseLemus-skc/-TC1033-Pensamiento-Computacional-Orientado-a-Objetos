/*
 * Proyecto Email Gestioner
 * Jose Manuel Lemus Gomez
 * A01707194
 * 05/12/2025
 */

/*
 * Clase EmployeeEmails, maneja grupos de Emails divididos en las clases
 * hijas PromoSpam, PurchaseConfirmation y Tickets.
 */

#ifndef EMPLOYEEEMAILS_H_
#define EMPLOYEEEMAILS_H_

#include <string>
#include "promospam.h"
#include "purchaseconfirmation.h"
#include "tickets.h"

const int MAX = 16;

class EmployeeEmails{

    private:

    // Declaracion de variables de instancia.
    std::string employeeName;
    float perEmailCommission, earnings;
    int penalties;

    PromoSpam promoSpamList[MAX];
    PurchaseConfirmation purchaseConfirmationList[MAX];
    Tickets ticketList[MAX];

    int promoSpamIndex, purchaseConfirmationIndex, ticketIndex;

    // Procesamiento de calculo de ganancias
    void calculateEarnings();


    public:

    // Constructores
    /**
     * Constructor por default
     * @param
     * @return Objeto EmployeeEmails
     **/
    EmployeeEmails(){}

      /**
     * Constructor con parametros
     *
     * @param name nombre
     * @param commission comision
     * @return Objeto EmployeeEmails
     */
    EmployeeEmails(std::string name, float commission){
        employeeName = name;
        perEmailCommission = commission;
        penalties = 0;
        earnings = 0;

        promoSpamIndex = 0;
        purchaseConfirmationIndex = 0;
        ticketIndex = 0;
    }

    // Creacion de correos
    void createPromoSpam(std::string code, std::string receiver, short h, short d, short m, short y);
    void createPurchaseConfirmation(float money, std::string ID, std::string receiver, short h, short d, short m, short y);
    void createTicket(std::string concert, std::string artist, std::string code, std::string receiver,  short h, short d, short m, short y);

    // Declaracion de miembros de la clase (Setters)
    void setSpamDiscount(int index, int discount);
    void setRefundableStatus(int index, bool status);
    void setValidStatus(int index, bool status);
    
    void setPriorityPromo(int index, std::string priority);
    void setPriorityPurchase(int index, std::string priority);
    void setPriorityTicket(int index, std::string priority);
    
    // Declaracion de miembros de la clase (Getters)
    std::string getEmployeeName();
    
    std::string getPromoSpam(int index);
    std::string getPurchaseConfirmation(int index);
    std::string getTicket(int index);
    std::string getEarnings();

    int getPromoIndex();
    int getPurchaseIndex();
    int getTicketIndex();

    std::string getRecieverDatePromo(int index);
    std::string getRecieverDatePurchase(int index);
    std::string getRecieverDateTicket(int index);
};


//  Creacion de correos

/**
 * Manda a llamar al constructor de PromoSpam y lo agrega al arreglo
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
void EmployeeEmails::createPromoSpam(std::string code, std::string receiver, short h, short d, short m, short y){
    if (0 <= promoSpamIndex && promoSpamIndex < 16){
      promoSpamList[promoSpamIndex] = PromoSpam(code, receiver, h, d, m, y);
      promoSpamIndex ++;  
    }else{
        return;
    }
}

/**
 * Manda a llamar al constructor de PurchaseConfirmation y lo agrega al arreglo
 * Inicializa objeto con monto, ID de orden, receptor, prioridad y fecha
 *
 * @param money monto gastado
 * @param ID identificador de orden
 * @param receiver receptor
 * @param h hora
 * @param d dia
 * @param m mes
 * @param y año
 * @return Objeto PurchaseConfirmation
 */
void EmployeeEmails::createPurchaseConfirmation(float money, std::string ID, std::string receiver, short h, short d, short m, short y){
    if (0 <= purchaseConfirmationIndex && purchaseConfirmationIndex < 16){
      purchaseConfirmationList[purchaseConfirmationIndex] = PurchaseConfirmation(money, ID, receiver, h, d, m, y);
      purchaseConfirmationIndex ++;  
    }else{
        return;
    }
}

/**
 * Manda a llamar al constructor de PurchaseConfirmation y lo agrega al arreglo
 * Inicializa objeto con nombre del concierto, nombre del artista, receptor, prioridad y fecha
 * 
 * @param concert nombre del concierto
 * @param artist nombre del artista
 * @param code codigo del ticket
 * @param receiver receptor
 * @param h hora
 * @param d dia
 * @param m mes
 * @param y año
 * @return Objeto Date
 */
void EmployeeEmails::createTicket(std::string concert, std::string artist, std::string code, std::string receiver,  short h, short d, short m, short y){
    if (0 <= ticketIndex && ticketIndex < 16){
      ticketList[ticketIndex] = Tickets(concert, artist, code, receiver, h, d, m, y);
      ticketIndex ++;  
    }else{
        return;
    }
}


// Setters de descuento, habilidad de rembolso, validez del boleto y prioridad

/**
 * Modifica el descuento de un PromoSpam
 *
 * @param index
 * @param discount
 * @return void
 */
void EmployeeEmails::setSpamDiscount(int index, int discount){
    index -= 1;
    penalties ++;

    if (0 <= index && index <= promoSpamIndex){
        promoSpamList[index].setDiscount(discount);
    }else{
        return;
    };

}

/**
 * Cambia la habilidad de reembolsar de un PurchaseConfirmation
 *
 * @param index
 * @param status
 * @return void
 */
void EmployeeEmails::setRefundableStatus(int index, bool status){
    index -= 1;
    penalties ++;

    if (0 <= index && index <= purchaseConfirmationIndex){
        purchaseConfirmationList[index].setRefundable(status);
    }else{
        return;
    }

}

/**
 * Cambia validez del Ticket
 *
 * @param index
 * @param status
 * @return void
 */
void EmployeeEmails::setValidStatus(int index, bool status){
    index -= 1;
    penalties ++;

    if (0 <= index && index <= ticketIndex){
        ticketList[index].setValid(status);
    }else{
        return;
    }

}

/**
 * Calcula el sueldo final tomando en cuenta las penalizaciones acumuladas
 *
 * @param
 * @return void
 */
void EmployeeEmails::calculateEarnings(){
    int totalEmails = promoSpamIndex + purchaseConfirmationIndex + ticketIndex;
    earnings = (perEmailCommission * totalEmails) - (perEmailCommission * penalties);
}

// Setters de prioridad

/**
 * Cambia prioridad de un PromoSpam
 *
 * @param index
 * @param priority
 * @return void
 */
void EmployeeEmails::setPriorityPromo(int index, std::string priority){
    index -= 1;
    penalties ++;

    if (0 <= index && index <= promoSpamIndex){
        promoSpamList[index].setPriority(priority);
    }else{
        return;
    }

}

/**
 * Cambia prioridad de un PurchaseConfirmation
 *
 * @param index
 * @param priority
 * @return void
 */
void EmployeeEmails::setPriorityPurchase(int index, std::string priority){
    penalties ++;
    index -= 1;

    if (0 <= index && index <= purchaseConfirmationIndex){
        purchaseConfirmationList[index].setPriority(priority);
    }else{
        return;
    }

}

/**
 * Cambia la priorioridad y manda a llamar a la funcion de castigo en Tickets
 *
 * @param index
 * @return void
 */
void EmployeeEmails::setPriorityTicket(int index, std::string priority){
    penalties ++;
    index -= 1;

    if (0 <= index && index <= ticketIndex){
        ticketList[index].setPriority(priority);
    }else{
        return;
    }

}


// Getters de nombre de empleado, ganancias, emails, sus fechas, receptores y cantidad

/**
 * Getter del nombre del empleado
 *
 * @param
 * @return string: nombre
 */
std::string EmployeeEmails::getEmployeeName(){
    return employeeName;
};

/**
 * Manda a llamar al calculo de sueldo final y devuelve el resultado
 *
 * @param
 * @return string: ganancias
 */
std::string EmployeeEmails::getEarnings(){
    calculateEarnings();

    std::stringstream aux;
    if (penalties != 0){
        aux << "Has hecho $" << earnings << ". Si tan solo hicieras tu trabajo bien :(";
    }else{
        aux << "Has hecho $" << earnings << ". YAY!";
    }
    return aux.str();

}

// Getters de las 3 hijas de Email

/**
 * Obtiene un PromoSpam en formato emailDraft con informacion adicional
 *
 * @param index
 * @return string: correo o "INEXISTENTE"
 */
std::string EmployeeEmails::getPromoSpam(int index){
    index -= 1;

    if (0 <= index && index <= promoSpamIndex){
        std::string tempString = promoSpamList[index].emailDraft();
        tempString += "\n\nEnviado por medio de " 
            + promoSpamList[index].getDelivery()
            + " con prioridad "
            + promoSpamList[index].getPriority();
        return tempString;
    }else{
        return "INEXISTENTE";
    };

}

/**
 * Obtiene un PurchaseConfirmation en formato emailDraft con informacion adicional
 *
 * @param index
 * @return string: correo o "INEXISTENTE"
 */
std::string EmployeeEmails::getPurchaseConfirmation(int index){
    index -= 1;
    
    if (0 <= index && index <= purchaseConfirmationIndex){
        std::string tempString = purchaseConfirmationList[index].emailDraft();
        tempString += "\n\nEnviado por medio de "
            + purchaseConfirmationList[index].getDelivery()
            + " con prioridad "
            + purchaseConfirmationList[index].getPriority()
            + "\nReembolsable: idk. Intente cambiarlo. Algo pasara.";
        return tempString;
    }else{
        return "INEXISTENTE";
    }

}

/**
 * Obtiene un Ticket en formato emailDraft con informacion adicional
 *
 * @param index
 * @return string: correo o "INEXISTENTE"
 */
std::string EmployeeEmails::getTicket(int index){
    index -= 1;

    if (0 <= index && index <= ticketIndex){
        std::string tempString = ticketList[index].emailDraft();
        tempString += "\n\nEnviado por medio de "
            + ticketList[index].getDelivery()
            + " con prioridad "
            + ticketList[index].getPriority();
        return tempString;
    }else{
        return "INEXISTENTE";
    }

}

/**
 * Getter del numero de PromoSpam creados
 *
 * @param
 * @return int: cantidad
 */
int EmployeeEmails::getPromoIndex(){
    return promoSpamIndex;
}

/**
 * Getter del numero de PurchaseConfirmations creados
 *
 * @param
 * @return int: cantidad
 */
int EmployeeEmails::getPurchaseIndex(){
    return purchaseConfirmationIndex;
}

/**
 * Getter del numero de Tickets creados
 *
 * @param
 * @return int: cantidad
 */
int EmployeeEmails::getTicketIndex(){
    return ticketIndex;    
}

/**
 * Devuelve la fecha y el receptor de un PromoSpam
 *
 * @param index
 * @return string: fecha y receptor o "INEXISTENTE"
 */
std::string EmployeeEmails::getRecieverDatePromo(int index){
    if (index < 0 || index >= promoSpamIndex)
        return "INEXISTENTE";
    return promoSpamList[index].getDate() + " " + promoSpamList[index].getReceiver();
}

/**
 * Devuelve la fecha y el receptor de un PurchaseConfirmation
 *
 * @param index
 * @return string: fecha y receptor o "INEXISTENTE"
 */
std::string EmployeeEmails::getRecieverDatePurchase(int index){
    if (index < 0 || index >= purchaseConfirmationIndex) {
        return "INEXISTENTE";
    }
    return purchaseConfirmationList[index].getDate() + " " + purchaseConfirmationList[index].getReceiver();
}

/**
 * Devuelve la fecha y el receptor de un Ticket
 *
 * @param index
 * @return string: fecha y receptor o "INEXISTENTE"
 */
std::string EmployeeEmails::getRecieverDateTicket(int index){
    if (index < 0 || index >= ticketIndex) {
        return "INEXISTENTE";
    }
    return ticketList[index].getDate() + " " + ticketList[index].getReceiver();
}

#endif
