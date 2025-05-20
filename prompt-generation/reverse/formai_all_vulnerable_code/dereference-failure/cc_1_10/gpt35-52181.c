//FormAI DATASET v1.0 Category: Ebook reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 50
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_CHAPTERS 100
#define MAX_CHAPTER_LENGTH 2000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char chapters[MAX_CHAPTERS][MAX_CHAPTER_LENGTH];
    int num_chapters;
} book;

char* read_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    
    if (!file) {
        printf("Error opening file!\n");
        return NULL;
    }
    
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    char* buffer = (char*)malloc(sizeof(char) * (file_size + 1));
    rewind(file);
    
    fread(buffer, sizeof(char), file_size, file);
    buffer[file_size] = '\0';
    
    fclose(file);
    return buffer;
}

void load_book(book* new_book, const char* filename) {
    char* file_data = read_file(filename);
    
    if (!file_data) {
        printf("Could not load book!\n");
        return;
    }
    
    char* token = strtok(file_data, "\n");
    strncpy(new_book->title, token, MAX_TITLE_LENGTH);
    
    token = strtok(NULL, "\n");
    strncpy(new_book->author, token, MAX_AUTHOR_LENGTH);
    
    new_book->num_chapters = 0;
    while ((token = strtok(NULL, "\n")) && new_book->num_chapters < MAX_CHAPTERS) {
        strncpy(new_book->chapters[new_book->num_chapters], token, MAX_CHAPTER_LENGTH);
        ++new_book->num_chapters;
    }
    
    free(file_data);
}

void print_book_info(const book* my_book) {
    printf("Title: %s\n", my_book->title);
    printf("Author: %s\n", my_book->author);
    printf("Number of chapters: %d\n", my_book->num_chapters);
}

void print_chapter(const book* my_book, int chapter_num) {
    if (chapter_num < 0 || chapter_num >= my_book->num_chapters) {
        printf("Chapter does not exist!\n");
        return;
    }
    
    printf("Chapter %d:\n%s\n", chapter_num + 1, my_book->chapters[chapter_num]);
}

void print_all_chapters(const book* my_book) {
    printf("%s by %s\n", my_book->title, my_book->author);
    for (int i = 0; i < my_book->num_chapters; ++i) {
        printf("\nChapter %d:\n%s", i + 1, my_book->chapters[i]);
    }
}

int main() {
    book my_book;
    load_book(&my_book, "my_book.txt");
    print_book_info(&my_book);
    print_chapter(&my_book, 5);
    print_all_chapters(&my_book);
    return 0;
}