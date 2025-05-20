//FormAI DATASET v1.0 Category: Ebook reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10

/* Structure to store book details */
typedef struct {
    char title[50];
    char author[50];
    int year;
    char filename[50];
    int size;
} Book;

/* Array to store all the books */
Book books[MAX_BOOKS];

/* Function to read book details from file */
void readBookFromFile(Book *book, char *filename) {
    FILE *fp;
    char line[100];
    char *token;
    
    fp = fopen(filename, "r");
    fgets(line, sizeof(line), fp);
    strcpy(book->title, line);
    fgets(line, sizeof(line), fp);
    strcpy(book->author, line);
    fgets(line, sizeof(line), fp);
    book->year = atoi(line);
    fseek(fp, 0, SEEK_END);
    book->size = ftell(fp) - ftell(fp) % 512;  // Round size down to multiple of 512 bytes
    fseek(fp, book->size, SEEK_SET);  // Jump to end of file
    fgets(line, sizeof(line), fp);  // Read last line
    strtok(line, "\n");  // Remove newline from end of line
    strcpy(book->filename, line);  // Set filename
    fclose(fp);
}

int main() {
    int num_books = 0;
    int i, choice;
    char search_title[50];
    Book *book;
    
    /* Read book details from file */
    readBookFromFile(&books[num_books], "book1.txt");
    num_books++;
    readBookFromFile(&books[num_books], "book2.txt");
    num_books++;
    
    /* Display menu */
    do {
        printf("EBook Reader Menu\n");
        printf("-----------------\n");
        printf("1. Search for a book\n");
        printf("2. Display all books\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                /* Search for a book */
                printf("Enter title to search for: ");
                scanf("%s", search_title);
                for (i = 0; i < num_books; i++) {
                    if (strcmp(books[i].title, search_title) == 0) {
                        book = &books[i];
                        printf("Book found:\n");
                        printf("Title: %s\n", book->title);
                        printf("Author: %s\n", book->author);
                        printf("Year: %d\n", book->year);
                        printf("Size: %d bytes\n", book->size);
                        printf("Filename: %s\n", book->filename);
                        break;
                    }
                }
                if (i == num_books) {
                    printf("Book not found.\n");
                }
                break;
            case 2:
                /* Display all books */
                for (i = 0; i < num_books; i++) {
                    book = &books[i];
                    printf("Book %d:\n", i+1);
                    printf("Title: %s\n", book->title);
                    printf("Author: %s\n", book->author);
                    printf("Year: %d\n", book->year);
                    printf("Size: %d bytes\n", book->size);
                    printf("Filename: %s\n", book->filename);
                }
                break;
            case 3:
                /* Exit */
                printf("Goodbye!\n");
                break;
            default:
                /* Invalid input */
                printf("Invalid choice, try again.\n");
                break;
        }
    } while (choice != 3);
    
    return 0;
}