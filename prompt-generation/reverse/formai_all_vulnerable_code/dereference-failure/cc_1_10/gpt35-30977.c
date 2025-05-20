//FormAI DATASET v1.0 Category: Memory management ; Style: artistic
#include<stdio.h>
#include<stdlib.h>

/*
    This program demonstrates the concept of dynamic memory allocation
    using malloc, realloc, and free in an artistic way.
*/

int main(){

    // Drawing a canvas
    printf("\n\n\t\tWelcome to Memory Painting!\n\n");
    printf("\t\t\t|_____________________|\n");
    printf("\t\t\t|                     |\n");
    printf("\t\t\t|                     |\n");
    printf("\t\t\t|_____________________|\n\n");

    // Allocating memory for an array to store paint colors
    int *paintColors = (int*) malloc(5*sizeof(int));

    // Drawing the paint containers
    printf("Let's start with some colors!\n\n");
    printf("\t\t|\t|\t|\t|\t|\n");
    for(int i=0; i<5; i++){
        paintColors[i] = i*50; // Assigning values to the paint containers
        printf("\t\t|   %d   ", paintColors[i]); // Drawing the paint containers
    }
    printf("|\n");
    printf("\t\t|\t|\t|\t|\t|\n\n");

    // Re-allocating memory to add new paint colors
    printf("Oops, we ran out of colors!\n\n");
    int *newPaintColors = (int*) realloc(paintColors, 8*sizeof(int));

    // Drawing the extended paint containers
    printf("\t\t\t|\t\t|\n");
    printf("\t\t|\t|\t|\t|\t|\n");
    for(int i=0; i<8; i++){
        newPaintColors[i] = i*30; // Assigning values to the paint containers
        if(i<5){
            printf("\t\t|   %d   ", newPaintColors[i]); // Drawing the original paint containers
        }
        else{
            printf("\t\t|\t%d   ", newPaintColors[i]); // Drawing the extended paint containers
        }
    }
    printf("|\n");
    printf("\t\t|\t|\t|\t|\t|\n");
    printf("\t\t\t|\t\t|\n\n");

    // Freeing the memory allocated
    free(newPaintColors);

    // Drawing the final state of the canvas
    printf("\n\n\t\tThank you for using Memory Painting!\n\n");
    printf("\t\t\t|_____________________|\n");
    printf("\t\t\t|                     |\n");
    printf("\t\t\t|                     |\n");
    printf("\t\t\t|___________X_________|\n\n");

    return 0;
}