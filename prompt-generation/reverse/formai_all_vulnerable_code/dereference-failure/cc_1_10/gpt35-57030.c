//FormAI DATASET v1.0 Category: Socket programming ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT "8080"
#define MAX_DATA_SIZE 100

int main(void) {
    int status;
    int sockfd;
    struct addrinfo hints, *res;
    struct sockaddr_storage client_addr;
    socklen_t addr_size;
    char buffer[MAX_DATA_SIZE];
    char message[] = "Hello from server!";

    // 1. Initialize hints struct
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC; // use either IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM; // TCP socket
    hints.ai_flags = AI_PASSIVE; // use local IP address

    // 2. Get address info
    if ((status = getaddrinfo(NULL, PORT, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return 1;
    }

    // 3. Create socket
    if ((sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1) {
        perror("socket error");
        return 2;
    }

    // 4. Bind socket
    if (bind(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        perror("bind error");
        return 3;
    }

    // 5. Start listening
    if (listen(sockfd, 10) == -1) {
        perror("listen error");
        return 4;
    }

    printf("Server is listening on port %s...\n", PORT);

    // 6. Accept incoming connections
    while (1) {
        addr_size = sizeof client_addr;
        int new_fd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_size);

        if (new_fd == -1) {
            perror("accept error");
            continue;
        }

        // 7. Receive data from client
        int bytes_received = recv(new_fd, buffer, MAX_DATA_SIZE, 0);

        if (bytes_received == -1) {
            perror("recv error");
            close(new_fd);
            continue;
        }

        // 8. Print received data
        buffer[bytes_received] = '\0';
        printf("Received: %s\n", buffer);

        // 9. Send response to client
        if (send(new_fd, message, strlen(message), 0) == -1) {
            perror("send error");
        }

        close(new_fd);
    }

    freeaddrinfo(res);
    close(sockfd);
    return 0;
}