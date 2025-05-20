//FormAI DATASET v1.0 Category: Memory management ; Style: creative
#include <stdlib.h>
#include <stdio.h>

/* Define a structure to represent a book */
typedef struct{
    char* title;
    char* author;
    int pages;
} Book;

int main(){
    /* Allocate memory for a new book */
    Book* newBook = (Book*) malloc(sizeof(Book));
    
    /* Check if the memory allocation succeeded */
    if(newBook == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    /* Allocate memory for the book's attributes */
    newBook->title = (char*) malloc(50 * sizeof(char));
    newBook->author = (char*) malloc(30 * sizeof(char));
    
    /* Check if the memory allocation succeeded */
    if(newBook->title == NULL || newBook->author == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    /* Set the book's attributes */
    printf("Enter the book's title: ");
    fgets(newBook->title, 50, stdin);
    printf("Enter the book's author: ");
    fgets(newBook->author, 30, stdin);
    printf("Enter the number of pages in the book: ");
    scanf("%d", &newBook->pages);
    
    /* Print the book's information */
    printf("\nBook information:\n");
    printf("Title: %s", newBook->title);
    printf("Author: %s", newBook->author);
    printf("Pages: %d\n", newBook->pages);
    
    /* Free up the allocated memory */
    free(newBook->title);
    free(newBook->author);
    free(newBook);
    
    /* Exit the program */
    return 0;
}