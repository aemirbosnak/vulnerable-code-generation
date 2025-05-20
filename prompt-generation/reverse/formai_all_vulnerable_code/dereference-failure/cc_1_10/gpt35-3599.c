//FormAI DATASET v1.0 Category: Ebook reader ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure for book information
struct Book {
    char title[100];
    char author[100];
    int pageCount;
    float price;
};

//Structure for page information
struct Page {
    int pageNumber;
    char content[1000];
};

//Structure for Ebook information
struct Ebook {
    struct Book book;
    int currentPage;
    struct Page *pages;
};

//Function to read ebook information from file
void readEbookFromFile(struct Ebook *ebook, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        exit(1);
    }

    //Read book information
    fscanf(file, "%s", ebook->book.title);
    fscanf(file, "%s", ebook->book.author);
    fscanf(file, "%d", &ebook->book.pageCount);
    fscanf(file, "%f", &ebook->book.price);

    //Allocate memory for pages
    ebook->pages = (struct Page *) malloc(ebook->book.pageCount * sizeof(struct Page));

    //Read page information
    int i;
    for (i = 0; i < ebook->book.pageCount; i++) {
        fscanf(file, "%d", &ebook->pages[i].pageNumber);
        fgets(ebook->pages[i].content, 1000, file);
    }

    fclose(file);
}

//Function to display ebook information
void displayEbook(struct Ebook ebook) {
    printf("Title: %s\n", ebook.book.title);
    printf("Author: %s\n", ebook.book.author);
    printf("Page count: %d\n", ebook.book.pageCount);
    printf("Price: %.2f\n", ebook.book.price);
    printf("Current page: %d\n", ebook.currentPage);
    printf("Content: %s\n", ebook.pages[ebook.currentPage - 1].content);
}

int main() {
    struct Ebook ebook;
    char filename[] = "ebook.txt";
    readEbookFromFile(&ebook, filename);

    //Start reading from first page
    ebook.currentPage = 1;

    //Display ebook information
    displayEbook(ebook);

    //Read pages until end of book is reached
    printf("Press enter key to continue reading...");
    while (ebook.currentPage <= ebook.book.pageCount) {
        getchar();

        //Move to next page
        ebook.currentPage++;

        //Display ebook information
        displayEbook(ebook);

        //If end of book is reached, break out of loop
        if (ebook.currentPage > ebook.book.pageCount) {
            break;
        }

        printf("Press enter key to continue reading...");
    }

    free(ebook.pages);

    return 0;
}