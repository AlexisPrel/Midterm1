/*
 * Main program that calls other functions one by one and outputs their result in a meaningful way.
 */
 
/* Usual libraries used here */
#include <stdio.h>
#include <math.h>
#include <time.h>

/* Project-specific needed files */
#include "pi_funs.h"
#include "precision_timer_leibniz.c"
#include "precision_timer_bbp.c"

int main(void)
{
    /* variable definitions sorted by order of first value assignement */
    double error = 1, eps = pow(10,-6);                         /* error needs an initial value > eps for loops to start.*/
    int n1, n2;
    double pi, t1, t2, ratio;
    
    /* Leibniz method: execution and search for a value of n1 such that error <= eps */
    printf("Using pi_leibniz:\n");  
    n1 = pow(10,5);  
    while(error > eps)                                          /* as long as the error is bigger than our targetted precisiob*/
    {
    	pi = pi_leibniz(n1);                                    /* we calculate an approximation of pi ... */
        error = fabs(pi - M_PI);                                /* ... and its absolute error ... */        
        printf("%8d   %20.15f   %20.15f\n", n1, pi, error);
    	n1 += pow(10,5);                                        /* ... for increasing values of n1. */
    }
    
    n1 -= pow(10,5);                                            /* we undo the last incrementation */
    printf("n1: %d    pi_leibniz(n1): %f\n",n1,pi);             /* and output desired value with corresponding approximation */
    printf("\n");                                               /* some space for output clarity */
   
   	error = 1;                                                  /* re-initialisation of used variable */
   	
   	/* BBP Method: for comments refers to Leibniz method */
   	printf("Using pi_bbp:\n");
   	n2 = 1;
    while(error > eps)
    {
        pi = pi_bbp(n2);
        error = fabs(pi - M_PI);                                /* absolute error */
        printf("%8d   %20.15f   %20.15f\n", n2, pi, error);
        n2 += 1;
    }
    
    n2 -= 1;                                                    /* we undo the last incrementation */
    printf("n2: %d    pi_bbp(n2): %f\n",n2,pi);                 /* and output desired value with corresponding approximation */
    printf("\n");                                               /* some space for output clarity */

	/* Timing for both functions */
	t1 = precision_timer_leibniz(n1);
	t2 = precision_timer_bbp(n2);
	ratio = round(t1/t2);                                       /* round() makes the ratio be an integer */
	/* Results output */
	printf("t_leibniz: %20.15f sec per iteration\n",t1); 
	printf("t_bbp: %20.15f sec per iteration\n",t2);
    printf("Ratio: %21.0f \n", ratio);

    return 0;
}

