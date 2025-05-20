//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_REQ_LEN 1024
#define MAX_RES_LEN 1024

int main(int argc , char *argv[])
{
    if (argc < 2) {
        printf("Usage : %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    int server_sock , client_sock , c , read_size;
    struct sockaddr_in server , client;
    char client_message[MAX_REQ_LEN], server_response[MAX_RES_LEN];

    server_sock = socket(AF_INET , SOCK_STREAM , 0);
    if (server_sock == -1) {
        printf("Could not create socket");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);

    if (bind(server_sock,(struct sockaddr *)&server , sizeof(server)) < 0) {
        perror("bind failed. Error");
        return 1;
    }

    listen(server_sock , 3);

    printf("Proxy server listening on port %d...\n", port);

    while (1) {
        c = sizeof(struct sockaddr_in);

        client_sock = accept(server_sock, (struct sockaddr *)&client, (socklen_t*)&c);
        if (client_sock < 0) {
            perror("accept failed");
            return 1;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        memset(client_message, 0, MAX_REQ_LEN);
        read_size = recv(client_sock , client_message , MAX_REQ_LEN , 0);

        printf("HTTP request received:\n%s\n", client_message);

        int server_sock2 = socket(AF_INET , SOCK_STREAM , 0);
        if (server_sock2 == -1) {
            printf("Could not create socket");
            return 1;
        }

        struct sockaddr_in server2;
        server2.sin_family = AF_INET;
        server2.sin_addr.s_addr = inet_addr("127.0.0.1");
        server2.sin_port = htons(80);

        if (connect(server_sock2 , (struct sockaddr *)&server2 , sizeof(server2)) < 0) {
            perror("connection failed");
            return 1;
        }

        printf("Connected to server\n");

        if (send(server_sock2 , client_message , strlen(client_message) , 0) < 0) {
            perror("send failed");
            return 1;
        }

        printf("HTTP request forwarded to web server\n");

        memset(server_response, 0, MAX_RES_LEN);
        read_size = recv(server_sock2, server_response, MAX_RES_LEN, 0);

        printf("HTTP response received from web server:\n%s\n", server_response);

        if (send(client_sock , server_response , strlen(server_response) , 0) < 0) {
            perror("send failed");
            return 1;
        }

        printf("HTTP response forwarded to client\n");

        close(client_sock);
        close(server_sock2);
    }

    close(server_sock);
    return 0;
}