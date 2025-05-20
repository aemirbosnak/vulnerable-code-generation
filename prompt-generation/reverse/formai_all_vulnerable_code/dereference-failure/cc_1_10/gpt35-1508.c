//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    int x, y, distance;
    char direction;
    struct Node *next;
};

void insert(struct Node** head_ref, int x, int y, int distance, char direction) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->x = x;
    new_node->y = y;
    new_node->distance = distance;
    new_node->direction = direction;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node *node) {
    while (node != NULL) {
        printf("(%d, %d) distance %d %c \n", node->x, node->y, node->distance, node->direction);
        node = node->next;
    }
}

int main() {
    
    struct Node *head = NULL;

    insert(&head, 0, 0, 0, 'S');
    insert(&head, 10, 0, 10, 'E');
    insert(&head, 10, 10, 20, 'N');
    insert(&head, 0, 10, 30, 'W');
    
    printf("Navigating GPS Simulation:\n");
    printf("Directions:\n");
    printList(head);
    printf("\n");

    int current_x = 0, current_y = 0, total_distance = 0;
    
    struct Node *temp = head;
    while(temp != NULL) {
        if(temp->x > current_x) {
            total_distance += temp->x - current_x;
            current_x = temp->x;
        }
        else if(temp->x < current_x) {
            total_distance += current_x - temp->x;
            current_x = temp->x;
        }
        
        if(temp->y > current_y) {
            total_distance += temp->y - current_y;
            current_y = temp->y;
        }
        else if(temp->y < current_y) {
            total_distance += current_y - temp->y;
            current_y = temp->y;
        }
        temp = temp->next;
    }

    printf("Total Distance traveled: %d\n", total_distance);
    
    return 0;
}