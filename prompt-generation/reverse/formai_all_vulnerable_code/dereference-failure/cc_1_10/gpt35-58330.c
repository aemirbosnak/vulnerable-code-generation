//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

typedef struct {
    char *username;
    char *password;
} Credentials;

typedef struct {
    char **headers;
    char *body;
} Response;

int connect_to_server(char *ip_address, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        fprintf(stderr, "Error opening socket.\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);
    server_addr.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error connecting to server.\n");
        exit(EXIT_FAILURE);
    }

    return sock;
}

int send_command(int sock, char *command) {
    if (send(sock, command, strlen(command), 0) < 0) {
        fprintf(stderr, "Error sending command to server.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

char *read_response(int sock) {
    char *response = malloc(MAX_BUFFER_SIZE * sizeof(char));
    bzero(response, MAX_BUFFER_SIZE);

    if (recv(sock, response, MAX_BUFFER_SIZE, 0) < 0) {
        fprintf(stderr, "Error receiving response from server.\n");
        exit(EXIT_FAILURE);
    }

    return response;
}

Credentials get_credentials() {
    char *username = malloc(MAX_BUFFER_SIZE * sizeof(char));
    char *password = malloc(MAX_BUFFER_SIZE * sizeof(char));

    printf("Enter username: ");
    fgets(username, MAX_BUFFER_SIZE, stdin);

    printf("Enter password: ");
    fgets(password, MAX_BUFFER_SIZE, stdin);

    // Strip newline characters
    username[strcspn(username, "\n")] = 0;
    password[strcspn(password, "\n")] = 0;

    Credentials credentials = { username, password };

    return credentials;
}

Response send_login_command(int sock, Credentials credentials) {
    char *command = malloc(MAX_BUFFER_SIZE);
    bzero(command, MAX_BUFFER_SIZE);

    // Construct command string
    sprintf(command, "USER %s\r\n", credentials.username);
    send_command(sock, command);

    sprintf(command, "PASS %s\r\n", credentials.password);
    send_command(sock, command);

    // Read response
    char *response = read_response(sock);

    // Parse response
    Response parsed_response;
    parsed_response.headers = malloc(2 * sizeof(char *));
    parsed_response.headers[0] = strtok(response, "\r\n");
    parsed_response.headers[1] = strtok(NULL, "\r\n");

    return parsed_response;
}

Response send_stat_command(int sock) {
    // Send STAT command
    char *command = "STAT\r\n";
    send_command(sock, command);

    // Read response
    char *response = read_response(sock);

    // Parse response
    Response parsed_response;
    parsed_response.headers = malloc(sizeof(char *));
    parsed_response.headers[0] = strtok(response, "\r\n");

    char *body = strtok(NULL, "");
    if (body[0] == '\r' && body[1] == '\n') {
        body = NULL;
    }
    parsed_response.body = body;

    return parsed_response;
}

int main(int argc, char **argv) {
    printf("Welcome to POP3 Client!\n");

    if (argc != 3) {
        fprintf(stderr, "Usage: pop3_client [IP address] [port]\n");
        exit(EXIT_FAILURE);
    }

    char *ip_address = argv[1];
    int port = atoi(argv[2]);

    printf("Connecting to server at %s:%d...\n", ip_address, port);
    int sock = connect_to_server(ip_address, port);

    printf("Connected to server!\n");

    Credentials credentials = get_credentials();

    printf("Logging in...\n");

    Response response = send_login_command(sock, credentials);

    if (strstr(response.headers[0], "+OK") != NULL) {
        printf("Login successful! Retrieving mailbox statistics...\n");

        response = send_stat_command(sock);

        if (response.body != NULL) {
            printf("You have %s messages in your mailbox.\n", response.body);
        } else {
            printf("You have no messages in your mailbox.\n");
        }
    } else {
        printf("Login failed. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    close(sock);
    printf("Connection closed.\n");

    return 0;
}