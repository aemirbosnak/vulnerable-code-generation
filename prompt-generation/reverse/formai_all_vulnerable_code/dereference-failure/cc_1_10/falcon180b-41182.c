//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct hostent *host;
    struct sockaddr_in server_addr;
    char username[50], password[50];
    char buffer[BUFFER_SIZE];
    int nbytes;

    // get server address
    host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Error: Invalid server address\n");
        exit(1);
    }

    // create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Failed to create socket\n");
        exit(1);
    }

    // set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Failed to connect to server\n");
        exit(1);
    }

    // send username and password
    sprintf(buffer, "USER %s\r\n", argv[2]);
    write(sock, buffer, strlen(buffer));

    sprintf(buffer, "PASS %s\r\n", argv[3]);
    write(sock, buffer, strlen(buffer));

    // receive server response
    nbytes = read(sock, buffer, BUFFER_SIZE);
    buffer[nbytes] = '\0';
    printf("Server response: %s\n", buffer);

    // send file transfer command
    sprintf(buffer, "RETR %s\r\n", argv[4]);
    write(sock, buffer, strlen(buffer));

    // receive file contents
    nbytes = read(sock, buffer, BUFFER_SIZE);
    buffer[nbytes] = '\0';
    printf("File contents:\n%s", buffer);

    // close socket
    close(sock);
    return 0;
}