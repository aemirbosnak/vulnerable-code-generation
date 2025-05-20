//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define SERVER "google.com" // The server we shall ping
#define PORT 80 // The port we shall connect to

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void perform_speed_test() {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    int n;
    
    // Let's create a socket!
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("Error opening socket");

    // Finding our friendly neighborhood server
    server = gethostbyname(SERVER);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    // Prepare the destination to whom we'll connect
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(PORT);

    // Let's connect to our server!
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
    printf("Connected to %s\n", SERVER);
    
    // Let's gracefully create our request
    snprintf(buffer, sizeof(buffer) - 1, "GET / HTTP/1.0\r\nHost: %s\r\n\r\n", SERVER);

    // Set the starting time for our speed test journey
    clock_t start = clock();
    
    // Send our glorious request to the server
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
        error("ERROR writing to socket");
    
    // Hold our breath as we wait for a response
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        n = read(sockfd, buffer, BUFFER_SIZE - 1);
        if (n <= 0) break; // EOF or error
        printf("%s", buffer); // Print the response
    }

    // Capture the ending time
    clock_t end = clock();
    
    // Compute the total duration
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nSpeed test completed!\n");
    printf("Total time taken: %.2f seconds\n", duration);

    // Close the socket and end our adventure!
    close(sockfd);
}

int main() {
    printf("Welcome to the Curious C Internet Speed Test!\n");
    printf("We shall embark on a journey to measure your internet speed.\n");
    printf("Gather your courage, for we shall ping a server!\n\n");
    
    // Invoke the speed test
    perform_speed_test();
    
    printf("\nThank you for testing your speed with us!\n");
    return 0;
}