// Derek Richards
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

vector<string> randomNames;

void GetRandomNames(vector<string>& names, const string& path = "PokemonNames.txt") {
    names.clear();
    ifstream file(path);
    if (!file.is_open()) {
        cout << "File not found: " << path << "\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        if (!line.empty())
            names.push_back(line);
    }
    file.close();
}

class BasePokemon {
public:
    BasePokemon() {
        pokemonSpecies = randomNames[rand() % randomNames.size()];
        nickname = "";
        maxHealth = rand() % 5 + 5;
        health = maxHealth;
        attack = rand() % 3 + 3;
        defense = rand() % 3 + 3;
        speed = rand() % 3 + 3;
        hunger = 3;
    }
    BasePokemon(const BasePokemon& obj)
        : pokemonSpecies(obj.pokemonSpecies), nickname(obj.nickname),
        health(obj.health), maxHealth(obj.maxHealth),
        attack(obj.attack), defense(obj.defense),
        speed(obj.speed), hunger(obj.hunger) {
    }
    BasePokemon& operator=(const BasePokemon& other) {
        if (this != &other) {
            pokemonSpecies = other.pokemonSpecies;
            nickname = other.nickname;
            health = other.health;
            maxHealth = other.maxHealth;
            attack = other.attack;
            defense = other.defense;
            speed = other.speed;
            hunger = other.hunger;
        }
        return *this;
    }
    virtual ~BasePokemon() {}

    virtual void Feed() = 0;
    virtual void Train() = 0;
    virtual void Listen() = 0;

protected:
    string pokemonSpecies;   
    string nickname;  

    int health;
    int maxHealth;
    int attack;
    int defense;
    int speed;
    int hunger;

    string DisplayName() const {
        return nickname.empty() ? pokemonSpecies : nickname + " (" + pokemonSpecies + ")";
    }
};

class Pokemon : public BasePokemon {
public:
#pragma region GetterFunctions
    string GetName() const { return DisplayName(); }
    string GetSpecies() const { return pokemonSpecies; }
    string GetNickname() const { return nickname; }
    int GetHealth() const { return health; }
    int GetMaxHealth() const { return maxHealth; }
    int GetAttack() const { return attack; }
    int GetDefense() const { return defense; }
    int GetSpeed() const { return speed; }
    int GetHunger() const { return hunger; }
#pragma endregion
#pragma region SetterFunctions
    void SetNickname(const string& newNickname) {
        nickname = newNickname;
        if (nickname.empty())
        {
            cout << "Nickname cleared. Pokemon will be called " << pokemonSpecies << ".\n";
        }
        else
        {
            cout << pokemonSpecies << " has been nicknamed \"" << nickname << "\"!\n";
        }
    }
    void SetHealth(int val)
    {
        health = val;
    }
    void SetMaxHealth(int val) {
        maxHealth = val;
    }
    void SetDefense(int val) {
        defense = val;
    }
    void SetAttack(int val) {
        attack = val;
    }
    void SetHunger(int val) {
        hunger = val;
    }
    void SetSpeed(int val) {
        speed = val;
    }
#pragma endregion
    void PromptNickname() {
        cout << "Enter a nickname for " << pokemonSpecies
            << " , press Enter to keep " << pokemonSpecies << ": ";
        string input;
        getline(cin, input);
        SetNickname(input);
    }
#pragma region UserActionFunctions
    void Feed() override {
        hunger -= 5;
        if (hunger < 0) hunger = 0;
        cout << DisplayName() << " has been fed. Hunger is now " << hunger << ".\n";
    }

    void Train() override {
        if (hunger >= 10) {
            cout << DisplayName() << " is too hungry to train!\n";
            return;
        }
        else if (hunger > 5) {
            cout << DisplayName() << " is getting hungry, feed them soon!\n";
        }

        int randomRoll = rand() % 3;
        hunger += 3;
        if (randomRoll == 0) {
            maxHealth += 3;
            cout << DisplayName() << " has been trained. Max health is now " << maxHealth << endl;
        }
        else if (randomRoll == 1) {
            attack += 3;
            defense += 3;
            cout << DisplayName() << " has been trained. Attack is now " << attack
                << " and defense is now " << defense << endl;
        }
        else if (randomRoll == 2) {
            speed += 3;
            cout << DisplayName() << " has been trained. Speed is now " << speed << endl;
        }
        
    }

    void Listen() override {
        cout << "Pokemon: " << DisplayName() << endl;
        cout << "HP:      " << health << " / " << maxHealth << endl;
        cout << "Attack:  " << attack << endl;
        cout << "Defense: " << defense << endl;
        cout << "Speed:   " << speed << endl;
        cout << "Hunger:  " << hunger << endl;
    }

