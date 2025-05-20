//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_ROUTES 1000

typedef struct city {
    char name[50];
    double lat;
    double lon;
} city_t;

typedef struct route {
    int num_cities;
    city_t cities[MAX_CITIES];
} route_t;

route_t* generate_route(int num_cities) {
    route_t* route = malloc(sizeof(route_t));
    route->num_cities = num_cities;

    srand(time(NULL));
    for (int i = 0; i < num_cities; i++) {
        city_t city;
        city.lat = (double)rand() / RAND_MAX * 180 - 90;
        city.lon = (double)rand() / RAND_MAX * 360 - 180;
        city.name[0] = '\0';
        route->cities[i] = city;
    }

    return route;
}

void print_route(route_t* route) {
    printf("Route with %d cities:\n", route->num_cities);
    for (int i = 0; i < route->num_cities; i++) {
        printf("City %d: %s (%f, %f)\n", i + 1, route->cities[i].name, route->cities[i].lat, route->cities[i].lon);
    }
}

int main() {
    int num_cities;

    printf("Enter the number of cities in the route (1-100): ");
    scanf("%d", &num_cities);

    if (num_cities < 1 || num_cities > MAX_CITIES) {
        printf("Invalid number of cities.\n");
        return 1;
    }

    route_t* route = generate_route(num_cities);
    print_route(route);

    free(route);
    return 0;
}