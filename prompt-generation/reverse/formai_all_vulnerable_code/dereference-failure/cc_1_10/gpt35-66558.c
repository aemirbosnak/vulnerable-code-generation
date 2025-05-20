//FormAI DATASET v1.0 Category: Ebook reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct eBook {
    char title[50];
    char author[50];
    char publisher[50];
    int yearPublished;
    char fileName[50];
};

struct node {
    struct eBook book;
    struct node *next;
};

struct blockchain {
    int blockID;
    int prevHash;
    int currHash;
    struct node *head;
    struct blockchain *next;
};

void printBook(struct eBook book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Publisher: %s\n", book.publisher);
    printf("Year Published: %d\n", book.yearPublished);
}

struct node *createNode(struct eBook book) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->book = book;
    newNode->next = NULL;
    return newNode;
}

struct blockchain *createBlock(int blockID, int prevHash, int currHash) {
    struct blockchain *newBlock = (struct blockchain*)malloc(sizeof(struct blockchain));
    newBlock->blockID = blockID;
    newBlock->prevHash = prevHash;
    newBlock->currHash = currHash;
    newBlock->head = NULL;
    newBlock->next = NULL;
    return newBlock;
}

void addBook(struct eBook book, struct blockchain *blockchain) {
    struct node *newNode = createNode(book);
    
    if(blockchain->head == NULL) {
        blockchain->head = newNode;
    }
    else {
        struct node *temp = blockchain->head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printBlock(struct blockchain *blockchain) {
    printf("Block ID: %d\n", blockchain->blockID);
    printf("Previous Hash: %d\n", blockchain->prevHash);
    printf("Current Hash: %d\n", blockchain->currHash);
    printf("Books in Block:\n");
    
    struct node *temp = blockchain->head;
    while(temp != NULL) {
        printBook(temp->book);
        temp = temp->next;
    }
}

int main() {
    struct eBook book1 = {"The Catcher in the Rye", "J.D. Salinger", "Little, Brown and Company", 1951, "catcher_in_the_rye.pdf"};
    struct eBook book2 = {"To Kill a Mockingbird", "Harper Lee", "J. B. Lippincott & Co.", 1960, "to_kill_a_mockingbird.pdf"};
    struct eBook book3 = {"1984", "George Orwell", "Secker & Warburg", 1949, "1984.pdf"};
    struct eBook book4 = {"The Great Gatsby", "F. Scott Fitzgerald", "Charles Scribner's Sons", 1925, "the_great_gatsby.pdf"};

    struct blockchain *blockchain = createBlock(1, 0, 12345);
    addBook(book1, blockchain);
    addBook(book2, blockchain);

    struct blockchain *newBlock = createBlock(2, 12345, 67890);
    addBook(book3, newBlock);
    addBook(book4, newBlock);

    blockchain->next = newBlock;

    printBlock(blockchain);
    printBlock(newBlock);

    return 0;
}