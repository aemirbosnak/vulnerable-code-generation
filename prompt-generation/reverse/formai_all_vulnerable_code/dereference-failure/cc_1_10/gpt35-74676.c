//FormAI DATASET v1.0 Category: Database simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    int id;
    char title[50];
    char author[50];
    float price;
} Book;

typedef struct Database {
    int size;
    Book* books[100];
} Database;

void init(Database* db) {
    db->size = 0;
}

void addBook(Database* db, Book* book) {
    db->books[db->size++] = book;
}

void printBooks(Database* db) {
    printf("\nID   Title\t\tAuthor\t\tPrice\n");
    printf("----------------------------------------------\n");
    for(int i=0; i<db->size; i++) {
        printf("%-4d %-20.20s %-20.20s $%4.2f\n", db->books[i]->id, db->books[i]->title, db->books[i]->author, db->books[i]->price);
    }
    printf("\n");
}

Book* findBook(Database* db, int id) {
    for(int i=0; i<db->size; i++) {
        if(db->books[i]->id == id) {
            return db->books[i];
        }
    }
    return NULL;
}

void updateBook(Database* db, int id, Book* book) {
    Book* oldBook = findBook(db, id);
    if(oldBook != NULL) {
        oldBook->id = book->id;
        strcpy(oldBook->title, book->title);
        strcpy(oldBook->author, book->author);
        oldBook->price = book->price;
    }
}

void deleteBook(Database* db, int id) {
    for(int i=0; i<db->size; i++) {
        if(db->books[i]->id == id) {
            for(int j=i; j<db->size-1; j++) {
                db->books[j] = db->books[j+1];
            }
            free(db->books[--db->size]);
        }
    }
}

int main() {
    Database db;
    init(&db);
    
    Book* b1 = (Book*) malloc(sizeof(Book));
    b1->id = 1;
    strcpy(b1->title, "The Alchemist");
    strcpy(b1->author, "Paulo Coelho");
    b1->price = 9.99;
    addBook(&db, b1);
    
    Book* b2 = (Book*) malloc(sizeof(Book));
    b2->id = 2;
    strcpy(b2->title, "To Kill a Mockingbird");
    strcpy(b2->author, "Harper Lee");
    b2->price = 8.99;
    addBook(&db, b2);
    
    Book* b3 = (Book*) malloc(sizeof(Book));
    b3->id = 3;
    strcpy(b3->title, "1984");
    strcpy(b3->author, "George Orwell");
    b3->price = 7.99;
    addBook(&db, b3);
    
    printBooks(&db);
    
    Book* b4 = (Book*) malloc(sizeof(Book));
    b4->id = 4;
    strcpy(b4->title, "Brave New World");
    strcpy(b4->author, "Aldous Huxley");
    b4->price = 10.99;
    addBook(&db, b4);
    
    printBooks(&db);
    
    Book* b5 = (Book*) malloc(sizeof(Book));
    b5->id = 5;
    strcpy(b5->title, "Animal Farm");
    strcpy(b5->author, "George Orwell");
    b5->price = 6.99;
    addBook(&db, b5);
    
    printBooks(&db);
    
    Book* b6 = (Book*) malloc(sizeof(Book));
    b6->id = 4;
    strcpy(b6->title, "1984");
    strcpy(b6->author, "George Orwell");
    b6->price = 11.99;
    updateBook(&db, 3, b6);
    
    printBooks(&db);
    
    deleteBook(&db, 2);
    
    printBooks(&db);

    return 0;
}