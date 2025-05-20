//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: genius
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 24

typedef struct {
    char *text;
    int len;
} TextBlock;

typedef struct {
    TextBlock *blocks;
    int numBlocks;
} Book;

Book *loadBook(const char *filename) {
    Book *book = malloc(sizeof(Book));
    book->numBlocks = 0;

    // Load the text file into a string array
    char *line = NULL;
    size_t len = 0;
    size_t cap = 1024;
    FILE *file = fopen(filename, "r");
    while (getline(&line, &len, file) >= 0) {
        book->blocks = realloc(book->blocks, (book->numBlocks + 1) * sizeof(TextBlock));
        book->blocks[book->numBlocks].text = line;
        book->blocks[book->numBlocks].len = strlen(line);
        book->numBlocks++;
    }
    free(line);
    fclose(file);

    return book;
}

void drawBook(Book *book) {
    // Calculate the total width and height of the book
    int totalWidth = 0;
    int totalHeight = 0;
    for (int i = 0; i < book->numBlocks; i++) {
        totalWidth += book->blocks[i].len;
        totalHeight += HEIGHT;
    }

    // Create a 2D array to store the text blocks
    char **textBlocks = malloc(totalWidth * HEIGHT * sizeof(char));

    // Draw each text block
    for (int i = 0; i < book->numBlocks; i++) {
        int x = (book->blocks[i].len / WIDTH) * WIDTH;
        int y = i * HEIGHT;
        printf("%s\n", book->blocks[i].text);
        for (int j = 0; j < WIDTH; j++) {
            textBlocks[x + j * HEIGHT] = book->blocks[i].text[j];
        }
    }

    // Print the final text
    for (int i = 0; i < totalWidth; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf("%c", textBlocks[i + j * totalWidth]);
        }
        printf("\n");
    }

    free(textBlocks);
}

int main() {
    // Load the book
    Book *book = loadBook("example.txt");

    // Draw the book
    drawBook(book);

    return 0;
}