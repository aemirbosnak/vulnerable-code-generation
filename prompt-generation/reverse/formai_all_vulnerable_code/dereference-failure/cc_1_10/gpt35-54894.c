//FormAI DATASET v1.0 Category: Database querying ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define structures
typedef struct {
    int id;
    char name[30];
    double x;
    double y;
} Point;

typedef struct {
    int id;
    int point1_id;
    int point2_id;
    double distance;
} Line;

// Define a function to calculate the distance between two points
double distance(Point p1, Point p2)
{
    double x_diff = p2.x - p1.x;
    double y_diff = p2.y - p1.y;
    return sqrt(x_diff * x_diff + y_diff * y_diff);
}

int main()
{
    // Declare variables
    int num_points, num_lines, i, j;
    Point *points;
    Line *lines;

    // Get user input
    printf("Enter the number of points: ");
    scanf("%d", &num_points);

    printf("Enter the number of lines: ");
    scanf("%d", &num_lines);

    // Allocate memory for arrays
    points = (Point*) malloc(num_points * sizeof(Point));
    lines = (Line*) malloc(num_lines * sizeof(Line));

    // Populate points array
    for (i = 0; i < num_points; i++) {
        printf("Enter point %d (id, name, x, y): ", i+1);
        scanf("%d%s%lf%lf", &points[i].id, points[i].name, &points[i].x, &points[i].y);
    }

    // Populate lines array
    for (i = 0; i < num_lines; i++) {
        printf("Enter line %d (id, point1_id, point2_id): ", i+1);
        scanf("%d%d%d", &lines[i].id, &lines[i].point1_id, &lines[i].point2_id);

        // Calculate distance between points and store in lines array
        Point point1, point2;
        for (j = 0; j < num_points; j++) {
            if (points[j].id == lines[i].point1_id) {
                point1 = points[j];
            } else if (points[j].id == lines[i].point2_id) {
                point2 = points[j];
            }
        }
        lines[i].distance = distance(point1, point2);
    }

    // Query the database for lines longer than a user-inputted distance
    double query_distance;
    printf("Enter a minimum distance: ");
    scanf("%lf", &query_distance);

    printf("Lines longer than %lf:\n", query_distance);
    for (i = 0; i < num_lines; i++) {
        if (lines[i].distance > query_distance) {
            printf("Line %d from point %d to point %d is %lf units long.\n", lines[i].id, lines[i].point1_id, lines[i].point2_id, lines[i].distance);
        }
    }

    // Deallocate memory
    free(points);
    free(lines);

    return 0;
}