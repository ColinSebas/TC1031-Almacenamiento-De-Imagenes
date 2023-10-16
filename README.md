# TC1031-Almacenamiento-De-Imagenes

Este proyecto busca generar un ordenamiento de objetos de tipo "imagen" en colecciones. Buscando emular algo 
similar a iCloud o flickr, en dónde una imagen tiene diferentes metadatos como la fecha en que fue tomada, 
el tamaño de la imagen, el formato, quien la tomo etc. 

## Selecciona un algoritmo de ordenamiento adecuado al problema
Para este proyecto se utilizo la librería estándar de C++, utilizando std::sort para hacer el ordenamiento
de las imágenes en base a la fecha. Se realizo una sobrecarga de operadores para que se pudiera ordenar un 
vector que almacena objetos de tipo imagen, en dónde checa el año, luego el mes y luego el día para tomar 
el orden de ordenamiento. 

## Segundo avance de proyecto 
Para este segundo avence, se incorporó un archivo de texto de entrada para poder crear varios objetos de 
manera más rápida, y ejemplificar el funcionamiento del programa. De igual manera se incorporó una lista 
ligada simple que almacena los diferentes años en los que existen fotografías. Aún falta poder incorporar
el algoritmo de ordenamiento también a la lista ligada. Este cambio se realizará para la última entrega. 

    Nota: para correr el archivo ejecutable con el texto se debe de poner primero el nombre del archivo ejecutable,
    seguido de un espacio, y luego el nombre del archivo de texto. 
      Ejemplo: a.exe pruebas.txt


