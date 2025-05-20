//Gemma-7B DATASET v1.0 Category: Interprocess communication ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080

typedef struct {
    char name[255];
    int age;
    struct list_node* next;
} person_t;

typedef struct list_node {
    person_t* person;
    struct list_node* next;
} list_node_t;

list_node_t* insert_at_tail(list_node_t* head, person_t* person) {
    list_node_t* new_node = (list_node_t*)malloc(sizeof(list_node_t));
    new_node->person = person;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        head->next = new_node;
    }

    return head;
}

int main() {
    int sockfd, newsockfd;
    person_t* head = NULL;
    list_node_t* current = NULL;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(PORT));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Listen for connections
    while (1) {
        newsockfd = accept(sockfd, NULL, NULL);
        if (newsockfd < 0) {
            perror("Error accepting connection");
            continue;
        }

        // Create a new person
        person_t* new_person = (person_t*)malloc(sizeof(person_t));
        new_person->name[0] = '\0';
        new_person->age = 0;

        // Insert the new person into the list
        insert_at_tail(head, new_person);

        // Send a confirmation message
        write(newsockfd, "Connection accepted", 20);

        // Close the connection
        close(newsockfd);
    }

    return 0;
}