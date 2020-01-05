# EasingFunctions

![Capture](/capture.png?raw=true)

Este proyecto fue parte de un test para un trabajo. Es una aplicación para visualizar los distintas funciones de easing: https://easings.net/

----

This project was part of a test for a job. It's an application to visualize the different easing functions: https://easings.net/

# Compilación / Compiling

El proyecto lo probé en Visual Studio 2017, pero debería poder compilarse sin problemas con cualquier otro compilador o IDE.

----

I tested the project in Visual Studio 2017, but it should compile without issues in any compiler or IDE.

# Setup

El desarrollo es en C++ usando SDL2, así que hay que descargar SDL2 y configurar el proyecto con los paths a los include y las libs.

Una vez compilado el proyecto en Release o Debug hay que copiar las siguientes .dll junto al ejecutable:
* SDL2.dll
* SDL2_image.dll
* libpng16-16.dll

----

The application is writen in C++ using SDL2, so you mas download the SDL2 library and setup the proyect with the paths to the include and lib folders.

Once the project is compiled either in Release or Debug, you must copy the following .dlls to the same folder of the executable:
* SDL2.dll
* SDL2_image.dll
* libpng16-16.dll

# Uso / Usage

## Controles / Controls

Clic en la pantalla para hacer que el círculo blanco se mueva hasta ese punto. El movimiento es de acuerdo a la función de easing seleccionada.

Los botones de la izquierda son las distintas funciones.
Los botones del centro son el tipo de easing (in, out, o in-out).
A la derecha se grafica la función de easing actual.

Escape o clic en la X cierran la aplicación.

----

Clic anywhere on the screen to make the circle move to that point. The movement will be based on the easing function selected.

The buttons at the left are the different easing functions.
The buttons in the center are the easing type (in, out, o in-out).
At the right there's a plot showing the current easing function.

Pressing the escape key or clicking the X closes the application.
