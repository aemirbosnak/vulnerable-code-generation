//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAX_DATA_SIZE 1024
#define SERVER_PORT 8080

typedef struct {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[MAX_DATA_SIZE];
} client_t;

void error_handling(const char* message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        error_handling("socket failed");
    }

    return sockfd;
}

void close_socket(int sockfd) {
    close(sockfd);
}

int connect_to_server(const char* ip, int port) {
    struct hostent* server = gethostbyname(ip);

    if (server == NULL) {
        error_handling("gethostbyname failed");
    }

    client_t client = {0};
    client.sockfd = create_socket();

    if (connect(client.sockfd, (struct sockaddr*)&(server->h_addr), sizeof(server->h_length)) == -1) {
        error_handling("connect failed");
    }

    client.server_addr.sin_family = AF_INET;
    client.server_addr.sin_port = htons(port);
    client.server_addr.sin_addr.s_addr = *(unsigned long*)server->h_addr;

    return client.sockfd;
}

int send_data(int sockfd, const char* data) {
    return send(sockfd, data, strlen(data), 0);
}

int receive_data(int sockfd, char* buffer) {
    return recv(sockfd, buffer, MAX_DATA_SIZE, 0);
}

int main() {
    int sockfd = connect_to_server("localhost", SERVER_PORT);

    if (sockfd == -1) {
        return 1;
    }

    char buffer[MAX_DATA_SIZE] = {0};

    while (1) {
        int bytes_received = receive_data(sockfd, buffer);

        if (bytes_received <= 0) {
            error_handling("receive_data failed");
        }

        printf("Received from server: %s\n", buffer);
    }

    close_socket(sockfd);
    return 0;
}