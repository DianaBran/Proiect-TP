#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "proiect.h"

#define PI 3.14159265358979323846
#define NUM_VALUES 10000

int main() {
    generate_and_save_distributions();

    // Verifică dacă fișierele au fost create și conțin date
    FILE *normal_file = fopen("normal_distribution.txt", "r");
    FILE *poisson_file = fopen("poisson_distribution.txt", "r");

    if (normal_file == NULL || poisson_file == NULL) {
        printf("Eroare: Unul sau ambele fișiere nu au fost create.\n");
    } else {
        fseek(normal_file, 0, SEEK_END);
        fseek(poisson_file, 0, SEEK_END);
        long normal_size = ftell(normal_file);
        long poisson_size = ftell(poisson_file);

        if (normal_size > 0 && poisson_size > 0) {
            printf("Fișierele au fost create și conțin date.\n");
        } else {
            printf("Eroare: Unul sau ambele fișiere sunt goale.\n");
        }

        fclose(normal_file);
        fclose(poisson_file);
    }

    return 0;
}