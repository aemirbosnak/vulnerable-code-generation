//FormAI DATASET v1.0 Category: Digital Diary ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Define structure of the digital diary
typedef struct {
    int day;
    int month;
    int year;
    char* message;
} DiaryEntry;

// Function prototypes
void addEntry(DiaryEntry** diary, int* size, int day, int month, int year, char* message);
void viewEntries(DiaryEntry* diary, int size);

// Main function
int main() {
    DiaryEntry* diary = NULL;
    int size = 0;
    int choice, day, month, year;
    char message[100];

    while(1) {
        printf("\n");
        printf("Digital Diary\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter date (dd/mm/yyyy): ");
                scanf("%d/%d/%d", &day, &month, &year);
                printf("Enter message: ");
                scanf(" %[^\n]s", message);
                addEntry(&diary, &size, day, month, year, message);
                break;
            case 2:
                viewEntries(diary, size);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Function to add a new entry to the diary
void addEntry(DiaryEntry** diary, int* size, int day, int month, int year, char* message) {
    // Increase the size of the diary by 1
    *size += 1;
    *diary = (DiaryEntry*) realloc(*diary, sizeof(DiaryEntry) * (*size));
    
    // Assign values to the new entry
    (*diary)[*size - 1].day = day;
    (*diary)[*size - 1].month = month;
    (*diary)[*size - 1].year = year;
    (*diary)[*size - 1].message = message;
}

// Function to view all the entries in the diary
void viewEntries(DiaryEntry* diary, int size) {
    if(size == 0) {
        printf("No entries!\n");
        return;
    }

    printf("\n");
    printf("Digital Diary Entries\n");
    printf("-------------------------------------------------\n");
    printf("Date\t\t\tMessage\n");
    printf("-------------------------------------------------\n");

    for(int i = 0; i < size; i++) {
        printf("%d/%d/%d\t\t%s\n", diary[i].day, diary[i].month, diary[i].year, diary[i].message);
    }

    printf("-------------------------------------------------\n");
}