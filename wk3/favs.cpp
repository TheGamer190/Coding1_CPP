#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string input;
    vector<string> favoriteGames; 
    while(true)
    {
        cout << "What would you like to do\n";
        cout << "You can 'add', 'edit', 'remove', 'show', or 'quit'\n";
        getline(cin, input);
        if(input == "quit")
        {
            cout << "Thanks for playing!\n";
            break;
        }
        else if(input == "add")
        {
            cout << "Please input what you would like to add: \n";
            getline(cin, input);
            favoriteGames.push_back(input);
        }
        else if (input == "edit")
        {
            cout << "Choose a game to edit: \n";
            string input;
            getline(cin, input);

            vector<string>::iterator chosenGame = favoriteGames.begin();
            chosenGame = find(favoriteGames.begin(), favoriteGames.end(), input);
            if(chosenGame != favoriteGames.end())
            {
                cout << "What would you like to change " << *chosenGame << " to?\n";
                getline(cin, input);
                *chosenGame = input;
                cout << "The game is now " << *chosenGame << endl;
            }
        }
        else if(input == "remove")
        {
            cout << "Choose a game to remove: \n";
            string input;
            getline(cin, input);

            auto iter = find(favoriteGames.begin(), favoriteGames.end(), input);
            if(find(favoriteGames.begin(), favoriteGames.end(), input) != favoriteGames.end())
            {
                cout << "Removing game\n";
                favoriteGames.erase(iter);
            }
        }
        else if (input == "show")
        {
            for(int i = 0; i < favoriteGames.size(); i++)
            {
                cout << i + 1 << ". " << favoriteGames[i] << endl;
            }
        }
        else{
            cout << "I don't recongize that input\n";
        }
    }
    return 0;
}