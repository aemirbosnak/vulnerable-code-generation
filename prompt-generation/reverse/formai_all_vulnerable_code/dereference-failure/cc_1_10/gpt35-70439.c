//FormAI DATASET v1.0 Category: Ebook reader ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Struct to hold information about each ebook
struct eBook {
    char title[50];
    char author[50];
    char publisher[50];
    double price;
    char format[20];
};

//Function to securely read a string input from user
void secure_readString(char *string, int maxLength) {
    fgets(string, maxLength, stdin);
    if(string[strlen(string)-1] == '\n') {
        string[strlen(string)-1] = '\0';
    }
    else {
        while(getchar()!='\n');
    }
}

int main() {
    int num_books;
    printf("Enter the number of eBooks: ");
    scanf("%d", &num_books);
    struct eBook *books = (struct eBook*)malloc(num_books*sizeof(struct eBook));
    for(int i=0; i<num_books; i++) {
        printf("Enter title of book %d: ", i+1);
        secure_readString(books[i].title, 50);
        printf("Enter author of book %d: ", i+1);
        secure_readString(books[i].author, 50);
        printf("Enter publisher of book %d: ", i+1);
        secure_readString(books[i].publisher, 50);
        printf("Enter price of book %d: ", i+1);
        scanf("%lf", &books[i].price);
        printf("Enter format of book %d: ", i+1);
        secure_readString(books[i].format, 20);
    }
    printf("List of %d eBooks:\n", num_books);
    double total_cost = 0;
    for(int i=0; i<num_books; i++) {
        printf("\nTitle: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Publisher: %s\n", books[i].publisher);
        printf("Price: %.2lf\n", books[i].price);
        printf("Format: %s\n", books[i].format);
        total_cost += books[i].price;
    }
    printf("\nTotal cost of eBooks: %.2lf\n", total_cost);
    free(books);
    return 0;
}