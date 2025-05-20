//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <math.h>

#define MAX_VEHICLES 1000
#define MAX_ROADS 100
#define MAX_INTERSECTIONS 100

typedef struct {
    int id;
    int length;
    int speed_limit;
    int num_lanes;
    int *lanes;
} road_t;

typedef struct {
    int id;
    char *name;
    int num_roads;
    road_t **roads;
} intersection_t;

typedef struct {
    int id;
    char *type;
    int length;
    int speed_limit;
    int num_lanes;
    int *lanes;
    intersection_t *intersection;
} vehicle_t;

typedef struct {
    int num_vehicles;
    vehicle_t **vehicles;
    int num_roads;
    road_t **roads;
    int num_intersections;
    intersection_t **intersections;
} traffic_flow_t;

traffic_flow_t *create_traffic_flow(int num_vehicles, int num_roads, int num_intersections) {
    traffic_flow_t *traffic_flow = malloc(sizeof(traffic_flow_t));
    traffic_flow->num_vehicles = num_vehicles;
    traffic_flow->vehicles = malloc(sizeof(vehicle_t *) * num_vehicles);
    for (int i = 0; i < num_vehicles; i++) {
        traffic_flow->vehicles[i] = malloc(sizeof(vehicle_t));
        traffic_flow->vehicles[i]->id = i;
        traffic_flow->vehicles[i]->type = "car";
        traffic_flow->vehicles[i]->length = 4;
        traffic_flow->vehicles[i]->speed_limit = 50;
        traffic_flow->vehicles[i]->num_lanes = 1;
        traffic_flow->vehicles[i]->lanes = malloc(sizeof(int) * traffic_flow->vehicles[i]->num_lanes);
        traffic_flow->vehicles[i]->lanes[0] = 0;
        traffic_flow->vehicles[i]->intersection = NULL;
    }
    traffic_flow->num_roads = num_roads;
    traffic_flow->roads = malloc(sizeof(road_t *) * num_roads);
    for (int i = 0; i < num_roads; i++) {
        traffic_flow->roads[i] = malloc(sizeof(road_t));
        traffic_flow->roads[i]->id = i;
        traffic_flow->roads[i]->length = 1000;
        traffic_flow->roads[i]->speed_limit = 50;
        traffic_flow->roads[i]->num_lanes = 2;
        traffic_flow->roads[i]->lanes = malloc(sizeof(int) * traffic_flow->roads[i]->num_lanes);
        traffic_flow->roads[i]->lanes[0] = 0;
        traffic_flow->roads[i]->lanes[1] = 1;
    }
    traffic_flow->num_intersections = num_intersections;
    traffic_flow->intersections = malloc(sizeof(intersection_t *) * num_intersections);
    for (int i = 0; i < num_intersections; i++) {
        traffic_flow->intersections[i] = malloc(sizeof(intersection_t));
        traffic_flow->intersections[i]->id = i;
        traffic_flow->intersections[i]->name = "intersection";
        traffic_flow->intersections[i]->num_roads = 4;
        traffic_flow->intersections[i]->roads = malloc(sizeof(road_t *) * traffic_flow->intersections[i]->num_roads);
        traffic_flow->intersections[i]->roads[0] = traffic_flow->roads[i * 2];
        traffic_flow->intersections[i]->roads[1] = traffic_flow->roads[i * 2 + 1];
        traffic_flow->intersections[i]->roads[2] = traffic_flow->roads[i * 2 + 2];
        traffic_flow->intersections[i]->roads[3] = traffic_flow->roads[i * 2 + 3];
    }
    return traffic_flow;
}

void destroy_traffic_flow(traffic_flow_t *traffic_flow) {
    for (int i = 0; i < traffic_flow->num_vehicles; i++) {
        free(traffic_flow->vehicles[i]->lanes);
        free(traffic_flow->vehicles[i]);
    }
    free(traffic_flow->vehicles);
    for (int i = 0; i < traffic_flow->num_roads; i++) {
        free(traffic_flow->roads[i]->lanes);
        free(traffic_flow->roads[i]);
    }
    free(traffic_flow->roads);
    for (int i = 0; i < traffic_flow->num_intersections; i++) {
        free(traffic_flow->intersections[i]->roads);
        free(traffic_flow->intersections[i]->name);
        free(traffic_flow->intersections[i]);
    }
    free(traffic_flow->intersections);
    free(traffic_flow);
}

void print_traffic_flow(traffic_flow_t *traffic_flow) {
    printf("Traffic flow:\n");
    for (int i = 0; i < traffic_flow->num_vehicles; i++) {
        printf("Vehicle %d:\n", traffic_flow->vehicles[i]->id);
        printf("  Type: %s\n", traffic_flow->vehicles[i]->type);
        printf("  Length: %d\n", traffic_flow->vehicles[i]->length);
        printf("  Speed limit: %d\n", traffic_flow->vehicles[i]->speed_limit);
        printf("  Num lanes: %d\n", traffic_flow->vehicles[i]->num_lanes);
        printf("  Lanes: ");
        for (int j = 0; j < traffic_flow->vehicles[i]->num_lanes; j++) {
            printf("%d ", traffic_flow->vehicles[i]->lanes[j]);
        }
        printf("\n");
        if (traffic_flow->vehicles[i]->intersection) {
            printf("  Intersection: %s\n", traffic_flow->vehicles[i]->intersection->name);
        } else {
            printf("  Intersection: None\n");
        }
    }
    for (int i = 0; i < traffic_flow->num_roads; i++) {
        printf("Road %d:\n", traffic_flow->roads[i]->id);
        printf("  Length: %d\n", traffic_flow->roads[i]->length);
        printf("  Speed limit: %d\n", traffic_flow->roads[i]->speed_limit);
        printf("  Num lanes: %d\n", traffic_flow->roads[i]->num_lanes);
        printf("  Lanes: ");
        for (int j = 0; j < traffic_flow->roads[i]->num_lanes; j++) {
            printf("%d ", traffic_flow->roads[i]->lanes[j]);
        }
        printf("\n");
    }
    for (int i = 0; i < traffic_flow->num_intersections; i++) {
        printf("Intersection %d:\n", traffic_flow->intersections[i]->id);
        printf("  Name: %s\n", traffic_flow->intersections[i]->name);
        printf("  Num roads: %d\n", traffic_flow->intersections[i]->num_roads);
        printf("  Roads: ");
        for (int j = 0; j < traffic_flow->intersections[i]->num_roads; j++) {
            printf("%d ", traffic_flow->intersections[i]->roads[j]->id);
        }
        printf("\n");
    }
}

int main() {
    traffic_flow_t *traffic_flow = create_traffic_flow(1000, 100, 100);
    print_traffic_flow(traffic_flow);
    destroy_traffic_flow(traffic_flow);
    return 0;
}