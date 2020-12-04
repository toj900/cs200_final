#include <iostream>

<<<<<<< Updated upstream
=======
class Word{
private:
    std::string word;
    std::string fileName;
    std::string hint;
public:
    void setWord(  std::string newWord){
        word = newWord;
    }
    //Todo: add file implementation or change virtual function to word.
    virtual std::string getFile() = 0;
    std::string getWord(){
        return word;
    }
    void setFileName(  std::string newFile){
        fileName = newFile;
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
     std::string getFile(){
        return fileName;
    }
private:
    std::string fileName = "okay";
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
>>>>>>> Stashed changes

int main() {
    std::cout << "Hello, World!" << std::endl;
    int i = 0;
    while (i > 10){
        i++;
    }

    return 0;
}
