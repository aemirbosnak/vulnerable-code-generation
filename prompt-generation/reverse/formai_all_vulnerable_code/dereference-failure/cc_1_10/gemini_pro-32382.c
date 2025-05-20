//GEMINI-pro DATASET v1.0 Category: Networking ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_MSG_LEN 1024

// Custom error handling
void cyberError(const char *err) {
    printf("[ERROR] %s\n", err);
    exit(1);
}

int main(int argc, char **argv) {
    // Welcome message
    printf("\n\n   _                                        _          _          _ \n");
    printf("  (_)_ ____ _  __ _  ___   _ __ ___    ___  _  _   _  (_)_  ___  (_)_  ___ \n");
    printf("   __)|  _ \\ |/ _` |/ _ \\ | '_ ` _ \\  / _ \\| || | | | | || |/ _ \\ | | |/ _ \\\n");
    printf("  / __| | |\\ \\ (_| ||  __/ | | | | | || (_) | || |_| | | | | (_) || | | (_) |\n");
    printf(" |____|_| |_|\\__,_|\\___| |_| |_| |_| \\___/ |_|\\__,_| |_|_|\___/ |_| |\\___/ \n");
    printf("                                                                       \n\n");

    // Check for command line arguments
    if (argc != 3) {
        cyberError("Usage: cyberConnect <hostname> <port>");
    }

    // Resolve hostname to IP address
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        cyberError("Invalid hostname");
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        cyberError("Socket creation failed");
    }

    // Set up server address
    struct sockaddr_in serv_addr;
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr = *((struct in_addr *) host->h_addr);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        cyberError("Connection failed");
    }

    // Main loop
    char msg[MAX_MSG_LEN], buf[MAX_MSG_LEN];
    while (1) {
        // Get input from user
        printf("> ");
        fgets(msg, MAX_MSG_LEN, stdin);

        // Send message to server
        if (send(sockfd, msg, strlen(msg), 0) < 0) {
            cyberError("Send failed");
        }

        // Receive response from server
        if (recv(sockfd, buf, MAX_MSG_LEN, 0) < 0) {
            cyberError("Receive failed");
        }

        // Print response
        printf("%s\n", buf);
    }

    // Close socket
    close(sockfd);

    // Exit program
    return 0;
}