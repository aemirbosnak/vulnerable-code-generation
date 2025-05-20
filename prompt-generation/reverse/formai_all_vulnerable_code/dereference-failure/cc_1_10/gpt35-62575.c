//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: protected
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_ELEMENTS 1000

typedef struct {
    char *name;
    char *value;
} XmlAttribute;

typedef struct XmlElement {
    char *name;
    XmlAttribute *attributes[MAX_ELEMENTS];
    struct XmlElement *child_elements[MAX_ELEMENTS];
    char *text;
} XmlElement;

void parse_element(XmlElement **element, char *buffer, int *pos);

void parse_text(char **dest, char *buffer, int *pos) {
    int i = 0;
    while(buffer[*pos+i] != '<' && buffer[*pos+i] != '\0') {
        i++;
    }
    *dest = malloc(sizeof(char) * (i+1));
    strncpy(*dest, buffer+*pos, i);
    (*dest)[i] = '\0';
    *pos += i-1;
}

void parse_attributes(XmlAttribute ***attributes, char *buffer, int *pos) {
    XmlAttribute **attrs = malloc(sizeof(XmlAttribute*) * MAX_ELEMENTS);
    int i = 0;
    while(buffer[*pos+i] != '>' && buffer[*pos+i] != '/') {
        if(buffer[*pos+i] != ' ' && buffer[*pos+i] != '\n') {
            int j = 0;
            while(buffer[*pos+i+j] != '=' && buffer[*pos+i+j] != '\0') {
                j++;
            }
            attrs[i] = malloc(sizeof(XmlAttribute));
            attrs[i]->name = malloc(sizeof(char) * (j+1));
            strncpy(attrs[i]->name, buffer+*pos+i, j);
            attrs[i]->name[j] = '\0';
            i ++;
            if(buffer[*pos+i+j+1] == '"') {
                j += 2;
                int k=0;
                while(buffer[*pos+i+j+k+1] != '"' && buffer[*pos+i+j+k+1] != '\0') {
                    k++;
                }
                attrs[i-1]->value = malloc(sizeof(char) * (k+1));
                strncpy(attrs[i-1]->value, buffer+*pos+i+j, k);
                attrs[i-1]->value[k] = '\0';
                i ++;
            }
        }
        i++;
    }
    if(i > 0) {
        *attributes = attrs;
        return;
    }
    free(attrs);
    *attributes = NULL;
}

void parse_void_element(XmlElement **element, char *buffer, int *pos) {
    (*element) = malloc(sizeof(XmlElement));
    (*element)->name = malloc(sizeof(char) * 50);
    int i = 0;
    while(buffer[*pos+i] != '>' && buffer[*pos+i] != '/') {
        (*element)->name[i] = buffer[*pos+i];
        i ++;
    }
    (*element)->name[i] = '\0';
    parse_attributes(&(*element)->attributes, buffer, pos);
    (*pos) += i;
}

void parse_element(XmlElement **element, char *buffer, int *pos) {
    if(buffer[*pos+1] == '/') {
        return;
    }
    (*element) = malloc(sizeof(XmlElement));
    (*element)->name = malloc(sizeof(char) * 50);
    int i = 0;
    *pos += 1;
    while(buffer[*pos+i] != '>' && buffer[*pos+i] != ' ') {
        (*element)->name[i] = buffer[*pos+i];
        i ++;
    }
    (*element)->name[i] = '\0';
    parse_attributes(&(*element)->attributes, buffer, pos);
    if(buffer[*pos+i] == '>') {
        *pos += i+1;
        parse_text(&(*element)->text, buffer, pos);
        while(strncmp(buffer+*pos, "</", 2)) {
            parse_element(&(*element)->child_elements[MAX_ELEMENTS], buffer, pos);
        }
        *pos += strlen((*element)->name)+3;
    }
    else if(buffer[*pos+i] == '/') {
        *pos += i+2;
    }
}

int main() {
    char *xml_buffer;
    FILE *file = fopen("example.xml", "r");
    size_t n = 0;
    int c;

    if (file == NULL)
        return 1; // could not open file

    while ((c = fgetc(file)) != EOF)
    {
        xml_buffer = realloc(xml_buffer, n + 1);
        xml_buffer[n++] = (char) c;
    }
    xml_buffer[n-1] = '\0';

    XmlElement *root;
    parse_element(&root, xml_buffer, &(int){0});

    return 0;
}