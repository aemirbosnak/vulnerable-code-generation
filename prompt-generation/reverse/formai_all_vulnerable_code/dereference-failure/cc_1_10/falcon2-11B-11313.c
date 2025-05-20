//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct inventory {
    char item[20];
    int quantity;
};

struct inventory* create_inventory(char item[], int quantity) {
    struct inventory* inv = malloc(sizeof(struct inventory));
    if (inv == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(inv->item, item);
    inv->quantity = quantity;
    return inv;
}

void print_inventory(struct inventory* inv) {
    printf("%s: %d\n", inv->item, inv->quantity);
}

int main() {
    char item1[] = "Apple";
    int quantity1 = 10;
    struct inventory* inv1 = create_inventory(item1, quantity1);
    printf("Inventory: %s\n", inv1->item);
    print_inventory(inv1);

    char item2[] = "Banana";
    int quantity2 = 20;
    struct inventory* inv2 = create_inventory(item2, quantity2);
    printf("Inventory: %s\n", inv2->item);
    print_inventory(inv2);

    char item3[] = "Orange";
    int quantity3 = 30;
    struct inventory* inv3 = create_inventory(item3, quantity3);
    printf("Inventory: %s\n", inv3->item);
    print_inventory(inv3);

    char item4[] = "Pear";
    int quantity4 = 40;
    struct inventory* inv4 = create_inventory(item4, quantity4);
    printf("Inventory: %s\n", inv4->item);
    print_inventory(inv4);

    char item5[] = "Grapes";
    int quantity5 = 50;
    struct inventory* inv5 = create_inventory(item5, quantity5);
    printf("Inventory: %s\n", inv5->item);
    print_inventory(inv5);

    char item6[] = "Strawberry";
    int quantity6 = 60;
    struct inventory* inv6 = create_inventory(item6, quantity6);
    printf("Inventory: %s\n", inv6->item);
    print_inventory(inv6);

    char item7[] = "Watermelon";
    int quantity7 = 70;
    struct inventory* inv7 = create_inventory(item7, quantity7);
    printf("Inventory: %s\n", inv7->item);
    print_inventory(inv7);

    char item8[] = "Kiwi";
    int quantity8 = 80;
    struct inventory* inv8 = create_inventory(item8, quantity8);
    printf("Inventory: %s\n", inv8->item);
    print_inventory(inv8);

    char item9[] = "Mango";
    int quantity9 = 90;
    struct inventory* inv9 = create_inventory(item9, quantity9);
    printf("Inventory: %s\n", inv9->item);
    print_inventory(inv9);

    char item10[] = "Papaya";
    int quantity10 = 100;
    struct inventory* inv10 = create_inventory(item10, quantity10);
    printf("Inventory: %s\n", inv10->item);
    print_inventory(inv10);

    return 0;
}