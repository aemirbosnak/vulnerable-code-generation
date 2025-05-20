//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOOK_FILE_NAME "ebook.txt"
#define LINE_SIZE 80

void read_book(char* book_file_name);
void display_book(char* book_file_name);
void close_book(char* book_file_name);

int main() {
    char* book_file_name = (char*)malloc(sizeof(char) * strlen(BOOK_FILE_NAME) + 1);
    strcpy(book_file_name, BOOK_FILE_NAME);
    
    read_book(book_file_name);
    display_book(book_file_name);
    close_book(book_file_name);
    
    free(book_file_name);
    
    return 0;
}

void read_book(char* book_file_name) {
    FILE* book_file = fopen(book_file_name, "r");
    
    if (book_file == NULL) {
        printf("Error opening file %s\n", book_file_name);
        return;
    }
    
    char line[LINE_SIZE];
    while (fgets(line, LINE_SIZE, book_file)!= NULL) {
        printf("%s\n", line);
    }
    
    fclose(book_file);
}

void display_book(char* book_file_name) {
    FILE* book_file = fopen(book_file_name, "r");
    
    if (book_file == NULL) {
        printf("Error opening file %s\n", book_file_name);
        return;
    }
    
    char line[LINE_SIZE];
    while (fgets(line, LINE_SIZE, book_file)!= NULL) {
        printf("%s\n", line);
    }
    
    fclose(book_file);
}

void close_book(char* book_file_name) {
    FILE* book_file = fopen(book_file_name, "w");
    
    if (book_file == NULL) {
        printf("Error opening file %s\n", book_file_name);
        return;
    }
    
    fclose(book_file);
}