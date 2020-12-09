#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


class Word{
private:
    std::string word;
    std::string fileName;
    std::string hint;
public:
    void setWord(  std::string newWord) {
        word = newWord;
    }

    std::string getWord() {
        return word;
    }
    void setFileName(  std::string newFile) {
        fileName = newFile;
    }

    void setHint(  std::string newHint) {
        hint = newHint;
    }
    std::string getHint() {
        return hint;
    }
};

class Sports: public Word {
private:
    string sports = ["soccer", "basketball", "cricket", "tennis", "boxing", "hockey", "volleyball",
                        "golf", "badminton", "baseball", "football", "rugby", "wrestling"];
    //should this be "word" instead of "sports"? apply this to the other classes :)
public:
    
};
class Music: public Word {
private:
    string music = ["jazz", "pop", "rap", "rock", "classical", "reggae", "hiphop", "blues"];
public:
    
};
//I changed this from history to food because im terrible at guessing history, change it if u want
class Food: public Word {
private:
    string food = ["grape", "tomato", "cheese", "chocolate", "eggroll", "pizza", "ramen", "apple"];
public:

    
};
class Player{
private:
    int lives;

public:
    Player() {
        lives =6;
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
        for (int i=0; i<= size-1; i++) {
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
    Word:Sports footBall;
    footBall.setWord("Penalty");
    footBall.setHint("Misconduct");
    //std::cout<<"Word: "<< footBall.getWord()<<  "Hint: "<< footBall.getHint()<<std::endl;

    // Example of Player initial lives with overloaded constructor
    Player playerOne;

    // Hangman print screen
    std::string positions[] {
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
    };
    //Initializing  scoreboard class with ascii art
    ScoreBoard uno;
    uno.setPositions(positions,7);

    // Test print of ascii art
    for(int i = 0; i <= 6; i++) {
        //std::cout<<uno.getPositions(6);
    }

    // Todo: Replace the following code with class calls.
    std::string word = "ass";
    std::string guess;



    int size =word.size();
    bool reduce = true;

    // Use of STL Container in the form of a vector
    std::vector<char> l (size, '*');

    std::cout << "\n" << ("Word: ");
    //Example use of STL algorithm(s) <for_each> //Which replaces the following for loop
    auto print = [](const char& n) { std::cout << n; };
    // Example of use of STL iterator(s) //<vector>.cbegin and <vector>.cend
    std::for_each(l.cbegin(), l.cend(), print);

    std::cout << "\nEnter a letter: ";
    std::cin >> (guess);
    // Loop to compare word and player  guess, If the guess is correct will replace each * with the corresponding letters
    // If the guess is wrong, it will change the reduce bool to later reduce total lives
    for (int i = 0; i <= size-1; i++){
        if (word[i] == guess[0]){
            l[i] = guess[0];
            reduce = false;

        }
        //std::cout<<l[i];
    }
    std::for_each(l.cbegin(), l.cend(), print);
    if (reduce) {
        playerOne.setLives(1);
    }



    /*
    std::cout<<"\nWord: ";
    for (int i=0; i<=size-1;i++){
            std::cout<<l[i];
        }
    */

    std::cout << "\n" << uno.getPositions(6-playerOne.getLives());
    return 0;
}
