/*
 * Proyecto Ticketmaster Email Gestioner
 * Jose Manuel Lemus Gomez
 * A01707194
 * 05/12/2025
*/



#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "EmployeeEmails.h"



// Menu de Login
void loginMenu(){
    
    // Limpia pantalla (Rudimentario pero evita problemas de compilacion)
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    // Opciones de registro
    std::cout << "Login:\n";
    std::cout << "1. Ingresar nombre.\n";
    std::cout << "2. Ingresar comision por email.\n";
    std::cout << "3. Continuar.\n";
    std::cout << "4. Salir.\n";
}



// Menu principal
void menu(EmployeeEmails& user){

    // Limpia pantalla 
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    // Opciones de acciones
    std::cout << "Bienvenido, " + user.getEmployeeName() + ".\n";
    std::cout << "1. Crear email. \n";
    std::cout << "2. Consultar email. \n";
    std::cout << "3. Modificar email. \n";
    std::cout << "4. Calcular ganancias. \n";
    std::cout << "5. Salir. \n";
}



// Menu para crear emails
void emailCreatorMenu(){

    // Limpia pantalla
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    // Opciones de tipo de email a crear
    std::cout << "Creacion de Emails:\n";
    std::cout << "1. Crear email promocional.\n";
    std::cout << "2. Crear email de confirmacion de pago.\n";
    std::cout << "3. Crear email de tickets.\n";
    std::cout << "4. Regresar.\n";
}



// Menu para consultar emails
void emailConsultorMenu(){

    // Limpia pantalla
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    // Opciones de tipo de email a consultar
    std::cout << "Consulta de emails:\n";
    std::cout << "1. Consultar email promocional.\n";
    std::cout << "2. Consultar email de confirmacion de pago.\n";
    std::cout << "3. Consultar email de tickets.\n";
    std::cout << "4. Regresar \n";
}



// Menu para modificar emails
void emailModifierMenu(){

    // Limpia pantalla
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    // Opciones de acciones a tomar
    std::cout << "Modificacion de emails:\n";
    std::cout << "1. Cambiar descuento en un email promocional.\n";
    std::cout << "2. Cambiar estatus de refund en una comfirmacion de compra.\n";
    std::cout << "3. Cambiar estatus de validez de tickets.\n";
    std::cout << "4. Cambiar prioridad de email.\n";
    std::cout << "5. Regresar. \n";
}



// Submenu para modificar prioridades
void priorityModifierMenu(){

    // Limpia pantalla
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    // Opciones de tipo de email a modificar
    std::cout << "Cambiar prioridad en:\n";
    std::cout << "1. Email promocional.\n";
    std::cout << "2. Email de comfirmacion de pago.\n";
    std::cout << "3. Email de tickets.\n";
    std::cout << "4. Regresar.\n";
}



