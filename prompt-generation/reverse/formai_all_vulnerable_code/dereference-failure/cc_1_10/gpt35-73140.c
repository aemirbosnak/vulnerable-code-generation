//FormAI DATASET v1.0 Category: Digital Diary ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TEXT_LENGTH 2000
#define MAX_ENTRIES 100

typedef struct {
    char text[MAX_TEXT_LENGTH];
    struct tm date;
} Entry;

void clear_screen() {
    system("clear||cls");
}

void print_menu() {
    clear_screen();
    printf("Digital Diary\n");
    printf("------------------------\n");
    printf("[1] New entry\n");
    printf("[2] View entries\n");
    printf("[3] Search entries\n");
    printf("[4] Exit\n");
    printf("------------------------\n");
}

int get_menu_choice() {
    int choice = 0;
    scanf("%d", &choice);
    getchar(); // clear input buffer
    return choice;
}

void get_entry_text(char* text) {
    printf("Enter entry text (Max %d characters):\n", MAX_TEXT_LENGTH);
    fgets(text, MAX_TEXT_LENGTH, stdin);
    // remove trailing newline character
    text[strcspn(text, "\n")] = 0;
}

void save_entry(Entry* entry, int* num_entries) {
    FILE* file = fopen("diary.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    fprintf(file, "%s\n", entry->text);
    fprintf(file, "%d-%02d-%02d %02d:%02d:%02d\n", entry->date.tm_year + 1900, entry->date.tm_mon + 1, entry->date.tm_mday, entry->date.tm_hour, entry->date.tm_min, entry->date.tm_sec);
    fclose(file);
    (*num_entries)++;
    printf("Entry saved.\n");
}

void get_entries(Entry* entries, int num_entries) {
    FILE* file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    char text[MAX_TEXT_LENGTH];
    char date_str[20];
    for (int i = 0; i < num_entries; i++) {
        fgets(text, MAX_TEXT_LENGTH, file);
        fgets(date_str, 20, file);
        strptime(date_str, "%Y-%m-%d %H:%M:%S", &entries[i].date);
        strcpy(entries[i].text, text);
    }
    fclose(file);
}

void view_entries(Entry* entries, int num_entries) {
    if (num_entries == 0) {
        printf("No entries found.\n");
        return;
    }
    for (int i = 0; i < num_entries; i++) {
        char date_str[20];
        strftime(date_str, 20, "%Y-%m-%d %H:%M:%S", &entries[i].date);
        printf("------------------------\n");
        printf("%s\n", date_str);
        printf("%s\n", entries[i].text);
        printf("\n");
    }
}

int search_entries(Entry* entries, int num_entries, char* query) {
    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].text, query) != NULL) {
            char date_str[20];
            strftime(date_str, 20, "%Y-%m-%d %H:%M:%S", &entries[i].date);
            printf("------------------------\n");
            printf("%s\n", date_str);
            printf("%s\n", entries[i].text);
            printf("\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No entries found.\n");
    }
}

int main() {
    int choice = 0;
    int num_entries = 0;
    Entry entries[MAX_ENTRIES];

    get_entries(entries, num_entries);

    while (choice != 4) {
        print_menu();
        choice = get_menu_choice();

        switch (choice) {
            case 1:
                clear_screen();
                if (num_entries >= MAX_ENTRIES) {
                    printf("Maximum number of entries reached.\n");
                    break;
                }
                Entry entry;
                get_entry_text(entry.text);
                time_t now = time(NULL);
                entry.date = *localtime(&now);
                save_entry(&entry, &num_entries);
                break;
            case 2:
                clear_screen();
                view_entries(entries, num_entries);
                getchar(); // wait for user input
                break;
            case 3:
                clear_screen();
                char query[MAX_TEXT_LENGTH];
                printf("Enter search query:\n");
                fgets(query, MAX_TEXT_LENGTH, stdin);
                query[strcspn(query, "\n")] = 0;
                search_entries(entries, num_entries, query);
                getchar(); // wait for user input
                break;
            case 4:
                clear_screen();
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}