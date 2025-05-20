//Falcon2-11B DATASET v1.0 Category: Text to ASCII art generator ; Style: detailed
#include <stdio.h>

void read_input(char* text);
void convert_to_ascii_art(char* text);
void write_output(char* ascii_art);

int main()
{
    read_input("Enter text: ");
    convert_to_ascii_art("Enter text: ");
    write_output("Enter text: ");
    return 0;
}

void read_input(char* text)
{
    printf("Enter text: ");
    fgets(text, 100, stdin);
}

void convert_to_ascii_art(char* text)
{
    char ascii_art[1000];
    char characters[1000] = { '[', ']' };

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '[')
        {
            ascii_art[i] = ']';
        }
        else
        {
            characters[i] = text[i];
        }
    }

    ascii_art[strlen(text)] = '\0';

    for (int i = 0; i < strlen(ascii_art); i++)
    {
        printf("%c", ascii_art[i]);
    }
    printf("\n");
}

void write_output(char* ascii_art)
{
    FILE* file = fopen("ascii_art.txt", "w");
    if (file == NULL)
    {
        printf("Failed to open file\n");
        return;
    }

    fputs(ascii_art, file);
    fclose(file);
}