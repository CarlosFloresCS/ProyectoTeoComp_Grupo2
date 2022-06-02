# Proyecto Teoría de la computación

## Integrantes:
Carlos Alonso Flores Panduro \
Gilver Alexis Raza Estrada \
Fernando Adriano Choqque Mejía

## Profesor:
Juan Gabriel Gutierrez Alva

# Busqueda en texto 🚀

## Introducción
En esta primera entrega presentaremos el avance de la monografía final donde nos enfocamos 
en la resolución del problema Substring, aplicando  los conocimientos adquiridos referentes
a Autómatas (AFD y AFN).

## Definición del problema
La primera situación se trata sobre la simulación de una b ́usqueda en
texto, tenemos que evaluar si ciertas palabras se encuentran en el documento.
El primer problema es implementar un AFN. El segundo problema es resolver
el substring usando la adaptaci ́on del BFS sobre un AFN. El tercer problema
es resolver el substring convirtiendo el AFN a AFD.

## Pseudocódigos de los algoritmos
### _Pregunta 1_

```
Input: Un alfabeto Σ, una cadena s sobre Σ y un conunto de cadenas T sobre Σ.
Result: ”YES”, si el problema de substring devuelve verdadero, y ”NO”, en caso contrario.
Data: size, arrayString, estado Inicial, puntero Estado, estado Nuevo.

for i=0 hasta size do
|   Almacenar las transiciones iniciales en el estado Inicial;
|   Ubicar el puntero Estado en el estado siguiente respectivo;
|   for j=0 hasta el tamaño de arrayString[i] do
|   |   El puntero Estado almacenará la transición del arrayString[i] en la posición j;
|   |   Se crea estado Nuevo;
|   |   El siguiente estado que apuntara, puntero Estado, será al estado Nuevo;
|   |   El  puntero Estado tomara el valor del Estado Nuevo;
|   end
end
```

- El primer for recorre tantas veces como el número entero ingresado en el input.
- El estado inicial almacenará todas las transciones iniciales.
- Para recorrer usamos un puntero que nos llevará al estado siguiente a donde apunta. 
- A donde apunte dependerá de las iteraciones de "i".

- El segundo for recorre de acuerdo al size del array string generado en el input.
- El puntero almacena la transición del array string en la posición "i" con "j". 
- Se generara un estado nuevo que permitirá intercambiar estados: entre el estado a donde apunta 
  puntero y el estado nuevo.
- Almacenamos y relacionamos entre sí cada estado nuevo, generando finalmente el AFN.


### _Pregunta 2_
```
Input: Un alfabeto Σ, una cadena s sobre Σ y un conjunto decadenas T sobre Σ.
Result: ”YES”, si el problema de substring devuelve verdadero, y ”NO”, en caso contrario.
Data: stringSize, estados Finales, q, h, statesS, loop

En loop le damos valor true;
En q pusheamos 1;
for i=0 hasta stringSize do
|   for j=0 hasta tamaño de q do
|   |   En h pusheamos el valor front de q;
|   |   Hacemos un pop a la q;
|   |   statesS almacenamos lo resultado al llamar a la función statelist;
|   |   for k=0 hasta tamaño de statesS do
|   |   |   if statesS no es estado final then
|   |   |   |   En q pusheamos statesS[k];
|   |   |   end
|   |   end
|   |   En h hacemos pop;
|   end
|   
|   for l=0 hasta tamaño de q do
|   |   for m=0 hasta tamaño de transiciones do
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


