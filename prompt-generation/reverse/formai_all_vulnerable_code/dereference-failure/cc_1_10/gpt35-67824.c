//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define PORT_NUMBER 8000
#define MESSAGE_SIZE 1024

char *get_current_time() {
    time_t raw_time;
    struct tm* time_info;
    char* buffer;

    time(&raw_time);
    time_info = localtime(&raw_time);

    buffer = malloc(sizeof(char) * 80);
    strftime(buffer, 80, "%x %I:%M:%S %p", time_info);

    return buffer;
}

int main(int argc, char* argv[]) {
    int socket_fd, port_number, num_bytes;
    struct sockaddr_in server_address;
    struct hostent* server;
    char* message;
    char response[MESSAGE_SIZE];
    clock_t start_time, end_time;
    double duration;
    
    if(argc < 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    port_number = PORT_NUMBER;
    server = gethostbyname(argv[1]);
    
    if(server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(1);
    }

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    if(socket_fd < 0) {
        fprintf(stderr, "Error: failed to create socket\n");
        exit(1);
    }

    bzero((char*) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(port_number);
    
    if(connect(socket_fd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Error: failed to connect to server\n");
        exit(1);
    }

    message = "Hello, world!";
    start_time = clock();

    for(int i = 0; i < 1000; i++) {
        num_bytes = write(socket_fd, message, strlen(message));
        
        if(num_bytes < 0) {
            fprintf(stderr, "Error: failed to send message\n");
            exit(1);
        }

        bzero(response, MESSAGE_SIZE);
        num_bytes = read(socket_fd, response, MESSAGE_SIZE);

        if(num_bytes < 0) {
            fprintf(stderr, "Error: failed to receive response\n");
            exit(1);
        }

        printf("Response #%d received at %s: %s\n", i+1, get_current_time(), response);
    }

    end_time = clock();
    duration = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Test completed in %.3f seconds\n", duration);

    close(socket_fd);

    return 0;
}