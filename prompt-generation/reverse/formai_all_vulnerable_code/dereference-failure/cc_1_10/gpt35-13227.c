//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct xml_element {
    char *name;
    char **attributes;
    char *text;
    struct xml_element *children[100];
    int num_children;
};

void parse_element(struct xml_element *parent_element, char *xml_str, int *pos_ptr) {
    int pos = *pos_ptr;
    int len = strlen(xml_str);
    char ch;
    
    // Get element name
    char *name = malloc(sizeof(char) * 50);
    int name_len = 0;
    
    while (pos < len) {
        ch = xml_str[pos];
        pos++;
        
        if (ch == '>') {
            break;
        } else if (ch == ' ') {
            break;
        } else {
            name[name_len] = ch;
            name_len++;
        }
    }
    
    parent_element->name = name;
    
    // Get attributes
    int num_attrs = 0;
    char **attributes = malloc(sizeof(char *) * 10);
    
    while (xml_str[pos] != '>') {
        if (xml_str[pos] == ' ') {
            // Skip spaces
            pos++;
        } else {
            // Get attribute name
            char *attr_name = malloc(sizeof(char) * 50);
            int attr_name_len = 0;
            
            while (xml_str[pos] != '=') {
                attr_name[attr_name_len] = xml_str[pos];
                attr_name_len++;
                pos++;
            }
            
            // Skip =
            pos++;
            
            // Skip "
            pos++;
            
            // Get attribute value
            char *attr_val = malloc(sizeof(char) * 50);
            int attr_val_len = 0;
            
            while (xml_str[pos] != '"') {
                attr_val[attr_val_len] = xml_str[pos];
                attr_val_len++;
                pos++;
            }
            
            // Skip "
            pos++;
            
            // Add attribute to list
            char *attribute = malloc(sizeof(char) * 100);
            sprintf(attribute, "%s=\"%s\"", attr_name, attr_val);
            attributes[num_attrs] = attribute;
            num_attrs++;
        }
    }
    
    parent_element->attributes = attributes;
    
    // Get text
    char *text = malloc(sizeof(char) * 100);
    int text_len = 0;
    
    while (xml_str[pos] != '<') {
        text[text_len] = xml_str[pos];
        text_len++;
        pos++;
    }
    
    parent_element->text = text;
    
    // Get child elements
    pos++;
    
    while (pos < len) {
        if (xml_str[pos] == '<') {
            if (xml_str[pos+1] == '/') {
                // End of this element
                *pos_ptr = pos+2;
                return;
            } else {
                // Start of a new child element
                struct xml_element *child_element = malloc(sizeof(struct xml_element));
                child_element->num_children = 0;
                parent_element->children[parent_element->num_children] = child_element;
                parent_element->num_children++;
                parse_element(child_element, xml_str, &pos);
            }
        } else {
            // Skip non-element text
            pos++;
        }
    }
}

int main() {
    char xml_str[] = "<bookstore> \n"
                     "<book category=\"cooking\"> \n"
                     "<title lang=\"en\">Everyday Italian</title> \n"
                     "<author>Giada De Laurentiis</author> \n"
                     "<year>2005</year> \n"
                     "<price>30.00</price> \n"
                     "</book> \n"
                     "<book category=\"children\"> \n"
                     "<title lang=\"en\">Harry Potter</title> \n"
                     "<author>J.K. Rowling</author> \n"
                     "<year>2005</year> \n"
                     "<price>29.99</price> \n"
                     "</book> \n"
                     "</bookstore>";
    
    struct xml_element *root_element = malloc(sizeof(struct xml_element));
    root_element->num_children = 0;
    
    int pos = 0;
    parse_element(root_element, xml_str, &pos);
    
    printf("Root element name: %s\n", root_element->name);
    
    for (int i=0; i<root_element->num_children; i++) {
        struct xml_element *book_element = root_element->children[i];
        printf("Book element category: %s\n", book_element->attributes[0]);
        printf("Book element title: %s\n", book_element->children[0]->text);
    }
    
    return 0;
}