//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define MAX_URL_LENGTH 256
#define SERVER_PORT 80
#define CHECK_INTERVAL 5 // in seconds

void check_website(const char *url);
void log_status(const char *url, int status);

int main() {
    char url[MAX_URL_LENGTH];

    printf("Welcome to the Uptime Monitor!\n");
    printf("Please enter a URL to monitor (without 'http://'): ");
    scanf("%s", url);

    printf("Monitoring %s...\n", url);
    
    while (1) {
        check_website(url);
        sleep(CHECK_INTERVAL);
    }

    return 0;
}

void check_website(const char *url) {
    struct sockaddr_in server_addr;
    int sock;
    char request[512];
    char response[4096];

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return;
    }

    // Setting up server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(url); // Note that this is simplified for a real case! Use name resolution in production

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("%s is DOWN!\n", url);
        log_status(url, 0);
        close(sock);
        return;
    }

    // Send HTTP GET request
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", url);
    send(sock, request, strlen(request), 0);

    // Read the response
    recv(sock, response, sizeof(response) - 1, 0);
    response[sizeof(response) - 1] = '\0'; // Null-terminate the response

    printf("%s is UP! Response received.\n", url);
    log_status(url, 1);

    close(sock);
}

void log_status(const char *url, int status) {
    FILE *log_file;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    log_file = fopen("uptime_log.txt", "a");
    if (log_file == NULL) {
        perror("Could not open log file");
        return;
    }

    if (status) {
        fprintf(log_file, "[%04d-%02d-%02d %02d:%02d:%02d] %s is UP!\n", 
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, 
            tm.tm_hour, tm.tm_min, tm.tm_sec, url);
    } else {
        fprintf(log_file, "[%04d-%02d-%02d %02d:%02d:%02d] %s is DOWN!\n", 
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, 
            tm.tm_hour, tm.tm_min, tm.tm_sec, url);
    }

    fclose(log_file);
}