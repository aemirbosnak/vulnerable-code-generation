//FormAI DATASET v1.0 Category: Port Scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <regex.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_PORTS_RANGE 65535
#define REGEX_IP "^(?:[0-9]{1,3}\\.){3}[0-9]{1,3}$"

bool validatePort(char* port) {
    int intPort = atoi(port);
    if(intPort > 0 && intPort <= MAX_PORTS_RANGE) {
        return true;
    }
    return false;
}

bool validateIP(char* ip) {
    regex_t regex;
    if (regcomp(&regex, REGEX_IP, REG_EXTENDED) != 0) {
        return false;
    }
    int result = regexec(&regex, ip, 0, NULL, 0);
    regfree(&regex);
    if (result == 0) {
        return true;
    }
    return false;
}

int scanPort(char* ipAddress, int port) {
    int sockfd, err;
    struct sockaddr_in target;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        return -1;
    }

    // Configure target address
    target.sin_family = AF_INET;
    inet_aton(ipAddress, &target.sin_addr);
    target.sin_port = htons(port);

    // Connect to target
    err = connect(sockfd, (struct sockaddr*) &target, sizeof(target));
    close(sockfd);
    if (err < 0) {
        return 0; // Port closed
    }
    return 1; // Port open
}

int main(int argc, char* argv[]) {
    // Validate command line arguments
    if (argc != 3 || !validateIP(argv[1]) || !validatePort(argv[2])) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        return 1;
    }

    // Scan port on target IP address
    int port = atoi(argv[2]);
    int status = scanPort(argv[1], port);
    if (status == -1) {
        printf("Error creating socket\n");
        return 1;
    } else if (status == 0) {
        printf("Port %d closed on %s\n", port, argv[1]);
    } else {
        printf("Port %d open on %s\n", port, argv[1]);
    }

    return 0;
}