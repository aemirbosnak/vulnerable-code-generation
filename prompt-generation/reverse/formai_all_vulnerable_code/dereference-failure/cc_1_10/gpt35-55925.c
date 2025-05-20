//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define FTP_PORT 21

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [hostname] [username] [password]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Establish connection to server
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[1024];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(FTP_PORT);
    connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

    // Login to FTP server
    printf("Connected to FTP server %s\n", argv[1]);
    recv(sockfd, buffer, 1024, 0);
    printf("%s", buffer);
    sprintf(buffer, "USER %s\r\n", argv[2]);
    send(sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, 1024, 0);
    printf("%s", buffer);
    sprintf(buffer, "PASS %s\r\n", argv[3]);
    send(sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, 1024, 0);
    printf("%s", buffer);

    // Change to binary mode
    sprintf(buffer, "TYPE I\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, 1024, 0);
    printf("%s", buffer);

    // Enter passive mode
    sprintf(buffer, "PASV\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, 1024, 0);
    printf("%s", buffer);
    char* ip_address, *token;
    int port_number;
    strtok(buffer, "(");
    token = strtok(NULL, ")");
    ip_address = strtok(token, ",");
    for (int i = 0; i < 3; i++) {
        ip_address = strtok(NULL, ",");
    }
    port_number = atoi(strtok(NULL, ","));
    port_number = port_number * 256 + atoi(strtok(NULL, ","));
    struct sockaddr_in data_servaddr;
    int data_sockfd;
    data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&data_servaddr, 0, sizeof(data_servaddr));
    data_servaddr.sin_family = AF_INET;
    data_servaddr.sin_addr.s_addr = inet_addr(ip_address);
    data_servaddr.sin_port = htons(port_number);
    connect(data_sockfd, (struct sockaddr*)&data_servaddr, sizeof(data_servaddr));

    // Request file from server
    sprintf(buffer, "RETR %s\r\n", "example_file.txt");
    send(sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, 1024, 0);
    printf("%s", buffer);

    FILE* file = fopen("example_file.txt", "wb");
    while (recv(data_sockfd, buffer, 1024, 0)) {
        fwrite(buffer, 1, sizeof(buffer), file);
        memset(buffer, 0, sizeof(buffer));
    }

    // Close data connection and file
    fclose(file);
    close(data_sockfd);

    // Quit FTP session
    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, 1024, 0);
    printf("%s", buffer);

    close(sockfd);
    return 0;
}