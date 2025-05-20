//Falcon2-11B DATASET v1.0 Category: Music Library Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100
#define MAX_BOOKS 100

typedef struct {
    char name[MAX_LEN];
    int price;
} Book;

typedef struct {
    char name[MAX_LEN];
    int totalBooks;
    Book books[MAX_BOOKS];
} Library;

int main() {
    Library library;
    Library *libraries[100];
    int numLibraries, i;

    // Initialize libraries
    for (i = 0; i < 100; i++) {
        libraries[i] = (Library*)malloc(sizeof(Library));
        strcpy(libraries[i]->name, "Library ");
        libraries[i]->totalBooks = 0;
        for (int j = 0; j < MAX_BOOKS; j++) {
            libraries[i]->books[j].price = 0;
            strcpy(libraries[i]->books[j].name, "");
        }
    }

    // User input
    printf("Enter number of libraries: ");
    scanf("%d", &numLibraries);

    printf("Enter library name: ");
    scanf("%s", libraries[0]->name);
    for (i = 1; i < numLibraries; i++) {
        printf("Enter library name: ");
        scanf("%s", libraries[i]->name);
    }

    // Library operations
    for (i = 0; i < numLibraries; i++) {
        printf("Library %s:\n", libraries[i]->name);
        printf("Total books: %d\n", libraries[i]->totalBooks);
        for (int j = 0; j < MAX_BOOKS; j++) {
            printf("Book %s ($%d)\n", libraries[i]->books[j].name, libraries[i]->books[j].price);
        }
    }

    return 0;
}