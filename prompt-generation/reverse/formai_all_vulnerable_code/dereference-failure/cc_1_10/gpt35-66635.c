//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct coffee{
    char name[50];
    int price;
    int quantity;
    struct coffee *next;
};

struct coffee *head=NULL;

void add_new_coffee(char name[50],int price,int quantity){
    struct coffee *new_coffee=(struct coffee*)malloc(sizeof(struct coffee));
    strcpy(new_coffee->name,name);
    new_coffee->price=price;
    new_coffee->quantity=quantity;
    new_coffee->next=NULL;
    if(head==NULL){
        head=new_coffee;
    }
    else{
        struct coffee *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_coffee;
    }
}

void remove_coffee(int coffee_index){
    if(coffee_index<0){
        printf("Invalid index. Try again.\n");
        return;
    }
    if(coffee_index==0){
        struct coffee *temp=head;
        head=head->next;
        free(temp);
    }
    else{
        struct coffee *temp_1=head;
        struct coffee *temp_2=head->next;
        while(temp_2!=NULL && coffee_index>1){  
            coffee_index--;
            temp_1=temp_2;
            temp_2=temp_2->next;
        }
        if(temp_2==NULL){
            printf("Invalid index. Try again.\n");
            return;
        }
        temp_1->next=temp_2->next;
        free(temp_2);
    } 
}

void display_coffees(){
    struct coffee *temp=head;
    while(temp!=NULL){
        printf("%s\tRs%d\tQuantity=%d\n",temp->name,temp->price,temp->quantity);
        temp=temp->next;
    }
}

int main(){
    
    add_new_coffee("Espresso",50,10);
    add_new_coffee("Americano",70,15);
    add_new_coffee("Latte",80,20);
    add_new_coffee("Cappuccino",90,22);
    add_new_coffee("Mocha",100,5);
    
    while(1){
        printf("\nWelcome to Cafe Billing System\n\n");
        printf("1. Add new coffee\n");
        printf("2. Remove a coffee\n");
        printf("3. Display all coffees\n");
        printf("4. Bill generation\n");
        printf("5. Exit\n");
        printf("Enter your choice:\n");
        
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("Enter name of coffee:\n");
                char name[50];
                scanf("%s",name);
                printf("Enter price of coffee:\n");
                int price;
                scanf("%d",&price);
                printf("Enter quantity of coffee:\n");
                int quantity;
                scanf("%d",&quantity);
                add_new_coffee(name,price,quantity);
                printf("Coffee added successfully.\n");
                break;
            }
            case 2:{
                printf("Enter index of coffee to remove (starting from 0):\n");
                int index;
                scanf("%d",&index);
                remove_coffee(index);
                break;
            }
            case 3:{
                printf("\nMenu:\n");
                printf("Name of coffee\tPrice\tQuantity\n\n");
                display_coffees();
                break;
            }
            case 4:{
                int total_bill=0;
                printf("Enter number of coffees to bill:\n");
                int number_of_coffees;
                scanf("%d",&number_of_coffees);
                for(int i=0;i<number_of_coffees;i++){
                    printf("Enter name of coffee:\n");
                    char name[50];
                    scanf("%s",name);
                    struct coffee *temp=head;
                    while(temp!=NULL){
                        if(strcmp(temp->name,name)==0){
                            int quantity;
                            printf("Enter quantity of coffee:\n");
                            scanf("%d",&quantity);
                            if(temp->quantity<quantity){
                                printf("Sorry. We don't have enough quantity of %s.\n",name);
                            }
                            else{
                                temp->quantity-=quantity;
                                int price=temp->price*quantity;
                                printf("%d %s(s) bill: Rs %d\n",quantity,name,price);
                                total_bill+=price;
                            }
                            break;
                        }
                        temp=temp->next;
                    }
                    if(temp==NULL){
                        printf("%s not found in menu.\n",name);
                    }
                }
                printf("Total bill: Rs%d\n",total_bill);
                break;
            }
            case 5:{
                printf("Thank you for using Cafe Billing System.\n");
                exit(0);
            }
            default:{
                printf("Invalid choice. Try again.\n");
            }
        }
    }
    return 0;
}