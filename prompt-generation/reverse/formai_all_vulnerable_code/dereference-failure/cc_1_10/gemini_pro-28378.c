//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// My Request Structure
typedef struct {
    char *method;
    char *path;
    char *version;
} Request;

// My Response Structure
typedef struct {
    int status_code;
    char *status_message;
    char *body;
} Response;

// My Server Configuration Structure
typedef struct {
    int port;
    char *root_dir;
} ServerConfig;

// My Server Context Structure
typedef struct {
    int sockfd;
    ServerConfig config;
} ServerContext;

// Function Prototypes
Request *parse_request(char *request);
Response *handle_request(Request *request, ServerContext *context);
void send_response(ServerContext *context, Response *response);
void start_server(ServerContext *context);

int main() {
    // Set up server configuration
    ServerConfig config;
    config.port = 8080;
    config.root_dir = ".";

    // Create server context
    ServerContext context;
    context.config = config;

    // Start the server
    start_server(&context);

    return 0;
}

void start_server(ServerContext *context) {
    // Create a socket
    context->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (context->sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set up server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(context->config.port);

    // Bind socket to server address
    if (bind(context->sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket to address");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(context->sockfd, 5) < 0) {
        perror("Error listening for incoming connections");
        exit(1);
    }

    // Accept incoming connections and handle requests
    while (1) {
        // Accept incoming connection
        int client_sockfd;
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        client_sockfd = accept(context->sockfd, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_sockfd < 0) {
            perror("Error accepting incoming connection");
            continue;
        }

        // Receive request from client
        char request[1024];
        int n = recv(client_sockfd, request, sizeof(request), 0);
        if (n < 0) {
            perror("Error receiving request from client");
            close(client_sockfd);
            continue;
        }

        // Parse request
        Request *request_struct = parse_request(request);

        // Handle request
        Response *response = handle_request(request_struct, context);

        // Send response to client
        send_response(context, response);

        // Close client socket
        close(client_sockfd);
    }
}

Request *parse_request(char *request) {
    // Allocate memory for request structure
    Request *request_struct = malloc(sizeof(Request));

    // Parse method
    char *method_end = strchr(request, ' ');
    if (method_end == NULL) {
        request_struct->method = NULL;
    } else {
        *method_end = '\0';
        request_struct->method = strdup(request);
    }

    // Parse path
    char *path_start = method_end == NULL ? request : method_end + 1;
    char *path_end = strchr(path_start, ' ');
    if (path_end == NULL) {
        request_struct->path = NULL;
    } else {
        *path_end = '\0';
        request_struct->path = strdup(path_start);
    }

    // Parse version
    char *version_start = path_end == NULL ? NULL : path_end + 1;
    if (version_start == NULL) {
        request_struct->version = NULL;
    } else {
        request_struct->version = strdup(version_start);
    }

    return request_struct;
}

Response *handle_request(Request *request, ServerContext *context) {
    // Allocate memory for response structure
    Response *response = malloc(sizeof(Response));

    // Check if request is valid
    if (request->method == NULL || request->path == NULL || request->version == NULL) {
        response->status_code = 400;
        response->status_message = "Bad Request";
        response->body = NULL;
        return response;
    }

    // Check if request method is supported
    if (strcmp(request->method, "GET") != 0) {
        response->status_code = 405;
        response->status_message = "Method Not Allowed";
        response->body = NULL;
        return response;
    }

    // Get file path from request path
    char file_path[1024];
    snprintf(file_path, sizeof(file_path), "%s%s", context->config.root_dir, request->path);

    // Check if file exists
    if (access(file_path, F_OK) != 0) {
        response->status_code = 404;
        response->status_message = "Not Found";
        response->body = NULL;
        return response;
    }

    // Read file into response body
    FILE *file = fopen(file_path, "rb");
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    char *file_body = malloc(file_size + 1);
    fread(file_body, file_size, 1, file);
    fclose(file);
    file_body[file_size] = '\0';
    response->status_code = 200;
    response->status_message = "OK";
    response->body = file_body;
    return response;
}

void send_response(ServerContext *context, Response *response) {
    // Create response header
    char header[1024];
    snprintf(header, sizeof(header), "HTTP/1.1 %d %s\r\nContent-Length: %ld\r\n\r\n", response->status_code, response->status_message, strlen(response->body));

    // Send response header
    send(context->sockfd, header, strlen(header), 0);

    // Send response body
    send(context->sockfd, response->body, strlen(response->body), 0);
}