//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 80

void clear_screen()
{
    printf("\033[2J");
}

void draw_map(int **map, int x, int y)
{
    for (int y = 0; y < map[0]; y++)
    {
        for (int x = 0; x < map[1]; x++)
        {
            printf("%c ", map[y][x]);
        }
        printf("\n");
    }
}

int main()
{
    int **map = NULL;
    int x = 0, y = 0, direction = 0;

    map = (int**)malloc(10 * sizeof(int*));
    for (int i = 0; i < 10; i++)
    {
        map[i] = (int*)malloc(10 * sizeof(int));
    }

    map[0][0] = 1;
    map[0][1] = 1;
    map[1][0] = 1;
    map[1][1] = 1;

    draw_map(map, x, y);

    while (1)
    {
        char input;

        printf("Enter direction (w, a, s, d): ");
        scanf(" %c", &input);

        switch (input)
        {
            case 'w':
                y--;
                break;
            case 'a':
                x--;
                break;
            case 's':
                y++;
                break;
            case 'd':
                x++;
                break;
            default:
                break;
        }

        if (map[y][x] == 0)
        {
            printf("You have reached the end of the map!\n");
            break;
        }

        draw_map(map, x, y);
    }

    return 0;
}