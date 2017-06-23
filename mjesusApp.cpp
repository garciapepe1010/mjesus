/***************************************************************
 * Name:      mjesusApp.cpp
 * Purpose:   Code for Application Class
 * Author:    pepe (garciapepe1010@gmail.com)
 * Created:   2017-06-04
 * Copyright: pepe (none)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "mjesusApp.h"
#include "mjesusMain.h"

IMPLEMENT_APP(mjesusApp);

bool mjesusApp::OnInit()
{
    mjesusFrame* frame = new mjesusFrame(0L);
    
    frame->Show();
    
    return true;
}
