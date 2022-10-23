//
// Created by jeanc on 17/10/2022.
//

#ifndef PROYECTO_2_MENU_H
#define PROYECTO_2_MENU_H
#include "TwoFour.h"
#include "RuntimeException.h"
#include <chrono>
class Menu {
private:
    TwoFour *theTree;
public:
    Menu();

    void mainMenu();

    void insertN();

    virtual ~Menu();

    void probabilityN();

    void printInOrder();

    void viewTreeLevels();

    void insertElement();

    void deleteElement();

    void findElement();
};


#endif //PROYECTO_2_MENU_H
