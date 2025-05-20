//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void play_sound(char sound) {
    switch (sound) {
        case 'a':
            system("play sound/a.wav");
            break;
        case 'b':
            system("play sound/b.wav");
            break;
        case 'c':
            system("play sound/c.wav");
            break;
        default:
            break;
    }
}

int main() {
    srand(time(NULL));
    int i, j, k, l, m, n, ghosts_num = 5, rooms_num = 3;

    char **map = (char**)malloc(rooms_num * sizeof(char*));
    for (i = 0; i < rooms_num; i++) {
        map[i] = (char*)malloc(ghosts_num * sizeof(char));
        for (j = 0; j < ghosts_num; j++) {
            map[i][j] = '0';
        }
    }

    map[0][0] = '1';
    map[1][2] = '1';
    map[2][1] = '1';

    for (k = 0; k < 5; k++) {
        l = rand() % rooms_num;
        m = rand() % ghosts_num;
        if (map[l][m] == '0') {
            map[l][m] = '1';
        } else {
            k--;
        }
    }

    printf("Welcome to the Haunted House!\n");
    printf("--------------------\n");

    for (n = 0; n < rooms_num; n++) {
        printf("Room %d: ", n + 1);
        for (i = 0; i < ghosts_num; i++) {
            if (map[n][i] == '1') {
                play_sound('a');
                printf("Ghost found!\n");
            }
        }
        printf("\n");
    }

    free(map);

    return 0;
}