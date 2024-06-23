#ifndef proiect_H
#define proiect_H

unsigned* makeRandArray(unsigned seed, unsigned n);
void printArray_u(unsigned* array, unsigned n);
int* makeRandLimitArray(int seed, unsigned n, int a, int b);
int* makeRandFlexiArray(unsigned n, int (*getNewElem)(int*, unsigned));
int getNextIncreasingElem(int* array, unsigned n);
int getNextDecreasingElem(int* array, unsigned n);
void printArray(int* array, unsigned n);

double normalDistribution(double media, double abatere);
int poissonDistribution(double lambda);
void generate_and_save_distributions();

#endif
