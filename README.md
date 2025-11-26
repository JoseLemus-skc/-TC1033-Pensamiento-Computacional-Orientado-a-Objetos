 -TC1033-Pensamiento-Computacional-Orientado-a-Objetos
# Creador de emails para TicketMaster®.

## Problema.
Ticketmaster™ necesita una herramienta de software interna que permita a sus empleados generar correos electrónicos que, sin esfuerzo y de forma constante, hagan la vida de nuestros usuarios jodidamente miserable. Hemos observado que arruinar la experiencia del cliente manualmente requiere tiempo, energía y una pizca de voluntad. Tomar pasos para automatizar este proceso aumenta el sufrimiento generado per capita/empleado. Por es necesario el programa.

## Rol del programa. 
Crear una clase base llamada Email, a partir de la cual se derivarán todas las clases de correos relevantes para los clientes. Las clases hijas serán: Spam promocional, Confirmación de compras, Recordatorio de conciertos y Tickets. Cada una de estas clases deberá construirse utilizando la misma información esencial que gestiona la clase madre: Direccion de origen, Direccion receptora, asunto, cuerpo, hora a enviar, prioridad (importante, normal, spam) y metodo de envio. Además de almacenar esta información, contar con metodos para rellenar y consultar esta informacion, imprimir un boceto del correo, determinar a qué directorio del usuario debe enviarse según la prioridad asignada y cambiar su metodo de envio en caso de no apetecer un email.

Crear una clase hija PromoSpam con los siguientes atributos: un promoCode, un discountPercent aleatorio y un campo isUnsubscribeFunctional que siempre será false (se puede introducir otro valor booleano, aunque no se le asignara al atributo porque no existe la menor intención de permitir que el usuario deje de recibir estas cosas).

Crear una clase hija PurchaseConfirmation con los siguientes atributos: un moneySpent, orderID y un campo isRefundable que siempre será falso (igual, se puede intentar cambiarlo, pero regresará a falso como recordatorio al usuario de que aquí no existen los reembolsos). También se manejará un valor cantidad de dinero pagado + servicios, donde “servicios” es 200% del monto original por motivos absolutamente injustificables.

Crear una clase hija ConcertReminder con los siguientes atributos: concertName, venue, concertDate y un campo venueMap vacío. La fecha del concierto se ajustará automáticamente a la fecha que se enviara el correo. Si se intenta colocar cualquier cosa dentro del venueMap, el programa dará un error, porque quien intente hacer la experiencia del usuario lo más mínimo agradable merece un recordatorio de la política de la empresa.

Crear una clase hija Ticket con los siguientes atributos: el ticketCode, un contador attempts que incrementará cada vez que el usuario intente cambiar el metodo de envio del correo (cuando esto ocurra, tambien el método de envío a “horse, fuck you”), un campo isValid que presentará una posibilidad de 50/50 entre verdadero y falso.

## Acciones del usuario.
El usuario puede registrar y consultar la siguiente información en todas las clases hijas:
- Dirección de origen
- Dirección receptora
- Asunto
- Cuerpo
- Hora a enviar // Excepcion de ConcertReminder
- Prioridad 
- Metodo de envio // Solo consultar


El usuario puede registrar y consultar la siguiente información en PromoSpam:
- promoCode
- discountPercent // Solo consultar
- isUnsubscribeFunctional // En practica solo consultar

El usuario puede registrar y consultar la siguiente información en PurchaseConfirmation:
- moneySpent
- orderID
- isRefundable // En practica solo consultar

El usuario puede registrar y consultar la siguiente información en ConcertReminder:
- concertName
- venue
- concertDate
- venueMap // En practica solo consultar

El usuario puede registrar y consultar la siguiente información en Ticket:
- ticketCode
- isValid // 50 / 50
- attempts // Aumenta en 1 al intentar modificar la prioridad
