//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: futuristic
// Aegis: The Sentinel of Digital Realms

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <fcntl.h>

// Constants
#define BUFFER_SIZE 4096
#define DOMAIN_SIZE 256

// Structs representing entities in the digital realm
typedef struct Website {
    char domain[DOMAIN_SIZE];
    int port;
} Website;

typedef struct MonitoringTask {
    Website website;
    int interval;
} MonitoringTask;

// Function Declarations
Website* createWebsite(char* domain, int port);
MonitoringTask* createMonitoringTask(Website* website, int interval);
int isWebsiteUp(Website* website);
void monitorWebsite(MonitoringTask* task);

// Main Function: Orchestrating the Digital Watchdog
int main() {

    // Genesis: Creating the Monitoring Entities
    Website* website1 = createWebsite("sentinel.com", 80);
    Website* website2 = createWebsite("nexus.ai", 443);

    MonitoringTask* task1 = createMonitoringTask(website1, 30);
    MonitoringTask* task2 = createMonitoringTask(website2, 60);

    // Infinite Vigilance: Monitoring the Cyberverse
    while(1) {
        // Dispatching Monitoring Agents
        monitorWebsite(task1);
        monitorWebsite(task2);

        // Maintaining Vigilance Intervals
        sleep(1);
    }

    return 0;
}

// Function to Create a Website Entity
Website* createWebsite(char* domain, int port) {
    Website* website = malloc(sizeof(Website));
    strcpy(website->domain, domain);
    website->port = port;

    return website;
}

// Function to Create a Monitoring Task
MonitoringTask* createMonitoringTask(Website* website, int interval) {
    MonitoringTask* task = malloc(sizeof(MonitoringTask));
    task->website = *website;
    task->interval = interval;

    return task;
}

// Function to Check Website Availability
int isWebsiteUp(Website* website) {
    int sockfd, ret;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    // Establishing Connection to the Website
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
        return -1;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(website->port);
    serv_addr.sin_addr.s_addr = inet_addr(website->domain);

    ret = connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if(ret < 0) {
        close(sockfd);
        return -1;
    }

    // Sending a Probe to the Website
    strcpy(buffer, "GET / HTTP/1.1\r\nHost: ");
    strcat(buffer, website->domain);
    strcat(buffer, "\r\n\r\n");

    ret = send(sockfd, buffer, strlen(buffer), 0);
    if(ret < 0) {
        close(sockfd);
        return -1;
    }

    // Receiving Response from the Website
    ret = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if(ret < 0) {
        close(sockfd);
        return -1;
    }

    close(sockfd);

    // Analyzing Response to Determine Website Status
    if(strstr(buffer, "HTTP/1.1 200 OK"))
        return 1;
    
    return 0;
}

// Function to Monitor a Website
void monitorWebsite(MonitoringTask* task) {
    if(isWebsiteUp(&task->website))
        printf("Website %s is up!\n", task->website.domain);
    else
        printf("Website %s is down!\n", task->website.domain);

    sleep(task->interval);
}