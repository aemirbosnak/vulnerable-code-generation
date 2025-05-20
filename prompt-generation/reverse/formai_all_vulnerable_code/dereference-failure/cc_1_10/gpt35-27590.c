//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    int sockfd, n;
    struct sockaddr_in server_address;

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Get the IP address of the host */
    struct hostent *server;
    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    /* Set up server address */
    memset((char *)&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    memcpy((char *)&server_address.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    server_address.sin_port = htons(atoi(argv[2]));

    /* Connect to server */
    if (connect(sockfd,(struct sockaddr *)&server_address,sizeof(server_address)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    char buffer[BUFFER_SIZE];

    /* Prompt user for username and password */
    char username[BUFFER_SIZE], password[BUFFER_SIZE];
    printf("Username: ");
    fgets(username, BUFFER_SIZE, stdin);
    printf("Password: ");
    fgets(password, BUFFER_SIZE, stdin);

    /* Send username and password to server */
    char userpass[BUFFER_SIZE * 2];
    sprintf(userpass, "%s\r\n%s\r\n", username, password);
    n = write(sockfd, userpass, strlen(userpass));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    /* Read response from server */
    n = read(sockfd, buffer, BUFFER_SIZE - 1);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    buffer[n] = '\0';

    printf("%s", buffer);

    /* Prompt user for command */
    char command[BUFFER_SIZE];
    printf("> ");
    fgets(command, BUFFER_SIZE, stdin);

    /* Send command to server */
    n = write(sockfd, command, strlen(command));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    /* Read response from server */
    n = read(sockfd, buffer, BUFFER_SIZE - 1);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    buffer[n] = '\0';

    printf("%s", buffer);

    /* Close connection */
    close(sockfd);

    return 0;
}