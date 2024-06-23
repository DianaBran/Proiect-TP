#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "proiect.h"

#define PI 3.14159265358979323846
#define NUM_VALUES 10000

unsigned* makeRandArray(unsigned seed, unsigned n) 
{
    unsigned *array = (unsigned *)malloc(n * sizeof(unsigned));
    srand(seed);
    if (array == NULL) 
    {
        return NULL;
    }
    for (unsigned i = 0; i < n; i++)
    {
        array[i] = rand();
    }
    return array;
}

void printArray_u(unsigned* array, unsigned n) 
{
    for (unsigned i = 0; i < n; i++) 
    {
        printf("%u ", array[i]);
    }
    printf("\n");
}

int* makeRandLimitArray(int seed, unsigned n, int a, int b) 
{
    if (a >= b) 
    {
        return NULL;
    }
    srand(seed);
    int *array = (int*)malloc(n * sizeof(int));
    if (array == NULL) {
        return NULL;
    }
    for (unsigned i = 0; i < n; i++) 
    {
        int randomNumber;
        do 
        {
            randomNumber = rand();
        } while (randomNumber < a || randomNumber > b);
        array[i] = randomNumber;
    }
    return array;
}

int* makeRandFlexiArray(unsigned n, int (*getNewElem)(int*, unsigned))
{
    int* array = (int*)malloc(n * sizeof(int));
    if (!array) 
    {
        printf("Eroare la alocarea memoriei.\n");
        return NULL;
    }
    for (unsigned i = 0; i < n; ++i) 
    {
        array[i] = getNewElem(array, i);
    }
    return array;
}

int getNextIncreasingElem(int* array, unsigned n) 
{
    int delta = rand() % 10 + 1;
    if (n == 0) return rand() % 10;
    return array[n - 1] + delta;
}

int getNextDecreasingElem(int* array, unsigned n) 
{
    int delta = rand() % 10 + 1;
    if (n == 0) return 100 - (rand() % 10);
    return array[n - 1] - delta;
}

void printArray(int* array, unsigned n) 
{
    for (unsigned i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

double normalDistribution(double media, double abatere) 
{
    double u1 = (double) rand() / RAND_MAX;
    double u2 = (double) rand() / RAND_MAX;
    double z = sqrt(-2 * log(u1)) * cos(2 * PI * u2);
    return media + z * abatere;
}

int poissonDistribution(double lambda) 
{
    double limit = exp(-lambda);
    double p = (double) rand() / RAND_MAX;
    int n = 0;
    while (p >= limit) {
        p = p * (double) rand() / RAND_MAX;
        n++;
    }
    return n;
}

void generate_and_save_distributions() {
    unsigned seed = (unsigned)time(NULL);
    srand(seed);

    FILE *normal_file = fopen("normal_distribution.txt", "w");
    if (normal_file == NULL) {
        perror("Eroare la deschiderea fișierului pentru distribuția normală");
        return;
    }

    for (unsigned i = 0; i < NUM_VALUES; i++) {
        double val = normalDistribution(0.0, 1.0);
        if (fprintf(normal_file, "%.20f\n", val) < 0) {
            perror("Eroare la scrierea în fișierul pentru distribuția normală");
            fclose(normal_file);
            return;
        }
    }

    if (fclose(normal_file) != 0) {
        perror("Eroare la închiderea fișierului pentru distribuția normală");
    }

    FILE *poisson_file = fopen("poisson_distribution.txt", "w");
    if (poisson_file == NULL) {
        perror("Eroare la deschiderea fișierului pentru distribuția Poisson");
        return;
    }

    for (unsigned i = 0; i < NUM_VALUES; i++) {
        int val = poissonDistribution(4.0);
        if (fprintf(poisson_file, "%d\n", val) < 0) {
            perror("Eroare la scrierea în fișierul pentru distribuția Poisson");
            fclose(poisson_file);
            return;
        }
    }

    if (fclose(poisson_file) != 0) {
        perror("Eroare la închiderea fișierului pentru distribuția Poisson");
    }

    printf("Distribuțiile au fost generate și salvate cu succes.\n");
}

