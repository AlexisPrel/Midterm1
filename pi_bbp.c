/*
* Returns an approximation of pi using the Bailey-Borwein-Plouffe series
* pi = sum{k,0,inf}(u_k)
* with u_k = 16^(-k) * (4/(8k+1) - 2/(8k+4) - 1/(8k+5) - 1/(8k+6))
*/

double pi_bbp(int n)
{
    double partial_pi= 0.;                       /* approximation of pi, improved at each iteration */
    double k8 = 0, a = 1;                        /* 8*k and 16^-k */
    double uk;
    for(double k =0; k <= n; k++)               /* n+1 iterations are needed to calculate the sum from 0 to n*/
    {
        uk = a*(4./(k8 + 1) - 2./(k8+4) - 1./(k8+5) - 1./(k8 +6) );
        partial_pi += uk;                       /* term u_k is added */
        k8 += 8;
        a /= 16;
    }
    return partial_pi;                          /* we return the sum */    
}
