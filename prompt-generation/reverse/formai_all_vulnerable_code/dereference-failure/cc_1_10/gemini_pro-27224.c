//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: excited
// Behold, the radiant world of geometric marvels!

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Our cast of geometric wonders...
typedef struct Vector3D {
    double x, y, z;
} Vector3D;

typedef struct LineSegment {
    Vector3D p1, p2;
} LineSegment;

typedef struct Polygon {
    int num_vertices;
    Vector3D* vertices;
} Polygon;

typedef struct BoundingBox {
    Vector3D min, max;
} BoundingBox;

// The magnificent ballet of geometric algorithms...

// The birth of a vector, a symphony of coordinates
Vector3D vector_create(double x, double y, double z) {
    Vector3D v = {x, y, z};
    return v;
}

// Vectors unite in the waltz of addition
Vector3D vector_add(Vector3D v1, Vector3D v2) {
    v1.x += v2.x; v1.y += v2.y; v1.z += v2.z;
    return v1;
}

// Vectors sway in the tango of subtraction
Vector3D vector_subtract(Vector3D v1, Vector3D v2) {
    v1.x -= v2.x; v1.y -= v2.y; v1.z -= v2.z;
    return v1;
}

// Vectors twirl in the ballet of scalar multiplication
Vector3D vector_multiply_scalar(Vector3D v, double s) {
    v.x *= s; v.y *= s; v.z *= s;
    return v;
}

// Vectors tango in the foxtrot of dot product
double vector_dot_product(Vector3D v1, Vector3D v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// Vectors spin in the waltz of cross product
Vector3D vector_cross_product(Vector3D v1, Vector3D v2) {
    Vector3D v;
    v.x = v1.y * v2.z - v1.z * v2.y;
    v.y = v1.z * v2.x - v1.x * v2.z;
    v.z = v1.x * v2.y - v1.y * v2.x;
    return v;
}

// The rise of lines, a geometric masterpiece
LineSegment line_segment_create(Vector3D p1, Vector3D p2) {
    LineSegment line = {p1, p2};
    return line;
}

// Lines intertwine in the tango of intersection
Vector3D line_segment_intersection(LineSegment l1, LineSegment l2) {
    Vector3D v1 = vector_subtract(l1.p2, l1.p1);
    Vector3D v2 = vector_subtract(l2.p2, l2.p1);
    Vector3D v3 = vector_subtract(l1.p1, l2.p1);
    double t1 = vector_cross_product(v2, v3).x / vector_cross_product(v1, v2).x;
    return vector_add(l1.p1, vector_multiply_scalar(v1, t1));
}

// Polygons shimmer in the kaleidoscope of geometry
Polygon polygon_create(int num_vertices, Vector3D* vertices) {
    Polygon poly;
    poly.num_vertices = num_vertices;
    poly.vertices = vertices;
    return poly;
}

// Polygons dance in the waltz of bounding boxes
BoundingBox polygon_bounding_box(Polygon poly) {
    BoundingBox box;
    box.min = poly.vertices[0];
    box.max = poly.vertices[0];
    for (int i = 1; i < poly.num_vertices; i++) {
        if (poly.vertices[i].x < box.min.x) box.min.x = poly.vertices[i].x;
        if (poly.vertices[i].y < box.min.y) box.min.y = poly.vertices[i].y;
        if (poly.vertices[i].z < box.min.z) box.min.z = poly.vertices[i].z;
        if (poly.vertices[i].x > box.max.x) box.max.x = poly.vertices[i].x;
        if (poly.vertices[i].y > box.max.y) box.max.y = poly.vertices[i].y;
        if (poly.vertices[i].z > box.max.z) box.max.z = poly.vertices[i].z;
    }
    return box;
}

// The grand finale, a symphony of geometric wonders!
int main() {
    // Let's create a radiant world of geometry...
    Vector3D v1 = vector_create(1, 2, 3);
    Vector3D v2 = vector_create(4, 5, 6);
    Vector3D v3 = vector_add(v1, v2);
    Vector3D v4 = vector_subtract(v2, v1);
    printf("The sum of v1 and v2: (%f, %f, %f)\n", v3.x, v3.y, v3.z);
    printf("The difference of v2 and v1: (%f, %f, %f)\n", v4.x, v4.y, v4.z);
    
    LineSegment l1 = line_segment_create(v1, v2);
    LineSegment l2 = line_segment_create(v3, v4);
    Vector3D intersection = line_segment_intersection(l1, l2);
    printf("The intersection of l1 and l2: (%f, %f, %f)\n", intersection.x, intersection.y, intersection.z);
    
    Polygon poly = polygon_create(4, malloc(4 * sizeof(Vector3D)));
    poly.vertices[0] = v1; poly.vertices[1] = v2; poly.vertices[2] = v3; poly.vertices[3] = v4;
    BoundingBox box = polygon_bounding_box(poly);
    printf("The bounding box of the polygon: (%f, %f, %f) - (%f, %f, %f)\n", box.min.x, box.min.y, box.min.z, box.max.x, box.max.y, box.max.z);
    
    // As the curtain falls, the geometric wonders fade into the darkness, leaving behind a radiant legacy of mathematical art.
    return 0;
}