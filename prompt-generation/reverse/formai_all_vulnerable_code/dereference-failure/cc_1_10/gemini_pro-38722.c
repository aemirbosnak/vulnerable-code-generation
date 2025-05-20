//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
// Let's play a guessing game.
// I'll give you a hint: It's something that connects computers.

char *guess_the_word(char *buffer) {
    char *guess = NULL;
    
    // --- --- --- --- --- ---
    // We'll start with a simple one.
    // Think of something that has a prefix "net".
    
    if (strncmp(buffer, "net", 3) == 0) {
        guess = "Network";
    }
    
    // --- --- --- --- --- ---
    // Now let's try something more specific.
    // Think of a type of network that maps out the connections between nodes.
    
    else if (strcmp(buffer, "Network Topology Mapper") == 0) {
        guess = "Network Topology Mapper";
    }
    
    // --- --- --- --- --- ---
    // What about a tool that can show you the physical layout of a network?
    
    else if (strcmp(buffer, "Network Diagram") == 0) {
        guess = "Network Diagram";
    }

    return guess;
}

// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
// Now, let's write a function to create a network topology map.
// We'll start with a simple one that just prints out the IP addresses of the local hosts.

void create_network_topology_map() {
    // --- --- --- --- --- ---
    // First, we need to get the list of local hosts.
    
    struct hostent *host_list = gethostbyname("localhost");
    if (host_list == NULL) {
        perror("gethostbyname");
        return;
    }
    
    // --- --- --- --- --- ---
    // Now, let's print out the IP addresses of each host.
    
    printf("Local hosts:\n");
    for (int i = 0; host_list->h_addr_list[i] != NULL; i++) {
        struct in_addr *addr = (struct in_addr *)host_list->h_addr_list[i];
        printf("  %s\n", inet_ntoa(*addr));
    }
}

// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
// Finally, let's put it all together and create a simple network topology mapper.

int main() {
    char buffer[1024];
    
    // --- --- --- --- --- ---
    // First, we'll ask the user to guess the word.
    
    printf("Guess the word: ");
    fgets(buffer, sizeof(buffer), stdin);
    
    // --- --- --- --- --- ---
    // Check if the user's guess is correct.
    
    char *guess = guess_the_word(buffer);
    if (guess == NULL) {
        printf("Sorry, that's not the correct answer.\n");
        return 1;
    }
    
    // --- --- --- --- --- ---
    // If the user guessed correctly, we'll create the network topology map.
    
    printf("Congratulations! You guessed correctly.\n");
    create_network_topology_map();
    
    return 0;
}