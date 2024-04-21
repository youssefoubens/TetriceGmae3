#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <chrono>
#include <ctime>
#include "../prr/intro.h"
#include <iostream>
#include <cstdlib> // for std::rand()
#include "../prr/shape.h"
#include "../prr/class_shape.h"
#include "../prr/decalage.h"
#include <string.h>
#include <windows.h>
#include "../prr/menu.h"
#include <sstream>
#include "../prr/Question.h"

class Game {
private:
    int etat=2;
    int etat1=0;
     sf::Text buttonText;
     std::string q="",options1="",options2="",options3="",options4="";
     std::string op[5];
    QuestionGenerator questionGenerator;
    sf::Clock clock;
    sf::RenderWindow window;
    sf::Font font;
    int timerr;
     sf::Text op1[4];
    int level = 1;
    int failed = 2;
    int failed1 = 0;
    bool islevelfinish = false;
    sf::RectangleShape frame1, frame2, frame3, frame4, frame5, frame6, frame7,frame8,frame9,frame10;
    sf::Text text, text1, text2, text3, text4, text5, text6, text7;
    sf::Texture texture;
    sf::Texture texture2;
    sf::Texture texture3;
    sf::Text timerText;
    sf::Texture prevButtonTexture[4];
    sf::Sprite prevButtonSprite[4];
    bool isTimeUp = false;
    std::stringstream ss;
    list_shape shapeList;
    shape currentShape;
    bool isGameRunning = false;
    float po = 300;
    bool inMenu = true;
    //sf::Clock clock; // Add a clock for time tracking
    int timerLimit = 30;

public:
    Game() : window(sf::VideoMode(1000, 500), "Shapes", sf::Style::Titlebar | sf::Style::Close) {}

    void menu1() {
        Menu menu(window);
        menu.loadFont("C:\\Windows\\Fonts\\arial.ttf");
        menu.addItem("Start Game", 40, sf::Color::Red, sf::Vector2f(400.f, 200.f));
        menu.addItem("Choose Level", 40, sf::Color::White, sf::Vector2f(400.f, 255.f));
        menu.addItem("Exit", 40, sf::Color::White, sf::Vector2f(400.f, 320.f));
        sf::Texture texture1;
        if (!texture1.loadFromFile("C:\\Users\\youssef\\Desktop\\game_tetrice\\prr\\image.png")) {
        std::cerr << "Failed to load image!" << std::endl;
       }
       menu.settexture(texture1);

        while (menu.isOpenMenu()) {
            menu.handleInput();
            window.clear();  // Clear the window once per frame
            menu.draw();     // Draw the menu
        }

        int selectedItemIndex = menu.getSelectedItemIndex();
        switch (selectedItemIndex) {
            case 0:
                std::cout << "Starting the game..." << std::endl;
                inMenu = false;
                isGameRunning = true;
                break;
            case 1:
                std::cout << "Choosing level..." << std::endl;
                if (menu2() == 0) {
                    menu1();  // Restart the menu
                }
                inMenu = false;
                isGameRunning = true;
                break;
            case 2:
                std::cout << "Exiting the game..." << std::endl;
                window.close();
                break;
        }
    }

    int menu2() {
        Menu menu(window);
        menu.loadFont("C:\\Windows\\Fonts\\arial.ttf");

        menu.addItem("Level 1", 30, sf::Color::Red, sf::Vector2f(200.f, 200.f));
        menu.addItem("Level 2", 30, sf::Color::White, sf::Vector2f(200.f, 250.f));
        menu.addItem("Go Back", 30, sf::Color::White, sf::Vector2f(200.f, 300.f));
        sf::Texture texture1;
        if (!texture1.loadFromFile("C:\\Users\\youssef\\Desktop\\game_tetrice\\prr\\image.png")) {
        std::cerr << "Failed to load image!" << std::endl;

       }
       menu.settexture(texture1);
        while (menu.isOpenMenu()) {
            menu.handleInput();
            window.clear();  // Clear the window once per frame
            menu.draw();     // Draw the menu
        }

        int selectedItemIndex = menu.getSelectedItemIndex();
        switch (selectedItemIndex) {
            case 0:
                std::cout << "Level 1" << std::endl;
                inMenu = false;
                level = 1;
                break;
            case 1:
                std::cout << "Level 2" << std::endl;
                if (failed1 == 0) {
                    window.clear();
                    window.draw(frame6);
                    std::string fail = "you cannot play level 2\n\n try to win level 1";
                    text2.setCharacterSize(30.0f);
                    text2.setString(fail);
                    window.draw(text2);
                    window.display();
                    Sleep(2000);
                    return 0;
                } else {
                    inMenu = false;
                    level = 2;
                }
                break;
            case 2:
                std::cout << "Go back" << std::endl;
                return 0;
        }
    }


