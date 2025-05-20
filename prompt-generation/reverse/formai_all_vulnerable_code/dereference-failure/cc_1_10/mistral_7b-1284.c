//MISTRAL-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <signal.h>
#include <time.h>

// Function to send HTTP request and check for 200 OK status
int check_website(char *website) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    server = gethostbyname(website);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR opening socket\n");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        return 1;
    }

    // Send HTTP request
    write(sockfd, "GET / HTTP/1.1\r\nHost: ", strlen("GET / HTTP/1.1\r\nHost: "));
    write(sockfd, website, strlen(website));
    write(sockfd, "\r\nUser-Agent: Uptime Joker\r\nAccept: text/html\r\n\r\n", strlen("User-Agent: Uptime Joker\r\nAccept: text/html\r\n\r\n"));

    // Read response header
    char response[256];
    n = read(sockfd, response, 256);
    if (n < 0) {
        perror("ERROR reading from socket");
        close(sockfd);
        return 1;
    }

    // Check for 200 OK status
    if (strstr(response, "HTTP/1.1 200 OK") == NULL) {
        fprintf(stderr, "ERROR, website returned status code: %s\n", response);
        close(sockfd);
        return 1;
    }

    close(sockfd);
    return 0;
}

// Function to print funny message and exit program
void die(char *msg) {
    printf("%s: %s\n", msg, "Oh noes! The website is down. Run for cover!\n");
    exit(1);
}

// Main function
int main() {
    char *website = "www.example.com";
    int uptime = 0;

    while (1) {
        int status = check_website(website);

        if (status == 1) {
            die("Uptime Joker");
        }

        // Increment uptime if website is up
        sleep(60);
        uptime++;

        printf("Uptime Joker: Website %s is up. Uptime: %d minutes\n", website, uptime);
    }

    return 0;
}