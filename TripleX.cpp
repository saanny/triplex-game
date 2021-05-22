#include <iostream>
#include <ctime>

void Printintroduction(int levelDifficulty){
    std::cout << std::endl;
    std::cout << "You are a secret agent breaking into a secure server room ..." << " level " << levelDifficulty << std::endl;
    std::cout << "Enter the correct code to continue ..." << std::endl;
}
bool PlayGame(int levelDifficulty){

    Printintroduction(levelDifficulty);

    const int CodeA = rand() % levelDifficulty + levelDifficulty;
    const int CodeB = rand()  % levelDifficulty + levelDifficulty;
    const int CodeC = rand()  % levelDifficulty  + levelDifficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code" << std::endl;
    std::cout << "+ The codes add-up to: " << CodeSum << std::endl;
    std::cout << "+ The codes multiply to give : " << CodeProduct << std::endl;
    
    int GuessA,GuessB,GuessC;

    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;


    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    std::cout << "You Entered" << GuessA << GuessB << GuessC;
    std::cout << std::endl;
    
    if(GuessSum == CodeSum && GuessProduct == CodeProduct){
        std::cout << "You win ! \r\n";
        return true;
    }else{
        std::cout << "You lose ! \r\n";
        return false;
    }
}

int main() {
    srand(time(NULL));
    
    int levelDifficulty = 1;
    int MaxDifficulty = 5;

    while(levelDifficulty <= MaxDifficulty){
            bool bLevelComplete = PlayGame(levelDifficulty);
            std::cin.clear();
            std::cin.ignore();
            if(bLevelComplete){
                ++levelDifficulty;
            }
    }
    std::cout << "\n*** Great work agent! you got all the files! now get out of there **\n";

    return 0;
}