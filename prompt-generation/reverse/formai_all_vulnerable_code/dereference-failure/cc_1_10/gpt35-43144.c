//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    char elements[118][2];
    strcpy(elements[0], "H");
    strcpy(elements[1], "He");
    strcpy(elements[2], "Li");
    strcpy(elements[3], "Be");
    strcpy(elements[4], "B");
    strcpy(elements[5], "C");
    strcpy(elements[6], "N");
    strcpy(elements[7], "O");
    strcpy(elements[8], "F");
    strcpy(elements[9], "Ne");
    strcpy(elements[10], "Na");
    strcpy(elements[11], "Mg");
    strcpy(elements[12], "Al");
    strcpy(elements[13], "Si");
    strcpy(elements[14], "P");
    strcpy(elements[15], "S");
    strcpy(elements[16], "Cl");
    strcpy(elements[17], "Ar");
    strcpy(elements[18], "K");
    strcpy(elements[19], "Ca");
    strcpy(elements[20], "Sc");
    strcpy(elements[21], "Ti");
    strcpy(elements[22], "V");
    strcpy(elements[23], "Cr");
    strcpy(elements[24], "Mn");
    strcpy(elements[25], "Fe");
    strcpy(elements[26], "Co");
    strcpy(elements[27], "Ni");
    strcpy(elements[28], "Cu");
    strcpy(elements[29], "Zn");
    strcpy(elements[30], "Ga");
    strcpy(elements[31], "Ge");
    strcpy(elements[32], "As");
    strcpy(elements[33], "Se");
    strcpy(elements[34], "Br");
    strcpy(elements[35], "Kr");
    strcpy(elements[36], "Rb");
    strcpy(elements[37], "Sr");
    strcpy(elements[38], "Y");
    strcpy(elements[39], "Zr");
    strcpy(elements[40], "Nb");
    strcpy(elements[41], "Mo");
    strcpy(elements[42], "Tc");
    strcpy(elements[43], "Ru");
    strcpy(elements[44], "Rh");
    strcpy(elements[45], "Pd");
    strcpy(elements[46], "Ag");
    strcpy(elements[47], "Cd");
    strcpy(elements[48], "In");
    strcpy(elements[49], "Sn");
    strcpy(elements[50], "Sb");
    strcpy(elements[51], "Te");
    strcpy(elements[52], "I");
    strcpy(elements[53], "Xe");
    strcpy(elements[54], "Cs");
    strcpy(elements[55], "Ba");
    strcpy(elements[56], "La");
    strcpy(elements[57], "Ce");
    strcpy(elements[58], "Pr");
    strcpy(elements[59], "Nd");
    strcpy(elements[60], "Pm");
    strcpy(elements[61], "Sm");
    strcpy(elements[62], "Eu");
    strcpy(elements[63], "Gd");
    strcpy(elements[64], "Tb");
    strcpy(elements[65], "Dy");
    strcpy(elements[66], "Ho");
    strcpy(elements[67], "Er");
    strcpy(elements[68], "Tm");
    strcpy(elements[69], "Yb");
    strcpy(elements[70], "Lu");
    strcpy(elements[71], "Hf");
    strcpy(elements[72], "Ta");
    strcpy(elements[73], "W");
    strcpy(elements[74], "Re");
    strcpy(elements[75], "Os");
    strcpy(elements[76], "Ir");
    strcpy(elements[77], "Pt");
    strcpy(elements[78], "Au");
    strcpy(elements[79], "Hg");
    strcpy(elements[80], "Tl");
    strcpy(elements[81], "Pb");
    strcpy(elements[82], "Bi");
    strcpy(elements[83], "Po");
    strcpy(elements[84], "At");
    strcpy(elements[85], "Rn");
    strcpy(elements[86], "Fr");
    strcpy(elements[87], "Ra");
    strcpy(elements[88], "Ac");
    strcpy(elements[89], "Th");
    strcpy(elements[90], "Pa");
    strcpy(elements[91], "U");
    strcpy(elements[92], "Np");
    strcpy(elements[93], "Pu");
    strcpy(elements[94], "Am");
    strcpy(elements[95], "Cm");
    strcpy(elements[96], "Bk");
    strcpy(elements[97], "Cf");
    strcpy(elements[98], "Es");
    strcpy(elements[99], "Fm");
    strcpy(elements[100], "Md");
    strcpy(elements[101], "No");
    strcpy(elements[102], "Lr");
    strcpy(elements[103], "Rf");
    strcpy(elements[104], "Db");
    strcpy(elements[105], "Sg");
    strcpy(elements[106], "Bh");
    strcpy(elements[107], "Hs");
    strcpy(elements[108], "Mt");
    strcpy(elements[109], "Ds");
    strcpy(elements[110], "Rg");
    strcpy(elements[111], "Cn");
    strcpy(elements[112], "Nh");
    strcpy(elements[113], "Fl");
    strcpy(elements[114], "Mc");
    strcpy(elements[115], "Lv");
    strcpy(elements[116], "Ts");
    strcpy(elements[117], "Og");

    int score = 0;

    printf("Welcome to the Periodic Table Quiz!\n\n");

    srand(time(NULL));
    int rand_num = rand() % 118;
    char element[2];
    strcpy(element, elements[rand_num]); // pick a random element

    printf("What is the symbol for %s? ", element);

    char user_input[2];
    scanf("%s", user_input);

    if (strcmp(user_input, element) == 0) {
        printf("\nCongratulations! You are correct! %s is the symbol for %s.\n", element, element);
        score++;
    } else {
        printf("\nSorry, %s is not the correct symbol for %s.\n", user_input, element);
    }

    printf("\nYour current score is %d.\n", score);

    printf("\nReady for the next question?\n");
    printf("Press Y for yes or any other character to quit.\n");

    char ready;
    scanf("%c", &ready);

    if (ready == 'Y' || ready == 'y') {
        rand_num = rand() % 118;
        strcpy(element, elements[rand_num]); // pick a random element

        printf("What is the symbol for %s? ", element);

        char user_input[2];
        scanf("%s", user_input);

        if (strcmp(user_input, element) == 0) {
            printf("\nCongratulations! You are correct! %s is the symbol for %s.\n", element, element);
            score++;
        } else {
            printf("\nSorry, %s is not the correct symbol for %s.\n", user_input, element);
        }

        printf("\nYour current score is %d.\n", score);

        printf("\nReady for the next question?\n");
        printf("Press Y for yes or any other character to quit.\n");

        scanf("%c", &ready);

        while (ready == 'Y' || ready == 'y') {
            rand_num = rand() % 118;
            strcpy(element, elements[rand_num]); // pick a random element

            printf("What is the symbol for %s? ", element);

            char user_input[2];
            scanf("%s", user_input);

            if (strcmp(user_input, element) == 0) {
                printf("\nCongratulations! You are correct! %s is the symbol for %s.\n", element, element);
                score++;
            } else {
                printf("\nSorry, %s is not the correct symbol for %s.\n", user_input, element);
            }

            printf("\nYour current score is %d.\n", score);

            printf("\nReady for the next question?\n");
            printf("Press Y for yes or any other character to quit.\n");

            scanf("%c", &ready);
        }

        printf("\nThanks for playing the Periodic Table Quiz!\n");
        printf("Your final score is %d out of 3.\n", score);
    } else {
        printf("\nThanks for playing the Periodic Table Quiz!\n");
        printf("Your final score is %d.\n", score);
    }

    return 0;
}