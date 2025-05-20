//GEMINI-pro DATASET v1.0 Category: Password management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a password
typedef struct {
  char *username;
  char *password;
} Password;

// Function to create a new password
Password *new_password(char *username, char *password) {
  Password *pwd = malloc(sizeof(Password));
  pwd->username = strdup(username);
  pwd->password = strdup(password);
  return pwd;
}

// Function to free a password
void free_password(Password *pwd) {
  free(pwd->username);
  free(pwd->password);
  free(pwd);
}

// Function to store a password in a file
int store_password(Password *pwd, char *filename) {
  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
    return -1;
  }
  fprintf(fp, "%s %s\n", pwd->username, pwd->password);
  fclose(fp);
  return 0;
}

// Function to retrieve a password from a file
Password *retrieve_password(char *username, char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  char line[256];

  while (fgets(line, sizeof(line), fp) != NULL) {
    char *username_line = strtok(line, " ");
    char *password_line = strtok(NULL, "\n");

    if (strcmp(username_line, username) == 0) {
      Password *pwd = new_password(username_line, password_line);
      fclose(fp);
      return pwd;
    }
  }

  fclose(fp);
  return NULL;
}

int main() {
  // Prompt the user for a username and password
  char username[256];
  char password[256];
  printf("Enter your username: ");
  scanf("%s", username);
  printf("Enter your password: ");
  scanf("%s", password);

  // Create a new password
  Password *pwd = new_password(username, password);

  // Store the password in a file
  int store_result = store_password(pwd, "passwords.txt");
  if (store_result != 0) {
    printf("Error storing password!\n");
    return 1;
  }

  // Retrieve the password from the file
  Password *retrieved_pwd = retrieve_password(username, "passwords.txt");

  if (retrieved_pwd == NULL) {
    printf("Error retrieving password!\n");
    return 1;
  }

  // Verify that the retrieved password matches the original password
  if (strcmp(retrieved_pwd->username, username) != 0 || strcmp(retrieved_pwd->password, password) != 0) {
    printf("Error: retrieved password does not match original password!\n");
    return 1;
  }

  // Free the retrieved password
  free_password(retrieved_pwd);

  // Free the original password
  free_password(pwd);

  return 0;
}