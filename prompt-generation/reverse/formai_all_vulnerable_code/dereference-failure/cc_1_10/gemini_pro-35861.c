//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int num_points;
} Path;

typedef struct {
    Path *paths;
    int num_paths;
} RobotMovement;

RobotMovement *create_robot_movement() {
    RobotMovement *robot_movement = malloc(sizeof(RobotMovement));
    robot_movement->paths = NULL;
    robot_movement->num_paths = 0;
    return robot_movement;
}

void destroy_robot_movement(RobotMovement *robot_movement) {
    for (int i = 0; i < robot_movement->num_paths; i++) {
        free(robot_movement->paths[i].points);
    }
    free(robot_movement->paths);
    free(robot_movement);
}

Path *create_path() {
    Path *path = malloc(sizeof(Path));
    path->points = NULL;
    path->num_points = 0;
    return path;
}

void destroy_path(Path *path) {
    free(path->points);
    free(path);
}

void add_point_to_path(Path *path, Point point) {
    path->points = realloc(path->points, (path->num_points + 1) * sizeof(Point));
    path->points[path->num_points] = point;
    path->num_points++;
}

void add_path_to_robot_movement(RobotMovement *robot_movement, Path *path) {
    robot_movement->paths = realloc(robot_movement->paths, (robot_movement->num_paths + 1) * sizeof(Path));
    robot_movement->paths[robot_movement->num_paths] = *path;
    robot_movement->num_paths++;
}

void print_robot_movement(RobotMovement *robot_movement) {
    for (int i = 0; i < robot_movement->num_paths; i++) {
        Path path = robot_movement->paths[i];
        printf("Path %d:\n", i + 1);
        for (int j = 0; j < path.num_points; j++) {
            Point point = path.points[j];
            printf("  Point %d: (%d, %d)\n", j + 1, point.x, point.y);
        }
    }
}

int main() {
    RobotMovement *robot_movement = create_robot_movement();

    Path *path1 = create_path();
    add_point_to_path(path1, (Point){0, 0});
    add_point_to_path(path1, (Point){10, 10});
    add_point_to_path(path1, (Point){20, 20});
    add_path_to_robot_movement(robot_movement, path1);

    Path *path2 = create_path();
    add_point_to_path(path2, (Point){0, 0});
    add_point_to_path(path2, (Point){10, 0});
    add_point_to_path(path2, (Point){10, 10});
    add_point_to_path(path2, (Point){0, 10});
    add_path_to_robot_movement(robot_movement, path2);

    print_robot_movement(robot_movement);

    destroy_robot_movement(robot_movement);

    return 0;
}