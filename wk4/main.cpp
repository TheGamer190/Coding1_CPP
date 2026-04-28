//derek richards
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void WriteFile(string input, string path = "save.txt")
{
    ofstream file(path);
    file << input;
    file.close();
}

void WriteFile(vector<string>& vector, string path = "vector.txt") {
    ofstream file(path);
    for (int i = 0; i < vector.size(); i++)
    {
        file << vector[i] << endl;
    }
    file.close();
}

void ReadFile(string path = "save.txt")
{
    ifstream file(path);
    string line;
    if (file.is_open())
    {
        while (getline(file, line)) {
            cout << line << endl;
        }
    }
    else
    {
        cout << "File not found";
    }
    file.close();
}

void ReadFile(vector<string>& vector, string path = "vector.txt") {
    vector.clear();
    ifstream file(path);
    string line;
    if (file.is_open())
    {
        while (getline(file, line)) {
            vector.push_back(line);
        }
    }
    else {
        cout << "File not found";
    }
    file.close();
}

int main()
{
    ofstream file("save.txt");
    file.close();

    WriteFile("Here is some text.\nNext line from the file\n");
    ReadFile();

    vector<string> names = { "john", "roger", "ben" };
    ReadFile(names, "names.txt");
    for (int i = 0; i < names.size(); i++)
    {
        cout << names.at(i) << endl;
    }
    WriteFile(names, "names.txt");

    return 0;
}