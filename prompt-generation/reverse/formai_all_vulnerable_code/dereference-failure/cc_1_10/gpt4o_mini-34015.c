//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define PAGE_SIZE 5

void displayPage(char **content, int startIndex) {
    for (int i = 0; i < PAGE_SIZE; i++) {
        if (content[startIndex + i] != NULL) {
            printf("%s\n", content[startIndex + i]);
        } else {
            break;
        }
    }
    printf("\n");
}

char **readFile(const char *filename, int *totalLines) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    char **lines = malloc(BUFFER_SIZE * sizeof(char *));
    char buffer[BUFFER_SIZE];
    int count = 0;

    while (fgets(buffer, BUFFER_SIZE, file)) {
        if (count >= BUFFER_SIZE) {
            lines = realloc(lines, (BUFFER_SIZE + count) * sizeof(char *));
        }
        lines[count] = strdup(buffer);
        count++;
    }

    fclose(file);
    *totalLines = count;
    return lines;
}

void freeContent(char **content, int totalLines) {
    for (int i = 0; i < totalLines; i++) {
        free(content[i]);
    }
    free(content);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int totalLines;
    char **content = readFile(argv[1], &totalLines);
    if (content == NULL) {
        return EXIT_FAILURE;
    }

    int currentPage = 0;
    char command;

    do {
        printf("\n--- Page %d ---\n", currentPage + 1);
        displayPage(content, currentPage * PAGE_SIZE);

        printf("Commands: n (next), p (previous), q (quit)\n");
        command = getchar();
        while (getchar() != '\n'); // Clear the input buffer

        switch (command) {
            case 'n':
                if ((currentPage + 1) * PAGE_SIZE < totalLines) {
                    currentPage++;
                } else {
                    printf("You are already at the last page!\n");
                }
                break;
            case 'p':
                if (currentPage > 0) {
                    currentPage--;
                } else {
                    printf("You are already at the first page!\n");
                }
                break;
            case 'q':
                printf("Exiting... Happy reading!\n");
                break;
            default:
                printf("Invalid command! Please try again.\n");
                break;
        }
    } while (command != 'q');

    freeContent(content, totalLines);
    return EXIT_SUCCESS;
}