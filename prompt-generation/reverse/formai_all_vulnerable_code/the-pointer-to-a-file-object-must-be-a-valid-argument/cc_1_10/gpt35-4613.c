//FormAI DATASET v1.0 Category: System administration ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

void display_menu() {
  printf("\n========MENU========\n");
  printf("1. Add user\n");
  printf("2. Remove user\n");
  printf("3. View users\n");
  printf("4. Exit\n");
  printf("=====================\n");
}

int count_users() {
  FILE *file = fopen("/etc/passwd", "r");
  int count = 0;
  char line[256];
 
  while (fgets(line, sizeof(line), file)) {
    count++;
  }
  fclose(file);
 
  return count;
}

void add_user() {
  char username[MAX_COMMAND_LENGTH], command[MAX_COMMAND_LENGTH];
  printf("Enter the username to be added: ");
  scanf("%s", username);
  sprintf(command, "sudo useradd -m %s", username);
 
  system(command);
  printf("User %s added successfully.\n", username);
}
 
void remove_user() {
  char username[MAX_COMMAND_LENGTH], command[MAX_COMMAND_LENGTH];
  printf("Enter the username to be removed: ");
  scanf("%s", username);
  sprintf(command, "sudo userdel -r %s", username);
 
  system(command);
  printf("User %s removed successfully.\n", username);
}
 
void view_users() {
  FILE *file = fopen("/etc/passwd", "r");
  char line[256];
  printf("\n");
 
  while (fgets(line, sizeof(line), file)) {
    printf("%s", line);
  }
  fclose(file);
}
 
int main() {
  int choice;
  
  do {
    display_menu();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_user();
        break;
      case 2:
        remove_user();
        break;
      case 3:
        view_users();
        break;
      case 4:
        printf("Exiting Program.\n");
        break;
      default:
        printf("Invalid choice.\n");
        break;
    }

  } while (choice != 4);
 
  return 0;
}