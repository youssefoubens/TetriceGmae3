#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

class QuestionGenerator {
private:
    std::vector<std::pair<std::string, std::string>> triviaQuestions; // Pair of question and answer
    std::vector<std::vector<std::string>> options; // Vector to store options for each question
    int score;
    int correctIndex; // Index of the correct answer

public:
    QuestionGenerator() : score(0) {
        // Read questions and options from files
        readQuestionsAndOptionsFromFile("..//prr//questions.txt", "..//prr//options.txt");
    }

    void readQuestionsAndOptionsFromFile(const std::string& questionsFilename, const std::string& optionsFilename) {
        // Read questions from file
        std::ifstream questionsFile(questionsFilename);
        if (!questionsFile.is_open()) {
            std::cerr << "Error opening file: " << questionsFilename << std::endl;
            return;
        }

        std::string line;
        while (std::getline(questionsFile, line)) {
            std::istringstream iss(line);
            std::string question, answer;
            if (std::getline(iss, question, ',') && std::getline(iss, answer)) {
                triviaQuestions.push_back(std::make_pair(question, answer));
            }
        }
        questionsFile.close();

        // Read options from file
        std::ifstream optionsFile(optionsFilename);
        if (!optionsFile.is_open()) {
            std::cerr << "Error opening file: " << optionsFilename << std::endl;
            return;
        }

        while (std::getline(optionsFile, line)) {
            std::istringstream iss(line);
            std::vector<std::string> questionOptions;
            std::string option;
            while (std::getline(iss, option, ',')) {
                questionOptions.push_back(option);
            }
            options.push_back(questionOptions);
        }
        optionsFile.close();
    }

    void generateQuestion() {
        // Randomly select a question
        srand(time(0));
        int randomIndex = rand() % triviaQuestions.size();
        std::string correctAnswer = triviaQuestions[randomIndex].second;

        // Set question text to be displayed
        questionText.setString(triviaQuestions[randomIndex].first);

        // Set options text to be displayed
        std::vector<std::string> questionOptions = options[randomIndex];
        optionsTexts.clear();
        for (size_t i = 0; i < questionOptions.size(); ++i) {
            sf::Text optionText;
            optionText.setFont(font);
            optionText.setCharacterSize(24);
            optionText.setFillColor(sf::Color::Black);
            optionText.setString(std::to_string(i + 1) + ". " + questionOptions[i]);
            //std::cout<<questionOptions[i];
            optionText.setPosition(50, 100 + i * 50);
            optionsTexts.push_back(optionText);
            if (questionOptions[i] == correctAnswer) {
                correctIndex = i;
            }
        }
        std::cout<<"hellow";
    }

    bool checkAnswer(int selectedIndex) {
        return selectedIndex == correctIndex;
    }

    sf::Text questionText; // Moved here to access it from main
    std::vector<sf::Text> optionsTexts; // Vector to store sf::Text objects for options
    sf::Font font; // Font object
};

