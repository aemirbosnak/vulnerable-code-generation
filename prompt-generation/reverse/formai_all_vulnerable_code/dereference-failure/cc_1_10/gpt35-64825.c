//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_SIZE 1024

void check(int exp, char *msg) {
    if (exp == -1) {
        perror(msg);
        exit(1);
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Could not resolve hostname: %s\n", hostname);
        exit(1);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    check(sock, "Failed to create socket");

    struct sockaddr_in serv_addr = {.sin_family = AF_INET, .sin_port = htons(993)};
    memcpy(&serv_addr.sin_addr, host->h_addr_list[0], host->h_length);

    check(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)), "Failed to connect");
    
    char buffer[MAX_SIZE];
    int length = recv(sock, buffer, MAX_SIZE, 0);
    check(length, "Failed to receive message");

    memset(buffer, '\0', MAX_SIZE);
    sprintf(buffer, "a001 LOGIN %s %s\r\n", username, password);
    check(send(sock, buffer, strlen(buffer), 0), "Failed to send message");

    length = recv(sock, buffer, MAX_SIZE, 0);
    check(length, "Failed to receive message");

    memset(buffer, '\0', MAX_SIZE);
    sprintf(buffer, "a002 SELECT INBOX\r\n");
    check(send(sock, buffer, strlen(buffer), 0), "Failed to send message");

    length = recv(sock, buffer, MAX_SIZE, 0);
    check(length, "Failed to receive message");

    memset(buffer, '\0', MAX_SIZE);
    sprintf(buffer, "a003 FETCH 1 BODY[TEXT]\r\n");
    check(send(sock, buffer, strlen(buffer), 0), "Failed to send message");

    length = recv(sock, buffer, MAX_SIZE, 0);
    check(length, "Failed to receive message");

    printf("%s\n", buffer);

    return 0;
}