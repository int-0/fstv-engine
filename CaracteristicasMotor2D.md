# Especificaciones del motor 2D #

Esta página describe las características generales del motor 2D del juego. Esto permitirá crear gráficos para el juego de una forma unificada y funcional.

El espacio de color de todos los gráficos que maneja el motor es **RGBA** de 16 bits.

El formato de imagen que podrá cargar el motor es **PNG**.

## Escenarios ##

La resolución de la pantalla es de **1024x768**. Esta será la dimensión del escenario. No debería contar con zonas semitransparentes puesto que el motor no dibujará nada _por debajo_. Las capas de dibujado serán las siguientes (en orden de _renderizado_):

  1. Fondo
  1. Items Power-ups
  1. Enemigos
  1. Personajes
  1. Balas / Escudos / Opciones
  1. Cuadros / Texto OSD

El _area de juego_ será el mismo para todos los escenarios. Así mismo, todos los escenarios contarán con cuatro puertas que podrán abrirse/cerrarse según se desee.

Para unificar los escenarios sería recomendable elaborar una _plantilla vacía_ de escenario. A partir de esta plantilla se crea la lógica del motor y se crean todos los escenarios que se deseen.

## Enemigos/personajes ##

Gráficamente tendrán las mismas características. Para cada enemigo/personaje se deben crear las animaciones de andar en cinco direcciones: arriba, diagonal arriba-derecha, derecha, diagonal abajo-derecha y abajo. Las otras tres direcciones se crearán automáticamente a partir de los fotogramas reflejados verticalmente.

Todos los fotogramas de un personaje deberán tener el mismo tamaño. Es recomendable definir un tamaño de _frame_ para cada personaje y utilizar plantillas sin color de fondo para todos sus _frames_.

Todas las animaciones de los personajes serán _loops_, es decir: cuando se alcance el final de una animación se volverá a dibujar el primer fotograma.

Debería crearse una animación de _stanby_ para cada jugador. Esta animación la ejecutarían los jugadores que llevan un rato sin moverse.

## Items / power-ups ##

Estos objetos son los que aparecerán por el escenario para que los pueda recoger un jugador. No serán animaciones, serán un gráfico fijo de cualquier tamaño.

## Opciones ##

Existen _items_ que consisten en la aparición de un escudo y cosas así al rededor del personaje. Este tipo de elementos gráficos se dibujan directamente encima del personaje, por lo que deberán ser _frames_ del mismo tamaño que el personaje y en su mayoría de _pixels_ transparentes. Estos gráficos también pueden ser _loops_.