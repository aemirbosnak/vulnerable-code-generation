//FormAI DATASET v1.0 Category: Password management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct to hold password information
typedef struct {
  char website[50];
  char username[20];
  char password[20];
} Password;

// helper function used to get user input
char* get_input() {
  char* input = malloc(sizeof(char)*50);
  printf("> ");
  fgets(input, 50, stdin);
  input[strcspn(input, "\n")] = 0;
  return input;
}

// function to add a new password to the password manager
void add_password(Password* passwords, int* num_passwords) {
  printf("Enter website name: ");
  strcpy(passwords[*num_passwords].website, get_input());
  printf("Enter username: ");
  strcpy(passwords[*num_passwords].username, get_input());
  printf("Enter password: ");
  strcpy(passwords[*num_passwords].password, get_input());
  printf("Password added successfully!\n");
  (*num_passwords)++;
}

// function to search for a password by website
void search_password(Password* passwords, int num_passwords) {
  printf("Enter website name to search for: ");
  char* website = get_input();
  for(int i = 0; i < num_passwords; i++) {
    if(strcmp(passwords[i].website, website) == 0) {
      printf("Website: %s\n", passwords[i].website);
      printf("Username: %s\n", passwords[i].username);
      printf("Password: %s\n", passwords[i].password);
      free(website);
      return;
    }
  }
  printf("No match found for website \"%s\"\n", website);
  free(website);
}

// function to print all passwords in the password manager
void print_passwords(Password* passwords, int num_passwords) {
  printf("Website\t\tUsername\t\tPassword\n");
  printf("-------------------------------------------------------\n");
  for(int i = 0; i < num_passwords; i++) {
    printf("%-20s\t%-20s\t%-20s\n", passwords[i].website, passwords[i].username, passwords[i].password);
  }
}

int main() {
  Password passwords[50]; // array to hold up to 50 passwords
  int num_passwords = 0; // keep track of number of passwords currently stored

  int choice;
  while(1) {
    printf("1. Add password\n");
    printf("2. Search for password\n");
    printf("3. Print all passwords\n");
    printf("4. EXIT\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    getchar(); // consume newline character left over from scanf

    switch(choice) {
      case 1:
        add_password(passwords, &num_passwords);
        break;
      case 2:
        search_password(passwords, num_passwords);
        break;
      case 3:
        print_passwords(passwords, num_passwords);
        break;
      case 4:
        printf("Goodbye!\n");
        return 0;
      default:
        printf("Invalid choice. Try again.\n");
        break;
    }
  }
  return 0;
}