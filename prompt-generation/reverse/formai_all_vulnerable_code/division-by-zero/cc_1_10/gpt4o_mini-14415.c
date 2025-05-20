//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50

void printShape(int size, char shape_type) {
    if (shape_type == 'T') { // Triangle Shape
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= i; j++) {
                printf("* ");
            }
            printf("\n");
        }
    } 
    else if (shape_type == 'S') { // Square Shape
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                printf("* ");
            }
            printf("\n");
        }
    } 
    else if (shape_type == 'C') { // Circle Approximation
        for (int i = 0; i <= size; i++) {
            for (int j = 0; j <= size; j++) {
                float distance = (i - size/2)*(i - size/2) + (j - size/2)*(j - size/2);
                if (distance <= (size/2)*(size/2)) {
                    printf("* ");
                } else {
                    printf("  ");
                }
            }
            printf("\n");
        }
    }
}

void arithmeticOperations(int a, int b) {
    printf("\nArithmetic Operations:\n");
    printf("Addition: %d + %d = %d\n", a, b, a + b);
    printf("Subtraction: %d - %d = %d\n", a, b, a - b);
    printf("Multiplication: %d * %d = %d\n", a, b, a * b);
    if (b != 0) {
        printf("Division: %d / %d = %.2f\n", a, b, (float)a / b);
    } else {
        printf("Division: Cannot divide by zero!\n");
    }
    printf("Modulus: %d %% %d = %d\n", a, b, a % b);
}

void randomShapesAndArithmetic() {
    int numShapes = 3;
    char shapes[] = {'T', 'S', 'C'};
    int random_shape_index;
    int a, b;
    
    // Make shapes change every iteration
    for (int i = 0; i < numShapes; i++) {
        random_shape_index = rand() % 3;     // Randomly select shape
        int size = rand() % (MAX_SIZE - 1) + 1; // Random size between 1 and MAX_SIZE
        
        printf("Shape #%d: %s (size: %d)\n", i + 1, (random_shape_index == 0) ? "Triangle" : (random_shape_index == 1) ? "Square" : "Circle", size);
        printShape(size, shapes[random_shape_index]);

        // Generate random arithmetic numbers
        a = rand() % 100;  // Random number between 0-99
        b = rand() % 100;  // Random number between 0-99
        arithmeticOperations(a, b);
    }
}

int main() {
    srand(time(0)); // Seed random number generator

    printf("Shape Shifting Arithmetic Program\n");
    printf("===================================\n");
    
    // Loop for three rounds of shapes and arithmetic
    for (int i = 0; i < 3; i++) {
        randomShapesAndArithmetic();
        printf("\n==============================\n");
    }

    printf("Thank you for using the program!\n");
    return 0;
}