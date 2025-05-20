//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct entry {
    char *title;
    char *body;
    struct entry *next;
};

struct diary {
    struct entry *head;
};

void create_diary(struct diary **diary) {
    *diary = malloc(sizeof(struct diary));
    (*diary)->head = NULL;
}

void add_entry(struct diary *diary, char *title, char *body) {
    struct entry *new_entry = malloc(sizeof(struct entry));
    new_entry->title = strdup(title);
    new_entry->body = strdup(body);
    new_entry->next = NULL;

    if (diary->head == NULL) {
        diary->head = new_entry;
    } else {
        struct entry *current = diary->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_entry;
    }
}

void print_entry(struct entry *entry) {
    printf("Title: %s\n", entry->title);
    printf("Body: %s\n", entry->body);
}

void print_diary(struct diary *diary) {
    struct entry *current = diary->head;
    while (current != NULL) {
        print_entry(current);
        current = current->next;
    }
}

void free_diary(struct diary *diary) {
    struct entry *current = diary->head;
    while (current != NULL) {
        struct entry *next = current->next;
        free(current->title);
        free(current->body);
        free(current);
        current = next;
    }
    free(diary);
}

int main() {
    struct diary *diary;
    create_diary(&diary);

    add_entry(diary, "First Entry", "This is my first entry in my digital diary.");
    add_entry(diary, "Second Entry", "This is my second entry in my digital diary.");
    add_entry(diary, "Third Entry", "This is my third entry in my digital diary.");

    print_diary(diary);

    free_diary(diary);

    return 0;
}