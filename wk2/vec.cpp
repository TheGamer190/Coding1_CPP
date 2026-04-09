//Derek Richards
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int chpater = 0;

    std::cout << "What program would you like to run\n";
    std::cout << "Press 1 for vectors\n";
    std::cout << "Press 2 for push_back and pop_back\n";
    std::cout << "Press 3 for algorithms\n";
    std::string input;
    std::cin >> chpater;

    if (chpater == 1)
    {
        std::vector<std::string> names = { "Oh-no", "John", "Roger" };
        std::cout << "There are " << names.size() << " in the vector.\n";
        for (int i = 0; i < names.size(); ++i)
        {
            std::cout << i + 1 << ". " << names[i] << ".\n";
        }
        std::cout << "The first name in the vector is " << *(names.begin()) << ".\n";

        std::vector<std::string>::iterator iter;
        iter = names.begin() + 2; // points to the third address of names
        std::cout << "iter is pointing at " << *iter << ".\n";
    }
    if (chpater == 2)
    {
        std::cout << "Push_back and pop_back\n";
        std::vector<std::string> favMovies;
        while (favMovies.size() < 3)
        {
            std::cout << "Add a fav movie: ";
            std::cin >> input;

            favMovies.push_back(input);
        }
        std::cout << "Heres the favmovies list: \n";
        for (std::vector<std::string>::iterator iter = favMovies.begin(); iter != favMovies.end(); iter++)
        {
            std::cout << *iter << std::endl;
        }
    }
    if (chpater == 3)
    {
        std::vector<std::string> friends;

        friends.push_back("Joey");
        friends.push_back("Monica");
        friends.push_back("Phoebe");
        friends.push_back("Ross");
        friends.push_back("Chandler");
        friends.push_back("Rachael");

        std::cout << "Here are your friends: \n";
        for (int i = 0; i < friends.size(); i++)
        {
            std::cout << friends[i] << ".\n";
        }

        std::cout << "Choose a friend to vist: \n";
        std::string input;
        std::cin >> input;

        std::vector<std::string>::iterator chosenFriend = friends.begin();
        chosenFriend = find(friends.begin(), friends.end(), input);
        if(chosenFriend != friends.end())
        {
            std::cout << "Lets talk to " << *chosenFriend << ".\n";
        }
        else{
            std::cout << "Not your friend\n";
        }

        std::cout << "Lets give " << *chosenFriend << " a new name\n";
        std::cin >> input;
        *chosenFriend = input;
        std::cout << "Their name is now " << *chosenFriend << ".\n";
    }
    else {
        std::cout << "Chapter not available\n";
    }

    return 0;
}