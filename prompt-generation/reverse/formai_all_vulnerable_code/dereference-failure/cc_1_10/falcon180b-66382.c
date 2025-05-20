//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 21

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    if(argc!= 4) {
        printf("Usage: %s <hostname> <username> <password>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    struct hostent *host = gethostbyname(hostname);
    if(host == NULL) {
        error("gethostbyname");
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        error("socket");
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = *(unsigned long *)host->h_addr;

    if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        error("connect");
    }

    char login[64];
    sprintf(login, "USER %s\r\n", username);
    send(sock, login, strlen(login), 0);

    char password_str[64];
    sprintf(password_str, "PASS %s\r\n", password);
    send(sock, password_str, strlen(password_str), 0);

    char buffer[BUFFER_SIZE];
    while(1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if(bytes_received <= 0) {
            break;
        }
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}