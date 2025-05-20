//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 5000

int main() {
    int sockfd, valread, valwrite;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // fill in the server address struct
    server = gethostbyname("127.0.0.1");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connection successful\n");

    // send command to drone
    write(sockfd, "takeoff", 7);

    // read command from drone
    bzero(&valread, sizeof(valread));
    valread = read(sockfd, &valread, 1);
    if (valread!= 0) {
        printf("Error: %d\n", valread);
    } else {
        printf("Takeoff command sent successfully\n");
    }

    // send command to drone to land
    write(sockfd, "land", 5);

    // read command from drone
    bzero(&valread, sizeof(valread));
    valread = read(sockfd, &valread, 1);
    if (valread!= 0) {
        printf("Error: %d\n", valread);
    } else {
        printf("Landing command sent successfully\n");
    }

    // close socket
    close(sockfd);

    return 0;
}