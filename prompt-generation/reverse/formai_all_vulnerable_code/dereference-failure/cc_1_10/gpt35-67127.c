//FormAI DATASET v1.0 Category: Browser Plugin ; Style: lively
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// Define a struct to represent a link in the linked list
typedef struct node {
    char* url;
    struct node* next;
} node_t;

// Declare the linked list head
node_t* head = NULL;

// Function to add a new URL to the linked list
void add_url(char* url) {
    // Allocate memory for the new link
    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    
    // Initialize the new link
    new_node->url = url;
    new_node->next = NULL;

    if (head == NULL) {
        // If the linked list is empty, set the head to the new link
        head = new_node;
    } else {
        // Otherwise, find the end of the linked list and add the new link there
        node_t* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to remove a URL from the linked list
void remove_url(char* url) {
    // Check if the linked list is empty
    if (head == NULL) {
        return;
    }

    // Check if the first link matches the URL to be removed
    if (head->url == url) {
        node_t* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    // Otherwise, iterate through the linked list to find the link to be removed
    node_t* current = head;
    while (current->next != NULL) {
        if (current->next->url == url) {
            node_t* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;
        }
        current = current->next;
    }
}

// Function to check if a URL is in the linked list
bool url_exists(char* url) {
    node_t* current = head;
    while (current != NULL) {
        if (current->url == url) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Plugin initialization function
void init_plugin() {
    // Add some initial URLs to the linked list
    add_url("https://www.google.com");
    add_url("https://www.facebook.com");
    add_url("https://www.twitter.com");
}

// Plugin cleanup function
void cleanup_plugin() {
    // Remove all URLs from the linked list
    while (head != NULL) {
        node_t* temp = head;
        head = head->next;
        free(temp);
    }
}

// Plugin function to handle a new URL
void handle_url(char* url) {
    if (url_exists(url)) {
        printf("URL already exists in the linked list!\n");
    } else {
        printf("Adding new URL to the linked list...\n");
        add_url(url);
    }
}

// Plugin function to handle a removed URL
void handle_removed_url(char* url) {
    if (url_exists(url)) {
        printf("Removing URL from the linked list...\n");
        remove_url(url);
    } else {
        printf("URL not found in the linked list!\n");
    }
}

// Main function (not used in the plugin)
int main() {
    // Initialize the plugin
    init_plugin();
    
    // Handle some URLs
    handle_url("https://www.google.com");
    handle_url("https://www.amazon.com");
    handle_url("https://www.facebook.com");
    handle_removed_url("https://www.amazon.com");
    handle_removed_url("https://www.twitter.com");

    // Cleanup the plugin
    cleanup_plugin();
    return 0;
}