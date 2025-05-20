//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>

/* Define structures for fitness data */
typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    int reps;
    float weight;
} Exercise;

typedef struct {
    int id;
    char name[30];
    Exercise bench_press;
    Exercise squat;
    Exercise deadlift;
    Date date;
} Workout;

/* Function declarations */
void print_workout(Workout w);
void add_workout(Workout **workouts_ptr, int *num_workouts_ptr);

int main() {
    int num_workouts = 0;
    Workout *workouts = NULL;
    int choice;
    
    printf("Welcome to the Fitness Tracker!\n\n");
    
    do {
        printf("Select an option:\n");
        printf("1. Add a workout\n");
        printf("2. View all workouts\n");
        printf("3. Quit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_workout(&workouts, &num_workouts);
                break;
            case 2:
                for (int i = 0; i < num_workouts; i++) {
                    print_workout(workouts[i]);
                }
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);
    
    /* Free memory allocated for workouts array */
    free(workouts);
    
    return 0;
}

/* Function to print a workout */
void print_workout(Workout w) {
    printf("Workout #%d\n", w.id);
    printf("Name: %s\n", w.name);
    printf("Date: %d/%d/%d\n", w.date.month, w.date.day, w.date.year);
    printf("Bench press: %d reps at %.2f lbs\n", w.bench_press.reps, w.bench_press.weight);
    printf("Squat: %d reps at %.2f lbs\n", w.squat.reps, w.squat.weight);
    printf("Deadlift: %d reps at %.2f lbs\n\n", w.deadlift.reps, w.deadlift.weight);
}

/* Function to add a workout to the array of workouts */
void add_workout(Workout **workouts_ptr, int *num_workouts_ptr) {
    /* Increment number of workouts */
    (*num_workouts_ptr)++;
    
    /* Reallocate memory for workouts array */
    *workouts_ptr = (Workout *)realloc(*workouts_ptr, (*num_workouts_ptr) * sizeof(Workout));
    
    /* Get user input for new workout */
    printf("Enter name: ");
    scanf("%s", (*workouts_ptr)[(*num_workouts_ptr)-1].name);
    printf("Enter date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &(*workouts_ptr)[(*num_workouts_ptr)-1].date.month, &(*workouts_ptr)[(*num_workouts_ptr)-1].date.day, &(*workouts_ptr)[(*num_workouts_ptr)-1].date.year);
    printf("Enter bench press (reps weight): ");
    scanf("%d %f", &(*workouts_ptr)[(*num_workouts_ptr)-1].bench_press.reps, &(*workouts_ptr)[(*num_workouts_ptr)-1].bench_press.weight);
    printf("Enter squat (reps weight): ");
    scanf("%d %f", &(*workouts_ptr)[(*num_workouts_ptr)-1].squat.reps, &(*workouts_ptr)[(*num_workouts_ptr)-1].squat.weight);
    printf("Enter deadlift (reps weight): ");
    scanf("%d %f", &(*workouts_ptr)[(*num_workouts_ptr)-1].deadlift.reps, &(*workouts_ptr)[(*num_workouts_ptr)-1].deadlift.weight);
    
    /* Set workout ID to index of workout in array */
    (*workouts_ptr)[(*num_workouts_ptr)-1].id = (*num_workouts_ptr);
}