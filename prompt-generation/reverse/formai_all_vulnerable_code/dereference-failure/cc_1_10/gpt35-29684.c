//FormAI DATASET v1.0 Category: Phone Book ; Style: cheerful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct contact{
    char name[50];
    char phone_num[20];
};

void clear_input_buffer() {
  int c;
  do {
    c = getchar();
  } while (c != '\n' && c != EOF);
}

void print_contacts(struct contact *contacts, int num_contacts) {
  printf("CONTACT LIST:\n");
  for(int i=0; i<num_contacts; i++) {
    printf("%d. Name: %s\n   Phone number: %s\n", i+1, contacts[i].name, contacts[i].phone_num);
  }
}

void add_contact(struct contact *contacts, int *num_contacts) {
  printf("Enter name: ");
  fgets(contacts[*num_contacts].name, 50, stdin);
  strtok(contacts[*num_contacts].name, "\n"); // remove \n character from string
  printf("Enter phone number: ");
  scanf("%s", contacts[*num_contacts].phone_num);
  clear_input_buffer();  // clear input buffer to avoid errors in subsequent fgets calls
  printf("Contact added successfully!\n\n");
  (*num_contacts)++;
}

void search_contact(struct contact *contacts, int num_contacts) {
  char search_name[50];
  printf("Enter name to search: ");
  fgets(search_name, 50, stdin);
  strtok(search_name, "\n"); // remove \n character from string
  for(int i=0; i<num_contacts; i++) {
    if(strcmp(contacts[i].name, search_name) == 0) {
      printf("Contact found!\n");
      printf("Name: %s\nPhone number: %s\n\n", contacts[i].name, contacts[i].phone_num);
      return;
    }
  }
  printf("Contact not found!\n\n");
}

int main() {
  struct contact *contacts = malloc(20 * sizeof(struct contact)); // allocate memory for contacts
  int num_contacts = 0;
  int option;
  while(1) {
    printf("MENU:\n");
    printf("1. View all contacts\n2. Add new contact\n3. Search contact by name\n4. Exit\n");
    printf("Enter option (1-4): ");
    scanf("%d", &option);
    clear_input_buffer(); // clear input buffer to avoid errors in subsequent fgets calls
    printf("\n");
    switch(option) {
      case 1:
        if(num_contacts == 0) {
          printf("No contacts found!\n\n");
        } else{
          print_contacts(contacts, num_contacts);
        }
        break;

      case 2:
        add_contact(contacts, &num_contacts);
        break;

      case 3:
        search_contact(contacts, num_contacts);
        break;

      case 4:
        free(contacts); // free memory allocated for contacts before exiting
        printf("Thank you for using the Phone Book program!\n");
        return 0; // exit program
        break;

      default:
        printf("Invalid option! Please try again.\n\n");
        break;
    }
  }
  return 0;
}