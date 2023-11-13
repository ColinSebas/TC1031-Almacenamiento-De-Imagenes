# TC1031-Almacenamiento-De-Imagenes

Este proyecto busca generar un ordenamiento de objetos de tipo "imagen" en colecciones. Buscando emular algo 
similar a iCloud o flickr, en dónde una imagen tiene diferentes metadatos como la fecha en que fue tomada, 
el tamaño de la imagen, el formato, quien la tomo etc. 

## SICT0302B: Toma decisiones

### Selecciona y usa un algoritmo de ordenamiento adecuado para el problema 
Para este proyecto se utilizo una implementación de Bubble Sort, se eligió este ya que se debía de implementar
utilizando la lista ligada implementada, y este era una implementación no tan compleja con el manejo de apuntadores. 
Se realizo una sobrecarga de operadores para que se pudiera ordenar esta lista que almacena objetos de tipo imagen. 
Estos comparan la fecha en que esta fue tomada para hacer el ordenamiento. 

### Selecciona y usa una estructura lineal adecuada al problema
Implementé una lista ligada para poder almacenar los objetos de tipo imagen, en este caso las imagenes se "suben" al 
sistema en la manera en la que el usuario quiera, por lo que se pueden subir fotos con fechas muy lejanas o muy cercanas,
y con el algoritmo de ordenamiento estas se ordenarán con base en las fechas. Una imagen también puede ser borrada de 
la lista sin ningún problema. 

## SICT0301B: Evalúa los componentes

### Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa
Los casos de prueba se encuetran en el archivo main.cpp, en dónde se crean los objetos y se imprimen. Para la entrega
final se creará un archivo de prueba para todas las funciones auxiliares (sean utilizadas o no en el programa final). 

### Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes

**Lista de Imágenes**

- toString: O(n), se recorre toda la lista de inicio a fin para imprimir cada elemento.
- insert: O(1), siempre se introduce el nuevo elemento al principio de la lista.
- search: O(n), se hace un recorrido lineal de la lista para encontrar la imagen deseada.
- deleteFirst: O(1), se utiliza sólo para eliminar el primer elemento, y no hay un recorrido.
- deleteAt: O(n) ya que se realiza una búsqueda lineal hasta llegar a la posición deseada para eliminar.
- sort: O(n^2), esto debido a que se debe pasar tantas ves como pares de valores existan en la lista.

## SICT0303B: Implementa acciones científicas

### Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa
El programa tiene la opción de consultar las imágenes ordenadas mediante la función search y mediante la función toString 
de la lista, que permite accesar a la información de todos las imágenes en la lista. 

### Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa.
Las imágenes se crean con el archivo testOne.txt, las cuáles son leidas al inicio del programa para crear las imágenes. 

### Implementa mecanismos de escritura de archivos correctos y útiles dentro de un programa.
Las imágenes creadas se almacenarán en un archivo con el nombre que el usuario desee, simplemente debe de tener 
la extensión ".txt". La forma correcta de correr el ejecutable es:

    >> a.exe testOne.txt imagenes.txt

Siendo "a.exe" el nombre del archivo ejecutable, "testOne.txt" el nombre del archivo de lectura, y "imagenes.txt" 
el nombre del archivo de salida. 
  


## Segundo avance de proyecto 
Para este segundo avence, se incorporó un archivo de texto de entrada para poder crear varios objetos de 
manera más rápida, y ejemplificar el funcionamiento del programa. De igual manera se incorporó una lista 
ligada simple que almacena los diferentes años en los que existen fotografías. Aún falta poder incorporar
el algoritmo de ordenamiento también a la lista ligada. Este cambio se realizará para la última entrega. 

    Nota: para correr el archivo ejecutable con el texto se debe de poner primero el nombre del archivo ejecutable,
    seguido de un espacio, y luego el nombre del archivo de texto. 
      Ejemplo: a.exe pruebas.txt


