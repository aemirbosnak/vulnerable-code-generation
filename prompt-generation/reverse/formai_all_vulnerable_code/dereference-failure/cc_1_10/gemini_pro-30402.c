//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a line from a file
char *readline(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if ((read = getline(&line, &len, fp)) != -1) {
        line[read - 1] = '\0';  // Remove newline character
    }

    return line;
}

// Function to print a page of text
void print_page(char *text, size_t page_size) {
    size_t i = 0;

    while (i < page_size && text[i] != '\0') {
        printf("%c", text[i]);
        i++;
    }

    printf("\n");
}

// Function to paginate a text file
void paginate(FILE *fp, size_t page_size) {
    char *line = NULL;
    size_t page = 1;

    while ((line = readline(fp)) != NULL) {
        if (page == 1) {
            printf("Page %zu\n\n", page);
        }

        print_page(line, page_size);

        page++;
    }

    free(line);
}

int main() {
    FILE *fp = fopen("book.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    size_t page_size = 20;  // Page size can be customized

    paginate(fp, page_size);

    fclose(fp);

    return EXIT_SUCCESS;
}