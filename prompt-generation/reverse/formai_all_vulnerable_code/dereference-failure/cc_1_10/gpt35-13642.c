//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define USERNAME "guest"
#define PASSWORD "cyberpunkftw"

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    struct hostent *host;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int sock_fd, bytes_received, bytes_sent, port;
    char command[BUFFER_SIZE], filename[BUFFER_SIZE];
    FILE *fp;
    char *username = USERNAME;
    char *password = PASSWORD;

    if (argc != 3) {
        printf("Usage: ftpclient <hostname> <port>\n");
        exit(1);
    }

    host = gethostbyname(argv[1]);
    port = atoi(argv[2]);

    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        error("Error creating socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr*) host->h_addr);
    memset(&(server_addr.sin_zero), '\0', 8);

    if (connect(sock_fd, (struct sockaddr*) &server_addr, sizeof(struct sockaddr)) == -1) {
        error("Error connecting to server");
    }

    bytes_received = recv(sock_fd, buffer, BUFFER_SIZE, 0);

    if (bytes_received == -1) {
        error("Error receiving welcome message from server");
    }

    printf("%s\n", buffer);

    bytes_sent = sprintf(buffer, "USER %s\r\n", username);
    send(sock_fd, buffer, bytes_sent, 0);

    bytes_received = recv(sock_fd, buffer, BUFFER_SIZE, 0);

    if (bytes_received == -1) {
        error("Error receiving response from server");
    }

    printf("%s\n", buffer);

    bytes_sent = sprintf(buffer, "PASS %s\r\n", password);
    send(sock_fd, buffer, bytes_sent, 0);

    bytes_received = recv(sock_fd, buffer, BUFFER_SIZE, 0);

    if (bytes_received == -1) {
        error("Error receiving response from server");
    }

    printf("%s\n", buffer);

    while(1) {
        printf("Enter FTP command (GET <filename>, QUIT): ");
        fgets(command, BUFFER_SIZE, stdin);

        if (strncmp(command, "QUIT", 4) == 0) {
            bytes_sent = sprintf(buffer, "QUIT\r\n");
            send(sock_fd, buffer, bytes_sent, 0);
            bytes_received = recv(sock_fd, buffer, BUFFER_SIZE, 0);
            printf("%s\n", buffer);
            break;
        } else if (strncmp(command, "GET", 3) == 0) {
            sscanf(command, "GET %s\n", filename);
            bytes_sent = sprintf(buffer, "RETR %s\r\n", filename);
            send(sock_fd, buffer, bytes_sent, 0);
            bytes_received = recv(sock_fd, buffer, BUFFER_SIZE, 0);

            if (bytes_received == -1) {
                error("Error receiving response from server");
            }

            if (strncmp(buffer, "550", 3) == 0) {
                printf("File not found\n");
            } else {
                fp = fopen(filename, "wb");

                if (!fp) {
                    printf("Error opening file\n");
                } else {
                    printf("Downloading file...\n");
                    while(1) {
                        bytes_received = recv(sock_fd, buffer, BUFFER_SIZE, 0);
                        if (bytes_received == 0) {
                            break;
                        } else if (bytes_received == -1) {
                            error("Error receiving file from server");
                        }

                        fwrite(buffer, sizeof(char), bytes_received, fp);
                    }
                    fclose(fp);
                    printf("File downloaded\n");
                }
            }
        } else {
            printf("Invalid command\n");
        }
    }

    close(sock_fd);

    return 0;
}