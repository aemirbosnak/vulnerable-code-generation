//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the data structure for a fitness tracker entry
typedef struct {
    double timestamp;  // Timestamp of the entry in seconds since the epoch
    double distance;   // Distance traveled in meters
    double speed;     // Speed in meters per second
    double calories;  // Calories burned
    double heart_rate; // Heart rate in beats per minute
} fitness_tracker_entry;

// Define the data structure for a fitness tracker
typedef struct {
    int num_entries;  // Number of entries in the tracker
    fitness_tracker_entry *entries; // Array of entries
} fitness_tracker;

// Create a new fitness tracker
fitness_tracker *create_fitness_tracker() {
    fitness_tracker *tracker = malloc(sizeof(fitness_tracker));
    tracker->num_entries = 0;
    tracker->entries = NULL;
    return tracker;
}

// Add an entry to a fitness tracker
void add_entry_to_fitness_tracker(fitness_tracker *tracker, double timestamp, double distance, double speed, double calories, double heart_rate) {
    // Allocate memory for the new entry
    tracker->entries = realloc(tracker->entries, (tracker->num_entries + 1) * sizeof(fitness_tracker_entry));

    // Set the values of the new entry
    tracker->entries[tracker->num_entries].timestamp = timestamp;
    tracker->entries[tracker->num_entries].distance = distance;
    tracker->entries[tracker->num_entries].speed = speed;
    tracker->entries[tracker->num_entries].calories = calories;
    tracker->entries[tracker->num_entries].heart_rate = heart_rate;

    // Increment the number of entries
    tracker->num_entries++;
}

// Get the total distance traveled from a fitness tracker
double get_total_distance_from_fitness_tracker(fitness_tracker *tracker) {
    double total_distance = 0;
    for (int i = 0; i < tracker->num_entries; i++) {
        total_distance += tracker->entries[i].distance;
    }
    return total_distance;
}

// Get the average speed from a fitness tracker
double get_average_speed_from_fitness_tracker(fitness_tracker *tracker) {
    double total_distance = get_total_distance_from_fitness_tracker(tracker);
    double total_time = tracker->entries[tracker->num_entries - 1].timestamp - tracker->entries[0].timestamp;
    return total_distance / total_time;
}

// Get the maximum heart rate from a fitness tracker
double get_maximum_heart_rate_from_fitness_tracker(fitness_tracker *tracker) {
    double max_heart_rate = 0;
    for (int i = 0; i < tracker->num_entries; i++) {
        if (tracker->entries[i].heart_rate > max_heart_rate) {
            max_heart_rate = tracker->entries[i].heart_rate;
        }
    }
    return max_heart_rate;
}

// Get the average heart rate from a fitness tracker
double get_average_heart_rate_from_fitness_tracker(fitness_tracker *tracker) {
    double total_heart_rate = 0;
    for (int i = 0; i < tracker->num_entries; i++) {
        total_heart_rate += tracker->entries[i].heart_rate;
    }
    return total_heart_rate / tracker->num_entries;
}

// Print the data from a fitness tracker to a file
void print_fitness_tracker_data_to_file(fitness_tracker *tracker, FILE *file) {
    for (int i = 0; i < tracker->num_entries; i++) {
        fprintf(file, "%f, %f, %f, %f, %f\n",
                tracker->entries[i].timestamp,
                tracker->entries[i].distance,
                tracker->entries[i].speed,
                tracker->entries[i].calories,
                tracker->entries[i].heart_rate);
    }
}

// Free the memory allocated for a fitness tracker
void free_fitness_tracker(fitness_tracker *tracker) {
    free(tracker->entries);
    free(tracker);
}

int main() {
    // Create a new fitness tracker
    fitness_tracker *tracker = create_fitness_tracker();

    // Add some entries to the fitness tracker
    add_entry_to_fitness_tracker(tracker, 0.0, 0.0, 0.0, 0.0, 0.0);
    add_entry_to_fitness_tracker(tracker, 300.0, 1000.0, 3.33, 100.0, 120.0);
    add_entry_to_fitness_tracker(tracker, 600.0, 2000.0, 3.33, 200.0, 130.0);
    add_entry_to_fitness_tracker(tracker, 900.0, 3000.0, 3.33, 300.0, 140.0);
    add_entry_to_fitness_tracker(tracker, 1200.0, 4000.0, 3.33, 400.0, 150.0);

    // Print the data from the fitness tracker to a file
    FILE *file = fopen("fitness_tracker_data.csv", "w");
    print_fitness_tracker_data_to_file(tracker, file);
    fclose(file);

    // Get the total distance traveled from the fitness tracker
    double total_distance = get_total_distance_from_fitness_tracker(tracker);

    // Get the average speed from the fitness tracker
    double average_speed = get_average_speed_from_fitness_tracker(tracker);

    // Get the maximum heart rate from the fitness tracker
    double maximum_heart_rate = get_maximum_heart_rate_from_fitness_tracker(tracker);

    // Get the average heart rate from the fitness tracker
    double average_heart_rate = get_average_heart_rate_from_fitness_tracker(tracker);

    // Print the results to the console
    printf("Total distance traveled: %f meters\n", total_distance);
    printf("Average speed: %f meters per second\n", average_speed);
    printf("Maximum heart rate: %f beats per minute\n", maximum_heart_rate);
    printf("Average heart rate: %f beats per minute\n", average_heart_rate);

    // Free the memory allocated for the fitness tracker
    free_fitness_tracker(tracker);

    return 0;
}