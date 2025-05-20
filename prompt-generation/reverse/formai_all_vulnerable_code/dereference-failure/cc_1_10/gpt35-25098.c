//FormAI DATASET v1.0 Category: Database simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define the structures for database

struct employee{
    char name[50];
    int age;
    int id;
};

struct customers{
    char name[50];
    char email[50];
    int phone;
    int id;
};

//define the structure for the linked list

struct linkedList{
    void *data;
    struct linkedList *next;
};

//define the functions for the linked list operations

void displayEmployee(void *data){
    struct employee *emp = (struct employee*)data;
    printf("Name: %s\nAge: %d\nID: %d\n\n", emp->name, emp->age, emp->id);
}

void displayCustomer(void *data){
    struct customers *cust = (struct customers*)data;
    printf("Name: %s\nEmail: %s\nPhone: %d\nID: %d\n\n", cust->name, cust->email, cust->phone, cust->id);
}

struct linkedList* addNode(void *data, struct linkedList *head){
    struct linkedList *newNode = malloc(sizeof(struct linkedList));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

void traverseList(struct linkedList *head, void (*f)(void*)){
    while(head != NULL){
        (*f)(head->data);
        head = head->next;
    }
}

void freeList(struct linkedList *head){
    while(head != NULL){
        struct linkedList *temp = head;
        head = head->next;
        free(temp->data);
        free(temp);
    }
}

int main(){
    //initialize the linked lists for employees and customers
    struct linkedList *employees = NULL;
    struct linkedList *customers = NULL;

    //add employees to the linked list
    struct employee emp1 = {"John Smith", 30, 12345};
    struct employee emp2 = {"Jane Doe", 25, 23456};
    struct employee emp3 = {"Bob Johnson", 40, 34567};
    struct employee emp4 = {"Sarah Williams", 28, 45678};
    struct employee emp5 = {"Mike Brown", 35, 56789};

    employees = addNode(&emp1, employees);
    employees = addNode(&emp2, employees);
    employees = addNode(&emp3, employees);
    employees = addNode(&emp4, employees);
    employees = addNode(&emp5, employees);

    //add customers to the linked list
    struct customers cust1 = {"Tom Jones", "tjones@gmail.com", 1234567890, 111};
    struct customers cust2 = {"Mary Johnson", "mjohnson@gmail.com", 2345678901, 222};
    struct customers cust3 = {"Joe Smith", "jsmith@gmail.com", 3456789012, 333};
    struct customers cust4 = {"Sue Davis", "sdavis@gmail.com", 4567890123, 444};
    struct customers cust5 = {"Dan Taylor", "dtaylor@gmail.com", 5678901234, 555};

    customers = addNode(&cust1, customers);
    customers = addNode(&cust2, customers);
    customers = addNode(&cust3, customers);
    customers = addNode(&cust4, customers);
    customers = addNode(&cust5, customers);

    //display the lists
    printf("List of Employees:\n");
    traverseList(employees, displayEmployee);

    printf("List of Customers:\n");
    traverseList(customers, displayCustomer);

    //free memory
    freeList(employees);
    freeList(customers);

    return 0;
}