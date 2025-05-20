//Falcon2-11B DATASET v1.0 Category: Networking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void calculate_fibonacci(int n) {
    int i, fib_seq[n+1];
    fib_seq[0] = 0;
    fib_seq[1] = 1;
    for (i = 2; i <= n; i++) {
        fib_seq[i] = fib_seq[i-1] + fib_seq[i-2];
    }
    printf("Fibonacci sequence upto %d: ", n);
    for (i = 0; i <= n; i++) {
        printf("%d ", fib_seq[i]);
    }
    printf("\n");
}

void handle_client(int sockfd, char* ip_addr, int port) {
    int n;
    char buffer[BUFFER_SIZE];
    int n_bytes;
    socklen_t client_len;
    client_len = sizeof(struct sockaddr_in);

    while (1) {
        n_bytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (n_bytes <= 0) {
            printf("Client disconnected.\n");
            break;
        }
        if (n_bytes > 0) {
            printf("Received message from client: %s\n", buffer);
            n = atoi(buffer);
            calculate_fibonacci(n);
            send(sockfd, buffer, n_bytes, 0);
        }
    }
}

int main(int argc, char *argv[]) {
    int sockfd, client_len;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    if (listen(sockfd, 3) < 0) {
        perror("ERROR on listen");
        exit(1);
    }

    while (1) {
        client_len = sizeof(client_addr);
        sockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_len);
        if (sockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }
        printf("New connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        handle_client(sockfd, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    }

    return 0;
}