//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 512
#define HEIGHT 256

#define SHIP_SIZE 10
#define BULLET_SIZE 2

typedef struct Ship
{
    int x, y;
    struct Ship* next;
} Ship;

typedef struct Bullet
{
    int x, y;
    struct Bullet* next;
} Bullet;

Ship* CreateShip(int x, int y)
{
    Ship* ship = malloc(sizeof(Ship));
    ship->x = x;
    ship->y = y;
    ship->next = NULL;
    return ship;
}

Bullet* CreateBullet(int x, int y)
{
    Bullet* bullet = malloc(sizeof(Bullet));
    bullet->x = x;
    bullet->y = y;
    bullet->next = NULL;
    return bullet;
}

void MoveShip(Ship* ship, int dx, int dy)
{
    ship->x += dx;
    ship->y += dy;
}

void ShootBullet(Ship* ship, Bullet* bullet)
{
    bullet->x = ship->x;
    bullet->y = ship->y;
}

int main()
{
    srand(time(NULL));

    Ship* head = CreateShip(WIDTH / 2, HEIGHT - 1);

    Bullet* bulletHead = CreateBullet(head->x, head->y - 1);

    int score = 0;

    while (!head->next)
    {
        MoveShip(head, rand() % 5 - 2, rand() % 3 - 1);
        ShootBullet(head, bulletHead);
        bulletHead = CreateBullet(head->x, head->y - 1);

        score++;
    }

    printf("Your score: %d\n", score);

    return 0;
}