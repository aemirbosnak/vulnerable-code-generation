//FormAI DATASET v1.0 Category: System administration ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>

int main()
{
  struct passwd *pwd;
  char *username = NULL;
  char *password = NULL;
  int change_password = 0;

  printf("Welcome, system administrator!\n\n");
  
  while (1) {
    printf("Please choose an option:\n");
    printf("1. Create a new user account\n");
    printf("2. Change a user's password\n");
    printf("3. Delete a user account\n");
    printf("4. Exit\n\n");

    int choice = 0;
    scanf("%d", &choice);

    if (choice == 1) {
      printf("\nCreating a new user account...\n");
      printf("Please enter the username: ");
      scanf("%ms", &username);
      printf("Please enter the password: ");
      scanf("%ms", &password);

      char command[256];
      sprintf(command, "useradd -m -p '%s' '%s'", password, username);
      system(command);

      printf("User account created successfully!\n\n");
      free(username);
      free(password);
    }
    else if (choice == 2) {
      printf("\nChanging a user's password...\n");
      printf("Please enter the username: ");
      scanf("%ms", &username);
      printf("Would you like to force the user to change their password at next login? (y/n) ");
      
      char force_change;
      scanf(" %c", &force_change);
      if (force_change == 'y' || force_change == 'Y') {
        change_password = 1;
      }

      char command[256];
      sprintf(command, "passwd %s", username);

      if (change_password) {
        strcat(command, " -e");
      }

      system(command);

      printf("Password changed successfully!\n\n");
      free(username);
    }
    else if (choice == 3) {
      printf("\nDeleting a user account...\n");
      printf("Please enter the username: ");
      scanf("%ms", &username);
      char command[256];
      sprintf(command, "userdel '%s'", username);
      system(command);
      printf("User account deleted successfully!\n\n");
      free(username);
    }
    else if (choice == 4) {
      printf("\nExiting...\n");
      break;
    }
    else {
      printf("\nInvalid option. Please try again.\n\n");
    }
  }

  return 0;
}