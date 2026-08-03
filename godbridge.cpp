#include <iostream>
#include <windows.h>
#include "WinIn.hpp"


/*
hold shift
hold s d


rclick spam
unhold shift
timeout
hold shift

*/

int Start() {
    WORD shift[] = {VK_SHIFT};
    WORD space[] = {VK_SPACE};
    WORD Rmouse[] = {VK_RBUTTON};
    WORD sd[] = {0x53, 0x44};
    WORD UsedButt[] = {0x53, 0x44, VK_SHIFT};
    DWORD64 Bdelay = 220; // BRIDGE DELAY
    DWORD64 PSHdelay = 100; // POST SHIFT HOLDING DELAY
    DWORD64 BlocksDelay = 100;
    DWORD64 MDelay = 500;

    PressKbd(shift, 1, DOWN__); //holding Shift
    Sleep(300);
    PressKbd(sd, 2, DOWN__); // holding S and D
    Sleep(300);
    PressKbd(shift, 1, UP__);
    while(1) {
            PressMouseR(40, 27);
            PressKbd(shift, 1, DOWN__);
        DWORD Check = GetAsyncKeyState(0x5A); // Z
        printf("f");
        if(Check == 1 || Check == PF) {
            printf("ds");
            PressKbd(sd, 2, UP__);
            Sleep(300);
            PressKbd(shift, 2, UP__); 
            return 0;
        }
        Sleep(500);
        PressKbd(shift, 2, UP__); 
    }
    return 0;
}


int main() {

    while(1) {
        DWORD a = GetAsyncKeyState(VK_F9); // TO EXIT
        DWORD b = GetAsyncKeyState(0x58); // TO START (X)
        if(a == 1 || a == PF) return 0;

        if(b == 1 || b == PF) {
            Start();
        }
    } // waiting for F8




}
