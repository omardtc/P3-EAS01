#include "Rectangle.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using namespace sf;
using namespace std;

int main()
{
    // setup
    RenderWindow window(VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(60);
    Rectangle rect(Vector2f(30,30));

    // loop
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            /** (5pts)
                Cuando se de click izquierdo, se deberá actualizar el objetivo del cuadrado a la posición del mouse.
            */
            if (event.type == Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == Mouse::Left)
                {
                    Vector2i click = Mouse::getPosition(window);
                    rect.setObjective(Vector2f (click));
                    
                }
            }

        }

        window.clear();
        rect.update();
        rect.drawTo(window);
        window.display();
    }

    return 0;
}
