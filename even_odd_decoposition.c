#include <stdio.h>
#include <stdlib.h>

typedef int num_t;
/**
*eods- even/odd decomposition samples
*/
typedef struct _eods
{
    float *even;
    float *odd;
}eods;

/**
* EOD- finds the eods
* @input:
* @N: Number of samples
* Return: even and odd samples
*/
eods *EOD(float *input, num_t N)
{
    eods *samples = (eods *)malloc(sizeof(eods));
    samples->even = (float *)malloc(sizeof(float) * N);
    samples->odd = (float *)malloc(sizeof(float) * N);


    for (int n = 0; n < N; n++)
    {
        samples->even[n] = (input[n] + input[(N - n) % N]) / 2;
        samples->odd[n] = (input[n] - input[(N - n) % N]) / 2;
    }

    return (samples);
}

int main(void)
{
    float ex[] = {0.1, 8.9, 90.3, 8.0, 7.2, 9.0, 8.9, 12.3};

    eods *s = EOD(ex, 8);

    for (int i = 0; i < 8; i++)
        printf("\teven: %f\todd: %f\n", s->even[i], s->odd[i]);
}