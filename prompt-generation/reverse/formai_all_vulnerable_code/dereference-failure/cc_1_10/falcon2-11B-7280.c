//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char name[50];
    float price;
} Product;

typedef struct {
    Product *products;
    int size;
} Cart;

void add_to_cart(Cart *cart, Product product) {
    if (cart->size == 0) {
        cart->products = (Product *)malloc(sizeof(Product));
        strcpy(cart->products[0].name, product.name);
        cart->products[0].price = product.price;
        cart->size++;
    } else {
        Product *new_product = (Product *)malloc(sizeof(Product));
        strcpy(new_product->name, product.name);
        new_product->price = product.price;
        cart->products = (Product *)realloc(cart->products, (cart->size + 1) * sizeof(Product));
        strcpy(cart->products[cart->size].name, new_product->name);
        cart->products[cart->size].price = new_product->price;
        cart->size++;
    }
}

float calculate_total(Cart *cart) {
    float total = 0;
    for (int i = 0; i < cart->size; i++) {
        total += cart->products[i].price;
    }
    return total;
}

void print_cart(Cart *cart) {
    printf("Cart:\n");
    for (int i = 0; i < cart->size; i++) {
        printf("- %s: %.2f\n", cart->products[i].name, cart->products[i].price);
    }
}

int main() {
    Cart cart;
    cart.size = 0;
    cart.products = NULL;

    Product product1;
    strcpy(product1.name, "Item 1");
    product1.price = 10.99;
    add_to_cart(&cart, product1);

    Product product2;
    strcpy(product2.name, "Item 2");
    product2.price = 5.99;
    add_to_cart(&cart, product2);

    Product product3;
    strcpy(product3.name, "Item 3");
    product3.price = 2.99;
    add_to_cart(&cart, product3);

    printf("Total: %.2f\n", calculate_total(&cart));
    print_cart(&cart);

    return 0;
}