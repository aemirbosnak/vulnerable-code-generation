//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: standalone
#include <stdio.h>
#include <string.h>
#define INPUT_SIZE 200

char* sanitizeURL(char* input) {
    const char* blacklist[] = {"script", "alert", "javascript"}; // list of blacklisted keywords
    const char* whitelist[] = {"https", "http"}; // list of whitelisted protocols
    
    char* output = malloc(INPUT_SIZE); // dynamic allocation of memory
    strncpy(output, input, INPUT_SIZE - 1);
    output[INPUT_SIZE - 1] = '\0';
    
    char* token = strtok(output, "/"); // break string into tokens separated by /
    int is_valid_protocol = 0; // flag to check if input contains a valid protocol
    
    // check if input contains a valid protocol
    for(int i = 0; i < sizeof(whitelist)/sizeof(whitelist[0]); ++i) {
        if(strncmp(token, whitelist[i], strlen(whitelist[i])) == 0) {
            is_valid_protocol = 1;
            break;
        }
    }
    
    if(is_valid_protocol) {
        // process remaining tokens
        while(token != NULL) {
            int is_blacklisted = 0; // flag to check if token contains a blacklisted keyword
            
            // check if token contains a blacklisted keyword
            for(int i = 0; i < sizeof(blacklist)/sizeof(blacklist[0]); ++i) {
                if(strstr(token, blacklist[i]) != NULL) {
                    is_blacklisted = 1;
                    break;
                }
            }
            
            if(!is_blacklisted) {
                strcat(output, "/");
                strcat(output, token);
            }
            
            token = strtok(NULL, "/"); // move to next token
        }
    }
    else {
        output[0] = '\0'; // if input doesn't contain a valid protocol, output an empty string
    }
    
    return output;
}

int main() {
    char input[INPUT_SIZE] = "https://www.example.com/script/path/alert.html"; // test input
    char* output = sanitizeURL(input); // call sanitizeURL function
    
    printf("Input: %s\n", input);
    printf("Output: %s\n", output);
    
    free(output); // free dynamically allocated memory
    
    return 0;
}