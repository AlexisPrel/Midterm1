/*
* Returns an approximation of pi using the Leibniz series
* pi = 4*sum{i,0,inf}(u_i)
* with u_i = (-1^i)/(2i+1)
*/

#include <math.h>                                   /* we are using pow() from math lib */
double pi_leibniz (int n)
{
    double partial_pi_over4 = 0;
    for(int i=0; i <= n; i++)                       /* n+1 iterations are needed to calculate the sum from 0 to n*/
		partial_pi_over4 += pow(-1.,i)/(2.*i+1.);	/* term u_i is added */
    return 4*partial_pi_over4;                      /* multiplication by 4 in the end so the operation is not repeated */
}
