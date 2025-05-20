//FormAI DATASET v1.0 Category: Ebook reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[50];
    char author[50];
    char publisher[50];
    int year;
};

struct Ebook {
    char title[50];
    char author[50];
    char format[10];
    float size;
};

void display_menu() {
    printf("\n\n1. Import Books\n");
    printf("2. Import Ebooks\n");
    printf("3. View Books\n");
    printf("4. View Ebooks\n");
    printf("5. Exit\n");
}

int main() {
    int choice, num_books = 0, num_ebooks = 0;
    struct Book *books;
    struct Ebook *ebooks;
    
    while(1) {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter the number of books to import: ");
                scanf("%d", &num_books);
                books = (struct Book*) malloc(num_books * sizeof(struct Book));
                for(int i = 0; i < num_books; i++) {
                    printf("\nEnter the title of book %d: ", i+1);
                    getchar();
                    fgets(books[i].title, 50, stdin);
                    printf("Enter the author of book %d: ", i+1);
                    fgets(books[i].author, 50, stdin);
                    printf("Enter the publisher of book %d: ", i+1);
                    fgets(books[i].publisher, 50, stdin);
                    printf("Enter the publishing year of book %d: ", i+1);
                    scanf("%d", &books[i].year);
                }
                printf("\nImport successful!");
                break;
                
            case 2:
                printf("\nEnter the number of ebooks to import: ");
                scanf("%d", &num_ebooks);
                ebooks = (struct Ebook*) malloc(num_ebooks * sizeof(struct Ebook));
                for(int i = 0; i < num_ebooks; i++) {
                    printf("\nEnter the title of ebook %d: ", i+1);
                    getchar();
                    fgets(ebooks[i].title, 50, stdin);
                    printf("Enter the author of ebook %d: ", i+1);
                    fgets(ebooks[i].author, 50, stdin);
                    printf("Enter the format of ebook %d: ", i+1);
                    fgets(ebooks[i].format, 10, stdin);
                    printf("Enter the size of ebook %d: ", i+1);
                    scanf("%f", &ebooks[i].size);
                }
                printf("\nImport successful!");
                break;
                
            case 3:
                if(num_books == 0) {
                    printf("\nNo books have been imported yet!\n");
                    break;
                }
                printf("\nThe following books have been imported:\n");
                printf("Title\t\tAuthor\t\tPublisher\tYear\n");
                for(int i = 0; i < num_books; i++) {
                    printf("%s\t%s\t%s\t%d\n", books[i].title, books[i].author, books[i].publisher, books[i].year);
                }
                break;
                
            case 4:
                if(num_ebooks == 0) {
                    printf("\nNo ebooks have been imported yet!\n");
                    break;
                }
                printf("\nThe following ebooks have been imported:\n");
                printf("Title\t\tAuthor\t\tFormat\tSize\n");
                for(int i = 0; i < num_ebooks; i++) {
                    printf("%s\t%s\t%s\t%.2f\n", ebooks[i].title, ebooks[i].author, ebooks[i].format, ebooks[i].size);
                }
                break;
                
            case 5:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}