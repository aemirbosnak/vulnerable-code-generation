//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ART_SIZE 10

char art[ART_SIZE][ART_SIZE];

void init_art() {
    int i, j;
    for(i = 0; i < ART_SIZE; i++) {
        for(j = 0; j < ART_SIZE; j++) {
            art[i][j] = '*';
        }
    }
    art[ART_SIZE - 1][ART_SIZE - 1] = '\0';
}

void generate_art(char c) {
    int i, j, x, y;
    switch(c) {
        case 'A':
            x = 0; y = 0;
            art[x][y] = 'O';
            art[x][y+1] = art[x+1][y] = art[x][y+2] = 'O';
            art[x][y+2] = art[x+1][y+1] = 'X';
            art[x+1][y] = art[x][y+1] = '\0';
            break;
        case 'B':
            for(i = 0; i < ART_SIZE; i++) {
                for(j = 0; j < ART_SIZE; j++) {
                    if((i+j)%2 == 0) {
                        art[i][j] = '*';
                    } else {
                        art[i][j] = ' ';
                    }
                }
            }
            break;
        default:
            break;
    }
}

int main(int argc, char *argv[]) {
    char c;
    if(argc != 2) {
        printf("Usage: %s <character>\n", argv[0]);
        return 1;
    }

    init_art();
    c = argv[1][0];
    generate_art(c);

    printf("\n");
    int i, j;
    for(i = 0; i < ART_SIZE; i++) {
        for(j = 0; j < ART_SIZE; j++) {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }

    return 0;
}