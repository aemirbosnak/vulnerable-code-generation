//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define ALIEN_VOCAB_SIZE 10

typedef struct {
    char english[20];
    char alien[20];
} Vocabulary;

Vocabulary dictionary[ALIEN_VOCAB_SIZE] = {
    {"hello", "znorp"},
    {"world", "blorpt"},
    {"cat", "flimgog"},
    {"dog", "gloob"},
    {"sun", "krizzn"},
    {"moon", "bimble"},
    {"star", "qwertz"},
    {"sky", "blimf"},
    {"water", "jibber"},
    {"earth", "quocqu"},
};

char* to_alien(char* input) {
    char* output = (char*)malloc(BUFFER_SIZE);
    memset(output, 0, BUFFER_SIZE);
    
    char* token = strtok(input, " ");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < ALIEN_VOCAB_SIZE; i++) {
            if (strcmp(token, dictionary[i].english) == 0) {
                strcat(output, dictionary[i].alien);
                strcat(output, " ");
                found = 1;
                break;
            }
        }
        if (!found) {
            strcat(output, token);
            strcat(output, " ");
        }
        token = strtok(NULL, " ");
    }
    
    return output;
}

void whisper_to_universe(char* alien_text) {
    printf("\nAs you whisper to the infinite void:\n");
    printf("\"%s\"\n", alien_text);
    printf("The stars tremble and reply with glittering silence...\n");
}

int main() {
    char input[BUFFER_SIZE];
    
    printf("An invocation to the surreal realm:\n");
    printf("Speak your earthly words:\n");
    
    fgets(input, BUFFER_SIZE, stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline

    printf("\nTranslating to the alien tongue...\n");
    
    char* alien_output = to_alien(input);
    printf("In the language of the unknown: %s\n", alien_output);
    
    whisper_to_universe(alien_output);
    
    free(alien_output);
    return 0;
}