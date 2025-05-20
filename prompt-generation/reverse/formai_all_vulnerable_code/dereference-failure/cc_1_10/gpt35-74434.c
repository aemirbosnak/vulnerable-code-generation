//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char *name;
    char *value;
}XmlAttribute;

typedef struct {
    int xml_attribute_count;
    char* xml_node_name;
    XmlAttribute *xml_attributes;
    char* xml_node_text;
}XmlNode;

typedef struct {
    char* xml_string;
    XmlNode *xml_nodes;
}XmlDocument;

XmlDocument* parse_xml(char* xml_string) {
    XmlDocument* xml_doc = (XmlDocument*)malloc(sizeof(XmlDocument));
    xml_doc->xml_string = xml_string;
    XmlNode *current_node = (XmlNode*)malloc(sizeof(XmlNode));
    current_node->xml_attribute_count = 0;
    XmlAttribute *current_attribute = (XmlAttribute*)malloc(sizeof(XmlAttribute));
    int index=0;
    char current_char;
    char tag_name[50];
    while(xml_string[index]!='\0') {
        current_char = xml_string[index];
        if(current_char == '<' && xml_string[index+1]!='/') {
            index += 1;
            int tag_name_index = 0;
            while(xml_string[index]!=' ' && xml_string[index]!='>'&& xml_string[index]!='/') {
                tag_name[tag_name_index++] = xml_string[index++];
            }
            tag_name[tag_name_index] = '\0';
            current_node->xml_node_name = tag_name;
            if(xml_string[index] == ' ') {
                index += 1;
                current_node->xml_attributes = (XmlAttribute*)malloc(sizeof(XmlAttribute));
                int xml_attribute_index = 0;
                while(xml_string[index]!='>') {
                    char attribute_name[50], attribute_value[50];
                    int attribute_name_index = 0;
                    while(xml_string[index]!='=') {
                        attribute_name[attribute_name_index++] = xml_string[index++];
                    }
                    attribute_name[attribute_name_index] = '\0';
                    index += 2;
                    int attribute_value_index = 0;
                    while(xml_string[index]!='"') {
                        attribute_value[attribute_value_index++] = xml_string[index++];
                    }
                    attribute_value[attribute_value_index] = '\0';
                    current_attribute->name = attribute_name;
                    current_attribute->value = attribute_value;
                    current_node->xml_attributes[xml_attribute_index] = *current_attribute;
                    current_node->xml_attribute_count++;
                    xml_attribute_index++;
                    index+=1;
                }
            }
        }
        else if(current_char == '<' && xml_string[index+1]=='/') {
            index += 2;
            int tag_name_index = 0;
            char closing_tag_name[50];
            while(xml_string[index]!='>') {
                closing_tag_name[tag_name_index++] = xml_string[index++];
            }
            closing_tag_name[tag_name_index] = '\0';
            if(!strcmp(current_node->xml_node_name,closing_tag_name)) {
                //do nothing
            }
            else{
                printf("Error: Invalid XML");
                return NULL;
            }
        }
        else if(current_char!='\n' && current_char!='\r') {
            int text_index = 0;
            char text_string[100];
            while(xml_string[index]!='<') {
                text_string[text_index++] = xml_string[index++];
            }
            text_string[text_index] = '\0';
            current_node->xml_node_text = text_string;
        }
        if(xml_string[index] == '>') {
            index += 1;
            current_node = (XmlNode*)malloc(sizeof(XmlNode));
            current_node->xml_attribute_count = 0;
            current_attribute = (XmlAttribute*)malloc(sizeof(XmlAttribute));
        }
    }
    return xml_doc;
}

int main(){
    char* xml_string = "<bookstore>\n<book category=\"cooking\" cover=\"paperback\">\n<title lang=\"en\">Everyday Italian</title>\n<author>Giada De Laurentiis</author>\n<year>2005</year>\n<price>30.00</price>\n</book>\n\n<book category=\"children\">\n<title lang=\"en\">Harry Potter</title>\n<author>J.K. Rowling</author>\n<year>2005</year>\n<price>29.99</price>\n</book>\n</bookstore>";
    XmlDocument* xml_doc = parse_xml(xml_string);
    printf("Xml Parsed Successfully!\n");
    return 0;
}