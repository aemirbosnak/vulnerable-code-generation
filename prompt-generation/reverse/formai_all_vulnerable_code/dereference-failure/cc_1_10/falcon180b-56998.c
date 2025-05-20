//Falcon-180B DATASET v1.0 Category: Email Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define MAX_SIZE 1024

typedef struct {
    char username[50];
    char password[50];
    char server_address[100];
    int server_port;
} Config;

void load_config(Config* config) {
    FILE* file = fopen("config.txt", "r");
    if (file == NULL) {
        printf("Error: Failed to open config file.\n");
        exit(1);
    }

    fscanf(file, "%s %s %s %d", config->username, config->password, config->server_address, &config->server_port);

    fclose(file);
}

int main() {
    Config config;
    load_config(&config);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Failed to create socket.\n");
        exit(1);
    }

    struct hostent* server = gethostbyname(config.server_address);
    if (server == NULL) {
        printf("Error: Failed to resolve server address.\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(config.server_port);
    server_addr.sin_addr = *(struct in_addr*)server->h_addr;

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Failed to connect to server.\n");
        exit(1);
    }

    char username[50];
    char password[50];

    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    send(sock, username, strlen(username), 0);
    send(sock, password, strlen(password), 0);

    char buffer[MAX_SIZE];
    while (1) {
        memset(buffer, 0, MAX_SIZE);
        int bytes_received = recv(sock, buffer, MAX_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error: Disconnected from server.\n");
            exit(1);
        }

        char* message = strtok(buffer, "\r\n");
        while (message!= NULL) {
            printf("%s", message);
            message = strtok(NULL, "\r\n");
        }
    }

    return 0;
}