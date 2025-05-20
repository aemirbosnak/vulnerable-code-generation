//MISTRAL-7B DATASET v1.0 Category: Intrusion detection system ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) die("ERROR opening socket");

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr(server->h_addr_list[0]);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        die("ERROR connecting");

    char buffer[BUFFER_SIZE];
    int n;

    while ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        for (int i = 0; i < n; i++) {
            if (buffer[i] == '\x00' || buffer[i] == '\x0a') {
                buffer[i] = '\0';
                int len = i;
                char *str = (char *) malloc(len + 1);
                strncpy(str, buffer, len);
                if (strlen(str) > 10) {
                    printf("Suspicious string detected: %s\n", str);
                }
                free(str);
                for (int j = i; j < n; j++) buffer[j] = buffer[j + 1];
                i--;
                n--;
            }
        }

        memset(buffer, 0, BUFFER_SIZE);
    }

    close(sockfd);
    return EXIT_SUCCESS;
}