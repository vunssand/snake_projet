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
           

void callback(uv_timer_t *handle) {
        if()
}


int main(){
    int i = 0;
    for(i=0; i<20; ++i)
    {
        printf("%s\n", world[i]);
    }
    
    int x = 10;
    int xbis = 10;
    int ybis = 10;
    int y = 10;

    

        

        uv_loop_t *loop = malloc(sizeof(uv_loop_t));
            uv_loop_init(loop);

            uv_timer_t timer_req;
            uv_tty_t input_tty;

            uv_timer_init(loop, &timer_req);
            uv_timer_start(&timer_req, callback, 1000, 1000);

            uv_tty_init(loop, &input_tty, STDIN_FILENO, 0);
            uv_tty_set_mode(&input_tty, UV_TTY_MODE_RAW);

            uv_run(loop, UV_RUN_DEFAULT);

            callback(timer_req);
            deplacement();
    
            uv_run(loop, UV_RUN_DEFAULT);

            uv_loop_close(loop);
            free(loop);
            
         
    

    for(i=0; i<20; ++i)
    {
        printf("%s\n", world[i]);
    }

    world[Serpent.x][Serpent.y] = ' ';
    

    return 0;

   
}
