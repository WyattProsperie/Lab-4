#include <stdio.h>
#include <stdlib.h>

extern int sum_array(int *array, int count);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s datafile\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    int count;

    fscanf(file, "%d", &count);

    int *array = malloc(count * sizeof(int));

    for (int i = 0; i < count; i++)
    {
        fscanf(file, "%d", &array[i]);
    }

    fclose(file);

    int sum = sum_array(array, count);

    printf("Sum = %d\n", sum);

    free(array);

    return 0;
}