//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Let's start our adventure with a pinch of curiosity.
FILE *book;
char *page;
int chapter, verse;

// Open the book and prepare for an immersive journey.
void open_book(char *filename) {
    book = fopen(filename, "r");
    if (book == NULL) {
        printf("Oops, I can't seem to find the book you're looking for.\n");
        exit(1);
    }
    page = malloc(1024);  // Allocate a page of ample size.
    chapter = 1;
    verse = 1;
}

// Step into a new chapter, turning the pages with anticipation.
void next_chapter() {
    chapter++;
    verse = 1;
    fseek(book, 0, SEEK_SET);  // Rewind to the beginning of the book.
    while (fgetc(book) != '\n');  // Skip the headers.
}

// Flip through the pages, verse by verse, unveiling the story.
void next_verse() {
    verse++;
    while (fgetc(book) != '\n');  // Skip to the end of the current verse.
    fgets(page, 1024, book);  // Read the next verse.
}

// Dive into the depths of the text, exploring its words and meanings.
void print_verse() {
    printf("Chapter %d, Verse %d:\n", chapter, verse);
    printf("%s", page);
}

// Close the book, bidding farewell to the tales it holds.
void close_book() {
    fclose(book);
    free(page);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Alas, you forgot to tell me which book to open.\n");
        exit(1);
    }

    open_book(argv[1]);  // Let's open the door to this mysterious book.

    // Embark on a literary expedition, chapter by chapter.
    while (!feof(book)) {
        print_verse();  // Let the words dance before your curious eyes.
        next_verse();  // Turn the page, eager to discover what lies ahead.
        printf("\n");
        if (fgetc(book) == '\n') next_chapter();  // Journey to the next chapter, if we've reached the end of this one.
    }

    close_book();  // Gently close the book, a treasure trove of tales left behind.
    return 0;
}