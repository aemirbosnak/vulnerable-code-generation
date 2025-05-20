//FormAI DATASET v1.0 Category: Database Indexing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for storing books
typedef struct {
    int id;
    char title[50];
    char author[50];
    char genre[20];
} Book;

// Struct for storing indexes
typedef struct {
    int id;
    long offset;
} Index;

// Function to compare IDs
int cmpID(const void* a, const void* b) {
    Index* x = (Index*)a;
    Index* y = (Index*)b;
    return x->id - y->id;
}

// Function to compare titles
int cmpTitle(const void* a, const void* b) {
    Index* x = (Index*)a;
    Index* y = (Index*)b;
    Book book1, book2;
    FILE* db = fopen("books.db", "rb");
    fseek(db, x->offset, SEEK_SET);
    fread(&book1, sizeof(Book), 1, db);
    fseek(db, y->offset, SEEK_SET);
    fread(&book2, sizeof(Book), 1, db);
    fclose(db);
    return strcmp(book1.title, book2.title);
}

// Function to compare authors
int cmpAuthor(const void* a, const void* b) {
    Index* x = (Index*)a;
    Index* y = (Index*)b;
    Book book1, book2;
    FILE* db = fopen("books.db", "rb");
    fseek(db, x->offset, SEEK_SET);
    fread(&book1, sizeof(Book), 1, db);
    fseek(db, y->offset, SEEK_SET);
    fread(&book2, sizeof(Book), 1, db);
    fclose(db);
    return strcmp(book1.author, book2.author);
}

// Function to compare genres
int cmpGenre(const void* a, const void* b) {
    Index* x = (Index*)a;
    Index* y = (Index*)b;
    Book book1, book2;
    FILE* db = fopen("books.db", "rb");
    fseek(db, x->offset, SEEK_SET);
    fread(&book1, sizeof(Book), 1, db);
    fseek(db, y->offset, SEEK_SET);
    fread(&book2, sizeof(Book), 1, db);
    fclose(db);
    return strcmp(book1.genre, book2.genre);
}

int main() {
    // Creating indexes
    Index* idIndex = malloc(5 * sizeof(Index));
    Index* titleIndex = malloc(5 * sizeof(Index));
    Index* authorIndex = malloc(5 * sizeof(Index));
    Index* genreIndex = malloc(5 * sizeof(Index));

    // Initializing indexes
    idIndex[0].id = 1;
    idIndex[0].offset = 0;

    titleIndex[0].id = 1;
    titleIndex[0].offset = 0;

    authorIndex[0].id = 1;
    authorIndex[0].offset = 0;

    genreIndex[0].id = 1;
    genreIndex[0].offset = 0;

    // Creating database file
    FILE* db = fopen("books.db", "wb");
    Book book1 = {1, "The Hobbit", "J.R.R. Tolkien", "Fantasy"};
    Book book2 = {2, "1984", "George Orwell", "Dystopian"};
    Book book3 = {3, "To Kill a Mockingbird", "Harper Lee", "Southern Gothic"};
    Book book4 = {4, "Pride and Prejudice", "Jane Austen", "Romance"};
    Book book5 = {5, "The Catcher in the Rye", "J.D. Salinger", "Coming of Age"};
    fwrite(&book1, sizeof(Book), 1, db);
    fwrite(&book2, sizeof(Book), 1, db);
    fwrite(&book3, sizeof(Book), 1, db);
    fwrite(&book4, sizeof(Book), 1, db);
    fwrite(&book5, sizeof(Book), 1, db);
    fclose(db);

    // Updating indexes
    idIndex[1].id = 2;
    idIndex[1].offset = sizeof(Book);

    titleIndex[1].id = 2;
    titleIndex[1].offset = sizeof(Book);

    authorIndex[1].id = 2;
    authorIndex[1].offset = sizeof(Book);

    genreIndex[1].id = 2;
    genreIndex[1].offset = sizeof(Book);

    idIndex[2].id = 3;
    idIndex[2].offset = 2 * sizeof(Book);

    titleIndex[2].id = 3;
    titleIndex[2].offset = 2 * sizeof(Book);

    authorIndex[2].id = 3;
    authorIndex[2].offset = 2 * sizeof(Book);

    genreIndex[2].id = 3;
    genreIndex[2].offset = 2 * sizeof(Book);

    idIndex[3].id = 4;
    idIndex[3].offset = 3 * sizeof(Book);

    titleIndex[3].id = 4;
    titleIndex[3].offset = 3 * sizeof(Book);

    authorIndex[3].id = 4;
    authorIndex[3].offset = 3 * sizeof(Book);

    genreIndex[3].id = 4;
    genreIndex[3].offset = 3 * sizeof(Book);

    idIndex[4].id = 5;
    idIndex[4].offset = 4 * sizeof(Book);

    titleIndex[4].id = 5;
    titleIndex[4].offset = 4 * sizeof(Book);

    authorIndex[4].id = 5;
    authorIndex[4].offset = 4 * sizeof(Book);

    genreIndex[4].id = 5;
    genreIndex[4].offset = 4 * sizeof(Book);

    // Sorting indexes
    qsort(idIndex, 5, sizeof(Index), cmpID);
    qsort(titleIndex, 5, sizeof(Index), cmpTitle);
    qsort(authorIndex, 5, sizeof(Index), cmpAuthor);
    qsort(genreIndex, 5, sizeof(Index), cmpGenre);

    // Printing results
    printf("ID Index:\n");
    for (int i = 0; i < 5; i++) {
        printf("ID: %d, Offset: %ld\n", idIndex[i].id, idIndex[i].offset);
    }
    printf("\n");

    printf("Title Index:\n");
    for (int i = 0; i < 5; i++) {
        printf("ID: %d, Offset: %ld\n", titleIndex[i].id, titleIndex[i].offset);
    }
    printf("\n");

    printf("Author Index:\n");
    for (int i = 0; i < 5; i++) {
        printf("ID: %d, Offset: %ld\n", authorIndex[i].id, authorIndex[i].offset);
    }
    printf("\n");

    printf("Genre Index:\n");
    for (int i = 0; i < 5; i++) {
        printf("ID: %d, Offset: %ld\n", genreIndex[i].id, genreIndex[i].offset);
    }

    // Freeing memory
    free(idIndex);
    free(titleIndex);
    free(authorIndex);
    free(genreIndex);

    return 0;
}