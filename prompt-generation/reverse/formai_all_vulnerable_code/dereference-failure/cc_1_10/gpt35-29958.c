//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: detailed
#include<stdio.h> 
#include<stdlib.h> 

// Structure to represent a baggage item
struct baggage_item{
    int id; // unique id for the item
    int weight; // weight of the item in Kg
};

// Structure to represent a baggage cart
struct cart{
    int cart_id; // unique id for the cart
    int capacity; // maximum capacity of the cart in Kg
    int current_weight; // current weight of the cart in Kg
    int num_items; // number of baggage items in the cart
    struct baggage_item* items[50]; // array of pointers to baggage_item
};

// Helper function to create a new baggage item
struct baggage_item* create_baggage_item(int id, int weight){
    struct baggage_item* item = (struct baggage_item*) malloc(sizeof(struct baggage_item));
    item->id = id;
    item->weight = weight;
    return item;
}

// Helper function to create a new cart with the given id and capacity
struct cart* create_cart(int cart_id, int capacity){
    struct cart* cart = (struct cart*) malloc(sizeof(struct cart));
    cart->cart_id = cart_id;
    cart->capacity = capacity;
    cart->current_weight = 0;
    cart->num_items = 0;
    return cart;
}

// Function to add a baggage item to a cart
void add_baggage_item_to_cart(struct cart* cart, struct baggage_item* item){
    if(cart->current_weight + item->weight > cart->capacity){
        printf("Error: Cart %d is already full! Cannot add item %d\n", 
                cart->cart_id, item->id);
        return;
    }

    cart->items[cart->num_items] = item; // add pointer to the item to cart's array of items
    cart->num_items++; // increment the number of items in the cart
    cart->current_weight += item->weight; // add item's weight to cart's current weight

    printf("Added item %d to cart %d\n", item->id, cart->cart_id);
}

// Function to print the contents of a cart
void print_cart_contents(struct cart* cart){
    printf("Cart %d has %d items with total weight %d Kg\n", 
            cart->cart_id, cart->num_items, cart->current_weight);

    printf("Item IDs: ");
    for(int i=0;i<cart->num_items;i++){
        printf("%d ", cart->items[i]->id);
    }
    printf("\n");
}

int main(){

    // Create 4 carts with different capacities
    struct cart* cart1 = create_cart(1, 1000);
    struct cart* cart2 = create_cart(2, 2000);
    struct cart* cart3 = create_cart(3, 1500);
    struct cart* cart4 = create_cart(4, 3000);

    // Create 10 baggage items
    struct baggage_item* item1 = create_baggage_item(1, 250);
    struct baggage_item* item2 = create_baggage_item(2, 150);
    struct baggage_item* item3 = create_baggage_item(3, 350);
    struct baggage_item* item4 = create_baggage_item(4, 200);
    struct baggage_item* item5 = create_baggage_item(5, 100);
    struct baggage_item* item6 = create_baggage_item(6, 400);
    struct baggage_item* item7 = create_baggage_item(7, 300);
    struct baggage_item* item8 = create_baggage_item(8, 50);
    struct baggage_item* item9 = create_baggage_item(9, 450);
    struct baggage_item* item10 = create_baggage_item(10, 150);

    // Add some items to the carts
    add_baggage_item_to_cart(cart1, item6);
    add_baggage_item_to_cart(cart2, item1);
    add_baggage_item_to_cart(cart3, item2);
    add_baggage_item_to_cart(cart1, item7);
    add_baggage_item_to_cart(cart1, item9);
    add_baggage_item_to_cart(cart4, item3);

    // Print contents of carts
    print_cart_contents(cart1);
    print_cart_contents(cart2);
    print_cart_contents(cart3);
    print_cart_contents(cart4);

    // Add more items to carts
    add_baggage_item_to_cart(cart2, item5);
    add_baggage_item_to_cart(cart4, item10);
    add_baggage_item_to_cart(cart3, item4);
    add_baggage_item_to_cart(cart4, item8);

    // Print contents of carts again
    print_cart_contents(cart1);
    print_cart_contents(cart2);
    print_cart_contents(cart3);
    print_cart_contents(cart4);

    return 0;
}