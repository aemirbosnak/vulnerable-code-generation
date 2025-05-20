//FormAI DATASET v1.0 Category: Data mining ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME 100

typedef struct item{
    int id;
    char name[MAX_NAME];
    float weight;
    int quantity;
} ITEM;

int main(){

    ITEM items[MAX_ITEMS];
    int num_items = 0;

    FILE *fp;
    char* filename = "inventory.txt";
    char line[MAX_NAME];

    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("Error: cannot read inventory file.\n");
        exit(EXIT_FAILURE);
    }

    // read in inventory file
    while(fgets(line, MAX_NAME, fp)){
        char* token;
        token = strtok(line, ",");

        // get id
        items[num_items].id = atoi(token);
        token = strtok(NULL, ",");

        // get name
        strcpy(items[num_items].name, token);
        token = strtok(NULL, ",");

        // get weight
        items[num_items].weight = atof(token);
        token = strtok(NULL, ",");

        // get quantity
        items[num_items].quantity = atoi(token);

        num_items++;
    }

    fclose(fp);

    // display initial inventory
    printf("Initial Inventory:\n");
    for(int i = 0; i < num_items; i++){
        printf("Item %d: %s, Weight: %.2f, Quantity: %d\n", items[i].id, items[i].name, items[i].weight, items[i].quantity);
    }

    // search for valuable items
    printf("\nSearching for valuable items...\n");
    for(int i = 0; i < num_items; i++){
        if(items[i].weight < 1 && items[i].quantity > 0){ // valuable item
            printf("Valuable item found! Item %d: %s, Weight: %.2f, Quantity: %d\n", items[i].id, items[i].name, items[i].weight, items[i].quantity);

            // update quantity and write to file
            items[i].quantity--;
            fp = fopen(filename, "w");

            if(fp == NULL){
                printf("Error: cannot write to inventory file.\n");
                exit(EXIT_FAILURE);
            }

            for(int j = 0; j < num_items; j++){
                fprintf(fp, "%d,%s,%.2f,%d\n", items[j].id, items[j].name, items[j].weight, items[j].quantity);
            }

            fclose(fp);
            break;
        }
    }

    // display updated inventory
    printf("\nUpdated Inventory:\n");
    for(int i = 0; i < num_items; i++){
        printf("Item %d: %s, Weight: %.2f, Quantity: %d\n", items[i].id, items[i].name, items[i].weight, items[i].quantity);
    }

    return 0;
}