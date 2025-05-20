//FormAI DATASET v1.0 Category: Ebook reader ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book {
    char* title;
    int num_pages;
    char* author;
    char* filename;
} Book;

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <book filename>\n", argv[0]);
        return 1;
    }
    
    char* filename = argv[1];
    
    Book* book = malloc(sizeof(Book));
    book->filename = filename;
    
    FILE* fp;
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: unable to open file %s\n", filename);
        return 1;
    }
    
    // read book information from file
    char temp[256];
    fgets(temp, 256, fp);
    book->title = strdup(temp);
    fgets(temp, 256, fp);
    book->num_pages = atoi(temp);
    fgets(temp, 256, fp);
    book->author = strdup(temp);
    
    fclose(fp);
    
    printf("Title: %s", book->title);
    printf("Author: %s", book->author);
    printf("Number of pages: %d", book->num_pages);
    
    printf("Entering Ebook reader mode...\n");
    
    // read book contents into memory
    fp = fopen(book->filename, "rb");
    if (fp == NULL) {
        printf("Error: unable to open file %s\n", book->filename);
        return 1;
    }
    
    fseek(fp, strlen(book->title) + strlen(book->author) + 1 + strlen(book->num_pages) + 2, SEEK_SET);
    char* contents = malloc(book->num_pages + 1);
    fread(contents, book->num_pages, 1, fp);
    fclose(fp);
    contents[book->num_pages] = '\0';
    
    printf("Book contents:\n%s", contents);
    
    return 0;
}