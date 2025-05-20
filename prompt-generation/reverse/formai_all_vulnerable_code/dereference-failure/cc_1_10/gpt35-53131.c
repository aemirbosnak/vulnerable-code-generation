//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <curl/curl.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080

// Function that fetches the response from the given URL using CURL.
char *get_response(char *url)
{
    CURL *curl;
    CURLcode res;
    char *response = malloc(sizeof(char) * 10000);

    // Initialize curl session.
    curl = curl_easy_init();
    if (curl)
    {
        // Set the URL option.
        curl_easy_setopt(curl, CURLOPT_URL, url);
        
        // Discard the body of the response.
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        
        // Set the write function to capture the header of the response.
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &fwrite);
        
        // Set the write data to be the response string we allocated.
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);
        
        // Perform the request.
        res = curl_easy_perform(curl);
        
        // Cleanup.
        curl_easy_cleanup(curl);
    }

    return response;
}

// Function to send the given message to all the connected clients.
void broadcast(int *sockets, int max_index, char *message)
{
    for (int i = 0; i < max_index; i++)
    {
        if (sockets[i] > 0)
        {
            write(sockets[i], message, strlen(message));
        }
    }
}

int main()
{
    int server_fd, new_socket, max_index = 0, opt = 1;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int sockets[10] = {0};
    char *response;
    time_t start_time, current_time;

    // Create a TCP socket and bind it to the given port.
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
    {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Listening on port %d...\n", PORT);

    while (true)
    {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
        {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        char *message = "Connected!";

        // Add the new socket to the list of sockets.
        for (int i = 0; i < 10; i++)
        {
            if (sockets[i] == 0)
            {
                sockets[i] = new_socket;
                printf("New client connected, socket fd is %d, ip is : %s, port : %d\n", new_socket, inet_ntoa(address.sin_addr), ntohs(address.sin_port));
                write(new_socket, message, strlen(message));
                break;
            }
        }

        // Check if any of the URLs we are monitoring are down.
        char *urls[] = {"https://www.google.com", "https://www.yahoo.com", "https://www.reddit.com", "https://www.facebook.com"};
        int num_urls = sizeof(urls) / sizeof(urls[0]);
        for (int i = 0; i < num_urls; i++)
        {
            response = get_response(urls[i]);

            // If the response code is not in the 2xx range, print a message to the console and broadcast it to all connected clients.
            if (strncmp(response, "HTTP/1.1 2", 10) != 0)
            {
                printf("%s is down!\n", urls[i]);
                broadcast(sockets, max_index, "Alert: A website is down!");
            }
        }
        
        // Sleep for 5 seconds before checking again.
        sleep(5);
    }

    return 0;
}