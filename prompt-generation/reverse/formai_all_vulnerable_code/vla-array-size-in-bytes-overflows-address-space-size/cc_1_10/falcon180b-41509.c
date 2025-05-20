//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: multivariable
//C Searching Algorithm Example Program

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining the maximum size of the array
#define MAX 100

//Defining the structure for the items in the array
typedef struct{
    char name[50];
    int quantity;
    float price;
}Item;

//Defining the function to compare two items based on their names
int compare(const void* a, const void* b){
    const char* nameA = ((const Item*)a)->name;
    const char* nameB = ((const Item*)b)->name;
    return strcmp(nameA, nameB);
}

//Defining the function to search for an item in the array
int search(Item arr[], int size, char* name){
    Item* result = bsearch(&name, arr, size, sizeof(Item), compare);
    if(result!= NULL){
        printf("Item found:\n");
        printf("Name: %s\n", result->name);
        printf("Quantity: %d\n", result->quantity);
        printf("Price: %.2f\n", result->price);
    }
    else{
        printf("Item not found.\n");
    }
    return 0;
}

int main(){
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    Item arr[size];
    printf("Enter the items:\n");
    for(int i=0; i<size; i++){
        scanf("%s %d %.2f", arr[i].name, &arr[i].quantity, &arr[i].price);
    }

    char name[50];
    printf("Enter the name of the item to search: ");
    scanf("%s", name);

    search(arr, size, name);

    return 0;
}

//End of the program