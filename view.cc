#include "view.h"
#include <iostream>
#include <string>
using namespace std;

//Player postion - Tile 
int tile00Pos [7] = {84, 85, 86, 87, 84, 85, 86, 87}
int tile01Pos [7] = {76, 77, 78, 79, 76, 77, 78, 79}
int tile02Pos [7] = {68, 69, 70, 71, 68, 69, 70, 71}
int tile03Pos [7] = {60, 61, 62, 63, 60, 61, 62, 63}
int tile04Pos [7] = {52, 53, 54, 55, 52, 53, 54, 55}
int tile05Pos [7] = {44, 45, 46, 47, 44, 45, 46, 47}
int tile06Pos [7] = {36, 37, 38, 39, 36, 37, 38, 39}
int tile07Pos [7] = {28, 29, 30, 31, 28, 29, 30, 31}
int tile08Pos [7] = {20, 21, 22, 23, 20, 21, 22, 23}
int tile09Pos [7] = {12, 13, 14, 15, 12, 13, 14, 15}
int tile10Pos [7] = {4, 5, 6, 7, 4, 5, 6, 7}

int tile11Pos [7] = {4, 5, 6, 7, 4, 5, 6, 7}
int tile12Pos [7] = {4, 5, 6, 7, 4, 5, 6, 7}
int tile13Pos [7] = {4, 5, 6, 7, 4, 5, 6, 7}
int tile14Pos [7] = {4, 5, 6, 7, 4, 5, 6, 7}
int tile15Pos [7] = {4, 5, 6, 7, 4, 5, 6, 7}
int tile16Pos [7] = {4, 5, 6, 7, 4, 5, 6, 7}
int tile17Pos [7] = {4, 5, 6, 7, 4, 5, 6, 7}
int tile18Pos [7] = {4, 5, 6, 7, 4, 5, 6, 7}
int tile19Pos [7] = {4, 5, 6, 7, 4, 5, 6, 7}
int tile20Pos [7] = {4, 5, 6, 7, 4, 5, 6, 7}

int tile21Pos [7] = {12, 13, 14, 15, 12, 13, 14, 15}
int tile22Pos [7] = {20, 21, 22, 23, 20, 21, 22, 23}
int tile23Pos [7] = {28, 29, 30, 31, 28, 29, 30, 31}
int tile24Pos [7] = {36, 37, 38, 39, 36, 37, 38, 39}
int tile25Pos [7] = {44, 45, 46, 47, 44, 45, 46, 47}
int tile26Pos [7] = {52, 53, 54, 55, 52, 53, 54, 55}
int tile27Pos [7] = {60, 61, 62, 63, 60, 61, 62, 63}
int tile28Pos [7] = {68, 69, 70, 71, 68, 69, 70, 71}
int tile29Pos [7] = {76, 77, 78, 79, 76, 77, 78, 79}
int tile30Pos [7] = {84, 85, 86, 87, 84, 85, 86, 87}

int tile31Pos [7] = {82, 83, 84, 85, 86, 87, 88, 82}
int tile32Pos [7] = {82, 83, 84, 85, 86, 87, 88, 82}
int tile33Pos [7] = {82, 83, 84, 85, 86, 87, 88, 82}
int tile34Pos [7] = {82, 83, 84, 85, 86, 87, 88, 82}
int tile35Pos [7] = {82, 83, 84, 85, 86, 87, 88, 82}
int tile36Pos [7] = {82, 83, 84, 85, 86, 87, 88, 82}
int tile37Pos [7] = {82, 83, 84, 85, 86, 87, 88, 82}
int tile38Pos [7] = {82, 83, 84, 85, 86, 87, 88, 82}
int tile39Pos [7] = {82, 83, 84, 85, 86, 87, 88, 82}

