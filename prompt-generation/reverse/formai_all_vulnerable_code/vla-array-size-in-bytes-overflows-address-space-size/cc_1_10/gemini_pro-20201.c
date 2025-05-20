//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and prices
char menu[][20] = {"Coffee", "Tea", "Sandwich", "Salad", "Cake"};
float prices[] = {1.50, 1.20, 4.00, 5.00, 2.50};

// Get the number of items ordered
int get_num_items() {
  int num_items;
  printf("How many items would you like to order? ");
  scanf("%d", &num_items);
  return num_items;
}

// Get the item ordered
int get_item(int num_items) {
  int item;
  printf("What item would you like to order? (Enter the number corresponding to the item on the menu): ");
  scanf("%d", &item);
  while (item < 1 || item > num_items) {
    printf("Invalid item. Please enter a number between 1 and %d: ", num_items);
    scanf("%d", &item);
  }
  return item;
}

// Calculate the total price of the order
float calculate_total(int num_items, int items[]) {
  float total = 0.0;
  for (int i = 0; i < num_items; i++) {
    total += prices[items[i] - 1];
  }
  return total;
}

// Print the receipt
void print_receipt(float total) {
  printf("Your total is: %.2f\n", total);
  printf("Thank you for your patronage!\n");
}

// Main function
int main() {
  // Get the number of items ordered
  int num_items = get_num_items();

  // Get the items ordered
  int items[num_items];
  for (int i = 0; i < num_items; i++) {
    items[i] = get_item(num_items);
  }

  // Calculate the total price of the order
  float total = calculate_total(num_items, items);

  // Print the receipt
  print_receipt(total);

  return 0;
}