#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int chooseByProb(int A[], int N) {
    int rnd,i,k,top = 0;
    for(i=0; i<N; i++) {
        top = top + A[i];
    }
    rnd = random() % top;
    k = A[0];
    i = 0;
    while(k <= rnd) {
        i++;
        k = k + A[i];
    }
    //printf("top: %d, rnd: %d\n", top, rnd);
    return i;
}

int main()
{
    int i,j, s, a,b,c;
    int k,l,m;
    int P[] = {10, 20, 5};
    srand(time(NULL));
    k = 0;
    l = 0;
    m = 0;
    for(j=0; j<100; j++)
    {
        a = 0;
        b = 0;
        c = 0;
        for(i=0; i<100; i++) {
            s = chooseByProb(P, 3);
            printf("%d ", s);
            if (s == 0)
                a++;
            else if (s == 1)
                b++;
            else if (s == 2)
                c++;
        }
        k = k + a;
        l = l + b;
        m = m + c;
        printf("\n%d %d %d\n", a,b,c);
    }
    s = k + l + m;
    printf("\n%2f %2f %2f\n", (float)k/s,(float)l/s,(float)m/s);
    return 0;
}
