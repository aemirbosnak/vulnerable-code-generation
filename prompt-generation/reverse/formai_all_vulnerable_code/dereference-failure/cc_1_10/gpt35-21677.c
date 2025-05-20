//FormAI DATASET v1.0 Category: Ebook reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

struct eBook {
    char title[50];
    char author[50];
    char format[10];
    int numOfPages;
    float fileSize;
    char* content;
};

void displayBookInfo(struct eBook book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Format: %s\n", book.format);
    printf("Number of pages: %d\n", book.numOfPages);
    printf("File size: %.2f MB\n", book.fileSize);
}

void displayBookContent(struct eBook book) {
    printf("%s", book.content);
}

int main() {
    struct eBook myBook;
    FILE *fp;
    long fileSize;
    char *buffer;
    
    // Open eBook file
    fp = fopen("myBook.epub", "rb");
    if(fp == NULL) {
        printf("Error opening eBook file.");
        exit(1);
    }
    
    // Get file size
    fseek(fp, 0L, SEEK_END);
    fileSize = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    
    // Allocate memory for buffer
    buffer = (char*)malloc(fileSize * sizeof(char));
    if(buffer == NULL) {
        printf("Memory not allocated.");
        exit(1);
    }
    
    // Read file into buffer
    fread(buffer, fileSize, 1, fp);
    
    // Populate eBook struct
    strcpy(myBook.title, "My Awesome eBook");
    strcpy(myBook.author, "Jane Doe");
    strcpy(myBook.format, "epub");
    myBook.numOfPages = 100;
    myBook.fileSize = fileSize / (1024.0 * 1024.0); // convert to MB
    myBook.content = buffer;
    
    // Display eBook info and content
    displayBookInfo(myBook);
    displayBookContent(myBook);
    
    // Close file and free memory
    fclose(fp);
    free(buffer);
    
    return 0;
}