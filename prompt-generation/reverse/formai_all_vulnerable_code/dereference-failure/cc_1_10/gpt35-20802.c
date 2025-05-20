//FormAI DATASET v1.0 Category: Ebook reader ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Custom book structure
typedef struct {
    char title[50];
    char author[30];
    int pages;
    float price;
} Book;

// Function to display book details
void display(Book b) {
    printf("\nTitle: %s\nAuthor: %s\nPages: %d\nPrice: $%.2f\n", b.title, b.author, b.pages, b.price);
}

// Function to read a book from file
Book readBookFromFile(char filename[]) {
    FILE *fp;
    Book b;
    fp = fopen(filename, "r"); // Open file in read mode
    if(fp == NULL) {
        printf("\nError reading file!");
        exit(1);
    }
    fscanf(fp, "%s%s%d%f", b.title, b.author, &b.pages, &b.price); // Read values from file
    fclose(fp); // Close file
    return b;
}

// Function to check if file exists
int fileExists(char filename[]) {
    FILE *fp;
    fp = fopen(filename, "r");
    if(fp == NULL) {
        return 0;
    }
    else {
        return 1;
    }
    fclose(fp);
}

// Main function
int main() {
    srand(time(0)); // Seed the random number generator with current time
    
    printf("Welcome to the Surrealist Ebook Reader!\n");
    
    // Choose a random book from the library
    int randIndex = rand() % 5;
    char filename[50] = {'\0'};
    switch(randIndex) {
        case 0: strcpy(filename, "book1.txt"); break;
        case 1: strcpy(filename, "book2.txt"); break;
        case 2: strcpy(filename, "book3.txt"); break;
        case 3: strcpy(filename, "book4.txt"); break;
        case 4: strcpy(filename, "book5.txt"); break;
    }
    
    // Check if book file exists
    if(!fileExists(filename)) {
        printf("\nSorry, the book you are looking for does not exist.");
        return 1;
    }
    
    // Read the book from file
    printf("\nReading book: %s\n", filename);
    Book book = readBookFromFile(filename);
    
    // Display the book details
    display(book);
    
    // Let the reader read the book
    printf("\nEnjoy reading %s by %s!", book.title, book.author);
    
    return 0;
}