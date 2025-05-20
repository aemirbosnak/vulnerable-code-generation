//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char* ssid;
    int strength;
    struct Node* next;
};

// Function to insert a new node at the beginning of the list
void insert(struct Node** head, char* ssid, int strength) {
    // Allocate memory for new node
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->ssid = malloc(strlen(ssid) + 1);

    // Copy the values for new node
    strcpy(new_node->ssid, ssid);
    new_node -> strength = strength;

    // Set next of new node as head
    new_node->next = (*head);

    // Move head to point to new node
    (*head) = new_node;
}

// Function to print the list
void printList(struct Node* head) {
    struct Node* temp = head;
    printf("SSID\tSignal Strength\n");
    while(temp != NULL) {
        printf("%s\t%d dBm\n", temp->ssid, temp->strength);
        temp = temp->next;
    }
}

// Function to search for a specific SSID and return its strength
int find(struct Node* head, char* ssid) {
    struct Node* temp = head;

    // Traverse the list until we find the SSID
    while(temp != NULL) {
        if(strcmp(temp->ssid, ssid) == 0) {
            return temp->strength;
        }
        temp = temp->next;
    }
    // If we reach here, SSID was not found
    return -1;
}

// Function to delete a specific SSID from the list
void delete(struct Node** head, char* ssid) {
    // If list is empty, exit
    if((*head) == NULL) {
        return;
    } 

    // If head node contains the SSID
    if(strcmp((*head)->ssid, ssid) == 0) {
        struct Node* temp = (*head);
        (*head) = (*head) -> next;
        free(temp);
        return;
    }

    struct Node* temp = (*head)->next;
    struct Node* prev = (*head);

    // Traverse the list until we find the SSID
    while(temp != NULL) {
        if(strcmp(temp->ssid, ssid) == 0) {
            prev->next = temp->next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

int main() {
    // Initialize an empty list
    struct Node* head = NULL;

    // Insert initial SSIDs and strengths to the list
    insert(&head, "My WiFi", -45);
    insert(&head, "Neighbour's WiFi", -60);
    insert(&head, "Coffee Shop WiFi", -70);

    // Print the list
    printList(head);

    // Search for a specific SSID and print its strength
    int strength = find(head, "My WiFi");
    if(strength != -1) {
        printf("\n%s signal strength: %d dBm\n", "My WiFi", strength);
    } else {
        printf("\n%s not found in the list.\n", "My WiFi");
    }

    // Delete a specific SSID from the list and print the updated list
    delete(&head, "Coffee Shop WiFi");
    printf("\nList after deleting \"Coffee Shop WiFi\":\n");
    printList(head);

    // Free the memory allocated for the list
    while(head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp->ssid);
        free(temp);
    }

    return 0;
}