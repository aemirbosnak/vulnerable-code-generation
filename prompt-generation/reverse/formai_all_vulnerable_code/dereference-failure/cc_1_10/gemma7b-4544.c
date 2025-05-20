//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **fitness_tracker_menu = NULL;
    int fitness_tracker_menu_size = 0;
    int selected_fitness_tracker_option = 0;
    int i = 0;

    fitness_tracker_menu_size = 3;
    fitness_tracker_menu = malloc(fitness_tracker_menu_size * sizeof(char *));

    fitness_tracker_menu[0] = "Track Heart Rate";
    fitness_tracker_menu[1] = "Record Exercise";
    fitness_tracker_menu[2] = "View Stats";

    printf("Welcome to the Fitness Tracker!\n\n");

    for (i = 0; i < fitness_tracker_menu_size; i++)
    {
        printf("%d. %s\n", i + 1, fitness_tracker_menu[i]);
    }

    printf("Please select an option: ");
    scanf("%d", &selected_fitness_tracker_option);

    switch (selected_fitness_tracker_option)
    {
        case 1:
            printf("Enter your current heart rate: ");
            int heart_rate = 0;
            scanf("%d", &heart_rate);
            printf("Your heart rate is: %d\n", heart_rate);
            break;
        case 2:
            printf("Enter the duration of your exercise in minutes: ");
            int exercise_duration = 0;
            scanf("%d", &exercise_duration);
            printf("Enter the intensity of your exercise (1-10): ");
            int exercise_intensity = 0;
            scanf("%d", &exercise_intensity);
            printf("You have completed %d minutes of %s exercise at an intensity of %d.\n", exercise_duration, exercise_intensity == 1 ? "walking" : "running", exercise_intensity);
            break;
        case 3:
            printf("Your total number of steps today: ");
            int steps = 0;
            scanf("%d", &steps);
            printf("Your total distance traveled today (in miles): ");
            float distance = 0.0f;
            scanf("%f", &distance);
            printf("You have taken %d steps and traveled a distance of %.2f miles.\n", steps, distance);
            break;
        default:
            printf("Invalid selection.\n");
    }

    free(fitness_tracker_menu);

    return 0;
}