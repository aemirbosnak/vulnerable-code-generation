//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 1000
#define NONE -1

typedef struct {
  char name[50];
  char address[100];
  char phone[15];
} contact;

int main() {
  int choice, i, n, flag = 0, search;
  char ch;
  contact book[MAX];

  printf("Welcome to Phonebook!\n");
  printf("---------------------------------\n");

  while(1) {
    printf("\nEnter 1 to add contact\n");
    printf("Enter 2 to display all contacts\n");
    printf("Enter 3 to search a contact\n");
    printf("Enter 4 to exit\n");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter name: ");
        scanf("%s", book[n].name);
        printf("Enter address: ");
        scanf("%s", book[n].address);
        printf("Enter phone number: ");
        scanf("%s", book[n].phone);
        n++;
        break;

      case 2:
        printf("\nName\tAddress\tPhone\n");
        for(i=0; i<n; i++) {
          printf("%s\t%s\t%s\n", book[i].name, book[i].address, book[i].phone);
        }
        break;

      case 3:
        printf("Enter name to search: ");
        scanf("%s", ch);
        search = 0;
        for(i=0; i<n; i++) {
          if(strcmp(book[i].name, ch) == 0) {
            printf("\nName: %s\nAddress: %s\nPhone: %s\n", book[i].name, book[i].address, book[i].phone);
            search = 1;
            break;
          }
        }
        if(search == 0) {
          printf("Contact not found!\n");
        }
        break;

      case 4:
        printf("Exiting...\n");
        exit(0);

      default:
        printf("Invalid choice!\n");
    }
  }

  return 0;
}