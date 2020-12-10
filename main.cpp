#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdlib.h>
#include <string>
#include <vector>


class Word {
protected:
    std::string fileName;
    std::string hint;
    std::vector<std::string> word;

public:
    void setWord(std::vector<std::string> newWord) {
        word = newWord;
    }

    std::vector<std::string> getWord() const {
        return word;
    }

    void setFileName(std::string newFile) {
        fileName = newFile;
    }

    void setHint(std::string newHint) {
        hint = newHint;
    }

    std::string getHint() const {
        return hint;
    }

    virtual void addWord() = 0;
};

class Sports : public Word {
public:
    Sports() {
        word = {"soccer", "basketball", "cricket", "tennis", "boxing", "hockey", "volleyball",
                "golf", "badminton", "baseball", "football", "wrestling"};
        //hints are in order in accordance to the words
        hint = {"eleven players per side", "my name is trey", "protect your sticks", "15, 30, 40, game!", "you can do it! don't give up",
                    "slippery boxing", "be careful of that spike!", "theres a lion in the woods!", "look at that birdie go", "how strong are you with that wooden pole?",
                        "help i'm running from 11 people at once", "don't wanna go stargazing today"};
    }

    void addWord() override {
        std::string input;
        std::cout << "Word to add to sports: ";
        std::cin >> input;
        word.push_back(input);
    }
};

class Music : public Word {
public:
    Music() {
        word = {"jazz", "pop", "rap", "rock", "classical", "reggae", "hiphop", "blues"};
        
        hint = {"sexy saxaphone", "coca-cola", "what is he saying?", "patricks house", "im so sophisticated", 
                "jama-rley", "sick beat man", "originated in the Deep South of the United States around the 1860s"};
    }

    void addWord() override {
        std::string input;
        std::cout << "Word to add to music: ";
        std::cin >> input;
        word.push_back(input);
    }
};

//I changed this from history to food because im terrible at guessing history, change it if u want
class Food : public Word {
private:
    //std::vector<std::string> word;

public:
    Food() {
        word = {"grape", "tomato", "cheese", "chocolate", "eggroll", "pizza", "ramen", "apple"};
        
        hint = {"power in numbers", "fruit or veggie?", "stinky!", "happy valentines day", "stop drop and ???", "easy bake oven", "naruto's favorite", "keeps the doctor away"};
    }

    void addWord() override {
        std::string input;
        std::cout << "Word to add to food: ";
        std::cin >> input;
        word.push_back(input);
    }
};

class Player {
private:
    int lives;

public:
    Player() {
        lives = 6;
    }

    void setLives(int reduction) {
        lives -= reduction;
    }

    int getLives() const {
        return lives;
    }
};

class ScoreBoard {
private:
    std::string hangman[7];

public:
    void setPositions(std::string *positions, int size) {
        for (int i = 0; i <= size - 1; i++) {
            hangman[i] = positions[i];
        }

    }

    std::string getPositions(int pos) {
        return hangman[pos];
    }
};

int main() {
    Sports *sports = new Sports;
    Food *food = new Food;
    Music *music = new Music;
    ScoreBoard scoreBoard;

    Player playerOne;

    std::vector<std::string> wordList;

    std::string word = "astronomy";

    std::string guess;
    std::string selection;
    // selection of catagory of word
    bool select = false;

    // Pointless error catching
    std::cout << "Please Choose a word category:\n1: Sport Names\n2: Music Genres\n3: Food\nq: Quit\n";
    while (!select) {
        std::cout << "Enter Selection: ";
        std::cin >> selection;
        try {
            switch (selection[0]) {
            case '1' :
                wordList = sports->getWord();
                select = true;
                break; //optional
            case '2' :
                wordList = music->getWord();
                select = true;
                break; //optional
            case '3' :
                wordList = food->getWord();
                select = true;
                break;
            case 'q' :
                return 0;
                break;
            default : //Optional
                throw 'i';
            }
        } catch(...) {
            std::cout << "\rPlease enter a valid input." << std::endl;
        }
    }

    //Selects random word from selected category list
    word = wordList[(rand() % wordList.size()-1)];

    // Hangman print screen

    std::string positions[]{
            " +---+\n"
            " |   |\n"
            "     |\n"
            "     |\n"
            "     |\n"
            "     |\n"
            "=========\n\n",
            "+---+\n"
            "|   |\n"
            "0   |\n"
            "    |\n"
            "    |\n"
            "    |\n"
            "=========\n",
            "+---+\n"
            "|   |\n"
            "0   |\n"
            "|   |\n"
            "    |\n"
            "    |\n"
            "=========\n",
            " +---+\n"
            " |   |\n"
            " O   |\n"
            "/|   |\n"
            "     |\n"
            "     |\n"
            "=========\n",
            " +---+\n"
            " |   |\n"
            " O   |\n"
            "/|\\  |\n"
            "     |\n"
            "     |\n"
            "=========\n",
            " +---+\n"
            " |   |\n"
            " O   |\n"
            "/|\\  |\n"
            "/    |\n"
            "     |\n"
            "=========\n",
            " +---+\n"
            " |   |\n"
            " O   |\n"
            "/|\\  |\n"
            "/ \\  |\n"
            "     |\n"
            "=========\n"
    };
    //Initializing  scoreboard class with ascii art

    scoreBoard.setPositions(positions, 7);
    // Test print of ascii art
    for (int i = 0; i <= 6; i++) {
        //std::cout<<scoreBoard.getPositions(i);
    }

    int size = word.size();
    int count = 0;
    // Use of STL Container in the form of a vector
    std::vector<char> hiddenWord(size, '*');

    //Example use of STL algorithm(s) <for_each> //Which replaces the following for loop
    auto print = [](const char &n) { std::cout << n; };

    // Example of use of STL iterator(s) //<vector>.cbegin and <vector>.cend
    std::cout << "\n" << ("The word you have to guess is : ");
    std::for_each(hiddenWord.cbegin(), hiddenWord.cend(), print);
    std::cout << "\n" << "There are " << hiddenWord.size() << " Letters in word" << std::endl;

    std::cout << "\n" << scoreBoard.getPositions(6 - playerOne.getLives());
    while (playerOne.getLives() != 0) {
        bool reduce = true;

        std::for_each(hiddenWord.cbegin(), hiddenWord.cend(), print);

        std::cout << "\nEnter a letter: ";
        std::cin >> (guess);
        // Loop to compare word and player  guess, If the guess is correct will replace each * with the corresponding letters
        // If the guess is wrong, it will change the reduce bool to later reduce total lives
        for (int i = 0; i <= size - 1; i++) {
            if (word[i] == guess[0] && hiddenWord[i] != guess[0]) {
                hiddenWord[i] = guess[0];
                reduce = false;
                ++count;
            }
            //std::cout<<l[i];
        }
        std::for_each(hiddenWord.cbegin(), hiddenWord.cend(), print);
        std::cout << "\n";
        if (reduce) {
            playerOne.setLives(1);
        }
        count = 0;
        for (int i = 0; i <= size - 1; i++) {
            if (hiddenWord[i] != '*') {
                count++;
            }
            if (count == size) {
                int end = 0, reduct = 0;
                reduct = (-1 * (playerOne.getLives() - 6));
                end = 6 - reduct;
                //std::cout<<"end: "<<end;
                playerOne.setLives(end);

            }
        }
        std::cout << "\n" << scoreBoard.getPositions(6 - playerOne.getLives());

    }

    return 0;
}
