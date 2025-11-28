#include <iostream>
#include <string>
#include "email.h"
#include "promospam.h"
#include "purchaseconfirmation.h"
#include "tickets.h"

int main() {
    int opcion;
    bool offButton = true;

    std::cout << "1) Crear PromoSpam\n";
    std::cout << "2) Crear Confirmacion Compra\n";
    std::cout << "3) Crear Tickets\n";
    std::cout << "Opcion: ";
    std::cin >> opcion;

    if (opcion == 1) {
        std::string code, receiver, time;
        std::cout << "Codigo promocional: ";
        std::cin >> code;

        std::cout << "Direccion de correo a enviar: ";
        std::cin >> receiver;

        std::cout << "Fecha: ";
        std::cin >> time;

        PromoSpam spam(code, receiver, time);
        std::cout << spam.emailDraft() << "\n";
        
        std::cout << "Cerrar " << opcion << "?" ;
        std::cin >> offButton;
    }

    else if (opcion == 2) {
        float money;
        std::string orderID, receiver, time;

        std::cout << "Dinero gastado: ";
        std::cin >> money;

        std::cout << "Numero de la orden: ";
        std::cin >> orderID;

        std::cout << "Direccion de correo a enviar: ";
        std::cin >> receiver;

        std::cout << "Fecha: ";
        std::cin >> time;

        PurchaseConfirmation confirmacion(money, orderID, receiver, time);
        std::cout << confirmacion.emailDraft() << "\n";

        std::cout << "Cerrar " << opcion << "?" ;
        std::cin >> offButton;
    }

    else if (opcion == 3) {
        std::string concert, artist, code, receiver, time;

        std::cout << "Concierto: ";
        std::cin >> concert;

        std::cout << "Artista: ";
        std::cin >> artist;

        std::cout << "Codigo del ticket: ";
        std::cin >> code;

        std::cout << "Direccion de correo a enviar: ";
        std::cin >> receiver;

        std::cout << "Fecha: ";
        std::cin >> time;

        Tickets boletos(concert, artist, code, receiver, time);
        std::cout << boletos.emailDraft() << "\n";

        std::cout << "Cerrar " << opcion << "?" ;
        std::cin >> offButton;
    }

    else {
        std::cout << "Opcion invalida.\n";
    }

    return 0;
}
