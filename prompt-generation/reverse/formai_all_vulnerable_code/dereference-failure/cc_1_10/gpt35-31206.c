//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void read_response(int sock);

int main (int argc, char *argv[]) {
    int sock, port, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE], username[BUFFER_SIZE], password[BUFFER_SIZE];

    if (argc < 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[2]);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        perror("Error opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        printf("Error, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(sock,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    read_response(sock);

    printf("Username: ");
    fgets(username, BUFFER_SIZE, stdin);
    printf("Password: ");
    fgets(password, BUFFER_SIZE, stdin);

    char user_buffer[BUFFER_SIZE + strlen(username)];
    sprintf(user_buffer, "USER %s", username);

    char pass_buffer[BUFFER_SIZE + strlen(password)];
    sprintf(pass_buffer, "PASS %s", password);

    send(sock, user_buffer, strlen(user_buffer), 0);
    read_response(sock);

    send(sock, pass_buffer, strlen(pass_buffer), 0);
    read_response(sock);

    send(sock, "LIST\n", 5, 0);
    read_response(sock);

    send(sock, "QUIT\n", 5, 0);
    read_response(sock);

    close(sock);

    return 0;
}

void read_response(int sock) {
    int n;
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);

    while ((n = read(sock, buffer, BUFFER_SIZE - 1)) > 0) {
        printf("%s", buffer);
        bzero(buffer, BUFFER_SIZE);
    }

    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
}