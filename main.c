#include <stdio.h>
#include "Game.h"

int main(){
    int loop = 0;
    int option = 0;
    printf("Please choose an option: \n");
    printf("1) Display the game \n");
    printf("2) Decide the number of generations \n");
    printf("3) Change the size of the world \n");
    printf("4) Load the last state\n");
    scanf("%d", &option);
    getchar();
    switch (option) {
        case 1: {
            initialize();
            RandomGenerateCells();
            while(1){
                RenderScreen();
                SDL_Delay(50);
                if (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        PlaceOnFile();
                        return 0;
                    }
                }
            }
        }
        case 2: {
            printf("Please enter the number of generation: \n");
            scanf("%d", &loop);
            getchar();
            initialize();
            RandomGenerateCells();
            for (int i = 0; i < loop; ++i) {
                RenderScreen();
                SDL_Delay(500);
                PlaceOnFile();
            }
            break;
        }
        case 3: {
            printf("Please enter the size of the world: (200 - 764)");
            scanf("%d", &windowSize);
            getchar();
            initialize();
            RandomGenerateCells();
            while(1){
                RenderScreen();
                SDL_Delay(50);
                if (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        PlaceOnFile();
                        return 0;
                    }
                }
            }
        }
        case 4: {
            initialize();
            ReadFile();
            while(1){
                RenderScreen();
                SDL_Delay(50);
                if (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        //PlaceOnFile();
                        return 0;
                    }
                }
            }
        }
    }

}