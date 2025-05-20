//FormAI DATASET v1.0 Category: Ebook reader ; Style: complete
#include <stdio.h>
#include <stdlib.h>

struct Book {
    char title[50];
    char author[50];
    int pages;
    float price;
};

int main() {
    int num_books;
    printf("Enter number of books: ");
    scanf("%d", &num_books);

    struct Book library[num_books];

    // Initialize book library
    for(int i=0; i<num_books; i++) {
        printf("\nBook %d:\n", i+1);
        printf("Title: ");
        scanf("%s", library[i].title);
        printf("Author: ");
        scanf("%s", library[i].author);
        printf("Pages: ");
        scanf("%d", &library[i].pages);
        printf("Price: ");
        scanf("%f", &library[i].price);
    }

    // Display book library
    printf("\nBook Library:\n");
    for(int i=0; i<num_books; i++) {
        printf("\nBook %d\n", i+1);
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n", library[i].author);
        printf("Pages: %d\n", library[i].pages);
        printf("Price: $%.2f\n", library[i].price);
    }

    // Ebook reader functionality
    int book_choice;
    while(1) {
        printf("\nEnter book number to read (0 to exit): ");
        scanf("%d", &book_choice);
        if(book_choice == 0) {
            break;
        }
        if(book_choice > num_books || book_choice < 1) {
            printf("Invalid book choice!\n");
            continue;
        }
        printf("\n***Reading %s by %s***\n", library[book_choice-1].title, library[book_choice-1].author);
        printf("Press enter to turn the page.\n");
        while(getchar() != '\n');
        char user_input[2];
        int curr_page = 1;
        while(1) {
            printf("\nPage %d\n", curr_page);
            printf("------------------------------------------------------\n");
            // Open ebook file
            char ebook_file_name[60];
            sprintf(ebook_file_name, "%s/ebook%d.html", library[book_choice-1].title, curr_page);
            FILE *fp = fopen(ebook_file_name, "r");
            if(fp == NULL) {
                printf("Error: Either the ebook file does not exist or could not be opened!\n");
                break;
            }
            // Read ebook page content from file and display on console
            char ebook_page_content[1000];
            int read_chars = fread(ebook_page_content, sizeof(char), 1000, fp);
            ebook_page_content[read_chars] = '\0';
            printf("%s\n", ebook_page_content);
            // Close ebook file
            fclose(fp);
            // Check if last page of ebook is reached
            if(feof(fp)) {
                printf("End of %s ebook reached.\n", library[book_choice-1].title);
                break;
            }
            // Wait for user input to turn page
            printf("------------------------------------------------------\n");
            printf("\nEnter 'n' to go to next page, 'b' to go to previous page or 'x' to exit: ");
            scanf("%s", user_input);
            if(user_input[0] == 'n') {
                curr_page++;
            } else if(user_input[0] == 'b') {
                curr_page--;
                if(curr_page < 1) {
                    printf("Already at first page.\n");
                    curr_page = 1;
                }
            } else if(user_input[0] == 'x') {
                break;
            } else {
                printf("Invalid input!\n");
            }
        }
    }

    return 0;
}