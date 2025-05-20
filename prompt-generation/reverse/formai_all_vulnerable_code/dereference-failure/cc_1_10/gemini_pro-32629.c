//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the structure of a point in 2D space
typedef struct {
  double x;
  double y;
} Point;

// Define the structure of a line segment
typedef struct {
  Point p1;
  Point p2;
} LineSegment;

// Define the structure of a circle
typedef struct {
  Point center;
  double radius;
} Circle;

// Define the structure of a rectangle
typedef struct {
  Point p1; // Bottom left corner
  Point p2; // Top right corner
} Rectangle;

// Define the structure of a triangle
typedef struct {
  Point p1;
  Point p2;
  Point p3;
} Triangle;

// Define the structure of a polygon
typedef struct {
  int num_points;
  Point* points;
} Polygon;

// Function to create a new point
Point* point_create(double x, double y) {
  Point* point = (Point*)malloc(sizeof(Point));
  point->x = x;
  point->y = y;
  return point;
}

// Function to create a new line segment
LineSegment* line_segment_create(Point* p1, Point* p2) {
  LineSegment* line_segment = (LineSegment*)malloc(sizeof(LineSegment));
  line_segment->p1 = *p1;
  line_segment->p2 = *p2;
  return line_segment;
}

// Function to create a new circle
Circle* circle_create(Point* center, double radius) {
  Circle* circle = (Circle*)malloc(sizeof(Circle));
  circle->center = *center;
  circle->radius = radius;
  return circle;
}

// Function to create a new rectangle
Rectangle* rectangle_create(Point* p1, Point* p2) {
  Rectangle* rectangle = (Rectangle*)malloc(sizeof(Rectangle));
  rectangle->p1 = *p1;
  rectangle->p2 = *p2;
  return rectangle;
}

// Function to create a new triangle
Triangle* triangle_create(Point* p1, Point* p2, Point* p3) {
  Triangle* triangle = (Triangle*)malloc(sizeof(Triangle));
  triangle->p1 = *p1;
  triangle->p2 = *p2;
  triangle->p3 = *p3;
  return triangle;
}

// Function to create a new polygon
Polygon* polygon_create(int num_points, Point* points) {
  Polygon* polygon = (Polygon*)malloc(sizeof(Polygon));
  polygon->num_points = num_points;
  polygon->points = (Point*)malloc(sizeof(Point) * num_points);
  for (int i = 0; i < num_points; i++) {
    polygon->points[i] = points[i];
  }
  return polygon;
}

// Function to free the memory allocated for a point
void point_free(Point* point) {
  free(point);
}

// Function to free the memory allocated for a line segment
void line_segment_free(LineSegment* line_segment) {
  free(line_segment);
}

// Function to free the memory allocated for a circle
void circle_free(Circle* circle) {
  free(circle);
}

// Function to free the memory allocated for a rectangle
void rectangle_free(Rectangle* rectangle) {
  free(rectangle);
}

// Function to free the memory allocated for a triangle
void triangle_free(Triangle* triangle) {
  free(triangle);
}

// Function to free the memory allocated for a polygon
void polygon_free(Polygon* polygon) {
  free(polygon->points);
  free(polygon);
}

// Function to print a point
void point_print(Point* point) {
  printf("(%f, %f)", point->x, point->y);
}

// Function to print a line segment
void line_segment_print(LineSegment* line_segment) {
  printf("Line segment: ");
  point_print(&line_segment->p1);
  printf(" -> ");
  point_print(&line_segment->p2);
  printf("\n");
}

// Function to print a circle
void circle_print(Circle* circle) {
  printf("Circle: center = ");
  point_print(&circle->center);
  printf(", radius = %f\n", circle->radius);
}

// Function to print a rectangle
void rectangle_print(Rectangle* rectangle) {
  printf("Rectangle: ");
  point_print(&rectangle->p1);
  printf(" -> ");
  point_print(&rectangle->p2);
  printf("\n");
}

// Function to print a triangle
void triangle_print(Triangle* triangle) {
  printf("Triangle: ");
  point_print(&triangle->p1);
  printf(", ");
  point_print(&triangle->p2);
  printf(", ");
  point_print(&triangle->p3);
  printf("\n");
}

// Function to print a polygon
void polygon_print(Polygon* polygon) {
  printf("Polygon: ");
  for (int i = 0; i < polygon->num_points; i++) {
    point_print(&polygon->points[i]);
    if (i < polygon->num_points - 1) {
      printf(", ");
    }
  }
  printf("\n");
}

// Main function
int main() {
  // Create a point
  Point* point = point_create(1.0, 2.0);

  // Create a line segment
  LineSegment* line_segment = line_segment_create(point, point_create(3.0, 4.0));

  // Create a circle
  Circle* circle = circle_create(point, 5.0);

  // Create a rectangle
  Rectangle* rectangle = rectangle_create(point, point_create(6.0, 7.0));

  // Create a triangle
  Triangle* triangle = triangle_create(point, point_create(8.0, 9.0), point_create(10.0, 11.0));

  // Create a polygon
  Polygon* polygon = polygon_create(4, (Point[]){*point, *point_create(12.0, 13.0), *point_create(14.0, 15.0), *point_create(16.0, 17.0)});

  // Print the point
  printf("Point: ");
  point_print(point);
  printf("\n");

  // Print the line segment
  line_segment_print(line_segment);

  // Print the circle
  circle_print(circle);

  // Print the rectangle
  rectangle_print(rectangle);

  // Print the triangle
  triangle_print(triangle);

  // Print the polygon
  polygon_print(polygon);

  // Free the memory allocated for the point
  point_free(point);

  // Free the memory allocated for the line segment
  line_segment_free(line_segment);

  // Free the memory allocated for the circle
  circle_free(circle);

  // Free the memory allocated for the rectangle
  rectangle_free(rectangle);

  // Free the memory allocated for the triangle
  triangle_free(triangle);

  // Free the memory allocated for the polygon
  polygon_free(polygon);

  return 0;
}