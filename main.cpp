#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{

    string line;
    ifstream scriptFile("script.txt");

    if (scriptFile.is_open())
    {
        while (true)
        {
            if (GetKeyState(VK_NUMPAD7) && 0x8000)
            {
                while (getline(scriptFile, line))
                {
                    if (!line.empty())
                    {
                        for (char &c : line)
                        {
                            if (GetKeyState(VK_NUMPAD9) && 0x8000)
                                return 0;
                            INPUT input = {0};
                            input.type = INPUT_KEYBOARD;
                            if (c == '!')
                            {
                                input.ki.wVk = VkKeyScanA(' ');
                            }
                            else if (c == '\'')
                            {
                                input.ki.wVk = VkKeyScanA(' ');
                            }
                            else if (c == '?')
                            {
                                input.ki.wVk = VkKeyScanA(' ');
                            }
                            else
                            {
                                input.ki.wVk = VkKeyScanA(c);
                            }
                            SendInput(1, &input, sizeof(input));
                            ZeroMemory(&input, sizeof(input));
                            Sleep(15);
                            input.ki.dwFlags = KEYEVENTF_KEYUP;
                            SendInput(1, &input, sizeof(input));
                            ZeroMemory(&input, sizeof(input));
                            Sleep(15);
                        }
                        INPUT input = {0};
                        input.type = INPUT_KEYBOARD;
                        input.ki.wVk = VkKeyScanA(VK_RETURN);
                        SendInput(1, &input, sizeof(input));
                        ZeroMemory(&input, sizeof(input));
                        Sleep(20);
                        input.ki.dwFlags = KEYEVENTF_KEYUP;
                        SendInput(1, &input, sizeof(input));
                        ZeroMemory(&input, sizeof(input));
                        Sleep(10);
                    }
                }
            }
        }
        scriptFile.close();
    }
    else
    {
        cout << "Something failed" << endl;
    }

    return 0;
}