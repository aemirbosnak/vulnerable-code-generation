//FormAI DATASET v1.0 Category: Digital Diary ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct diary_entry_t {
    char date[12];
    char text[100];
    struct diary_entry_t *next;
} diary_entry;

diary_entry *new_entry(char date[12], char text[100]) {
    diary_entry *entry = malloc(sizeof(diary_entry));
    strcpy(entry->date, date);
    strcpy(entry->text, text);
    entry->next = NULL;
    return entry;
}

void print_entry(diary_entry *entry) {
    printf("%s:\n%s\n", entry->date, entry->text);
}

void print_diary(diary_entry *head) {
    diary_entry *current = head;
    while (current != NULL) {
        print_entry(current);
        current = current->next;
    }
}

void add_entry(diary_entry **head, diary_entry *entry) {
    diary_entry *current = *head;
    if (*head == NULL) {
        *head = entry;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = entry;
    }
}

int main() {
    diary_entry *head = NULL;

    printf("Welcome to your Digital Diary!\n");
    printf("Enter new entries below:\n");

    while (1) {
        char date[12];
        time_t t = time(NULL);
        struct tm *tm = localtime(&t);
        strftime(date, sizeof(date), "%m/%d/%Y", tm);

        char text[100];
        fgets(text, sizeof(text), stdin);

        diary_entry *entry = new_entry(date, text);
        add_entry(&head, entry);

        printf("\nEntry added!\n");
        printf("Do you want to add another entry? [y/n]\n");

        char input[2];
        fgets(input, sizeof(input), stdin);
        if (input[0] == 'n') {
            break;
        }
    }

    printf("\nYour Diary Entries:\n");
    print_diary(head);

    return 0;
}