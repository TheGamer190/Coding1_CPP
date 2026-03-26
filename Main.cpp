//Derek Richards

//To compile open CMD VS 22, 
// navigate to this folder, 
// run the command "cl /EHsc " to compile, 
// run file by calling the name

#include <iostream> //Libary for in out stream for printing text 
#include <string>
using namespace std; //Dont need to type std::

int main()
{
    string playerName;

    cout << "What's your name? " << endl;
    cin >> playerName;

    cout << "Hello " << playerName << "." << endl;

    return 0;
}