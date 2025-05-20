//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[MAX_LENGTH];
    char entry[MAX_LENGTH];
} DiaryEntry;

void add_entry(DiaryEntry diary[], int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Alas, no more entries can be added, for the tome is full!\n");
        return;
    }
    
    printf("Write thy entry for today in the scroll of remembrance:\n");
    fgets(diary[*count].entry, MAX_LENGTH, stdin);
    
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(diary[*count].date, "%02d-%02d-%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    
    (*count)++;
    printf("Thy entry hath been scribed on %s!\n", diary[*count - 1].date);
}

void view_entries(DiaryEntry diary[], int count) {
    if (count == 0) {
        printf("Nay, there be no entries to behold!\n");
        return;
    }
    
    printf("Behold thy past entries:\n");
    for (int i = 0; i < count; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Entry: %s\n\n", diary[i].entry);
    }
}

void delete_entry(DiaryEntry diary[], int *count) {
    if (*count == 0) {
        printf("Nay, there be no entries to remove!\n");
        return;
    }

    printf("Enter the index of the entry to remove (0 to %d): ", *count - 1);
    int index;
    scanf("%d", &index);
    getchar(); // Consume the newline character
    
    if (index < 0 || index >= *count) {
        printf("Alas, that index is out of bounds!\n");
        return;
    }
    
    for (int i = index; i < *count - 1; i++) {
        diary[i] = diary[i + 1];
    }
    (*count)--;
    
    printf("Thy entry hath been erased from the annals of time!\n");
}

void save_entries(DiaryEntry diary[], int count) {
    FILE *file = fopen("medieval_diary.txt", "w");
    if (file == NULL) {
        printf("Alas, an error hath befallen the saving of thy entries!\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "Date: %s\nEntry: %s\n\n", diary[i].date, diary[i].entry);
    }
    
    fclose(file);
    printf("Thy entries hath been duly saved in the scroll of the realm!\n");
}

void load_entries(DiaryEntry diary[], int *count) {
    FILE *file = fopen("medieval_diary.txt", "r");
    if (file == NULL) {
        printf("No scrolls of past entries could be found!\n");
        return;
    }
    
    while (fgets(diary[*count].date, MAX_LENGTH, file) != NULL) {
        fgets(diary[*count].entry, MAX_LENGTH, file);
        (*count)++;
    }
    
    fclose(file);
    printf("Thy past entries hath been recovered from the depths of time!\n");
}

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int count = 0;
    int choice;

    while (1) {
        printf("\nWelcome to the Medieval Digital Diary!\n");
        printf("1. Scribe a new entry\n");
        printf("2. View past entries\n");
        printf("3. Remove an entry\n");
        printf("4. Save entries to scroll\n");
        printf("5. Load entries from scroll\n");
        printf("6. Exit the diary\n");
        printf("Make thy choice (1-6): ");

        scanf("%d", &choice);
        getchar(); // Consume the newline character

        switch (choice) {
            case 1:
                add_entry(diary, &count);
                break;
            case 2:
                view_entries(diary, count);
                break;
            case 3:
                delete_entry(diary, &count);
                break;
            case 4:
                save_entries(diary, count);
                break;
            case 5:
                load_entries(diary, &count);
                break;
            case 6:
                printf("Farewell, until we meet again!\n");
                exit(0);
            default:
                printf("Thy choice is most unfathomable! Please choose wisely!\n");
                break;
        }
    }
    return 0;
}