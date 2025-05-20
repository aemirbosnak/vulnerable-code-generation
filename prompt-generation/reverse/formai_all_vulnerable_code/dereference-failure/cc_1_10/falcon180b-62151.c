//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[20];
    char entry[200];
} diary;

void addEntry(diary *d, int size) {
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", d[size].date);
    printf("Enter your entry:\n");
    fgets(d[size].entry, 200, stdin);
}

void viewEntries(diary d[], int size) {
    printf("\n\nDiary Entries:\n");
    for(int i=0; i<size; i++) {
        printf("%s : %s\n", d[i].date, d[i].entry);
    }
}

void searchByDate(diary d[], int size) {
    char searchDate[20];
    printf("Enter date to search (dd/mm/yyyy): ");
    scanf("%s", searchDate);
    for(int i=0; i<size; i++) {
        if(strcmp(d[i].date, searchDate) == 0) {
            printf("%s\n%s\n", d[i].date, d[i].entry);
        }
    }
}

void deleteEntry(diary *d, int *size) {
    printf("Enter date to delete (dd/mm/yyyy): ");
    scanf("%s", d[*size-1].date);
    strcpy(d[*size-1].date, d[*size-2].date);
    strcpy(d[*size-1].entry, d[*size-2].entry);
    (*size)--;
}

int main() {
    diary d[MAX_ENTRIES];
    int size = 0;
    char choice;
    do {
        printf("\nDigital Diary\n");
        printf("1. Add Entry\n2. View Entries\n3. Search by Date\n4. Delete Entry\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        switch(choice) {
            case '1':
                if(size == MAX_ENTRIES) {
                    printf("Diary is full! ");
                } else {
                    addEntry(d, size);
                    size++;
                }
                break;
            case '2':
                viewEntries(d, size);
                break;
            case '3':
                searchByDate(d, size);
                break;
            case '4':
                deleteEntry(d, &size);
                break;
            case '5':
                printf("\nExiting...\n");
                break;
            default:
                printf("Invalid choice! ");
        }
    } while(choice!= '5');
    return 0;
}