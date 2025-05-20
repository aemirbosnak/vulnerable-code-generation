//Gemma-7B DATASET v1.0 Category: Building a POP3 Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netdb.h>

#define POP3_PORT 110
#define POP3_HOST "pop.mymailserver.com"
#define POP3_USER "myusername"
#define POP3_PASS "mypassword"

int main()
{
    int sockfd, newsockfd, ret, n, i, len, flag = 0;
    char buffer[1024], filename[256], cmd[256], user[256], pass[256];
    struct sockaddr_in server_addr, client_addr;

    // Paranoid security measures
    setuid(0);
    setuid(geteuid());

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(POP3_PORT));

    // Connect to the server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr(POP3_HOST);
    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Authenticate
    sprintf(user, "%s", POP3_USER);
    sprintf(pass, "%s", POP3_PASS);
    send(sockfd, user, strlen(user), 0);
    recv(sockfd, buffer, 1024, 0);
    send(sockfd, pass, strlen(pass), 0);
    recv(sockfd, buffer, 1024, 0);

    // List messages
    sprintf(cmd, "LIST");
    send(sockfd, cmd, strlen(cmd), 0);
    recv(sockfd, buffer, 1024, 0);

    // Download message
    sprintf(cmd, "RETR %d", 1);
    send(sockfd, cmd, strlen(cmd), 0);
    recv(sockfd, buffer, 1024, 0);

    // Save message to file
    filename[0] = '\0';
    sprintf(filename, "message.txt");
    FILE *fp = fopen(filename, "w");
    fprintf(fp, "%s", buffer);
    fclose(fp);

    // Close the socket
    close(sockfd);

    return 0;
}