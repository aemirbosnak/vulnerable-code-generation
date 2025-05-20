//FormAI DATASET v1.0 Category: Ebook reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Ebook structure
struct Ebook {
    char title[50];
    char author[50];
    int pages;
    char* content;
};

// Define function to read Ebook from file
void readEbook(FILE *file, struct Ebook *ebook) {
    fscanf(file, "%[^,],%[^,],%d", ebook->title, ebook->author, &ebook->pages);
    ebook->content = (char *) malloc(ebook->pages * sizeof(char));
    if (ebook->content == NULL) {
        printf("Error: Failed to allocate memory.\n");
        exit(1);
    }
    fseek(file, 1, SEEK_CUR); // Skip comma
    fgets(ebook->content, ebook->pages + 1, file);
}

// Define function to display Ebook info
void displayEbook(struct Ebook *ebook) {
    printf("Title: %s\n", ebook->title);
    printf("Author: %s\n", ebook->author);
    printf("Pages: %d\n", ebook->pages);
    printf("Content: %s\n", ebook->content);
}

int main() {
    FILE *file;
    struct Ebook ebook;
    
    // Open ebook file for reading
    file = fopen("mybook.txt", "r");
    if (file == NULL) {
        printf("Error: Failed to open file.\n");
        exit(1);
    }
    
    // Read and display ebook
    readEbook(file, &ebook);
    displayEbook(&ebook);
    
    // Close file and free memory
    fclose(file);
    free(ebook.content);
    
    return 0;
}