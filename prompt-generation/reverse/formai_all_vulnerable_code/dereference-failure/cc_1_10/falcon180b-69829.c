//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char exercise[50];
    int duration;
    int calories;
} Entry;

void add_entry(Entry *entries, int count, char *exercise, int duration, int calories) {
    if (count >= MAX_ENTRIES) {
        printf("Cannot add more entries. Maximum limit reached.\n");
        return;
    }

    strcpy(entries[count].exercise, exercise);
    entries[count].duration = duration;
    entries[count].calories = calories;
    count++;
}

void display_entries(Entry *entries, int count) {
    printf("Total entries: %d\n", count);

    for (int i = 0; i < count; i++) {
        printf("%d. %s - %d minutes - %d calories\n", i+1, entries[i].exercise, entries[i].duration, entries[i].calories);
    }
}

void delete_entry(Entry *entries, int count, int index) {
    if (index >= count) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index; i < count-1; i++) {
        strcpy(entries[i].exercise, entries[i+1].exercise);
        entries[i].duration = entries[i+1].duration;
        entries[i].calories = entries[i+1].calories;
    }

    count--;
}

int main() {
    Entry entries[MAX_ENTRIES];
    int count = 0;

    while (1) {
        printf("1. Add entry\n2. Display entries\n3. Delete entry\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char exercise[50];
                int duration, calories;
                printf("Enter exercise: ");
                scanf("%s", exercise);
                printf("Enter duration in minutes: ");
                scanf("%d", &duration);
                printf("Enter calories burned: ");
                scanf("%d", &calories);
                add_entry(entries, count, exercise, duration, calories);
                break;
            }
            case 2: {
                display_entries(entries, count);
                break;
            }
            case 3: {
                int index;
                printf("Enter index of entry to delete: ");
                scanf("%d", &index);
                delete_entry(entries, count, index);
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}