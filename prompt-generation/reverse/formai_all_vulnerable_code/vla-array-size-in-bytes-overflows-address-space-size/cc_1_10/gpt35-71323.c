//FormAI DATASET v1.0 Category: Ebook reader ; Style: detailed
#include <stdio.h>

//Structure for Ebook
struct Ebook{
  char title[50];
  char author[50];
  char format[20];
  int year;
  float price;
};

//Function to display Ebook details
void display(struct Ebook e){
  printf("Title: %s\nAuthor: %s\nFormat: %s\nYear: %d\nPrice: $%.2f\n", e.title, e.author, e.format, e.year, e.price);
}

int main() {
  int size; //Variable to store number of Ebooks
  printf("Enter number of Ebooks you want to enter: ");
  scanf("%d", &size);

  struct Ebook ebooks[size]; //Array of Ebooks

  //Loop to input details of each Ebook
  for(int i=0; i<size; i++){
    printf("\nEnter details for Ebook %d:\n", i+1);

    printf("Enter title: ");
    scanf(" %[^\n]s", ebooks[i].title); //scanf with %s only accepts one word, so we use %[^\n]s to accept whole line with spaces

    printf("Enter author: ");
    scanf(" %[^\n]s", ebooks[i].author);

    printf("Enter format: ");
    scanf(" %[^\n]s", ebooks[i].format);

    printf("Enter year: ");
    scanf("%d", &ebooks[i].year);

    printf("Enter price: ");
    scanf("%f", &ebooks[i].price);
  }

  //Loop to display details of each Ebook
  for(int i=0; i<size; i++){
    printf("\nDetails of Ebook %d:\n", i+1);
    display(ebooks[i]);
  }

  return 0;
}