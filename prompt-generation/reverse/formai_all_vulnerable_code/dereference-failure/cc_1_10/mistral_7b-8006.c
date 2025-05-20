//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 4096

typedef struct {
    int sockfd;
    struct sockaddr_in serv_addr;
} client;

void die(const char *msg) {
    perror(msg);
    exit(1);
}

client *create_client(const char *hostname, int port) {
    client *client = calloc(1, sizeof(client));
    if (!client)
        die("Memory error!\n");

    client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sockfd < 0)
        die("Could not create socket!\n");

    client->serv_addr.sin_family = AF_INET;
    client->serv_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, hostname, &client->serv_addr.sin_addr) <= 0) {
        die("Invalid address/ Address not supported!\n");
    }

    if (connect(client->sockfd, (struct sockaddr *) &client->serv_addr,
               sizeof(client->serv_addr)) < 0)
        die("Connection failed!\n");

    return client;
}

void send_request(client *client, const char *request) {
    ssize_t num_bytes_sent;
    num_bytes_sent = send(client->sockfd, request, strlen(request), 0);
    if (num_bytes_sent < 0)
        die("Error sending request!\n");
    printf("Request sent: %s\n", request);
}

void read_response(client *client, char *buffer, size_t size) {
    ssize_t num_bytes_received;
    num_bytes_received = recv(client->sockfd, buffer, size - 1, 0);
    if (num_bytes_received < 0) {
        die("Error reading response!\n");
    }

    buffer[num_bytes_received] = '\0';
    printf("Response received:\n%s\n", buffer);
}

void cleanup(client *client) {
    close(client->sockfd);
    free(client);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    client *client = create_client(argv[1], atoi(argv[2]));
    const char *request = "--sync-example--\n"
                          "Host: %s\r\n"
                          "Connection: Keep-Alive\r\n"
                          "User-Agent: Sync-Example/1.0\r\n"
                          "\r\n";

    char buffer[BUFFER_SIZE];

    snprintf(request, sizeof(request), request, argv[1]);
    printf("Connecting to %s:%s\n", argv[1], argv[2]);

    send_request(client, request);
    read_response(client, buffer, BUFFER_SIZE);

    cleanup(client);
    return 0;
}