//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <time.h>

typedef struct {
    time_t start_time;
    time_t end_time;
    double distance;
    double duration;
    double speed;
} activity_log_entry;

typedef struct {
    double total_distance;
    double total_duration;
    double average_speed;
} activity_summary;

activity_log_entry* create_activity_log_entry(time_t start_time, time_t end_time, double distance) {
    activity_log_entry* entry = malloc(sizeof(activity_log_entry));
    entry->start_time = start_time;
    entry->end_time = end_time;
    entry->distance = distance;
    entry->duration = difftime(end_time, start_time);
    entry->speed = entry->distance / entry->duration;
    return entry;
}

activity_summary* calculate_activity_summary(activity_log_entry** entries, size_t num_entries) {
    activity_summary* summary = malloc(sizeof(activity_summary));
    summary->total_distance = 0;
    summary->total_duration = 0;
    summary->average_speed = 0;
    for (size_t i = 0; i < num_entries; i++) {
        summary->total_distance += entries[i]->distance;
        summary->total_duration += entries[i]->duration;
    }
    summary->average_speed = summary->total_distance / summary->total_duration;
    return summary;
}

void print_activity_log_entry(activity_log_entry* entry) {
    printf("Start time: %s", ctime(&entry->start_time));
    printf("End time: %s", ctime(&entry->end_time));
    printf("Distance: %.2f km\n", entry->distance);
    printf("Duration: %.2f hours\n", entry->duration);
    printf("Speed: %.2f km/h\n", entry->speed);
    printf("\n");
}

void print_activity_summary(activity_summary* summary) {
    printf("Total distance: %.2f km\n", summary->total_distance);
    printf("Total duration: %.2f hours\n", summary->total_duration);
    printf("Average speed: %.2f km/h\n", summary->average_speed);
}

int main() {
    // Create an array of activity log entries.
    activity_log_entry* entries[] = {
        create_activity_log_entry(1640995200, 1640998800, 5.0),
        create_activity_log_entry(1641081600, 1641085200, 7.5),
        create_activity_log_entry(1641168000, 1641171600, 10.0),
    };

    // Calculate the activity summary.
    activity_summary* summary = calculate_activity_summary(entries, sizeof(entries) / sizeof(activity_log_entry*));

    // Print the activity log entries.
    for (size_t i = 0; i < sizeof(entries) / sizeof(activity_log_entry*); i++) {
        print_activity_log_entry(entries[i]);
    }

    // Print the activity summary.
    print_activity_summary(summary);

    // Free the allocated memory.
    for (size_t i = 0; i < sizeof(entries) / sizeof(activity_log_entry*); i++) {
        free(entries[i]);
    }
    free(summary);
    return 0;
}