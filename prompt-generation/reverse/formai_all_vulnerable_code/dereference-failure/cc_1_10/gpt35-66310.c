//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc < 4) {
        error("Usage: ftp_client <IP address> <port number> <file name>");
    }

    char *ip_address = argv[1];
    int port = atoi(argv[2]);
    char *filename = argv[3];

    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    // connect to server
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip_address, &server_addr.sin_addr) <= 0) {
        error("Invalid IP address");
    }

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting to server");
    }

    // send file name to server
    if (write(sockfd, filename, strlen(filename)) < 0) {
        error("Error sending file name to server");
    }

    // receive file data from server
    char buffer[1024];
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        error("Error opening file");
    }
    while (1) {
        int bytes_received = read(sockfd, buffer, sizeof(buffer));
        if (bytes_received < 0) {
            error("Error receiving file data");
        } else if (bytes_received == 0) {
            break;
        }
        fwrite(buffer, 1, bytes_received, file);
    }
    fclose(file);

    // close socket
    close(sockfd);

    printf("File received successfully!\n");

    return 0;
}