#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class GameIntroduction {
private:
    sf::RenderWindow& window;
    std::vector<sf::Texture> introTextures;
    std::vector<sf::Sprite> introSprites;
    sf::Texture nextButtonTexture;
    sf::Sprite nextButtonSprite;
    sf::Texture prevButtonTexture;
    sf::Sprite prevButtonSprite;
    size_t currentIndex;

public:
    // Constructor with window parameter
    GameIntroduction(sf::RenderWindow& win) : window(win), currentIndex(0) {
        introTextures.resize(3); // Resize the vector to hold 3 elements

        // Load introduction images
        if (!introTextures[0].loadFromFile("C:\\Users\\youssef\\Desktop\\game_tetrice\\Tetrice\\goals.png")) {
            std::cerr << "Failed to load game goals image\n";
            // Handle image loading failure
        }

        if (!introTextures[1].loadFromFile("C:\\Users\\youssef\\Desktop\\game_tetrice\\Tetrice\\conditions.png")) {
            std::cerr << "Failed to load game conditions image\n";
            // Handle image loading failure
        }

        if (!introTextures[2].loadFromFile("C:\\Users\\youssef\\Desktop\\game_tetrice\\Tetrice\\instruction.png")) {
            std::cerr << "Failed to load game instructions image\n";
            // Handle image loading failure
        }

        // Load next button image
        if (!nextButtonTexture.loadFromFile("C:\\Users\\youssef\\Desktop\\game_tetrice\\Tetrice\\next.png")) {
            std::cerr << "Failed to load next button image\n";
            // Handle image loading failure
        }

        // Load previous button image
        if (!prevButtonTexture.loadFromFile("C:\\Users\\youssef\\Desktop\\game_tetrice\\Tetrice\\previous.png")) {
            std::cerr << "Failed to load previous button image\n";
            // Handle image loading failure
        }

        // Initialize sprites
        for (size_t i = 0; i < 3; ++i) {
            introSprites.push_back(sf::Sprite());
            introSprites[i].setTexture(introTextures[i]);
        }

        nextButtonSprite.setTexture(nextButtonTexture);
        nextButtonSprite.setPosition(500, 0);
        nextButtonSprite.scale(1.1f, 0.5f);
        prevButtonSprite.setTexture(prevButtonTexture);
        prevButtonSprite.setPosition(500,260);
        prevButtonSprite.scale(1.1f, 0.5f);
    }

    int run() {
        int i = 0;
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        // Check if the "Next" button is clicked
                        sf::FloatRect nextButtonBounds = nextButtonSprite.getGlobalBounds();
                        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                        if (nextButtonBounds.contains(mousePos)) {
                            // Move to the next image
                            currentIndex = (currentIndex + 1) % introSprites.size();
                            i++;
                        }
                        // Check if the "Previous" button is clicked
                        sf::FloatRect prevButtonBounds = prevButtonSprite.getGlobalBounds();
                        if (prevButtonBounds.contains(mousePos)) {
                            // Move to the previous image
                            currentIndex = (currentIndex == 0) ? introSprites.size() - 1 : currentIndex - 1;
                            i--;
                               if (!nextButtonTexture.loadFromFile("C:\\Users\\youssef\\Desktop\\game_tetrice\\Tetrice\\next.png")) {
            std::cerr << "Failed to load next button image\n";
            // Handle image loading failure
        }

                        }
                    }
                }
            }

            if (i < 0) {
                i = 0; // Ensure the index doesn't go below 0
            }
            if (i > 2) {
                return 0;
            }
            if(i==2)
            {
                 if (!nextButtonTexture.loadFromFile("C:\\Users\\youssef\\Desktop\\game_tetrice\\Tetrice\\play.png")) {
            std::cerr << "Failed to load next button image\n";
            // Handle image loading failure
               }

            }



            window.clear(sf::Color::White);
            window.draw(introSprites[currentIndex]);
            window.draw(nextButtonSprite);
            window.draw(prevButtonSprite);
            window.display();
        }
    }
};



