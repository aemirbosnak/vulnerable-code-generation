//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure of each element in the XML file
typedef struct {
    char *name;
    char *value;
} Element;

// structure of the XML file
typedef struct {
    Element *elements;
    int num_elements;
} XML;

// function to parse the XML file
XML *parse_xml(char *xml_string) {
    // allocate memory for the XML struct
    XML *xml = (XML*) malloc(sizeof(XML));
    xml->num_elements = 0;
    
    // get the length of the XML string
    int length = strlen(xml_string);
    
    // initialize variables for element parsing
    int i = 0;
    int j;
    char element_name[100];
    int element_name_length = 0;
    char element_value[100];
    int element_value_length = 0;
    
    // loop through the input string
    while (i < length) {
        // check if this is the start of a new element
        if (xml_string[i] == '<') {
            j = i+1;
            
            // get the element name
            while (xml_string[j] != '>') {
                element_name[element_name_length++] = xml_string[j++];
            }
            element_name[element_name_length] = '\0';
            
            // check if this is an opening element
            if (element_name[0] != '/') {
                // allocate memory for the new element
                Element *new_element = (Element*) malloc(sizeof(Element));
                new_element->name = (char*) malloc((strlen(element_name)+1) * sizeof(char));
                strcpy(new_element->name, element_name);
                new_element->value = NULL;
                xml->elements = (Element*) realloc(xml->elements, (xml->num_elements+1) * sizeof(Element));
                xml->elements[xml->num_elements++] = *new_element;
            } else {
                // find the matching opening element
                int k;
                for (k = xml->num_elements-1; k >= 0; k--) {
                    Element *current_element = &(xml->elements[k]);
                    if (strcmp(current_element->name, &element_name[1]) == 0) {
                        // update the value of the element
                        current_element->value = (char*) malloc((element_value_length+1) * sizeof(char));
                        strcpy(current_element->value, element_value);
                        break;
                    }
                }
            }
            
            // clear the variables for the next element
            element_name_length = 0;
            element_value_length = 0;
            i = j+1;
        } else {
            // add the character to the element value
            element_value[element_value_length++] = xml_string[i++];

            // check if this is the end of the element value
            if (xml_string[i] == '<') {
                element_value[element_value_length] = '\0';
            }
        }
    }
    
    return xml;
}

// test function
void test_xml_parser() {
    char *xml_string = "<note><to>Tove</to><from>Jani</from><heading>Reminder</heading><body>Don't forget me this weekend!</body></note>";
    XML *xml = parse_xml(xml_string);
    
    printf("Parsed XML:\n");
    int i;
    for (i = 0; i < xml->num_elements; i++) {
        printf("%s=", xml->elements[i].name);
        if (xml->elements[i].value != NULL) {
            printf("%s\n", xml->elements[i].value);
        } else {
            printf("\n");
        }
    }
}

int main() {
    test_xml_parser();
    return 0;
}