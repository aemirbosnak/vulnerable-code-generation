//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: all-encompassing
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>

int main()
{
    int sockfd, portno, newsockfd, n;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[1024];

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // get server address
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    // fill in server's address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(21);

    // connect to the server
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // send command to server
    printf("FTP client\n");
    printf("Enter the command to be sent to server: ");
    fgets(buffer, 1024, stdin);

    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // read response from server
    if (read(sockfd, buffer, 1024) < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s\n", buffer);

    close(sockfd);
    return 0;
}