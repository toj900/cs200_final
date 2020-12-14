#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdlib.h>
#include <vector>
#include <ctime>

class Word {
protected:
    std::string fileName;
    std::vector<std::string> hint;
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

    void setHint(std::vector<std::string> newHint) {
        hint = newHint;
    }

    std::vector<std::string> getHint() const {
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
        std::cout<<word.at(12);
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

    Player* operator-=(const int& amount) {
        lives -= amount;
        return this;
    }
};

class ScoreBoard {
private:
    std::string hangman[8];

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

    std::vector<Word*> words = {new Sports,new Music, new Food };

    ScoreBoard scoreBoard;

    Player playerOne;

    std::vector<std::string> wordList, hintList;

    std::string word,hint, addWord;
    std::string guess, selection;

    // selection of catagory of word
    bool select = false;
    int random;
    // Pointless error catching
    std::cout << "Please Choose a word category:\n1: Sport Names\n2: Music Genres\n3: Food\nq: Quit\n";
    while (!select) {
        std::cout << "Enter Selection: ";
        std::cin >> selection;
        try {
            switch (selection[0]) {
            case '1' :
                //wordList = sports->getWord();
                wordList = words[0]->getWord();
                hintList = words[0]->getHint();
                select = true;
                break; //optional
            case '2' :
                wordList = words[1]->getWord();
                hintList = words[1]->getHint();
                select = true;
                break; //optional
            case '3' :
                wordList = words[2]->getWord();
                hintList = words[2]->getHint();
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
    srand(time(NULL));
    random = (rand() % wordList.size());

    word = wordList[random];
    hint = hintList[random];

    std::string positions[] {
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
            "=========\n",
            "        _      _\n"
            "       (_)    | |\n"
            " __   ___  ___| |_ ___  _ __ _   _\n "
            "\\ \\ / / |/ __| __/ _ \\| '__| | | |\n"
            "  \\ V /| | (__| || (_) | |  | |_| |\n"
            "   \\_/ |_|\\___|\\__\\___/|_|  \\__,  |\n"
            "                              __/ |\n"
            "                              |___/ \n"

    };
    //Initializing  scoreboard class with ascii art

    scoreBoard.setPositions(positions, 8);
    // Test print of ascii art
    for (int i = 0; i <= 6; i++) {
        //std::cout<<scoreBoard.getPositions(i);
    }

    int size = word.size();
    int count = 0;
    // Use of STL Container in the form of a vector
    std::vector<char> hiddenWord(size, '*');

    std::vector<char>::iterator z;
    //Example use of STL algorithm(s) <for_each> //Which replaces the following for loop



    auto print = [](const char &n) { std::cout << n; };

    //Example use of STL algorithm(s) <for_each> //Which replaces the following for loop
    std::cout << "\n" << ("The word you have to guess is : ");
    std::for_each(hiddenWord.cbegin(), hiddenWord.cend(), print);
    std::cout << "\n" << "There are " << hiddenWord.size() << " Letters in word" << std::endl;
    bool win = false;
    std::cout << "\n" << scoreBoard.getPositions(6 - playerOne.getLives());
    int lives = playerOne.getLives();
    while (lives != 0 ) {
        bool reduce = true;

        std::for_each(hiddenWord.cbegin(), hiddenWord.cend(), print);

        std::cout << "\nEnter a letter or \"1\" for a hint: ";
        std::cin >> (guess);
        guess[0] = tolower(guess[0]);
        // Loop to compare word and player guess, If the guess is correct will replace each * with the corresponding letters
        // If the guess is wrong, it will change the reduce bool to later reduce total lives

        for (int i = 0; i <= size - 1; i++) {
            if (word[i] == guess[0] && hiddenWord[i] != guess[0]) {
                hiddenWord[i] = guess[0];
                reduce = false;
                ++count;
            }
            //std::cout<<l[i];
        }
        if (guess[0] == '1'){
            reduce = false;
            std::cout << "hint: "<< hint << std::endl;
        }
        std::for_each(hiddenWord.cbegin(), hiddenWord.cend(), print);
        std::cout << "\n";
        if (reduce) {
            playerOne.operator-=(1);
        }
        count = 0;
        //Example use of Iterator

        for (z = hiddenWord.begin();z<hiddenWord.end();z++){
            if (*z != '*') {
                count++;
            }
            if (count == size) {
                int end = 0, reduct = 0;
                reduct = (-1 * (playerOne.getLives() - 6));
                end = 6 - reduct;
                playerOne.operator-=(end);
                win = true;
                std::cout << "\n" << scoreBoard.getPositions(7);

            }
        }
        //Example of for loop without iterator
        /*
        for (int i = 0; i <= size - 1; i++) {
            if (hiddenWord[i] != '*') {
                count++;
            }
            if (count == size) {
                int end = 0, reduct = 0;
                reduct = (-1 * (playerOne.getLives() - 6));
                end = 6 - reduct;
                playerOne.setLives(end);
                win = true;
                std::cout << "\n" << scoreBoard.getPositions(7);

            }
        }
         */
        int set =0;
        set = (playerOne.getLives());
        if (!win) {
            std::cout << "\n" << scoreBoard.getPositions(6 - set);
        }
        lives = playerOne.getLives();
    }

    std::cout<<"Your word was: "<<word<<std::endl;
    for( int i = 0 ; i < words.size(); i++)
        delete words[i];
    words.clear();

    return 0;
}
