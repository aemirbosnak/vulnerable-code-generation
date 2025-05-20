//Falcon-180B DATASET v1.0 Category: Firewall ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <pthread.h>

#define BUF_SIZE 1024
#define MAX_CLIENTS 10
#define WHITE_LIST "192.168.1.100"

int whitelist_check(char* ip) {
    if(strcmp(ip, WHITE_LIST) == 0) {
        return 1;
    }
    return 0;
}

void* handle_client(void* arg) {
    int client_socket = *(int*)arg;
    char buffer[BUF_SIZE];

    while(1) {
        bzero(buffer, BUF_SIZE);
        int bytes_received = recv(client_socket, buffer, BUF_SIZE, 0);

        if(bytes_received <= 0) {
            break;
        }

        char* ip = inet_ntoa(((struct sockaddr_in*)&(client_socket))->sin_addr);
        if(!whitelist_check(ip)) {
            send(client_socket, "Access Denied\r\n", 14, 0);
            break;
        }

        send(client_socket, buffer, bytes_received, 0);
    }

    close(client_socket);
    pthread_exit(0);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_socket, MAX_CLIENTS);

    printf("Firewall started on port 8080\n");

    while(1) {
        struct sockaddr_in client_addr;
        socklen_t client_size = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_size);

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void*)&client_socket);
    }

    return 0;
}