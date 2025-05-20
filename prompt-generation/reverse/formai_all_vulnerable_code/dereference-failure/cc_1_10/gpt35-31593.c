//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<fcntl.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    int sock_desc;
    struct sockaddr_in server_addr;
    char buffer[MAX_SIZE], command[MAX_SIZE];
    unsigned int port;
    char *server_ip, *username, *password;

    if (argc != 5) {
        printf("Usage : %s <server ip> <port> <username> <password>\n", argv[0]);
        exit(-1);
    }

    server_ip = argv[1];
    port = atoi(argv[2]);
    username = argv[3];
    password = argv[4];

    if ((sock_desc = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Failed to create socket\n");
        exit(-1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) < 0) {
        printf("Invalid server IP address\n");
        exit(-1);
    }

    if (connect(sock_desc, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to connect to server\n");
        exit(-1);
    }

    /* Login to FTP server */
    sprintf(command, "USER %s\r\n", username);
    send(sock_desc, command, strlen(command), 0);
    recv(sock_desc, buffer, MAX_SIZE, 0);

    sprintf(command, "PASS %s\r\n", password);
    send(sock_desc, command, strlen(command), 0);
    recv(sock_desc, buffer, MAX_SIZE, 0);

    printf("Login successful\n");

    /* List files in FTP server */
    sprintf(command, "LIST\r\n");
    send(sock_desc, command, strlen(command), 0);

    while (recv(sock_desc, buffer, MAX_SIZE, 0) > 0) {
        printf("%s", buffer);
    }

    /* Download a file from FTP server */
    sprintf(command, "RETR file.txt\r\n");
    send(sock_desc, command, strlen(command), 0);

    int fd = open("file.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);

    while (recv(sock_desc, buffer, MAX_SIZE, 0) > 0) {
        write(fd, buffer, strlen(buffer));
    }

    printf("File downloaded successfully\n");

    close(sock_desc);
    return 0;
}