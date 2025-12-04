
// Bibliotecas
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "employeeEmails.h"

// Menu de Login
void loginMenu(){
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "Login:\n";
    std::cout << "1. Ingresar nombre.\n";
    std::cout << "2. Ingresar comision por email.\n";
    std::cout << "3. Continuar.\n";
    std::cout << "4. Salir.\n";
}

// Menu principal
void menu(EmployeeEmails user){
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "Bienvenido, " + user.getEmployeeName() + ".\n";
    std::cout << "1. Crear email. \n";
    std::cout << "2. Consultar email. \n";
    std::cout << "3. Modificar email. \n";
    std::cout << "4. Calcular ganancias. \n";
    std::cout << "5. Salir. \n";
}

// Menu de creacion de email
void emailCreatorMenu(){
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "Menu:\n";
    std::cout << "1. Crear email promocional.\n";
    std::cout << "2. Crear email de confirmacion de pago.\n";
    std::cout << "3. Crear email de tickets.\n";
    std::cout << "4. Regresar.\n";
}

// Menu de consultar email
void emailConsultorMenu(){
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "Menu:\n";
    std::cout << "1. Consultar email promocional.\n";
    std::cout << "2. Consultar email de confirmacion de pago.\n";
    std::cout << "3. Consultar email de tickets.\n";
    std::cout << "4. Regresar \n";
}

// Email de modificar Email
void emailModifierMenu(){
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "Menu:\n\n";
    std::cout << "1. Cambiar descuento en un email promocional.\n";
    std::cout << "2. Cambiar estatus de refund.\n";
    std::cout << "3. Cambiar estatus de boletos.\n";
    std::cout << "4. Cambiar prioridad de email.\n";
    std::cout << "5. Regresar. \n";
}

// Submenu de modificar prioridades
void priorityModifierMenu(){
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "Cambiar prioridad en:\n";
    std::cout << "1. Email promocional.\n";
    std::cout << "2. Email de comfirmacion de pago.\n";
    std::cout << "3. Email de tickets.\n";
    std::cout << "4. Regresar.\n";
}

// standarCreator
void standarCreator(std::string &r, short &h, short &d, short &m, short &y){
    std::cout << "Ingresa email receptor: ";
    std::cin >> r;
    
    do{
       std::cout << "Ingresa hora (24 horas): ";
       std::cin >> h; 
    }while (0 > h || h > 24);

    do{
       std::cout << "Ingresa dia (1-30): ";
       std::cin >> d; 
    }while (1 > d || d > 30);

    do{
       std::cout << "Ingresa mes (1-12): ";
       std::cin >> m; 
    }while (1 > m || m > 12);

    do{
        std::cout << "Ingresa un ano: ";
        std::cin >> y; 
    }while (y < 0);
}

void TrueFalse(){
    std::cout << "Permitir refunds: ";
    std::cout << "1 - Chi. ";
    std::cout << "2 - No.";
}

