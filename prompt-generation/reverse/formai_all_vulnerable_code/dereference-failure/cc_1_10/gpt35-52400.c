//FormAI DATASET v1.0 Category: Browser Plugin ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/* Check if file exists */
bool fileExists(char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

/* Read file contents */
char* readFile(char *filename) {
    FILE *file = fopen(filename, "r");
    fseek(file, 0L, SEEK_END);
    long fileSize = ftell(file);
    char *content = (char*) malloc(fileSize + 1);
    rewind(file);
    fread(content, fileSize, 1, file);
    fclose(file);
    content[fileSize] = '\0';
    return content;
}

/* Write to file */
bool writeFile(char *filename, char *content) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        return false;
    }
    fputs(content, file);
    fclose(file);
    return true;
}

/* Check if string contains substring */
bool contains(char *string, char *substring) {
    return (strstr(string, substring) != NULL);
}

/* Main function */
int main() {

    char *filename = "/etc/my_browser_plugin.conf";   // Set the plugin configuration file path
    char *defaultContent = "enabled=true\n";          // Set the default plugin configuration
    
    // Create plugin configuration file if it doesn't exist
    if (!fileExists(filename)) {
        writeFile(filename, defaultContent);
    }
    
    // Read plugin configuration file
    char *content = readFile(filename);
    
    // Check if plugin is enabled
    if (contains(content, "enabled=true")) {
        // Do something if enabled
        printf("My browser plugin is enabled.\n");
    } else {
        // Do something else if disabled
        printf("My browser plugin is disabled.\n");
    }
    
    return 0;
}