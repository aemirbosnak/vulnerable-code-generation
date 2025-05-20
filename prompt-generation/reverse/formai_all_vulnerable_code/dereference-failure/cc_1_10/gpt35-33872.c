//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[20];
    struct node* next;
};

int main() {

    struct node* head = NULL;
    struct node* tail = NULL;


    printf("Enter the devices in the network(Enter 'end' to finish):\n");
    char input[20];
    scanf("%s", input);
    while(strcmp(input, "end") != 0) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        strcpy(newNode->name, input);
        newNode->next = NULL;
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        scanf("%s", input);
    }

    printf("Enter the connections between the devices:\n");
    char connect[20];
    char* source;
    char* destination;

    while(strcmp(connect, "end") != 0) {
        scanf("%s", connect);
        if(strcmp(connect, "end") != 0) {
            source = strtok(connect, "-");
            destination = strtok(NULL, "");
            struct node* curr = head;
            struct node* srcNode = NULL;
            struct node* destNode = NULL;

            while(curr != NULL) {
                if(strcmp(curr->name, source) == 0) {
                    srcNode = curr;
                }
                if(strcmp(curr->name, destination) == 0) {
                    destNode = curr;
                }
                curr = curr->next;
            }

            if(srcNode == NULL) {
                printf("%s is not in the network.\n", source);
            }
            else if(destNode == NULL) {
                printf("%s is not in the network.\n", destination);
            }
            else {
                printf("There is a connection between %s and %s.\n", source,destination);
            }

        }
    }

    return 0;
}