//FormAI DATASET v1.0 Category: Ebook reader ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Book {                    
    char title[50];
    char author[50];
    int pages;
    float price;
};

void displayBook(struct Book b) {  //function to display book
    printf("\nTitle: %s", b.title);
    printf("\nAuthor: %s", b.author);
    printf("\nPages: %d", b.pages);
    printf("\nPrice: $%.2f", b.price);
}

void readBook(struct Book *b) {   //function to read book
    printf("\n\nPlease enter the details of the book:\n");
    printf("\nTitle: ");
    scanf("%[^\n]%*c", b->title);  //accepts string with spaces
    printf("Author: ");
    scanf("%[^\n]%*c", b->author);
    printf("Pages: ");
    scanf("%d", &b->pages);
    printf("Price: ");
    scanf("%f", &b->price);
}

int main() {
    int choice, i, n;
    printf("\nWelcome to the C Ebook Reader!\n\n");
    printf("Please enter the number of books you wish to read: ");
    scanf("%d", &n);

    struct Book library[n];     //creating an array of Books

    for(i=0;i<n;i++) {          //reading details of all the books
        readBook(&library[i]);
    }

    do {                        //menu-driven program
        printf("\n\nMenu\n\n");
        printf("1. Display all books\n");
        printf("2. Search for a book by title\n");
        printf("3. Filter books by author\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:                     //display all books
                printf("\n\nAll Books:\n\n");
                for(i=0;i<n;i++) {
                    displayBook(library[i]);
                    printf("\n\n");
                }
                break;

            case 2: {                   //search for a book by title
                char search_title[50];
                int flag = 0;
                printf("\n\nEnter the title of the book you wish to search: ");
                scanf(" %[^\n]%*c", search_title);
                for(i=0;i<n;i++) {
                    if(strcmp(search_title,library[i].title)==0) {
                        displayBook(library[i]);
                        flag = 1;
                        break;
                    }
                }
                if(flag==0) {
                    printf("\n\nBook not found.\n");
                }
                break;
            }

            case 3: {                   //filter books by author
                char filter_author[50];
                int flag = 0;
                printf("\n\nEnter the author name to filter books: ");
                scanf(" %[^\n]%*c", filter_author);
                printf("\nBooks by %s:\n\n", filter_author);
                for(i=0;i<n;i++) {
                    if(strcmp(filter_author,library[i].author)==0) {
                        displayBook(library[i]);
                        printf("\n\n");
                        flag = 1;
                    }
                }
                if(flag==0) {
                    printf("\n\nNo books found by %s.\n", filter_author);
                }
                break;
            }

            case 4:                     //exit program
                printf("\nThank you for using the C Ebook Reader!\n");
                exit(0);

            default:                    //incorrect choice
                printf("\nPlease enter a valid choice!\n");
        }
    } while(1);

    return 0;
}