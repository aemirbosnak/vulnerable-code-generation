//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 21

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char *username = "anonymous";
    char *password = "";

    if (argc!= 3)
    {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    char *cmd = "USER ";
    send(sock, cmd, strlen(cmd), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);

    cmd = "PASS ";
    send(sock, cmd, strlen(cmd), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);

    cmd = "STAT ";
    send(sock, cmd, strlen(cmd), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);

    cmd = "LIST ";
    send(sock, cmd, strlen(cmd), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);

    printf("Listing directory:\n%s", buffer);

    cmd = "RETR ";
    send(sock, cmd, strlen(cmd), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);

    printf("Downloading file: %s\n", buffer);

    FILE *fp;
    fp = fopen("download.txt", "wb");

    if (fp == NULL)
    {
        printf("Error creating file\n");
        exit(1);
    }

    char data[BUFFER_SIZE];
    int bytes;

    while ((bytes = recv(sock, data, BUFFER_SIZE, 0)) > 0)
    {
        fwrite(data, bytes, 1, fp);
    }

    fclose(fp);

    close(sock);

    printf("File downloaded successfully\n");

    return 0;
}