//Falcon2-11B DATASET v1.0 Category: Building a XML Parser ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure to hold the parsed XML
typedef struct {
    char* elementName;
    char** elementValues;
    int numElements;
} XmlElement;

// Function to parse the XML input file into memory
XmlElement* parseXmlFile(const char* filename) {
    
    // Open the file
    FILE* fp = fopen(filename, "rb");
    
    if (!fp) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Initialize the output structure
    XmlElement* result = malloc(sizeof(XmlElement));
    result->numElements = 0;
    
    // Read through the lines of the file until we hit EOF
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        
        // Skip comments and blank lines
        if (line[0] == '!' || strncmp(line, "<?", 3) == 0)
            continue;
        
        // Check if this line starts a new element
        if (strncmp(line, "<", 1) == 0) {
            
            // Get the element name
            char* elementName = strchr(line, '>');
            elementName++;
            size_t len = strlen(elementName);
            char* newElementName = malloc(len + 1);
            strncpy(newElementName, elementName, len);
            newElementName[len] = '\0';
            
            // Allocate memory for the element values array
            result->elementValues = malloc(sizeof(char*));
            result->elementValues[result->numElements] = newElementName;
            result->numElements++;
        }
        else {
            
            // Add the value of the current element to its array
            char* value = strchr(line, '>');
            value++;
            size_t len = strlen(value);
            char* newValue = malloc(len + 1);
            strncpy(newValue, value, len);
            newValue[len] = '\0';
            result->elementValues[result->numElements] = newValue;
        }
    }
    
    // Close the file
    fclose(fp);
    
    // Return the parsed XML structure
    return result;
}

// Function to print the parsed XML
void printXml(XmlElement* xml) {
    for (int i = 0; i < xml->numElements; i++) {
        printf("<%s>%s</%s>\n", xml->elementValues[i], xml->elementValues[i], xml->elementValues[i]);
    }
}

int main() {
    
    // Parse the XML file
    XmlElement* parsedXml = parseXmlFile("example.xml");
    
    // Print the parsed XML
    printXml(parsedXml);
    
    // Free the memory used by the parsed XML structure
    free(parsedXml->elementValues);
    free(parsedXml);
    
    return 0;
}