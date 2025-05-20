//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *alien;
    char *english;
} translation;

translation dictionary[] = {
    {"abogus", "hello"},
    {"adiablo", "goodbye"},
    {"afuego", "fire"},
    {"agua", "water"},
    {"aire", "air"},
    {"amor", "love"},
    {"arbol", "tree"},
    {"azul", "blue"},
    {"blanco", "white"},
    {"caliente", "hot"},
    {"casa", "house"},
    {"coche", "car"},
    {"comida", "food"},
    {"conejo", "rabbit"},
    {"corazon", "heart"},
    {"cuchillo", "knife"},
    {"demonio", "demon"},
    {"diablo", "devil"},
    {"dios", "god"},
    {"dragon", "dragon"},
    {"elfo", "elf"},
    {"enemigo", "enemy"},
    {"energia", "energy"},
    {"espiritu", "spirit"},
    {"estrella", "star"},
    {"fuego", "fire"},
    {"gato", "cat"},
    {"gente", "people"},
    {"gigante", "giant"},
    {"hada", "fairy"},
    {"hombre", "man"},
    {"humano", "human"},
    {"infierno", "hell"},
    {"insecto", "insect"},
    {"jardin", "garden"},
    {"jefe", "boss"},
    {"ladron", "thief"},
    {"lago", "lake"},
    {"lechuga", "lettuce"},
    {"leon", "lion"},
    {"libro", "book"},
    {"lobo", "wolf"},
    {"luz", "light"},
    {"magia", "magic"},
    {"mago", "wizard"},
    {"malvado", "evil"},
    {"mano", "hand"},
    {"mar", "sea"},
    {"mesa", "table"},
    {"metal", "metal"},
    {"miedo", "fear"},
    {"monstruo", "monster"},
    {"muerte", "death"},
    {"mundo", "world"},
    {"musica", "music"},
    {"noche", "night"},
    {"nube", "cloud"},
    {"oceano", "ocean"},
    {"ojo", "eye"},
    {"oro", "gold"},
    {"oscuridad", "darkness"},
    {"pajaro", "bird"},
    {"pais", "country"},
    {"padre", "father"},
    {"pan", "bread"},
    {"paraguas", "umbrella"},
    {"pato", "duck"},
    {"paz", "peace"},
    {"pelo", "hair"},
    {"piedra", "stone"},
    {"planta", "plant"},
    {"poder", "power"},
    {"pollo", "chicken"},
    {"puerta", "door"},
    {"que", "what"},
    {"quien", "who"},
    {"rata", "rat"},
    {"rayo", "lightning"},
    {"rio", "river"},
    {"roca", "rock"},
    {"rosa", "rose"},
    {"rojo", "red"},
    {"sabor", "flavor"},
    {"sangre", "blood"},
    {"serpiente", "snake"},
    {"sol", "sun"},
    {"sombra", "shadow"},
    {"sueño", "dream"},
    {"tierra", "earth"},
    {"tigre", "tiger"},
    {"tiempo", "time"},
    {"tormenta", "storm"},
    {"torre", "tower"},
    {"tradicion", "tradition"},
    {"trueno", "thunder"},
    {"unicornio", "unicorn"},
    {"universo", "universe"},
    {"vampiro", "vampire"},
    {"viento", "wind"},
    {"virus", "virus"},
    {"volcan", "volcano"},
    {"zorro", "fox"}
};

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <alien word> <english word>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *alien = argv[1];
    char *english = argv[2];
    int i;

    for (i = 0; i < sizeof(dictionary) / sizeof(translation); i++) {
        if (strcmp(alien, dictionary[i].alien) == 0) {
            printf("%s\n", dictionary[i].english);
            return EXIT_SUCCESS;
        } else if (strcmp(english, dictionary[i].english) == 0) {
            printf("%s\n", dictionary[i].alien);
            return EXIT_SUCCESS;
        }
    }

    printf("Translation not found.\n");
    return EXIT_FAILURE;
}