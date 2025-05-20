//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

//Structs for the products
struct product{
    int id;
    char name[50];
    float cost;
    int stock;
};

//Struct for the warehouse
struct warehouse{
    int id;
    char name[50];
    int capacity;
    int num_products;
    struct product *products; //Array of products in warehouse
};

//Function to check if a product is available in the warehouse
void check_product(struct product *prods, int n, int id){
    int i, flag = 0;
    for(i=0;i<n;i++){
        if(prods[i].id == id){
            flag = 1;
            printf("\nProduct Name: %s", prods[i].name);
            printf("\nProduct Cost: %f", prods[i].cost);
            printf("\nProduct Stock: %d", prods[i].stock);
            break;
        }
    }
    if(flag == 0)
        printf("\nProduct not found!\n");
}

//Function to add a new product to the warehouse
void add_product(struct product *prods, int n, int id, char name[], float cost, int stock){
    prods[n].id = id;
    strcpy(prods[n].name, name);
    prods[n].cost = cost;
    prods[n].stock = stock;
    printf("\nProduct added successfully!\n");
}

//Function to remove a product from the warehouse
void remove_product(struct product *prods, int n, int id){
    int i, flag = 0;
    for(i=0;i<n;i++){
        if(prods[i].id == id){
            flag = 1;
            prods[i] = prods[n-1];  //Replace the product with the last product in the array
            printf("\nProduct removed successfully!\n");
            break;
        }
    }
    if(flag == 0)
        printf("\nProduct not found!\n");
}

//Function to display the products in the warehouse
void display_products(struct product *prods, int n){
    int i;
    printf("\nID\tNAME\tCOST\tSTOCK\n");
    for(i=0;i<n;i++){
        printf("%d\t%s\t%f\t%d\n", prods[i].id, prods[i].name, prods[i].cost, prods[i].stock);
    }
}

int main(){
    //Creating a warehouse
    struct warehouse w1;
    w1.id = 1;
    strcpy(w1.name, "Warehouse 1");
    w1.capacity = 100;
    w1.num_products = 0;
    w1.products = (struct product*)malloc(w1.capacity*sizeof(struct product));

    //Adding some products to the warehouse
    add_product(w1.products, w1.num_products++, 1, "Product 1", 10.0, 20);
    add_product(w1.products, w1.num_products++, 2, "Product 2", 15.0, 30);
    add_product(w1.products, w1.num_products++, 3, "Product 3", 20.0, 10);

    //Displaying the products in the warehouse
    display_products(w1.products, w1.num_products);

    //Checking if a product is available in the warehouse
    check_product(w1.products, w1.num_products, 2);

    //Removing a product from the warehouse
    remove_product(w1.products, w1.num_products--, 2);

    //Displaying the products in the warehouse after removal
    display_products(w1.products, w1.num_products);

    //Free the memory allocated for the products array
    free(w1.products);

    printf("\nProgram executed successfully!\n");

    return 0;
}