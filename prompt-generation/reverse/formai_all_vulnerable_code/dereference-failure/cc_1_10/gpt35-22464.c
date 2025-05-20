//FormAI DATASET v1.0 Category: Product Inventory System ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

/* Global Definition of Structure for the Product */
struct product
{
    int product_id;
    char product_name[20];
    int quantity;
    float price;
    struct product *nextProduct;
};

/* Function Prototypes */
void addProduct();
void displayProducts(struct product *currentProduct);
void searchProduct(struct product *currentProduct, int id);
struct product* deleteProduct(struct product *currentProduct, int id);

/* Global Declarations */
struct product *startProduct = NULL;

/* Main Function */
int main()
{
    int choice, id;
    do
    {
        printf("\n\n*** Welcome to the Product Inventory System ***\n\n");
        printf("List of Available Operations:\n");
        printf("1. Add a New Product\n");
        printf("2. Display all the Available Products\n");
        printf("3. Search for a Specific Product\n");
        printf("4. Delete a Product\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addProduct();
                break;
            case 2:
                if(startProduct == NULL)
                    printf("\nSorry, The Inventory is Empty.\n");
                else
                    displayProducts(startProduct);
                break;
            case 3:
                printf("\nEnter the Product ID you want to Search: ");
                scanf("%d", &id);
                if(startProduct == NULL)
                    printf("\nSorry, The Inventory is Empty.\n");
                else
                    searchProduct(startProduct, id);
                break;
            case 4:
                printf("\nEnter the Product ID you want to Delete: ");
                scanf("%d", &id);
                if(startProduct == NULL)
                    printf("\nSorry, The Inventory is Empty.\n");
                else
                    startProduct = deleteProduct(startProduct, id);
                break;
            case 5:
                printf("\nExiting the Program. Thank you!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid Choice. Please Enter a Valid Choice.\n");
        }
    } while(choice != 5);
    return 0;
}

/* Function to Add a New Product */
void addProduct()
{
    struct product *newProduct, *currentProduct;
    newProduct = (struct product*) malloc(sizeof(struct product));
    printf("\nEnter the Product ID: ");
    scanf("%d", &newProduct->product_id);
    printf("Enter the Product Name: ");
    scanf("%s", &newProduct->product_name);
    printf("Enter the Quantity of the Product: ");
    scanf("%d", &newProduct->quantity);
    printf("Enter the Price of the Product: ");
    scanf("%f", &newProduct->price);
    newProduct->nextProduct = NULL;
    
    /* Recursive Function to Insert the Product at the End of the Inventory */
    if(startProduct == NULL)
    {
        startProduct = newProduct;
    }
    else
    {
        currentProduct = startProduct;
        while(currentProduct->nextProduct != NULL)
        {
            currentProduct = currentProduct->nextProduct;
        }
        currentProduct->nextProduct = newProduct;
    }
    printf("\nNew Product Added Successfully.\n");
}

/* Function to Display all the Available Products */
void displayProducts(struct product *currentProduct)
{
    printf("\nList of Available Products:\n");
    printf("Product ID\tProduct Name\tQuantity\tPrice\n");
    while(currentProduct != NULL)
    {
        printf("%d\t%s\t\t%d\t\t%.2f\n", currentProduct->product_id, currentProduct->product_name, currentProduct->quantity, currentProduct->price);
        currentProduct = currentProduct->nextProduct;
    }
}

/* Function to Search for a Specific Product */
void searchProduct(struct product *currentProduct, int id)
{
    int flag = 0;
    while(currentProduct != NULL)
    {
        if(currentProduct->product_id == id)
        {
            printf("\nProduct Found in the Inventory.\n");
            printf("Product ID\tProduct Name\tQuantity\tPrice\n");
            printf("%d\t%s\t\t%d\t\t%.2f\n", currentProduct->product_id, currentProduct->product_name, currentProduct->quantity, currentProduct->price);
            flag = 1;
            break;
        }
        currentProduct = currentProduct->nextProduct;
    }
    if(flag == 0)
    {
        printf("\nSorry, The Product is not Found in the Inventory.\n");
    }
}

/* Function to Delete a Product */
struct product* deleteProduct(struct product *currentProduct, int id)
{
    struct product *temp;
    if(currentProduct == NULL)
    {
        printf("\nSorry, The Inventory is Empty.\n");
        return currentProduct;
    }
    if(currentProduct->product_id == id)
    {
        temp = currentProduct->nextProduct;
        free(currentProduct);
        printf("\nProduct Deleted Successfully.\n");
        return temp;
    }
    currentProduct->nextProduct = deleteProduct(currentProduct->nextProduct, id);
    return currentProduct;
}