    int drawTimer(int timeRemaining) {
    window.clear();
        sf::Time elapsedTime = clock.restart(); // Get time elapsed since last restart
        timerLimit -= static_cast<int>(elapsedTime.asSeconds());
        std::cout<<"/"<<timerLimit<<"/";
    // Create text for displaying the timer
    std::string timerString = "Time: " + std::to_string(timeRemaining);
    sf::Text timerText(timerString, font, 24);
    timerText.setPosition(10, 10); // Adjust position as needed
    timerText.setFillColor(sf::Color::White); // Adjust color as needed
    window.draw(timerText);
}


    void game_plateau() {
        if (!texture.loadFromFile("C:\\Users\\youssef\\Desktop\\game_tetrice\\prr\\téléchargement.png")) {
            std::cout << "error";
        }
        if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) {
            // Font loading failed
            std::exit(1);
        }
             if (!texture2.loadFromFile("C:\\Users\\youssef\\Desktop\\game_tetrice\\prr\\congratulation (2).png")) {
        std::cerr << "Failed to load image!" << std::endl;
       }
            if (!texture3.loadFromFile("C:\\Users\\youssef\\Desktop\\game_tetrice\\prr\\congratulation (1).png")) {
        std::cerr << "Failed to load image!" << std::endl;
       }

              if (!prevButtonTexture[0].loadFromFile("C:\\Users\\youssef\\Desktop\\game_tetrice\\Tetrice\\get.png")) {
            std::cerr << "Failed to load previous button image\n";
            // Handle image loading failure
        }
              if (!prevButtonTexture[1].loadFromFile("C:\\Users\\youssef\\Desktop\\game_tetrice\\Tetrice\\correct.jpg")) {
            std::cerr << "Failed to load previous button image\n";
            // Handle image loading failure
        }
              if (!prevButtonTexture[2].loadFromFile("C:\\Users\\youssef\\Desktop\\game_tetrice\\Tetrice\\false.jpg")) {
            std::cerr << "Failed to load previous button image\n";
            // Handle image loading failure
        }
        questionGenerator.font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"); // Load font
        questionGenerator.questionText.setFont(questionGenerator.font);
        questionGenerator.questionText.setCharacterSize(24);
        questionGenerator.questionText.setFillColor(sf::Color::Black);
        questionGenerator.questionText.setPosition(50, 50);



        text.setFont(font);
        text.setPosition(0, 100);
        text.setCharacterSize(40);
        text.setColor(sf::Color::Red);
        text.setStyle(sf::Text::Bold);

        text2.setFont(font);
        text2.setPosition(250, 200);
        text2.setCharacterSize(24);
        text2.setColor(sf::Color::Red);
        text2.setStyle(sf::Text::Bold);

        text3.setFont(font);
        text3.setPosition(250, 200);
        text3.setCharacterSize(45);
        text3.setColor(sf::Color::Green);
        text3.setStyle(sf::Text::Bold);

        text4.setFont(font);
        text4.setPosition(0, 400);
        text4.setCharacterSize(45);
        text4.setColor(sf::Color::Black);
        text4.setStyle(sf::Text::Bold | sf::Text::Underlined);

        text5.setFont(font);
        text5.setPosition(0, 10);
        text5.setCharacterSize(45);
        text5.setColor(sf::Color::Red);
        text5.setStyle(sf::Text::Bold);

        text6.setFont(font);
        text6.setPosition(340, 350);
        text6.setCharacterSize(24);
        text6.setColor(sf::Color::Red);
        text6.setStyle(sf::Text::Bold);

        text7.setFont(font);
        text7.setPosition(335, 440);
        text7.setCharacterSize(30);
        text7.setColor(sf::Color::Red);
        text7.setStyle(sf::Text::Bold);

        for (int i = 0; i < 4; ++i) {
       if(i<3){
        prevButtonSprite[i].setTexture(prevButtonTexture[i]);
        prevButtonSprite[i].setPosition(180,350);
        prevButtonSprite[i].scale(0.3f, 0.5f);
       }

        op1[i].setFont(font);
        op1[i].setCharacterSize(35);
        op1[i].setFillColor(sf::Color::Black);
        op1[i].setStyle(sf::Text::Bold);
        if(i<2)
        op1[i].setPosition(335+i*300,400);
        else if(i==2)op1[i].setPosition(335,450);
        else op1[i].setPosition(635,450);
    }


        frame1.setSize(sf::Vector2f(1000, 150));
        frame1.setFillColor(sf::Color::White);
        frame1.setPosition(0, 200);

