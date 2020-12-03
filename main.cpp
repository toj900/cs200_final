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
    int lives = 6;

public:
    void setLives(int reduction){
        lives -= reduction;
    }
    int getLives(){
        return lives;
    }
};

class ScoreBoard{

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Word:Sports footBall;
    footBall.setWord("Penalty");
    footBall.setHint("Misconduct");
    std::cout<<"Word: "<< footBall.getWord()<< "Hint: "<< footBall.getHint()<<std::endl;


    return 0;
}
