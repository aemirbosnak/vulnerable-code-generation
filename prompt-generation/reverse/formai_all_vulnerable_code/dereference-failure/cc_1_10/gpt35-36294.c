//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: lively
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFF_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error("Cannot create socket");
    }

    char* server_address = argv[1];
    int server_port = atoi(argv[2]);

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_address);
    server.sin_port = htons(server_port);

    int connect_return = connect(sock, (struct sockaddr*) &server, sizeof(server));
    if (connect_return < 0) {
        error("Cannot connect to server");
    }

    printf("FTP client connected to server at %s:%d\n", server_address, server_port);

    char buffer[BUFF_SIZE];
    memset(buffer, 0, BUFF_SIZE);

    printf("Enter filename to upload:\n");
    fgets(buffer, BUFF_SIZE-1, stdin);
    char* filename = strtok(buffer, "\n");

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        error("Cannot open file");
    }

    printf("Uploading file %s...\n", filename);

    int n;
    while ((n = fread(buffer, 1, BUFF_SIZE, file)) > 0) {
        if (send(sock, buffer, n, 0) < 0) {
            error("Failed to send file");
        }
        memset(buffer, 0, BUFF_SIZE);
    }

    fclose(file);
    close(sock);

    printf("File upload complete\n");

    return 0;
}