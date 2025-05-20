//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24

void generate_map(char **map);
void print_map(char **map);
void place_player(char **map, int *player_x, int *player_y);

int main(){
    char *map[HEIGHT];
    int player_x, player_y;
    srand(time(NULL));

    for(int i = 0; i < HEIGHT; i++){
        map[i] = (char*)malloc(WIDTH * sizeof(char));
    }

    generate_map(map);
    place_player(map, &player_x, &player_y);

    while(1){
        system("clear");
        print_map(map);
        // player movement and game logic here
        // ...
    }

    return 0;
}

void generate_map(char **map){
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){
            if((rand() % 100) < 20){
                map[y][x] = '#';
            }else{
                map[y][x] = '.';
            }
        }
    }
}

void print_map(char **map){
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){
            putchar(map[y][x]);
        }
        putchar('\n');
    }
}

void place_player(char **map, int *player_x, int *player_y){
    while(1){
        *player_x = rand() % WIDTH;
        *player_y = rand() % HEIGHT;
        if(map[*player_y][*player_x] == '.'){
            map[*player_y][*player_x] = '@';
            break;
        }
    }
}