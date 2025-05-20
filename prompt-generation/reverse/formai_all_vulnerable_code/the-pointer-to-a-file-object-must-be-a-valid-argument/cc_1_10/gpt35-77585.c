//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Define the maximum number of elements in the xml*/
#define MAX_ELEMENTS 100

/*Structure to represent a single element*/
typedef struct {
    char name[100];
    char value[100];
} element;

/*Global array to store all the elements in the xml*/
element elements[MAX_ELEMENTS];

/*Function to parse the xml file*/
void parseXML(char* filename) {
    FILE* fp = fopen(filename, "r");
    char buf[100];
    int elementIndex = 0;
    int insideElement = 0;
    char* token;
    char* name;
    char* value;
    while (fgets(buf,100,fp) != NULL) {
        /*Remove newline characters*/
        buf[strcspn(buf, "\r\n")] = 0;
        if (insideElement) {
            /*Check if we have reached the end of the element*/
            if (strstr(buf, "</") != NULL) {
                /*Extract the value*/
                value = token;
                value[strlen(value)-1] = '\0';
                /*Set the element value and reset insideElement*/
                strcpy(elements[elementIndex].value, value);
                insideElement = 0;
                elementIndex++;
            } else {
                /*Append to the element value*/
                strcat(token, buf);
            }
        } else {
            /*Check if we have found the start of a new element*/
            if (strstr(buf, "<") != NULL) {
                name = strtok(buf+1, ">");
                strcpy(elements[elementIndex].name, name);
                /*Get the value*/
                token = strtok(NULL, ">");
                /*Check if the element has a value or another element inside*/
                if (strstr(token, "</") == NULL) {
                    /*Set insideElement to true and set the starting value*/
                    insideElement = 1;
                    strcpy(elements[elementIndex].value, token);
                    token = elements[elementIndex].value + strlen(elements[elementIndex].value);
                } else {
                    /*Extract the value*/
                    value = strtok(token, "<");
                    strcpy(elements[elementIndex].value, value);
                    elementIndex++;
                }
            }
        }
    }
    fclose(fp);
}

/*Main function to test the XML parser*/
int main() {
    parseXML("example.xml");
    printf("Parsed %d elements from XML file\n", MAX_ELEMENTS);
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (strlen(elements[i].name) > 0) {
            /*Print the element*/
            printf("<%s>%s</%s>\n", elements[i].name, elements[i].value, elements[i].name);
        } else {
            break;
        }
    }
    return 0;
}