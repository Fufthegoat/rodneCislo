#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_ROK 1954
#define MAX_ROK 2054

#define MIN_MESIC 1
#define MAX_MESIC 12

#define MIN_DEN 1
#define MAX_DEN 30

#define MIN_POHLAVI 0 //zena
#define MAX_POHLAVI 1 //muz

#define MIN_TROJCISLI 0
#define MAX_TROJCISLI 999

void bufferClean() {
    while (getchar() != '\n') {
    }
}
int nactiCislo(const char *text, int min, int max) {
        int hodnota;

        do {
            printf("Zadej %s v intervalu %d - %d: ", text, min, max);

            if (scanf("%d", &hodnota) != 1) {
                printf("Spatny vstup, zkus znovu.\n");
                bufferClean();
                continue;
            }

            if (hodnota < min || hodnota > max) {
                printf("Zadane cislo neni v intervalu %d - %d\n", min, max);
            }

        } while (hodnota < min || hodnota > max);

        return hodnota;
    }

void generujRodneCislo(int rok, int mesic, int den, int pohlavi, int trojcisli) {
        int rr = rok % 100;
        if (pohlavi == 0) {
            mesic += 50;
        }
        printf("Bylo vytvoreno validni rodne cislo: %02d%02d%02d%03d\n", rr, mesic, den, trojcisli);
    }

int main(void) {
        srand((unsigned) time(NULL));
        char znovu;

        do {
            int rok = nactiCislo("rok", MIN_ROK, MAX_ROK);
            printf("Zadal jsi rok: %d\n", rok);
            int mesic = nactiCislo("mesic", MIN_MESIC, MAX_MESIC);
            printf("Zadal jsi mesic: %d\n", mesic);
            int den = nactiCislo("den", MIN_DEN, MAX_DEN);
            printf("Zadal jsi den: %d\n", den);
            int pohlavi = nactiCislo("pohlavi (0 = zena, 1 = muz)", MIN_POHLAVI, MAX_POHLAVI);
            printf("Zadal jsi pohlavi: %d\n", pohlavi);
            int trojcisli = nactiCislo("trojcisli", MIN_TROJCISLI, MAX_TROJCISLI);
            printf("Zadal jsi trojcisli: %d\n", trojcisli);

            generujRodneCislo(rok, mesic, den, pohlavi, trojcisli);

            printf("Pro opakovane zadani rodneho cisla zadej enter: \n");
            bufferClean();
            znovu = getchar();

        }  while (znovu == '\n');

        return 0;
    }