        frame2.setSize(sf::Vector2f(180, 200));
        frame2.setFillColor(sf::Color::Green);
        frame2.setPosition(0, 350);

        frame3.setSize(sf::Vector2f(1000, 2));
        frame3.setFillColor(sf::Color::Yellow);
        frame3.setPosition(0, 210);

        frame4.setSize(sf::Vector2f(1000, 200));
        frame4.setFillColor(sf::Color::Cyan);
        frame4.setPosition(330, 350);

        frame5.setSize(sf::Vector2f(600, 200));
        frame5.setFillColor(sf::Color::White);
        frame5.setPosition(200, 0);

        frame6.setSize(sf::Vector2f(200, 200));
        frame6.setFillColor(sf::Color::White);
        frame6.setPosition(0, 0);

        frame7.setSize(sf::Vector2f(1000, 2));
        frame7.setFillColor(sf::Color::Yellow);
        frame7.setPosition(0, 300);

        frame8.setSize(sf::Vector2f(600, 200));
        frame8.setFillColor(sf::Color::White);
        frame8.setPosition(200, 150);


    }

    void run() {
       GameIntroduction intro(window);

       intro.run();
       game_plateau();
        etiq1:
        std::cout << shapeList.insert_shape(Color::Blue, ShapeType::Diamond, true);
        std::cout << shapeList.insert_shape(Color::Green, ShapeType::Circle, false);
        std::cout << shapeList.insert_shape(Color::Red, ShapeType::Square, true);
        std::cout << shapeList.insert_shape(Color::Yellow, ShapeType::Triangle4, false);
        menu1();
        window.clear();

        isGameRunning == true;
        while (window.isOpen()) {

           sf::Event event;
            if (isGameRunning == true ) {
                start(0, 0, true);

                isGameRunning = false;
                std::cout << isGameRunning;
            }

            while (window.pollEvent(event)) {
            ////////////
             if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                        sf::FloatRect prevButtonBounds = prevButtonSprite[0].getGlobalBounds();
                        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                         sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    if (prevButtonBounds.contains(mousePos)) {
                        // Generate and display a random question
                           int i=0;
                           if(etat==2){
                            etat1=0;
                            questionGenerator.generateQuestion();
                            std::cout << "Question Text: " << questionGenerator.questionText.getString().toAnsiString() << std::endl;
                           for (const auto& optionText : questionGenerator.optionsTexts) {
                          std::cout << "Option Text: " << optionText.getString().toAnsiString() << std::endl;

                          op[i] =optionText.getString().toAnsiString();
                          i++;

                          }
                          q = questionGenerator.questionText.getString().toAnsiString();
                         start(0, 0, false);
                           }


                    }

                    for (int i = 0; i < 4; ++i) {
                        if (op1[i].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                             if (questionGenerator.checkAnswer(i)) {

                               etat=1;
                               shapeList.delete_shape();
                               start(0, 0, false);

                            } else {

                              etat=0;
                              start(0, 0, false);
                            }
                        }
                    }


                }
            }







            ///////////
                if (level == 1) {
                    handleEvent(event, 0);
                } else {
                    handleEvent(event, 1);
                }
            }
            //if(!window.pollEvent(event))
            //{

                //start(0, 0, false);
               // Sleep(1000);
            //}


            if (failed == 0) {
                break;
            } else if (failed == 1) {//if the player win
                break;
            }

        }

        failed = 2;
        shapeList.delete_all_shapes(&shapeList);
        inMenu = true;

        window.clear();
        goto etiq1;
    }



    int handleEvent(const sf::Event& event, bool b) {
        if (event.type == sf::Event::Closed)
            window.close();
        else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Left)
                handleLeftKeyPressed();
            else if (event.key.code == sf::Keyboard::Right)
                handleRightKeyPressed();
            else if (b == 0) {
                switch_color(&shapeList, event);
                switch_form(&shapeList, event);
                etat=2;
                etat1=1;
                start(true, b, false);
            }
        }
    }

    int handleLeftKeyPressed() {
        etat=2;
        etat1=1;
        start(true, 1, false);
        if (po > 64)
            po -= 64;
        else
            po += 64;
    }

    int handleRightKeyPressed() {
        etat=2;
        etat1=1;
        start(false, 1, false);
        if (shapeList.getsize() >= 10 && po > 64)
            po -= 64;
    }

    shape displayRandomShape(sf::RenderWindow& window, sf::RectangleShape& frame5, list_shape* l) {
         int random=std::rand() % 4;
         ShapeType shapeType ;
         Color color;
    switch(random) {
    case 0:color = Color::Blue;break;
    case 1:color = Color::Red;break;
    case 2:color = Color::Green;break;
    case 3:color = Color::Yellow;break;
    default:break;
}
    switch(random) {
    case 0:shapeType = ShapeType::Circle;break;
    case 1:shapeType = ShapeType::Diamond;break;
    case 2:shapeType = ShapeType::Square;break;
    case 3:shapeType= ShapeType::Triangle4;break;
    default:break;
}
        float xPos = frame5.getPosition().x + (frame5.getSize().x - 20.f) / 2.f;
        float yPos = frame5.getPosition().y + (frame5.getSize().y - 20.f) / 2.f;
        l->drawShape(window, color, shapeType, sf::Vector2f(xPos, yPos), 80.f);
        shape newShape;
        newShape.c = color;
        newShape.f = shapeType;
        return newShape;
    }

    int start(bool left, int a, bool st) {
        window.clear();

       // window.draw(buttonText);
        // drawTimer(timerLimit);
       // get_question();
        if (a == 1) {
            std::cout << shapeList.insert_shape(currentShape.c, currentShape.f, left);
        }
           shapeList.delete_three_same_linked();

        if (shapeList.getsize() == 0) {
            window.clear();
            window.draw(frame7);
            sf::Sprite sprite2(texture3);
            sprite2.setScale(0.53f, 0.5f);
            sprite2.setPosition(0, 0);
            window.draw(sprite2);
            std::string scoreString = std::to_string(shapeList.getscore());
            text3.setString(scoreString);
            window.draw(text3);
            failed1 = 1;
            failed = 1;
            window.display();
            Sleep(2000);
            window.clear();
            return 0;
        } else if (shapeList.getsize() == 15 ) {
            window.clear();
            shapeList.setscore(0);
            //timerLimit=30;
            window.draw(frame8);
            std::string fail = "oops!! you fail";
            text2.setString(fail);
            text2.setCharacterSize(50.0f);
            window.draw(text2);
            window.display();
            Sleep(2000);
            failed = 0;
            failed1 = 0;
            return 1;
        }

        window.draw(frame1);
        window.draw(frame2);
        window.draw(frame3);
        window.draw(frame4);
        window.draw(frame5);
        window.draw(frame6);
        window.draw(frame7);



        std::string text11 = "Shapes:\t";

        std::string size1 = std::to_string(shapeList.getsize());
        text.setString(text11 + size1);

        text4.setString("score:\n" + std::to_string(shapeList.getscore()));
        text6.setString(q);
        for (int i = 0; i < 4; ++i) {

        op1[i].setString(op[i]);

    }

        shapeList.display_shapes(window, po, 250, 0);

        if (st == true) {
            currentShape = displayRandomShape(window, frame5, &shapeList);
        }

        inMenu = true;

        if (a == 1) {
            currentShape = displayRandomShape(window, frame5, &shapeList);
        } else if (!st) {
            float xPos = frame5.getPosition().x + (frame5.getSize().x - 20.f) / 2.f;
            float yPos = frame5.getPosition().y + (frame5.getSize().y - 20.f) / 2.f;
            shapeList.drawShape(window, currentShape.c, currentShape.f, sf::Vector2f(xPos, yPos), 80.f);
        }
          if (level == 2) {
            std::string l = "level 2";
             text5.setString(l);
             text5.setCharacterSize(45);
             text5.setOutlineColor(sf::Color::Black);
             text5.setOutlineThickness(3);
            window.draw(text5);
        } else {

            std::string l1 = "level 1";
            text5.setString(l1);
            text5.setOutlineColor(sf::Color::Black);
            text5.setCharacterSize(45);
            text5.setOutlineThickness(3);
            window.draw(text5);

        }

        sf::Sprite sprite(texture);
        sprite.setScale(1.f, 1.35f);
        sprite.setPosition(800, 0);
        window.draw(sprite);
        window.draw(text);
        window.draw(text5);
        window.draw(text4);

        if(etat==2)
        {
            window.draw(prevButtonSprite[0]);
        }

        else if(etat==1){
                window.draw(prevButtonSprite[1]);

        }

        else{
                window.draw(prevButtonSprite[2]);
        }
        for (int i = 0; i < 4; ++i) {
            if((etat==1 || etat==0) || (etat1==1))
            {

                 op1[i].setString("");
                 text6.setString("");
            }
            window.draw(op1[i]);

        }
         window.draw(text6);
        window.display();
    }

void get_question()
{


     window.clear();
        window.draw(questionGenerator.questionText);
        for (const auto& optionText : questionGenerator.optionsTexts) {
            window.draw(optionText);
        }
}


};

int main() {
    Game *game=new Game;
    game->run();
    return 0;
}
