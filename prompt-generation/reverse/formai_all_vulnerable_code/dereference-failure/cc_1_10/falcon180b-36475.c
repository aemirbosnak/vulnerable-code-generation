//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    int n;
    int port = 21;
    char *ip = "127.0.0.1";
    int opt = 1;

    if(argc!= 3){
        printf("Usage: %s <IP> <Port>\n", argv[0]);
        return 1;
    }

    ip = argv[1];
    port = atoi(argv[2]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1){
        printf("Error creating socket\n");
        return 1;
    }

    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip);

    if(connect(sock, (struct sockaddr *)&server, sizeof(server))!= 0){
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to %s on port %d\n", inet_ntoa(server.sin_addr), ntohs(server.sin_port));

    while(1){
        printf("Enter command: ");
        fgets(command, BUFFER_SIZE, stdin);
        send(sock, command, strlen(command), 0);

        n = recv(sock, buffer, BUFFER_SIZE, 0);
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}