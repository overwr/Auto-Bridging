#include <iostream>
#include <windows.h>

#define UP__ 0
#define DOWN__ 1
#define ONCE__ 2
#define VKDOWN__ 0
#define VKUP__ KEYEVENTF_KEYUP

#define PF -32767 // Pressed button flag


BOOL PressKbdOnce(WORD keycode) {
    INPUT in[2];
        in[0].type = INPUT_KEYBOARD;
        in[0].ki.wVk = keycode;
        in[0].ki.dwFlags = VKDOWN__;

        in[1].type = INPUT_KEYBOARD;
        in[1].ki.wVk = keycode;
        in[1].ki.dwFlags = VKUP__;

        SendInput(2, in, sizeof(INPUT));
        return true;
}

BOOL PressKbd(WORD keycodes[], DWORD klen, WORD hold) {
    INPUT in[klen];
    for (DWORD Index = 0; Index != klen; Index++) {
        in[Index].type = INPUT_KEYBOARD;
        in[Index].ki.wVk = keycodes[Index];
        if(hold == UP__) {
            in[Index].ki.dwFlags = KEYEVENTF_KEYUP;
        }
        else if(hold == DOWN__) {
            in[Index].ki.dwFlags = VKDOWN__;
        }

    }
    // for(DWORD64 i = 0; i != times; i++) SendInput(klen, in, sizeof(INPUT));
    SendInput(klen, in, sizeof(INPUT));
    return true;
} 




BOOL PressMouseR(DWORD64 times, DWORD64 delay) {
    INPUT in[2];

    in[0].type = INPUT_MOUSE;
    in[0].mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;

    in[1].type = INPUT_MOUSE;
    in[1].mi.dwFlags = MOUSEEVENTF_RIGHTUP;
    for (int i = 0; i != times; i++)
    {
        SendInput(1, &in[0], sizeof(INPUT));
        Sleep(delay);
        SendInput(1, &in[1], sizeof(INPUT));
    }


return true;
}