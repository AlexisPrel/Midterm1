/*
*  Chronometer for the function pi_leibniz.
*   returns t in sec/iteration
*   first rough estimation with 1 iteration
*   then deduces the number of iterations n needed to obtain a total time T ~= 7.5s
*   finally measures T for n iterations -> t = T/n
*/

#include <stdio.h>
#include <time.h>
#include <math.h>
#include "pi_funs.h"

double precision_timer_leibniz(int n1)
{
    /* variables definition */
    int n;
    double t_rough,t,T,pi;
    clock_t begin, end;

    /* first rough estimation */
    begin = clock();
    pi= pi_leibniz(n1);
    end = clock();
    t_rough = (double)(end - begin) / CLOCKS_PER_SEC;
    
    /* calculus of n. We need ceil for it to be an integer */
    n = ceil(7.5/t_rough);
    
    /* total time for n iterations */
    begin = clock();
    for(int i=1;i<n;i++)
        pi = pi_leibniz(n1);
    end = clock();
    T = (double)(end - begin) / CLOCKS_PER_SEC;
    
    /* output */
    t = T/((double)n);
    return t;
}
