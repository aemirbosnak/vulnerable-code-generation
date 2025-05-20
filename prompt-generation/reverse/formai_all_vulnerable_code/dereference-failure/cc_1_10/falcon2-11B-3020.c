//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    // Create a socket
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set up the server address structure
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(12345);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Read the ebook
    FILE *ebook = fopen("ebook.txt", "r");
    if (ebook == NULL) {
        perror("ERROR opening ebook");
        exit(1);
    }
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), ebook)!= NULL) {
        printf("%s\n", buffer);
    }
    fclose(ebook);

    // Send a message to the server
    int msg_len = 256;
    char msg[msg_len];
    sprintf(msg, "I finished reading the ebook.");
    send(sockfd, msg, msg_len, 0);

    // Close the socket
    close(sockfd);

    return 0;
}