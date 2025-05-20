//MISTRAL-7B DATASET v1.0 Category: Building a FTP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 21
#define BUFFER_SIZE 1024
#define MAX_NAME_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    int sock;
} client_t;

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int connect_to_server(const char *ip) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        die("socket failed");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, ip, &server_addr.sin_addr) <= 0) {
        die("invalid address/ Address not supported");
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("connection failed");
    }

    return sock;
}

client_t *create_new_client(const char *name) {
    client_t *client = malloc(sizeof(client_t));
    strcpy(client->name, name);
    client->sock = -1;
    return client;
}

void print_welcome_message() {
    printf("--------Welcome to Ada's FTP Client--------\n");
    printf("I, Ada Lovelace, the world's first computer programmer,\n");
    printf("invite you to enjoy my humble FTP client.\n");
}

void print_help_message() {
    printf(" Commands:\n");
    printf("  'ls'      List files in the remote directory.\n");
    printf("  'get <filename>' Download a file from the server.\n");
    printf("  'put <filename>' Upload a file to the server.\n");
    printf("  'mkdir <directory_name>' Create a new directory on the server.\n");
    printf("  'quit'      Disconnect from the server and exit the client.\n");
}

void process_command(client_t *client, int sock) {
    char command[MAX_NAME_LEN];
    char response[BUFFER_SIZE];

    printf("%s: > ", client->name);
    fgets(command, MAX_NAME_LEN, stdin);
    command[strcspn(command, "\n")] = '\0';

    if (strcmp(command, "quit") == 0) {
        close(client->sock);
        free(client);
        exit(0);
    }

    write(sock, command, strlen(command) + 1);

    int bytes_received = recv(sock, response, BUFFER_SIZE, 0);
    if (bytes_received > 0) {
        response[bytes_received] = '\0';
        printf("%s\n", response);
    }
}

int main() {
    print_welcome_message();
    print_help_message();

    char ip[MAX_NAME_LEN];
    printf("Enter the server IP address: ");
    scanf("%s", ip);

    int sock = connect_to_server(ip);
    client_t *client = create_new_client("Ada's Client");

    while (1) {
        process_command(client, sock);
    }

    return 0;
}