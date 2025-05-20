//FormAI DATASET v1.0 Category: Firewall ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LEN 200

/* Define a linked-list node to store blocked URLs */
typedef struct url_node {
    char url[MAX_URL_LEN];
    struct url_node *next;
} url_node;

/* Add a new URL to the list of blocked URLs */
void add_url(url_node **url_list, char *new_url) {
    url_node *new_node = (url_node*) malloc(sizeof(url_node));
  
    strcpy(new_node->url, new_url);
    new_node->next = (*url_list);
    (*url_list) = new_node;
}

/* Check if a URL needs to be blocked based on the list of blocked URLs */
int is_blocked(url_node *url_list, char *url) {
    while (url_list != NULL) {
        if (strstr(url, url_list->url) != NULL) {
            return 1;
        }
        url_list = url_list->next;
    }
    return 0;
}

/* Main function */
int main(void) {
    url_node *blocked_list = NULL;
    char target_url[MAX_URL_LEN];
    
    // Add some sample URLs to the blocked list
    add_url(&blocked_list, "facebook.com");
    add_url(&blocked_list, "twitter.com");
    add_url(&blocked_list, "instagram.com");

    // Read input URLs and check if they need to be blocked
    while (1) {
        printf("Enter URL to access (enter 'exit' to quit): ");
        scanf("%s", target_url);

        if (strcmp(target_url, "exit") == 0) {
            break;
        }
        else if (is_blocked(blocked_list, target_url)) {
            printf("Access to %s has been blocked!\n", target_url);
        }
        else {
            printf("Accessing %s\n", target_url);
        }
    }
    return 0;
}