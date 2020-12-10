#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdlib.h>
#include <string>
#include <vector>


class Word {
private:
    //std::string word;

    std::string fileName;
    std::string hint;
protected:
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
private:
    //std::vector<std::string> word;
    //should this be "word" instead of "sports"? apply this to the other classes :)

public:
    Sports() {
        word = {"soccer", "basketball", "cricket", "tennis", "boxing", "hockey", "volleyball",
                "golf", "badminton", "baseball", "football", "rugby", "wrestling"};
    }

    void addWord() override {
        std::string input;
        std::cout << "Word to add to sports: ";
        std::cin >> input;
        word.push_back(input);
    }
};

class Music : public Word {
private:
    //std::vector<std::string> word;

public:
    Music() {
        word = {"jazz", "pop", "rap", "rock", "classical", "reggae", "hiphop", "blues"};
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

    std::string getPositions(int pos) const {
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
    while (!select) {
        try {
            std::cout << "Please Choose a word category: \n1: Sport Names \n2: Music Genres \n3: Food\n Enter Selection: ";
            std::cin >> selection;
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
            default : //Optional
                throw 'e';
            }
        } catch(...) {
            std::cout << "Please enter a valid input." << std::endl;
        }
    }

    //Selects random word from selected category list
    word = wordList[(rand() % wordList.size())];

    // This should be moved to a class so image can be redrawn by calling a function
    // I think specific lines can be overwritten https://codereview.stackexchange.com/a/186537/234023
    // This way previous views are not seen
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
            /*  "        _      _\n"
              "       (_)    | |\n"
              " __   ___  ___| |_ ___  _ __ _   _\n "
              "\\ \\ / / |/ __| __/ _ \\| '__| | | |\n"
              "  \\ V /| | (__| || (_) | |  | |_| |\n"
              "   \\_/ |_|\\___|\\__\\___/|_|  \\__,  |\n"
              "                              __/ |\n"
              "                              |___/ \n"
              */
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
