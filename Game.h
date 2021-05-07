//
// Created by rouple on 2021/5/5.
//

#ifndef GAMEOFLIFE01_GAME_H
#define GAMEOFLIFE01_GAME_H

#include<stdlib.h>
#include<string.h>
#include<SDL2/SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event event;

int EachSize;
int windowSize;
int CurrentCells[64][64];
int cells[64][64];
SDL_Rect cursor;

FILE * StateFile;

void initialize();
void RandomGenerateCells();
void RenderScreen();
void CreateBackup();
void EvolveOneGeneration();
int CountAroundCells(int x, int y);
void PlaceOnFile();
void ReadFile();

#endif //GAMEOFLIFE01_GAME_H





