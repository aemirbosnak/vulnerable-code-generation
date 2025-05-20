//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define PAGE_SIZE 256
#define TOC_LINES 5

// Structure to hold the eBook information
typedef struct {
    FILE *file;
    char **toc;
    int total_pages;
} Ebook;

// Function to simulate reading a page
void* read_page(void *arg) {
    Ebook *ebook = (Ebook *)arg;
    char page[PAGE_SIZE];
    int page_number = 0;

    while (fgets(page, sizeof(page), ebook->file) != NULL) {
        printf("Page %d:\n%s\n", page_number + 1, page);
        page_number++;
        sleep(2);  // Simulate time taken to read a page
    }

    return NULL;
}

// Function to display the Table of Contents (TOC)
void* display_toc(void *arg) {
    Ebook *ebook = (Ebook *)arg;

    printf("\nTable of Contents:\n");
    for (int i = 0; i < ebook->total_pages && i < TOC_LINES; i++) {
        printf("%s", ebook->toc[i]);
        sleep(1);  // Simulate delay to make TOC visible
    }

    return NULL;
}

// Function to navigate to start of TOC in the file
void generate_toc(Ebook *ebook) {
    ebook->toc = malloc(TOC_LINES * sizeof(char *));
    for (int i = 0; i < TOC_LINES; i++) {
        ebook->toc[i] = malloc(50 * sizeof(char)); // each line max of 50 chars
        snprintf(ebook->toc[i], 50, "Chapter %d - Example Title\n", i + 1);
    }
}

// Main function
int main() {
    Ebook ebook;
    pthread_t read_thread, toc_thread;

    // Open the eBook file
    ebook.file = fopen("ebook.txt", "r");
    if (ebook.file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Count lines in the eBook for TOC generation
    ebook.total_pages = 0;
    while (fgetc(ebook.file) != EOF) {
        if (fgetc(ebook.file) == '\n') {
            ebook.total_pages++;
        }
    }
    rewind(ebook.file); // Return to the beginning of the file

    // Generate the TOC
    generate_toc(&ebook);

    // Create the threads for reading and TOC display
    pthread_create(&read_thread, NULL, read_page, &ebook);
    pthread_create(&toc_thread, NULL, display_toc, &ebook);

    // Wait for both threads to finish
    pthread_join(read_thread, NULL);
    pthread_join(toc_thread, NULL);

    // Free resources
    for (int i = 0; i < TOC_LINES; i++) {
        free(ebook.toc[i]);
    }
    free(ebook.toc);
    fclose(ebook.file);

    return EXIT_SUCCESS;
}