//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a product
typedef struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

// Function to create a new product
Product* createProduct(int id, char* name, int quantity, float price) {
    Product* product = (Product*)malloc(sizeof(Product));
    product->id = id;
    strcpy(product->name, name);
    product->quantity = quantity;
    product->price = price;
    return product;
}

// Function to add a product to the inventory
void addProduct(Product* product) {
    // Open the inventory file in append mode
    FILE* fp = fopen("inventory.txt", "a");
    
    // Write the product details to the file
    fprintf(fp, "%d %s %d %.2f\n", product->id, product->name, product->quantity, product->price);
    
    // Close the file
    fclose(fp);
}

// Function to search for a product in the inventory
Product* searchProduct(int id) {
    // Open the inventory file in read mode
    FILE* fp = fopen("inventory.txt", "r");
    
    // Read the file line by line
    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        // Split the line into tokens
        char* tokens[4];
        int i = 0;
        char* token = strtok(line, " ");
        while (token != NULL) {
            tokens[i++] = token;
            token = strtok(NULL, " ");
        }
        
        // Check if the product ID matches the given ID
        if (atoi(tokens[0]) == id) {
            // Create a new product object and populate it with the data from the file
            Product* product = createProduct(atoi(tokens[0]), tokens[1], atoi(tokens[2]), atof(tokens[3]));
            
            // Close the file and return the product
            fclose(fp);
            return product;
        }
    }
    
    // If the product ID is not found, return NULL
    fclose(fp);
    return NULL;
}

// Function to update a product in the inventory
void updateProduct(Product* product) {
    // Open the inventory file in read/write mode
    FILE* fp = fopen("inventory.txt", "r+");
    
    // Read the file line by line
    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        // Split the line into tokens
        char* tokens[4];
        int i = 0;
        char* token = strtok(line, " ");
        while (token != NULL) {
            tokens[i++] = token;
            token = strtok(NULL, " ");
        }
        
        // Check if the product ID matches the given ID
        if (atoi(tokens[0]) == product->id) {
            // Update the product details in the file
            fseek(fp, -strlen(line), SEEK_CUR);
            fprintf(fp, "%d %s %d %.2f\n", product->id, product->name, product->quantity, product->price);
            
            // Close the file
            fclose(fp);
            return;
        }
    }
    
    // If the product ID is not found, add the new product to the file
    addProduct(product);
}

// Function to delete a product from the inventory
void deleteProduct(int id) {
    // Open the inventory file in read/write mode
    FILE* fp = fopen("inventory.txt", "r+");
    
    // Read the file line by line
    char line[100];
    FILE* temp = fopen("temp.txt", "w");
    while (fgets(line, sizeof(line), fp)) {
        // Split the line into tokens
        char* tokens[4];
        int i = 0;
        char* token = strtok(line, " ");
        while (token != NULL) {
            tokens[i++] = token;
            token = strtok(NULL, " ");
        }
        
        // Check if the product ID matches the given ID
        if (atoi(tokens[0]) != id) {
            // Write the line to the temporary file
            fprintf(temp, "%s", line);
        }
    }
    
    // Close both files
    fclose(fp);
    fclose(temp);
    
    // Delete the inventory file and rename the temporary file to inventory.txt
    remove("inventory.txt");
    rename("temp.txt", "inventory.txt");
}

// Function to print the inventory
void printInventory() {
    // Open the inventory file in read mode
    FILE* fp = fopen("inventory.txt", "r");
    
    // Read the file line by line
    char line[100];
    printf("Inventory:\n");
    while (fgets(line, sizeof(line), fp)) {
        // Split the line into tokens
        char* tokens[4];
        int i = 0;
        char* token = strtok(line, " ");
        while (token != NULL) {
            tokens[i++] = token;
            token = strtok(NULL, " ");
        }
        
        // Print the product details
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", atoi(tokens[0]), tokens[1], atoi(tokens[2]), atof(tokens[3]));
    }
    
    // Close the file
    fclose(fp);
}

int main() {
    // Create a new product
    Product* product1 = createProduct(1, "Apple", 10, 1.50);
    
    // Add the product to the inventory
    addProduct(product1);
    
    // Search for the product in the inventory
    Product* product2 = searchProduct(1);
    
    // Update the product in the inventory
    product2->quantity = 15;
    updateProduct(product2);
    
    // Delete the product from the inventory
    deleteProduct(1);
    
    // Print the inventory
    printInventory();
    
    return 0;
}