//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ascii_art(char *text) {
    char *art = malloc(strlen(text) * 10);
    int i, j, k;
    for (i = 0; i < strlen(text); i++) {
  for (j = 0; j < 10; j++) {
      k = (text[i] - ' ') * 10 + j;
      art[i * 10 + j] = "           **        * **            *        ** *  **         **       "
                         "      *   *  **     *    **            **         **  **        * *      "
                         "      *   *    **   *    * **           *           **  **       **      "
                         "      *  *      ** *     * * *          *           ** * *       **      "
                         "      **        ** *     ** * *         *           **  **       * *      "
                         "     *  *      *  **    *    **         *          *    **      *  **     "
                         "     **       *    *   *    * **        *          *    * *     *    *    "
                         "    *  *      *     *  *    *   *       *         *     *  *    *     *   "
                         "    *   *     *      * *    **   *      *         *     *   *   *      *  "
                         "    *    **   *       **   **  *  ****  *       *     *    *  **      * "
                         "     **   *   *        **  **   **  * * *      *     *     *  **      *  "
                         "      *  *   *          ** *   *    *  **     *     *      *  **       ** "
                         "      *   *  *           ** *   *    *   **    *     *      *   **      ** "
                         "     *    * *            ** *   *    *    *   *     *       *   **      * "
                         "     *    * *             ** *   *    *    *   *     *        *  **     *  "
                         "    *     * *              ** *   *    *    *   *     *         **    *   "
                         "    *      **               ** *   *    *    *   *     *           **  *  "
                         "   *       **               **  *   *    *    *   *     *            ** * "
                         "   *         **             *   *   *    *    *   *     *              **"
                         "   *          **            *   *   *    *    *   *     *               * "
                         "   *           **           *   *   *    *    *   *     *                * "
                         "   *            **          *   *   *    *    *   *     *                 "
                         "    *             **        *   *   *    *    *   *     *                  "
                         "     *             **       *   *   *    *    *   *     *                   "
                         "      *            * *      *   *   *    **   *   *     *                    "
                         "       *            **      *   *   *     **  *   *     *                     "
                         "        *           **     *   *   *       ** *   *     *                      "
                         "         *          **    *   *   *          **  *   *                      "
                         "          *         **  *   *   *              * *   *                       "
                         "           *        ** *   *   *                 **  *                        "
                         "            *       ** *   *   *                   ** *                         "
                         "             *      **   *   *                      **                          "
                         "              *     **    *  *                        **                           "
                         "                *   **     * *                           *                            "
                         "                 **       **                             "
                         "                    **        *                              "
                         "                      **                                  "
                         "                        *                                   "
                         "                          " [k];
    }
  }
  return art;
}

int main() {
  char *text = "POST-APOCALYPTIC";
  char *art = ascii_art(text);
  printf("%s\n", art);
  free(art);
  return 0;
}