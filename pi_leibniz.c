/*
* Returns an approximation of pi using the Leibniz series
* pi = 4*sum{i,0,inf}(u_i)
* with u_i = (-1^i)/(2i+1)
* thus u_i+1 = (-1)*(-1^i)/(2i+3) = (-1)*u_i*(2*i+1)/(2*i+3) = (2/(2i+3) -1)*u_i 
*/

double pi_leibniz (int n)
{
    double partial_pi_over4 = 0;
    double ui = 1;                                  /* u0 calculated once for good */
    for(int i=0; i <= n; i++)                       /* n+1 iterations are needed to calculate the sum from 0 to n*/
	{
		partial_pi_over4 += ui;                     /* term u_i is added */
		ui = (2./(2.*i+3) -1.)*ui;                  /* u_i+1 = f(u_i) */
	}
    return 4*partial_pi_over4;                      /* multiplication by 4 in the end so the operation is not repeated */
}