void View::print(){
	string tmpArr[56];
    tmpArr[0]  = "-----------------------------------------------------------------------------------------";
    tmpArr[1]  = "|Goose  |       |NEEDLES|       |       |V1     |       |       |CIF    |       |GO TO  |";
    tmpArr[2]  = "|Nesting|-------|HALL   |-------|-------|       |-------|-------|       |-------|TIMS   |";
    tmpArr[3]  = "|       |EV1    |       |EV2    |EV3    |       |PHYS   |B1     |       |B2     |       |";
    tmpArr[4]  = "|       |       |       |       |       |       |       |       |       |       |       |";
    tmpArr[5]  = "|-------|-----------------------------------------------------------------------|-------|";
    tmpArr[6]  = "|       |                                                                       |       |";
    tmpArr[7]  = "|-------|                                                                       |-------|";
    tmpArr[8]  = "|OPT    |                                                                       |EIT    |";
    tmpArr[9]  = "|       |                                                                       |       |";
    tmpArr[10] = "|-------|                                                                       |-------|";
    tmpArr[11] = "|       |                                                                       |       |";
    tmpArr[12] = "|-------|                                                                       |-------|";
    tmpArr[13] = "|BMH    |                                                                       |ESC    |";
    tmpArr[14] = "|       |                                                                       |       |";
    tmpArr[15] = "|-------|                                                                       |-------|";
    tmpArr[16] = "|SLC    |                                                                       |SLC    |";
    tmpArr[17] = "|       |                                                                       |       |";
    tmpArr[18] = "|       |                                                                       |       |";
    tmpArr[19] = "|       |                                                                       |       |";
    tmpArr[20] = "|-------|                                                                       |-------|";
    tmpArr[21] = "|       |                                                                       |       |";
    tmpArr[22] = "|-------|                                                                       |-------|";
    tmpArr[23] = "|LHI    |                                                                       |C2     |";
    tmpArr[24] = "|       |                                                                       |       |";
    tmpArr[25] = "|-------|                                                                       |-------|";
    tmpArr[26] = "|UWP    |                             BB7K                                      |REV    |";
    tmpArr[27] = "|       |                                                                       |       |";
    tmpArr[28] = "|       |                                                                       |       |";
    tmpArr[29] = "|       |                                                                       |       |";
    tmpArr[30] = "|-------|                                                                       |-------|";
    tmpArr[31] = "|       |                                                                       |NEEDLES|";
    tmpArr[32] = "|-------|                                                                       |HALL   |";
    tmpArr[33] = "|CPH    |                                                                       |       |";
    tmpArr[34] = "|       |                                                                       |       |";
    tmpArr[35] = "|-------|                                                                       |-------|";
    tmpArr[36] = "|       |                                                                       |       |";
    tmpArr[37] = "|-------|                                                                       |-------|";
    tmpArr[38] = "|DWE    |                                                                       |MC     |";
    tmpArr[39] = "|       |                                                                       |       |";
    tmpArr[40] = "|-------|                                                                       |-------|";
    tmpArr[41] = "|PAC    |                                                                       |COOP   |";
    tmpArr[42] = "|       |                                                                       |FEE    |";
    tmpArr[43] = "|       |                                                                       |       |";
    tmpArr[44] = "|       |                                                                       |       |";
    tmpArr[45] = "|-------|                                                                       |-------|";
    tmpArr[46] = "|       |                                                                       |       |";
    tmpArr[47] = "|-------|                                                                       |-------|";
    tmpArr[48] = "|RCH    |                                                                       |DC     |";
    tmpArr[49] = "|       |                                                                       |       |";
    tmpArr[50] = "|-------|-----------------------------------------------------------------------|-------|";
    tmpArr[51] = "|DC Tims|       |       |NEEDLES|       |MKV    |TUITION|       |SLC    |       |COLLECT|";
    tmpArr[52] = "|Line   |-------|-------|HALL   |-------|       |       |-------|       |-------|OSAP   |";
    tmpArr[53] = "|       |HH     |PAS    |       |ECH    |       |       |ML     |       |AL     |       |";
    tmpArr[54] = "|       |       |       |       |       |       |       |       |       |       |       |";
    tmpArr[55] = "-----------------------------------------------------------------------------------------";

    for (int i = 0; i < 55; i++){
        cout << tmpArr[i];
    }
}

void View::notify(int playerNum, Tile * t){
}

void View::setNumberOfPlayers(int num){
	numPlayers = num;
}

void View::addPlayer(string piece){

}

View::~View(){
	
}
