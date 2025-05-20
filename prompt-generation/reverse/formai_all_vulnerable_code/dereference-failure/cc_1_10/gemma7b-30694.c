//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

void generate_receipt(char **arr, int size) {
  printf("--------------------------------------------------------\n");
  printf("Grateful Cafe Receipt\n");
  printf("--------------------------------------------------------\n");
  printf("Items:\n");
  for (int i = 0; i < size; i++) {
    printf("%s - %d\n", arr[i], arr[i + size]);
  }
  printf("\nTotal Amount: %d\n", arr[size + 1]);
  printf("Thank you for your visit to Grateful Cafe!\n");
  printf("--------------------------------------------------------\n");
}

int main() {
  char **arr = (char **)malloc(10 * sizeof(char *));
  int size = 0;

  // Get item name and quantity
  while (1) {
    printf("Enter item name: ");
    arr[size] = malloc(20 * sizeof(char));
    scanf("%s", arr[size]);

    printf("Enter item quantity: ");
    scanf("%d", &arr[size + 1]);

    size++;

    // Check if the user wants to continue
    char continue_or_not;
    printf("Do you want to continue? (Y/N): ");
    scanf(" %c", &continue_or_not);

    if (continue_or_not == 'N' || continue_or_not == 'n') {
      break;
    }
  }

  // Generate the receipt
  generate_receipt(arr, size);

  // Free the memory
  for (int i = 0; i < size; i++) {
    free(arr[i]);
  }
  free(arr);

  return 0;
}