//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_SIZE 10
#define MAX_PLANET_SIZE 100

typedef struct room {
    int x, y;
    char type;
} room;

typedef struct planet {
    int size;
    room *rooms;
} planet;

typedef struct ship {
    int x, y;
} ship;

void init_room(room *r, int x, int y, char type) {
    r->x = x;
    r->y = y;
    r->type = type;
}

void init_planet(planet *p, int size) {
    p->size = size;
    p->rooms = malloc(sizeof(room) * size * size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            init_room(&p->rooms[i * size + j], i, j, '.');
        }
    }
}

void init_ship(ship *s, int x, int y) {
    s->x = x;
    s->y = y;
}

void print_planet(planet *p) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            printf("%c", p->rooms[i * p->size + j].type);
        }
        printf("\n");
    }
}

void move_ship(ship *s, char direction) {
    switch (direction) {
        case 'w':
            s->y--;
            break;
        case 'a':
            s->x--;
            break;
        case 's':
            s->y++;
            break;
        case 'd':
            s->x++;
            break;
    }
}

int main() {
    srand(time(NULL));

    planet p;
    init_planet(&p, MAX_PLANET_SIZE);

    ship s;
    init_ship(&s, p.size / 2, p.size / 2);

    while (1) {
        print_planet(&p);
        printf("Ship: (%d, %d)\n", s.x, s.y);

        char input;
        scanf(" %c", &input);

        if (input == 'q') {
            break;
        } else if (input == 'w' || input == 'a' || input == 's' || input == 'd') {
            move_ship(&s, input);
        }
    }

    return 0;
}