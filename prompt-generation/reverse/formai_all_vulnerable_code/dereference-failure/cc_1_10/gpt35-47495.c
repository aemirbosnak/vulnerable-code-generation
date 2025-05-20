//FormAI DATASET v1.0 Category: Digital Diary ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int diary_count = 0;

typedef struct DiaryEntry {
    char date[30];
    char content[1000];
} DiaryEntry;

void add_diary_entry(DiaryEntry* diary, char* date, char* content){
    strcpy(diary[diary_count].date, date);
    strcpy(diary[diary_count].content, content);
    diary_count++;
}

void print_diary_entry(DiaryEntry entry) {
    printf("Date: %s\n", entry.date);
    printf("Content: %s\n", entry.content);
}

void view_diary_entries(DiaryEntry* diary) {
    for (int i = 0; i < diary_count; i++) {
        printf("== Diary Entry %d ==\n", i+1);
        print_diary_entry(diary[i]);
    }
}

int main() {
    DiaryEntry* diary = malloc(sizeof(DiaryEntry) * 10);
    char ch, date[30], content[1000];

    printf("Welcome to Curious Digital Diary!\n");

    while (1){
        printf("\nPlease select an option:\n");
        printf("1. Add a new diary entry\n");
        printf("2. View all diary entries\n");
        printf("3. Quit\n");

        ch = getchar();
        getchar(); // eat up newline

        switch(ch) {
            case '1':
                printf("Enter the date in YYYY-MM-DD format: ");
                fgets(date, 30, stdin);
                strtok(date, "\n"); // remove trailing newline

                printf("Enter the content of your diary entry: ");
                fgets(content, 1000, stdin);
                strtok(content, "\n"); // remove trailing newline

                add_diary_entry(diary, date, content);
                printf("\nDiary entry added!\n");
                break;
            case '2':
                if (diary_count == 0) {
                    printf("\nYour diary is empty!\n");
                } else {
                    printf("\n== All Diary Entries ==\n");
                    view_diary_entries(diary);
                }
                break;
            case '3':
                printf("\nThank you for using Curious Digital Diary!\n");
                return 0;
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    }

    free(diary);
    return 0;
}