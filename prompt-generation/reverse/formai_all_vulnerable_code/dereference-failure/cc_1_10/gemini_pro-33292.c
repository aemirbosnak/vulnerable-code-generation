//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: medieval
// Ye Olde Catte Language Translated To C

#include <stdio.h>

#define YE 1
#define NAY 0

// Declarest ye functiones that transformith the user's input.
int translate(char *);
void speak(char *);
void leave();

// Beginneth the main function.
int main(int argc, char *argv[])
{
    // Declarest variables to hold the user's input and the translated message.
    char *input, *output;

    // If the user hath not provided an argument, printeth an error message and leaveth.
    if (argc < 2)
    {
        printf("Usage: %s <message>\n", argv[0]);
        leave();
    }

    // Assigneth the user's input to a variable.
    input = argv[1];

    // Translateth the user's input into the catte language.
    output = translate(input);

    // Speeketh the translated message.
    speak(output);

    // Leaveth the program.
    leave();

    return 0;
}

// Translateth the user's input into the catte language.
int translate(char *input)
{
    // Declarest variables to hold the translated message.
    char *output;

    // Allocates memory to store the translated message.
    output = (char *)malloc(sizeof(char) * strlen(input));

    // Loop through the user's input.
    for (int i = 0; input[i] != '\0'; i++)
    {
        // Transformeth each character into the catte language.
        switch (input[i])
        {
        case 'a':
            output[i] = 'e';
            break;
        case 'e':
            output[i] = 'a';
            break;
        case 'i':
            output[i] = 'o';
            break;
        case 'o':
            output[i] = 'i';
            break;
        case 'u':
            output[i] = 'y';
            break;
        case 'y':
            output[i] = 'u';
            break;
        default:
            output[i] = input[i];
            break;
        }
    }

    // Assigneth the translated message to the variable and return it.
    output[strlen(input)] = '\0';
    return output;
}

// Speeketh the translated message.
void speak(char *message)
{
    // Loop through the translated message.
    for (int i = 0; message[i] != '\0'; i++)
    {
        // Printeth each character of the message.
        printf("%c", message[i]);
    }

    // Printeth a newline.
    printf("\n");
}

// Leaveth the program.
void leave()
{
    // Printeth a farewell message.
    printf("Meow!\n");

    // Exit the program.
    exit(0);
}