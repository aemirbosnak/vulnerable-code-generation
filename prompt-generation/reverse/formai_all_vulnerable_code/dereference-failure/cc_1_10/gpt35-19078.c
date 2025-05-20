//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_URL_LENGTH 100

typedef struct node {
    char url[MAX_URL_LENGTH];
    bool is_up;
    struct node* next;
} Node;

Node* head = NULL;
int num_urls = 0;

bool check_url(char* url) {
    // Implement your own URL checking function here
    return true;
}

void add_url(char* url) {
    if (num_urls == 0) {
        head = malloc(sizeof(Node));
        strcpy(head->url, url);
        head->is_up = true;
        head->next = NULL;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            if (strcmp(current->url, url) == 0) {
                // URL already in list, stop adding
                return;
            }
            current = current->next;
        }
        Node* new_node = malloc(sizeof(Node));
        strcpy(new_node->url, url);
        new_node->is_up = true;
        new_node->next = NULL;
        current->next = new_node;
    }
    num_urls++;
}

void check_urls() {
    Node* current = head;
    while (current != NULL) {
        if (!check_url(current->url)) {
            current->is_up = false;
        }
        current = current->next;
    }
}

void print_status() {
    Node* current = head;
    while (current != NULL) {
        printf("%s: %s\n", current->url, current->is_up ? "Up" : "Down");
        current = current->next;
    }
}

int main() {
    add_url("https://www.google.com");
    add_url("https://www.facebook.com");
    add_url("https://www.apple.com");
    add_url("https://www.microsoft.com");
    add_url("https://www.amazon.com");
    
    printf("Checking website status...\n\n");
    check_urls();
    print_status();
    
    return 0;
}