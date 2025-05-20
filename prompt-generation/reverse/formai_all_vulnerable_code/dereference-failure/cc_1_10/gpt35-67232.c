//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char medicine_name[20];
    int quantity;
    float price;
} medicine;

void update_stock(medicine *med, int n)
{
    int choice, qty;
    printf("Please select the medicine to update quantity: \n");
    for(int i=0;i<n;i++)
    {
        printf("%d. %s\n", i+1, med[i].medicine_name);
    }
    scanf("%d", &choice);
    printf("Enter the new quantity: ");
    scanf("%d", &qty);
    med[choice-1].quantity = qty;
    printf("Stock updated successfully!\n");
}

void display_medicine(medicine med)
{
    printf("%s\t\t%d\t\t%.2f\n", med.medicine_name, med.quantity, med.price);    
}

void display_stock(medicine *med, int n)
{
    printf("Medicine\tQuantity\tPrice\n");
    for(int i=0;i<n;i++)
    {
        display_medicine(med[i]);
    }
}

void search_stock(medicine *med, int n)
{
    char search_name[20];
    printf("Enter medicine name to search: ");
    scanf("%s",search_name);
    int flag = 0;
    for(int i=0;i<n;i++)
    {
        if(strcmp(med[i].medicine_name, search_name)==0)
        {
            flag = 1;
            display_medicine(med[i]);
        }
    }
    if(flag == 0)
    {
        printf("No match found\n");
    }
}

void add_stock(medicine *med, int n)
{
    med = realloc(med, sizeof(medicine) * (n+1));
    printf("Enter medicine name, quantity and price: ");
    scanf("%s %d %f",(med+n)->medicine_name, &(med+n)->quantity, &(med+n)->price);
    printf("New stock added successfully!\n");
}

int main()
{
    int choice, n = 5;
    medicine *med = malloc(sizeof(medicine) * n);
    strcpy(med[0].medicine_name, "Paracetamol");
    med[0].quantity = 50;
    med[0].price = 2.50;
    strcpy(med[1].medicine_name, "Ibuprofen");
    med[1].quantity = 25;
    med[1].price = 3.75;
    strcpy(med[2].medicine_name, "Aspirin");
    med[2].quantity = 40;
    med[2].price = 2.00;
    strcpy(med[3].medicine_name, "Penicillin");
    med[3].quantity = 10;
    med[3].price = 5.00;
    strcpy(med[4].medicine_name, "Amoxicillin");
    med[4].quantity = 20;
    med[4].price = 7.50;

    printf("Welcome to the Medical Store Management System\n");
    printf("==============================================\n");

    while(1)
    {
        printf("\n");
        printf("1. Display current stock\n");
        printf("2. Update stock\n");
        printf("3. Search stock\n");
        printf("4. Add new stock\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            display_stock(med, n);
            break;
        case 2:
            update_stock(med, n);
            break;
        case 3:
            search_stock(med, n);
            break;
        case 4:
            add_stock(med, n++);
            break;
        case 5:
            printf("Thank you for using the Medical Store Management System\n");
            exit(0);
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
        }
    }
    return 0;
}