//FormAI DATASET v1.0 Category: Product Inventory System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product
{
    int product_id;
    char product_name[100];
    int quantity;
    float price;
};

struct node
{
    struct product pro;
    struct node *next;
};

struct node *head = NULL;

void add_product()
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter Product ID: ");
    scanf("%d", &temp->pro.product_id);
    printf("Enter Product Name: ");
    scanf("%s", &temp->pro.product_name);
    printf("Enter Quantity: ");
    scanf("%d", &temp->pro.quantity);
    printf("Enter Price: ");
    scanf("%f", &temp->pro.price);
    temp->next = NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        struct node *p;
        p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
    }
    printf("\nProduct added successfully.\n\n");
}

void display_all_products()
{
    struct node *p;
    p=head;
    if(p==NULL)
    {
        printf("\nNo products to display!\n");
    }
    else
    {
        printf("\nProduct ID\tProduct Name\t\tQuantity\tPrice\n");
        while(p!=NULL)
        {
            printf("%-15d%-25s%-15d%-10.2f\n", p->pro.product_id, p->pro.product_name, p->pro.quantity, p->pro.price);
            p=p->next;
        }
    }
    printf("\n");
}

void search_product_by_id()
{
    int product_id;
    printf("Enter Product ID: ");
    scanf("%d", &product_id);
    struct node *p, *temp;
    p=head;
    while(p!=NULL)
    {
        if(p->pro.product_id==product_id)
        {
            printf("\nProduct ID\tProduct Name\t\tQuantity\tPrice\n");
            printf("%-15d%-25s%-15d%-10.2f\n\n", p->pro.product_id, p->pro.product_name, p->pro.quantity, p->pro.price);
            temp=p;
            break;
        }
        else
        {
            p=p->next;
        }
    }
    if(p==NULL)
    {
        printf("\nProduct not found!\n\n");
    }
}

void update_product_by_id()
{
    int product_id;
    printf("Enter Product ID: ");
    scanf("%d", &product_id);
    struct node *p, *temp;
    p=head;
    while(p!=NULL)
    {
        if(p->pro.product_id==product_id)
        {
            printf("\nProduct ID\tProduct Name\t\tQuantity\tPrice\n");
            printf("%-15d%-25s%-15d%-10.2f\n\n", p->pro.product_id, p->pro.product_name, p->pro.quantity, p->pro.price);
            printf("Enter Product Name: ");
            scanf("%s", &p->pro.product_name);
            printf("Enter Quantity: ");
            scanf("%d", &p->pro.quantity);
            printf("Enter Price: ");
            scanf("%f", &p->pro.price);
            temp=p;
            break;
        }
        else
        {
            p=p->next;
        }
    }
    if(p==NULL)
    {
        printf("\nProduct not found!\n\n");
    }
    else
    {
        printf("\nProduct details updated successfully.\n\n");
    }
}

void delete_product_by_id()
{
    int product_id;
    printf("Enter Product ID: ");
    scanf("%d", &product_id);
    struct node *p, *temp;
    p=head;
    if(p!=NULL && p->pro.product_id==product_id)
    {
        head=p->next;
        free(p);
        printf("\nProduct deleted successfully.\n\n");
    }
    else if(p!=NULL)
    {
        while(p->next!=NULL)
        {
            if(p->next->pro.product_id==product_id)
            {
                temp=p->next;
                p->next=temp->next;
                free(temp);
                printf("\nProduct deleted successfully.\n\n");
                break;
            }
            else
            {
                p=p->next;
            }
        }
        if(p->next==NULL)
        {
            printf("\nProduct not found!\n\n");
        }
    }
    else
    {
        printf("\nProduct not found!\n\n");
    }
}

int main()
{
    int choice;
    printf("***Product Inventory System***\n\n");
    while(1)
    {
        printf("1. Add product\n");
        printf("2. Display all products\n");
        printf("3. Search product by ID\n");
        printf("4. Update product by ID\n");
        printf("5. Delete product by ID\n");
        printf("6. Exit\n\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: add_product();
                    break;
            case 2: display_all_products();
                    break;
            case 3: search_product_by_id();
                    break;
            case 4: update_product_by_id();
                    break;
            case 5: delete_product_by_id();
                    break;
            case 6: printf("\nThank you for using Product Inventory System!\n");
                    exit(0);
                    break;
            default: printf("\nInvalid choice! Please enter a valid choice.\n\n");
                     break;
        }
    }
    return 0;
}