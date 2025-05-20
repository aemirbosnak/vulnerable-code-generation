//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char *host_name = "localhost";
    char *port_name = "8080";
    char buffer[BUFFER_SIZE];
    int nbytes;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    host = gethostbyname(host_name);
    if (host == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port_name));
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    while (fgets(buffer, BUFFER_SIZE, stdin)!= NULL) {
        nbytes = send(sock, buffer, strlen(buffer), 0);
        if (nbytes == -1) {
            printf("Error sending message\n");
            exit(1);
        }
    }

    close(sock);
    return 0;
}