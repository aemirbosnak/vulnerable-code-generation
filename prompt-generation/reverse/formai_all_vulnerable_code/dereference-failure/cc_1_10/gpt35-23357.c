//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORKOUTS 7
#define MAX_LENGTH 50

/* Function to calculate the average of an array of floats */
float get_average(float values[], int length) {
    float sum = 0;
    int i;
    for(i = 0; i < length; i++) {
        sum += values[i];
    }
    return sum / length;
}

/* Struct to represent a workout */
typedef struct Workout {
    char exercise[MAX_LENGTH];
    int sets;
    float weights[MAX_WORKOUTS];
} Workout;

int main() {
    /* Declare an array of workouts */
    Workout workouts[MAX_WORKOUTS];
    int num_workouts = 0;
    int i, j;

    /* Main program loop */
    while(1) {
        /* Print out the current workouts */
        printf("Workouts:\n");
        for(i = 0; i < num_workouts; i++) {
            printf("%d. %s Sets: %d Weights: ", i+1, workouts[i].exercise, workouts[i].sets);
            for(j = 0; j < workouts[i].sets; j++) {
                printf("%.1f ", workouts[i].weights[j]);
            }
            printf("\n");
        }

        /* Get user input */
        printf("\nEnter a new workout (or 'quit' to exit): ");
        char input[MAX_LENGTH];
        fgets(input, sizeof(input), stdin);
        if(input[0] == 'q' && input[1] == 'u' && input[2] == 'i' && input[3] == 't') {
            break;
        }

        /* Parse the user input */
        Workout workout;
        char *token = strtok(input, ",");
        strcpy(workout.exercise, token);
        token = strtok(NULL, ",");
        workout.sets = atoi(token);
        for(i = 0; i < workout.sets; i++) {
            token = strtok(NULL, ",");
            workout.weights[i] = atof(token);
        }

        /* Add the workout to the array */
        workouts[num_workouts++] = workout;

        /* Print out some statistics */
        float total_weights[MAX_WORKOUTS] = {0};
        for(i = 0; i < num_workouts; i++) {
            for(j = 0; j < workouts[i].sets; j++) {
                total_weights[i] += workouts[i].weights[j];
            }
        }
        float average_weights[MAX_WORKOUTS] = {0};
        for(i = 0; i < num_workouts; i++) {
            average_weights[i] = get_average(workouts[i].weights, workouts[i].sets);
        }
        int total_sets = 0;
        for(i = 0; i < num_workouts; i++) {
            total_sets += workouts[i].sets;
        }

        /* Print out the statistics */
        printf("\nTotal workouts: %d\n", num_workouts);
        printf("Total sets: %d\n", total_sets);
        printf("Total weights lifted: ");
        for(i = 0; i < num_workouts; i++) {
            printf("%.1f ", total_weights[i]);
        }
        printf("\n");
        printf("Average weights lifted: ");
        for(i = 0; i < num_workouts; i++) {
            printf("%.1f ", average_weights[i]);
        }
        printf("\n");
    }

    return 0;
}