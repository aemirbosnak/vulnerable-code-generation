//FormAI DATASET v1.0 Category: Browser Plugin ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _bookmark {
    char title[256];
    char url[256];
    struct _bookmark *next;
} Bookmark;

Bookmark *bookmarks = NULL;

void add_bookmark(char *title, char *url) {
    Bookmark *new_bookmark = (Bookmark*)malloc(sizeof(Bookmark));
    strncpy(new_bookmark->title, title, sizeof(new_bookmark->title) - 1);
    strncpy(new_bookmark->url, url, sizeof(new_bookmark->url) - 1);
    new_bookmark->next = bookmarks;
    bookmarks = new_bookmark;
}

void remove_bookmark(char *url) {
    Bookmark *current = bookmarks;
    Bookmark *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->url, url) == 0) {
            if (previous == NULL) {
                bookmarks = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void print_bookmarks() {
    int i = 1;
    printf("Bookmarks:\n");
    Bookmark *current = bookmarks;
    while (current != NULL) {
        printf("%d: %s (%s)\n", i++, current->title, current->url);
        current = current->next;
    }
}

int main() {
    add_bookmark("Google", "https://www.google.com");
    add_bookmark("Stack Overflow", "https://stackoverflow.com");
    add_bookmark("GitHub", "https://github.com");
    print_bookmarks();
    remove_bookmark("https://stackoverflow.com");
    print_bookmarks();
    return 0;
}