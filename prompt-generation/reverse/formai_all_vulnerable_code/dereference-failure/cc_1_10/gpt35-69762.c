//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define DEFAULT_PORT 8080

struct Node {
    int id;
    int priority;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Connection {
    int socket;
    char* ipAddr;
};

void initializeQueue(struct Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

void addToQueue(struct Queue* q, int id, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->id = id;
    newNode->priority = priority;
    newNode->next = NULL;

    if(q->front == NULL) {
        q->front = newNode;
        q->rear = newNode;
        return;
    }

    if(newNode->priority > q->front->priority) {
        newNode->next = q->front;
        q->front = newNode;
        return;
    }

    struct Node* temp = q->front;
    while(temp->next != NULL && temp->next->priority > newNode->priority) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    if(newNode->next == NULL) {
        q->rear = newNode;
    }
}

struct Node* removeFromQueue(struct Queue* q) {
    if(q->front == NULL) {
        return NULL;
    }

    struct Node* temp = q->front;
    q->front = q->front->next;
    if(q->front == NULL) {
        q->rear = NULL;
    }
    return temp;
}

void printQueue(struct Queue* q) {
    struct Node* temp = q->front;
    while(temp != NULL) {
        printf("%d[%d] ", temp->id, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

void startServer(int port) {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    char buffer[BUFFER_SIZE];

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSocket < 0) {
        perror("Error while creating socket");
        exit(-1);
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(port);

    if(bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error while binding socket");
        exit(-1);
    }

    if(listen(serverSocket, 5) < 0) {
        perror("Error while listening to socket");
        exit(-1);
    }

    printf("Server started at port %d\n", port);

    int clientCount = 0;
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    initializeQueue(queue);

    while(1) {
        clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);
        if(clientSocket < 0) {
            perror("Error while accepting socket");
            exit(-1);
        }
        printf("New client connected from %s:%d\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
        addToQueue(queue, clientCount++, rand() % 10);
        printQueue(queue);
        close(clientSocket);
    }
}

void startClient(char* ipAddr, int port) {
    int clientSocket, serverResponse;
    struct Connection* connection = (struct Connection*)malloc(sizeof(struct Connection));
    struct sockaddr_in serverAddr;
    char buffer[BUFFER_SIZE];

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(clientSocket < 0) {
        perror("Error while creating socket");
        exit(-1);
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(ipAddr);
    serverAddr.sin_port = htons(port);

    if(connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error while connecting to server");
        exit(-1);
    }

    printf("Connected to server %s:%d\n", ipAddr, port);
    close(clientSocket);
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Usage:\n\t%s <server|client> [ipAddr] [port]\n", argv[0]);
        exit(-1);
    }

    if(strcmp(argv[1], "server") == 0) {
        startServer((argc > 2) ? atoi(argv[2]) : DEFAULT_PORT);
    } else if(strcmp(argv[1], "client") == 0) {
        if(argc < 4) {
            printf("Usage:\n\t%s client <ipAddr> <port>\n", argv[0]);
            exit(-1);
        }
        startClient(argv[2], atoi(argv[3]));
    } else {
        printf("Invalid mode %s. Modes: server, client.\n", argv[1]);
        exit(-1);
    }

    return 0;
}