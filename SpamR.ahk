#Requires AutoHotkey v2.0

spamDelay := 30 ; задержка между кликами в мс

XButton2::
{
    while GetKeyState("XButton2", "P")
    {
        if GetKeyState("RButton", "P")
        {
            Click "Right"
            Sleep spamDelay
        }
        else
        {
            
        }
    }
}
