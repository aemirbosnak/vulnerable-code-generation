//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SPEED 120
#define MIN_SPEED 0
#define MAX_TIME 3600

struct waypoint {
    double latitude;
    double longitude;
};

struct route {
    int num_waypoints;
    struct waypoint *waypoints;
};

struct vehicle {
    double latitude;
    double longitude;
    double speed;
    double heading;
};

void init_vehicle(struct vehicle *veh) {
    veh->latitude = 37.774929;
    veh->longitude = -122.419416;
    veh->speed = 0;
    veh->heading = 0;
}

void update_vehicle(struct vehicle *veh, double dt) {
    veh->latitude += veh->speed * dt * cos(veh->heading);
    veh->longitude += veh->speed * dt * sin(veh->heading);
}

void set_speed(struct vehicle *veh, double speed) {
    veh->speed = speed;
}

void set_heading(struct vehicle *veh, double heading) {
    veh->heading = heading;
}

void init_route(struct route *route, int num_waypoints) {
    route->num_waypoints = num_waypoints;
    route->waypoints = malloc(sizeof(struct waypoint) * num_waypoints);
}

void add_waypoint(struct route *route, int index, double latitude, double longitude) {
    route->waypoints[index].latitude = latitude;
    route->waypoints[index].longitude = longitude;
}

void follow_route(struct vehicle *veh, struct route *route, double dt) {
    int next_waypoint = 0;
    while (next_waypoint < route->num_waypoints) {
        double dx = route->waypoints[next_waypoint].latitude - veh->latitude;
        double dy = route->waypoints[next_waypoint].longitude - veh->longitude;
        double distance = sqrt(dx * dx + dy * dy);
        double heading = atan2(dy, dx);
        if (distance < 1) {
            next_waypoint++;
        }
        set_heading(veh, heading);
        set_speed(veh, MAX_SPEED);
        update_vehicle(veh, dt);
    }
}

int main() {
    srand(time(NULL));

    struct vehicle veh;
    init_vehicle(&veh);

    struct route route;
    init_route(&route, 10);
    add_waypoint(&route, 0, 37.774929, -122.419416);
    add_waypoint(&route, 1, 37.763890, -122.421961);
    add_waypoint(&route, 2, 37.776028, -122.452032);
    add_waypoint(&route, 3, 37.785811, -122.448944);
    add_waypoint(&route, 4, 37.789489, -122.435773);
    add_waypoint(&route, 5, 37.791331, -122.426207);
    add_waypoint(&route, 6, 37.793505, -122.417985);
    add_waypoint(&route, 7, 37.796558, -122.411517);
    add_waypoint(&route, 8, 37.800288, -122.405278);
    add_waypoint(&route, 9, 37.803926, -122.403674);

    double dt = 1;
    for (int i = 0; i < MAX_TIME; i++) {
        update_vehicle(&veh, dt);
        follow_route(&veh, &route, dt);
        printf("t=%d, lat=%f, lon=%f\n", i, veh.latitude, veh.longitude);
    }

    return 0;
}