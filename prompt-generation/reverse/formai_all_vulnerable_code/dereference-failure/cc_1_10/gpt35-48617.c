//FormAI DATASET v1.0 Category: Digital Diary ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*struct to hold each diary entry*/
typedef struct DiaryEntry {
    char date[11]; //dd/mm/yyyy format
    char title[50];
    char content[1000];
} DiaryEntry;

/*function to create a new diary entry*/
DiaryEntry createEntry() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    DiaryEntry entry;
    printf("Create a new diary entry:\n");
    printf("Date (dd/mm/yyyy): ");
    scanf("%10s", entry.date);
    printf("Title: ");
    scanf("%49s", entry.title);
    printf("Content: ");
    scanf(" %[^\n]s", entry.content);
    return entry;
}

/*function to add a diary entry to the file*/
void addEntry(DiaryEntry entry, FILE* filePtr) {
    fprintf(filePtr, "%s\n%s\n%s\n", entry.date, entry.title, entry.content);
}

/*function to read and print all diary entries in the file*/
void viewDiary(FILE* filePtr) {
    DiaryEntry entry;
    printf("Viewing diary entries:\n");
    while(fscanf(filePtr, "%s\n%[^\n]s\n%[^\n]s\n", entry.date, entry.title, entry.content) != EOF) {
        printf("%s\n%s\n%s\n", entry.date, entry.title, entry.content);
        printf("----------------------------------------\n");
    }
}

/*Main function*/
int main() {
    int mode; //1 for create entry, 2 for view diary
    FILE* filePtr;
    filePtr = fopen("diary.txt", "a+"); //open existing or create new diary file
    if(filePtr == NULL) {
        printf("Unable to open diary file.\n");
        exit(1);
    }
    printf("Digital Diary\n");
    printf("Do you want to create a new entry or view previous entries?\n");
    printf("1. Create entry\n2. View diary\n");
    scanf("%d", &mode);
    if(mode == 1) { //create new entry
        DiaryEntry newEntry = createEntry();
        addEntry(newEntry, filePtr);
        printf("Entry added successfully!\n");
    } else if(mode == 2) { //view diary
        viewDiary(filePtr);
    } else { //invalid mode
        printf("Invalid input.");
        exit(1);
    }
    fclose(filePtr); //close the diary file
    return 0;
}