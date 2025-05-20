//FormAI DATASET v1.0 Category: File handling ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

int main() {
  FILE *fp;
  char filename[] = "my_secret_file.txt";
  char password[] = "super_secret_password";
  char input[MAX];
  int choice;

  printf("Welcome to my secret file handler!\n");

  fp = fopen(filename, "r");
  if(fp == NULL) {
    printf("File doesn't exist. Creating a new file.\n");
    fp = fopen(filename, "w");
    fclose(fp);
    fp = fopen(filename, "r");
  }

  printf("Enter the password to access the file: ");
  fgets(input, MAX, stdin);
  input[strlen(input)-1] = '\0';

  if(strcmp(input, password) != 0) {
    printf("Incorrect password. Exiting program.\n");
    return 0;
  }

  printf("Access granted. What would you like to do?\n");
  printf("1 - Write to file\n");
  printf("2 - Read from file\n");
  printf("3 - Exit program\n");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      printf("Enter text to write to file: ");
      fgets(input, MAX, stdin);
      fp = fopen(filename, "a");
      fprintf(fp, "%s", input);
      fclose(fp);
      printf("Text written to file successfully.\n");
      break;

    case 2:
      printf("Reading file...\n");
      fp = fopen(filename, "r");
      while(fgets(input, MAX, fp) != NULL) {
        printf("%s", input);
      }
      fclose(fp);
      break;

    case 3:
      printf("Exiting program.\n");
      break;

    default:
      printf("Invalid choice. Exiting program.\n");
      break;
  }

  return 0;
}