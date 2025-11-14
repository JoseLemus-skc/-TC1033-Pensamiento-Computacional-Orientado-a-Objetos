 -TC1033-Pensamiento-Computacional-Orientado-a-Objetos
# Administración de Instrumentos en Eventos.

## Problema.
Eres parte del Staff Technico durante un concierto. Es necesario saber las conexiones de los intrumentos que llegan al Stage-box y de ahí a la consola; para esto se tienen que categorizar por Tipo de instrumento (Percusivo, Strings, Viento y Teclados) y a partir de ello el instrumento especifico junto con su numero (ej. Strings -> Guitarra -> [Guitarra 1, Electrica, Linea 12]).

## Rol del programa.
Crear una clase por cada tipo de instrumento relevante y clases derivadas que indiquen el instrumento especifico junto con información relevante como el nombre del instrumento, nombre del instrumentista, linea de conexion, booleano microfono, booleano linea directa, booleano pre-amp booleano DI box. Deben haber metodos para preguntarle al usuario y permitir al usuario consultar los nombres del instrumento, del intrumentista, el numero de la linea de conexión en el Stage-box, si se trata de una instrumento microfoneado o no y que esto, cuando se registre, derive en la opción de indicar si (en caso de ser True) se hace uso de pre-amps o si es por linea directa o (en caso de ser False) de si se uso un DI box o si fue por linea directa.

## Acciones del usuario.
El usuario puede registrar y consultar la siguiente información:
- Nombre Instrumento
- Nombre Instrumentista
- No. Linea
- Microfono / No microfono
- Derivados: pre-amps/Linea directa y DI box/Linea directa (respectivamente)
