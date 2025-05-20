//Falcon-180B DATASET v1.0 Category: Firewall ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 2048
#define MAX_CLIENTS 10
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"
#define WHITELIST_FILE "whitelist.txt"

char whitelist[MAX_CLIENTS][100];
int num_clients = 0;

void read_whitelist() {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen(WHITELIST_FILE, "r");
    if(fp == NULL) {
        printf("Error opening whitelist file\n");
        exit(1);
    }

    while(fgets(line, 100, fp)!= NULL) {
        strcpy(whitelist[i], line);
        i++;
    }

    fclose(fp);
}

int is_whitelisted(char *ip) {
    int i;

    for(i = 0; i < num_clients; i++) {
        if(strcmp(ip, whitelist[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    char *ip;
    struct sockaddr_in client_addr;
    socklen_t client_len;

    client_len = sizeof(client_addr);
    getsockname(client_socket, (struct sockaddr *)&client_addr, &client_len);
    inet_ntop(AF_INET, &client_addr.sin_addr, ip, sizeof(ip));

    if(is_whitelisted(ip)) {
        send(client_socket, "Welcome to the server!\n", strlen("Welcome to the server!\n"), 0);
    } else {
        send(client_socket, "Access denied.\n", strlen("Access denied.\n"), 0);
        close(client_socket);
    }
}

int main() {
    int server_socket, client_socket, opt = 1;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;

    read_whitelist();

    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    if(setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("Error setting socket option\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

    if(bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    if(listen(server_socket, MAX_CLIENTS) < 0) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while(1) {
        client_len = sizeof(client_addr);
        if((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            printf("Error accepting connection\n");
            exit(1);
        }

        handle_client(client_socket);
    }

    return 0;
}