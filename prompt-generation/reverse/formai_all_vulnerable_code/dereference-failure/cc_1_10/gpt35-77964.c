//FormAI DATASET v1.0 Category: Ebook reader ; Style: scalable
#include<stdio.h>
#include<stdlib.h>

struct Book{
  char title[50];
  char author[30];
  int pages;
  float price;
  char publisher[50];
};

void display(struct Book B) {
    printf("\nTitle of the book : %s", B.title);
    printf("\nAuthor : %s", B.author);
    printf("\nPages : %d", B.pages);
    printf("\nPrice : %f", B.price);
    printf("\nPublisher : %s", B.publisher);
}

void read(struct Book *B) {
    printf("\nEnter the title of the book : ");
    fgets(B->title, 50, stdin);
    printf("\nEnter the name of the author : ");
    fgets(B->author, 30, stdin);
    printf("\nEnter the number of pages : ");
    scanf("%d", &B->pages);
    printf("\nEnter the price of the book : ");
    scanf("%f", &B->price);
    getchar();  //to handle newline character
    printf("\nEnter the name of publisher : ");
    fgets(B->publisher, 50, stdin);
}

int main() {
    int n = 0, i;
    printf("Enter the number of books you want to read : ");
    scanf("%d", &n);
    getchar();  //to handle newline character

    struct Book *book = (struct Book*) calloc(n, sizeof(struct Book));

    for (i = 0; i < n; i++) {
        printf("\nEnter details of book %d : \n", i + 1);
        read(&book[i]);
    }

    printf("\nDetails of the books you entered : \n");
    for (i = 0; i < n; i++) {
        printf("\nDetails of book %d : \n", i + 1);
        display(book[i]);
        printf("\n");
    }

    free(book);
    return 0;
}