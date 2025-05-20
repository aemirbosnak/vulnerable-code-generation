//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 2048

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <port> <destination_address>\n", argv[0]);
        exit(1);
    }
    int port = atoi(argv[1]);
    char *dest_address = argv[2];
    int sockfd, client_fds[MAX_CLIENTS];
    struct sockaddr_in serv_addr, client_addr;
    fd_set read_fds;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
    listen(sockfd, MAX_CLIENTS);
    printf("Proxy server started on port %d\n", port);

    int max_fd = sockfd;
    int client_count = 0;
    int i;
    char buffer[BUFFER_SIZE];

    while (1) {
        FD_ZERO(&read_fds);
        FD_SET(sockfd, &read_fds);
        for (i = 0; i < client_count; i++) {
            FD_SET(client_fds[i], &read_fds);
        }
        if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) < 0) {
            perror("ERROR in select");
            exit(1);
        }
        if (FD_ISSET(sockfd, &read_fds)) {
            int client_len = sizeof(client_addr);
            int client_fd = accept(sockfd, (struct sockaddr *) &client_addr, &client_len);
            if (client_fd < 0) {
                perror("ERROR on accept");
                continue;
            }
            printf("Accepted connection from %s:%d\n", 
                inet_ntoa(client_addr.sin_addr),
                ntohs(client_addr.sin_port));
            if (client_count == MAX_CLIENTS) {
                printf("Too many clients, closing connection\n");
                close(client_fd);
            } else {
                client_fds[client_count++] = client_fd;
                if (client_fd > max_fd) {
                    max_fd = client_fd;
                }
            }
        }
        for (i = 0; i < client_count; i++) {
            if (FD_ISSET(client_fds[i], &read_fds)) {
                int bytes_read = read(client_fds[i], buffer, BUFFER_SIZE);
                if (bytes_read <= 0) {
                    printf("Connection closed by client\n");
                    close(client_fds[i]);
                    if (i != client_count - 1) {
                        client_fds[i] = client_fds[client_count - 1];
                    }
                    client_count--;
                } else {
                    buffer[bytes_read] = '\0';
                    printf("Received %d bytes from %d\n", bytes_read, client_fds[i]);
                    printf("Data: %s\n", buffer);
                    int dest_fd = socket(AF_INET, SOCK_STREAM, 0);
                    if (dest_fd < 0) {
                        perror("ERROR opening socket");
                        exit(1);
                    }
                    struct hostent *dest_host = gethostbyname(dest_address);
                    if (dest_host == NULL) {
                        perror("ERROR, no such host");
                        exit(1);
                    }
                    struct sockaddr_in dest_addr;
                    memset(&dest_addr, 0, sizeof(dest_addr));
                    dest_addr.sin_family = AF_INET;
                    dest_addr.sin_port = htons(80);
                    memcpy(&dest_addr.sin_addr.s_addr, dest_host->h_addr, dest_host->h_length);
                    if (connect(dest_fd, (struct sockaddr *) &dest_addr, sizeof(dest_addr)) < 0) {
                        perror("ERROR connecting");
                        exit(1);
                    }
                    printf("Connected to %s:%d\n", dest_address, 80);
                    if (write(dest_fd, buffer, strlen(buffer)) < 0) {
                        perror("ERROR writing to destination");
                        exit(1);
                    }
                    printf("Sent %d bytes to %s:%d\n", bytes_read, dest_address, 80);
                    char response[BUFFER_SIZE];
                    int bytes_received = read(dest_fd, response, BUFFER_SIZE);
                    if (bytes_received < 0) {
                        perror("ERROR reading from destination");
                        exit(1);
                    }
                    printf("Received %d bytes from %s:%d\n", bytes_received, dest_address, 80);
                    printf("Response: %s\n", response);
                    if (write(client_fds[i], response, bytes_received) < 0) {
                        perror("ERROR writing to client");
                        exit(1);
                    }
                    printf("Sent %d bytes to client\n", bytes_received);
                    close(dest_fd);
                }
            }
        }
    }
    return 0;
}