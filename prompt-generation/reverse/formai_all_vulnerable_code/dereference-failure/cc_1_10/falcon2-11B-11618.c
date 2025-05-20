//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_MESSAGE_SIZE 100
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define PORT "5000"

typedef struct {
    char message[MAX_MESSAGE_SIZE];
    int sender;
} Message;

Message messages[MAX_CLIENTS];

pthread_mutex_t message_mutex = PTHREAD_MUTEX_INITIALIZER;

void *send_message(void *arg) {
    int sockfd, i, j, bytes_read;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    sockfd = *(int *)arg;
    while (1) {
        printf("Send Message: ");
        fgets(messages[sockfd].message, MAX_MESSAGE_SIZE, stdin);

        pthread_mutex_lock(&message_mutex);
        messages[sockfd].sender = sockfd;
        pthread_mutex_unlock(&message_mutex);

        printf("Sending message to all clients...\n");
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (i!= sockfd) {
                printf("Sending message to client %d...\n", i);
                j = 0;
                bytes_read = send(sockfd, messages[i].message, MAX_MESSAGE_SIZE, 0);
                if (bytes_read < 0) {
                    perror("Send failed");
                    break;
                } else {
                    printf("Message sent successfully\n");
                }
            }
        }
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    int server_fd, portno, newsockfd, n, pid;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    pthread_t send_thread;

    if (argc < 2) {
        fprintf(stderr, "Usage %s port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(server_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Bind failed");
        exit(1);
    }

    listen(server_fd, 5);

    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(server_fd, (struct sockaddr *) &cli_addr, &clilen);

        if (newsockfd < 0) {
            perror("Accept failed");
            continue;
        }

        pid = fork();

        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        } else if (pid == 0) {
            // Child process
            close(newsockfd);
            printf("New client connected\n");

            pthread_create(&send_thread, NULL, send_message, (void *)newsockfd);
            pthread_detach(send_thread);

            close(server_fd);
            exit(0);
        } else {
            // Parent process
            close(newsockfd);
        }
    }

    return 0;
}