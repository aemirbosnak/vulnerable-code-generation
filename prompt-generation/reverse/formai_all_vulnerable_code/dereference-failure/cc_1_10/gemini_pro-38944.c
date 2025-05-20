//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Our tale begins as a seed is sown, the promise of a digital garden to be grown.
char *seed = "The seed of our digital garden grows, nurtured by lines that compose.";

//With each keystroke, a petal unfurls, a symphony of characters in swirling whirls.
char *petal(char *s) {
    char *p = malloc(strlen(s) + 3);
    sprintf(p, "%s%s%s", "<", s, ">");
    return p;
}

//As blossoms dance in vibrant hue, a tapestry woven, bright and true.
char *blossom(char *s) {
    char *b = malloc(strlen(s) + 3);
    sprintf(b, "%s%s%s", "{", s, "}");
    return b;
}

//The garden blooms in endless grace, a canvas painted, leaving no trace.
char *garden(char *s) {
    char *g = malloc(strlen(s) + 5);
    sprintf(g, "%s%s%s", "[", s, "]");
    return g;
}

//In this garden of prose, sculpted to perfection, words blossom with grace, a divine resurrection.
char *verse(char *s) {
    char *v = malloc(strlen(s) + 7);
    sprintf(v, "%s%s%s", "[Verse]", s, "[/Verse]");
    return v;
}

//As petals fall, a graceful dance, they coalesce to form a poetic trance.
char *stanza(char *s) {
    char *st = malloc(strlen(s) + 9);
    sprintf(st, "%s%s%s", "[Stanza]", s, "[/Stanza]");
    return st;
}

//In the garden's embrace, a symphony unfurls, a tapestry of words, where beauty twirls.
char *poem(char *s) {
    char *p = malloc(strlen(s) + 11);
    sprintf(p, "%s%s%s", "[Poem]", s, "[/Poem]");
    return p;
}

//Through lines and stanzas, a saga unfolds, where imagination's flame forever holds.
char *saga(char *s) {
    char *sg = malloc(strlen(s) + 13);
    sprintf(sg, "%s%s%s", "[Saga]", s, "[/Saga]");
    return sg;
}

//As the garden grows, a world to behold, a testament to stories yet untold.
char *world(char *s) {
    char *w = malloc(strlen(s) + 15);
    sprintf(w, "%s%s%s", "[World]", s, "[/World]");
    return w;
}

//In this ethereal realm, where fancies soar, the garden invites you to explore evermore.
char *universe(char *s) {
    char *u = malloc(strlen(s) + 17);
    sprintf(u, "%s%s%s", "[Universe]", s, "[/Universe]");
    return u;
}

//Where words dance and dreams take flight, the garden of text, a pure delight.
int main() {
    char *garden_text = world(saga(poem(stanza(verse(garden(blossom(petal(seed))))))));
    printf("%s\n", garden_text);
    free(garden_text);
    return 0;
}