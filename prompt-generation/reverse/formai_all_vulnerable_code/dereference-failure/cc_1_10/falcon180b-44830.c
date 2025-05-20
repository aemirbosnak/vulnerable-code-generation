//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define TRUE 1
#define FALSE 0
#define MAX 100

// Function to convert signal strength in dBm to percentage
int convertSignalStrength(int dbm) {
    int percentage;
    if (dbm <= -100)
        percentage = 0;
    else if (dbm >= -50)
        percentage = 100;
    else
        percentage = (2 * dbm) + 100;

    return percentage;
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char buffer[MAX];
    char *ip;
    int port;
    int opt = TRUE;
    int addrlen;

    // Check for correct number of arguments
    if (argc!= 4) {
        printf("Usage: %s <IP Address> <Port> <Signal Strength Threshold>\n", argv[0]);
        return 1;
    }

    // Convert IP address from string to integer
    ip = argv[1];
    inet_pton(AF_INET, ip, &server.sin_addr);

    // Convert port number from string to integer
    port = atoi(argv[2]);

    // Convert signal strength threshold from string to integer
    int threshold = atoi(argv[3]);

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // Connect to Wi-Fi network
    if (connect(sock, (struct sockaddr *)&server, sizeof(server))!= 0) {
        printf("Error connecting to Wi-Fi network\n");
        return 1;
    }

    // Get Wi-Fi signal strength
    char command[50] = "iwconfig wlan0 | grep Quality | cut -d':' -f2 | tr -d''";
    FILE *fp = popen(command, "r");
    fscanf(fp, "%s", buffer);
    int signal_strength_dbm = atoi(buffer);

    // Convert signal strength to percentage
    int signal_strength_percentage = convertSignalStrength(signal_strength_dbm);

    // Check if signal strength meets threshold
    if (signal_strength_percentage >= threshold) {
        printf("Wi-Fi signal strength is good.\n");
    } else {
        printf("Wi-Fi signal strength is weak.\n");
    }

    // Close socket
    close(sock);

    return 0;
}