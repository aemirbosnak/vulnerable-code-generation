//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Exercise {
    char name[50];
    int duration;
    int calories;
};

void addExercise(struct Exercise *exercise, int num) {
    printf("Enter exercise name: ");
    scanf("%s", exercise[num].name);
    printf("Enter exercise duration in seconds: ");
    scanf("%d", &exercise[num].duration);
    printf("Enter exercise calories burned: ");
    scanf("%d", &exercise[num].calories);
}

void displayExercises(struct Exercise *exercise, int num) {
    printf("\nExercises:\n");
    for (int i = 0; i < num; i++) {
        printf("%s - %d seconds - %d calories\n", exercise[i].name, exercise[i].duration, exercise[i].calories);
    }
}

void startWorkout(struct Exercise *exercise, int num) {
    int choice;
    printf("\nChoose an exercise:\n");
    for (int i = 0; i < num; i++) {
        printf("%d. %s\n", i+1, exercise[i].name);
    }
    scanf("%d", &choice);
    int duration = exercise[choice-1].duration;
    int calories = exercise[choice-1].calories;
    time_t start, end;
    time(&start);
    do {
        printf("\n%s for %d seconds...\n", exercise[choice-1].name, duration);
        fflush(stdout);
        time(&end);
        duration--;
    } while (difftime(end, start) < duration);
    printf("\n%s complete! You burned %d calories.\n", exercise[choice-1].name, calories);
}

int main() {
    int num;
    printf("How many exercises do you want to add? ");
    scanf("%d", &num);
    struct Exercise exercise[num];
    for (int i = 0; i < num; i++) {
        addExercise(exercise, num);
    }
    printf("\nWorkout complete! ");
    for (int i = 0; i < num; i++) {
        printf("\n%s - %d seconds - %d calories\n", exercise[i].name, exercise[i].duration, exercise[i].calories);
    }
    return 0;
}