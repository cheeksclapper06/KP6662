//
// Created by User on 05.12.2024.
//

#ifndef KP6_CUSTOMIZATION_H
#define KP6_CUSTOMIZATION_H

#define GREEN 2
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_YELLOW 14
#define LIGHT_RED 12
#define RESET_COLOR 7

#include <windows.h>

void setTextColor(const int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
#endif //KP6_CUSTOMIZATION_H
