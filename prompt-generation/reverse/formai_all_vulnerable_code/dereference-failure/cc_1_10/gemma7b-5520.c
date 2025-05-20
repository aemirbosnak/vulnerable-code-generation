//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

// Define the Banking Record System structure
typedef struct BankingRecordSystem
{
    char name[50];
    int account_number;
    double balance;
    struct BankingRecordSystem* next;
} BankingRecordSystem;

// Function to insert a new banking record system node
BankingRecordSystem* insert_node(BankingRecordSystem* head, char* name, int account_number, double balance)
{
    BankingRecordSystem* new_node = (BankingRecordSystem*)malloc(sizeof(BankingRecordSystem));
    strcpy(new_node->name, name);
    new_node->account_number = account_number;
    new_node->balance = balance;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        head->next = new_node;
    }

    return head;
}

// Function to search for a banking record system node
BankingRecordSystem* search_node(BankingRecordSystem* head, int account_number)
{
    BankingRecordSystem* current_node = head;

    while (current_node)
    {
        if (current_node->account_number == account_number)
        {
            return current_node;
        }
        current_node = current_node->next;
    }

    return NULL;
}

// Function to update a banking record system node
void update_node(BankingRecordSystem* node, char* name, int account_number, double balance)
{
    strcpy(node->name, name);
    node->account_number = account_number;
    node->balance = balance;
}

// Main function
int main()
{
    BankingRecordSystem* head = NULL;

    // Insert some nodes
    insert_node(head, "John Doe", 12345, 1000);
    insert_node(head, "Jane Doe", 67890, 2000);
    insert_node(head, "Bob Smith", 32154, 3000);

    // Search for a node
    BankingRecordSystem* node = search_node(head, 12345);

    // Update the node
    update_node(node, "John Doe", 12345, 1500);

    // Print the updated node
    printf("Name: %s\n", node->name);
    printf("Account Number: %d\n", node->account_number);
    printf("Balance: %f\n", node->balance);

    return 0;
}