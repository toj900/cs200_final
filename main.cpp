#include <iostream>
#include <vector>
#include <algorithm>
/* Todo
 *  add class implementation for: std::string word = "astronomy";
 *  add definition to sport, Music, and History sub class
 *  clean up scoreboard appearance
 *  !BUG! 
 *
 */

class Word{

protected:
    std::string word;
    std::string hint;
    std::string category;
public:

    virtual void setCategory() =0;
    void setWord(std::string newWord) {
        word = newWord;
    }

    std::string getWord(){
        return word;
    }
    void setHint(std::string newHint) {

        hint = newHint;
    }

    std::string getHint() {
        return hint;
    }
};

class Sports : public Word {
private:
    std::string sport;
public:
    void setCategory() override;
    void setCategory(std::string category) {
        sport = category;
    }
    std::string getCategory() {
        return sport;
    }

};

class Music : public Word {

};

class History : public Word {

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

    int getLives() {
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
    // Todo: add while loop to guess words.

    // Example of Word from sports SubClass: Potential to add file with word list example;
    Word:
    Sports footBall;
    footBall.setWord("Penalty");
    footBall.setHint("Misconduct");
    //std::cout<<"Word: "<< footBall.getWord()<<  "Hint: "<< footBall.getHint()<<std::endl;

    // Example of Player initial lives with overloaded constructor
    Player playerOne;

    // Hangman print screen
    std::string positions[]{
            " +---+\n"
            " |   |\n"
            "     |\n"
            "     |\n"
            "     |\n"
            "     |\n"
            "=========\n",
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
    ScoreBoard uno;
    uno.setPositions(positions, 7);
    std::cout << "\n" << uno.getPositions(1);
    // Test print of ascii art

    for (int i = 0; i <= 6; i++) {
        std::cout<<uno.getPositions(i);
    }

    // Todo: Replace the following code with class calls.
    std::string word = "astronomy";
    std::string guess;



    int size = word.size();

    int count = 0;
    // Use of STL Container in the form of a vector
    std::vector<char> hiddenWord(size, '*');
    std::cout << "\n" << ("Word: ");
    //Example use of STL algorithm(s) <for_each> //Which replaces the following for loop
    auto print = [](const char &n) { std::cout << n; };
    // Example of use of STL iterator(s) //<vector>.cbegin and <vector>.cend
    std::for_each(hiddenWord.cbegin(), hiddenWord.cend(), print);

    std::cout << "\n" << uno.getPositions(6 - playerOne.getLives());
    while (playerOne.getLives() != 0) {
        bool reduce = true;

        std::for_each(hiddenWord.cbegin(), hiddenWord.cend(), print);

        std::cout << "\nEnter a letter: ";
        std::cin >> (guess);
        // Loop to compare word and player  guess, If the guess is correct will replace each * with the corresponding letters
        // If the guess is wrong, it will change the reduce bool to later reduce total lives
        for (int i = 0; i <= size - 1; i++) {
            if (word[i] == guess[0] &&hiddenWord[i]!=guess[0]) {
                hiddenWord[i] = guess[0];
                reduce = false;
                ++count;
            }
            //std::cout<<l[i];
        }
        std::for_each(hiddenWord.cbegin(), hiddenWord.cend(), print);
        if (reduce) {
            playerOne.setLives(1);
        }
        count = 0;
        for (int i = 0; i <= size - 1; i++) {
            if (hiddenWord[i] != '*'){
                count++;
            }
            if (count == size){
                int end =0,reduct =0;
                reduct = (-1*(playerOne.getLives()-6));
                end = 6 - reduct;
                //std::cout<<"end: "<<end;
                playerOne.setLives(end);

            }
        }
        std::cout << "\n" << uno.getPositions(6 - playerOne.getLives());
    }

    return 0;
}
