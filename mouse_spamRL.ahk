#Requires AutoHotkey v2.0
#SingleInstance Force

clickDelay := 25


XButton2::
{
    global clickDelay

    while GetKeyState("XButton2", "P")
    {
        if GetKeyState("LButton", "P")
            Click "Left"

        if GetKeyState("RButton", "P")
            Click "Right"

        Sleep clickDelay
    }
}
