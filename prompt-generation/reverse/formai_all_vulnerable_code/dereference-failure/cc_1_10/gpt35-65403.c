//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define MAXSIZE 1024

int main(int argc, char *argv[]) {
    char *ip = argv[1];
    char *file = argv[2];
    char *username = "anonymous";
    char *password = "user@ftp.com";
    int port = 21;

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Failed to connect");
        exit(EXIT_FAILURE);
    }

    char buffer[MAXSIZE];
    bzero(buffer, MAXSIZE);

    // Read response from server
    read(sock, buffer, sizeof buffer);
    printf("%s", buffer);

    // Send username
    char *reply = "USER ";
    strcat(reply, username);
    strcat(reply, "\r\n");
    send(sock, reply, strlen(reply), 0);
    bzero(buffer, MAXSIZE);

    // Read response from server
    read(sock, buffer, sizeof buffer);
    printf("%s", buffer);

    // Send password
    reply = "PASS ";
    strcat(reply, password);
    strcat(reply, "\r\n");
    send(sock, reply, strlen(reply), 0);
    bzero(buffer, MAXSIZE);

    // Read response from server
    read(sock, buffer, sizeof buffer);
    printf("%s", buffer);

    // Set to binary mode
    reply = "TYPE I\r\n";
    send(sock, reply, strlen(reply), 0);
    bzero(buffer, MAXSIZE);

    // Read response from server
    read(sock, buffer, sizeof buffer);
    printf("%s", buffer);

    // Enter passive mode
    reply = "PASV\r\n";
    send(sock, reply, strlen(reply), 0);
    bzero(buffer, MAXSIZE);

    // Read response from server
    read(sock, buffer, sizeof buffer);
    printf("%s", buffer);

    // Parse passive response
    char *token;
    int data_port = 0;
    token = strtok(buffer, ",");
    for (int i = 0; i < 3; i++) {
        token = strtok(NULL, ",");
    }
    data_port = atoi(token) << 8;
    token = strtok(NULL, ",");
    data_port += atoi(token);
    printf("Data Port: %d\n", data_port);

    // Connect to data port
    struct sockaddr_in data_server;
    data_server.sin_addr.s_addr = inet_addr(ip);
    data_server.sin_family = AF_INET;
    data_server.sin_port = htons(data_port);

    int data_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(data_sock, (struct sockaddr *)&data_server, sizeof(data_server)) < 0) {
        printf("Failed to connect");
        exit(EXIT_FAILURE);
    }

    // Send retrieve command
    reply = "RETR ";
    strcat(reply, file);
    strcat(reply, "\r\n");
    send(sock, reply, strlen(reply), 0);
    bzero(buffer, MAXSIZE);

    // Read response from server
    read(sock, buffer, sizeof buffer);
    printf("%s", buffer);

    // Read data from server
    FILE *fp;
    fp = fopen(file, "w");
    int n = 0;
    while ((n = recv(data_sock, buffer, MAXSIZE, 0)) > 0) {
        fwrite(buffer, sizeof(char), n, fp);
    }

    fclose(fp);
    close(sock);
    close(data_sock);

    printf("File received successfully\n");
    return 0;
}