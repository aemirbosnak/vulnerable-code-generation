//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the diary structure
typedef struct {
    char date[10];  // Date of the entry (YYYY-MM-DD)
    char entry[50]; // Entry text
    int happiness;  // Happiness rating (1-5)
} diary_t;

// Define an array to store the diary entries
diary_t diary[10];

// Function to add a new diary entry
void add_entry(const char *date, const char *entry, int happiness) {
    diary_t *new_entry = malloc(sizeof(diary_t));
    strcpy(new_entry->date, date);
    strcpy(new_entry->entry, entry);
    new_entry->happiness = happiness;
    // Add the new entry to the end of the array
    int i = sizeof(diary) / sizeof(diary_t) - 1;
    while (i > 0 && strcmp(diary[i].date, date) < 0) {
        i--;
    }
    memmove(&diary[i + 1], &diary[i], sizeof(diary_t) * (i + 1));
    diary[i] = *new_entry;
}

// Function to display the diary entries
void display_entries() {
    for (int i = 0; i < sizeof(diary) / sizeof(diary_t); i++) {
        printf("%s (%d) - %s\n", diary[i].date, diary[i].happiness, diary[i].entry);
    }
}

// Function to calculate the average happiness
double average_happiness() {
    double total_happiness = 0;
    for (int i = 0; i < sizeof(diary) / sizeof(diary_t); i++) {
        total_happiness += diary[i].happiness;
    }
    return total_happiness / sizeof(diary_t);
}

int main() {
    // Initialize the diary array
    for (int i = 0; i < sizeof(diary) / sizeof(diary_t); i++) {
        diary[i].date[0] = '\0';
        diary[i].entry[0] = '\0';
        diary[i].happiness = 0;
    }

    // Add some sample diary entries
    add_entry("2022-01-01", "Woke up feeling refreshed and ready to tackle the day!", 5);
    add_entry("2022-01-02", "Had a productive day at work, but my evening commute was a nightmare. 😒", 3);
    add_entry("2022-01-03", "Spent the day binge-watching my favorite TV show and eating junk food. 🍿🍔", 2);
    add_entry("2022-01-04", "Went on a nice walk in the park and had a great conversation with a friend. 🌳👥", 4);
    add_entry("2022-01-05", "Had a tough day at work, but managed to get everything done on time. 💪🕒", 4);

    // Display the diary entries
    display_entries();

    // Calculate the average happiness
    double avg_happiness = average_happiness();
    printf("Average happiness: %f\n", avg_happiness);

    return 0;
}