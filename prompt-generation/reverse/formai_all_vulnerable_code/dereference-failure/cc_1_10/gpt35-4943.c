//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LENGTH 1024

int create_socket(const char *host, int port) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char error_buffer[MAX_LENGTH];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error opening socket: %s\n", strerror(errno));
        return -1;
    }

    // Get server information
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "Error finding host: %s\n", strerror(errno));
        return -1;
    }

    // Initialize server address structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        snprintf(error_buffer, sizeof(error_buffer), "Error connecting to server: %s", strerror(errno));
        perror(error_buffer);
        return -1;
    }

    return sockfd;
}

int receive_data(int sockfd, char *buffer, int buffer_size) {
    int num_bytes;

    num_bytes = recv(sockfd, buffer, buffer_size, 0);
    if (num_bytes < 0) {
        fprintf(stderr, "Error receiving data: %s\n", strerror(errno));
        return -1;
    }

    return num_bytes;
}

int send_data(int sockfd, char *data, int data_size) {
    int num_bytes;

    num_bytes = send(sockfd, data, data_size, 0);
    if (num_bytes < 0) {
        fprintf(stderr, "Error sending data: %s\n", strerror(errno));
        return -1;
    }

    return num_bytes;
}

int main(int argc, char *argv[]) {
    int sockfd;
    int port;
    char host[MAX_LENGTH];
    char command[MAX_LENGTH];
    char data[MAX_LENGTH];
    char buffer[MAX_LENGTH];
    char *arg;
    int num_bytes;
    bool is_connected = false;
    FILE *file;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    port = atoi(argv[1]);
    if (port <= 0 || port > 65535) {
        fprintf(stderr, "Invalid port number: %d\n", port);
        exit(EXIT_FAILURE);
    }

    puts("Welcome to the FTP client!\n");

    while (true) {
        // Get command
        fputs("ftp> ", stdout);
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        // Parse command
        arg = strtok(command, " ");
        if (arg == NULL) {
            continue;
        }

        if (strcmp(arg, "open") == 0) {
            arg = strtok(NULL, " ");
            if (arg == NULL) {
                fprintf(stderr, "Error: missing hostname.\n");
                continue;
            }
            strncpy(host, arg, sizeof(host));

            sockfd = create_socket(host, port);
            if (sockfd < 0) {
                fprintf(stderr, "Error connecting to %s.\n", host);
                is_connected = false;
            } else {
                printf("Connected to %s.\n", host);
                is_connected = true;
            }
        } else if (strcmp(arg, "close") == 0) {
            if (!is_connected) {
                puts("Not connected to server.");
                continue;
            }

            close(sockfd);
            puts("Connection closed.");
            is_connected = false;
        } else if (strcmp(arg, "put") == 0) {
            if (!is_connected) {
                puts("Not connected to server.");
                continue;
            }

            arg = strtok(NULL, " ");
            if (arg == NULL) {
                fprintf(stderr, "Error: missing local filename.\n");
                continue;
            }
            strncpy(data, arg, sizeof(data));

            arg = strtok(NULL, " ");
            if (arg == NULL) {
                fprintf(stderr, "Error: missing remote filename.\n");
                continue;
            }

            file = fopen(data, "r");
            if (file == NULL) {
                fprintf(stderr, "Error: can't open '%s' for reading.\n", data);
                continue;
            }

            snprintf(buffer, sizeof(buffer), "STOR %s\r\n", arg);
            send_data(sockfd, buffer, strlen(buffer));
            receive_data(sockfd, buffer, sizeof(buffer));
            if (strncmp(buffer, "150", 3) == 0) {
                while ((num_bytes = fread(buffer, 1, sizeof(buffer), file)) > 0) {
                    send_data(sockfd, buffer, num_bytes);
                }
                fclose(file);
                receive_data(sockfd, buffer, sizeof(buffer));
                printf("%s", buffer);
            } else {
                printf("%s", buffer);
                fclose(file);
            }
        } else if (strcmp(arg, "quit") == 0) {
            if (is_connected) {
                close(sockfd);
            }
            break;
        } else {
            puts("Invalid command.");
        }
    }

    puts("Goodbye!");
    return 0;
}