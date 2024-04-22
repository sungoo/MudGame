#pragma once
#include "Line.h"
#include "Character.h"
#include "map.h"

enum SCENE {
    TITLE_SCENE,
    MAIN_SCENE,
    INPUT_SCENE,
    TOTAL_SCENE,
    QUIT,
    SCENE_MAX
};

enum CH_E {//character elemental
    NAME, M_HP, M_MP, ATK, DEF, SPD, MAXIMUM
};

string SelectTitle(SCENE scene);

void displayTitle(string title);

void displayMain(Character& ch, bool& isChMaded, MAP map);

void displayInput(Character& ch, bool& isChMaded);

void displayCharacter(Character ch);

void displayMap(MAP m);