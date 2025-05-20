//FormAI DATASET v1.0 Category: Phone Book ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare global variables
#define MAX_CONTACTS 100
char name[25];
char number[25];

// Declare struct to hold contact information
typedef struct {
  char name[25];
  char number[25];
} Contact;

// Declare function prototypes
void display_menu();
void add_contact();
void delete_contact();
void edit_contact();
void search_contact();
void view_all_contacts();
void save_contacts();
void load_contacts();

// Declare global array to hold contacts
Contact contacts[MAX_CONTACTS];
int num_of_contacts = 0;

int main() {
  printf("*** Welcome to Your Personal Phone Book ***\n\n");

  // Load contacts from file
  load_contacts();

  // Declare variable to hold user choice
  int choice;

  // Display menu and get user choice
  do {
    display_menu();
    scanf("%d", &choice);
    printf("\n");

    switch(choice) {
      case 1:
        add_contact();
        break;
      case 2:
        delete_contact();
        break;
      case 3:
        edit_contact();
        break;
      case 4:
        search_contact();
        break;
      case 5:
        view_all_contacts();
        break;
      case 6:
        save_contacts();
        break;
      case 7:
        printf("Thank you for using Your Personal Phone Book!\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
    printf("\n");
  } while (choice != 7);

  return 0;
}

// Display the main menu
void display_menu() {
  printf("Please choose from the following options:\n");
  printf("1. Add a contact\n");
  printf("2. Delete a contact\n");
  printf("3. Edit a contact\n");
  printf("4. Search for a contact\n");
  printf("5. View all contacts\n");
  printf("6. Save contacts to file\n");
  printf("7. Exit\n");
  printf("Your choice: ");
}

// Add a new contact to the phone book
void add_contact() {
  if (num_of_contacts >= MAX_CONTACTS) {
    printf("Sorry, but you have reached the maximum number of contacts.\n");
    return;
  }

  printf("Enter the contact's name: ");
  scanf("%s", name);
  printf("Enter the contact's number: ");
  scanf("%s", number);

  // Add the new contact to the array
  strcpy(contacts[num_of_contacts].name, name);
  strcpy(contacts[num_of_contacts].number, number);
  num_of_contacts++;

  printf("%s has been added to your phone book.\n", name);
}

// Delete an existing contact from the phone book
void delete_contact() {
  char name_to_delete[25];
  int i, j;

  printf("Enter the name of the contact you want to delete: ");
  scanf("%s", name_to_delete);

  // Find the index of the contact to delete
  for (i = 0; i < num_of_contacts; i++) {
    if (strcmp(name_to_delete, contacts[i].name) == 0) {
      // Shift all contacts after the deleted one down by one
      for (j = i; j < num_of_contacts - 1; j++) {
        strcpy(contacts[j].name, contacts[j+1].name);
        strcpy(contacts[j].number, contacts[j+1].number);
      }
      // Decrement num_of_contacts to reflect the deleted contact
      num_of_contacts--;
      printf("%s has been deleted from your phone book.\n", name_to_delete);
      return;
    }
  }

  printf("No contact with that name exists in your phone book.\n");
}

// Edit an existing contact in the phone book
void edit_contact() {
  char name_to_edit[25];
  int i;

  printf("Enter the name of the contact you want to edit: ");
  scanf("%s", name_to_edit);

  // Find the contact to edit
  for (i = 0; i < num_of_contacts; i++) {
    if (strcmp(name_to_edit, contacts[i].name) == 0) {
      printf("Enter the new contact's name: ");
      scanf("%s", name);
      printf("Enter the new contact's number: ");
      scanf("%s", number);
      // Update the contact info
      strcpy(contacts[i].name, name);
      strcpy(contacts[i].number, number);
      printf("%s has been updated in your phone book.\n", name_to_edit);
      return;
    }
  }

  printf("No contact with that name exists in your phone book.\n");
}

// Search for an existing contact in the phone book
void search_contact() {
  char name_to_search[25];
  int i;

  printf("Enter the name of the contact you want to search for: ");
  scanf("%s", name_to_search);

  // Find the contact
  for (i = 0; i < num_of_contacts; i++) {
    if (strcmp(name_to_search, contacts[i].name) == 0) {
      printf("Name: %s\n", contacts[i].name);
      printf("Number: %s\n", contacts[i].number);
      return;
    }
  }

  printf("No contact with that name exists in your phone book.\n");
}

// View all existing contacts in the phone book
void view_all_contacts() {
  int i;

  if (num_of_contacts == 0) {
    printf("Your phone book is empty.\n");
    return;
  }

  printf("Your phone book:\n");
  for (i = 0; i < num_of_contacts; i++) {
    printf("%s - %s\n", contacts[i].name, contacts[i].number);
  }
}

// Save all contacts to a file
void save_contacts() {
  FILE *file;
  int i;

  file = fopen("contacts.txt", "w");
  if (file == NULL) {
    printf("Error opening file.\n");
    return;
  }

  for (i = 0; i < num_of_contacts; i++) {
    fprintf(file, "%s;%s\n", contacts[i].name, contacts[i].number);
  }
  fclose(file);

  printf("Contacts saved to file.\n");
}

// Load all contacts from a file
void load_contacts() {
  FILE *file;
  char line[50];
  char *name, *number;

  file = fopen("contacts.txt", "r");
  if (file == NULL) {
    printf("Creating new contacts file.\n");
    return;
  }

  while (fgets(line, sizeof(line), file) != NULL) {
    name = strtok(line, ";");
    number = strtok(NULL, ";");
    name[strcspn(name, "\n")] = 0;
    number[strcspn(number, "\n")] = 0;
    strcpy(contacts[num_of_contacts].name, name);
    strcpy(contacts[num_of_contacts].number, number);
    num_of_contacts++;
  }
  fclose(file);

  printf("%d contacts loaded from file.\n", num_of_contacts);
}