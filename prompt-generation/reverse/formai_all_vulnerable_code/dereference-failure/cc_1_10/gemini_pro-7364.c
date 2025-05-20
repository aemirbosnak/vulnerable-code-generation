//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct TEQueue {
    char *data;
    int front, rear, size;
};

struct TEQueue *TEQ_Create(int size) {
    struct TEQueue *queue = malloc(sizeof(struct TEQueue));
    queue->data = malloc(sizeof(char) * size);
    queue->front = queue->rear = -1;
    queue->size = size;
    return queue;
}

void TEQ_Enqueue(struct TEQueue *queue, char data) {
    if (queue->rear == queue->size - 1)
        printf("\nTEQueue is Full!!!");
    else {
        if (queue->front == -1)
            queue->front = queue->rear = 0;
        else
            queue->rear++;
        queue->data[queue->rear] = data;
    }
}

char TEQ_Dequeue(struct TEQueue *queue) {
    char data;
    if (queue->front == -1)
        printf("\nTEQueue is Empty!!!");
    else {
        data = queue->data[queue->front];
        queue->front++;
        if (queue->front > queue->rear)
            queue->front = queue->rear = -1;
    }
    return data;
}

int TEQ_IsEmpty(struct TEQueue *queue) {
    return (queue->front == -1);
}

int main() {
    int sockfd, newsockfd, len;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[1024];
    struct TEQueue *queue = TEQ_Create(1024);

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Filling server information
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Binding the socket with the server address
    if ((bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen
    if ((listen(sockfd, 5)) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept the data packet from client and enqueue it
    len = sizeof(cliaddr);
    while ((newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len)) >= 0) {
        int n;
        while ((n = read(newsockfd, buffer, sizeof(buffer))) > 0) {
            for (int i = 0; i < n; i++) {
                TEQ_Enqueue(queue, buffer[i]);
            }
        }

        // Dequeue from the queue and send it back to the client
        while (!TEQ_IsEmpty(queue)) {
            char data = TEQ_Dequeue(queue);
            send(newsockfd, &data, sizeof(data), 0);
        }

        // Close the socket
        close(newsockfd);
    }

    // Closing the socket
    close(sockfd);
    return 0;
}