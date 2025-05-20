//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Custom data structure to store website and its status
typedef struct website {
  char *url;
  int status; // 0: down, 1: up
} website;

// Function to get IP address from domain name
char *get_ip_address(char *domain) {
  struct hostent *host = gethostbyname(domain);
  if (host == NULL) {
    printf("Error: Could not resolve hostname %s\n", domain);
    return NULL;
  }

  // Convert the first IP address to a string
  char *ip_address = inet_ntoa(*((struct in_addr *)host->h_addr));
  return strdup(ip_address);
}

// Function to check if a website is up
int check_website_up(char *ip_address) {
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    printf("Error: Could not create socket\n");
    return -1;
  }

  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(80);
  serv_addr.sin_addr.s_addr = inet_addr(ip_address);

  int connect_status = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
  if (connect_status == -1) {
    printf("Error: Could not connect to website at %s\n", ip_address);
    return 0;
  }

  close(sockfd);
  return 1;
}

// Function to monitor a list of websites and print their status
void monitor_websites(website *websites, int num_websites) {
  printf("=================================================\n");
  printf("Website Uptime Monitor\n");
  printf("=================================================\n\n");

  for (int i = 0; i < num_websites; i++) {
    website *website = &websites[i];

    // Get the IP address of the website
    char *ip_address = get_ip_address(website->url);
    if (ip_address == NULL) {
      continue;
    }

    // Check if the website is up
    int status = check_website_up(ip_address);
    free(ip_address);

    // Update the website status
    website->status = status;

    // Print the website status
    printf("%s: %s\n", website->url, status ? "Up" : "Down");
  }
}

int main() {
  // Initialize the list of websites
  website websites[] = {
    {url: "www.google.com", status: 0},
    {url: "www.facebook.com", status: 0},
    {url: "www.github.com", status: 0},
    {url: "www.amazon.com", status: 0},
    {url: "www.microsoft.com", status: 0},
  };
  int num_websites = sizeof(websites) / sizeof(websites[0]);

  // Monitor the websites and print their status
  monitor_websites(websites, num_websites);

  return 0;
}