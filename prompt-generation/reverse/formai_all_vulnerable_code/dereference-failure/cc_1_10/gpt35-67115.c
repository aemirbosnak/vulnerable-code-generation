//FormAI DATASET v1.0 Category: Digital Diary ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_ENTRIES 100

struct date {
    int day;
    int month;
    int year;
};

struct diary_entry {
    char* title;
    struct date entry_date;
    char* content;
};

void add_entry(struct diary_entry entries[MAX_ENTRIES], int* num_entries);
void view_entry(struct diary_entry entries[MAX_ENTRIES], int num_entries);
void search_entries(struct diary_entry entries[MAX_ENTRIES], int num_entries);

int main() {
    struct diary_entry entries[MAX_ENTRIES];
    int num_entries = 0;
    int option = 0;
    while (option != 4) {
        printf("Enter an option:\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Quit\n");
        scanf("%d", &option);
        if (option == 1) {
            add_entry(entries, &num_entries);
        } else if (option == 2) {
            view_entry(entries, num_entries);
        } else if (option == 3) {
            search_entries(entries, num_entries);
        }
    }
    return 0;
}

void add_entry(struct diary_entry entries[MAX_ENTRIES], int* num_entries) {
    if (*num_entries == MAX_ENTRIES) {
        printf("Max entries reached\n");
        return;
    }
    printf("Enter the title of the entry:\n");
    char title[100];
    scanf("%s", title);
    entries[*num_entries].title = (char*) malloc(strlen(title) + 1);
    strcpy(entries[*num_entries].title, title);
    printf("Enter the date of the entry (in dd/mm/yyyy format):\n");
    scanf("%d/%d/%d", &entries[*num_entries].entry_date.day, 
                        &entries[*num_entries].entry_date.month, 
                        &entries[*num_entries].entry_date.year);
    printf("Enter the content of the entry:\n");
    char content[1000];
    char c;
    int i = 0;
    do {
        c = getchar();
        content[i++] = c;
    } while (c != '\n' && i < 999);
    content[i-1] = '\0';
    entries[*num_entries].content = (char*) malloc(strlen(content) + 1);
    strcpy(entries[*num_entries].content, content);
    *num_entries += 1;
    printf("Entry added successfully!\n");
}

void view_entry(struct diary_entry entries[MAX_ENTRIES], int num_entries) {
    if (num_entries == 0) {
        printf("No entries to display\n");
        return;
    }
    for (int i = 0; i < num_entries; i++) {
        printf("\nTitle: %s\n", entries[i].title);
        printf("Date: %d/%d/%d\n", entries[i].entry_date.day, 
                                    entries[i].entry_date.month, 
                                    entries[i].entry_date.year);
        printf("Content: %s\n", entries[i].content);
    }
}

void search_entries(struct diary_entry entries[MAX_ENTRIES], int num_entries) {
    if (num_entries == 0) {
        printf("No entries to search\n");
        return;
    }
    printf("Enter a search term:\n");
    char search_term[100];
    scanf("%s", search_term);
    int results[MAX_ENTRIES];
    int num_results = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].title, search_term) != NULL ||
            strstr(entries[i].content, search_term) != NULL) {
            results[num_results] = i;
            num_results++;
        }
    }
    if (num_results == 0) {
        printf("No results found\n");
    } else {
        printf("Search results:\n");
        for (int i = 0; i < num_results; i++) {
            printf("\nTitle: %s\n", entries[results[i]].title);
            printf("Date: %d/%d/%d\n", entries[results[i]].entry_date.day, 
                                        entries[results[i]].entry_date.month, 
                                        entries[results[i]].entry_date.year);
            printf("Content: %s\n", entries[results[i]].content);
        }
    }
}