//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VEHICLES 100
#define MAX_ROAD_LENGTH 100
#define MAX_SPEED 10

typedef struct vehicle {
    int id;
    int position;
    int speed;
} vehicle;

typedef struct road {
    int length;
    vehicle* vehicles[MAX_VEHICLES];
} road;

road* create_road(int length) {
    road* r = malloc(sizeof(road));
    r->length = length;
    for (int i = 0; i < MAX_VEHICLES; i++) {
        r->vehicles[i] = NULL;
    }
    return r;
}

vehicle* create_vehicle(int id, int position, int speed) {
    vehicle* v = malloc(sizeof(vehicle));
    v->id = id;
    v->position = position;
    v->speed = speed;
    return v;
}

void add_vehicle(road* r, vehicle* v) {
    for (int i = 0; i < MAX_VEHICLES; i++) {
        if (r->vehicles[i] == NULL) {
            r->vehicles[i] = v;
            break;
        }
    }
}

void remove_vehicle(road* r, vehicle* v) {
    for (int i = 0; i < MAX_VEHICLES; i++) {
        if (r->vehicles[i] == v) {
            r->vehicles[i] = NULL;
            break;
        }
    }
}

void update_vehicles(road* r) {
    for (int i = 0; i < MAX_VEHICLES; i++) {
        vehicle* v = r->vehicles[i];
        if (v != NULL) {
            v->position += v->speed;
            if (v->position >= r->length) {
                remove_vehicle(r, v);
                free(v);
            }
        }
    }
}

void print_road(road* r) {
    for (int i = 0; i < r->length; i++) {
        for (int j = 0; j < MAX_VEHICLES; j++) {
            if (r->vehicles[j] != NULL && r->vehicles[j]->position == i) {
                printf("X");
            } else {
                printf(".");
            }
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    road* r = create_road(MAX_ROAD_LENGTH);

    for (int i = 0; i < MAX_VEHICLES; i++) {
        add_vehicle(r, create_vehicle(i, rand() % r->length, rand() % MAX_SPEED));
    }

    while (1) {
        update_vehicles(r);
        print_road(r);
    }

    return 0;
}