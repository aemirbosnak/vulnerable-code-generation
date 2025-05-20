//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M_PI       3.14159265358979323846

typedef struct {
    double latitude;
    double longitude;
} Point;

typedef struct {
    Point start;
    Point end;
} Path;

typedef struct {
    int num_paths;
    Path *paths;
} Map;

Map map;
Point current_position;

void initialize_map() {
    map.num_paths = 5;
    map.paths = malloc(sizeof(Path) * map.num_paths);

    map.paths[0] = (Path) {{37.7868, -122.4096}, {37.7869, -122.4095}};
    map.paths[1] = (Path) {{37.7869, -122.4095}, {37.7870, -122.4094}};
    map.paths[2] = (Path) {{37.7870, -122.4094}, {37.7871, -122.4093}};
    map.paths[3] = (Path) {{37.7871, -122.4093}, {37.7872, -122.4092}};
    map.paths[4] = (Path) {{37.7872, -122.4092}, {37.7873, -122.4091}};

    current_position.latitude = 37.7868;
    current_position.longitude = -122.4096;
}

void navigate_to(Point destination) {
    double dx = destination.longitude - current_position.longitude;
    double dy = destination.latitude - current_position.latitude;
    double bearing = atan2(dy, dx);

    printf("Bearing: %.2f degrees\n", bearing * 180 / M_PI);

    double distance = sqrt(dx * dx + dy * dy);
    printf("Distance: %.2f km\n", distance);
}

int main() {
    initialize_map();
    navigate_to((Point) {37.7873, -122.4091});
    return 0;
}