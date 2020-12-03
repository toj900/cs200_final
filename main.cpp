#include <iostream>


class Word{
private:
    std::string word;
    std::string fileName;

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
    int lives =6;

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
    int i = 0;
    while (i > 10){
        i++;
    }

    return 0;
}
