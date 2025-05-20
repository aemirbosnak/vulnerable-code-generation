//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Romeo and Juliet Metadata Extractor

// A rose by any other name would smell as sweet. - William Shakespeare
typedef struct {
    char *name;
    char *family;
    char *species;
} Rose;

// But soft! what light through yonder window breaks? - William Shakespeare
void print_rose_metadata(Rose *rose) {
    assert(rose != NULL);
    assert(rose->name != NULL);
    assert(rose->family != NULL);
    assert(rose->species != NULL);

    printf("Name: %s\n", rose->name);
    printf("Family: %s\n", rose->family);
    printf("Species: %s\n", rose->species);
}

// The bud o'erflows with dewy wine. - William Shakespeare
Rose *create_rose(char *name, char *family, char *species) {
    assert(name != NULL);
    assert(family != NULL);
    assert(species != NULL);

    Rose *rose = malloc(sizeof(Rose));
    assert(rose != NULL);

    rose->name = strdup(name);
    assert(rose->name != NULL);

    rose->family = strdup(family);
    assert(rose->family != NULL);

    rose->species = strdup(species);
    assert(rose->species != NULL);

    return rose;
}

// Parting is such sweet sorrow. - William Shakespeare
void destroy_rose(Rose *rose) {
    assert(rose != NULL);

    free(rose->name);
    free(rose->family);
    free(rose->species);
    free(rose);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <name> <family> <species>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Rose *rose = create_rose(argv[1], argv[2], argv[3]);
    print_rose_metadata(rose);
    destroy_rose(rose);

    return EXIT_SUCCESS;
}