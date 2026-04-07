//Derek Richards
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0));

    const int size = 5;
    int highScores[size];
    std::string names[size];

    std::string input;
    int tempStore;

    for(int i = 0; i < size; ++i)
    {
        highScores[i] = rand();
    }

    for(int i = 0; i < size; i++)
    {
        std::cout << "Add your name\n";
        std::cin >> input;
        // if(input == "done")
        // {
        //     break;
        // }
        names[i] = input;
    }

    std::cout << "High scores: \n";
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; j++)
        {
            if(highScores[i] > highScores[j])
            {
                tempStore = highScores[i];
                highScores[i] = highScores[j];
                highScores[j] = tempStore;
            }
        }
    }

    for(int i = 0; i < size; i++)
    {
        std::cout << i + 1 << "." << names[i] << ": " << highScores[i] << std::endl;
    }
    std::string name = names[rand() % size]; 
    std::cout << "Talk about " << name << std::endl;
    switch(rand() % size)
    {
        case 0:
            std::cout << "I love " << name << std::endl;
            break;
        case 1:
            std::cout << "I like " << name << std::endl;
            break;
        case 2:
            std::cout << "I don't like " << name << std::endl;
            break;
        case 3:
            std::cout << "I hate " << name << std::endl;
            break;
        case 4:
            std::cout << "I don't care about " << name << std::endl;
            break;
        default:
            break;
    }

    

    return 0;
}