// Creador estandar de fecha + receptor
void standarCreator(std::string &r, short &h, short &d, short &m, short &y){
    
    std::cout << "Ingresa email receptor: ";
    std::cin >> r;
    
    // Loops de validacion de datos (hora, dia, mes, año)
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






int main() {
    
    // Declaracion de opciones para cada menu
    int optionLoginMenu;
    int optionMainMenu;
    int optionMailCreatorMenu;
    int optionMailConsultorMenu;
    int optionMailModifierMenu;
    int optionPriorityMenu;

    // Variable dummy. Pausar programa esperando un input (Rudimentario pero evita problemas de compilacion)
    std::string dummyInput;



    // Login
    loginMenu();

    // Inicializacion de variables
    std::string name = "";
    float comission = 0;

    std::cout << "\nElige una opcion: ";
    std::cin >> optionLoginMenu;

    // Loop de verificador de datos para creacion de usuario
    while ((name == "" || comission == 0) || optionLoginMenu != 3) {
        switch(optionLoginMenu){

            case 1: // Nombre
                std::cout << "[Usa '_' en lugar de espacios]\nIngresa tu nombre: ";
                std::cin >> name;
                break;

            case 2: // Comision por correo
                std::cout << "Ingresa tu comision por correo: $";
                std::cin >> comission;
                break;

            case 3: // Continuar al siguiente menu
                std::cout << "Rellena tu informacion antes de continuar." << std::endl;
                break;

            case 4: // Salir del programa
                exit(0);

            default:
                std::cout << "Opcion invalida." << std::endl;
                break;

        }
        std::cout << "\nElige una opcion: ";
        std::cin >> optionLoginMenu;
    }



    //  Crear objeto EmployeeEmails asociado al usuario
    EmployeeEmails userEmails(name, comission);



    // Menu Principal
    while (optionMainMenu != 5) {
        menu(userEmails);

        std::cout << "\nElige una opcion: ";
        std::cin >> optionMainMenu;

        switch(optionMainMenu){



        // Menu de crear email
        case 1:
            
            // Menu loop 
            do{
                emailCreatorMenu();

                // Inicializacion de variables
                short hour, day, month, year = 0;
                std::string receiver = "";

                float monto;
                std::string codigo, ID, artist, concert, ticketCode;
                
                std::cout << "\nElige una opcion: ";
                std::cin >> optionMailCreatorMenu;

                switch(optionMailCreatorMenu){


                    // Crear Email promocional
                    case 1:

                        standarCreator(receiver,hour, day, month, year);

                        std::cout << "\nIngresa codigo de promocion: ";
                        std::cin >> codigo;

                        // Llamado de metodo constructor, en EmployeeEmails
                        userEmails.createPromoSpam(codigo, receiver, hour, day, month, year);

                        std::cout << "Se creo con exito.\n\nTabula un digito y presione Enter para Regresar." << std::endl;
                        std::cin >> dummyInput;
                        break;



                    // Crear Email de confirmacion de compra
                    case 2:

                        standarCreator(receiver,hour, day, month, year);

                        std::cout << "\nIngresa ID de la transaccion: ";
                        std::cin >> ID;
                        std::cout << "\nIngresa monto de la transaccion: ";
                        std::cin >> monto;

                        // Llamado de metodo constructor, en EmployeeEmails
                        userEmails.createPurchaseConfirmation(monto, ID, receiver, hour, day, month, year);
                        
                        std::cout << "Se creo con exito.\n\nTabula un digito y presione Enter para Regresar." << std::endl;
                        std::cin >> dummyInput;
                        break;



                    // Crear Email de ticket
                    case 3:

                        standarCreator(receiver,hour, day, month, year);

                        std::cout << "\n[Usa '_' en lugar de espacios] \nIngresa artista del ticket: ";
                        std::cin >> artist;
                        std::cout << "\nIngresa titulo del concierto: ";
                        std::cin >> concert;
                        std::cout << "\nIngresa codigo del ticket: ";
                        std::cin >> ticketCode;

                        // Llamado de metodo constructor, en EmployeeEmails
                        userEmails.createTicket(concert, artist, ticketCode, receiver, hour, day, month, year);
                        
                        std::cout << "Se creo con exito.\n\nTabula un digito y presione Enter para Regresar." << std::endl;
                        std::cin >> dummyInput;
                        break;



                    // Salir del loop del menu de creacion. Regresar a menu principal
                    case 4:
                        break;


                    
                    default:
                        std::cout << "Opcion invalida. \nTabula un digito y presione Enter para Regresar." << std::endl;
                        std::cin >> dummyInput;
                        break;
                }
            // Verificador del loop
            }while (optionMailCreatorMenu !=4);
            break;
        


        // Menu para consultar email
        case 2:

            // Loop de menu
            do{
                emailConsultorMenu();
                std::cout << "\nElige una opcion: ";
                std::cin >> optionMailConsultorMenu;
                
                int consultIndex;

                switch(optionMailConsultorMenu){



                    // Consultar Email promocional
                    case 1:
                        // Imprime lista de emails de este tipo creados (su posicion, recibidor y fecha)
                        for (int i = 0; i < userEmails.getPromoIndex(); i++){
                            std::cout << i + 1 << " .- " << userEmails.getRecieverDatePromo(i) << std::endl;
                        }

                        std::cout << "\nIndica email a consultar: ";
                        std::cin >> consultIndex;

                        std::cout << "\n\n" << userEmails.getPromoSpam(consultIndex) << "\n\n";

                        std::cout << "\nTabula un digito y presione Enter para Regresar.";
                        std::cin >> dummyInput;
                        break;



                    // Consultar Email de confirmacion de compra
                    case 2:
                        // Imprime lista de emails de este tipo creados
                        for (int i = 0; i < userEmails.getPurchaseIndex(); i++){
                            std::cout << i + 1 << " .- " << userEmails.getRecieverDatePurchase(i) << std::endl;
                        }

                        std::cout << "\nIndica email a consultar: ";
                        std::cin >> consultIndex;

                        std::cout << "\n\n" << userEmails.getPurchaseConfirmation(consultIndex) << "\n\n";
                        
                        std::cout << "\nTabula un digito y presione Enter para Regresar.";
                        std::cin >> dummyInput;
                        break;



                    // Consultar Email de Tickets
                    case 3:
                        // Imprime lista de emails de este tipo creados
                        for (int i = 0; i < userEmails.getTicketIndex(); i++){
                            std::cout << i + 1 << " .- " << userEmails.getRecieverDateTicket(i) << std::endl;
                        }

                        std::cout << "\nIndica email a consultar: ";
                        std::cin >> consultIndex;

                        std::cout << "\n\n" << userEmails.getTicket(consultIndex) << "\n\n";

                        std::cout << "\nTabula un digito y presione Enter para Regresar.";
                        std::cin >> dummyInput;
                        break;



                    // Salir del loop del menu de consulta. Regresar a menu principal
                    case 4:
                        break;



                    default:
                        std::cout << "Opcion invalida.\nTabula un digito y presione Enter para Regresar." << std::endl;
                        std::cin >> dummyInput;
                        break;
                }
            // Verificador del loop
            }while (optionMailConsultorMenu !=4);
            break;
        


        // Menu para modificar emails
        case 3:
            
            // Loop de menu
            do{
                emailModifierMenu();
                std::cout << "\nElige una opcion: ";
                std::cin >> optionMailModifierMenu;

                // Inicializacion de variables
                int modifierIndex, discount, choice;
                std::string priority;

                switch(optionMailModifierMenu){



                    // Modificar descuento de email promocional
                    case 1:
                        // Imprime lista de emails de este tipo creados     
                        for (int i = 0; i < userEmails.getPromoIndex(); i++){
                            std::cout << i + 1 << " .- " << userEmails.getRecieverDatePromo(i) << std::endl;
                        }

                        std::cout << "\nIndica email a modificar: ";
                        std::cin >> modifierIndex;
                        std::cout << "\nIndica nuevo descuento: ";
                        std::cin >> discount;

                        userEmails.setSpamDiscount(modifierIndex, discount);
                        
                        std::cout << "Se modifico con exito.\n\nRegresar." << std::endl;
                        std::cin >> dummyInput;
                        break;



                    // Modificar permiso de recibir refunds de un email de compra
                    case 2:
                        // Imprime lista de emails de este tipo creados
                        for (int i = 0; i < userEmails.getPurchaseIndex(); i++){
                            std::cout << i + 1 << " .- " << userEmails.getRecieverDatePurchase(i) << std::endl;
                        }

                        std::cout << "\nIndica email a modificar: ";
                        std::cin >> modifierIndex;


                        // Loop de menu de eleccion de booleano
                        do {
                            std::cout << "\nPermitir refunds: ";
                            std::cout << "1 - Chi. 2 - No." << std::endl;
                            std::cin >> choice;

                            switch(choice){

                                case 1: // Intencionalmente cierra el programa.
                                    userEmails.setRefundableStatus(modifierIndex, true);
                                    break;

                                case 2:
                                    userEmails.setRefundableStatus(modifierIndex, false);
                                    break;

                                default:
                                    std::cout << "Opcion invalida. Intenta de nuevo.\n";
                                    break;

                            }
                        // Verificador del loop
                        }while (choice != 1 && choice != 2);

                        
                        std::cout << "Buena decision.\n\nRegresar." << std::endl;
                        std::cin >> dummyInput;
                        break;



                    // Modificar validez de un Ticket
                    case 3:
                        // Imprime lista de emails de este tipo creados
                        for (int i = 0; i < userEmails.getTicketIndex(); i++){
                            std::cout << i + 1 << " .- " << userEmails.getRecieverDateTicket(i) << std::endl;
                        }

                        std::cout << "\nIndica email a modificar: ";
                        std::cin >> modifierIndex;


                        // Loop de menu de eleccion de booleano
                        do {
                            std::cout << "Es el Ticket valido?";
                            std::cout << "1 - Chi. 2 - No." << std::endl;
                            std::cin >> choice;

                            switch(choice){

                                case 1:
                                    userEmails.setValidStatus(modifierIndex, true);
                                    break;

                                case 2:
                                    userEmails.setValidStatus(modifierIndex, false);
                                    break;

                                default:
                                    std::cout << "Opcion invalida. Intenta de nuevo.\n";
                                    break;

                            }
                        // Verificador del loop
                        }while (choice != 1 && choice != 2);

                        
                        std::cout << "Consecuencias aplicadas con exito.\n\nRegresar." << std::endl;
                        std::cin >> dummyInput;
                        break;



                    // Modificar prioridad de un email
                    case 4:

                        // Loop del menu para modificar prioridades
                        do{
                            priorityModifierMenu();
                            std::cout << "\nElige una opcion: ";
                            std::cin >> optionPriorityMenu;

                            switch(optionPriorityMenu){



                                // Modificar prioridad de email promocional
                                case 1:
                                    for (int i = 0; i < userEmails.getPromoIndex(); i++){
                                        std::cout << i + 1 << " .- " << userEmails.getRecieverDatePromo(i) << std::endl;
                                    }

                                    std::cout << "\nIndica email a modificar: ";
                                    std::cin >> modifierIndex;
                                    std::cout << "\nIndica nuevo prioridad: ";
                                    std::cin >> priority;

                                    userEmails.setPriorityPromo(modifierIndex, priority);
                        
                                    std::cout << "Se modifico con exito.\n\nabula un digito y presione Enter para Regresar." << std::endl;
                                    std::cin >> dummyInput;
                                    break;



                                // Modificar prioridad de email de confirmacion de compra
                                case 2:
                                    for (int i = 0; i < userEmails.getPurchaseIndex(); i++){
                                        std::cout << i + 1 << " .- " << userEmails.getRecieverDatePurchase(i) << std::endl;
                                    }

                                    std::cout << "\nIndica email a modificar: ";
                                    std::cin >> modifierIndex;
                                    std::cout << "\nIndica nuevo prioridad: ";
                                    std::cin >> priority;

                                    userEmails.setPriorityPurchase(modifierIndex, priority);
                        
                                    std::cout << "Se modifico con exito.\n\nTabula un digito y presione Enter para Regresar." << std::endl;
                                    std::cin >> dummyInput;
                                    break;



                                // Modificar prioridad de email con ticket
                                case 3:
                                   for (int i = 0; i < userEmails.getTicketIndex(); i++){
                                        std::cout << i + 1 << " .- " << userEmails.getRecieverDateTicket(i) << std::endl;
                                    }

                                    std::cout << "\nIndica email a modificar: ";
                                    std::cin >> modifierIndex;
                                    std::cout << "Indica nuevo prioridad: ";
                                    std::cin >> priority;

                                    userEmails.setPriorityTicket(modifierIndex, priority);
                        
                                    std::cout << "Se modifico con exito.\n\nRegresar." << std::endl;
                                    std::cin >> dummyInput;
                                    break;



                                // Salir del loop del menu de prioridades. Volver a menu de modificacion
                                case 4:
                                    break;



                                default:
                                    std::cout << "Opcion invalida. \nTabula un digito y presione Enter para Regresar." << std::endl;
                                    std::cin >> dummyInput;
                                    break;
                            }
                        }while (optionPriorityMenu !=4);
                        break;
                    

                    
                    //Salir del loop del menu de modificacion. Volver a menu principal
                    case 5:
                        break;


    
                    default:
                        std::cout << "Opcion invalida. \nTabula un digito y presione Enter para Regresar." << std::endl;
                        break;
                }
            }while (optionMailModifierMenu !=5);
            break;



        // Calcular ganancias
        case 4:
            std::cout << userEmails.getEarnings();

            std::cout << "\nTabula un digito y presione Enter para Regresar.";
            std::cin >> dummyInput;
            break;


        // Terminar programa
        case 5:
            exit(0);


    
        default:
            std::cout << "Opcion invalida. \nTabula un digito y presione Enter para Regresar.";
            std::cin >> dummyInput;
            break;
        }
    }
    return 0;
}

