 -TC1033-Pensamiento-Computacional-Orientado-a-Objetos
# Gestor de emails para TicketMaster®.

## Problema.
Ticketmaster™ necesita una herramienta de software interna que permita a sus empleados generar correos electrónicos que, sin esfuerzo y de forma constante, hagan la vida de nuestros usuarios jodidamente miserable. Hemos observado que arruinar la experiencia del cliente manualmente requiere tiempo, energía y una pizca de voluntad. Tomar pasos para automatizar este proceso aumenta el sufrimiento generado per capita/empleado. Por es necesario el programa.

## Rol del programa. 
Crear una clase base llamada Email, a partir de la cual se derivarán todas las clases de correos relevantes para los clientes. Las clases hijas serán: Spam promocional, Confirmación de compras y Tickets. Cada una de estas clases deberá construirse utilizando la misma información esencial que gestiona la clase madre: Direccion de origen, Direccion receptora, asunto, cuerpo, hora de envio, prioridad y metodo de envio. Además de almacenar esta información, contar con metodos para rellenar y consultar esta informacion, imprimir un boceto del correo y cambiar su metodo de envio en caso de no apetecer un email y hacerle la vida mas dificil al cliente.

Crear una clase hija PromoSpam con los siguientes atributos: un promoCode y un discountPercent, el cual puede ser modificado tras crearse. Por defecto el discountPercent tendra un valos de -100 para obligar al cliente a pagar doble.

Crear una clase hija PurchaseConfirmation con los siguientes atributos: un moneySpent, orderID y un campo isRefundable que siempre será falso (igual, se puede intentar cambiarlo, pero te sacara del programa para recordar al usuario de que aquí no existen los reembolsos). También se manejará un valor cantidad de dinero pagado + servicios, donde “servicios” es 200% del monto original por motivos absolutamente injustificables.

Crear una clase hija Ticket con los siguientes atributos: el ticketCode, un campo isValid que por defecto sera falso y una funcion que cuando se cambie isValid cambiara el método de envío a “horse, fuck you” y la prioridad a "ninguna', porque los usuarios no merecen recibir sus boletos.

Todas las clases construiran sus propios cuerpos y asuntos a partir de un template con espacios que cambiaran de acuerdo se a los atributos del objeto.

Igualmente, crear una clase de fecha, que recibira hora, dia, mes y año para construir las diversas representaciones de una fecha segun los cuerpos y asuntos de las diversas clases.

Todo esto sera manejado a traves de la clase EmployeeEmails, la cual actua como el centro de operaciones. Esta clase organiza, almacena y gestiona múltiples los correos creados por los empleados, junto con su informacion, comision por correo, penalizaciones (por cambiar atributos y por ende atentar contra la mision del corporativo TicketMaster®) y sus ganacias.

## Acciones del usuario.
El usuario puede registrar y consultar la siguiente información en todas las clases hijas:
- Dirección de origen
- Dirección receptora
- Asunto
- Cuerpo
- Hora de envio
- Prioridad 
- Metodo de envio

El usuario puede registrar y consultar la siguiente información en PromoSpam:
- promoCode
- discountPercent

El usuario puede registrar y consultar la siguiente información en PurchaseConfirmation:
- moneySpent
- orderID
- isRefundable

El usuario puede registrar y consultar la siguiente información en Ticket:
- ticketCode
- isValid

El usuario puede registrar y consultar la siguiente información en Date:
- hora, dia, mes y año

- El usuario puede registrar y consultar la siguiente información en EmployeeEmails:
- Objeto de clase PromoSpam, PurchaseConfirmation y Ticket.
- Nombre del empleado
- Comision
- Total de ganancias
- Cantidad de correos creados por tipo
