//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct diary {
    char *title;
    char *content;
    struct diary *next;
} diary_t;

diary_t *head = NULL;

void add_entry(char *title, char *content) {
    diary_t *new_entry = malloc(sizeof(diary_t));
    new_entry->title = malloc(strlen(title) + 1);
    strcpy(new_entry->title, title);
    new_entry->content = malloc(strlen(content) + 1);
    strcpy(new_entry->content, content);
    new_entry->next = head;
    head = new_entry;
}

void print_diary() {
    diary_t *current = head;
    while (current != NULL) {
        printf("Title: %s\n", current->title);
        printf("Content: %s\n", current->content);
        current = current->next;
    }
}

void free_diary() {
    diary_t *current = head;
    while (current != NULL) {
        diary_t *next = current->next;
        free(current->title);
        free(current->content);
        free(current);
        current = next;
    }
}

int main() {
    // Let's write some cheerful entries in our digital diary!
    add_entry("A Sunny Day", "Woke up to the sound of birds chirping and the sun shining through my window. It's going to be a great day!");
    add_entry("A Walk in the Park", "Took a stroll through the park and saw all sorts of happy people. The flowers were in bloom and the air was filled with laughter.");
    add_entry("A Good Laugh", "Had a hilarious conversation with my friend over coffee. We laughed so hard our stomachs hurt!");

    // Now let's read our diary and smile!
    print_diary();

    // And finally, let's free the memory used by our diary.
    free_diary();

    return 0;
}