//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 110
#define BUFFER_SIZE 1024

void surrealConnection(FILE *sock, const char *action) {
    fprintf(sock, "%s\r\n", action);
    char response[BUFFER_SIZE];
    fgets(response, sizeof(response), sock);
    printf("%s", response);
}

void abstractEmailReceive(FILE *sock) {
    char buffer[BUFFER_SIZE];
    surrealConnection(sock, "USER surrealist");
    surrealConnection(sock, "PASS dreamscape");

    surrealConnection(sock, "LIST");
    printf("\n--- Here Comes The List: ---\n");
    while (fgets(buffer, sizeof(buffer), sock) && strcmp(buffer, ".\n") != 0) {
        printf("Strangely: %s", buffer);
    }
    
    surrealConnection(sock, "RETR 1"); // Retrieve first email
    printf("\n--- Absurd Email: ---\n");
    
    while (fgets(buffer, sizeof(buffer), sock) && strcmp(buffer, ".\n") != 0) {
        printf("Whispered: %s", buffer);
    }
    
    surrealConnection(sock, "DELE 1"); // Deleting the first email
    surrealConnection(sock, "QUIT");
}

void whimsicalJourney(const char *hostname) {
    struct hostent *server;
    struct sockaddr_in server_addr;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Connection Failed: A shadowy error haunted my socket\n");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Host Unreachable: The clouds conspired against me\n");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Connection Failure: As if the universe itself resisted\n");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    FILE *sock_stream = fdopen(sockfd, "r+");
    if (sock_stream == NULL) {
        fprintf(stderr, "Stream Error: Reality collapsed in on itself\n");
        exit(EXIT_FAILURE);
    }

    char greeting[BUFFER_SIZE];
    fgets(greeting, sizeof(greeting), sock_stream);
    printf("--- The Server Speaks: %s", greeting);
    
    abstractEmailReceive(sock_stream);
    fclose(sock_stream);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <POP3_SERVER>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    printf("\n--- Begin The Surreal Journey ---\n");
    whimsicalJourney(argv[1]);
    printf("\n--- End Of Surrealism ---\n");

    return 0;
}