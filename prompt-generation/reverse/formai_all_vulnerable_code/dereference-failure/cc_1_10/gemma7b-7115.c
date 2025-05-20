//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num_records = 0;
  int rec_size = 0;
  int data_array[100] = {0};

  printf("Welcome to the CRUD-tastic Database!\n");
  printf("--------------------\n");

  while (1) {
    char choice;

    printf("Enter 'a' to add, 'r' to read, 'u' to update, or 'd' to delete: ");
    scanf(" %c", &choice);

    switch (choice) {
      case 'a':
        printf("Enter the record size: ");
        scanf(" %d", &rec_size);
        data_array[num_records] = rec_size;
        num_records++;
        break;

      case 'r':
        printf("Enter the record number: ");
        int rec_num;
        scanf(" %d", &rec_num);
        printf("Record data: %d\n", data_array[rec_num]);
        break;

      case 'u':
        printf("Enter the record number: ");
        scanf(" %d", &rec_num);
        printf("Enter the new record size: ");
        scanf(" %d", &rec_size);
        data_array[rec_num] = rec_size;
        break;

      case 'd':
        printf("Enter the record number: ");
        scanf(" %d", &rec_num);
        data_array[rec_num] = 0;
        num_records--;
        break;

      default:
        printf("Invalid input.\n");
    }

    printf("--------------------\n");
  }

  return 0;
}