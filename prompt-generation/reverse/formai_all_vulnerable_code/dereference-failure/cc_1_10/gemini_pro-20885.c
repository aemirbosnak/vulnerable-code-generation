//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of steps that can be recorded.
#define MAX_STEPS 10000

// Define the structure of a fitness tracker record.
typedef struct {
    int steps;
    int distance;
    int calories;
    time_t timestamp;
} FitnessTrackerRecord;

// Define the structure of a fitness tracker database.
typedef struct {
    FitnessTrackerRecord records[MAX_STEPS];
    int num_records;
} FitnessTrackerDatabase;

// Create a new fitness tracker database.
FitnessTrackerDatabase *create_database() {
    FitnessTrackerDatabase *database = malloc(sizeof(FitnessTrackerDatabase));
    database->num_records = 0;
    return database;
}

// Add a new record to the fitness tracker database.
void add_record(FitnessTrackerDatabase *database, int steps, int distance, int calories) {
    if (database->num_records < MAX_STEPS) {
        database->records[database->num_records].steps = steps;
        database->records[database->num_records].distance = distance;
        database->records[database->num_records].calories = calories;
        database->records[database->num_records].timestamp = time(NULL);
        database->num_records++;
    }
}

// Print the fitness tracker database to the console.
void print_database(FitnessTrackerDatabase *database) {
    for (int i = 0; i < database->num_records; i++) {
        FitnessTrackerRecord record = database->records[i];
        printf("Steps: %d\n", record.steps);
        printf("Distance: %d\n", record.distance);
        printf("Calories: %d\n", record.calories);
        printf("Timestamp: %s\n", ctime(&record.timestamp));
        printf("\n");
    }
}

// Destroy the fitness tracker database.
void destroy_database(FitnessTrackerDatabase *database) {
    free(database);
}

int main() {
    // Create a new fitness tracker database.
    FitnessTrackerDatabase *database = create_database();

    // Add some records to the database.
    add_record(database, 1000, 500, 200);
    add_record(database, 2000, 1000, 400);
    add_record(database, 3000, 1500, 600);

    // Print the database to the console.
    print_database(database);

    // Destroy the database.
    destroy_database(database);

    return 0;
}