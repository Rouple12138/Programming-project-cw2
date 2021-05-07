//
// Created by rouple on 2021/5/5.
//

#include "Game.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

int EachSize = 12;
int windowSize = 764;
int CurrentCells[64][64]={};
int cells[64][64]={};

void initialize(){
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Game Of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowSize, windowSize, SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    cursor = (SDL_Rect){0, 0, EachSize, EachSize};
}

void RandomGenerateCells(){ //Randomly generate cells
    for(int y = 0; y < 64; y++){
        for(int x = 0; x < 64; x++){
            if(rand() % 4 == 0){
                cells[y][x] = 1;
            }
        }
    }
}

void RenderScreen(){//Render the screen for one generation
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xff);
    SDL_RenderClear(renderer);
    CreateBackup();
    EvolveOneGeneration();
    SDL_Rect cell = {0, 0, 5, 5};
    SDL_Rect verticalGrid = {0, 0, 10, windowSize};
    SDL_Rect horizontalGrid = {0, 0, windowSize, 10};
    for(int y = 0; y < 64; y++){
        SDL_SetRenderDrawColor(renderer, 22, 22, 22, 0xff);
        horizontalGrid.y = (y * EachSize) - 1;
        SDL_RenderDrawRect(renderer, &horizontalGrid);
        verticalGrid.x = (y * EachSize) - 1;
        SDL_RenderDrawRect(renderer, &verticalGrid);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0xff);
        for(int x = 0; x < 64; x++){
            cell.x = x * EachSize;
            cell.y = y * EachSize;
            if(cells[y][x] == 1){
                SDL_RenderFillRect(renderer, &cell);
            }
        }
    }
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 200);
    SDL_RenderFillRect(renderer, &cursor);
    SDL_RenderPresent(renderer);
}

void CreateBackup(){//Create a backup of the cells so far
    for(int y = 0; y < 64; y++){
        for(int x = 0; x < 64; x++){
            CurrentCells[y][x] = cells[y][x];
        }
    }
}

void EvolveOneGeneration(){//Evolve one generation
    for(int y = 0; y < 64; y++){
        for(int x = 0; x < 64; x++){
            int count = CountAroundCells(x, y);
            if(count == 3){
                cells[y][x] = 1;
            }else if(count < 2 || count > 3){
                cells[y][x] = 0;
            }
        }
    }
}

int CountAroundCells(int x, int y){//Count the number of alive cells neighbouring the specific cell
    int count =
            CurrentCells[y - 1][x - 1] + CurrentCells[y - 1][x] + CurrentCells[y - 1][x + 1] +
            CurrentCells[y][x - 1]     + 			 0			+     CurrentCells[y][x + 1] +
            CurrentCells[y + 1][x - 1] + CurrentCells[y + 1][x] + CurrentCells[y + 1][x + 1];
    return count;
}

void PlaceOnFile(){
    if((StateFile = fopen("memory.txt","w")) == NULL){
        printf("Can't open memory.txt!\n");
        exit(1);
    }
    for(int y = 0; y < 64; y++){
        for(int x = 0; x < 64; x++){
            fprintf(StateFile, "%d", CurrentCells[y][x]);
        }
        fprintf(StateFile, "\n");
        printf("\n");
    }
    fclose(StateFile);
}

void ReadFile(){
    if((StateFile = fopen("memory.txt","r")) == NULL){
        printf("No Game Cache Here!\n");
        exit(1);
    }
    int column[64] = {};
    int temp[64] = {};
    int row[64] = {};
    while(fscanf(StateFile,"%[^\n]",column)!=EOF) {
        fgetc(StateFile);
        for (int i = 0; i < 64; i++) {
             temp[i]= atoi(column[i]);
             printf("%d", &temp[i]);
        }
        //printf("%d", temp);
        printf("n");
    }

    fclose(StateFile);
}