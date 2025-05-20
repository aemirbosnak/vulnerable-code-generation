//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: puzzling
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// The book's chapters and pages
char *book[] = {
    "Once upon a time, there was a little girl who loved to read.",
    "She would spend hours curled up in her favorite chair, lost in a world of stories.",
    "One day, she found a mysterious book hidden in the attic.",
    "It was an old and dusty book, with a strange symbol on the cover.",
    "The girl couldn't resist opening the book, and as she did, she was transported to a magical land.",
    "In this land, the girl met talking animals, friendly giants, and even a wise old wizard.",
    "She had many adventures in this magical land, but she always knew that she would eventually have to return home.",
    "When she finally did, she was a changed girl.",
    "She had learned the importance of imagination and the power of stories.",
    "And she knew that she would never forget her time in the magical land.",
};

// The page numbers
int pages[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// The current page
int currentPage = 0;

// Print the current page
void printPage() {
    printf("%s\n", book[currentPage]);
}

// Go to the next page
void nextPage() {
    if (currentPage < 9) {
        currentPage++;
    }
}

// Go to the previous page
void previousPage() {
    if (currentPage > 0) {
        currentPage--;
    }
}

// Go to a specific page
void goToPage(int page) {
    if (page >= 1 && page <= 10) {
        currentPage = page - 1;
    }
}

// Get the number of pages in the book
int getNumberOfPages() {
    return sizeof(pages) / sizeof(int);
}

// Open text file and read it as a string
char *readfile(char *filename) {
    FILE *fp = fopen(filename, "r");
    fseek(fp, 0, SEEK_END);
    long int size = ftell(fp);
    rewind(fp);
    char *str = (char *)malloc(size + 1);
    fread(str, sizeof(char), size, fp);
    fclose(fp);
    str[size] = '\0';
    return str;
}

// Main function
int main() {
    // Print the introduction
    printf("Welcome to the E-Book Reader!\n");

    // Get the book filename
    char *filename = "book.txt";

    // Read the book from the file
    char *book_content = readfile(filename);

    // Split the book into chapters and pages
    char *chapter_delimiter = "\n\n";
    char *page_delimiter = "\n";
    char *chapter_start = book_content;
    char *chapter_end;
    char *page_start;
    char *page_end;
    int chapter_count = 0;
    int page_count = 0;

    while (chapter_start) {
        chapter_end = strstr(chapter_start, chapter_delimiter);
        page_start = chapter_start;
        page_count = 0;

        while (page_start) {
            page_end = strstr(page_start, page_delimiter);
            if (page_end) {
                book[page_count] = strndup(page_start, page_end - page_start);
                page_count++;
                page_start = page_end + 1;
            } else {
                book[page_count] = strdup(page_start);
                page_count++;
                page_start = NULL;
            }
        }

        pages[chapter_count] = page_count;
        chapter_count++;
        chapter_start = chapter_end ? chapter_end + strlen(chapter_delimiter) : NULL;
    }

    // Print the book's chapters and pages
    for (int i = 0; i < chapter_count; i++) {
        printf("Chapter %d:\n", i + 1);
        for (int j = 0; j < pages[i]; j++) {
            printf("  Page %d:\n", j + 1);
            printPage();
            nextPage();
        }
        previousPage();
    }

    // Free the allocated memory
    free(book_content);
    for (int i = 0; i < chapter_count; i++) {
        free(book[i]);
    }

    // Return 0 to indicate success
    return 0;
}