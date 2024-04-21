#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>



class Level {
private:
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text text, text2, text3, text4, text5, text6, timerText;
    sf::RectangleShape frame1, frame2, frame3, frame4, frame5, frame6, frame7;
    sf::Texture texture;
    int levelNumber; // Added member to store the level number

    // Define any other member variables and functions here

public:
    Level(sf::RenderWindow& win, int level) : window(win), levelNumber(level) {}

    void initialize() {
        if (!texture.loadFromFile("C:\\Users\\youssef\\Desktop\\font\\téléchargement.png")) {
            std::cout << "Error loading texture" << std::endl;
        }

        if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
            std::cout << "Error loading font" << std::endl;
            std::exit(1);
        }

        timerText.setFont(font);
        timerText.setCharacterSize(24);
        timerText.setColor(sf::Color::Green);
        timerText.setStyle(sf::Text::Bold);
        timerText.setPosition(200, 10);

        // Initialize other variables and shapes here based on the levelNumber
        if (levelNumber == 1) {
            // Initialize for level 1
        } else if (levelNumber == 2) {
            // Initialize for level 2
        }
    }

    void run() {
        initialize();
        // Your run logic here
    }

    void introGame() {
        // Your intro game logic here
    }

    void start() {
        window.clear();
        // Your start logic here
    }

    int handleEvent(const sf::Event& event, bool b) {
        // Your handle event logic here
    }

    int handleLeftKeyPressed() {
        // Your handle left key pressed logic here
    }

    int handleRightKeyPressed() {
        // Your handle right key pressed logic here
    }

    // Define your other member functions here
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
    int selectedLevel = 1; // Change this to select different levels
    Level level(window, selectedLevel);
    level.run();
    return 0;
}
