//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX 100
#define PORT 8080
#define BACKLOG 10
#define TRUE 1
#define FALSE 0
#define DELAY 1000

int sockfd, newsockfd, client_socket[MAX], val;
struct sockaddr_in serv_addr, cli_addr;
char buffer[1024];
int addrlen;

void *thread_fun(void *arg) {
    int client_socket = *(int *) arg;
    char response[1024];
    sprintf(response, "Light status: %d\n", val);
    send(client_socket, response, strlen(response), 0);
    close(client_socket);
    return NULL;
}

int main(int argc, char *argv[]) {
    int opt = 1, res = 0, sd, new_sd;
    char *message = "Smart home light control system started.\n";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *) &opt, sizeof(opt));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, BACKLOG) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Smart home light control system started.\n");

    while (TRUE) {
        memset(&cli_addr, 0, sizeof(cli_addr));
        addrlen = sizeof(cli_addr);
        sd = accept(sockfd, (struct sockaddr *) &cli_addr, &addrlen);

        printf("New connection\n");

        pthread_t thread_id;
        int rc = pthread_create(&thread_id, NULL, thread_fun, (void *) sd);

        if (rc) {
            printf("Error: unable to start thread, %d\n", rc);
            exit(-1);
        }

        close(sd);
    }

    return 0;
}