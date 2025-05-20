//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    char *xml_data = "<root><child>Hello, world!</child></root>";
    int xml_data_len = strlen(xml_data);
    int i = 0;
    int state = 0;
    char current_tag[256];
    char *current_value = NULL;

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
                    current_tag[1] = '\0';
                    current_value = malloc(MAX_BUFFER_SIZE);
                    current_value[0] = '\0';
                }
                else
                {
                    current_value[i - 1] = xml_data[i];
                }
                break;

            case 2:
                if (xml_data[i] == '>')
                {
                    state = 0;
                    printf("Tag: %s, Value: %s\n", current_tag, current_value);
                    free(current_value);
                }
                else
                {
                    current_value[i - 1] = xml_data[i];
                }
                break;
        }
    }

    return 0;
}