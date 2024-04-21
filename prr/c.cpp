#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <ncurses.h>
#include "shape.h"
#include "class_shape.h"
#include "shape_decalage.h"

void displayFrame(list_shape &shapeList, shape &s, sf::RenderWindow &window)
{
    // Clear the window
    window.clear();

    // Drawing shape
    sf::Shape *sfmlShape = createShape(s.c, s.f);
    sfmlShape->setPosition(100, 100);
    window.draw(*sfmlShape);

    // Clean up memory
    delete sfmlShape;

    // Displaying other information
    // Example:
    sf::Font font;

    sf::Text text;
    text.setFont(font);
    text.setString("Press 'a' to add a shape to the right. Press 'l' to add a shape to the left. Press 'q' to exit.");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(10, 10);
    window.draw(text);

    // Displaying shapes from the list
    shapeList.display_shapes(); // Uncomment this line to display shapes from the list

    // Display everything on the window
    window.display();
}

// Rest of the code remains unchanged...

int main()
{
    list_shape shapeList;
    shape s;
    shapeList.insert_shape_left(Yellow, Diamond);
    shapeList.insert_shape_left(Red, Circle);
    shapeList.insert_shape_left(Yellow, Circle);
    shapeList.insert_shape_left(Blue, Square);
    shapeList.insert_shape_left(Blue, Diamond);
    shapeList.display_same_form();

    // s = generateRandomShape();

    char key;
    bool exitFlag = false;
    int a;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
    displayFrame(shapeList, s, window);

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.display();
    }
    return 0;
}
