//Falcon2-11B DATASET v1.0 Category: Browser Plugin ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKMARKS 100
#define MAX_URL_LENGTH 256

struct Bookmark {
    char url[MAX_URL_LENGTH];
    int count;
};

struct Bookmark bookmarks[MAX_BOOKMARKS];
int num_bookmarks = 0;

void save_bookmarks(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Unable to open file for writing\n");
        return;
    }

    for (int i = 0; i < num_bookmarks; i++) {
        if (bookmarks[i].count > 0) {
            fprintf(fp, "%s\n", bookmarks[i].url);
        }
    }

    fclose(fp);
}

void load_bookmarks(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open file for reading\n");
        return;
    }

    char url[MAX_URL_LENGTH];
    int count = 0;
    while (fscanf(fp, "%s", url) == 1) {
        struct Bookmark *new_bookmark = malloc(sizeof(struct Bookmark));
        strncpy(new_bookmark->url, url, MAX_URL_LENGTH);
        new_bookmark->count = 0;
        bookmarks[num_bookmarks++] = *new_bookmark;
    }

    fclose(fp);
}

void add_bookmark(const char *url) {
    int i;
    for (i = 0; i < num_bookmarks; i++) {
        if (strcmp(bookmarks[i].url, url) == 0) {
            break;
        }
    }

    if (i == num_bookmarks) {
        struct Bookmark *new_bookmark = malloc(sizeof(struct Bookmark));
        strncpy(new_bookmark->url, url, MAX_URL_LENGTH);
        new_bookmark->count = 0;
        bookmarks[num_bookmarks++] = *new_bookmark;
    } else {
        bookmarks[i].count++;
    }
}

void remove_bookmark(const char *url) {
    int i;
    for (i = 0; i < num_bookmarks; i++) {
        if (strcmp(bookmarks[i].url, url) == 0) {
            break;
        }
    }

    if (i!= num_bookmarks) {
        struct Bookmark *bookmark_to_remove = &bookmarks[i];
        for (int j = i; j < num_bookmarks - 1; j++) {
            bookmarks[j] = bookmarks[j + 1];
        }
        free(bookmark_to_remove);
        num_bookmarks--;
    }
}

void display_bookmarks() {
    for (int i = 0; i < num_bookmarks; i++) {
        printf("%s: %d\n", bookmarks[i].url, bookmarks[i].count);
    }
}

int main() {
    char url[MAX_URL_LENGTH];

    printf("Enter a URL to add a bookmark:\n");
    scanf("%s", url);
    add_bookmark(url);

    printf("Enter a URL to remove a bookmark:\n");
    scanf("%s", url);
    remove_bookmark(url);

    printf("Enter a URL to load bookmarks from a file:\n");
    scanf("%s", url);
    load_bookmarks(url);

    printf("Enter a URL to save bookmarks to a file:\n");
    scanf("%s", url);
    save_bookmarks(url);

    printf("Displaying bookmarks:\n");
    display_bookmarks();

    return 0;
}