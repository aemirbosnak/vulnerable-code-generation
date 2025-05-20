//FormAI DATASET v1.0 Category: Ebook reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[50];
    char author[50];
    char format[10];
    int pages;
    int publicationYear;
};

int main() {
    struct Book myBook;
    
    strcpy(myBook.title, "The Art of War");
    strcpy(myBook.author, "Sun Tzu");
    strcpy(myBook.format, "EPUB");
    myBook.pages = 100;
    myBook.publicationYear = 500;
    
    // Opening the ebook
    FILE *fp = fopen("The_Art_of_War.epub", "rb");
    
    if (fp == NULL) {
        printf("Error opening ebook.\n");
        exit(1);
    }
    
    printf("Ebook opened successfully!\n");
    
    // Reading ebook contents
    char buffer[10000];
    int numBytesRead = fread(buffer, sizeof(char), 10000, fp);
    
    if (numBytesRead == 0) {
        printf("Error reading ebook.\n");
        exit(1);
    }
    
    printf("Ebook contents read successfully.\n");
    
    // Closing the ebook
    fclose(fp);
    
    printf("Ebook closed successfully!\n");
    
    // Displaying ebook details and contents
    printf("Title: %s\n", myBook.title);
    printf("Author: %s\n", myBook.author);
    printf("Format: %s\n", myBook.format);
    printf("Pages: %d\n", myBook.pages);
    printf("Publication Year: %d\n", myBook.publicationYear);
    printf("Contents:\n%s", buffer);
    
    return 0;
}