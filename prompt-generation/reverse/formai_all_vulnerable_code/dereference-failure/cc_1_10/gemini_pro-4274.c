//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

struct cafe_item {
  char name[50];
  float price;
  int quantity;
};

struct cafe_order {
  struct cafe_item *items;
  int num_items;
  float total_price;
};

struct cafe_customer {
  char name[50];
  struct cafe_order *order;
};

void print_menu() {
  printf("Welcome to the Cafe! Our menu is as follows:\n");
  printf("----------------------------------------------------\n");
  printf("| Item | Price | Quantity |\n");
  printf("----------------------------------------------------\n");
  printf("| Coffee | 2.50 | Unlimited |\n");
  printf("| Tea | 1.50 | Unlimited |\n");
  printf("| Cake | 3.00 | Limited (5) |\n");
  printf("| Sandwich | 4.00 | Limited (3) |\n");
  printf("----------------------------------------------------\n");
}

void create_order(struct cafe_customer *customer) {
  int num_items;
  printf("How many items would you like to order? ");
  scanf("%d", &num_items);

  customer->order = (struct cafe_order *)malloc(sizeof(struct cafe_order));
  customer->order->items = (struct cafe_item *)malloc(sizeof(struct cafe_item) * num_items);
  customer->order->num_items = num_items;
  customer->order->total_price = 0.0;

  for (int i = 0; i < num_items; i++) {
    printf("What is the name of item %d? ", i + 1);
    scanf("%s", customer->order->items[i].name);

    printf("What is the price of item %d? ", i + 1);
    scanf("%f", &customer->order->items[i].price);

    printf("What is the quantity of item %d? ", i + 1);
    scanf("%d", &customer->order->items[i].quantity);

    customer->order->total_price += customer->order->items[i].price * customer->order->items[i].quantity;
  }
}

void print_order(struct cafe_customer *customer) {
  printf("Here is your order:\n");
  printf("----------------------------------------------------\n");
  printf("| Item | Price | Quantity | Subtotal |\n");
  printf("----------------------------------------------------\n");
  for (int i = 0; i < customer->order->num_items; i++) {
    printf("| %s | %.2f | %d | %.2f |\n", customer->order->items[i].name, customer->order->items[i].price,
           customer->order->items[i].quantity,
           customer->order->items[i].price * customer->order->items[i].quantity);
  }
  printf("----------------------------------------------------\n");
  printf("Total: %.2f\n", customer->order->total_price);
}

int main() {
  struct cafe_customer customer;

  printf("Welcome to the Cafe! What is your name? ");
  scanf("%s", customer.name);

  print_menu();

  create_order(&customer);

  print_order(&customer);

  return 0;
}