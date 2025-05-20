//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_LATITUDE 90
#define MAX_LONGITUDE 180
#define MIN_LATITUDE -90
#define MIN_LONGITUDE -180

typedef struct {
    double latitude;
    double longitude;
} coordinate;

typedef struct {
    coordinate start;
    coordinate end;
} route;

typedef struct {
    route *routes;
    size_t num_routes;
} map;

map create_map(size_t num_routes) {
    map m;
    m.num_routes = num_routes;
    m.routes = malloc(sizeof(route) * num_routes);
    return m;
}

void destroy_map(map *m) {
    free(m->routes);
    m->num_routes = 0;
}

void generate_random_coordinates(coordinate *c) {
    c->latitude = MIN_LATITUDE + (double)rand() / RAND_MAX * (MAX_LATITUDE - MIN_LATITUDE);
    c->longitude = MIN_LONGITUDE + (double)rand() / RAND_MAX * (MAX_LONGITUDE - MIN_LONGITUDE);
}

void generate_random_route(route *r) {
    generate_random_coordinates(&r->start);
    generate_random_coordinates(&r->end);
}

void generate_random_map(map *m) {
    for (size_t i = 0; i < m->num_routes; i++) {
        generate_random_route(&m->routes[i]);
    }
}

void print_coordinate(coordinate *c) {
    printf("(%lf, %lf)", c->latitude, c->longitude);
}

void print_route(route *r) {
    printf("Start: ");
    print_coordinate(&r->start);
    printf("\nEnd: ");
    print_coordinate(&r->end);
    printf("\n");
}

void print_map(map *m) {
    for (size_t i = 0; i < m->num_routes; i++) {
        printf("Route %zu: ", i);
        print_route(&m->routes[i]);
    }
}

int main() {
    srand(time(NULL));

    size_t num_routes = 10;
    map m = create_map(num_routes);
    generate_random_map(&m);
    print_map(&m);
    destroy_map(&m);

    return 0;
}