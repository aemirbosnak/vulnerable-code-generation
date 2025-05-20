//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_POEMS 10

// Structure to hold a poem
typedef struct {
    char *line;
    int line_length;
    struct poem *next;
} poem_t;

// Structure to hold a list of poems
typedef struct {
    poem_t *head;
    poem_t *tail;
} poem_list_t;

// Function to print a poem
void print_poem(poem_t *poem) {
    char *line = poem->line;
    int line_length = poem->line_length;

    // Print each line of the poem
    for (int i = 0; i < line_length; i++) {
        putchar(line[i]);
        if (line[i] == '\n') {
            putchar('\n');
        }
    }
}

// Function to generate a list of poems
poem_list_t *generate_poems(int num_poems) {
    poem_list_t *poem_list = calloc(1, sizeof(poem_list_t));

    // Generate each poem
    for (int i = 0; i < num_poems; i++) {
        // Generate a random line of the poem
        char *line = calloc(1, MAX_LINE_LENGTH);
        int line_length = rand() % MAX_LINE_LENGTH;
        for (int j = 0; j < line_length; j++) {
            line[j] = 'a' + (rand() % 26);
        }
        line[line_length] = '\0';

        // Add the poem to the list
        poem_t *new_poem = calloc(1, sizeof(poem_t));
        new_poem->line = line;
        new_poem->line_length = line_length;
        new_poem->next = NULL;

        if (poem_list->head == NULL) {
            poem_list->head = new_poem;
        } else {
            poem_list->tail->next = new_poem;
        }
        poem_list->tail = new_poem;
    }

    return poem_list;
}

int main() {
    srand(time(NULL));

    // Generate a list of poems
    poem_list_t *poem_list = generate_poems(MAX_POEMS);

    // Print each poem
    for (poem_t *poem = poem_list->head; poem != NULL; poem = poem->next) {
        print_poem(poem);
    }

    free(poem_list);
    return 0;
}