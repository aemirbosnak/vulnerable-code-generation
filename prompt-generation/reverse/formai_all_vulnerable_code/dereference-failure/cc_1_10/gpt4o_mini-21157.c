//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define PAGE_SIZE 20

void displayPage(char **content, int startIndex, int totalLines) {
    int endIndex = startIndex + PAGE_SIZE < totalLines ? startIndex + PAGE_SIZE : totalLines;
    for (int i = startIndex; i < endIndex; i++) {
        printf("%s", content[i]);
    }
    if (endIndex < totalLines) {
        printf("\n-- Press Enter to see more --\n");
    }
}

char **loadEbook(const char *filename, int *totalLines) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }

    char **content = malloc(sizeof(char *) * 1000);
    if (!content) {
        fclose(file);
        perror("Memory allocation failure");
        return NULL;
    }

    *totalLines = 0;
    while (!feof(file)) {
        content[*totalLines] = malloc(sizeof(char) * MAX_LINE_LENGTH);
        if (fgets(content[*totalLines], MAX_LINE_LENGTH, file) != NULL) {
            (*totalLines)++;
        }
    }
    
    fclose(file);
    return content;
}

void freeEbook(char **content, int totalLines) {
    for (int i = 0; i < totalLines; i++) {
        free(content[i]);
    }
    free(content);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <ebook_filename>\n", argv[0]);
        return 1;
    }

    int totalLines;
    char **content = loadEbook(argv[1], &totalLines);
    if (!content) {
        return 1;
    }

    printf("Welcome to the Brave C Ebook Reader!\n");
    printf("Press Enter to start reading.\n");
    getchar();

    int currentPage = 0;
    while (currentPage < totalLines) {
        displayPage(content, currentPage, totalLines);
        if (currentPage + PAGE_SIZE < totalLines) {
            getchar(); // Wait for Enter
        }
        currentPage += PAGE_SIZE;
    }

    freeEbook(content, totalLines);
    printf("You have reached the end of the ebook. Happy Reading!\n");
    return 0;
}