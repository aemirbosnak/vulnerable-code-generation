//FormAI DATASET v1.0 Category: Data mining ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a struct to hold survivor data
typedef struct survivor {
    int age;
    char gender;
    int location;
    float health;
    float food;
    float water;
    int time_in_bunker;
    int survived;
} survivor;

int main() {
    // Load the dataset from a file
    FILE* fp = fopen("survivor_dataset.csv", "r");
    if (fp == NULL) {
        printf("Error: Unable to load dataset\n");
        return 1;
    }

    // Initialize an array to hold the survivor data
    int num_survivors = 1000;
    survivor* survivors = (survivor*) malloc(num_survivors * sizeof(survivor));

    // Read the data from the file into the array
    char line[256];
    int index = 0;
    while (fgets(line, sizeof(line), fp)) {
        // Parse the line into individual data points
        char* token = strtok(line, ",");
        survivors[index].age = atoi(token);

        token = strtok(NULL, ",");
        survivors[index].gender = token[0];

        token = strtok(NULL, ",");
        survivors[index].location = atoi(token);

        token = strtok(NULL, ",");
        survivors[index].health = atof(token);

        token = strtok(NULL, ",");
        survivors[index].food = atof(token);

        token = strtok(NULL, ",");
        survivors[index].water = atof(token);

        token = strtok(NULL, ",");
        survivors[index].time_in_bunker = atoi(token);

        token = strtok(NULL, ",");
        survivors[index].survived = atoi(token);

        index++;
    }
    fclose(fp);

    // Use a decision tree to predict survival likelihood
    float age_threshold = 40.0;
    int bunker_threshold = 90;

    int num_alive = 0;
    for (int i = 0; i < num_survivors; i++) {
        if (survivors[i].age > age_threshold &&
            survivors[i].time_in_bunker >= bunker_threshold) {
            survivors[i].survived = 1;
            num_alive++;
        } else {
            survivors[i].survived = 0;
        }
    }

    printf("Survival likelihood:\n");
    printf("Age > %.1f and time in bunker >= %d:\n", age_threshold, bunker_threshold);
    printf("%d/%d\n", num_alive, num_survivors);

    free(survivors);
    return 0;
}