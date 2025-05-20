//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random time in the format "HH:MM:SS"
char *random_time() {
    int hours = random_number(0, 23);
    int minutes = random_number(0, 59);
    int seconds = random_number(0, 59);

    char *time = malloc(9);
    sprintf(time, "%02d:%02d:%02d", hours, minutes, seconds);

    return time;
}

// Function to generate a random activity
char *random_activity() {
    char *activities[] = {"Walking", "Running", "Cycling", "Swimming", "Yoga", "Pilates", "Strength training", "Cardio"};

    int index = random_number(0, 7);

    return activities[index];
}

// Function to generate a random duration in the format "HH:MM:SS"
char *random_duration() {
    int hours = random_number(0, 2);
    int minutes = random_number(0, 59);
    int seconds = random_number(0, 59);

    char *duration = malloc(9);
    sprintf(duration, "%02d:%02d:%02d", hours, minutes, seconds);

    return duration;
}

// Function to generate a random distance in kilometers
float random_distance() {
    return random_number(0, 100) / 10.0;
}

// Function to generate a random calories burned value
int random_calories_burned() {
    return random_number(0, 1000);
}

// Function to generate a random heart rate
int random_heart_rate() {
    return random_number(60, 220);
}

// Function to generate a random fitness tracker entry
struct FitnessTrackerEntry {
    char *time;
    char *activity;
    char *duration;
    float distance;
    int calories_burned;
    int heart_rate;
};

struct FitnessTrackerEntry random_fitness_tracker_entry() {
    struct FitnessTrackerEntry entry;

    entry.time = random_time();
    entry.activity = random_activity();
    entry.duration = random_duration();
    entry.distance = random_distance();
    entry.calories_burned = random_calories_burned();
    entry.heart_rate = random_heart_rate();

    return entry;
}

// Function to print a fitness tracker entry
void print_fitness_tracker_entry(struct FitnessTrackerEntry entry) {
    printf("Time: %s\n", entry.time);
    printf("Activity: %s\n", entry.activity);
    printf("Duration: %s\n", entry.duration);
    printf("Distance: %.1f km\n", entry.distance);
    printf("Calories burned: %d\n", entry.calories_burned);
    printf("Heart rate: %d bpm\n\n", entry.heart_rate);
}

// Function to generate a random fitness tracker log
struct FitnessTrackerLog {
    struct FitnessTrackerEntry *entries;
    int num_entries;
};

struct FitnessTrackerLog random_fitness_tracker_log(int num_entries) {
    struct FitnessTrackerLog log;

    log.entries = malloc(sizeof(struct FitnessTrackerEntry) * num_entries);
    log.num_entries = num_entries;

    for (int i = 0; i < num_entries; i++) {
        log.entries[i] = random_fitness_tracker_entry();
    }

    return log;
}

// Function to print a fitness tracker log
void print_fitness_tracker_log(struct FitnessTrackerLog log) {
    for (int i = 0; i < log.num_entries; i++) {
        print_fitness_tracker_entry(log.entries[i]);
    }
}

// Function to free the memory allocated for a fitness tracker log
void free_fitness_tracker_log(struct FitnessTrackerLog log) {
    for (int i = 0; i < log.num_entries; i++) {
        free(log.entries[i].time);
        free(log.entries[i].activity);
        free(log.entries[i].duration);
    }

    free(log.entries);
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a random fitness tracker log with 10 entries
    struct FitnessTrackerLog log = random_fitness_tracker_log(10);

    // Print the fitness tracker log
    print_fitness_tracker_log(log);

    // Free the memory allocated for the fitness tracker log
    free_fitness_tracker_log(log);

    return 0;
}