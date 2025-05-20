//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: surprised
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, newsockfd, addrlen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        perror("ERROR opening socket");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        perror("ERROR on binding");
        return 1;
    }

    listen(sockfd, 5);

    addrlen = sizeof(cli_addr);

    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &addrlen);

    if (newsockfd == -1) {
        perror("ERROR on accept");
        return 1;
    }

    while (1) {
        bzero(buffer, sizeof(buffer));
        bzero((char *) &cli_addr, sizeof(cli_addr));

        if (read(newsockfd, buffer, sizeof(buffer)) == -1) {
            perror("ERROR reading from socket");
            return 1;
        }

        printf("%s", buffer);

        bzero(buffer, sizeof(buffer));
        bzero((char *) &cli_addr, sizeof(cli_addr));

        if (write(newsockfd, buffer, sizeof(buffer)) == -1) {
            perror("ERROR writing to socket");
            return 1;
        }

        printf("%s", buffer);
    }

    return 0;
}