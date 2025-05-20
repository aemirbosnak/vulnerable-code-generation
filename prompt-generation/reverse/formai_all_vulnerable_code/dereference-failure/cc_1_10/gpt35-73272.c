//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for each exercise entry
typedef struct ExerciseEntry {
    int exercise_type;
    double duration;
    double intensity;
    struct ExerciseEntry* next;
} ExerciseEntry;

// Define a struct for the fitness tracker
typedef struct FitnessTracker {
    ExerciseEntry* head;
    int num_entries;
} FitnessTracker;

// Create a function to add a new exercise entry to the fitness tracker
int addExerciseEntry(FitnessTracker* tracker, int exercise_type, double duration, double intensity) {
    ExerciseEntry* new_entry = (ExerciseEntry*) malloc(sizeof(ExerciseEntry));
    new_entry->exercise_type = exercise_type;
    new_entry->duration = duration;
    new_entry->intensity = intensity;
    
    // Check if the head is null, if so add the new entry as the head
    if (tracker->head == NULL) {
        tracker->head = new_entry;
    } else {
        // If the head is not null, loop through the entries to find the last one
        ExerciseEntry* ptr = tracker->head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_entry;
    }
    tracker->num_entries++;
    
    return 0;
}

// Create a function to print all exercise entries in the fitness tracker
void printExerciseEntries(FitnessTracker* tracker) {
    int i = 1;
    printf("Exercise Entries for Tracker:\n");
    ExerciseEntry* ptr = tracker->head;
    while (ptr != NULL) {
        printf("Entry #%d: Exercise Type %d, Duration %.2lf minutes, Intensity %.2lf\n",
               i, ptr->exercise_type, ptr->duration, ptr->intensity);
        ptr = ptr->next;
        i++;
    }
}

int main() {
    // Create a new fitness tracker
    FitnessTracker* tracker = (FitnessTracker*) malloc(sizeof(FitnessTracker));
    tracker->head = NULL;
    tracker->num_entries = 0;
    
    // Add some dummy exercise entries
    addExerciseEntry(tracker, 1, 30.0, 5.0);
    addExerciseEntry(tracker, 2, 45.0, 7.5);
    addExerciseEntry(tracker, 3, 60.0, 10.0);
    
    // Print all exercise entries
    printExerciseEntries(tracker);

    // Free the fitness tracker memory
    ExerciseEntry* ptr = tracker->head;
    while (ptr != NULL) {
        ExerciseEntry* tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
    free(tracker);
    
    return 0;
}