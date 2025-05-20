//FormAI DATASET v1.0 Category: Ebook reader ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[50];
    char author[50];
    char publisher[50];
    char filename[50];
};

void display_menu();
void display_book(struct Book book);

int main() {
    // Create some sample books
    struct Book book1 = {"The Great Gatsby", "F. Scott Fitzgerald", "Scribner", "great_gatsby.epub"};
    struct Book book2 = {"Moby Dick", "Herman Melville", "Harper & Brothers", "moby_dick.epub"};
    struct Book book3 = {"Pride and Prejudice", "Jane Austen", "T. Egerton, Whitehall", "pride_and_prejudice.epub"};

    // Store the books in an array
    struct Book books[3] = {book1, book2, book3};

    int book_choice = 0;
    int font_size = 12;
    int line_spacing = 1;
    char input[50];

    // Display the menu and prompt the user for input
    display_menu();
    printf("\nBook choice: ");
    fgets(input, 50, stdin);
    book_choice = atoi(input);

    // Validate the user's input
    if (book_choice < 1 || book_choice > 3) {
        printf("Invalid book choice");
        return 1;
    }

    // Load the selected book
    struct Book selected_book = books[book_choice - 1];

    // Display the book's title and author
    display_book(selected_book);

    // Prompt the user for font size and line spacing
    printf("\nEnter font size (default is 12): ");
    fgets(input, 50, stdin);
    font_size = atoi(input);
    printf("Enter line spacing (default is 1): ");
    fgets(input, 50, stdin);
    line_spacing = atoi(input);

    // Load the book's contents from the file
    FILE* file = fopen(selected_book.filename, "r");
    if (file == NULL) {
        printf("Error opening book file");
        return 1;
    }
    fseek(file, 0, SEEK_END);
    int filesize = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* contents = malloc(filesize + 1);
    fread(contents, filesize, 1, file);
    contents[filesize] = '\0';
    fclose(file);

    // Display the book's contents with the selected font size and line spacing
    printf("\n\n");
    int i = 0;
    while (contents[i] != '\0') {
        if (contents[i] == '<') {
            // Process HTML tags
            while (contents[i] != '>' && contents[i] != '\0') {
                i++;
            }
        } else {
            // Print normal text with the selected font size and line spacing
            printf("%c", contents[i]);
            if (contents[i] == '\n') {
                for (int j = 0; j < line_spacing; j++) {
                    printf("\n");
                }
            }
        }
        i++;
    }

    free(contents);
    return 0;
}

void display_menu() {
    printf("Please choose a book by entering its number:\n");
    printf("1. The Great Gatsby\n");
    printf("2. Moby Dick\n");
    printf("3. Pride and Prejudice\n");
}

void display_book(struct Book book) {
    printf("\n\n%s\n", book.title);
    printf("by %s\n", book.author);
}