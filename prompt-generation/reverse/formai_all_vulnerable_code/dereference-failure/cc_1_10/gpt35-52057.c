//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: safe
// C Simple HTTP Proxy Example Program
// Safe Style

#include <stdio.h> // Standard Input and Output Library
#include <stdlib.h> // Standard Library
#include <string.h> // String Library
#include <stdbool.h> // Boolean Library
#include <netinet/in.h> // Internet Address Library
#include <sys/socket.h> // Socket Library
#include <unistd.h> // Standard Symbolic Constants and Types Library

#define BUFFER_SIZE 4096 // Maximum Buffer Size

bool is_valid_ip_address(char *ip_address) { // Function to check if the given IP Address is valid or not
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ip_address, &(sa.sin_addr)) != 0;
}

int main(int argc, char *argv[]) { // Main Function
    if (argc != 3) { // Check if the number of arguments is proper
        printf("Usage: %s <proxy_port> <web_server_ip_address>\n", argv[0]); // Display Proper Usage and Exit
        exit(1);
    }

    char *proxy_port_string = argv[1];
    int proxy_port_number = atoi(proxy_port_string);
    if (proxy_port_number < 1024 || proxy_port_number > 65535) { // Check if the given Port Number is valid or not
        printf("Error: Invalid Proxy Port Number!\n"); // Display Error Message and Exit
        exit(1);
    }

    char *web_server_ip_address = argv[2];
    if (!is_valid_ip_address(web_server_ip_address)) { // Check if the given IP Address is valid or not
        printf("Error: Invalid Web Server IP Address!\n"); // Display Error Message and Exit
        exit(1);
    }

    int server_proxy_socket = socket(AF_INET, SOCK_STREAM, 0); // Create a Socket for the Proxy Server
    if (server_proxy_socket < 0) { // Check if the Socket Creation is successful or not
        printf("Error: Socket Creation Failed!\n"); // Display Error Message and Exit
        exit(1);
    }
    
    struct sockaddr_in server_proxy_address, client_proxy_address; // Proxy Server Address and Client Proxy Address
    bzero(&server_proxy_address, sizeof(server_proxy_address)); // Set the Server Proxy Address to 0
    server_proxy_address.sin_family = AF_INET; // Set the Server Proxy Address Family to IPv4
    server_proxy_address.sin_addr.s_addr = htonl(INADDR_ANY); // Convert the IP Address to Network Byte Order
    server_proxy_address.sin_port = htons(proxy_port_number); // Convert the Port Number to Network Byte Order

    int bind_result = bind(server_proxy_socket, (struct sockaddr *)&server_proxy_address, sizeof(server_proxy_address)); // Bind the Server Proxy Socket to the Address
    if (bind_result < 0) { // Check if the Binding is successful or not
        printf("Error: Binding Failed!\n"); // Display Error Message and Exit
        exit(1); 
    }

    int listen_result = listen(server_proxy_socket, 10); // Listen for incoming connections
    if (listen_result < 0) { // Check if the Listening is successful or not
        printf("Error: Listening Failed!\n"); // Display Error Message and Exit
        exit(1);
    }

    printf("Waiting for incoming connections...\n");

    while (1) { // Infinite Loop to Handle Connections
        socklen_t client_address_length = sizeof(client_proxy_address); // Length of the Client Proxy Address
        int client_proxy_socket = accept(server_proxy_socket, (struct sockaddr *)&client_proxy_address, &client_address_length); // Accept the incoming connection
        if (client_proxy_socket < 0) { // Check if the Accepting is successful or not
            printf("Error: Accepting Failed!\n"); // Display Error Message and Skip
            continue;
        }

        char request_buffer[BUFFER_SIZE], response_buffer[BUFFER_SIZE], *hostname, *message; // Incoming Request Buffer, Outgoing Response Buffer, Hostname and Message
        
        bzero(request_buffer, BUFFER_SIZE); // Set the Request Buffer to 0
        int request_bytes_count = recv(client_proxy_socket, request_buffer, BUFFER_SIZE, 0); // Receive the Incoming Request
        if (request_bytes_count < 0) { // Check if the Receiving is successful or not
            printf("Error: Receiving Request Failed!\n"); // Display Error Message and Skip
            continue;
        }

        printf("%s\n", request_buffer); // Print the Request

        hostname = strstr(request_buffer, "Host: "); // Searching for the Hostname
        if (hostname != NULL) { // Found the Hostname
            hostname += 6; // Remove the "Host: " from the beginning
            message = strchr(hostname, '\r'); // Searching for the End of Line
            if (message == NULL) { // Could not find, so invalid request
                printf("Error: Invalid Request!\n"); // Display Error Message and Skip
                continue;
            }
            *message = '\0'; // Terminate the Hostname
        } else { // Hostname not found, invalid request
            printf("Error: Invalid Request!\n"); // Display Error Message and Skip
            continue;
        }

        printf("Hostname: %s\n", hostname); // Print the Hostname

        int server_web_socket = socket(AF_INET, SOCK_STREAM, 0); // Create a Socket for the Web Server
        if (server_web_socket < 0) { // Check if the Socket Creation is successful or not
            printf("Error: Socket Creation Failed!\n"); // Display Error Message and Skip
            continue;
        }

        struct sockaddr_in server_web_address; // Web Server Address
        bzero(&server_web_address, sizeof(server_web_address)); // Set the Server Web Address to 0
        server_web_address.sin_family = AF_INET; // Set the Server Web Address Family to IPv4
        server_web_address.sin_port = htons(80); // Set the Server Web Port to 80
        if (inet_pton(AF_INET, web_server_ip_address, &server_web_address.sin_addr) < 0) { // Convert the IP Address to Network Byte Order
            printf("Error: IP Address Conversion Failed!\n"); // Display Error Message and Skip
            continue;
        }

        int connect_result = connect(server_web_socket, (struct sockaddr *)&server_web_address, sizeof(server_web_address)); // Connect to the Web Server
        if (connect_result < 0) { // Check if the Connection is successful or not
            printf("Error: Connection to Web Server Failed!\n"); // Display Error Message and Skip
            continue;
        }

        sprintf(response_buffer, "GET / HTTP/1.0\r\nHost: %s\r\n\r\n", hostname); // Prepare the Request for Web Server
        int request_length = strlen(response_buffer); // Request Length
        int send_result = send(server_web_socket, response_buffer, request_length, 0); // Send the Request to the Web Server
        if (send_result < 0) { // Check if the Sending is successful or not
            printf("Error: Sending Request Failed!\n"); // Display Error Message and Skip
            continue;
        }

        bzero(response_buffer, BUFFER_SIZE); // Set the Response Buffer to 0
        int response_bytes_count = recv(server_web_socket, response_buffer, BUFFER_SIZE, 0); // Receive the Response from the Web Server
        if (response_bytes_count < 0) { // Check if the Receiving is successful or not
            printf("Error: Receiving Response Failed!\n"); // Display Error Message and Skip
            continue;
        }

        printf("%s\n", response_buffer); // Print the Response

        send_result = send(client_proxy_socket, response_buffer, response_bytes_count, 0); // Send the Response to the Client through Proxy Server
        if (send_result < 0) { // Check if the Sending is successful or not
            printf("Error: Sending Response Failed!\n"); // Display Error Message and Skip
            continue;
        }

        close(client_proxy_socket); // Close the Client Proxy Socket
        close(server_web_socket); // Close the Server Web Socket
    }
    
    close(server_proxy_socket); // Close the Server Proxy Socket

    return 0; // Return Success
}