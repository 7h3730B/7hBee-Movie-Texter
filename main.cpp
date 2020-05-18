#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    string line;
    ifstream scriptFile("script.txt");

    if (scriptFile.is_open())
    {
        while (true)
        {
            // TODO: Check for a Keypress
            while (getline(scriptFile, line) && true)
            {
                if (!line.empty())
                {
                    // TODO. Check for keyboard press and send Keyboard press
                    cout << line << '\n';
                }
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