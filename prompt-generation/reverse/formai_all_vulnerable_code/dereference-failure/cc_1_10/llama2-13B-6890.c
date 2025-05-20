//LLAMA2-13B DATASET v1.0 Category: Simple Web Server ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct knight {
    int sock;
    char *name;
};

void init_server(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(sock, 3);
}

void handle_request(int sock) {
    char buffer[1024];
    int client_len = recv(sock, buffer, 1024, 0);
    if (client_len < 0) {
        perror("recv");
        exit(1);
    }
    printf("Received request: %s\n", buffer);
    char *request = strtok(buffer, " ");
    char *parameter = strtok(NULL, " ");
    if (strcmp(request, "/hello") == 0) {
        char *message = "Greetings, brave knight!";
        send(sock, message, strlen(message), 0);
    } else if (strcmp(request, "/goodbye") == 0) {
        char *message = "Farewell, noble knight!";
        send(sock, message, strlen(message), 0);
    } else {
        printf("Unknown request: %s\n", request);
    }
    free(parameter);
}

int main(void) {
    init_server();
    while (1) {
        int sock = accept(0, NULL, NULL);
        handle_request(sock);
        close(sock);
    }
    return 0;
}