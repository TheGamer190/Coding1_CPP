//Derek richarrds
#include <iostream>

int main()
{
    int playerAge = -1;
    std::string playerName = "none";
    float playerHeight = -1.0f;
    bool playAgain = false;
    bool godMode = false;

    if(playerAge == -1)
    {
        std::cout << "How old are you?\n";
        std::cin >> playerAge;
        if(playerAge < 13)
        {
            std::cout << "Not old enough to player this game buddy :(\n";
        }
        else
        {
            std::cout << "Coolio\n";
        }
    }

    //test if player name is sally and if so ask the player what their name is

    if(playerName == "none")
    {
        std::cout << "What is your name? \n";
        std::cin >> playerName;
        std::cout << "Hello " << playerName << "!\n";
    }
    
    if((playerAge == 19) && (playerName == "Derek"))
    {
        std::cout << "Hello there. God mode enabled\n";
        godMode = true;
    }

    return 0;
}