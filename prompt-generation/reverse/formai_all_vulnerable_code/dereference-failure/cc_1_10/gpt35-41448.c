//FormAI DATASET v1.0 Category: Digital Diary ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 200

// structure for each diary entry
typedef struct {
    char date[MAX_LENGTH];
    char content[MAX_LENGTH];
} Entry;

// function prototypes
void addEntry(Entry* diary, int* numEntries);
void deleteEntry(Entry* diary, int* numEntries);
void viewEntries(Entry* diary, int numEntries);

int main() {
    Entry diary[MAX_ENTRIES];
    int numEntries = 0;
    int choice;

    do {
        printf("1. Add new entry\n");
        printf("2. Delete an entry\n");
        printf("3. View all entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addEntry(diary, &numEntries);
                break;
            case 2:
                deleteEntry(diary, &numEntries);
                break;
            case 3:
                viewEntries(diary, numEntries);
                break;
            case 4:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 4);

    return 0;
}

void addEntry(Entry* diary, int* numEntries) {
    if(*numEntries == MAX_ENTRIES) {
        printf("Diary is full. Cannot add any more entries.\n");
        return;
    }

    char date[MAX_LENGTH];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    snprintf(date, sizeof(date), "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    printf("Enter diary entry content (max %d characters): ", MAX_LENGTH);
    scanf("%s", diary[*numEntries].content);

    strncpy(diary[*numEntries].date, date, MAX_LENGTH);
    ++(*numEntries);

    printf("Diary entry added successfully.\n");
}

void deleteEntry(Entry* diary, int* numEntries) {
    if(*numEntries == 0) {
        printf("Diary is empty. Nothing to delete.\n");
        return;
    }
    printf("Enter the index of the entry you want to delete (1 - %d): ", *numEntries);
    int index;
    scanf("%d", &index);
    if(index > 0 && index <= *numEntries) {
        memmove(diary + (index - 1), diary + index, (*numEntries - index) * sizeof(Entry));
        --(*numEntries);
        printf("Diary entry deleted successfully.\n");
    } else {
        printf("Invalid index. Please try again.\n");
    }
}

void viewEntries(Entry* diary, int numEntries) {
    if(numEntries == 0) {
        printf("Diary is empty.\n");
        return;
    }

    for(int i = 0; i < numEntries; ++i) {
        printf("Entry %d - %s\n", i+1, diary[i].date);
        printf("%s\n", diary[i].content);
    }
}