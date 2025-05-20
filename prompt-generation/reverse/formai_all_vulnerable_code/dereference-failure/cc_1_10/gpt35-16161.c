//FormAI DATASET v1.0 Category: Database simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold information about a book
typedef struct {
    int id;
    char title[50];
    char author[50];
    int year;
} Book;

// Function to print the database
void printDatabase(Book *database, int numOfBooks) {
    printf("\n---------------------------------\n");
    printf("    MEDIEVAL BOOK DATABASE");
    printf("\n---------------------------------\n");
    printf("ID\t  TITLE\t\tAUTHOR\t  YEAR\n");
    printf("---------------------------------\n");
    for(int i=0; i<numOfBooks; i++) {
        printf("%d\t  %-15s %-15s %d\n", database[i].id, database[i].title, database[i].author, database[i].year);
    }
    printf("---------------------------------\n");
}

int main() {
    int numOfBooks = 0;
    int maxNumOfBooks = 10;
    Book *database = malloc(maxNumOfBooks * sizeof(Book));

    // Populate the database with some sample data
    Book book1 = {1, "The Knight's Tale", "Geoffrey Chaucer", 1387};
    database[0] = book1;
    numOfBooks++;

    Book book2 = {2, "Le Morte d'Arthur", "Thomas Malory", 1485};
    database[1] = book2;
    numOfBooks++;

    Book book3 = {3, "The Canterbury Tales", "Geoffrey Chaucer", 1400};
    database[2] = book3;
    numOfBooks++;

    // Print the initial database
    printDatabase(database, numOfBooks);

    // Add a new book to the database
    Book newBook = {4, "Sir Gawain and the Green Knight", "Unknown", 1400};

    if(numOfBooks == maxNumOfBooks) {
        // If the database is full, allocate more memory
        maxNumOfBooks = maxNumOfBooks*2;
        database = realloc(database, maxNumOfBooks * sizeof(Book));
    }

    database[numOfBooks] = newBook;
    numOfBooks++;

    // Print the updated database
    printDatabase(database, numOfBooks);

    // Search for a book in the database
    char searchTerm[50];
    printf("\nEnter a search term: ");
    scanf("%s", searchTerm);

    int resultsFound = 0;
    for(int i=0; i<numOfBooks; i++) {
        if(strstr(database[i].title, searchTerm) != NULL) {
            printf("%d\t  %-15s %-15s %d\n", database[i].id, database[i].title, database[i].author, database[i].year);
            resultsFound++;
        }
    }

    if(resultsFound == 0) {
        printf("No results found.\n");
    }

    // Free the memory
    free(database);
    database = NULL;

    return 0;
}