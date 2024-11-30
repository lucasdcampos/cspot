#include "spot.h"
#include <X11/Xlib.h>

// minimum required to open a window
int sptx11_open_window(spt_window *win, const spt_vec2 res, const char* title) {
    Display* MainDisplay = XOpenDisplay(0);
    Window RootWindow = XDefaultRootWindow(MainDisplay);
    
    Window MainWindow = XCreateSimpleWindow(MainDisplay, RootWindow, 0, 0, res.x, res.y, 0, 0, 0x0000);
    XMapWindow(MainDisplay, MainWindow);
    XFlush(MainDisplay);

    for(;;) { spt_sleep(1); }

    return 0;
}

void sptx11_close_window(spt_window *win) {

}