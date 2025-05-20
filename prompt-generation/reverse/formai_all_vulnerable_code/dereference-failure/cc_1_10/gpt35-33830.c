//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 8080
#define MAXLINE 1024

// Function to randomly generate a string of given length
char* generate_string(int length) {
    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char* randomString = NULL;

    if (length) {
        randomString = malloc(sizeof(char) * (length +1));

        if (randomString) {
            int i;
            for (i=0; i<length; i++) {
                int index = rand() % (strlen(charset));
                randomString[i] = charset[index];
            }

            randomString[length] = '\0';
        }
    }

    return randomString;
}

int main() {
    int sockfd;
    char buffer[MAXLINE];
    char *hello = generate_string(1000000); // Generate 1MB of random string
    struct sockaddr_in servaddr;

    // Create a socket for the client
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed...\n");
        exit(0);
    }

    // Clear the servaddr structure
    memset(&servaddr, 0, sizeof(servaddr));

    // Set the server address and port number
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        printf("Connection with the server failed...\n");
        exit(0);
    }
    else {
        printf("Connected to the server...\n");
    }

    // Send the data
    clock_t start = clock();
    write(sockfd, hello, strlen(hello));
    clock_t end = clock();

    double time_elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    double speed = (strlen(hello) * 8) / (time_elapsed * 1000000);

    printf("Data sent successfully.\n");
    printf("Time elapsed for data transfer: %f seconds\n", time_elapsed);
    printf("Internet Speed: %f Mbps\n", speed);

    // Close the socket
    close(sockfd);

    return 0;
}