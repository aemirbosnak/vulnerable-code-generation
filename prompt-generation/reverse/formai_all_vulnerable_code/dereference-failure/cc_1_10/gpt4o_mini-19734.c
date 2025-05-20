//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SIZE 200 // Number of characters per page
#define MAX_FILENAME_LEN 100

void display_page(const char *content, int start_index) {
    for (int i = 0; i < PAGE_SIZE; i++) {
        if (content[start_index + i] == '\0') { // End of the content
            break;
        }
        putchar(content[start_index + i]);
    }
}

int read_ebook_content(const char *filename, char **content) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    *content = (char *)malloc(file_size + 1);
    if (*content == NULL) {
        printf("Memory allocation failed\n");
        fclose(file);
        return -1;
    }
    
    fread(*content, 1, file_size, file);
    (*content)[file_size] = '\0'; // Null-terminate the string
    fclose(file);
    return file_size;
}

void clean_up(char *content) {
    if (content) {
        free(content);
    }
}

int main() {
    char filename[MAX_FILENAME_LEN];
    char *content = NULL;
    int total_chars = 0;
    int current_page = 0;

    printf("Welcome to the Simple C Ebook Reader!\n");
    printf("Please enter the name of the ebook file: ");
    scanf("%s", filename);

    total_chars = read_ebook_content(filename, &content);
    if (total_chars <= 0) {
        clean_up(content);
        return EXIT_FAILURE;
    }

    int total_pages = (total_chars + PAGE_SIZE - 1) / PAGE_SIZE; // Calculate the total number of pages

    while (1) {
        printf("\n--- Page %d of %d ---\n", current_page + 1, total_pages);
        display_page(content, current_page * PAGE_SIZE);
        printf("\n\nOptions: (N)ext, (P)revious, (Q)uit\n");
        char option;
        scanf(" %c", &option);

        if (option == 'N' || option == 'n') {
            if (current_page < total_pages - 1) {
                current_page++;
            } else {
                printf("You are already on the last page.\n");
            }
        } else if (option == 'P' || option == 'p') {
            if (current_page > 0) {
                current_page--;
            } else {
                printf("You are already on the first page.\n");
            }
        } else if (option == 'Q' || option == 'q') {
            break;
        } else {
            printf("Unknown option, please try again.\n");
        }
    }

    clean_up(content);
    printf("Thank you for using the Simple C Ebook Reader!\n");
    return EXIT_SUCCESS;
}