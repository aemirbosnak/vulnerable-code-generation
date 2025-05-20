//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/time.h>

#define MAX_STR_LEN 1024
#define TRUE 1
#define FALSE 0

// Function to convert signal strength in dBm to percentage
int dBmToPercentage(int dBm) {
    int percentage = (int) ((float) dBm / 100.0 * 100.0);
    return percentage;
}

// Function to display signal strength in a bar graph
void displaySignalStrength(int signalStrength) {
    int i;
    for (i = 0; i < signalStrength; i++) {
        printf("#");
    }
    printf("\n");
}

// Function to get the signal strength from the router
int getSignalStrength(char *routerIP) {
    int sockfd, portno, n, valread, signalStrength = 0;
    char buffer[MAX_STR_LEN];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket");
        exit(0);
    }

    server = gethostbyname(routerIP);
    if (server == NULL) {
        printf("No such host");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    send(sockfd, "GET / HTTP/1.0\r\n\r\n", strlen("GET / HTTP/1.0\r\n\r\n"), 0);

    while ((n = read(sockfd, buffer, MAX_STR_LEN)) > 0) {
        buffer[n] = '\0';
        if (strstr(buffer, "rssi")) {
            sscanf(buffer, "rssi=%d", &signalStrength);
            break;
        }
    }

    close(sockfd);
    return signalStrength;
}

int main() {
    char routerIP[MAX_STR_LEN] = "192.168.1.1"; // Replace with your router IP address
    int signalStrength = getSignalStrength(routerIP);
    displaySignalStrength(signalStrength);
    printf("Signal strength: %d%%\n", dBmToPercentage(signalStrength));
    return 0;
}