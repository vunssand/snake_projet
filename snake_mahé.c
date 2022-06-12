#include <stdio.h>
#include <stdlib.h>
#include <uv.h>
#include <time.h>

char world[20][21]={
    "XXXXXXXXXXXXXXXXXXXX",
    "x                  x",
    "x                  x",
    "x                  x",
    "x                  x",
    "x                  x",
    "x                  x",
    "x                  x",
    "x                  x",
    "x                  x",
    "x                  x",
    "x                  x",
    "x                  x",
    "x                  x",
    "x                  x",
    "x                  x",
    "x                  x",
    "x                  x",
    "x                  x",
    "XXXXXXXXXXXXXXXXXXXX"
};


typedef struct Coords {
   int x;
    int y;
} Coords;

Coords Serpent {
    Serpent.x = rand(19);
    Serpent.y = rand(19);
}



void deplacement () {

    FILE *entree_u;

    entree_u = fopen("file.txt", "w+");

     for (;;) {
                int user_input = getchar();

                if(user_input == 'm'){
                    break;
                }
                if(user_input == 's'){
                    if(Serpent.x >= 1 && Serpent.x<18){
                        Serpent.x +=1;
                        fputs("s", entree_u);
                    }
                }
                if(user_input == 'z'){
                    if(Serpent.x >= 1 && Serpent.x<18){
                        Serpent.x -=1;
                        fputs("z", entree_u);
                    }
                }
                if(user_input == 'd'){
                    if(Serpent.y >= 1 && Serpent.y<18){
                         Serpent.y +=1;
                         fputs("d", entree_u);
                    }
                }
                if(user_input == 'q'){
                    if(Serpent.y >= 1 && Serpent.y<18){
                        Serpent.y +=1;
                        fputs("q", entree_u);
                    }
                }
        
                world[Serpent.x][Serpent.y] = 'o';
            }

}