//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMIES 10

void generate_enemies(int **enemies, int num_enemies);
void battle(int **enemies, int num_enemies);

int main()
{
    int num_enemies = rand() % MAX_ENEMIES + 1;
    int **enemies = NULL;

    generate_enemies(&enemies, num_enemies);
    battle(enemies, num_enemies);

    free(enemies);

    return 0;
}

void generate_enemies(int **enemies, int num_enemies)
{
    *enemies = malloc(num_enemies * sizeof(int));

    for (int i = 0; i < num_enemies; i++)
    {
        enemies[i] = rand() % 10 + 1;
    }
}

void battle(int **enemies, int num_enemies)
{
    for (int i = 0; i < num_enemies; i++)
    {
        printf("Enemy %d: HP %d\n", i + 1, enemies[i]);
    }

    printf("Prepare for battle...\n");
    sleep(1);

    for (int i = 0; i < num_enemies; i++)
    {
        enemies[i] -= rand() % 5 + 1;
    }

    for (int i = 0; i < num_enemies; i++)
    {
        if (enemies[i] <= 0)
        {
            printf("Enemy %d has been defeated!\n", i + 1);
        }
    }
}