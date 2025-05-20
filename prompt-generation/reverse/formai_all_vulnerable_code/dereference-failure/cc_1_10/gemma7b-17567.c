//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define MAX_SIZE 10

struct bucket {
    int *arr;
    int size;
    struct bucket *next;
};

void insert(struct bucket **head, int data) {
    struct bucket *new_bucket = malloc(sizeof(struct bucket));
    new_bucket->arr = malloc(MAX_SIZE * sizeof(int));
    new_bucket->size = 0;
    new_bucket->next = NULL;

    if (*head == NULL) {
        *head = new_bucket;
    } else {
        (*head)->next = new_bucket;
        *head = new_bucket;
    }

    new_bucket->arr[new_bucket->size++] = data;
}

int main() {
    int sockfd, newsockfd, port = 8080, i, j, data, size = 0;
    struct bucket *head = NULL;
    char buffer[1024];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

    // Listen for connections
    newsockfd = accept(sockfd, NULL, NULL);

    // Receive data
    recv(newsockfd, buffer, 1024, 0);

    // Convert data to an integer
    data = atoi(buffer);

    // Insert data into the bucket list
    insert(&head, data);

    // Send confirmation
    send(newsockfd, "Data received", 15, 0);

    // Close connections
    close(newsockfd);
    close(sockfd);

    // Print the bucket list
    for (i = 0; i < head->size; i++) {
        printf("%d ", head->arr[i]);
    }

    return 0;
}