//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Metadata structure
typedef struct {
    char *name;
    char *email;
    char *ip_address;
    char *user_agent;
    time_t timestamp;
} metadata_t;

// Create a new metadata object
metadata_t *new_metadata(char *name, char *email, char *ip_address, char *user_agent, time_t timestamp) {
    metadata_t *metadata = malloc(sizeof(metadata_t));
    metadata->name = strdup(name);
    metadata->email = strdup(email);
    metadata->ip_address = strdup(ip_address);
    metadata->user_agent = strdup(user_agent);
    metadata->timestamp = timestamp;
    return metadata;
}

// Free a metadata object
void free_metadata(metadata_t *metadata) {
    free(metadata->name);
    free(metadata->email);
    free(metadata->ip_address);
    free(metadata->user_agent);
    free(metadata);
}

// Print a metadata object
void print_metadata(metadata_t *metadata) {
    printf("Name: %s\n", metadata->name);
    printf("Email: %s\n", metadata->email);
    printf("IP Address: %s\n", metadata->ip_address);
    printf("User Agent: %s\n", metadata->user_agent);
    printf("Timestamp: %s\n", ctime(&metadata->timestamp));
}

// Main function
int main(int argc, char **argv) {
    // Create a new metadata object
    metadata_t *metadata = new_metadata("John Doe", "johndoe@example.com", "127.0.0.1", "Mozilla/5.0", time(NULL));

    // Print the metadata object
    print_metadata(metadata);

    // Free the metadata object
    free_metadata(metadata);

    return 0;
}