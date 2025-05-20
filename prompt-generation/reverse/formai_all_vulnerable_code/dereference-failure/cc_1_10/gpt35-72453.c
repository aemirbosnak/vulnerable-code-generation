//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#define PORT 110

void receive_and_print(int sock) {
    char buff[4096];
    int n;
    while (1) {
        bzero(buff, sizeof(buff));
        if ((n = read(sock, buff, 4096)) <= 0) {
            perror("read");
            exit(1);
        } else {
            printf("%s", buff);
            fflush(stdout);
            if (strstr(buff, "\r\n.\r\n"))
                break;
        }
    }
}

int main() {
    char hostname[255];
    printf("Enter hostname of the server: ");
    scanf("%s", hostname);
    struct hostent *he;
    if ((he = gethostbyname(hostname)) == NULL) {
        perror("gethostbyname");
        return 1;
    }
    struct sockaddr_in server_addr;
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr, he->h_addr_list[0], he->h_length);
    int sock;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return 1;
    }
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }
    receive_and_print(sock);
    char user[255];
    printf("Enter username: ");
    scanf("%s", user);
    char pass[255];
    printf("Enter password: ");
    scanf("%s", pass);
    char user_command[255];
    sprintf(user_command, "USER %s\r\n", user);
    if (write(sock, user_command, strlen(user_command)) < 0) {
        perror("write to socket");
        return 1;
    }
    receive_and_print(sock);
    char pass_command[255];
    sprintf(pass_command, "PASS %s\r\n", pass);
    if (write(sock, pass_command, strlen(pass_command)) < 0) {
        perror("write to socket");
        return 1;
    }
    receive_and_print(sock);
    if (write(sock, "LIST\r\n", 6) < 0) {
        perror("write to socket");
        return 1;
    }
    receive_and_print(sock);
    if (write(sock, "QUIT\r\n", 6) < 0) {
        perror("write to socket");
        return 1;
    }
    receive_and_print(sock);
    close(sock);
    return 0;
}