int main() {
    int optionLoginMenu;
    int optionMainMenu;
    int optionMailCreatorMenu;
    int optionMailConsultorMenu;
    int optionMailModifierMenu;
    int optionPriorityMenu;

    std::string buffer;

    // Menu de Login
    loginMenu();

    std::string name = "Undefined User";
    float comission = 1.0;

    std::cout << "\nElige una opcion: ";
    std::cin >> optionLoginMenu;

    while ((name == "Undefined User" || comission == 1.0) || optionLoginMenu != 3) {
        switch(optionLoginMenu){
            case 1:
                std::cout << "Ingresa tu nombre: ";
                std::cin >> name;
                break;
            case 2:
                std::cout << "Ingresa tu comision por correo: ";
                std::cin >> comission;
                break;
            case 3:
                std::cout << "Rellena tu informacion antes de continuar." << std::endl;
                break;
            case 4:
                exit(0); 
            default:
                std::cout << "Opcion invalida." << std::endl;
                break;
        }
        std::cout << "\nElige una opcion: ";
        std::cin >> optionLoginMenu;
    }

    // Construct user object
    EmployeeEmails userEmails(name, comission);

    // Menu Principal
    while (optionMainMenu != 5) {
        menu(userEmails);

        std::cout << "\nElige una opcion: ";
        std::cin >> optionMainMenu;

        switch(optionMainMenu){
        case 1:
            do{
                emailCreatorMenu();
                short hour, day, month, year = 0;
                std::string receiver = "";

                std::string codigo;
                float monto;
                std::string ID;
                std::string artist;
                std::string concert;
                std::string ticketCode;
                
                std::cout << "\nElige una opcion: ";
                std::cin >> optionMailCreatorMenu;

                switch(optionMailCreatorMenu){
                    case 1:
                        standarCreator(receiver,hour, day, month, year);

                        std::cout << "\nIngresa codigo de promocion :";
                        std::cin >> codigo;

                        userEmails.createPromoSpam(codigo, receiver, hour, day, month, year);

                        std::cout << "Se creo con exito.\n\nRegresar." << std::endl;
                        std::cin >> buffer;
                        break;
                    case 2:
                        standarCreator(receiver,hour, day, month, year);

                        std::cout << "\nIngresa ID de la transaccion:";
                        std::cin >> ID;
                        std::cout << "\nIngresa monto de la transaccion:";
                        std::cin >> monto;

                        userEmails.createPurchaseConfirmation(monto, ID, receiver, hour, day, month, year);
                        
                        std::cout << "Se creo con exito.\n\nRegresar." << std::endl;
                        std::cin >> buffer;
                        break;
                    case 3:
                        standarCreator(receiver,hour, day, month, year);

                        std::cout << "\nIngresa artista del ticket:";
                        std::cin >> artist;
                        std::cout << "\nIngresa titulo del concierto:";
                        std::cin >> concert;
                        std::cout << "\nIngresa codigo del ticket:";
                        std::cin >> ticketCode;

                        userEmails.createTicket(concert, artist, ticketCode, receiver, hour, day, month, year);
                        
                        std::cout << "Se creo con exito.\n\nRegresar." << std::endl;
                        std::cin >> buffer;
                        break;
                    case 4:
                        break;
                    default:
                        std::cout << "Opcion invalida." << std::endl;
                        std::cin >> buffer;
                        break;
                }
            }while (optionMailCreatorMenu !=4);
            break;
        case 2:
            do{
                emailConsultorMenu();
                std::cout << "\nElige una opcion: ";
                std::cin >> optionMailConsultorMenu;
                
                int consultIndex;

                switch(optionMailConsultorMenu){
                    case 1:
                        for (int i = 0; i < userEmails.getPromoIndex(); i++){
                            std::cout << i + 1 << " .- " << userEmails.getRecieverDatePromo(i) << std::endl;
                        }

                        std::cout << "\nIndica email a consultar: ";
                        std::cin >> consultIndex;

                        std::cout << "\n\n" << userEmails.getPromoSpam(consultIndex) << "\n\n";

                        
                        std::cout << "\nRegresar.";
                        std::cin >> buffer;
                        break;
                    case 2:
                        for (int i = 0; i < userEmails.getPurchaseIndex(); i++){
                            std::cout << i + 1 << " .- " << userEmails.getRecieverDatePurchase(i) << std::endl;
                        }

                        std::cout << "\nIndica email a consultar: ";
                        std::cin >> consultIndex;

                        std::cout << "\n\n" << userEmails.getPurchaseConfirmation(consultIndex) << "\n\n";
                        
                        std::cout << "\nRegresar.";
                        std::cin >> buffer;
                        break;
                    case 3:
                        for (int i = 0; i < userEmails.getTicketIndex(); i++){
                            std::cout << i + 1 << " .- " << userEmails.getRecieverDateTicket(i) << std::endl;
                        }

                        std::cout << "\nIndica email a consultar: ";
                        std::cin >> consultIndex;

                        std::cout << "\n\n" << userEmails.getTicket(consultIndex) << "\n\n";

                        std::cout << "\nRegresar.";
                        std::cin >> buffer;
                        break;
                    case 4:
                        break;
                    default:
                        std::cout << "Opcion invalida." << std::endl;
                        std::cin >> buffer;
                        break;
                }
            }while (optionMailConsultorMenu !=4);
            break;
        case 3:
            do{
                emailModifierMenu();
                std::cout << "\nElige una opcion: ";
                std::cin >> optionMailModifierMenu;

                int modifierIndex;
                int discount;
                int choice;
                std::string priority;

                switch(optionMailModifierMenu){
                    case 1:
                        for (int i = 0; i < userEmails.getPromoIndex(); i++){
                            std::cout << i + 1 << " .- " << userEmails.getRecieverDatePromo(i) << std::endl;
                        }

                        std::cout << "\nIndica email a modificar: ";
                        std::cin >> modifierIndex;
                        std::cout << "\nIndica nuevo descuento: ";
                        std::cin >> discount;

                        userEmails.setSpamDiscount(modifierIndex, discount);
                        
                        std::cout << "Se modifico con exito.\n\nRegresar." << std::endl;
                        std::cin >> buffer;
                        break;
                    case 2:
                        for (int i = 0; i < userEmails.getPurchaseIndex(); i++){
                            std::cout << i + 1 << " .- " << userEmails.getRecieverDatePurchase(i) << std::endl;
                        }

                        std::cout << "\nIndica email a modificar: ";
                        std::cin >> modifierIndex;
                        TrueFalse();
                        std::cin >> choice;

                        switch(choice){
                            case 1:
                                userEmails.setRefundableStatus(modifierIndex,true);
                            case 2:
                                userEmails.setRefundableStatus(modifierIndex, false);
                            default:
                            std::cout << "Opcion invalida." << std::endl;
                        }
                        
                        std::cout << "Buena decision.\n\nRegresar." << std::endl;
                        std::cin >> buffer;
                        break;
                    case 3:
                        for (int i = 0; i < userEmails.getTicketIndex(); i++){
                            std::cout << i + 1 << " .- " << userEmails.getRecieverDateTicket(i) << std::endl;
                        }

                        std::cout << "\nIndica email a modificar: ";
                        std::cin >> modifierIndex;
                        TrueFalse();
                        std::cin >> choice;

                        switch(choice){
                            case 1:
                                userEmails.setValidStatus(modifierIndex,true);
                            case 2:
                                userEmails.setValidStatus(modifierIndex, false);
                            default:
                            std::cout << "Opcion invalida." << std::endl;
                        }
                        
                        std::cout << "Consecuencias aplicadas con exito.\n\nRegresar." << std::endl;
                        std::cin >> buffer;
                        break;
                    case 4:
                        do{
                            priorityModifierMenu();
                            std::cout << "\nElige una opcion: ";
                            std::cin >> optionPriorityMenu;

                            switch(optionPriorityMenu){
                                case 1:
                                    for (int i = 0; i < userEmails.getPromoIndex(); i++){
                                        std::cout << i + 1 << " .- " << userEmails.getRecieverDatePromo(i) << std::endl;
                                    }

                                    std::cout << "\nIndica email a modificar: ";
                                    std::cin >> modifierIndex;
                                    std::cout << "\nIndica nuevo descuento: ";
                                    std::cin >> priority;

                                    userEmails.setPriorityPromo(modifierIndex, priority);
                        
                                    std::cout << "Se modifico con exito.\n\nRegresar." << std::endl;
                                    std::cin >> buffer;
                                    break;
                                case 2:
                                    for (int i = 0; i < userEmails.getPurchaseIndex(); i++){
                                        std::cout << i + 1 << " .- " << userEmails.getRecieverDatePurchase(i) << std::endl;
                                    }

                                    std::cout << "\nIndica email a modificar: ";
                                    std::cin >> modifierIndex;
                                    std::cout << "\nIndica nuevo descuento: ";
                                    std::cin >> priority;

                                    userEmails.setPriorityPurchase(modifierIndex, priority);
                        
                                    std::cout << "Se modifico con exito.\n\nRegresar." << std::endl;
                                    std::cin >> buffer;
                                    break;
                                case 3:
                                   for (int i = 0; i < userEmails.getTicketIndex(); i++){
                                        std::cout << i + 1 << " .- " << userEmails.getRecieverDateTicket(i) << std::endl;
                                    }

                                    std::cout << "\nIndica email a modificar: ";
                                    std::cin >> modifierIndex;
                                    std::cout << "\nIndica nuevo descuento: ";

                                    userEmails.setPriorityTicket(modifierIndex);
                        
                                    std::cout << "Se modifico con exito.\n\nRegresar." << std::endl;
                                    std::cin >> buffer;
                                    break;
                                case 4:
                                    break;
                                default:
                                    std::cout << "Opcion invalida." << std::endl;
                                    std::cin >> buffer;
                                    break;
                            }
                        }while (optionPriorityMenu !=4);
                        break;
                    case 5:
                        break;
                    default:
                        std::cout << "Opcion invalida." << std::endl;
                        break;
                }
            }while (optionMailModifierMenu !=5);
            break;
        case 4:
            std::cout << userEmails.getEarnings();

            std::cout << "\nRegresar [Teclea cualquier cosa].";
            std::cin >> buffer;
            break;
        case 5:
            exit(0);
        default:
            std::cout << "Opcion invalida. ";
            std::cout << "\nRegresar [Teclea cualquier cosa].";
            std::cin >> buffer;
            break;
        }
    }
    return 0;
}
