//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>

int main(int argc, char* argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    int len;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Assign local port number
    portno = atoi(argv[1]);

    // Create address struct and fill in the address
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send message to server
    n = sprintf(buffer, "Hello, World!\r\n");
    send(sockfd, buffer, n, 0);
    printf("%s\n", buffer);

    // Receive response from server
    len = recv(sockfd, buffer, sizeof(buffer), 0);
    if (len < 0) {
        perror("ERROR receiving");
        exit(1);
    }
    printf("%s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}