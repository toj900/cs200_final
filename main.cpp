#include <iostream>


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
        for (int i=0; i<= size; i++){
            hangman[i] = positions[i];
        }

    }
    std::string getPositions(int pos){
        return hangman[pos];
    }
};

int main() {
    // Example of Word from sports SubClass: Potential to add file with word list example;
    Word:Sports footBall;
    footBall.setWord("Penalty");
    footBall.setHint("Misconduct");
    std::cout<<"Word: "<< footBall.getWord()<<  "Hint: "<< footBall.getHint()<<std::endl;

    // Example of Player initial lives with overloaded constructor
    Player playerOne;
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
            "|   |\n"
            "    |\n"
            "    |\n"
            "=========\n",
            " +---+\n"
            " |   |\n"
            " O   |\n"
            "/|   |\n"
            "     |\n"
            "     |\n",
            "=========\n"
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
    ScoreBoard uno;
    uno.setPositions(positions,6);

    for(int i=0; i<=5; i++){
        std::cout<<uno.getPositions(i);
    }
    return 0;
}
