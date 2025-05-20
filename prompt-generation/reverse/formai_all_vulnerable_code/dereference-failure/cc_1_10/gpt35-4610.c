//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to hold data from the XML file
typedef struct XmlData {
    char name[50];
    char value[100];
    struct XmlData* next;   // Pointer to the next XML data
} XmlData;

// Method to process the XML file and store the data in the linked list
XmlData* processXml(char* xmlFilePath) {
    FILE* fp = fopen(xmlFilePath, "r");
    if (fp == NULL) {
        printf("Error opening XML file.\n");
        exit(1);
    }

    char line[150];
    XmlData* head = NULL;
    XmlData* current = NULL;
    while (fgets(line, sizeof(line), fp)) {
        // Check if this line contains XML data element
        char* start = strstr(line, "<");
        char* end = strstr(line, ">");
        if (start != NULL && end != NULL) {
            char name[50];
            char value[100];
            strncpy(name, start+1, end-start-1);  // Copy the XML element name
            name[end-start-1] = '\0';
            char* valStart = end+1;
            char* valEnd = strstr(valStart, "<"); // Find the end of the element value
            if (valEnd != NULL) {
                int len = valEnd - valStart;
                strncpy(value, valStart, len);  // Copy the XML element value
                value[len] = '\0';

                // Allocate memory for the new data element
                XmlData* newXmlData = (XmlData*) malloc(sizeof(XmlData));
                strcpy(newXmlData->name, name);
                strcpy(newXmlData->value, value);

                if (head == NULL) {
                    head = newXmlData;
                } else {
                    current->next = newXmlData;
                }

                current = newXmlData;
            }
        }
    }

    fclose(fp);
    return head;
}

int main() {
    // Process an XML file and print the data
    XmlData* xmldata = processXml("sample.xml");
    XmlData* current = xmldata;
    while (current != NULL) {
        printf("Name: %s\nValue: %s\n\n", current->name, current->value);
        current = current->next;
    }

    return 0;
}