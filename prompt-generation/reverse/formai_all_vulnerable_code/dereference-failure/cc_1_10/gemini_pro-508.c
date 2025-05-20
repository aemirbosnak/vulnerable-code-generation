//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CONNECTIONS 5

struct ftp_client {
    int sockfd;
    struct sockaddr_in servaddr;
};

struct ftp_client clients[MAX_CONNECTIONS];
int num_clients = 0;

void *ftp_client_thread(void *arg) {
    struct ftp_client *client = (struct ftp_client *)arg;

    // Connect to the FTP server
    if (connect(client->sockfd, (struct sockaddr *)&client->servaddr, sizeof(client->servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send the USER command
    char user_cmd[100];
    snprintf(user_cmd, sizeof(user_cmd), "USER %s\r\n", "anonymous");
    if (send(client->sockfd, user_cmd, strlen(user_cmd), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive the response from the FTP server
    char response[100];
    if (recv(client->sockfd, response, sizeof(response), 0) < 0) {
        perror("recv");
        exit(1);
    }

    // Send the PASS command
    char pass_cmd[100];
    snprintf(pass_cmd, sizeof(pass_cmd), "PASS %s\r\n", "guest");
    if (send(client->sockfd, pass_cmd, strlen(pass_cmd), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive the response from the FTP server
    if (recv(client->sockfd, response, sizeof(response), 0) < 0) {
        perror("recv");
        exit(1);
    }

    // Send the LIST command
    char list_cmd[100];
    snprintf(list_cmd, sizeof(list_cmd), "LIST\r\n");
    if (send(client->sockfd, list_cmd, strlen(list_cmd), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive the response from the FTP server
    char *list_response = malloc(1000);
    int list_response_len = 0;
    while (1) {
        int n = recv(client->sockfd, list_response + list_response_len, sizeof(response), 0);
        if (n < 0) {
            perror("recv");
            exit(1);
        } else if (n == 0) {
            break;
        }
        list_response_len += n;
    }

    // Print the list of files
    printf("%s", list_response);
    free(list_response);

    // Close the connection to the FTP server
    close(client->sockfd);

    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Fill in the server's address
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_aton(argv[1], &servaddr.sin_addr) == 0) {
        fprintf(stderr, "Invalid IP address: %s\n", argv[1]);
        exit(1);
    }

    // Create the FTP client threads
    pthread_t threads[MAX_CONNECTIONS];
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        clients[i].sockfd = sockfd;
        clients[i].servaddr = servaddr;
        pthread_create(&threads[i], NULL, ftp_client_thread, &clients[i]);
    }

    // Join the FTP client threads
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Close the socket
    close(sockfd);

    return 0;
}