//FormAI DATASET v1.0 Category: Error handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {

    printf("Welcome to the post-apocalyptic world!\n");
    
    // Check for errors in memory allocation
    int* array = malloc(sizeof(int)*10);
    if(array == NULL) {
        printf("Error: Insufficient memory to allocate array.\n");
        exit(1);
    }
    
    // Verify proper file opening
    FILE* fp;
    fp = fopen("survivor_stats.txt", "r");
    if(fp == NULL) {
        printf("Error: Unable to open file survivor_stats.txt.\n");
        exit(1);
    }
    
    // Check for invalid input in while loop
    int survivor_count = 0;
    int temp;
    bool valid_input = true;
    while(valid_input) {
        printf("Enter number of survivors: ");
        if(scanf("%d", &temp) != 1) {
            printf("Error: Invalid input. Please enter an integer.\n");
            valid_input = false;
        }
        else {
            if(temp < 0) {
                printf("Error: Invalid input. Number of survivors cannot be negative.\n");
            }
            else {
                 survivor_count = temp;
                 valid_input = false;
            }
        }
    }
    
    // Divide by zero error example
    int result;
    int numerator = 50;
    int denominator = 0;
    if(denominator == 0) {
        printf("Error: Division by zero.\n");
        exit(1);
    }
    else {
        result = numerator / denominator;
    }
    
    // No errors detected
    printf("Congratulations, you survived the code!\n");
    free(array);
    fclose(fp);
    return 0;
}