//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

typedef struct{
    char name[20];
    int code;
    float price;
}Item;

void addItem(Item *menu, int *size){
    char name[20];
    int code;
    float price;

    printf("Enter the name of the item: ");
    scanf("%s",name);

    printf("Enter the code for the item: ");
    scanf("%d",&code);

    printf("Enter the price of the item: ");
    scanf("%f",&price);

    (*size)++;
    menu = realloc(menu,(*size)*sizeof(Item));

    strcpy(menu[*size-1].name,name);
    menu[*size-1].code = code;
    menu[*size-1].price = price;
}

void displayMenu(Item menu[], int size){
    int i;

    for(i=0;i<size;i++){
        printf("%d. %s - $%.2f\n",i+1,menu[i].name,menu[i].price);
    }
}

int main(){
    int size = 0;
    Item menu[10];

    addItem(menu,&size);
    addItem(menu,&size);
    addItem(menu,&size);

    displayMenu(menu,size);

    return 0;
}