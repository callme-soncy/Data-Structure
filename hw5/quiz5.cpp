#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
void get_in(int**, int**, int);
int* add(int*, int*, int);

int main(void) {
    int count, i;
    int* in1 = NULL, * in2 = NULL, * result = NULL;
    printf("# of input pairs: ");
    scanf("%d", &count);
    get_in(&in1, &in2, count);
    result = add(in1, in2, count);
    for (i = 0; i < count; i++)
        printf("%d + %d = %d\n", in1[i], in2[i], result[i]);

    free(in1);
    free(in2);
    return 0;
}

void get_in(int** in1, int** in2, int count)
{
    int i = 0;
    *in1 = (int*)malloc(count * sizeof(int));
    *in2 = (int*)malloc(count * sizeof(int));


    if (in1 != NULL && in2 != NULL)
    {
        //
        while (count > 0)
        {
            printf("in1 in2 : ");

            scanf("%d %d", *in1 + i, *in2 + i);
            i++;
            count--;
        }
    }

    printf("done");
}

int* add(int* in1, int* in2, int count)
{
    int i = 0;
    int* p;
    p = (int*)malloc(count * sizeof(int));
    while (count > 0)
    {
        p[i] = in1[i] + in2[i];
        count--; i++;
    }
    return p;
}
