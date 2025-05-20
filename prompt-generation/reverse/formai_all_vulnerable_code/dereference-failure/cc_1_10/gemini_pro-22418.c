//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Structure to store a single boot entry
typedef struct {
    char *name;
    char *path;
    int priority;
} boot_entry_t;

// Linked list to store all boot entries
typedef struct {
    boot_entry_t *entry;
    struct boot_list_t *next;
} boot_list_t;

// Global variables
boot_list_t *boot_list = NULL;

// Function to add a boot entry to the linked list
void add_boot_entry(char *name, char *path, int priority) {
    // Allocate memory for the new entry
    boot_entry_t *new_entry = malloc(sizeof(boot_entry_t));
    if (new_entry == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for new boot entry.\n");
        exit(1);
    }
    
    // Initialize the new entry
    new_entry->name = strdup(name);
    new_entry->path = strdup(path);
    new_entry->priority = priority;
    
    // Add the new entry to the linked list
    boot_list_t *new_node = malloc(sizeof(boot_list_t));
    if (new_node == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for new boot list node.\n");
        exit(1);
    }
    
    new_node->entry = new_entry;
    new_node->next = boot_list;
    boot_list = new_node;
}

// Function to read the boot configuration file and populate the linked list
void read_boot_config_file(char *filename) {
    // Open the boot configuration file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open boot configuration file '%s'.\n", filename);
        exit(1);
    }
    
    // Read the file line by line
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        // Parse the line
        char *name, *path, *priority;
        name = strtok(line, ":");
        path = strtok(NULL, ":");
        priority = strtok(NULL, "\n");
        if (name == NULL || path == NULL || priority == NULL) {
            fprintf(stderr, "Error: Invalid boot configuration file line: '%s'.\n", line);
            exit(1);
        }
        
        // Add the boot entry to the linked list
        add_boot_entry(name, path, atoi(priority));
    }
    
    // Close the file
    fclose(fp);
}

// Function to sort the linked list of boot entries by priority
void sort_boot_list() {
    // Iterate over the linked list
    boot_list_t *node = boot_list;
    while (node != NULL) {
        // Find the node with the highest priority
        boot_list_t *max_node = node;
        boot_list_t *max_prev_node = NULL;
        boot_list_t *prev_node = node;
        while (prev_node != NULL) {
            if (prev_node->entry->priority > max_node->entry->priority) {
                max_node = prev_node;
                max_prev_node = prev_node;
            }
            prev_node = prev_node->next;
        }
        
        // Swap the nodes
        if (max_node != node) {
            if (max_prev_node == NULL) {
                boot_list = max_node;
            } else {
                max_prev_node->next = max_node;
            }
            max_node->next = node;
            node->next = max_node;
        }
        
        // Move to the next node
        node = node->next;
    }
}

// Function to print the sorted linked list of boot entries
void print_boot_list() {
    // Iterate over the linked list
    boot_list_t *node = boot_list;
    while (node != NULL) {
        // Print the boot entry
        printf("%s: %s (%d)\n", node->entry->name, node->entry->path, node->entry->priority);
        
        // Move to the next node
        node = node->next;
    }
}

// Function to write the sorted linked list of boot entries to a new boot configuration file
void write_boot_config_file(char *filename) {
    // Open the new boot configuration file
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open new boot configuration file '%s'.\n", filename);
        exit(1);
    }
    
    // Iterate over the linked list
    boot_list_t *node = boot_list;
    while (node != NULL) {
        // Write the boot entry to the file
        fprintf(fp, "%s:%s:%d\n", node->entry->name, node->entry->path, node->entry->priority);
        
        // Move to the next node
        node = node->next;
    }
    
    // Close the file
    fclose(fp);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user specified a boot configuration file
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <boot configuration file>\n", argv[0]);
        exit(1);
    }
    
    // Read the boot configuration file
    read_boot_config_file(argv[1]);
    
    // Sort the boot list by priority
    sort_boot_list();
    
    // Print the sorted boot list
    printf("Sorted boot list:\n");
    print_boot_list();
    
    // Write the sorted boot list to a new boot configuration file
    write_boot_config_file("new_boot_config.txt");
    
    // Exit the program
    return 0;
}