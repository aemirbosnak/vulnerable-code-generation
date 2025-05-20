//FormAI DATASET v1.0 Category: Banking Record System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  char address[50];
  char phone[10];
  float balance;
} account;

int main() {
  account a1;
  FILE *file = fopen("record.txt", "rb");

  // create file if it doesn't exist
  if (!file) {
    file = fopen("record.txt", "wb");
    fclose(file);
    file = fopen("record.txt", "rb");
  }

  // read in existing record
  if (fread(&a1, sizeof(account), 1, file)) {
    printf("Existing Account:\n");
    printf("Name: %s\n", a1.name);
    printf("Address: %s\n", a1.address);
    printf("Phone: %s\n", a1.phone);
    printf("Balance: %.2f\n", a1.balance);
  }

  // get user input
  printf("Enter Account Information:\n");
  printf("Name: ");
  scanf("%s", a1.name);
  printf("Address: ");
  scanf("%s", a1.address);
  printf("Phone: ");
  scanf("%s", a1.phone);
  printf("Balance: ");
  scanf("%f", &a1.balance);

  // write to file
  file = fopen("record.txt", "wb");
  fwrite(&a1, sizeof(account), 1, file);

  // close file
  fclose(file);

  printf("Account Updated Successfully!\n");

  return 0;
}