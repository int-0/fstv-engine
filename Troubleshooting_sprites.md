Observando una imagen de mapeado de sprites del smashtv me di  cuenta de que las piernas y los el resto del cuerpo iban en partes diferentes, creo que esto lo hicieron por el tema de la jugabilidad que tenían el juego al poder desplazarnos por la pantalla manteniendo una dirección de disparo.
| ![http://fstv-engine.googlecode.com/files/images.jpeg](http://fstv-engine.googlecode.com/files/images.jpeg)  |
|:-------------------------------------------------------------------------------------------------------------|


Otro asunto relacionado con las animaciones de los sprites es la siguiente:
Para que no halla golpes ni discontinuidad al pasar de una animación del personaje correspondiente a una dirección, por ejemplo, diagonal arriba derecha a otra como derecha. Tendría que se pasar del sprite n°3 de diagonal arriba derecha al n°4 de horizontal derecha, sin empezar de nuevo la animación desde el fotograma uno. Se consigue así que el ciclo de animación de las piernas se respete y no parezca que va tropezando cada vez que pasa de una dirección a otra.

Un aspecto más, sería evitar el efecto patinaje del personaje.se conseguiría ajustando la velocidad de sprites por segundo (fps) en relación con la cantidad de espacio que se desplaza el personaje. A más desplazamiento más fps y viceversa. El efecto "patinaje" es nuestro enemigo ;)