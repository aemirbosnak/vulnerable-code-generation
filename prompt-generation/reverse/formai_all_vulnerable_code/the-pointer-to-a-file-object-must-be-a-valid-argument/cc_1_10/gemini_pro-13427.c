//GEMINI-pro DATASET v1.0 Category: Password management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize the database
void init_database() {
  FILE *fp = fopen("passwords.txt", "w");
  fclose(fp);
}

// Add a new password to the database
void add_password(char *service, char *username, char *password) {
  FILE *fp = fopen("passwords.txt", "a");
  fprintf(fp, "%s %s %s\n", service, username, password);
  fclose(fp);
}

// Find a password in the database
char *find_password(char *service, char *username) {
  FILE *fp = fopen("passwords.txt", "r");
  char line[1024];
  while (fgets(line, 1024, fp)) {
    char *service_line, *username_line, *password_line;
    service_line = strtok(line, " ");
    username_line = strtok(NULL, " ");
    password_line = strtok(NULL, "\n");
    if (strcmp(service, service_line) == 0 && strcmp(username, username_line) == 0) {
      fclose(fp);
      return password_line;
    }
  }
  fclose(fp);
  return NULL;
}

// Delete a password from the database
void delete_password(char *service, char *username) {
  FILE *fp = fopen("passwords.txt", "r");
  FILE *temp = fopen("temp.txt", "w");
  char line[1024];
  while (fgets(line, 1024, fp)) {
    char *service_line, *username_line;
    service_line = strtok(line, " ");
    username_line = strtok(NULL, " ");
    if (strcmp(service, service_line) != 0 || strcmp(username, username_line) != 0) {
      fprintf(temp, "%s", line);
    }
  }
  fclose(fp);
  fclose(temp);
  remove("passwords.txt");
  rename("temp.txt", "passwords.txt");
}

// Print the entire database
void print_database() {
  FILE *fp = fopen("passwords.txt", "r");
  char line[1024];
  while (fgets(line, 1024, fp)) {
    printf("%s", line);
  }
  fclose(fp);
}

// Main function
int main() {
  // Initialize the database
  init_database();

  // Add a new password to the database
  add_password("gmail", "john.doe@gmail.com", "password1");

  // Find a password in the database
  char *password = find_password("gmail", "john.doe@gmail.com");
  printf("Password: %s\n", password);

  // Delete a password from the database
  delete_password("gmail", "john.doe@gmail.com");

  // Print the entire database
  print_database();

  return 0;
}