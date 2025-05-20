//Falcon-180B DATASET v1.0 Category: System administration ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print a colorful message
void print_colorful_message(char* message, int color) {
    printf("\033[1;%dm%s\033[0m\n", color, message);
}

// Function to print a list of running processes
void print_process_list() {
    FILE* file = popen("ps -aux", "r");
    char line[256];
    while (fgets(line, 256, file)!= NULL) {
        printf("%s", line);
    }
    pclose(file);
}

// Function to print system information
void print_system_info() {
    printf("Operating System: ");
    system("uname -a");
    printf("\n");
    printf("CPU Usage: ");
    system("top -bn1 | grep 'Cpu(s)' | sed's/.*, *\\([0-9.]*\\)%* id.*/\\1/'");
    printf("\n");
    printf("Memory Usage: ");
    system("free -m");
    printf("\n");
}

// Function to print disk usage
void print_disk_usage() {
    system("df -h");
}

// Function to print network information
void print_network_info() {
    system("ifconfig");
}

// Main function
int main() {
    print_colorful_message("Welcome to the System Administration Tool!", 32);
    printf("\n");

    // Print system information
    print_colorful_message("System Information", 34);
    print_system_info();

    // Print disk usage
    print_colorful_message("Disk Usage", 36);
    print_disk_usage();

    // Print network information
    print_colorful_message("Network Information", 33);
    print_network_info();

    // Print list of running processes
    print_colorful_message("List of Running Processes", 35);
    print_process_list();

    return 0;
}