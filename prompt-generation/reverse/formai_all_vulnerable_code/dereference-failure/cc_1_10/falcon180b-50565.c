//Falcon-180B DATASET v1.0 Category: Firewall ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_LINE 1024
#define PORT "8080"
#define IP "127.0.0.1"

void log_packet(char *packet) {
    FILE *logfile = fopen("firewall.log", "a");
    if (logfile!= NULL) {
        fprintf(logfile, "%s\n", packet);
        fclose(logfile);
    }
}

void handle_client(int client_socket) {
    char buffer[MAX_LINE];
    while (1) {
        memset(buffer, 0, MAX_LINE);
        int bytes_received = recv(client_socket, buffer, MAX_LINE, 0);
        if (bytes_received <= 0) {
            break;
        }
        log_packet(buffer);
        send(client_socket, buffer, strlen(buffer), 0);
    }
    close(client_socket);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(errno);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(PORT));
    server_addr.sin_addr.s_addr = inet_addr(IP);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(errno);
    }

    if (listen(server_socket, 5) == -1) {
        perror("listen");
        exit(errno);
    }

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket!= -1) {
            printf("Client connected\n");
            pid_t pid = fork();
            if (pid == -1) {
                perror("fork");
            } else if (pid > 0) {
                close(client_socket);
            } else {
                handle_client(client_socket);
                exit(0);
            }
        }
    }

    return 0;
}