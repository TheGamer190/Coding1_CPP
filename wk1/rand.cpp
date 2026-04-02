//Derek Richards
#include <iostream>
#include <random>
#include <ctime>

int main()
{
    srand(time(0));
    int randomNum;//set the seed for the random number
    int playerGuess;
    randomNum = rand() % 10 + 1;
     
    //std::cout << "The first random number is " << randomNum << ".\n";

    while (true)
    {
        std::cout << "Guess a number: " << std::endl;
        std::cin >> playerGuess;
        if(playerGuess == randomNum)
        {
            std::cout << "Correct!!! :)\n"; 
            break;
        }
        else if (playerGuess > randomNum)
        {
            std::cout << "Too high :(\n";
        }
        else{
            std::cout << "Too low :(\n";
        }
    }

    // int count = 0;
    // while (count++ < 10)
    // {
    //     std::cout << (rand() % 10) + 1 << std::endl;
    // }

    //number guess game
    //computer picks a number between 1 and 10
    //the computer then assks the player to guess
    //player inputs num
    //computer then computes if the number is too high, low or is correct

    return 0;
}