//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct Page {
    int pageNumber;
    char *content;
    struct Page *next;
} Page;

typedef struct Chapter {
    int chapterNumber;
    struct Page *pages;
    struct Chapter *next;
} Chapter;

typedef struct Book {
    char *title;
    struct Chapter *chapters;
} Book;

Book *createBook(char *title);
Chapter *createChapter(int chapterNumber);
Page *createPage(int pageNumber, char *content);
void addChapter(Book *book, Chapter *chapter);
void addPage(Chapter *chapter, Page *page);
void readChapter(Chapter *chapter);
void readPage(Page *page);
void freeBook(Book *book);
void freeChapter(Chapter *chapter);
void freePage(Page *page);

int main() {
    Book *myBook = createBook("The Great Adventure");

    Chapter *chapter1 = createChapter(1);
    addPage(chapter1, createPage(1, "In the beginning..."));
    addPage(chapter1, createPage(2, "The first challenge..."));

    Chapter *chapter2 = createChapter(2);
    addPage(chapter2, createPage(1, "The journey continues..."));
    addPage(chapter2, createPage(2, "A new ally appears..."));

    addChapter(myBook, chapter1);
    addChapter(myBook, chapter2);

    printf("Reading '%s'\n", myBook->title);
    readChapter(myBook->chapters);

    freeBook(myBook);
    return 0;
}

Book *createBook(char *title) {
    Book *book = (Book *)malloc(sizeof(Book));
    book->title = title;
    book->chapters = NULL;
    return book;
}

Chapter *createChapter(int chapterNumber) {
    Chapter *chapter = (Chapter *)malloc(sizeof(Chapter));
    chapter->chapterNumber = chapterNumber;
    chapter->pages = NULL;
    chapter->next = NULL;
    return chapter;
}

Page *createPage(int pageNumber, char *content) {
    Page *page = (Page *)malloc(sizeof(Page));
    page->pageNumber = pageNumber;
    page->content = content;
    page->next = NULL;
    return page;
}

void addChapter(Book *book, Chapter *chapter) {
    chapter->next = book->chapters;
    book->chapters = chapter;
}

void addPage(Chapter *chapter, Page *page) {
    page->next = chapter->pages;
    chapter->pages = page;
}

void readChapter(Chapter *chapter) {
    if (chapter == NULL) {
        return;
    }
    printf("\n--- Chapter %d ---\n", chapter->chapterNumber);
    readPage(chapter->pages);
    readChapter(chapter->next);
}

void readPage(Page *page) {
    if (page == NULL) {
        return;
    }
    printf("Page %d: %s\n", page->pageNumber, page->content);
    readPage(page->next);
}

void freeBook(Book *book) {
    if (book == NULL) {
        return;
    }
    freeChapter(book->chapters);
    free(book);
}

void freeChapter(Chapter *chapter) {
    if (chapter == NULL) {
        return;
    }
    freePage(chapter->pages);
    freeChapter(chapter->next);
    free(chapter);
}

void freePage(Page *page) {
    if (page == NULL) {
        return;
    }
    freePage(page->next);
    free(page);
}