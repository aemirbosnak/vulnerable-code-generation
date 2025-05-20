//FormAI DATASET v1.0 Category: File handling ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int main() {
  printf("Welcome to the File Handling program!\n");
  
  FILE *file1, *file2;
  char data[100];
  char new_data[100];
  char file1_name[20], file2_name[20];
  
  // Get the name of the first file to read data from
  printf("\nEnter the name of the first file: ");
  scanf("%s", file1_name);
  
  // Open the first file and read data from it
  file1 = fopen(file1_name, "r");
  if(file1 == NULL) {
    printf("\nError! Could not open file.");
    exit(1);
  }
  printf("\nReading data from %s...\n", file1_name);
  fgets(data, 100, file1);
  fclose(file1);
  printf("Data: %s\n", data);
  
  // Get the name of the second file to write data to
  printf("\nEnter the name of the second file: ");
  scanf("%s", file2_name);
  
  // Open the second file and write data to it
  file2 = fopen(file2_name, "w");
  if(file2 == NULL) {
    printf("\nError! Could not create file.");
    exit(1);
  }
  printf("\nEnter new data to write to %s: ", file2_name);
  scanf("%s", new_data);
  fprintf(file2, "%s", new_data);
  fclose(file2);
  printf("Data successfully written to %s!\n", file2_name);
  
  // Compare the contents of the two files
  printf("\nComparing contents of files...\n");
  file1 = fopen(file1_name, "r");
  file2 = fopen(file2_name, "r");
  bool equal = true;
  while(fgets(data, 100, file1) && fgets(new_data, 100, file2)) {
    if(strcmp(data, new_data) != 0) {
      equal = false;
      break;
    }
  }
  fclose(file1);
  fclose(file2);
  if(equal) {
    printf("The contents of %s and %s are identical!\n", file1_name, file2_name);
  }
  else {
    printf("The contents of %s and %s are different.\n", file1_name, file2_name);
  }
  
  printf("\nProgram complete. Exiting...\n");
  return 0;
}