    void Battle(Pokemon& opponent) {
        string input;
        while (true)
        {
            cout << "Battle: " << DisplayName() << " vs " << opponent.DisplayName() << endl;
            cout << "Choose action: fight, heal, run: ";
            getline(cin, input);
            if (input == "heal") {
                if (health >= maxHealth) {
                    cout << DisplayName() << " is already at full HP\n";
                }
                else {
                    health += 3;
                    if (health > maxHealth) health = maxHealth;
                    cout << DisplayName() << " recovered some HP: "
                        << health << " / " << maxHealth << endl;
                }
            }
            else if (input == "run") {
                if (speed > opponent.speed) {
                    cout << DisplayName() << " got away safely!\n";
                    return;
                }
                else {
                    // if pokemon is slower, then have a chance to escape
                    if ((rand() % 10) == 0) {
                        cout << DisplayName() << " got away!\n";
                        return;
                    }
                    else {
                        cout << DisplayName() << " couldn't escape!\n";
                    }
                }
            }
            else if (input == "fight") {
                if (hunger >= 10) {
                    cout << DisplayName() << " is too hungry to fight!\n";
                    return;
                }
                else if (hunger > 5) {
                    cout << DisplayName() << " is getting hungry, feed them soon!\n";
                }
                hunger++;
                auto doAttack = [](Pokemon& attacker, Pokemon& defender) {
                    int dmg = attacker.attack - defender.defense;
                    if (dmg < 1)
                    {
                        dmg = 1;   // always deal at least 1 damage
                    }
                    defender.health -= dmg;
                    cout << attacker.DisplayName() << " dealt " << dmg
                        << " damage to " << defender.DisplayName()
                        << "! (HP: " << defender.health << " / "
                        << defender.maxHealth << ")\n";
                    };

                if (speed >= opponent.speed) {       // player attacks first
                    doAttack(*this, opponent);
                    if (opponent.health > 0)
                    {
                        doAttack(opponent, *this);
                    }
                }
                else {                              // opponent attacks first
                    doAttack(opponent, *this);
                    if (health > 0)
                    {
                        doAttack(*this, opponent);
                    }
                }

                if (health <= 0) {
                    cout << DisplayName() << " fainted!\n";
                    return;
                }
                else if (opponent.health <= 0) {
                    cout << opponent.DisplayName() << " fainted! " << DisplayName() << " wins!\n";
                    return;
                }
            }
            else {
                cout << "Unknown action. Turn skipped.\n";
            }
        }
        }
        
#pragma endregion
};

Pokemon* FindPokemon(vector<Pokemon>& team, const string& query) {
    for (Pokemon& p : team) {
        if (p.GetSpecies() == query || p.GetNickname() == query)
        {
            return &p;
        }
    }
    return nullptr;
}

void PrintTeamNames(const vector<Pokemon>& team) {
    cout << "Your team: ";
    for (int i = 0; i < (int)team.size(); i++) {
        cout << team[i].GetName();
        if (i < (int)team.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

int main() {
    srand((time(0)));
    GetRandomNames(randomNames);
    vector<Pokemon> team(3);
    
    string input;

    cout << "Here is your starting team:\n";
    for (Pokemon& p : team)
    {
        p.Listen();
    }

    cout << "Would you like to nickname any of your Pokemon? (yes / no): \n";
    string answer;
    getline(cin, answer);
    if (answer == "yes") {
        for (Pokemon& p : team) {
            p.PromptNickname();
        }
    }

    while (true) {
        cout << "Actions: train, feed, listen, nickname, battle, quit\n ";
        getline(cin, input);

        if (input == "quit") {
            cout << "Thanks for playing!\n";
            break;
        }
        else if (input == "listen") {
            for (Pokemon& p : team)
            {
                p.Listen();
            }
        }
        else if (input == "feed") {
            PrintTeamNames(team);
            cout << "Which Pokemon would you like to feed? ";
            getline(cin, input);
            Pokemon* p = FindPokemon(team, input);
            if (p) {
                p->Feed();
            }
            else {
                cout << "Pokemon: " << input << " not found.\n";
            }
                
        }
        else if (input == "train") {
            PrintTeamNames(team);
            cout << "Which Pokemon would you like to train? ";
            getline(cin, input);
            Pokemon* p = FindPokemon(team, input);
            if (p) {
                p->Train();
            }
            else {
                cout << "Pokemon: " << input << " not found.\n";
            }
        }
        else if (input == "nickname") {
            PrintTeamNames(team);
            cout << "Which Pokemon would you like to nickname? ";
            getline(cin, input);
            Pokemon* p = FindPokemon(team, input);
            if (p) {
                p->PromptNickname();
            }
            else {
                cout << "Pokemon: " << input << " not found.\n";
            }
        }
        else if (input == "battle") {
            Pokemon opponentPokemon;
            PrintTeamNames(team);
            cout << "Which Pokemon will battle " << opponentPokemon.GetName() << "? ";
            getline(cin, input);
            Pokemon* p = FindPokemon(team, input);
            if (p) {
                p->Battle(opponentPokemon);
            }
            else {
                cout << "Pokemon: " << input << " not found.\n";
            }
        }
        else {
            cout << "Unknown command.\n";
        }
    }

    return 0;
}