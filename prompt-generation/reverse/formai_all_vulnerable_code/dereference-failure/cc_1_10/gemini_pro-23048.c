//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A custom file structure that represents an eBook
typedef struct {
    char *title;
    char *author;
    int num_pages;
    char **pages;
} eBook;

// A function to read an eBook from a file
eBook *read_ebook(FILE *fp) {
    eBook *book = (eBook *)malloc(sizeof(eBook)); // Allocate memory for the book struct
    char line[1024]; // A buffer to read lines of text
    
    // Read the title and author from the file
    fgets(line, sizeof(line), fp); // Read the first line
    char *title = strtok(line, ","); // Extract the title
    char *author = strtok(NULL, ","); // Extract the author
    book->title = malloc(strlen(title) + 1); // Allocate memory for the title
    strcpy(book->title, title); // Copy the title into the book struct
    book->author = malloc(strlen(author) + 1); // Allocate memory for the author
    strcpy(book->author, author); // Copy the author into the book struct
    
    // Read the number of pages and their contents from the file
    fgets(line, sizeof(line), fp); // Read the second line
    int num_pages = atoi(line); // Convert the number of pages to an integer
    book->num_pages = num_pages; // Set the number of pages in the book struct
    book->pages = malloc(num_pages * sizeof(char *)); // Allocate memory for the pages
    for (int i = 0; i < num_pages; i++) {
        fgets(line, sizeof(line), fp); // Read a page from the file
        book->pages[i] = malloc(strlen(line) + 1); // Allocate memory for the page
        strcpy(book->pages[i], line); // Copy the page into the book struct
    }
    
    return book;
}

// A function to print an eBook to the console
void print_ebook(eBook *book) {
    // Print the title and author of the book
    printf("Title: %s\nAuthor: %s\n", book->title, book->author);
    
    // Print the pages of the book
    for (int i = 0; i < book->num_pages; i++) {
        printf("Page %d:\n%s", i + 1, book->pages[i]);
    }
}

// A function to free the memory allocated for an eBook
void free_ebook(eBook *book) {
    // Free the memory allocated for the title and author
    free(book->title);
    free(book->author);
    
    // Free the memory allocated for each page
    for (int i = 0; i < book->num_pages; i++) {
        free(book->pages[i]);
    }
    
    // Free the memory allocated for the pages array
    free(book->pages);
    
    // Free the memory allocated for the book struct
    free(book);
}

int main() {
    // Open the eBook file
    FILE *fp = fopen("ebook.txt", "r");
    if (fp == NULL) {
        printf("Error opening the eBook file!\n");
        return EXIT_FAILURE;
    }
    
    // Read the eBook from the file
    eBook *book = read_ebook(fp);
    
    // Close the eBook file
    fclose(fp);
    
    // Print the eBook to the console
    print_ebook(book);
    
    // Free the memory allocated for the eBook
    free_ebook(book);
    
    return EXIT_SUCCESS;
}