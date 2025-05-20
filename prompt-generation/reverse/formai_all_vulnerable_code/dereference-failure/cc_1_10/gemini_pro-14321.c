//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: Romeo and Juliet
// Where ancient grudge break to new mutiny,
// Where civil blood makes civil hands unclean.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// O, Romeo, Romeo! wherefore art thou Romeo?
typedef struct {
    char *text;
    int length;
} Text;

// But soft, what light through yonder window breaks?
// It is the east, and Juliet is the sun.
Text *create_text(char *input) {
    Text *text = malloc(sizeof(Text));
    text->length = strlen(input);
    text->text = malloc(text->length + 1);
    strcpy(text->text, input);
    return text;
}

// A rose by any other word would smell as sweet.
void free_text(Text *text) {
    free(text->text);
    free(text);
}

// Two households, both alike in dignity,
// In fair Verona, where we lay our scene.
int main() {
    // From forth the fatal loins of these two foes
    // A pair of star-cross'd lovers take their life.
    char *input = "Two households, both alike in dignity,\n"
                  "In fair Verona, where we lay our scene,\n"
                  "From forth the fatal loins of these two foes\n"
                  "A pair of star-cross'd lovers take their life.\n"
                  "\n"
                  "The fearful passage of their death-mark'd love,\n"
                  "And the continuance of their parents' rage,\n"
                  "Which, but their children's end, naught could remove,\n"
                  "Is now the two hours' traffic of our stage;\n"
                  "\n"
                  "The which if you with patient ears attend,\n"
                  "What here shall miss, our toil shall strive to mend.";

    // Now old desire doth in his deathbed lie,
    // And young affection gapes to be his heir.
    Text *text = create_text(input);

    // For never was a story of more woe
    // Than this of Juliet and her Romeo.
    printf("\n%s\n", text->text);

    // Free the lovers from their tragic fate.
    free_text(text);

    return 0;
}