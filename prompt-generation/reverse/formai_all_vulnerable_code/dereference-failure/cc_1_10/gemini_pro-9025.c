//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *email;
    struct node *next;
} node_t;

typedef struct mailing_list {
    node_t *head;
    node_t *tail;
    int size;
} mailing_list_t;

mailing_list_t *create_mailing_list() {
    mailing_list_t *list = malloc(sizeof(mailing_list_t));
    if (list == NULL) {
        return NULL;
    }
    
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    
    return list;
}

void destroy_mailing_list(mailing_list_t *list) {
    node_t *current = list->head;
    
    while (current != NULL) {
        node_t *next = current->next;
        free(current->email);
        free(current);
        current = next;
    }
    
    free(list);
}

int add_email_to_list(mailing_list_t *list, char *email) {
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return -1;
    }
    
    new_node->email = strdup(email);
    if (new_node->email == NULL) {
        free(new_node);
        return -1;
    }
    
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    
    list->size++;
    
    return 0;
}

int remove_email_from_list(mailing_list_t *list, char *email) {
    node_t *current = list->head;
    node_t *previous = NULL;
    
    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous == NULL) {
                list->head = current->next;
            } else {
                previous->next = current->next;
            }
            
            if (current == list->tail) {
                list->tail = previous;
            }
            
            free(current->email);
            free(current);
            list->size--;
            
            return 0;
        }
        
        previous = current;
        current = current->next;
    }
    
    return -1;
}

void print_mailing_list(mailing_list_t *list) {
    node_t *current = list->head;
    
    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

int main() {
    mailing_list_t *list = create_mailing_list();
    
    add_email_to_list(list, "user@example.com");
    add_email_to_list(list, "admin@example.com");
    add_email_to_list(list, "moderator@example.com");
    
    print_mailing_list(list);
    
    remove_email_from_list(list, "admin@example.com");
    
    print_mailing_list(list);
    
    destroy_mailing_list(list);
    
    return 0;
}