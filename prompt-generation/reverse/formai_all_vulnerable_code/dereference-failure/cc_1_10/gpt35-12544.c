//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

/* Define a struct to hold data from the XML */
typedef struct {
    char name[50];
    char value[50];
} XMLData;

/* Define a function to parse the XML */
void parseXML(char *xmlData) {
    int i = 0, j = 0;
    XMLData data[50]; /* Assume max 50 fields */
    int dataCount = 0;
    char currentName[50], currentValue[50];
    int insideTag = 0;

    /* Loop through each character of the XML */
    while (xmlData[i] != '\0') {
        if (xmlData[i] == '<') {
            /* Starting a new tag */
            insideTag = 1;
            j = 0;
        } else if (xmlData[i] == '>') {
            /* Ending a tag */
            insideTag = 0;
            currentName[j] = '\0';
            j = 0;
            /* Add the data to the struct */
            if (dataCount < 50) {
                strcpy(data[dataCount].name, currentName);
                strcpy(data[dataCount].value, currentValue);
                dataCount++;
            }
        } else if (insideTag) {
            /* Parsing within a tag */
            if (xmlData[i] == '=') {
                /* Moving from tag name to tag value */
                currentName[j] = '\0';
                j = 0;
            } else if (xmlData[i] == '"') {
                /* Ignoring quotes */
            } else {
                /* Parsing a tag name or value */
                if (j == 0) {
                    currentName[j] = xmlData[i];
                } else {
                    currentValue[j-1] = xmlData[i];
                }
                j++;
            }
        }
        i++;
    }

    /* Print the data */
    for (i = 0; i < dataCount; i++) {
        printf("%s: %s\n", data[i].name, data[i].value);
    }
}

/* Main function */
int main() {
    char xmlData[] = "<person name=\"John Doe\" age=\"30\"><address>123 Main St</address><city>Anytown</city><state>CA</state></person>";
    parseXML(xmlData);
    return 0;
}