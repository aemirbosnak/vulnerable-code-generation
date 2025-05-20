//FormAI DATASET v1.0 Category: Product Inventory System ; Style: paranoid
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define HASH_SIZE 100
#define MAX_PRODUCTS 500

// Struct to store the details of a product.
typedef struct product {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

// Struct to store the details of a hash node.
typedef struct hash_node {
    Product p;
    struct hash_node* next;
} HashNode;

// Array to store the hash table.
HashNode* hash_table[HASH_SIZE];

// An array to store the products.
Product products[MAX_PRODUCTS];

// Counter for the number of products.
int num_products = 0;

// Function to convert a string to a hash value.
int hash_value(char* s) {
    int sum = 0;
    for(int i=0; i<strlen(s); i++) {
        sum += (int)s[i];
    }
    return sum % HASH_SIZE;
}

// Function to insert a product into the hash table.
void insert_product(Product p) {
    int key = hash_value(p.name);
    HashNode* new_node = (HashNode*) malloc(sizeof(HashNode));
    new_node->p = p;
    new_node->next = NULL;

    if(hash_table[key] == NULL) {
        hash_table[key] = new_node;
    } else {
        HashNode* temp = hash_table[key];
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to print the details of a product.
void print_product(Product p) {
    printf("Product ID: %d\n", p.id);
    printf("Product Name: %s\n", p.name);
    printf("Product Price: %.2f\n", p.price);
    printf("Product Quantity: %d\n", p.quantity);
    printf("--------------------\n");
}

// Function to print the details of all products.
void print_inventory() {
    for(int i=0; i<num_products; i++) {
        print_product(products[i]);
    }
}

// Function to search for a product by name.
Product* search_product(char* name) {
    int key = hash_value(name);
    HashNode* temp = hash_table[key];
    while(temp != NULL) {
        if(strcmp(temp->p.name, name) == 0) {
            return &(temp->p);
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to update the quantity of a product.
void update_quantity(Product* p, int quantity) {
    p->quantity += quantity;
}

// Function to remove a product.
void remove_product(Product* p) {
    p->id = -1;
    p->quantity = 0;
}

// Function to add a product to the inventory.
void add_product(Product p) {
    products[num_products++] = p;
    insert_product(p);
}

int main() {
    int choice;
    char name[50];
    Product* p;

    while(1) {
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Update Quantity\n");
        printf("4. Search Product\n");
        printf("5. Print Inventory\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product price: ");
                float price;
                scanf("%f", &price);
                printf("Enter product quantity: ");
                int quantity;
                scanf("%d", &quantity);
                Product p1 = {num_products+1, name, price, quantity};
                add_product(p1);
                printf("Product added successfully.\n");
                break;

            case 2:
                printf("Enter product name: ");
                scanf("%s", name);
                p = search_product(name);
                if(p == NULL) {
                    printf("Product not found.\n");
                } else {
                    remove_product(p);
                    printf("Product removed successfully.\n");
                }
                break;

            case 3:
                printf("Enter product name: ");
                scanf("%s", name);
                p = search_product(name);
                if(p == NULL) {
                    printf("Product not found.\n");
                } else {
                    printf("Enter quantity to add/remove: ");
                    int quantity;
                    scanf("%d", &quantity);
                    update_quantity(p, quantity);
                    printf("Quantity updated successfully.\n");
                }
                break;

            case 4:
                printf("Enter product name: ");
                scanf("%s", name);
                p = search_product(name);
                if(p == NULL) {
                    printf("Product not found.\n");
                } else {
                    print_product(*p);
                }
                break;

            case 5:
                print_inventory();
                break;

            case 6:
                exit(0);
        }
    }

    return 0;
}