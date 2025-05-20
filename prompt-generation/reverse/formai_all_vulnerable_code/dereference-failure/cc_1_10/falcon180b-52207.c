//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void die(const char *s) {
    perror(s);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <server> <username> <password>\n", argv[0]);
        return 1;
    }

    char server[NI_MAXHOST], username[NI_MAXHOST], password[NI_MAXHOST];
    strncpy(server, argv[1], NI_MAXHOST - 1);
    strncpy(username, argv[2], NI_MAXHOST - 1);
    strncpy(password, argv[3], NI_MAXHOST - 1);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        die("socket");
    }

    struct addrinfo hints, *servinfo;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    getaddrinfo(server, "110", &hints, &servinfo);

    if (connect(sock, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
        die("connect");
    }

    char buf[BUFFER_SIZE];
    snprintf(buf, BUFFER_SIZE, "USER %s\r\n", username);
    send(sock, buf, strlen(buf), 0);

    char response[BUFFER_SIZE];
    int bytes_received = recv(sock, response, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        die("recv");
    }

    response[bytes_received - 1] = '\0';
    if (strncmp(response, "+OK", 3)!= 0) {
        close(sock);
        fprintf(stderr, "Authentication failed: %s\n", response);
        return 1;
    }

    snprintf(buf, BUFFER_SIZE, "PASS %s\r\n", password);
    send(sock, buf, strlen(buf), 0);

    bytes_received = recv(sock, response, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        die("recv");
    }

    response[bytes_received - 1] = '\0';
    if (strncmp(response, "+OK", 3)!= 0) {
        close(sock);
        fprintf(stderr, "Authentication failed: %s\n", response);
        return 1;
    }

    char command[BUFFER_SIZE];
    while (fgets(command, BUFFER_SIZE, stdin)!= NULL) {
        if (strncmp(command, "quit\n", 5) == 0) {
            break;
        }

        send(sock, command, strlen(command), 0);

        bytes_received = recv(sock, response, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            die("recv");
        }

        response[bytes_received - 1] = '\0';
        printf("%s", response);
    }

    close(sock);
    return 0;
}