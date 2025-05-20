//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 11

typedef struct {
    char name[MAX_NAME_LENGTH];
    int steps;
    float distance; // in kilometers
    float calories; // in kilocalories
    char date[MAX_DATE_LENGTH];
} FitnessEntry;

FitnessEntry entries[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Entry limit reached. Please delete an entry before adding more.\n");
        return;
    }
    
    FitnessEntry newEntry;
    printf("Enter your name: ");
    scanf("%s", newEntry.name);
    
    printf("Enter steps: ");
    scanf("%d", &newEntry.steps);
    
    printf("Enter distance (in km): ");
    scanf("%f", &newEntry.distance);
    
    printf("Enter calories burned: ");
    scanf("%f", &newEntry.calories);
    
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(newEntry.date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    
    entries[entryCount] = newEntry;
    entryCount++;
    printf("Entry added successfully.\n");
}

void deleteEntry() {
    if (entryCount == 0) {
        printf("No entries to delete.\n");
        return;
    }
    
    printf("Enter the entry number to delete (1 to %d): ", entryCount);
    int entryNumber;
    scanf("%d", &entryNumber);
    
    if (entryNumber < 1 || entryNumber > entryCount) {
        printf("Invalid entry number.\n");
        return;
    }
    
    for (int i = entryNumber - 1; i < entryCount - 1; i++) {
        entries[i] = entries[i + 1];
    }
    entryCount--;
    printf("Entry deleted successfully.\n");
}

void displayEntries() {
    if (entryCount == 0) {
        printf("No entries to display.\n");
        return;
    }
    
    printf("Fitness Tracker Entries:\n");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Name: %s\n", entries[i].name);
        printf("Steps: %d\n", entries[i].steps);
        printf("Distance: %.2f km\n", entries[i].distance);
        printf("Calories: %.2f kcal\n", entries[i].calories);
        printf("Date: %s\n", entries[i].date);
        printf("----------------------------------------------------\n");
    }
}

void displaySummary() {
    if (entryCount == 0) {
        printf("No entries to summarize.\n");
        return;
    }
    
    int totalSteps = 0;
    float totalDistance = 0.0;
    float totalCalories = 0.0;

    for (int i = 0; i < entryCount; i++) {
        totalSteps += entries[i].steps;
        totalDistance += entries[i].distance;
        totalCalories += entries[i].calories;
    }

    printf("Fitness Summary:\n");
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Calories: %.2f kcal\n", totalCalories);
}

void showMenu() {
    printf("Fitness Tracker Menu:\n");
    printf("1. Add Entry\n");
    printf("2. Delete Entry\n");
    printf("3. Display Entries\n");
    printf("4. Display Summary\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        showMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                deleteEntry();
                break;
            case 3:
                displayEntries();
                break;
            case 4:
                displaySummary();
                break;
            case 5:
                printf("Exiting Fitness Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}