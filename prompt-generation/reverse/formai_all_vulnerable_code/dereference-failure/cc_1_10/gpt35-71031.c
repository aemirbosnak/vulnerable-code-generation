//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int item_code;
    char item_name[20];
    float item_price;
    int item_quantity;
    struct node *next;
}Item;

Item *head = NULL;                  //initially empty

Item* create_item(int code,char name[],float price,int quantity){
    Item *new_item = (Item *)malloc(sizeof(Item));     //allocating memory for new item
    new_item->item_code = code;
    strcpy(new_item->item_name,name);
    new_item->item_price = price;
    new_item->item_quantity = quantity;
    new_item->next = NULL;                             //new item is the last item
    return new_item;
}

void add_item_at_end(Item *new_item){
    if(head == NULL){                       //list is empty
        head = new_item;
    }
    else{                                   //list is not empty
        Item *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_item;
    }
}

void display(){
    printf("Item Code\tItem Name\tItem Price\tItem Quantity\n");
    Item *temp = head;
    while(temp != NULL){
        printf("%d\t\t%s\t\t%.2f\t\t%d\n",temp->item_code,temp->item_name,temp->item_price,temp->item_quantity);
        temp = temp->next;
    }
}

void delete_item(int code){
    Item *temp1 = head;
    Item *temp2 = head;
    while(temp1 != NULL && temp1->item_code != code){          //searching for the item to be deleted
        temp2 = temp1;
        temp1 = temp1->next;
    }
    if(temp1 == NULL){
        printf("Item not found with code %d\n",code);
    }
    else{
        temp2->next = temp1->next;
        free(temp1);
    }
}

void update_item_quantity(int code, int quantity){
    Item *temp = head;
    while(temp != NULL && temp->item_code != code){      //searching for the item to be updated
        temp = temp->next;
    }   
    if(temp == NULL){
        printf("Item not found with code %d\n",code);
    }
    else{
        temp->item_quantity = quantity;
    }
}

int main(){
    printf("C Product Inventory System\n");
    printf("1.Add Item\n2.Display Items\n3.Delete Item\n4.Update Item Quantity\n5.Exit\n");
    int choice,code,quantity;
    char name[20];
    float price;
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
                printf("Enter item code: ");
                scanf("%d",&code);
                printf("Enter item name: ");
                scanf("%s",name);
                printf("Enter item price: ");
                scanf("%f",&price);
                printf("Enter item quantity: ");
                scanf("%d",&quantity);
                add_item_at_end(create_item(code,name,price,quantity));    //adding item to the inventory
                break;
            case 2:
                display();                                                  //displaying inventory
                break;
            case 3:
                printf("Enter item code to delete: ");
                scanf("%d",&code);
                delete_item(code);                                          //deleting an item from inventory
                break;
            case 4:
                printf("Enter item code to update quantity: ");
                scanf("%d",&code);
                printf("Enter new quantity: ");
                scanf("%d",&quantity);
                update_item_quantity(code,quantity);                        //updating quantity of an item
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}