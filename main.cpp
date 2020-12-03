#include <iostream>
#include <vector>

class Word{
private:
    std::string word;
    std::string fileName;
    std::string hint;
public:
    void setWord(  std::string newWord){
        word = newWord;
    }
    std::string getWord(){
        return word;
    }
    void setFileName(  std::string newFile){
        fileName = newFile;
    }
    std::string getFile(){
        return fileName;
    }
    void setHint(  std::string newHint){
        hint = newHint;
    }
    std::string getHint(){
        return hint;
    }
};

class Sports: public Word{
public:
};
class Music: public Word{

};
class History: public Word{

};
class Player{
private:
    int lives;

public:
    Player(){
        lives =6;
    }
    void setLives(int reduction){
        lives -= reduction;
    }
    int getLives(){
        return lives;
    }
};

class ScoreBoard{
private:
    std::string hangman[7];
public:
    void setPositions(std::string *positions, int size){
        for (int i=0; i<= size-1; i++){
            hangman[i] = positions[i];
        }

    }
    std::string getPositions(int pos){
        return hangman[pos];
    }
};

int main() {
    // Todo: add while loop to guess words.

    // Example of Word from sports SubClass: Potential to add file with word list example;
    Word:Sports footBall;
    footBall.setWord("Penalty");
    footBall.setHint("Misconduct");
    std::cout<<"Word: "<< footBall.getWord()<<  "Hint: "<< footBall.getHint()<<std::endl;

    // Example of Player initial lives with overloaded constructor
    Player playerOne;

    // Hangman print screen
    std::cout<<playerOne.getLives()<<std::endl;
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
    };
    //Initializing  scoreboard class with ascii art
    ScoreBoard uno;
    uno.setPositions(positions,7);

    // Test print of ascii art
    for(int i=0; i<=6; i++){
        //std::cout<<uno.getPositions(6);
    }

    // Todo: Replace the following code with class calls.
    std::string word = "ass";
    std::string guess;
    std::cout<<"Enter a letter: ";
    std::cin>>(guess);
    //std::string guess = "s";

    int size =word.size();
    bool reduce = true;

    std::vector<char> l (3, '*');
    // Loop to compare word and player  guess, If the guess is correct will replace each * with the corresponding letters
    // If the guess is wrong, it will change the reduce bool to later reduce total lives
    for (int i=0; i<=size-1;i++){
        if (word[i] == guess[0]){
            l[i] = guess[0];
            reduce = false;

        }
        std::cout<<l[i];
    }

    if (reduce) {
        playerOne.setLives(1);
    }
    std::cout<<"\n"<<(6-playerOne.getLives());

    std::cout<<"\nWord: ";
    for (int i=0; i<=size-1;i++){
            std::cout<<l[i];
        }
    std::cout<<"\n"<<uno.getPositions(6-playerOne.getLives());
    return 0;
}
