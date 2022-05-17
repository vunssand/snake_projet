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

srand(time(NULL));

typedef struct Coords {
   int x;
    int y;
} Coords;

Coords Serpent {
    Serpent.x = rand(19);
    Serpent.y = rand(19);
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

    void callback (uv_timer_t *handle) {
    typedef void (*callback)();
    for (;;) {
        int user_input = getchar();

        if(user_input == 'm'){
            break;
        }
        if(user_input == 's'){
            if(Serpent.x >= 1 && Serpent.x<18){
                Serpent.x +=1;
            }
        }
        if(user_input == 'z'){
            if(Serpent.x >= 1 && Serpent.x<18){
                Serpent.x -=1;
            }
        }
        if(user_input == 'd'){
            if(Serpent.y >= 1 && Serpent.y<18){
                y +=1;
            }
        }
        if(user_input == 'q'){
            if(Serpent.y >= 1 && Serpent.y<18){
                y -=1;
            }
        }
        
        world[Serpent.x][Serpent.y] = 'o';
    }
        

        uv_loop_t *loop = malloc(sizeof(uv_loop_t));
            uv_loop_init(loop);

            uv_timer_t timer_req;

            uv_timer_init(loop, &timer_req);
            uv_timer_start(&timer_req, callback, 1000, 700);
    
            uv_run(loop, UV_RUN_DEFAULT);

            uv_loop_close(loop);
            free(loop);
            
         
    }

    for(i=0; i<20; ++i)
    {
        printf("%s\n", world[i]);
    }

    world[Serpent.x][Serpent.y] = ' ';
    }

    return 0;

   
}
}