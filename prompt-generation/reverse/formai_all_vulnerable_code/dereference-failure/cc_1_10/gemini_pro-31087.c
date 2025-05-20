//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 1024

typedef struct {
    char* data;
    size_t size;
} Block;

typedef struct {
    Block* blocks;
    size_t num_blocks;
} Book;

Book* book_new() {
    Book* book = malloc(sizeof(Book));
    book->blocks = malloc(sizeof(Block) * 10);
    book->num_blocks = 0;
    return book;
}

void book_free(Book* book) {
    for (size_t i = 0; i < book->num_blocks; i++) {
        free(book->blocks[i].data);
    }
    free(book->blocks);
    free(book);
}

int book_add_block(Book* book, char* data, size_t size) {
    if (book->num_blocks >= 10) {
        return -1;
    }
    
    book->blocks[book->num_blocks].data = malloc(size + 1);
    memcpy(book->blocks[book->num_blocks].data, data, size);
    book->blocks[book->num_blocks].data[size] = '\0';
    book->blocks[book->num_blocks].size = size;
    book->num_blocks++;
    return 0;
}

void book_print(Book* book) {
    for (size_t i = 0; i < book->num_blocks; i++) {
        printf("%s", book->blocks[i].data);
    }
}

int main() {
    Book* book = book_new();
    char* data = "This is a test of the decentralized C Ebook reader.\n";
    book_add_block(book, data, strlen(data));
    book_print(book);
    book_free(book);
    return 0;
}