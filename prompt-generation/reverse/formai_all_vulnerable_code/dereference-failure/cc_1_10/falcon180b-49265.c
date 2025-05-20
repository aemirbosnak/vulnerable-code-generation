//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROUTES 100
#define MAX_DESTINATIONS 100
#define MAX_ROUTE_LENGTH 50

typedef struct {
    int route_id;
    int destination_id;
    int route_length;
} route;

typedef struct {
    int num_routes;
    int num_destinations;
    int *destinations;
    int **routes;
} gps_data;

void generate_routes(gps_data *data) {
    srand(time(NULL));
    int i, j, k, route_length;
    data->routes = (int **)malloc(MAX_ROUTES * sizeof(int *));
    for (i = 0; i < MAX_ROUTES; i++) {
        data->routes[i] = (int *)malloc(MAX_DESTINATIONS * sizeof(int));
    }
    for (i = 0; i < MAX_ROUTES; i++) {
        route_length = rand() % MAX_ROUTE_LENGTH + 1;
        for (j = 0; j < route_length; j++) {
            k = rand() % data->num_destinations;
            data->routes[i][j] = k;
        }
    }
}

void print_routes(gps_data *data) {
    int i, j;
    for (i = 0; i < data->num_routes; i++) {
        printf("Route %d: ", i);
        for (j = 0; j < data->routes[i][0]; j++) {
            printf("%d ", data->routes[i][j]);
        }
        printf("\n");
    }
}

int main() {
    gps_data data;
    data.num_routes = 10;
    data.num_destinations = 30;
    data.destinations = (int *)malloc(data.num_destinations * sizeof(int));
    int i;
    for (i = 0; i < data.num_destinations; i++) {
        data.destinations[i] = i * 100000;
    }
    generate_routes(&data);
    print_routes(&data);
    return 0;
}