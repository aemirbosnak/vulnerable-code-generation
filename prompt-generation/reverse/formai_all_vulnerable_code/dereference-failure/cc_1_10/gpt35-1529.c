//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: complete
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 1000

char* translate(char sentence[MAX_LENGTH]);

int main() {
    char sentence[MAX_LENGTH];
	
    printf("Enter a sentence in C Cat Language: ");
    fgets(sentence, MAX_LENGTH, stdin);
	
    char *translated_sentence = translate(sentence);
	
    printf("Translation: %s", translated_sentence);

    return 0;
}

char* translate(char sentence[MAX_LENGTH]) {
    static char translated[MAX_LENGTH];
    char *token;
    char delim[] = " ";
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    int index = 0;
	
    token = strtok(sentence, delim);

    while(token != NULL) {
        int length = strlen(token);
		
        if (length == 3 && token[0] == 'c' && token[1] == 'a' && token[2] != 't') {
            translated[index] = token[2];
            index++;
        } else if (length == 4 && token[0] == 'c' && token[1] == 'a' && token[2] == 't') {
            int vowel_found = 0;
            for (int i = 0; i < 5; i++) {
                if (token[3] == vowels[i]) {
                    char temp[3];
                    temp[0] = token[3];
                    temp[1] = 'a';
                    temp[2] = 't';
                    strcat(translated, temp);
                    index += 3;
                    vowel_found = 1;
                    break;
                }
            }
            if (vowel_found == 0) {
                char temp[2];
                temp[0] = token[3];
                temp[1] = 'c';
                strcat(translated, temp);
                index += 2;
            }
        } else {
            strcat(translated, token);
            index += length;
        }
        strcat(translated, " ");
        index++;
		
        token = strtok(NULL, delim);
    }

    return translated;
}