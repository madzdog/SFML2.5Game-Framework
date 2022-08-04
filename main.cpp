/* Project Template for C++ with SFML 2.5.1 Library 
* This template uses sfml-graphics libararies to enable the RenderWindow class
* 
* https://www.sfml-dev.org/learn.php
* The SFML dll files must be copied into the Release and/or the Debug executable folder:
* C:\Users\mgmye\source\repos\SFML2.5GameWindow\x64\Debug
* sfml-audio-d-2.dll
* sfml-graphics-d-2.dll
* sfml-network-d-2.dll
* sfml-system-d-2.dll
* sfml-window-d-2.dll
* 
* 
* C:\Users\mgmye\source\repos\SFML2.5GameWindow\x64\Release
* sfml-audio-2.dll
* sfml-graphics-2.dll
* sfml-network-2.dll
* sfml-system-2.dll
* sfml-window-2.dll
* 
*  
* If you are using the sfml-audio module (regardless whether statically or 
* dynamically), you must also copy the DLL of the external library needed
* by it, which is openAL32.dll.
* 
*/



/* Opens a basic game window, with a game loop*/
#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.h"


int main()
{
    GameManager::start();

    return 0;
}





