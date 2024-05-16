/* #########################################
 *	
 *	File: skin.cpp
 *
 *	Author : Bagus Koko Wibawanto
 *
 * ########################################
 *
 * */

#include <iostream>
#include <fstream>
#include "../include/snake.hpp"
#include <clocale>

bool Game::chooseSkin() {
        curs_set(FALSE);
        noecho();
        std::string listMenu[5] = {" Qi ", " Ziro ", " Ate ", " The G ", " Yu "};
        box(Map, 0, 0);
        bool exit = false;
        keypad(Map, TRUE);
        //int highlight = 0;
        int yMenuWindow[5] = {4, 6, 8, 10, 12};
        int xMenuWindow[5] = {7, 7, 7, 7, 7};
        //int selectedSkin = 1; // start index from 0
        SkinPreview();
        wrefresh(Map);
        wrefresh(ShadowMap);

        while(exit != true) {
                for(int i = 0; i < 5; i++){
                        mvwprintw(Map, yMenuWindow[i], xMenuWindow[i], listMenu[i].c_str());
                }
                mvwprintw(Map, 0, 1, "[ q ]");
                mvwprintw(Map, 18, 15, "Press Space To Select");

                for(int i = 0; i < 5; i++) {
                        if(i == highlight) {
                                wattron(Map, A_REVERSE);
                                mvwprintw(Map, yMenuWindow[i], xMenuWindow[i], listMenu[i].c_str());
                                wattroff(Map, A_REVERSE);
                        }
                }
        
                readDataSkin();

                // Show Detail Selected Skin
                if(skinSelected == highlight) {
                        mvwprintw(ShadowMap, 0, 2, "[ Selected ]");
                        wrefresh(ShadowMap);
                } else {
                        werase(ShadowMap);
                        wrefresh(ShadowMap);
                }

                // Show Preview
                SkinPreview();

                int choice = wgetch(Map);

                switch(choice) {
                        case KEY_UP:
                                if(highlight == 0) {
                                        highlight = 0;
                                        break;
                                }
                                highlight--;
                                break;
                        case KEY_DOWN:
                                if(highlight == 4) {
                                        highlight = 4;
                                        break;
                                }
                                highlight++;
                                break;
                        case ' ':
                                skinSelected = highlight;
                                saveDataSkin();
                                break;
                        case 'q':
                                exit = true;
                        default:
                                break;
                }
                
        }
        
        if(skinSelected == 0) {
                SnakeHead = 'Q';
        } else if (skinSelected == 1) {
                SnakeHead = '0';
        } else if (skinSelected == 2) {
                SnakeHead = '@';
        } else if (skinSelected == 3) {
                SnakeHead = 'G';
        } else {
                SnakeHead = 'U';
        }

        return 0;
}

bool Game::SkinPreview() {
        werase(SkinPreviewWindow);
        box(SkinPreviewWindow, 0, 0);
        if(highlight == 0) {
                mvwprintw(SkinPreviewWindow, 2, 6, "Q+++");
        } else if(highlight == 1) {
                mvwprintw(SkinPreviewWindow, 2, 6, "0+++");
        } else if(highlight == 2) {
                mvwprintw(SkinPreviewWindow, 2, 6, "@+++");
        } else if(highlight == 3) {
                mvwprintw(SkinPreviewWindow, 2, 6, "G+++");
        } else {
                mvwprintw(SkinPreviewWindow, 2, 6, "U+++");
        }
        wrefresh(SkinPreviewWindow);

        return 0;
}