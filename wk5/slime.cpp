//Derek Richards
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

vector<string> slimeNames = {"Elizabeth", "Theodore", "Margret", "Lavenza", "Philimon", "Igor", "Justine", "Caroline"};

class BaseSlime{
public:
    
    BaseSlime(){
        name = slimeNames[rand() % slimeNames.size()] + " Slime";
        health = rand() % 5 + 5;
        damage = rand() % 3 + 3;
    }
    BaseSlime(string setName, int setHealth, int setDamage) : name(setName), health(setHealth), damage(setDamage){}
    void Hello(){
        cout << "My name is " << name << " my health is " << health <<
            " and my damage is " << damage << endl;
    }
    bool Attack(BaseSlime &otherFighter)
    {
        health -= otherFighter.damage;

        if(otherFighter.GetHealth() <= 0)
        {
            return true;
        }
        else{
            return false;
        }
    }

    #pragma region Getters
    string GetName(){
        return name;
    }
    int GetHealth(){
        return health;
    }
    int GetDamage(){
        return damage;
    }
    #pragma endregion
private:
    string name;
    int health;
    int damage;
};

int main()
{
    srand(time(0));
    vector<BaseSlime> allSlimes(6);
    BaseSlime bongoHead{"BongoHead", 20, 3};
    BaseSlime littleGuy{"Little guy", 20, 3};

    // allSlimes.push_back(bongoHead);
    // allSlimes.push_back(littleGuy);

    // for(int i = 0; i < allSlimes.size(); i++){
    //     allSlimes.at(i).Hello();
    // }

    for(BaseSlime &i : allSlimes)
    {
        i.Hello();
    }

    BaseSlime temp,temp2;
    BaseSlime& fighterA = temp;
    BaseSlime& fighterB = temp2;
    if(rand() % 2 == 0){
        cout << "BongoHead goes first\n";
        fighterA = bongoHead;
        fighterB = littleGuy;
    }
    else{
        cout << "Little Guy goes first\n";
        fighterA = littleGuy;
        fighterB = bongoHead;
    }

    while (fighterA.GetHealth() >= 0 && fighterB.GetHealth() >= 0){
        cout <<fighterA.GetName() << " punches " << fighterB.GetName() << endl;
        if(fighterA.Attack(fighterB)){
            cout << fighterB.GetName() << " has been beaten\n";
            break;
        }
        else{
            if(fighterB.Attack(fighterA)){
            cout << fighterA.GetName() << " has been beaten\n";
            break;
        }
        }
        // fighterA.Attack(fighterB);
        // if(fighterB.GetHealth() > 0){
        //     fighterB.Attack(fighterA);
        //     if(fighterA.GetHealth() <= 0){
        //         cout << fighterA.GetName() << " had been beaten\n";
        //         break;
        //     }
        // }
        // else{
        //     cout << fighterB.GetName() << " has been beaten\n";
        //     break;
        // }
    }


    return 0;
}