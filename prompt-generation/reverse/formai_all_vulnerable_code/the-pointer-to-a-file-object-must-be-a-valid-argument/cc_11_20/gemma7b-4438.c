//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
  system("clear");

  // Expense Tracker Main Menu
  printf("=================================\n");
  printf("       Expense Tracker v1.0       \n");
  printf("=================================\n");
  printf("1. Add Expense\n");
  printf("2. View Expenses\n");
  printf("3. Edit Expenses\n");
  printf("4. Delete Expenses\n");
  printf("5. Exit\n");

  // Get User Input
  int choice = 0;
  printf("Enter your choice: ");
  scanf("%d", &choice);

  // Shape Shifting Logic
  switch (choice) {
    case 1:
      // Add Expense Function
      printf("Enter expense name: ");
      char expense_name[20];
      scanf("%s", expense_name);

      printf("Enter expense amount: ");
      int expense_amount = 0;
      scanf("%d", &expense_amount);

      // Store Expense Data
      FILE *fp = fopen("expenses.txt", "a");
      fprintf(fp, "%s, %d\n", expense_name, expense_amount);
      fclose(fp);

      printf("Expense added successfully.\n");
      break;

    case 2:
      // View Expenses Function
      fp = fopen("expenses.txt", "r");
      printf("Expenses:\n");
      char line[100];
      while (fgets(line, 100, fp) != NULL) {
        printf("%s\n", line);
      }
      fclose(fp);
      break;

    case 3:
      // Edit Expenses Function
      printf("Enter expense name: ");
      char edit_name[20];
      scanf("%s", edit_name);

      printf("Enter new expense amount: ");
      int edit_amount = 0;
      scanf("%d", &edit_amount);

      // Update Expense Data
      fp = fopen("expenses.txt", "w");
      fprintf(fp, "Expenses:\n");
      line[0] = '\0';
      while (fgets(line, 100, fp) != NULL) {
        if (strcmp(line, edit_name) == 0) {
          fprintf(fp, "%s, %d\n", edit_name, edit_amount);
        } else {
          fprintf(fp, "%s\n", line);
        }
      }
      fclose(fp);

      printf("Expense updated successfully.\n");
      break;

    case 4:
      // Delete Expenses Function
      printf("Enter expense name: ");
      char delete_name[20];
      scanf("%s", delete_name);

      // Delete Expense Data
      fp = fopen("expenses.txt", "w");
      fprintf(fp, "Expenses:\n");
      line[0] = '\0';
      while (fgets(line, 100, fp) != NULL) {
        if (strcmp(line, delete_name) != 0) {
          fprintf(fp, "%s\n", line);
        }
      }
      fclose(fp);

      printf("Expense deleted successfully.\n");
      break;

    case 5:
      // Exit Function
      printf("Thank you for using Expense Tracker v1.0.\n");
      break;

    default:
      printf("Invalid input. Please try again.\n");
  }

  system("pause");
  return 0;
}