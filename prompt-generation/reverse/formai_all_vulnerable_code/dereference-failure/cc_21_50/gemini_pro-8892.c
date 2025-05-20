//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int dice, sides, rolls, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, aa, bb, cc, dd, ee, ff, gg, hh, ii, jj, kk, ll, mm, nn, oo, pp, qq, rr, ss, tt, uu, vv, ww, xx, yy, zz;
  if (argc != 2) {
    printf("Usage: %s <number of dice>\n", argv[0]);
    return 1;
  }
  dice = atoi(argv[1]);
  if (dice < 1) {
    printf("Error: number of dice must be greater than 0\n");
    return 1;
  }
  printf("Enter the number of sides for each die (separated by spaces): ");
  scanf("%d %d %d %d %d %d %d %d %d %d", &sides, &sides, &sides, &sides, &sides, &sides, &sides, &sides, &sides, &sides);
  if (sides < 2) {
    printf("Error: number of sides must be greater than 1\n");
    return 1;
  }
  printf("Enter the number of rolls: ");
  scanf("%d", &rolls);
  if (rolls < 1) {
    printf("Error: number of rolls must be greater than 0\n");
    return 1;
  }
  for (i = 0; i < rolls; i++) {
    for (j = 0; j < dice; j++) {
      for (k = 0; k < sides; k++) {
        for (l = 0; l < sides; l++) {
          for (m = 0; m < sides; m++) {
            for (n = 0; n < sides; n++) {
              for (o = 0; o < sides; o++) {
                for (p = 0; p < sides; p++) {
                  for (q = 0; q < sides; q++) {
                    for (r = 0; r < sides; r++) {
                      for (s = 0; s < sides; s++) {
                        for (t = 0; t < sides; t++) {
                          for (u = 0; u < sides; u++) {
                            for (v = 0; v < sides; v++) {
                              for (w = 0; w < sides; w++) {
                                for (x = 0; x < sides; x++) {
                                  for (y = 0; y < sides; y++) {
                                    for (z = 0; z < sides; z++) {
                                      for (aa = 0; aa < sides; aa++) {
                                        for (bb = 0; bb < sides; bb++) {
                                          for (cc = 0; cc < sides; cc++) {
                                            for (dd = 0; dd < sides; dd++) {
                                              for (ee = 0; ee < sides; ee++) {
                                                for (ff = 0; ff < sides; ff++) {
                                                  for (gg = 0; gg < sides; gg++) {
                                                    for (hh = 0; hh < sides; hh++) {
                                                      for (ii = 0; ii < sides; ii++) {
                                                        for (jj = 0; jj < sides; jj++) {
                                                          for (kk = 0; kk < sides; kk++) {
                                                            for (ll = 0; ll < sides; ll++) {
                                                              for (mm = 0; mm < sides; mm++) {
                                                                for (nn = 0; nn < sides; nn++) {
                                                                  for (oo = 0; oo < sides; oo++) {
                                                                    for (pp = 0; pp < sides; pp++) {
                                                                      for (qq = 0; qq < sides; qq++) {
                                                                        for (rr = 0; rr < sides; rr++) {
                                                                          for (ss = 0; ss < sides; ss++) {
                                                                            for (tt = 0; tt < sides; tt++) {
                                                                              for (uu = 0; uu < sides; uu++) {
                                                                                for (vv = 0; vv < sides; vv++) {
                                                                                  for (ww = 0; ww < sides; ww++) {
                                                                                    for (xx = 0; xx < sides; xx++) {
                                                                                      for (yy = 0; yy < sides; yy++) {
                                                                                        for (zz = 0; zz < sides; zz++) {
                                                                                          printf("%d %d %d %d %d %d %d %d %d %d\n", i, j, k, l, m, n, o, p, q, r);
                                                                                        }
                                                                                      }
                                                                                    }
                                                                                  }
                                                                                }
                                                                              }
                                                                            }
                                                                          }
                                                                        }
                                                                      }
                                                                    }
                                                                  }
                                                                }
                                                              }
                                                            }
                                                          }
                                                        }
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}