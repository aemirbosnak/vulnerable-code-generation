//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char* tag;
    char* value;
}xml_element;

void parse_element(char* line, xml_element* element){
    int tag_length = strstr(line, ">") - strstr(line, "<") - 1;
    int value_length = strlen(line) - tag_length - 3;
    strncpy(element->tag, strstr(line, "<") + 1, tag_length);
    strncpy(element->value, strstr(line, ">") + 1, value_length);
}

void parse_xml(char* xml, xml_element** elements, int* count){
    int i = 0;
    while(*xml){
        // Finding the next line that contains an element
        char* start = strstr(xml, "<");
        char* end = strstr(xml, ">");
        if(start && end){
            // Parsing the element and storing it in the array
            xml_element* element = (xml_element*) malloc(sizeof(xml_element));
            element->tag = (char*) malloc(1024);
            element->value = (char*) malloc(1024);
            parse_element(start, element);
            elements[i++] = element;
            xml = end+1;
            (*count)++;
        }
        else{
            break;
        }
    }
}

int main(){
    // Reading the XML file into a string
    FILE* fp = fopen("example.xml", "r");
    fseek(fp, 0L, SEEK_END);
    long int size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    char* xml = (char*) malloc(size);
    fread(xml, 1, size, fp);
    fclose(fp);

    // Initializing variables
    xml_element** elements = (xml_element**) malloc(sizeof(xml_element*) * 1024);
    int count = 0;

    // Parsing the XML file
    parse_xml(xml, elements, &count);

    // Printing the parsed elements
    for(int i=0; i<count; i++){
        printf("Tag: %s\nValue: %s\n\n", elements[i]->tag, elements[i]->value);
    }

    return 0;
}