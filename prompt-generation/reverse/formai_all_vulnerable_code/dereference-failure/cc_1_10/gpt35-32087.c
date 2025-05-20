//FormAI DATASET v1.0 Category: Ebook reader ; Style: genious
#include <stdio.h>
#include <stdlib.h>

typedef struct book {
    char* title;
    char* author;
    int num_pages;
    char* ebook_file;
} Book;

int main() {
    int num_books;
    printf("Enter the number of books in your library: ");
    scanf("%d", &num_books);

    Book* library = (Book*)malloc(num_books * sizeof(Book));

    for (int i = 0; i < num_books; i++) {
        printf("\nBook %d:\n", i+1);

        // get book title
        printf("Enter the book title: ");
        char title[50];
        scanf(" %[^\n]s", title);
        library[i].title = (char*)malloc((strlen(title)+1) * sizeof(char));
        strcpy(library[i].title, title);

        // get book author
        printf("Enter the book author: ");
        char author[50];
        scanf(" %[^\n]s", author);
        library[i].author = (char*)malloc((strlen(author)+1) * sizeof(char));
        strcpy(library[i].author, author);

        // get number of pages
        printf("Enter the number of pages: ");
        scanf("%d", &library[i].num_pages);

        // get ebook file name
        printf("Enter the ebook file name: ");
        char ebook_file[50];
        scanf(" %[^\n]s", ebook_file);
        library[i].ebook_file = (char*)malloc((strlen(ebook_file)+1) * sizeof(char));
        strcpy(library[i].ebook_file, ebook_file);
    }

    // display library
    printf("\nYour library contains the following books:\n");
    for (int i = 0; i < num_books; i++) {
        printf("\nBook %d:\nTitle: %s\nAuthor: %s\nNumber of pages: %d\nEbook file: %s\n", i+1, library[i].title, library[i].author, library[i].num_pages, library[i].ebook_file);
    }

    // find ebook file example
    printf("\nEnter the title of the ebook you want to open: ");
    char ebook[50];
    scanf(" %[^\n]s", ebook);
    for (int i = 0; i < num_books; i++) {
        if (strcmp(library[i].title, ebook) == 0) {
            printf("\nOpening ebook %s...", ebook);
            system(library[i].ebook_file);
            return 0;
        }
    }
    printf("\nEbook %s not found in library.\n", ebook);

    return 0;
}