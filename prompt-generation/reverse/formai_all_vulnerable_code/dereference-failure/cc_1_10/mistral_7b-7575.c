//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_PAGE_SIZE 4096
#define BUFFER_SIZE 8192

// Function to check if a file exists and is readable
int file_is_valid(const char *filename) {
    struct stat file_stat;
    int ret = 0;

    if (stat(filename, &file_stat) < 0) {
        perror("Error checking file existence");
        return 1;
    }

    if (!S_ISREG(file_stat.st_mode)) {
        fprintf(stderr, "File '%s' is not a regular file\n", filename);
        return 1;
    }

    if (access(filename, R_OK) < 0) {
        perror("Error checking file readability");
        return 1;
    }

    return ret;
}

// Function to read a single page from the ebook file
void read_page(FILE *file, char *page_buffer) {
    size_t bytes_read = 0;

    if (fgets(page_buffer, MAX_PAGE_SIZE, file) != NULL) {
        // Remove newline character from the end of the page buffer
        size_t newline_index = strcspn(page_buffer, "\n");
        if (newline_index > 0) {
            memmove(page_buffer, page_buffer, newline_index);
            page_buffer[newline_index] = '\0';
        }
    } else {
        fprintf(stderr, "Error reading page\n");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ebook_file>\n", argv[0]);
        exit(1);
    }

    if (file_is_valid(argv[1]) != 0) {
        fprintf(stderr, "Error: Invalid ebook file\n");
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening ebook file");
        exit(1);
    }

    char page_buffer[BUFFER_SIZE];
    char *current_page = malloc(MAX_PAGE_SIZE);

    while (!feof(file)) {
        read_page(file, page_buffer);

        // Check if the current page buffer is large enough to display
        size_t current_page_size = strlen(current_page) + strlen(page_buffer) + 1;
        if (current_page_size > BUFFER_SIZE) {
            // If not, copy the current page to a new buffer and free the old one
            char *new_page_buffer = malloc(current_page_size);
            if (new_page_buffer == NULL) {
                perror("Error allocating memory");
                exit(1);
            }

            strcpy(new_page_buffer, current_page);
            free(current_page);
            current_page = new_page_buffer;
        }

        // Append the new page to the current page buffer
        strcat(current_page, page_buffer);
        memset(page_buffer, 0, MAX_PAGE_SIZE);
    }

    printf("%s\n", current_page);

    free(current_page);
    fclose(file);

    return 0;
}