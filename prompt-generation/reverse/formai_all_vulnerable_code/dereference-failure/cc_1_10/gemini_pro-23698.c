//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Diary {
    char *title;
    char *content;
    time_t timestamp;
    struct Diary *next;
} Diary;

Diary *create_diary(char *title, char *content) {
    Diary *new_diary = malloc(sizeof(Diary));
    new_diary->title = strdup(title);
    new_diary->content = strdup(content);
    new_diary->timestamp = time(NULL);
    new_diary->next = NULL;
    return new_diary;
}

Diary *add_diary(Diary *head, Diary *new_diary) {
    if (head == NULL) {
        return new_diary;
    } else {
        head->next = add_diary(head->next, new_diary);
        return head;
    }
}

void print_diary(Diary *head) {
    if (head == NULL) {
        printf("No diaries to print.\n");
    } else {
        printf("Title: %s\n", head->title);
        printf("Content: %s\n", head->content);
        printf("Timestamp: %s\n", ctime(&head->timestamp));
        printf("\n");
        print_diary(head->next);
    }
}

Diary *find_diary(Diary *head, char *title) {
    if (head == NULL) {
        return NULL;
    } else if (strcmp(head->title, title) == 0) {
        return head;
    } else {
        return find_diary(head->next, title);
    }
}

Diary *delete_diary(Diary *head, char *title) {
    if (head == NULL) {
        return NULL;
    } else if (strcmp(head->title, title) == 0) {
        Diary *next_diary = head->next;
        free(head->title);
        free(head->content);
        free(head);
        return next_diary;
    } else {
        head->next = delete_diary(head->next, title);
        return head;
    }
}

int main() {
    Diary *head = NULL;
    head = add_diary(head, create_diary("My First Diary", "This is my first diary entry."));
    head = add_diary(head, create_diary("My Second Diary", "This is my second diary entry."));
    head = add_diary(head, create_diary("My Third Diary", "This is my third diary entry."));

    print_diary(head);

    Diary *found_diary = find_diary(head, "My Second Diary");
    if (found_diary != NULL) {
        printf("Found diary:\n");
        printf("Title: %s\n", found_diary->title);
        printf("Content: %s\n", found_diary->content);
        printf("Timestamp: %s\n", ctime(&found_diary->timestamp));
        printf("\n");
    } else {
        printf("Diary not found.\n");
    }

    head = delete_diary(head, "My Second Diary");
    print_diary(head);

    return 0;
}