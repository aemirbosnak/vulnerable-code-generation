//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

void read_buffer(int sockfd, char* buffer, int size) {
    int bytes_received = 0;
    while (bytes_received < size) {
        int bytes_read = read(sockfd, buffer + bytes_received, size - bytes_received);
        bytes_received += bytes_read;
    }
}

void send_cmd(int sockfd, char* cmd) {
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "%s\r\n", cmd);
    write(sockfd, buffer, strlen(buffer));
}

void receive_cmd(int sockfd, char* response) {
    read_buffer(sockfd, response, BUFFER_SIZE);
    response[BUFFER_SIZE - 1] = '\0';
}

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        exit(1);
    }

    struct hostent* server_info = gethostbyname(argv[1]);
    if (server_info == NULL) {
        printf("Error: could not resolve server %s\n", argv[1]);
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server_info->h_addr, server_info->h_length);
    server_addr.sin_port = htons(POP3_PORT);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: could not create socket\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error: could not connect to server\n");
        exit(1);
    }

    printf("Connected to server %s\n", argv[1]);

    char buffer[BUFFER_SIZE];

    receive_cmd(sockfd, buffer);
    printf("%s", buffer);

    send_cmd(sockfd, "USER");
    receive_cmd(sockfd, buffer);
    printf("%s", buffer);

    send_cmd(sockfd, argv[2]);
    receive_cmd(sockfd, buffer);
    printf("%s", buffer);

    send_cmd(sockfd, "PASS");
    receive_cmd(sockfd, buffer);
    printf("%s", buffer);

    send_cmd(sockfd, argv[3]);
    receive_cmd(sockfd, buffer);
    printf("%s", buffer);

    send_cmd(sockfd, "STAT");
    receive_cmd(sockfd, buffer);
    printf("%s", buffer);

    close(sockfd);

    return 0;
}