//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

void draw_map(int **map, int w, int h)
{
    for(int r = 0; r < h; r++)
    {
        for(int c = 0; c < w; c++)
        {
            switch(map[r][c])
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("X");
                    break;
                case 2:
                    printf("$");
                    break;
            }
        }
        printf("\n");
    }
}

int main()
{
    int w = 10;
    int h = 10;
    int **map = NULL;

    map = (int**)malloc(h * sizeof(int*));
    for(int r = 0; r < h; r++)
    {
        map[r] = (int*)malloc(w * sizeof(int));
    }

    // Create a post-apocalyptic map
    map[2][2] = 1;
    map[3][2] = 1;
    map[3][3] = 1;
    map[4][2] = 2;
    map[4][3] = 2;

    draw_map(map, w, h);

    free(map);

    return 0;
}