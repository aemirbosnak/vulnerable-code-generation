//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_ROUTES 1000

typedef struct {
    char name[20];
    int x, y;
} City;

typedef struct {
    int start_city, end_city;
    int distance;
} Route;

City cities[MAX_CITIES];
Route routes[MAX_ROUTES];
int num_cities, num_routes;

void init_cities() {
    int i;
    for (i = 0; i < MAX_CITIES; i++) {
        cities[i].x = rand() % 100;
        cities[i].y = rand() % 100;
        cities[i].name[0] = '\0';
    }
}

void init_routes() {
    int i;
    for (i = 0; i < MAX_ROUTES; i++) {
        routes[i].start_city = rand() % num_cities;
        routes[i].end_city = rand() % num_cities;
        routes[i].distance = rand() % 100;
    }
}

void print_cities() {
    int i;
    for (i = 0; i < num_cities; i++) {
        printf("%s (%d, %d)\n", cities[i].name, cities[i].x, cities[i].y);
    }
}

void print_routes() {
    int i;
    for (i = 0; i < num_routes; i++) {
        printf("%s -> %s: %d\n", cities[routes[i].start_city].name, cities[routes[i].end_city].name, routes[i].distance);
    }
}

int main() {
    srand(time(NULL));
    init_cities();
    init_routes();
    num_cities = 10;
    num_routes = 20;

    print_cities();
    print_routes();

    return 0;
}