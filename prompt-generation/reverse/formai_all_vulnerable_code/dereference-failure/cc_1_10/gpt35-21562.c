//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine{
    int code, quantity;
    char name[50], manufacturer[50];
    float price;
};

void add_medicine(struct medicine *med, int num_of_medicines){
    int i;
    for(i=0;i<num_of_medicines;i++){
        printf("\nEnter Details for Medicine %d : \n", i+1);
        printf("Medicine Code : ");
        scanf("%d",&(med+i)->code);
        printf("Medicine Name : ");
        scanf("%s",(med+i)->name);
        printf("Medicine Manufacturer : ");
        scanf("%s",(med+i)->manufacturer);
        printf("Medicine Price : ");
        scanf("%f",&(med+i)->price);
        printf("Quantity Available : ");
        scanf("%d",&(med+i)->quantity);
    }
}

void display_medicines(struct medicine *med, int num_of_medicines){
    int i;
    printf("\t\t--------------------------------------\n");
    printf("\t\t|| Medicine Code | Name | Manufacturer | Price | Quantity ||\n");
    printf("\t\t--------------------------------------\n");
    for(i=0;i<num_of_medicines;i++){
        printf("\t\t|| %-13d", (med+i)->code);
        printf("| %-15s", (med+i)->name);
        printf("| %-14s", (med+i)->manufacturer);
        printf("| %-6.2f", (med+i)->price);
        printf("| %-8d||\n", (med+i)->quantity);
    }
    printf("\t\t--------------------------------------\n");
}

void search_medicine(struct medicine *med, int num_of_medicines){
    int code, i;
    printf("Enter the medicine code : ");
    scanf("%d",&code);
    for(i=0;i<num_of_medicines;i++){
        if((med+i)->code==code){
            printf("\nDetails of Medicine with code %d : \n", code);
            printf("Medicine Name : %s\n", (med+i)->name);
            printf("Medicine Manufacturer : %s\n", (med+i)->manufacturer);
            printf("Medicine Price : %.2f\n", (med+i)->price);
            printf("Quantity Available : %d\n", (med+i)->quantity);
            return;
        }
    }
    printf("Medicine with code %d not found!\n", code);
}

void sell_medicine(struct medicine *med, int num_of_medicines){
    int code, i, qty;
    printf("Enter the medicine code : ");
    scanf("%d",&code);
    for(i=0;i<num_of_medicines;i++){
        if((med+i)->code==code){
            printf("Enter quantity to sell : ");
            scanf("%d",&qty);
            if(qty<=0 || qty>(med+i)->quantity){
                printf("\nInvalid Quantity!\n");
            }
            else{
                (med+i)->quantity-=(qty);
                printf("\nTotal Amount : %.2f\nThank You For Shopping!\n", qty*(med+i)->price);
            }
            return;
        }
    }
    printf("Medicine with code %d not found!\n", code);
}

int main(){
    int num_of_medicines;
    printf("Enter number of Medicines to add : ");
    scanf("%d",&num_of_medicines);
    struct medicine *med = (struct medicine*) malloc(num_of_medicines*sizeof(struct medicine));
    add_medicine(med, num_of_medicines);

    int option;
    while(1){
        printf("\n\t\t***** MEDICAL STORE MANAGEMENT *****\n\n");
        printf("\t\t1. Display Medicines\n");
        printf("\t\t2. Search Medicine\n");
        printf("\t\t3. Sell Medicine\n");
        printf("\t\t4. Exit\n");
        printf("\n\t\tEnter your option : ");
        scanf("%d",&option);

        switch(option){
            case 1: display_medicines(med, num_of_medicines);
                    break;
            case 2: search_medicine(med, num_of_medicines);
                    break;
            case 3: sell_medicine(med, num_of_medicines);
                    break;
            case 4: exit(0);
            default: printf("\nInvalid Option!\n");
        }
    }
    free(med);
    return 0;
}