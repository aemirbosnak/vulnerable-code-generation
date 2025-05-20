//FormAI DATASET v1.0 Category: Data mining ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for representing a book
struct book {
    char title[100];
    char author[50];
    int year;
    float price;
};

// Function to read book info from file
void read_books(struct book books[], int *num_books) {
    FILE *fp;
    char line[100];
    char *token;
    int i = 0;

    fp = fopen("books.txt", "r"); // Open input file

    if (fp == NULL) {
        printf("Error: Unable to read from file!\n");
        exit(1); // Exit program at error
    }
    while (fgets(line, 100, fp)) { // Read every line in the file
        token = strtok(line, ","); // Split line by comma
        strcpy(books[i].title, token);
        token = strtok(NULL, ",");
        strcpy(books[i].author, token);
        token = strtok(NULL, ",");
        books[i].year = atoi(token);
        token = strtok(NULL, ",");
        books[i].price = atof(token);
        i++;
    }
    *num_books = i;

    fclose(fp); // Close input file
}

// Function to find the average price of books
float average_price(struct book books[], int num_books) {
    float sum = 0;
    for (int i = 0; i < num_books; i++) {
        sum += books[i].price;
    }
    return sum / num_books;
}

// Function to find the number of books written by an author
int books_by_author(struct book books[], int num_books, char author[]) {
    int count = 0;
    for (int i = 0; i < num_books; i++) {
        if (strcmp(books[i].author, author) == 0) {
            count++;
        }
    }
    return count;
}

// Main function
int main() {
    struct book books[100];
    int num_books;
    char author[50];
    float avg_price;

    read_books(books, &num_books); // Read books from file
    avg_price = average_price(books, num_books); // Calculate average book price
    printf("The average price of books is $%.2f.\n", avg_price);
    printf("Enter the name of an author: ");
    scanf("%s", author);
    printf("%s has written %d books.\n", author, books_by_author(books, num_books, author)); // Print number of books written by author

    return 0;
}