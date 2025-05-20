//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SIZE 1024  // Number of characters per page

void display_page(char *page_content) {
    printf("%s\n", page_content);
    printf("\nPress Enter to continue or type 'exit' to quit: ");
    char choice[10];
    fgets(choice, sizeof(choice), stdin);
    if (strncmp(choice, "exit", 4) == 0) {
        exit(0);
    }
}

void read_ebook(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open the file");
        exit(EXIT_FAILURE);
    }

    char *buffer = malloc(PAGE_SIZE + 1);
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, PAGE_SIZE, file) != NULL) {
        // Handle multi-page content that might not fit in one read
        display_page(buffer);
    }

    free(buffer);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ebook-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Welcome to the C Ebook Reader!\n");
    printf("Reading from: %s\n", argv[1]);
    read_ebook(argv[1]);
    printf("End of the ebook. Thank you for reading!\n");
    
    return EXIT_SUCCESS;
}