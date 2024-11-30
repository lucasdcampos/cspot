#include "spot.h"

static spt_window_api _win_api = Default;

void spt_set_window_api(spt_window_api api)
{
    _win_api = api;
}

int spt_open_window(spt_window *win, const spt_vec2 res, const char* title) {
    switch (_win_api)
    {
    case X11:
        sptx11_open_window(win, res, title);
        break;
    default:
        #ifdef _WIN32
            printf("Win32 API not supported yet!");
        #else
            sptx11_open_window(win, res, title);
        #endif
        break;
    }
}

void spt_close_window(spt_window *win) {
    switch (_win_api)
    {
    case X11:
        sptx11_close_window(win);
        break;
    default:
        #ifdef _WIN32
            printf("Win32 API not supported yet!");
        #else
            sptx11_close_window(win);
        #endif
        break;
    }
}