//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_URLS 100
#define MAX_URL_LEN 1024

// Linked list of URLs to monitor
struct url_node {
    char url[MAX_URL_LEN];
    struct url_node *next;
};

// List of URLs to monitor
struct url_list {
    struct url_node *head;
    struct url_node *tail;
    int count;
};

// Create a new URL list
struct url_list *create_url_list() {
    struct url_list *list = malloc(sizeof(struct url_list));
    if (list == NULL) {
        perror("Error allocating memory for URL list");
        return NULL;
    }

    list->head = NULL;
    list->tail = NULL;
    list->count = 0;

    return list;
}

// Add a URL to the list
void add_url(struct url_list *list, char *url) {
    struct url_node *node = malloc(sizeof(struct url_node));
    if (node == NULL) {
        perror("Error allocating memory for URL node");
        return;
    }

    strcpy(node->url, url);
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
    } else {
        list->tail->next = node;
    }

    list->tail = node;
    list->count++;
}

// Free the URL list
void free_url_list(struct url_list *list) {
    struct url_node *node = list->head;
    while (node != NULL) {
        struct url_node *next = node->next;
        free(node);
        node = next;
    }

    free(list);
}

// Check if a URL is up
int is_url_up(char *url) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket");
        return 0;
    }

    // Set the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    if (inet_pton(AF_INET, url, &server_addr.sin_addr) == -1) {
        perror("Error converting URL to IP address");
        close(sockfd);
        return 0;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        close(sockfd);
        return 0;
    }

    // Send a request to the server
    char request[] = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
    if (write(sockfd, request, strlen(request)) == -1) {
        perror("Error sending request to server");
        close(sockfd);
        return 0;
    }

    // Read the response from the server
    char response[1024];
    int bytes_read = read(sockfd, response, 1024);
    close(sockfd);

    if (bytes_read == -1) {
        perror("Error reading response from server");
        return 0;
    }

    // Check the HTTP status code
    char *status_code = strstr(response, "HTTP/1.1 ");
    if (status_code == NULL) {
        return 0;
    }

    status_code += 9;
    int code = atoi(status_code);
    if (code >= 200 && code < 300) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char *argv[]) {
    // Create a new URL list
    struct url_list *list = create_url_list();

    // Add URLs to the list
    add_url(list, "www.example.com");
    add_url(list, "www.google.com");
    add_url(list, "www.facebook.com");

    // Check if the URLs are up
    struct url_node *node = list->head;
    while (node != NULL) {
        if (is_url_up(node->url)) {
            printf("%s is up\n", node->url);
        } else {
            printf("%s is down\n", node->url);
        }

        node = node->next;
    }

    // Free the URL list
    free_url_list(list);

    return 0;
}