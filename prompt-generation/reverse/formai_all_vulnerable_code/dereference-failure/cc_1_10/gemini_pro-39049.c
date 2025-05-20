//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct entry {
    char *title;
    char *content;
    struct tm *timestamp;
} entry_t;

entry_t *new_entry(char *title, char *content, struct tm *timestamp) {
    entry_t *e = malloc(sizeof(entry_t));
    e->title = strdup(title);
    e->content = strdup(content);
    e->timestamp = timestamp;
    return e;
}

void free_entry(entry_t *e) {
    free(e->title);
    free(e->content);
    free(e);
}

int main() {
    // Create a new digital diary
    FILE *fp = fopen("diary.txt", "w");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Add some sample entries
    entry_t *e1 = new_entry("My First Entry", "This is my first entry in my digital diary.", NULL);
    entry_t *e2 = new_entry("My Second Entry", "Today I went to the park with my friends.", NULL);
    entry_t *e3 = new_entry("My Third Entry", "I'm feeling really happy today!", NULL);

    // Write the entries to the file
    fprintf(fp, "%s\n%s\n", e1->title, e1->content);
    fprintf(fp, "%s\n%s\n", e2->title, e2->content);
    fprintf(fp, "%s\n%s\n", e3->title, e3->content);

    // Close the file
    fclose(fp);

    // Free the entries
    free_entry(e1);
    free_entry(e2);
    free_entry(e3);

    return EXIT_SUCCESS;
}