//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int item_code;
  char *item_name;
  float item_price;
  int item_quantity;
} item_t;

typedef struct {
  int bill_no;
  char *customer_name;
  char *date;
  item_t *items;
  int num_items;
  float total_amount;
} bill_t;

void add_item(bill_t *bill, item_t *item) {
  bill->items = realloc(bill->items, (bill->num_items + 1) * sizeof(item_t));
  bill->items[bill->num_items] = *item;
  bill->num_items++;
}

void calculate_total(bill_t *bill) {
  bill->total_amount = 0;
  for (int i = 0; i < bill->num_items; i++) {
    bill->total_amount += bill->items[i].item_price * bill->items[i].item_quantity;
  }
}

void print_bill(bill_t *bill) {
  printf("Bill No: %d\n", bill->bill_no);
  printf("Customer Name: %s\n", bill->customer_name);
  printf("Date: %s\n", bill->date);

  printf("\nItems:\n");
  printf("-------------------------------------------------------------------------\n");
  printf("%-10s %-20s %-10s %-10s %-10s\n", "Item Code", "Item Name", "Item Price", "Item Quantity", "Item Total");
  printf("-------------------------------------------------------------------------\n");
  for (int i = 0; i < bill->num_items; i++) {
    printf("%-10d %-20s %-10.2f %-10d %-10.2f\n",
           bill->items[i].item_code,
           bill->items[i].item_name,
           bill->items[i].item_price,
           bill->items[i].item_quantity,
           bill->items[i].item_price * bill->items[i].item_quantity);
  }
  printf("-------------------------------------------------------------------------\n");

  printf("Total Amount: %.2f\n", bill->total_amount);
}

int main() {
  bill_t bill;
  bill.bill_no = 1001;
  bill.customer_name = "John Doe";
  bill.date = "2023-03-08";
  bill.num_items = 0;
  bill.items = NULL;

  item_t item1;
  item1.item_code = 101;
  item1.item_name = "Pizza";
  item1.item_price = 100;
  item1.item_quantity = 2;

  item_t item2;
  item2.item_code = 102;
  item2.item_name = "Burger";
  item2.item_price = 50;
  item2.item_quantity = 3;

  item_t item3;
  item3.item_code = 103;
  item3.item_name = "Fries";
  item3.item_price = 20;
  item3.item_quantity = 1;

  add_item(&bill, &item1);
  add_item(&bill, &item2);
  add_item(&bill, &item3);

  calculate_total(&bill);
  print_bill(&bill);

  return 0;
}