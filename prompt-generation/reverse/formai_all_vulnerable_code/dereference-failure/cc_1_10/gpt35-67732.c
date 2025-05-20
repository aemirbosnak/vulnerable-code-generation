//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: careful
#include <stdio.h>
#include <string.h>

char* morse_code(char *string) {
    char alphabet[36][6] = {
        {".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."},
        {"...."}, {".."}, {".---"}, {"-.-"}, {".-.."}, {"--"}, {"-."},
        {"---"}, {".--."}, {"--.-"}, {".-."}, {"..."}, {"-"}, {"..-"},
        {"...-"}, {".--"}, {"-..-"}, {"-.--"}, {"--.."},
        /* Digits */
        {".----"}, {"..---"}, {"...--"}, {"....-"}, {"....."},
        {"-...."}, {"--..."}, {"---.."}, {"----."}, {"-----"}
    };
    
    char *buffer = malloc(strlen(string) * 6 + 1);
    char *bptr = buffer;
    
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == ' ')
        {
            *bptr++ = '/';
            continue;
        }
        
        int offset = (string[i] >= 'a' && string[i] <= 'z') ? 'a' : '0' + 26;
        strcpy(bptr, alphabet[string[i] - offset]);
        bptr += strlen(alphabet[string[i] - offset]);
        
        *bptr++ = ' ';
    }
    
    *(bptr - 1) = '\0';
    
    return buffer;
}

int main() {
    char input[256];
    char *result;
    
    printf("Enter a string to convert to Morse code: ");
    fgets(input, 256, stdin);
    input[strcspn(input, "\n")] = '\0';
    
    result = morse_code(input);
    
    printf("The Morse code for '%s' is '%s'\n", input, result);
    
    free(result);
    
    return 0;
}