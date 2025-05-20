//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Define the struct for a fitness entry
typedef struct {
    char* activity;
    int duration;
    time_t timestamp;
} fitness_entry;

//Function to print a fitness entry
void print_entry(fitness_entry entry) {
    printf("Activity: %s, Duration: %d minutes, Timestamp: %s\n", entry.activity, entry.duration, ctime(&entry.timestamp));
}

//Function to compare two fitness entries based on their timestamps
int compare_entries(const void* a, const void* b) {
    fitness_entry* entryA = (fitness_entry*)a;
    fitness_entry* entryB = (fitness_entry*)b;

    return difftime(entryB->timestamp, entryA->timestamp);
}

//Main function
int main() {
    //Initialize variables
    int num_entries;
    fitness_entry* entries = NULL;

    //Get number of entries from user
    printf("Enter the number of fitness entries: ");
    scanf("%d", &num_entries);

    //Allocate memory for entries
    entries = (fitness_entry*)malloc(num_entries * sizeof(fitness_entry));

    //Get entries from user
    for (int i = 0; i < num_entries; i++) {
        printf("Enter activity for entry %d: ", i+1);
        scanf("%s", entries[i].activity);

        printf("Enter duration (in minutes) for entry %d: ", i+1);
        scanf("%d", &entries[i].duration);

        entries[i].timestamp = time(NULL);
    }

    //Sort entries by timestamp
    qsort(entries, num_entries, sizeof(fitness_entry), compare_entries);

    //Print entries
    printf("Fitness entries sorted by timestamp:\n");
    for (int i = 0; i < num_entries; i++) {
        print_entry(entries[i]);
    }

    //Free memory
    free(entries);

    return 0;
}