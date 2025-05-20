//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    char *xml_data = "<book><title>XML Parser Example</title><author>John Doe</author></book>";
    int xml_data_len = strlen(xml_data);
    int i = 0;
    int state = 0; // 0 - outside, 1 - inside tag, 2 - attribute
    char current_tag[MAX_BUFFER_SIZE] = "";
    char current_attribute[MAX_BUFFER_SIZE] = "";

    for (i = 0; i < xml_data_len; i++)
    {
        switch (state)
        {
            case 0:
                if (xml_data[i] == '<')
                {
                    state = 1;
                    current_tag[0] = xml_data[i];
                }
                break;
            case 1:
                if (xml_data[i] == '>')
                {
                    state = 0;
                    current_tag[0] = '\0';
                    printf("Tag: %s\n", current_tag);
                }
                else
                {
                    memcpy(current_tag + 1, xml_data + i, MAX_BUFFER_SIZE - 1);
                    current_tag[MAX_BUFFER_SIZE - 1] = '\0';
                }
                break;
            case 2:
                if (xml_data[i] == '"')
                {
                    state = 0;
                    current_attribute[0] = '\0';
                    printf("Attribute: %s, Value: %s\n", current_attribute, current_tag);
                }
                else
                {
                    memcpy(current_attribute + 1, xml_data + i, MAX_BUFFER_SIZE - 1);
                    current_attribute[MAX_BUFFER_SIZE - 1] = '\0';
                }
                break;
        }
    }

    return 0;
}