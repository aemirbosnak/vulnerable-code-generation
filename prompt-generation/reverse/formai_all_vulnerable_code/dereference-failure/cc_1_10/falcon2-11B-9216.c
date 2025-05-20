//Falcon2-11B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <net/if.h>
#include <net/ethernet.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <net/if.h>
#include <signal.h>
#include <math.h>

//Global Variables
int sockfd = -1;
struct sockaddr_in serv_addr;
char message[1024];
char ssid[50];
char BSSID[18];
char channel[3];
int signalStrength = 0;

void print_signal_strength(int signalStrength) {
    int percent = (int)((signalStrength - 20) / 3 * 100);
    if (percent < 0) {
        percent = 0;
    }
    else if (percent > 100) {
        percent = 100;
    }
    printf("Signal Strength: %d%%\n", percent);
}

void print_info() {
    printf("SSID: %s\n", ssid);
    printf("BSSID: %s\n", BSSID);
    printf("Channel: %d\n", atoi(channel));
    printf("Signal Strength: %d%%\n", signalStrength);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <SSID>\n", argv[0]);
        return 0;
    }

    //Initialize the socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    //Set up the serv_addr struct
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(2020);

    //Bind the socket
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    //Read the SSID from command line
    strncpy(ssid, argv[1], sizeof(ssid));

    //Loop until CTRL+C is pressed
    while (1) {
        //Receive a datagram
        if (recvfrom(sockfd, message, sizeof(message), 0, NULL, NULL) < 0) {
            perror("ERROR receiving from socket");
            exit(1);
        }

        //Parse the message
        char *token;
        token = strtok(message, ",");
        strcpy(BSSID, token);
        token = strtok(NULL, ",");
        strcpy(channel, token);
        token = strtok(NULL, ",");
        token = strtok(NULL, ",");
        token = strtok(NULL, ",");
        token = strtok(NULL, ",");
        token = strtok(NULL, ",");
        token = strtok(NULL, ",");
        token = strtok(NULL, ",");
        strcpy(ssid, token);

        //Calculate the signal strength
        signalStrength = atoi(BSSID);
        signalStrength += 20 * atoi(channel);

        //Print the information
        print_info();

        //Calculate the percentage
        int percent = (int)((signalStrength - 20) / 3 * 100);
        if (percent < 0) {
            percent = 0;
        }
        else if (percent > 100) {
            percent = 100;
        }

        //Print the signal strength
        print_signal_strength(percent);
    }

    close(sockfd);
    return 0;
}