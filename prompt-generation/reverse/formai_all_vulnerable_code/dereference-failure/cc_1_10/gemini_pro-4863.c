//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constants for the 3D space
#define X_AXIS 0
#define Y_AXIS 1
#define Z_AXIS 2

// Structure to represent a 3D vector
typedef struct Vector3D {
    double x;
    double y;
    double z;
} Vector3D;

// Function to create a new 3D vector
Vector3D *createVector3D(double x, double y, double z) {
    Vector3D *vector = (Vector3D *)malloc(sizeof(Vector3D));
    vector->x = x;
    vector->y = y;
    vector->z = z;
    return vector;
}

// Function to add two 3D vectors
Vector3D *addVectors3D(Vector3D *vector1, Vector3D *vector2) {
    Vector3D *result = createVector3D(0, 0, 0);
    result->x = vector1->x + vector2->x;
    result->y = vector1->y + vector2->y;
    result->z = vector1->z + vector2->z;
    return result;
}

// Function to subtract two 3D vectors
Vector3D *subtractVectors3D(Vector3D *vector1, Vector3D *vector2) {
    Vector3D *result = createVector3D(0, 0, 0);
    result->x = vector1->x - vector2->x;
    result->y = vector1->y - vector2->y;
    result->z = vector1->z - vector2->z;
    return result;
}

// Function to calculate the dot product of two 3D vectors
double dotProduct3D(Vector3D *vector1, Vector3D *vector2) {
    return vector1->x * vector2->x + vector1->y * vector2->y + vector1->z * vector2->z;
}

// Function to calculate the cross product of two 3D vectors
Vector3D *crossProduct3D(Vector3D *vector1, Vector3D *vector2) {
    Vector3D *result = createVector3D(0, 0, 0);
    result->x = vector1->y * vector2->z - vector1->z * vector2->y;
    result->y = vector1->z * vector2->x - vector1->x * vector2->z;
    result->z = vector1->x * vector2->y - vector1->y * vector2->x;
    return result;
}

// Function to calculate the magnitude of a 3D vector
double magnitude3D(Vector3D *vector) {
    return sqrt(vector->x * vector->x + vector->y * vector->y + vector->z * vector->z);
}

// Function to normalize a 3D vector
Vector3D *normalize3D(Vector3D *vector) {
    double magnitude = magnitude3D(vector);
    Vector3D *result = createVector3D(0, 0, 0);
    result->x = vector->x / magnitude;
    result->y = vector->y / magnitude;
    result->z = vector->z / magnitude;
    return result;
}

// Function to print a 3D vector
void printVector3D(Vector3D *vector) {
    printf("<%.2f, %.2f, %.2f>\n", vector->x, vector->y, vector->z);
}

// Main function
int main() {
    // Create two 3D vectors
    Vector3D *vector1 = createVector3D(1, 2, 3);
    Vector3D *vector2 = createVector3D(4, 5, 6);

    // Add the two vectors
    Vector3D *result = addVectors3D(vector1, vector2);
    printf("Sum of the two vectors: ");
    printVector3D(result);

    // Subtract the two vectors
    result = subtractVectors3D(vector1, vector2);
    printf("Difference of the two vectors: ");
    printVector3D(result);

    // Calculate the dot product of the two vectors
    double dotProduct = dotProduct3D(vector1, vector2);
    printf("Dot product of the two vectors: %.2f\n", dotProduct);

    // Calculate the cross product of the two vectors
    result = crossProduct3D(vector1, vector2);
    printf("Cross product of the two vectors: ");
    printVector3D(result);

    // Calculate the magnitude of the first vector
    double magnitude = magnitude3D(vector1);
    printf("Magnitude of the first vector: %.2f\n", magnitude);

    // Normalize the first vector
    result = normalize3D(vector1);
    printf("Normalized first vector: ");
    printVector3D(result);

    return 0;
}