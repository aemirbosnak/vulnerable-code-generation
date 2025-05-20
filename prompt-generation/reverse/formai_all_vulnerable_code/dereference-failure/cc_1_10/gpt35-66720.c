//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int sock_fd, n;
    char buffer[BUF_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    // create the socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // get server address
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    // set server address to connect
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // connect to the server
    if (connect(sock_fd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // read the welcome message
    bzero(buffer, BUF_SIZE);
    n = read(sock_fd, buffer, BUF_SIZE-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // send the login command
    char user[50], password[50];
    printf("Username: ");
    scanf("%s", user);
    write(sock_fd, "1 LOGIN ", strlen("1 LOGIN "));
    write(sock_fd, user, strlen(user));
    write(sock_fd, "\r\n", strlen("\r\n"));
    bzero(buffer, BUF_SIZE);
    n = read(sock_fd, buffer, BUF_SIZE-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // send the password command
    printf("Password: ");
    scanf("%s", password);
    write(sock_fd, "2 PASS ", strlen("2 PASS "));
    write(sock_fd, password, strlen(password));
    write(sock_fd, "\r\n", strlen("\r\n"));
    bzero(buffer, BUF_SIZE);
    n = read(sock_fd, buffer, BUF_SIZE-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // select the mailbox
    write(sock_fd, "3 SELECT INBOX\r\n", strlen("3 SELECT INBOX\r\n"));
    bzero(buffer, BUF_SIZE);
    n = read(sock_fd, buffer, BUF_SIZE-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // list the messages
    write(sock_fd, "4 UID SEARCH UNSEEN\r\n", strlen("4 UID SEARCH UNSEEN\r\n"));
    bzero(buffer, BUF_SIZE);
    n = read(sock_fd, buffer, BUF_SIZE-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("Messages:\n%s\n", buffer);

    // close the socket
    close(sock_fd);

    return 0;
}