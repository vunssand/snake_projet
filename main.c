#include <stdio.h>
#include <stdlib.h>
#include <uv.h>
#include <time.h>
#include <string.h>

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


typedef struct Pomme {
    int x;
    int y;
} Pomme_t;

int rand_num(int from, int to) {

     if (from == to) {
        return to;

    } else { 
        int randNumber = from + (random() % (to - from)); } };

typedef struct Serpent {
    int x, y; 
    int longueur;
    int ancien_x, ancien_y;
} Serpent_t;

size_t strlen(const char * entree_u);

void deplacement (Serpent_t *Serpent, Pomme_t * Pomme, const int * rang, const char * entree_u) {


     for (;;) {
                int user_input = getchar();

                if(user_input == 'm'){
                    break;
                }
                if(user_input == 's'){
                    if(Serpent->x >= 1 && Serpent->x<18)
                    {
                        Serpent->x -=1;
                        (*entree_u)[rang];
                        rang++;
                    }
                }
                if(user_input == 'z'){
                    if(Serpent->x >= 1 && Serpent->x<18)
                    {
                        Serpent->x +=1;
                        (*entree_u)[rang];
                        rang++;
                    }
                }
                if(user_input == 'd'){
                    if(Serpent->y >= 1 && Serpent->y<18)
                    {
                         Serpent->y +=1;
                         (*entree_u)[rang];
                        rang++;
                    }
                }
                if(user_input == 'q'){
                    if(Serpent->y >= 1 && Serpent->y<18)
                    {
                        Serpent->y +=1;
                        (*entree_u)[rang];
                        rang++;
                    }
                }
        
                world[Serpent->x][Serpent->y] = 'o';
                world[Pomme->x][Pomme->y] = 'O';
            }

}
           

void  * callback( Serpent_t * Serpent, const char * entree_u, const int * rang) {

        if((*entree_u)[rang] == 'z') {
                if (Serpent->x > 1) {
                    Serpent->x+=1;
                }
                else {
                    Serpent->x = 18;
                }
        }
        if((*entree_u)[rang] == 's') {
                if (Serpent->x < 18) {
                    Serpent->x-=1;
                }
                else {
                    Serpent->x = 0;
                }
        }
        if((*entree_u)[rang] == 'd') {
                if (Serpent->y < 18) {
                    Serpent->y+=1;
                }
                else {
                    Serpent->y = 0;
                }
        }
        if((*entree_u)[rang] == 'q') {
                if (Serpent->y > 1) {
                    Serpent->y-=1;
                }
                else {
                    Serpent->y = 18;
                }
        }



}

int apparition_pomme(Serpent_t * Serpent, Pomme_t * Pomme) {

    free(Pomme);
    Pomme = malloc(sizeof(Pomme_t));
    Pomme->x = rand_num(1, 19);
    Pomme->y = rand_num(1, 19);
    Serpent->longueur += 1;
    world[Pomme->x][Pomme->y] = 'o'

}

int ajouter_serpent(Serpent_t * Serpent, const int * rang, const char * entree_u) {

        int n = 0;

        for (n = 0; n < Serpent->longueur; n++) {
                

                if((*entree_u)[rang] == 'd') {
                        
                        Serpent->ancien_x = Serpent->x;
                        Serpent->ancien_y = Serpent->y;

                        Serpent->x = Serpent->x+1;

                       

                }

                if((*entree_u)[rang] == 'q') {
                   
                       Serpent->ancien_x = Serpent->x;
                       Serpent->ancien_y = Serpent->y;

                       Serpent->x = Serpent->x-1;

                }
                  
                

                if((*entree_u)[rang] == 's') {

                        Serpent->ancien_x = Serpent->x;
                        Serpent->ancien_y = Serpent->y;

                        Serpent->y = Serpent->y-1;

                }

                if((*entree_u)[rang] == 'z') {

                        Serpent->ancien_x = Serpent->x;
                        Serpent->ancien_y = Serpent->y;

                        Serpent->y = Serpent->y+1;

                }

        world[Serpent->ancien_x][Serpent->ancien_y] = 'o';  

        }
}


int main()
{
    int i = 0;
    const int * entree_u[50] = {};
    const int * rang = 0;

    Serpent_t *Serpent;
    Pomme_t * Pomme = malloc(sizeof(Pomme_t));
    
    Serpent->x = rand_num(1, 19);
    Serpent->y = rand_num(1, 19);

    Pomme->x = 10;
    Pomme->y = 10;

    deplacement(Serpent, Pomme, rang, entree_u);

    if ((Serpent->x == Pomme->x) && (Serpent->y == Pomme->y)) {
            apparition_pomme(Serpent, Pomme);
            ajouter_serpent(Serpent, rang, entree_u);

    }

        
        
        uv_loop_t *loop = malloc(sizeof(uv_loop_t));
            uv_loop_init(loop);

            uv_timer_t timer_req;
            uv_tty_t input_tty;

            uv_timer_init(loop, &timer_req);
            uv_timer_start(&timer_req, callback, 1000, 1000);

            uv_run(loop, UV_RUN_DEFAULT);

            uv_loop_close(loop);
            free(loop);
            
         
    

    for(i=0; i<20; ++i)
    {
        printf("%s\n", world[i]);
    }

    world[Serpent->x][Serpent->y] = ' ';
    world[Pomme->x][Pomme->y] = ' ';
    

    return 0;

   
}
