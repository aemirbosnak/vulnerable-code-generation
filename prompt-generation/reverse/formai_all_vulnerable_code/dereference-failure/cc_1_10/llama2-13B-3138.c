//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *name;
    char *author;
    char *publisher;
    int published_year;
} Book;

typedef struct {
    Book book[10];
    int current_index;
} Ebook;

Ebook *load_ebook(const char *file_path) {
    Ebook *eb = malloc(sizeof(Ebook));
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return NULL;
    }
    int i = 0;
    while (1) {
        char line[BUFFER_SIZE];
        fgets(line, BUFFER_SIZE, file);
        if (strcmp(line, "") == 0) break;
        // Parse book information
        char *token = strtok(line, ":");
        eb->book[i].name = strdup(token);
        token = strtok(NULL, ":");
        eb->book[i].author = strdup(token);
        token = strtok(NULL, ":");
        eb->book[i].publisher = strdup(token);
        token = strtok(NULL, ":");
        eb->book[i].published_year = atoi(token);
        i++;
    }
    fclose(file);
    return eb;
}

void display_ebook(Ebook *eb) {
    printf("Ebook Contents:\n");
    for (int i = 0; i < eb->current_index; i++) {
        printf("Book: %s, Author: %s, Publisher: %s, Published Year: %d\n",
               eb->book[i].name, eb->book[i].author, eb->book[i].publisher,
               eb->book[i].published_year);
    }
}

int main() {
    Ebook *eb = load_ebook("example_ebook.txt");
    if (eb == NULL) {
        perror("Failed to load ebook");
        return 1;
    }
    display_ebook(eb);
    free(eb);
    return 0;
}