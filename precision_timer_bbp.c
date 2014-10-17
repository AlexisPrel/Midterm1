/*
*  Chronometer for the function pi_bbp.
*   returns t in sec/iteration
*   first rough estimation with 10^5 iterations
*   then deduces the number of iterations n needed to obtain a total time T ~= 10.0s
*   finally measures T for n iterations -> t = T/n
*/

#include <stdio.h>
#include <time.h>
#include <math.h>
#include "pi_funs.h"

double precision_timer_bbp(int n2)
{
    /* variables definition */
    int n;
    double t_rough,t,T,pi;
    clock_t begin, end;

    /* first rough estimationm this time we can not do it just once because t_rough would be too small 
    *   => 10^5 appeared to be a good choice. */
    begin = clock();
    for(int i=1;i<pow(10,5);i++)
        pi= pi_bbp(n2);
    end = clock();
    t_rough = (double)(end - begin) /pow(10,5)/CLOCKS_PER_SEC;
    
    /* calculus of n. We need ceil for it to be an integer */
    n = ceil(10./t_rough);
    
    /* total time for n iterations */
    begin = clock();
    for(int i=1;i<n;i++)
        pi = pi_bbp(n2);
    end = clock();
    T = (double)(end - begin) / CLOCKS_PER_SEC;
    
    /* output */ 
    t = T/((double)n);
    return t;
}
