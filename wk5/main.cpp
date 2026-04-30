//derek richards
#include <iostream>
#include <string>
using namespace std;

class robot
{
private:
    string name;
    int charge;
    int bordeom;
public:
    robot(string nameA, int chargeA, int bordeomA) : name(nameA), charge(chargeA), bordeom(bordeomA){
        Status();
    }

    robot(){
        Status();
    }

    void Status()
    {
        cout << "My name is " << name << ", and my charge is " << charge << endl;
        cout << "I am ";
        if(bordeom < 5){
            cout << "Happy\n";
        }
        else if(bordeom < 10){
            cout << "Bored\n";
        }
        else if(bordeom < 15){
            cout << "Frustruated\n";
        }
        else{
            cout << "Enraged\n";
        }
    }

    void NewDay(){
        bordeom += 2;
    }

    void Play(){
        bordeom--;
    }

    void SetName(string givenName){
        if(givenName.size() <= 5){
            name = givenName;
        }
        else{
            cout << "Name too long!\n";
        }
    }
    string GetName(){
        return name;
    }
    void SetCharge(int givenCharge){
        if(givenCharge < 0){
            givenCharge = 0;
        }
        charge = givenCharge;
    }
    int GetCharge(){
        return charge;
    }
    void SetBoredom(int givenBoredom){
        if(givenBoredom < 0){
            givenBoredom = 0;
        }
        bordeom = givenBoredom;
    }
    void ChangeCharge(int amount){
        SetCharge(charge += amount);
    }
    int GetBoredom(){
        return bordeom;
    }
};

int main()
{
    string input;
    int turns = 0;

    robot r2d2{"R2-D2", 100, 10};
    robot c3po{"C-3PO", 20, 5};
    c3po.Status();

    cout << r2d2.GetCharge() << endl;
    cout << c3po.GetCharge() << endl;

    while(c3po.GetCharge() < 60)
    {
        r2d2.ChangeCharge(-1);
        c3po.ChangeCharge(1);
    }
    cout << "New charge:\n";
    cout << r2d2.GetCharge() << endl;
    cout << c3po.GetCharge() << endl;

    while(true){
        while(turns < 3){
            cout << "What would you like to do?\n";
            getline(cin, input);
            if(input == "play"){
                cout << "Lets play with " << r2d2.GetName() << endl;
                r2d2.Play();
            }
            else if(input == "status"){
                r2d2.Status();
            }
            turns++;
        }
        turns = 0;
        cout << "Do you want to keep playing?\n";
        getline(cin, input);
        if(input == "no"){
            break;
        }
        r2d2.NewDay();
    }

    return 0;
}