//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>

#define MAX_LINE_LENGTH 1024
#define MAX_POEMS 10

typedef struct poem {
    char *title;
    char *verse1;
    char *verse2;
    char *verse3;
} poem_t;

int main(void) {
    // Declare a array of poems
    poem_t poems[MAX_POEMS];

    // Read poems from file
    FILE *fp = fopen("poems.txt", "r");
    if (fp == NULL) {
        perror("Error opening poems file");
        return 1;
    }
    int i = 0;
    while (i < MAX_POEMS) {
        char line[MAX_LINE_LENGTH];
        if (fgets(line, MAX_LINE_LENGTH, fp) == NULL) {
            break;
        }
        // Tokenize line into title and verses
        char *title = strtok(line, " ");
        char *verse1 = strtok(NULL, " ");
        char *verse2 = strtok(NULL, " ");
        char *verse3 = strtok(NULL, " ");

        // Create a new poem struct
        poem_t *new_poem = malloc(sizeof(poem_t));
        new_poem->title = title;
        new_poem->verse1 = verse1;
        new_poem->verse2 = verse2;
        new_poem->verse3 = verse3;

        // Add poem to array
        poems[i] = *new_poem;
        i++;
    }

    // Print poems
    for (int j = 0; j < i; j++) {
        printf("Poem %d:\n", j + 1);
        printf("Title: %s\n", poems[j].title);
        printf("Verse 1: %s\n", poems[j].verse1);
        printf("Verse 2: %s\n", poems[j].verse2);
        printf("Verse 3: %s\n", poems[j].verse3);
        printf("\n");
    }

    // Clean up
    fclose(fp);
    return 0;
}