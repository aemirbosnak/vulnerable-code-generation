//FormAI DATASET v1.0 Category: Firewall ; Style: cheerful
// Welcome to the Happy Firewall program!
// This program will protect your system with a big smile :)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_IP_LENGTH 15
#define MAX_PORTS 65535

// Declarations
void displayWelcomeMessage(); 
void checkArguments(int argc); 
void validateIP(char* ip); 
void validatePort(int port); 
void blockIP(char* ip); 
void blockPort(int port); 

// Global Variables
int blocked_ports[MAX_PORTS] = {0}; 

// Main Function
int main(int argc, char* argv[]) 
{ 
    // Display welcome message
    displayWelcomeMessage();
    
    // Check number of arguments
    checkArguments(argc);

    // Loop through arguments 
    for(int i = 1; i < argc; i++) 
    { 
        // Check if argument is an IP address 
        if(strstr(argv[i], ".") != NULL) 
        { 
            validateIP(argv[i]); 
            blockIP(argv[i]); 
        } 
        // Check if argument is a port number
        else 
        { 
            int port = atoi(argv[i]); 
            validatePort(port); 
            blockPort(port); 
        } 
    }

    // Exit program with happiness 
    printf("\nFirewall is happy! Your system is now protected with a big smile :)\n"); 
    return 0; 
} 

// Function to display welcome message
void displayWelcomeMessage() 
{ 
    printf("Hello! Welcome to the Happy Firewall program!\n"); 
    printf("This program will protect your system with a big smile :)\n\n"); 
} 

// Function to check number of arguments
void checkArguments(int argc) 
{ 
    if(argc == 1) 
    { 
        printf("You need to provide at least one IP address or port number to block.\n"); 
        printf("Syntax: ./happy_firewall [IP address or port number]\n"); 
        exit(0); 
    } 
} 

// Function to validate IP address
void validateIP(char* ip) 
{ 
    int num, dots = 0; 
    char* start; 
    start = ip; 
    while (*start) 
    { 
        if (*start == '.') 
            dots++; 
        start++; 
    } 
    if (dots != 3) 
    { 
        printf("Invalid IP address! Please provide a valid IP address.\n"); 
        exit(0); 
    } 
    if (sscanf(ip, "%d.%d.%d.%d", &num, &num, &num, &num) != 4) 
    { 
        printf("Invalid IP address! Please provide a valid IP address.\n"); 
        exit(0); 
    } 
} 

// Function to validate port number
void validatePort(int port) 
{ 
    if(port < 0 || port > MAX_PORTS) 
    { 
        printf("Invalid port number! Please provide a valid port number between 0 and 65535.\n"); 
        exit(0); 
    } 
} 

// Function to block IP address
void blockIP(char* ip) 
{ 
    printf("Blocking IP address %s...\n", ip); 
    // Here goes the code to block IP address 
    printf("IP address %s has been blocked!\n\n", ip); 
} 

// Function to block port number
void blockPort(int port) 
{ 
    if(blocked_ports[port] == 1) 
    { 
        printf("Port number %d has already been blocked!\n\n", port); 
        return; 
    } 
    printf("Blocking port number %d...\n", port); 
    // Here goes the code to block port number 
    printf("Port number %d has been blocked!\n\n", port); 
    blocked_ports[port] = 1; 
}