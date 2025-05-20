//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    char hostname[100];
    int port = 110;
    memset(&server_addr, 0, sizeof(server_addr));
    printf("Enter POP3 server hostname: ");
    scanf("%s", hostname);
    printf("Enter POP3 server port: ");
    scanf("%d", &port);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if(inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        printf("Invalid hostname\n");
        return 1;
    }
    if(connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Connection failed: %s\n", strerror(errno));
        return 1;
    }
    char username[100];
    char password[100];
    printf("Enter POP3 username: ");
    scanf("%s", username);
    printf("Enter POP3 password: ");
    scanf("%s", password);
    char buffer[MAX_LINE];
    sprintf(buffer, "USER %s\r\n", username);
    send(sock, buffer, strlen(buffer), 0);
    char response[MAX_LINE];
    memset(response, 0, sizeof(response));
    int count = recv(sock, response, sizeof(response), 0);
    if(count <= 0) {
        printf("Failed to receive response\n");
        return 1;
    }
    printf("Response: %s", response);
    sprintf(buffer, "PASS %s\r\n", password);
    send(sock, buffer, strlen(buffer), 0);
    memset(response, 0, sizeof(response));
    count = recv(sock, response, sizeof(response), 0);
    if(count <= 0) {
        printf("Failed to receive response\n");
        return 1;
    }
    printf("Response: %s", response);
    char quit[MAX_LINE];
    sprintf(quit, "QUIT\r\n");
    send(sock, quit, strlen(quit), 0);
    close(sock);
    return 0;
}