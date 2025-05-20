//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to establish a connection with the server
int connect_to_server(char* server_ip, int port) {
    struct sockaddr_in server_addr;
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_fd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    if (connect(sock_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server at %s:%d\n", server_ip, port);
    return sock_fd;
}

// Function to send a command to the server
void send_command(int sock_fd, char* cmd) {
    char buff[1024];
    sprintf(buff, "%s\r\n", cmd);

    if (send(sock_fd, buff, strlen(buff), 0) < 0) {
        perror("Command failed to send");
        exit(EXIT_FAILURE);
    }
}

// Function to receive data from the server
void recv_data(int sock_fd) {
    char buff[1024];
    int recv_len;

    while ((recv_len = recv(sock_fd, buff, sizeof(buff), 0)) > 0) {
        fwrite(buff, 1, recv_len, stdout);
    }

    if (recv_len < 0) {
        perror("Error receiving data");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <server-ip> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sock_fd = connect_to_server(argv[1], atoi(argv[2]));
    int logged_in = 0;
    char buff[1024];

    // Prompt user for username and password
    printf("Enter username: ");
    fgets(buff, sizeof(buff), stdin);
    strtok(buff, "\n");
    send_command(sock_fd, buff);

    printf("Enter password: ");
    fgets(buff, sizeof(buff), stdin);
    strtok(buff, "\n");
    send_command(sock_fd, buff);

    // Receive response from server
    recv_data(sock_fd);

    while (1) {
        printf("FTP> ");

        if (fgets(buff, sizeof(buff), stdin) == NULL) {
            break;
        }

        strtok(buff, "\n");

        if (strcmp(buff, "quit") == 0) {
            break;
        }

        send_command(sock_fd, buff);
        recv_data(sock_fd);
    }

    printf("Closing connection ...\n");
    close(sock_fd);
    return 0;
}