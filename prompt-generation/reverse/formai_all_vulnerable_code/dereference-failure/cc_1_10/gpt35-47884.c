//FormAI DATASET v1.0 Category: Ebook reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 100
#define MAX_TITLE_LEN 50
#define MAX_AUTHOR_LEN 30

struct EBook{
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int year;
    int pageCount;
    char* pages[MAX_PAGES];
};

void readEBook(struct EBook* book){
    printf("Enter the title of the book: ");
    fgets(book->title, MAX_TITLE_LEN, stdin);
    printf("Enter the author of the book: ");
    fgets(book->author, MAX_AUTHOR_LEN, stdin);
    printf("Enter the year of publication: ");
    scanf("%d", &book->year);
    printf("Enter the total number of pages: ");
    scanf("%d", &book->pageCount);
    getchar();
    printf("Enter the content of the book page by page:\n");
    for(int i=0; i<book->pageCount; i++){
        book->pages[i] = (char*)malloc(sizeof(char)*1000);
        fgets(book->pages[i], 1000, stdin);
    }
}

void printEBook(struct EBook* book){
    printf("---------------------------\n");
    printf("Title: %s", book->title);
    printf("Author: %s", book->author);
    printf("Year: %d\n", book->year);
    printf("Total Pages: %d\n", book->pageCount);
    printf("---------------------------\n");
    printf("Contents:\n");
    for(int i=0; i<book->pageCount; i++){
        printf("%s", book->pages[i]);
    }
}

void destroyEBook(struct EBook* book){
    for(int i=0; i<book->pageCount; i++){
        free(book->pages[i]);
    }
}

int main(){
    struct EBook* book = (struct EBook*)malloc(sizeof(struct EBook));
    readEBook(book);
    printEBook(book);
    destroyEBook(book);
    free(book);
    return 0;
}