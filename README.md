# Proyecto Teor铆a de la computaci贸n

## Integrantes:
Carlos Alonso Flores Panduro \
Gilver Alexis Raza Estrada \
Fernando Adriano Choqque Mej铆a

## Profesor:
Juan Gabriel Gutierrez Alva

# Busqueda en texto 馃殌

## Introducci贸n
En esta primera entrega presentaremos el avance de la monograf铆a final donde nos enfocamos 
en la resoluci贸n del problema Substring, aplicando  los conocimientos adquiridos referentes
a Aut贸matas (AFD y AFN).

## Definici贸n del problema
La primera situaci贸n se trata sobre la simulaci贸n de una b 虂usqueda en
texto, tenemos que evaluar si ciertas palabras se encuentran en el documento.
El primer problema es implementar un AFN. El segundo problema es resolver
el substring usando la adaptaci 虂on del BFS sobre un AFN. El tercer problema
es resolver el substring convirtiendo el AFN a AFD.

## Pseudoc贸digos de los algoritmos
### _Pregunta 1_

```
Input: Un alfabeto 危, una cadena s sobre 危 y un conunto de cadenas T sobre 危.
Result: 鈥漎ES鈥?, si el problema de substring devuelve verdadero, y 鈥漀O鈥?, en caso contrario.
Data: size, arrayString, estado Inicial, puntero Estado, estado Nuevo.

for i=0 hasta size do
|   Almacenar las transiciones iniciales en el estado Inicial;
|   Ubicar el puntero Estado en el estado siguiente respectivo;
|   for j=0 hasta el tama帽o de arrayString[i] do
|   |   El puntero Estado almacenar谩 la transici贸n del arrayString[i] en la posici贸n j;
|   |   Se crea estado Nuevo;
|   |   El siguiente estado que apuntara, puntero Estado, ser谩 al estado Nuevo;
|   |   El  puntero Estado tomara el valor del Estado Nuevo;
|   end
end
```

- El primer for recorre tantas veces como el n煤mero entero ingresado en el input.
- El estado inicial almacenar谩 todas las transciones iniciales.
- Para recorrer usamos un puntero que nos llevar谩 al estado siguiente a donde apunta. 
- A donde apunte depender谩 de las iteraciones de "i".

- El segundo for recorre de acuerdo al size del array string generado en el input.
- El puntero almacena la transici贸n del array string en la posici贸n "i" con "j". 
- Se generara un estado nuevo que permitir谩 intercambiar estados: entre el estado a donde apunta 
  puntero y el estado nuevo.
- Almacenamos y relacionamos entre s铆 cada estado nuevo, generando finalmente el AFN.


### _Pregunta 2_
```
Input: Un alfabeto 危, una cadena s sobre 危 y un conjunto decadenas T sobre 危.
Result: 鈥漎ES鈥?, si el problema de substring devuelve verdadero, y 鈥漀O鈥?, en caso contrario.
Data: stringSize, estados Finales, q, h, statesS, loop

En loop le damos valor true;
En q pusheamos 1;
for i=0 hasta stringSize do
|   for j=0 hasta tama帽o de q do
|   |   En h pusheamos el valor front de q;
|   |   Hacemos un pop a la q;
|   |   statesS almacenamos lo resultado al llamar a la funci贸n statelist;
|   |   for k=0 hasta tama帽o de statesS do
|   |   |   if statesS no es estado final then
|   |   |   |   En q pusheamos statesS[k];
|   |   |   end
|   |   end
|   |   En h hacemos pop;
|   end
|   
|   for l=0 hasta tama帽o de q do
|   |   for m=0 hasta tama帽o de transiciones do
|   |   |   if q es estado final then
|   |   |   |   imprime YES;
|   |   |   end
|   |   end
|   |   if loop es false
|   |   |   break;
|   |   end
|   end
|   if loop es false
|   |   break;
|   end
|   if stringSize-1 es igual a i
|   |   imprime NO;
|   end
end
```

- 


