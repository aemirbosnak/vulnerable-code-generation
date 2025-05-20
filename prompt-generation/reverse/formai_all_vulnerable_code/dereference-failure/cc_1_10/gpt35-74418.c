//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sock, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFSIZE];

    if (argc < 4) {
        fprintf(stderr, "usage %s hostname port username\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        error("ERROR opening socket");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    memset(buffer, 0, BUFSIZE);
    n = read(sock, buffer, BUFSIZE - 1);

    if (n < 0) {
        error("ERROR reading from socket");
    }

    printf("%s\n", buffer);

    char user[BUFSIZE], pass[BUFSIZE], command[BUFSIZE];
    printf("Please enter the email address: ");
    fgets(user, BUFSIZE - 1, stdin);
    printf("Please enter the password: ");
    fgets(pass, BUFSIZE - 1, stdin);

    snprintf(command, BUFSIZE - 1, "USER %sPASS %s\n", user, pass);

    n = write(sock, command, strlen(command));

    if (n < 0) {
        error("ERROR writing to socket");
    }

    memset(buffer, 0, BUFSIZE);
    n = read(sock, buffer, BUFSIZE - 1);

    if (n < 0) {
        error("ERROR reading from socket");
    }

    if (strncmp(buffer, "+OK", 3) != 0) {
        printf("%s\n", buffer);
        error("ERROR logging in");
    }

    printf("%s\n", buffer);

    while (1) {
        printf("Please enter a POP3 command (QUIT to exit): ");

        memset(command, 0, BUFSIZE);
        fgets(command, BUFSIZE - 1, stdin);

        if (strncmp(command, "QUIT", 4) == 0) {
            break;
        }

        n = write(sock, command, strlen(command));

        if (n < 0) {
            error("ERROR writing to socket");
        }

        memset(buffer, 0, BUFSIZE);
        n = read(sock, buffer, BUFSIZE - 1);

        if (n < 0) {
            error("ERROR reading from socket");
        }

        printf("%s\n", buffer);
    }

    close(sock);
    return 0;
}