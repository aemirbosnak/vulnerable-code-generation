//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: artistic
// A canvas of words, a symphony of strings,
// Where artistry meets code, where beauty sings.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A brush of bytes, a palette of hues,
// Transforming text into vibrant views.

typedef struct {
    char *str;
    int len;
} String;

// A stroke of genius, a touch of grace,
// Initializing strings with elegance and space.

String *init_string(char *s) {
    String *new_str = malloc(sizeof(String));
    new_str->len = strlen(s);
    new_str->str = malloc(new_str->len + 1);
    strcpy(new_str->str, s);
    return new_str;
}

// A dance of characters, a lyrical flow,
// Appending strings, letting their stories grow.

String *append(String *s1, String *s2) {
    String *new_str = malloc(sizeof(String));
    new_str->len = s1->len + s2->len;
    new_str->str = malloc(new_str->len + 1);
    strcpy(new_str->str, s1->str);
    strcat(new_str->str, s2->str);
    return new_str;
}

// A searchlight of words, a beacon bright,
// Finding patterns, illuminating the night.

int find(String *s, String *sub) {
    char *found = strstr(s->str, sub->str);
    if (found == NULL) return -1;
    return found - s->str;
}

// A kaleidoscope of colors, a vibrant hue,
// Reversing strings, a world anew.

String *reverse(String *s) {
    String *new_str = malloc(sizeof(String));
    new_str->len = s->len;
    new_str->str = malloc(new_str->len + 1);
    for (int i = 0; i < new_str->len; i++) {
        new_str->str[i] = s->str[new_str->len - i - 1];
    }
    new_str->str[new_str->len] = '\0';
    return new_str;
}

// A maestro of words, a conductor of sound,
// Orchestrating strings, a symphony profound.

int main() {
    // A canvas awaits, a story to unfold,
    // With strokes of code, a tale to be told.
    String *s1 = init_string("The world is a book,");
    String *s2 = init_string(" and those who do not travel read only one page.");
    String *s3 = append(s1, s2);

    // A tapestry of words, a vibrant display,
    // Weaving strings together, a masterpiece they sway.
    String *found = init_string("those");
    int pos = find(s3, found);
    if (pos != -1) { printf("Found \"%s\" at position %d\n", found->str, pos); }

    // A mirror of words, a reflection so clear,
    // Reversing strings, a new world to appear.
    String *reversed = reverse(s3);
    printf("Reversed: %s\n", reversed->str);

    // A virtuoso performance, a symphony complete,
    // Strings manipulated, a poetic feat.
    printf("Original: %s\n", s3->str);
    printf("Reversed: %s\n", reversed->str);

    // A curtain call, a round of applause,
    // For the strings that danced, the words that gave pause.
    free(s1->str); free(s1);
    free(s2->str); free(s2);
    free(s3->str); free(s3);
    free(found->str); free(found);
    free(reversed->str); free(reversed);

    // As the echoes fade, the story remains,
    // In the hearts of readers, forever it sustains.
    return 0;
}