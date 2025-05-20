//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1000

int main() {
    int sockfd, valread, numbytes;
    struct hostent *host;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUFFER_SIZE];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    host = gethostbyname("www.google.com");
    if (host == NULL) {
        printf("ERROR, no such host\n");
        exit(1);
    }
    serv_addr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&serv_addr.sin_addr.s_addr, host->h_length);
    serv_addr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    numbytes = write(sockfd, "GET / HTTP/1.0\r\n\r\n", 26);
    if (numbytes < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    memset(buffer, 0, MAX_BUFFER_SIZE);
    valread = read(sockfd, buffer, MAX_BUFFER_SIZE);
    if (valread < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    if (strstr(buffer, "200 OK")) {
        printf("Ping successful to %s\n", host->h_name);
    } else {
        printf("Ping failed to %s\n", host->h_name);
    }

    close(sockfd);
    return 0;
}