//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;
    int portno = 143; // default IMAP4 port number
    char buffer[1024];
    char username[100];
    char password[100];
    char command[100];

    if (argc < 2) {
        fprintf(stderr,"usage %s hostname [portno]\n", argv[0]);
        exit(0);
    }

    if (argc > 2)
        portno = atoi(argv[2]);

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error: host not found\n");
        exit(0);
    }

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: cannot open socket");
        exit(0);
    }

    // setup server address
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&server_addr.sin_addr.s_addr,
         server->h_length);
    server_addr.sin_port = htons(portno);

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error: cannot connect to server");
        exit(0);
    }

    // read welcome message
    bzero(buffer, sizeof(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer); // print welcome message to user

    // send login command with username and password
    printf("Username: ");
    fgets(username, sizeof(username), stdin);
    printf("Password: ");
    fgets(password, sizeof(password), stdin);
    sprintf(command, "LOGIN %s %s\n", username, password);
    write(sockfd, command, strlen(command));

    // read login response from server
    bzero(buffer, sizeof(buffer));
    read(sockfd, buffer, sizeof(buffer));
    if (strncmp(buffer, "* OK", 4) == 0) {
        printf("%s", buffer); // login success
    }
    else {
        printf("%s", buffer); // login failed
        exit(0);
    }

    // send list command to list available mailbox
    write(sockfd, "LIST \"\" *\n", strlen("LIST \"\" *\n"));

    // read list response from server
    bzero(buffer, sizeof(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer); // print mailbox list to user

    // close socket
    close(sockfd);
    return 0;
}