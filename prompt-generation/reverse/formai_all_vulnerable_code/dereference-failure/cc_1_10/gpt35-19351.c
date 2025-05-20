//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define PORT 8000
#define BUF_SIZE 4096

char* generate_data() {
    char *data = malloc(BUF_SIZE);
    int i, j;
    for (i = 0; i < BUF_SIZE-1; i++) {
        j = i % 10;
        data[i] = (char)(48 + j);
    }
    data[BUF_SIZE-1] = 0;
    return data;
}

void client() {
    int sockfd;
    char *data;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect with server");
        exit(EXIT_FAILURE);
    }

    data = generate_data();
    printf("\nSending data of size %d to server...\n", BUF_SIZE);
    send(sockfd, data, BUF_SIZE, 0);
    free(data);

    close(sockfd);
}

void server() {
    int sockfd, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    char buf[BUF_SIZE];
    int recv_size;
    clock_t start_time, end_time;
    double time_used;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind to socket");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);

    printf("\nServer is running and waiting for incoming connection...\n");
    client_sock = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sock < 0) {
        perror("Failed to accept client connection");
        exit(EXIT_FAILURE);
    }

    printf("\nClient connected with IP address: %s\n", inet_ntoa(client_addr.sin_addr));

    memset(buf, 0, BUF_SIZE);
    start_time = clock();
    recv_size = recv(client_sock, buf, BUF_SIZE, 0);
    end_time = clock();
    time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    if (recv_size > 0) {
        printf("\nReceived data of size %d from client in %f seconds\n", recv_size, time_used);
        printf("\nSpeed: %.2f Mbps\n", recv_size*8/(time_used*1024*1024));
    } else {
        printf("\nFailed to receive data from client\n");
    }

    close(client_sock);
    close(sockfd);
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <server/client>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "server") == 0) {
        server();
    } else if (strcmp(argv[1], "client") == 0) {
        client();
    } else {
        printf("Usage: %s <server/client>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    return 0;
}