#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    string word;
    ifstream scriptFile("script.txt");

    if (scriptFile.is_open())
    {
        while (scriptFile >> word)
        {
            if (!word.empty())
            {
                // TODO. Check for keyboard press and send Keyboard press
                cout << word << '\n';
            }
        }
        scriptFile.close();
    }
    else
    {
        cout << "Something failed";
    }

    cout << endl;

    return 0;
}