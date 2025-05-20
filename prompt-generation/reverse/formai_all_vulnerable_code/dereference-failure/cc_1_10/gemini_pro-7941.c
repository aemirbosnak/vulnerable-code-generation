//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Macros for colors
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"

// Data structures
typedef struct {
    int steps;
    int calories;
    int distance;
    int heart_rate;
    time_t timestamp;
} fitness_data;

typedef struct {
    int id;
    char *name;
    fitness_data *data;
    int data_count;
} user;

// Functions
void print_fitness_data(fitness_data *data) {
    printf("Steps: %d\n", data->steps);
    printf("Calories: %d\n", data->calories);
    printf("Distance: %d\n", data->distance);
    printf("Heart rate: %d\n", data->heart_rate);
    printf("Timestamp: %s\n", ctime(&data->timestamp));
}

void print_user(user *u) {
    printf("ID: %d\n", u->id);
    printf("Name: %s\n", u->name);
    printf("Data count: %d\n", u->data_count);
    for (int i = 0; i < u->data_count; i++) {
        print_fitness_data(&u->data[i]);
        printf("\n");
    }
}

int main() {
    // Create a user
    user u = {
        .id = 1,
        .name = "John Doe",
        .data = NULL,
        .data_count = 0
    };

    // Generate some random fitness data
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        fitness_data data = {
            .steps = rand() % 10000,
            .calories = rand() % 1000,
            .distance = rand() % 100,
            .heart_rate = rand() % 150,
            .timestamp = time(NULL)
        };

        // Add the data to the user's data array
        u.data = realloc(u.data, (u.data_count + 1) * sizeof(fitness_data));
        u.data[u.data_count] = data;
        u.data_count++;
    }

    // Print the user's fitness data
    print_user(&u);

    // Free the user's data array
    free(u.data);

    return 0;
}