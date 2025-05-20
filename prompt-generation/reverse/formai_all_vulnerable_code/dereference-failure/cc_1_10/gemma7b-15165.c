//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_CUSTOMERS 50

typedef struct Product
{
    char name[50];
    int quantity;
    double price;
    struct Product* next;
} Product;

typedef struct Customer
{
    char name[50];
    int customer_id;
    struct Customer* next;
} Customer;

Product* InsertProduct(Product* head, char* name, int quantity, double price)
{
    Product* newNode = (Product*)malloc(sizeof(Product));
    strcpy(newNode->name, name);
    newNode->quantity = quantity;
    newNode->price = price;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        head->next = newNode;
    }

    return head;
}

Customer* InsertCustomer(Customer* head, char* name, int customer_id)
{
    Customer* newNode = (Customer*)malloc(sizeof(Customer));
    strcpy(newNode->name, name);
    newNode->customer_id = customer_id;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        head->next = newNode;
    }

    return head;
}

void DisplayProducts(Product* head)
{
    while (head)
    {
        printf("%s - %d - %.2lf\n", head->name, head->quantity, head->price);
        head = head->next;
    }
}

void DisplayCustomers(Customer* head)
{
    while (head)
    {
        printf("%s - %d\n", head->name, head->customer_id);
        head = head->next;
    }
}

int main()
{
    Product* productHead = NULL;
    Customer* customerHead = NULL;

    InsertProduct(productHead, "Paracetamol", 10, 2.0);
    InsertProduct(productHead, "Ibuprofen", 5, 3.0);
    InsertProduct(productHead, "Tylenol", 7, 4.0);

    InsertCustomer(customerHead, "John Doe", 1);
    InsertCustomer(customerHead, "Jane Doe", 2);

    DisplayProducts(productHead);
    DisplayCustomers(customerHead);

    return 0;
}