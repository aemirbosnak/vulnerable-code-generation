//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 2048 // Define buffer size for incoming data
#define PARANOID_MODE 1 // Set to 1 for paranoid mode, 0 for normal mode

int connect_to_server(char *host, int port);
char *get_request_header(char *request, char *header_key);
int modify_request(char *request, char *new_host, int new_port);
int send_data(int socket, char *data, size_t len);
int receive_data(int socket, char **output_data);

int main(int argc, char *argv[]) {
    
    // Check if program has received correct amount of arguments
    if (argc != 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    int server_socket = connect_to_server(argv[1], atoi(argv[2]));

    // Read incoming data from client
    char request_buffer[BUFFER_SIZE];
    memset(request_buffer, 0, BUFFER_SIZE);
    int num_bytes_received = 0;
    while ((num_bytes_received = recv(server_socket, request_buffer, BUFFER_SIZE - 1, 0)) > 0) {

        // Check if incoming data contains a GET request
        char *get_request_start = strstr(request_buffer, "GET");
        if (get_request_start != NULL) {

            // If paranoid mode is enabled, modify the request to only retrieve headers
            if (PARANOID_MODE) {
                modify_request(request_buffer, NULL, 0);
            }

            // Extract the host and port from the request header
            char *request_host = get_request_header(request_buffer, "Host:");
            int request_port = atoi(strchr(request_host, ':') + 1);

            // Connect to the requested server
            int target_socket = connect_to_server(request_host, request_port);

            // Forward the modified request to the target server
            send_data(target_socket, request_buffer, strlen(request_buffer));

            // Receive the target server's response
            char *response_data = NULL;
            int response_bytes_received = receive_data(target_socket, &response_data);

            // Check if the response contains a "Content-Type" header
            char *content_type_header = get_request_header(response_data, "Content-Type:");
            if (content_type_header != NULL) {

                // If paranoid mode, only send back the content type header
                if (PARANOID_MODE) {
                    send_data(server_socket, content_type_header, strlen(content_type_header));
                } else {

                    // Otherwise, forward the entire response back to the client
                    send_data(server_socket, response_data, response_bytes_received);

                }
            }

            // Clean up memory
            close(target_socket);
            free(request_host);
            free(response_data);

        } else {

            // Forward the data back to the client if it does not contain a GET request
            send_data(server_socket, request_buffer, strlen(request_buffer));

        }

        // Clear buffer for next incoming data
        memset(request_buffer, 0, BUFFER_SIZE);

    }

    // Clean up socket
    close(server_socket);

    return 0;
}

int connect_to_server(char *host, int port) {

    // Create a socket object
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Failed to create socket\n");
        exit(EXIT_FAILURE);
    }

    // Define server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &server_address.sin_addr) <= 0) {
        printf("Error: Invalid address\n");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error: Failed to connect to server\n");
        exit(EXIT_FAILURE);
    }

    return sock;
}

char *get_request_header(char *request, char *header_key) {

    // Search for the header within the request
    char *header_start = strstr(request, header_key);

    // Return NULL if header is not found
    if (header_start == NULL) {
        return NULL;
    }

    // Skip the header key and the white space characters
    header_start += strlen(header_key);
    while (*header_start == ' ') {
        header_start++;
    }

    // Find the end of the header
    int header_length = 0;
    while (header_start[header_length] != '\r' && header_start[header_length] != '\n' && header_start[header_length] != 0) {
        header_length++;
    }

    // Allocate a new string for the header data
    char *header_value = malloc(header_length + 1);
    memcpy(header_value, header_start, header_length);
    header_value[header_length] = 0;

    return header_value;
}

int modify_request(char *request, char *new_host, int new_port) {

    // Search for the request header
    char *header_start = strstr(request, "GET ");

    // Return 1 if header is not found
    if (header_start == NULL) {
        return 1;
    }

    // Skip the "GET " characters
    header_start += 4;

    // Find the end of the request URL
    int url_length = 0;
    while (header_start[url_length] != ' ' && header_start[url_length] != '\r' && header_start[url_length] != '\n' && header_start[url_length] != 0) {
        url_length++;
    }

    // Remember the original URL and overwrite it with a new one
    char *original_url = malloc(url_length + 1);
    memcpy(original_url, header_start, url_length);
    original_url[url_length] = 0;

    // Insert the new HTTP host header if requested
    char new_request[BUFFER_SIZE];
    memset(new_request, 0, BUFFER_SIZE);
    if (new_host != NULL) {

        // Copy the GET header and the new HTTP host header to the new request string
        snprintf(new_request, BUFFER_SIZE, "GET %s HTTP/1.0\r\nHost: %s:%d\r\n", original_url, new_host, new_port);

        // Copy the rest of the request headers to the new request string
        char *line_end = strstr(header_start, "\r\n") + 2;
        while (*line_end != '\r' && *line_end != '\n' && *line_end != 0) {
            char *next_line_end = strstr(line_end, "\r\n") + 2;
            strncat(new_request, line_end, next_line_end - line_end);
            line_end = next_line_end;
        }

    } else {

        // Copy the entire request to the new request string
        sprintf(new_request, "%s", request);

    }

    // Replace the original request with the new one
    memcpy(request, new_request, BUFFER_SIZE);

    // Clean up memory
    free(original_url);

    return 0;
}

int send_data(int socket, char *data, size_t len) {

    // Write the data to the socket and check for errors
    int num_bytes_sent = send(socket, data, len, 0);
    if (num_bytes_sent < 0) {
        printf("Error: Failed to send data\n");
        close(socket);
        exit(EXIT_FAILURE);
    }

    return num_bytes_sent;
}

int receive_data(int socket, char **output_data) {

    // Allocate initial buffer for incoming data
    char response_buffer[BUFFER_SIZE];
    memset(response_buffer, 0, BUFFER_SIZE);
    int total_bytes_received = 0;

    // Loop until we have received all data from the socket
    int num_bytes_received;
    while ((num_bytes_received = recv(socket, response_buffer + total_bytes_received, BUFFER_SIZE - total_bytes_received - 1, 0)) > 0) {

        // Add the newly received data to the total byte count
        total_bytes_received += num_bytes_received;

        // Check if we have received the entire response
        if (strstr(response_buffer, "\r\n\r\n") != NULL) {

            // Allocate a new string for the response data
            *output_data = malloc(total_bytes_received + 1);
            memcpy(*output_data, response_buffer, total_bytes_received);
            (*output_data)[total_bytes_received] = 0;

            return total_bytes_received;

        }

    }

    // Check for errors
    if (num_bytes_received < 0) {
        printf("Error: Failed to receive data\n");
        close(socket);
        exit(EXIT_FAILURE);
    }

    return 0;
}