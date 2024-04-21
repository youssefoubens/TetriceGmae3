#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <SFML/Audio.hpp>
#include <iostream>

class Menu {
private:
    sf::RenderWindow& window;
    sf::Font font;


    sf::Texture texture;
    std::vector<sf::Text> menuItems;
    int selectedItemIndex = 0;
    bool isOpen = true;

public:
    Menu(sf::RenderWindow& win) : window(win) {}

    // Lo ad font
    bool loadFont(const std::string& fontPath) {
        if (!font.loadFromFile(fontPath)) {
            return false;
        }
        return true;
    }
     void settexture(sf::Texture texture)
    {
        Menu::texture = texture;
    }
    // Add menu item
    void addItem(const std::string& itemName, unsigned int fontSize, sf::Color color, sf::Vector2f position) {
        sf::Text item;
        item.setFont(font);

        item.setString(itemName);
        item.setCharacterSize(fontSize);
        item.setFillColor(color);
        item.setPosition(position);
        item.setOutlineColor(sf::Color::Black);
        item.setOutlineThickness(3);
        menuItems.push_back(item);

    }

    // Handle user input
    void handleInput() {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::KeyReleased:
                    if (event.key.code == sf::Keyboard::Up) {
                        moveUp();
                    } else if (event.key.code == sf::Keyboard::Down) {
                        moveDown();
                    } else if (event.key.code == sf::Keyboard::Return) {
                        isOpen = false;
                    }
                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }
    }

    // Move selection up
    void moveUp() {
        if (selectedItemIndex > 0) {
            menuItems[selectedItemIndex].setFillColor(sf::Color::White);
            selectedItemIndex--;
            menuItems[selectedItemIndex].setFillColor(sf::Color::Red);
        }
    }

    // Move selection down
    void moveDown() {
        if (selectedItemIndex < menuItems.size() - 1) {
            menuItems[selectedItemIndex].setFillColor(sf::Color::White);
            selectedItemIndex++;
            menuItems[selectedItemIndex].setFillColor(sf::Color::Red);
        }
    }

    // Draw menu
   void draw() {
        window.clear();
        // Draw the image
        sf::Sprite sprite(texture);
        sprite.setScale(0.53f, 0.5f);
        sprite.setPosition(0, 0);
        window.draw(sprite);

        for (const auto& item : menuItems) {
            window.draw(item);
        }
        window.display();
    }

    // Check if menu is open
    bool isOpenMenu() {
        return isOpen;
    }

    // Get selected item index
    int getSelectedItemIndex() const {
        return selectedItemIndex;
    }
};
