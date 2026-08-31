*rbutton::
    Loop
    {
        GetKeyState,state,rbutton,P
        if state = U
            break
        else
            Send,{rbutton}

    }
return

*lbutton::
    Loop
    {
        GetKeyState,state,lbutton,P
        if state = U
            break
        else
            Send,{lbutton}
    }
return


c::Suspend 
