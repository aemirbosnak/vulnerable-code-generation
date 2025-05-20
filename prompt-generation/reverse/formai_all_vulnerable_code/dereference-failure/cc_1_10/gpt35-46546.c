//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Declaration of Linked List structures
struct medicine
{
    char name[40], brand[20], type[10];
    int quantity;
    float price;
    struct medicine *next;
};

//Function to display all the medicines in the Linked List
void displayAllMedicines(struct medicine* head)
{
    struct medicine* ptr = head;
    printf("Name\tBrand\tType\tQuantity\tPrice\n");
    while(ptr != NULL)
    {
        printf("%s\t%s\t%s\t%d\t\t%f\n", ptr->name, ptr->brand, ptr->type, ptr->quantity, ptr->price);
        ptr = ptr->next;
    }
}

//Function to add a new medicine to the Linked List
void addMedicine(struct medicine** head_ref, char name[], char brand[], char type[], int quantity, float price)
{
    struct medicine* new_medicine = (struct medicine*)malloc(sizeof(struct medicine));
    strcpy(new_medicine->name, name);
    strcpy(new_medicine->brand, brand);
    strcpy(new_medicine->type, type);
    new_medicine->quantity = quantity;
    new_medicine->price = price;
    new_medicine->next = (*head_ref);
    (*head_ref) = new_medicine;
    printf("New medicine added successfully!\n");
}

//Function to search for a medicine by name and return its position in the list
int searchByName(struct medicine* head, char name[])
{
    int pos = 0;
    struct medicine* ptr = head;
    while(ptr != NULL)
    {
        if(strcmp(ptr->name, name) == 0)
            return pos;
        pos++;
        ptr = ptr->next;
    }
    return -1;
}

//Function to delete a medicine from the Linked List based on its position
void deleteMedicine(struct medicine** head_ref, int pos)
{
    struct medicine* temp = (*head_ref);
    if(pos == 0)
    {
        (*head_ref) = temp->next;
        free(temp);
        printf("Medicine deleted successfully!\n");
        return;
    }
    for(int i=0; temp!=NULL && i<pos-1; i++)
        temp = temp->next;
    if(temp == NULL || temp->next == NULL)
    {
        printf("Error: Medicine not found!\n");
        return;
    }
    struct medicine* next = temp->next->next;
    free(temp->next);
    temp->next = next;
    printf("Medicine deleted successfully!\n");
}

//Function to update the quantity of a medicine based on name
void updateQuantity(struct medicine* head, char name[], int quantity)
{
    struct medicine* ptr = head;
    while(ptr != NULL)
    {
        if(strcmp(ptr->name, name) == 0)
        {
            ptr->quantity += quantity;
            printf("Quantity updated successfully!\n");
            return;
        }
        ptr = ptr->next;
    }
    printf("Error: Medicine not found!\n");
}

//Main function
int main()
{
    //Declaration of variables
    int option = 0, pos = 0, quantity = 0;
    float price = 0.0;
    char name[40], brand[20], type[10];

    //Initial Linked List
    struct medicine *head = NULL;

    printf("Welcome to the Medical Store Management System!\n");

    do
    {
        //Menu
        printf("\n1. Display All Medicines\n2. Add a New Medicine\n3. Delete a Medicine\n4. Update Quantity of a Medicine\n0. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                displayAllMedicines(head);
                break;
            case 2:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Brand: ");
                scanf("%s", brand);
                printf("Enter Type: ");
                scanf("%s", type);
                printf("Enter Quantity: ");
                scanf("%d", &quantity);
                printf("Enter Price: ");
                scanf("%f", &price);
                addMedicine(&head, name, brand, type, quantity, price);
                break;
            case 3:
                printf("Enter Name: ");
                scanf("%s", name);
                pos = searchByName(head, name);
                if(pos == -1)
                {
                    printf("Error: Medicine not found!\n");
                    break;
                }
                deleteMedicine(&head, pos);
                break;
            case 4:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Quantity: ");
                scanf("%d", &quantity);
                updateQuantity(head, name, quantity);
                break;
            case 0:
                printf("Thank you for using the Medical Store Management System!\n");
                break;
            default:
                printf("Invalid option! Try again.\n");
        }
    }while(option != 0);

    return 0;
}