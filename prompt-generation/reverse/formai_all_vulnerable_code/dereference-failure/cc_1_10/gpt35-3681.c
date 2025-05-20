//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define PORT 80
#define MAX_RESPONSE_SIZE 1024
#define INTERVAL_MINS 5
#define MAX_FAILED_ATTEMPTS 3

struct Response {
    char* header;
    char* data;
    int status_code;
};

struct Website {
    char* name;
    char* ip_address;
    struct Response last_response;
    int failed_attempts;
};

void update_status(struct Website* site);
int send_request(int sock_fd, char* request);
struct Response receive_response(int sock_fd);
void print_response(struct Response response);
void display_status(struct Website site);
void notify(struct Website site);

int main(int argc, char *argv[]) {
    struct Website site;
    site.name = "example.com";
    site.ip_address = "93.184.216.34";

    while(1) {
        update_status(&site);
        display_status(site);

        if(site.failed_attempts >= MAX_FAILED_ATTEMPTS) {
            notify(site);
            site.failed_attempts = 0;
        }

        sleep(INTERVAL_MINS * 60);
    }

    return 0;
}

void update_status(struct Website* site) {
    int sock_fd;
    char request[MAX_RESPONSE_SIZE];
    struct sockaddr_in server_address;

    if((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        fprintf(stderr, "Socket creation error");
        exit(EXIT_FAILURE);
    }

    if(inet_pton(AF_INET, site->ip_address, &server_address.sin_addr)<= 0) {
        fprintf(stderr, "Invalid address / Address not supported");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    if(connect(sock_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Connection Failed");
        exit(EXIT_FAILURE);
    }

    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", site->name);

    if(send_request(sock_fd, request) < 0) {
        fprintf(stderr, "Failed to send request");
        exit(EXIT_FAILURE);
    }

    site->last_response = receive_response(sock_fd);

    if(site->last_response.status_code != 200) {
        site->failed_attempts++;
    } else {
        site->failed_attempts = 0;
    }

    close(sock_fd);
}

int send_request(int sock_fd, char* request) {
    return send(sock_fd, request, strlen(request), 0);
}

struct Response receive_response(int sock_fd) {
    char* response_header = (char*)malloc(MAX_RESPONSE_SIZE * sizeof(char));
    char* response_data = (char*)malloc(MAX_RESPONSE_SIZE * sizeof(char));
    char buffer[MAX_RESPONSE_SIZE];
    int bytes_received, total_bytes_received = 0;
    struct Response response;
    response.header = response_header;
    response.data = response_data;

    do {
        bytes_received = recv(sock_fd, buffer, MAX_RESPONSE_SIZE - 1, 0);
        if(bytes_received < 0) {
            fprintf(stderr, "Failed to receive response");
            exit(EXIT_FAILURE);
        }
        buffer[bytes_received] = '\0';

        if(total_bytes_received == 0) {
            // Copy the first line of the header (status line) and extract the status code
            sscanf(buffer, "%[^\r\n]", response.header);
            sscanf(response.header, "HTTP/1.1 %d", &response.status_code);
        }

        total_bytes_received += bytes_received;

        if(total_bytes_received > MAX_RESPONSE_SIZE) {
            fprintf(stderr, "Response exceeds maximum size");
            exit(EXIT_FAILURE);
        }

        // concatenate the remaining data to the response data
        strcat(response.data, buffer);
    } while(bytes_received > 0);

    return response;
}

void display_status(struct Website site) {
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    printf("%02d:%02d:%02d | %s | %s\n", tm->tm_hour, tm->tm_min, tm->tm_sec, site.name, site.last_response.status_code == 200 ? "UP" : "DOWN");
}

void notify(struct Website site) {
    printf("Site %s is down! Failed attempts: %d\n", site.name, site.failed_attempts);
}