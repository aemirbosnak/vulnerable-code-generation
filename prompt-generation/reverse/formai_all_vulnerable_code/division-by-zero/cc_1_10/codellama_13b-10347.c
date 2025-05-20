//Code Llama-13B DATASET v1.0 Category: Procedural Space Adventure ; Style: authentic
// Procedural Space Adventure

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_ENEMIES 10
#define MAX_ITEMS 10

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position position;
    char name[20];
    int health;
    int damage;
} Enemy;

typedef struct {
    Position position;
    char name[20];
    int value;
} Item;

typedef struct {
    Position position;
    int width;
    int height;
    Enemy enemies[MAX_ENEMIES];
    Item items[MAX_ITEMS];
} Room;

Room rooms[MAX_ROOMS];

void generate_rooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].position.x = rand() % 100;
        rooms[i].position.y = rand() % 100;
        rooms[i].width = rand() % 20;
        rooms[i].height = rand() % 20;
        for (int j = 0; j < MAX_ENEMIES; j++) {
            rooms[i].enemies[j].position.x = rand() % rooms[i].width;
            rooms[i].enemies[j].position.y = rand() % rooms[i].height;
            rooms[i].enemies[j].health = rand() % 100;
            rooms[i].enemies[j].damage = rand() % 10;
        }
        for (int j = 0; j < MAX_ITEMS; j++) {
            rooms[i].items[j].position.x = rand() % rooms[i].width;
            rooms[i].items[j].position.y = rand() % rooms[i].height;
            rooms[i].items[j].value = rand() % 100;
        }
    }
}

void print_rooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("Room %d\n", i);
        printf("  Position: (%d, %d)\n", rooms[i].position.x, rooms[i].position.y);
        printf("  Size: %dx%d\n", rooms[i].width, rooms[i].height);
        for (int j = 0; j < MAX_ENEMIES; j++) {
            printf("  Enemy %d\n", j);
            printf("    Position: (%d, %d)\n", rooms[i].enemies[j].position.x, rooms[i].enemies[j].position.y);
            printf("    Health: %d\n", rooms[i].enemies[j].health);
            printf("    Damage: %d\n", rooms[i].enemies[j].damage);
        }
        for (int j = 0; j < MAX_ITEMS; j++) {
            printf("  Item %d\n", j);
            printf("    Position: (%d, %d)\n", rooms[i].items[j].position.x, rooms[i].items[j].position.y);
            printf("    Value: %d\n", rooms[i].items[j].value);
        }
    }
}

int main() {
    generate_rooms();
    print_rooms();
    return 0;
}