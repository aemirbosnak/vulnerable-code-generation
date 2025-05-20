//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <time.h>

#define MAX_BUFFER_SIZE 256

// Function to handle errors and exit the program
void error(const char *msg) {
    perror(msg);
    exit(0);
}

// Function to get the current time
char* get_current_time() {
    time_t rawtime;
    time(&rawtime);
    return strtok(ctime(&rawtime), "\n");
}

int main(int argc, char *argv[]) {

    // Check if the user entered the required command line arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(0);
    }

    int sockfd, portno, n;
    char buffer[MAX_BUFFER_SIZE];

    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Set the destination IP address and port number
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server = gethostbyname(argv[1]);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Try to connect to the server multiple times to ensure network quality
    int num_attempts = 0;
    while (num_attempts < 5) {
        // Attempt to connect to the server
        if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
            printf("[%s] Failed to connect to %s on port %d. Trying again in 5 seconds.\n",
                get_current_time(), argv[1], portno);
            num_attempts++;
            sleep(5);
        } else {
            printf("[%s] Connected to %s on port %d.\n",
                get_current_time(), argv[1], portno);
            break;
        }
    }
    
    // If all attempts to connect to the server failed, exit the program
    if (num_attempts == 5) {
        error("Failed to connect to server after 5 attempts.");
    }

    // Continuously receive and send data to the server
    while (1) {
        // Clear the buffer and wait for user input
        bzero(buffer, MAX_BUFFER_SIZE);
        printf("Please enter a message: ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);

        // Send the message to the server
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            printf("[%s] Error writing to socket.\n", get_current_time());
            break;
        }

        // Clear the buffer and receive a response from the server
        bzero(buffer, MAX_BUFFER_SIZE);
        n = read(sockfd, buffer, MAX_BUFFER_SIZE - 1);
        if (n < 0) {
            printf("[%s] Error reading from socket.\n", get_current_time());
            break;
        } else if (n == 0) {
            printf("[%s] Connection closed by server.\n", get_current_time());
            break;
        } else {
            printf("[%s] Server response: %s\n", get_current_time(), buffer);
        }
    }

    // Close the socket and exit the program
    close(sockfd);
    printf("[%s] Program terminated.\n", get_current_time());
    return 0;
}