//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    char *content;
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

// Function to add a book to the library
void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    Book new_book;
    printf("Enter book title: ");
    getchar(); // Clear the newline from the buffer
    fgets(new_book.title, MAX_TITLE_LENGTH, stdin);
    // Remove newline character
    new_book.title[strcspn(new_book.title, "\n")] = 0;

    printf("Enter author name: ");
    fgets(new_book.author, MAX_AUTHOR_LENGTH, stdin);
    new_book.author[strcspn(new_book.author, "\n")] = 0;

    printf("Enter content (type 'END' on a new line to finish):\n");
    size_t content_size = 1024;
    new_book.content = malloc(content_size);
    new_book.content[0] = '\0';  // Initialize it
    char buffer[256];

    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        if (strcmp(buffer, "END\n") == 0) break;

        // Ensure we do not overflow the allocated content memory
        if (strlen(new_book.content) + strlen(buffer) >= content_size) {
            content_size *= 2;  // Double the size
            new_book.content = realloc(new_book.content, content_size);
        }
        
        strcat(new_book.content, buffer);
    }
    
    library[book_count] = new_book;
    book_count++;
    printf("Book added to the library!\n");
}

// Function to display all books in the library
void display_books() {
    if (book_count == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("Books in Library:\n");
    for (int i = 0; i < book_count; i++) {
        printf("Title: %s\nAuthor: %s\n", library[i].title, library[i].author);
    }
}

// Function to read the content of a specific book
void read_book() {
    if (book_count == 0) {
        printf("No books available to read.\n");
        return;
    }

    printf("Select a book (0 to %d): ", book_count - 1);
    int index;
    scanf("%d", &index);
    
    if (index < 0 || index >= book_count) {
        printf("Invalid selection.\n");
        return;
    }

    printf("\nReading '%s' by %s:\n", library[index].title, library[index].author);
    printf("%s\n", library[index].content);
}

// Function to free allocated memory when the program exits
void free_books() {
    for (int i = 0; i < book_count; i++) {
        free(library[i].content);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n=== E-Book Reader ===\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Read Book\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                display_books();
                break;
            case 3:
                read_book();
                break;
            case 4:
                free_books();
                printf("Exiting. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}