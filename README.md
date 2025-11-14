 -TC1033-Pensamiento-Computacional-Orientado-a-Objetos
# Administración de Instrumentos en Eventos.

## Problema.
Eres parte del Staff Technico durante un concierto. Es necesario saber las conexiones de los intrumentos que llegan al Stage-box y de ahí a la consola; para esto se tienen que categorizar por Tipo de instrumento (Percusivo, Strings, Viento y Teclados) y a partir de ello el instrumento especifico. Igualmente se tiene que tomar inventario de los microfonos inalambricos en uso, tanto por instrumentos como para vocales y sus conexiones en los diferentes Racks. De ser necesario, tambien conocer los backing tracks utilizados y las caracteristicas del equipo de origen (por lo general siendo una Laptop perteneciente a algun instrumentista).

## Rol del programa.
Crear una clase por cada tipo de input relevante en la consola: Instrumento, Microfono, Backing Track. Crear una clase de instrumentos que indique el tipo de instrumento junto con información relevante como el instrumento, nombre del instrumentista, linea de conexion, booleano microfono, booleano linea directa, booleano pre-amp, booleano DI box. Deben haber metodos para preguntarle al usuario y permitir al usuario consultar los nombres del instrumento, del intrumentista, el numero de la linea de conexión en el Stage-box, si se trata de una instrumento microfoneado o no y que esto, cuando se registre, derive en la opción de indicar si (en caso de ser True) se hace uso de pre-amps o si es por linea directa o (en caso de ser False) de si se uso un DI box o si fue por linea directa. 
Crear una clase de microfonos inalambricos que indique el tipo de microfono, el uso del microfono, el rack al que pertenece, numero de input, el nombre de la persona que le este dando uso, cantidad bateria y booleano Live (On/Off). Deben haber metodos para preguntarle al usuario y permitir al usuario consultar que tipo de microfono es, cual es el uso del microfono, el rack que recibe su señal, el nombre de la persona que le este dando uso en ese momento, la cantidad bateria con la que cuenta al momento del registro y saber si esta prendido o no (en caso de no tener bateria, automaticamente se marca como "No prendido").
Crear una clase de Backing track que indique el titulo de la pista, su numero en la cola, duración de la pista, duración del count-in (clicks antes de iniciar la canción), duración total, nombre del equipo de origen y el nombre de persona quien lo va a manejar. Deben haber metodos para preguntarle al usuario y permitir al usuario consultar el titulo de la pista que sonará, su numero en la cola, su duración por si sola, la duración del count-in y la duración total resultante, nombre del equipo de origen y el nombre de persona quien lo va a manejar.

## Acciones del usuario.
El usuario puede registrar y consultar la siguiente información:
- Nombre Instrumento
- Nombre Instrumentista
- No. Linea
- Microfono / No microfono
- Derivados: pre-amps/Linea directa y DI box/Linea directa (respectivamente)

- Tipo de Microfono Inalambrico
- Uso del Microfono
- Rack receptor
- No. Input en el Rack
- Nombre Responsable
- Bateria
- Derivado: Turned On/Off

- Titulo pista
- No. Cola
- Duración
- Duración Count-in
- Duración Total
- Equipo de Origen
- Nombre Operador
