//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Let's make it easy to slurp up an entire file
char *slurp_file(const char *filepath) {
    FILE *fp = fopen(filepath, "r");
    if (fp == NULL) return NULL;
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    char *buffer = malloc(size + 1);
    rewind(fp);
    fread(buffer, size, 1, fp);
    fclose(fp);
    buffer[size] = '\0'; // Just in case
    return buffer;
}

// Just some fancy text effects
void fancy_println(const char *str) {
    printf("\n=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
    printf("%s\n", str);
    printf("=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n\n");
}

int main() {
    // Let's open up a book!
    char *filepath = "the_book.txt";
    char *book = slurp_file(filepath);
    if (book == NULL) {
        fancy_println("Oops! Something went wrong while opening the book. Make sure the file exists!");
        return 1;
    }

    // Time to paginate the book
    int page_size = 20; // Let's say each page has 20 lines
    char *page = strtok(book, "\n");
    int page_number = 1;
    while (page != NULL) {
        fancy_println("======");
        printf("Page %d\n", page_number++);
        int line_count = 0;
        while (page != NULL && line_count < page_size) {
            // Let's make it readable
            int line_len = strlen(page);
            if (line_len > 80) {
                line_len = 80;
                page[line_len] = '\0'; // Hacky but quick
            }
            printf("%s\n", page);
            page = strtok(NULL, "\n");
            line_count++;
        }
        printf("Press ENTER to continue...\n");
        getchar();
    }

    // All done!
    printf("That's all, folks!\n");
    free(book);
    return 0;
}