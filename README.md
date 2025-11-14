 -TC1033-Pensamiento-Computacional-Orientado-a-Objetos
# Administración de Instrumentos en Eventos.

## Problema.
Eres parte del Staff Técnico durante un concierto. Es necesario saber las conexiones de los instrumentos que llegan al Stage-box y de ahí a la consola; para esto se tienen que categorizar por tipo de instrumento (Percusivo, Strings, Viento y Teclados) y, a partir de ello, el instrumento específico. Igualmente, se tiene que tomar inventario de los micrófonos inalámbricos en uso, tanto por instrumentos como para vocales y sus conexiones en los diferentes racks. De ser necesario, también conocer los backing tracks utilizados y las características del equipo de origen (por lo general siendo una laptop perteneciente a algún instrumentista).

## Rol del programa.
Crear una clase por cada tipo de input relevante en la consola: Instrumento, Micrófono, Backing Track. Crear una clase de instrumentos que indique el tipo de instrumento junto con información relevante como el instrumento, nombre del instrumentista, línea de conexión, booleano micrófono, booleano línea directa, booleano pre-amp, booleano DI box. Deben haber métodos para preguntarle al usuario y permitir al usuario consultar los nombres del instrumento, del instrumentista, el número de la línea de conexión en el Stage-box, si se trata de un instrumento microfoneado o no y que esto, cuando se registre, derive en la opción de indicar si (en caso de ser True) se hace uso de pre-amps o si es por línea directa o (en caso de ser False) si se usó un DI box o si fue por línea directa.

Crear una clase de micrófonos inalámbricos que indique el tipo de micrófono, el uso del micrófono, el rack al que pertenece, número de input, el nombre de la persona que le esté dando uso, cantidad de batería y booleano Live (On/Off). Deben haber métodos para preguntarle al usuario y permitir al usuario consultar qué tipo de micrófono es, cuál es el uso del micrófono, el rack que recibe su señal, el nombre de la persona que le esté dando uso en ese momento, la cantidad de batería con la que cuenta al momento del registro y saber si está prendido o no (en caso de no tener batería, automáticamente se marca como "No prendido").

Crear una clase de Backing Track que indique el título de la pista, su número en la cola, duración de la pista, duración del count-in (clicks antes de iniciar la canción), duración total, nombre del equipo de origen y el nombre de la persona quien lo va a manejar. Deben haber métodos para preguntarle al usuario y permitir al usuario consultar el título de la pista que sonará, su número en la cola, su duración por sí sola, la duración del count-in y la duración total resultante, nombre del equipo de origen y el nombre de la persona quien lo va a manejar.

## Acciones del usuario.
El usuario puede registrar y consultar la siguiente información:
- Nombre Instrumento
- Nombre Instrumentista
- No. Línea
- Micrófono / No micrófono
- Derivados: pre-amps/Línea directa y DI box/Línea directa (respectivamente)


- Tipo de Micrófono Inalámbrico
- Uso del Micrófono
- Rack receptor
- No. Input en el Rack
- Nombre Responsable
- Batería
- Derivado: Turned On/Off


- Título pista
- No. Cola
- Duración
- Duración Count-in
- Duración Total
- Equipo de Origen
- Nombre Operador
