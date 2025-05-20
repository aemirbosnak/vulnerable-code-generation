//FormAI DATASET v1.0 Category: Fractal Generation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
 * This program generates a fractal called the "Dragon Curve" using recursion.
 * The program takes an integer input from the user representing the number of iterations 
 * to generate the fractal.
 */

void dragonCurve(int iterations, char* curve) {
    if(iterations == 0) { // base case
        return;
    }

    // save the current curve to a temporary variable
    char* tempCurve = (char*) malloc(sizeof(char) * strlen(curve) * 2);
    strcpy(tempCurve, curve);

    // reverse the order of the characters in the curve
    for(int i = 0; i < strlen(tempCurve); i++) {
        if(tempCurve[i] == 'L') {
            tempCurve[i] = 'R';
        } else if(tempCurve[i] == 'R') {
            tempCurve[i] = 'L';
        }
    }

    // add the reverse of the curve to itself
    strcat(curve, "R");
    strcat(curve, tempCurve);

    // free the temporary variable
    free(tempCurve);

    // recursive call with one less iteration
    dragonCurve(iterations - 1, curve);
}

int main() {
    // get user input
    int iterations;
    printf("Enter the number of iterations to generate the fractal: ");
    scanf("%d", &iterations);

    // allocate memory for the curve string
    char* curve = (char*) malloc(sizeof(char));
    strcpy(curve, "R");

    // generate the fractal
    dragonCurve(iterations, curve);

    // print the fractal
    printf("%s\n", curve);

    // free allocated memory
    free(curve);

    return 0;
}