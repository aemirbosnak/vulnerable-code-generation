//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of each metadata tag
#define MAX_TAG_LENGTH 10

// Define a metadata structure
typedef struct {
    char tag[MAX_TAG_LENGTH];
    char value[100];
} Metadata;

// Define a function to extract metadata from a given string
Metadata* extract_metadata(char* string, int* num_metadata) {
    // Initialize an array to store extracted metadata
    Metadata* metadata_arr = malloc(sizeof(Metadata));
    // Initialize a counter to keep track of number of metadata extracted
    int count_metadata = 0;
    
    // Loop through the input string and extract metadata tags and values
    for (int i = 0; i < strlen(string); i++) {
        // Check if current character is the start of a new metadata tag
        if (string[i] == '[') {
            // Initialize a temporary metadata struct 
            Metadata temp_metadata;
            // Initialize a tag index variable to keep track of tag length
            int tag_index = 0;
            i++; // Move past the starting '[' character
            
            // Loop through the next characters until the end of the tag is reached
            while (string[i] != ']') {
                // Check if tag length exceeds maximum tag length
                if (tag_index >= MAX_TAG_LENGTH) {
                    printf("Error: Tag length exceeds maximum length of %d.\n", MAX_TAG_LENGTH);
                    return NULL;
                }
                // Store the current character as part of the tag
                temp_metadata.tag[tag_index] = string[i];
                i++; // Move to the next character
                tag_index++; // Increment the tag index variable
            }
            // Add null terminator to the tag string
            temp_metadata.tag[tag_index] = '\0';
            i++; // Move past the ending ']' character
            
            // Initialize a value index variable to keep track of value length
            int value_index = 0;
            // Loop through the next characters until the start of the next metadata tag is reached
            while (string[i] != '[' && i < strlen(string)) {
                // Check if value length exceeds maximum value length
                if (value_index >= 100) {
                    printf("Error: Value length exceeds maximum length of 100.\n");
                    return NULL;
                }
                // Store the current character as part of the value
                temp_metadata.value[value_index] = string[i];
                i++; // Move to the next character
                value_index++; // Increment the value index variable
            }
            // Add null terminator to the value string
            temp_metadata.value[value_index] = '\0';
            
            // Append the extracted metadata to the metadata array
            metadata_arr[count_metadata] = temp_metadata;
            count_metadata++; // Increment the metadata counter
            
            // Increase the size of the metadata array if necessary
            if (count_metadata >= sizeof(metadata_arr)/sizeof(Metadata)) {
                metadata_arr = realloc(metadata_arr, sizeof(metadata_arr) + sizeof(Metadata));
            }
        }
    }
    // Set the output parameter to the final number of metadata extracted
    *num_metadata = count_metadata;
    // Return the extracted metadata array
    return metadata_arr;
}

// Define a main function to test metadata extraction
int main() {
    char input_string[1000] = "[title]My awesome title[author]John Doe[year]2021";
    int num_metadata = 0;
    Metadata* extracted_metadata = extract_metadata(input_string, &num_metadata);
    
    for (int i = 0; i < num_metadata; i++) {
        printf("Tag %d: %s\n", i + 1, extracted_metadata[i].tag);
        printf("Value %d: %s\n", i + 1, extracted_metadata[i].value);
    }
    return 0;
}