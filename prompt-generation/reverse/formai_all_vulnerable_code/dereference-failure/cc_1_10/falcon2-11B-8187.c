//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLUMNS 20
#define MAX_BAGGAGE 1000

int main() {
    char baggage[MAX_BAGGAGE][MAX_ROWS][MAX_COLUMNS];
    int rows = 0;
    int columns = 0;
    int bags_left = 0;

    printf("Welcome to the surrealist airport baggage handling simulation!\n");
    printf("Please input the number of rows and columns in the airport:\n");
    scanf("%d %d", &rows, &columns);
    printf("Please input the number of bags:\n");
    scanf("%d", &bags_left);

    // Create the baggage area
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Enter the location of the bag: ");
            scanf("%s", baggage[i][j]);
        }
    }

    // Simulate the baggage handling process
    printf("Baggage handling process starting...\n");
    while (bags_left > 0) {
        printf("Handling bag: %s\n", baggage[rows - 1][columns - 1]);
        if (strcmp(baggage[rows - 1][columns - 1], "lost") == 0) {
            printf("Baggage lost!\n");
            bags_left--;
        } else {
            printf("Baggage loaded on plane!\n");
            bags_left--;
        }
    }

    // Print the final status
    printf("Baggage handling process completed. Final status:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%s ", baggage[i][j]);
        }
        printf("\n");
    }

    return 0;
}