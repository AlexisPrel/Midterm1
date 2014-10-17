/*
* Returns an approximation of pi using the Bailey-Borwein-Plouffe series
* pi = sum{k,0,inf}(u_k)
* with u_k = 16^(-k) * (4/(8k+1) - 2/(8k+4) - 1/(8k+5) - 1/(8k+6))
*/

#include <math.h>								/* we need this library for its pow() function */
double pi_bbp(int n)
{
    double partial_pi= 0;						/* approximation of pi, improved at each iteration */
    for(int k =0; k <= n; k++)					/* n+1 iterations are needed to calculate the sum from 0 to n*/
        partial_pi += pow(16,-k)*( (4./(8*k+1))- (2./(8*k+4)) - (1./(8*k+5)) - (1./(8*k+6))   ); /* term u_k is added */
    return partial_pi;							/* we return the sum */    
}
