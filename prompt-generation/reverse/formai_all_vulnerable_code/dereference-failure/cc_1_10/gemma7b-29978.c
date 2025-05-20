//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store item information
typedef struct item {
  char name[20];
  int price;
  int quantity;
} item_t;

// Define a function to calculate the total cost of an item
int calculate_cost(item_t item) {
  return item.price * item.quantity;
}

// Define a function to display the menu
void display_menu(item_t items[]) {
  for (int i = 0; items[i].name[0] != '\0'; i++) {
    printf("%s - %d\n", items[i].name, items[i].price);
  }
}

// Define a function to process customer order
void process_order(item_t items[]) {
  char item_name[20];
  int quantity;

  printf("Enter item name:");
  scanf("%s", item_name);

  for (int i = 0; items[i].name[0] != '\0'; i++) {
    if (strcmp(item_name, items[i].name) == 0) {
      printf("Enter quantity:");
      scanf("%d", &quantity);

      items[i].quantity += quantity;
    }
  }
}

int main() {
  // Create an array of items
  item_t items[] = {
    {"Coffee", 50, 0},
    {"Tea", 40, 0},
    {"Juice", 30, 0},
    {"Soda", 20, 0}
  };

  // Display the menu
  display_menu(items);

  // Process the customer order
  process_order(items);

  // Calculate the total cost of the order
  int total_cost = 0;
  for (int i = 0; items[i].name[0] != '\0'; i++) {
    total_cost += calculate_cost(items[i]);
  }

  // Print the total cost
  printf("Total cost: %d\n", total_cost);

  return 0;
}