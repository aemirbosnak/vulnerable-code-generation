//Falcon2-11B DATASET v1.0 Category: Wireless Network Scanner ; Style: happy
#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

// Function to scan for wireless networks
int scan_networks(int port) {
    struct sockaddr_in server_address;
    struct hostent *host;
    struct sockaddr_in their_address;
    int sockfd, len;
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return -1;
    }

    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    host = gethostbyname("192.168.1.1"); // Replace with your router IP address
    if (host == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        return -1;
    }

    bcopy((char *)host->h_addr, (char *)&server_address.sin_addr.s_addr, host->h_length);

    len = sizeof(server_address);

    if (connect(sockfd, (struct sockaddr *)&server_address, len) < 0) {
        perror("ERROR connecting");
        return -1;
    }

    while (1) {
        bzero(buffer, sizeof(buffer));
        len = write(sockfd, "GET / HTTP/1.1\r\nHost: 192.168.1.1\r\n\r\n", 50);
        if (len < 0) {
            perror("ERROR writing to socket");
            return -1;
        }

        bzero(buffer, sizeof(buffer));
        len = read(sockfd, buffer, sizeof(buffer));
        if (len < 0) {
            perror("ERROR reading from socket");
            return -1;
        }

        if (strstr(buffer, "HTTP/1.1 200 OK")!= NULL) {
            printf("%s\n", buffer);
        }

        bzero(buffer, sizeof(buffer));
        len = write(sockfd, "GET / HTTP/1.1\r\nHost: 192.168.1.1\r\n\r\n", 50);
        if (len < 0) {
            perror("ERROR writing to socket");
            return -1;
        }

        bzero(buffer, sizeof(buffer));
        len = read(sockfd, buffer, sizeof(buffer));
        if (len < 0) {
            perror("ERROR reading from socket");
            return -1;
        }

        if (strstr(buffer, "HTTP/1.1 200 OK")!= NULL) {
            printf("%s\n", buffer);
        }

        if (strstr(buffer, "<tr><td>SSID</td><td>")!= NULL) {
            printf("%s\n", buffer);
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    scan_networks(80);
    return 0;
}