# Phys 2200 - Computational Physics - Midterm Project 1
## General informations
-------	-----------:
Author	Alexis Prel 
Updated	10/16/2014

*Note: It is quite useless to mention those informations, but bragging with Markdown tables is fun.*
___
 
## Objectives
In this project, we perform a performance comparison between two well known method to approximate a value of pi,
our criteria being the time of execution needed for each algorithm to reach a given precision. 
Both algorithm (see below for further details) depend on a single parameter **n**. When **n** increases:
- the error pi-pi_approx decreases
- the time of execution increases



This leads us naturally to the following procedure:
1. Implementing the algorithm that gives an approximation of pi as a function of n for both methods.
2. For both methods, finding the value of n such that a given precision eps is reached.
3. Timing both methods
4. Drawing a comparison between the two times obtained. 
___

## In more details
### Series implemented
- The [Leibniz series](http://en.wikipedia.org/wiki/Leibniz_formula_for_%CF%80) read as follow: ![leibniz formula](http://upload.wikimedia.org/math/4/b/3/4b325f4142cab62b1786d8be1ac3be60.png)
- The [Bailey-Borwein-Plouffe series](http://en.wikipedia.org/wiki/Bailey%E2%80%93Borwein%E2%80%93Plouffe_formula) have a similar structure ![BBP formula](http://upload.wikimedia.org/math/5/3/5/535d2d106b4243d1f9872f916b273c7a.png)

Those series have common features:
- they are a sum over k of a function u(k)
- they converge to pi
- they are infinite and thus can not be calculated numerically. However, we can approximate the result by summing from 0 to **n**, where **n** is a finite integer.

A "for" loop thus do the sum quite simply.

```C
for(int k=0;k<=n;k++)
	pi_approx += ... /* expression of u(k)  comes here*/
```

Those two series are implemented in [pi_leibniz.c](./pi_leibniz.c) and [pi_bbp.c](./pi_bbp.c), which are thus extremely similar.
Actually, only the expression of u(k) differs, and a factor 4 introduced by Leibniz formula (*cf. above*).

### Finding n1 and n2 such that pi_leibniz(n1) < eps and pi_bbp(n2) < eps
As augmenting precision costs time, we want to find the minimum value of n for which 

### Timing a function
For a given value of **n** (**n1** or **n2** in our case) we can measure the time needed to execute the algorithm using the time library:

```C
#include <time.h>
#include "pi_funs.h"
double t;
clock_t begin, end;

begin = clock();
pi= pi_leibniz(n1);
end = clock();
t = (double)(end - begin) / CLOCKS_PER_SEC;
```
But this measure is somehow imprecise. We thus embed a loop between the two time measurements in order to execute the same function
many times. It is detailed in the timers files, [precision_timer_leibniz.c](./precision_timer_leibniz.c) and [precision_timer_bbp.c](./precision_timer_bbp.c).
In particular:
1. we first do a first approximation of the execution time
2. we deduce the number **n** of iterations needed for the total execution time of the loop to be  approx. 5-10s
3. we take a more precise measurement with the loop iterated **n** times.
### Comparisation

###  Additional information
The script [pi_funs.h](./pi_funs.h) allows a fast declaration of [pi_leibniz.c](./pi_leibniz.c) and [pi_bbp.c](./pi_bbp.c) in [the main function](./main1.c).
The [Makefile](./Makefile) asks the compiler for the creation of an executable **main1**, specifying its dependencies and the libraries needed.
The [gitignore file](./.gitignore) file allows updates without including files produced during compilation, or any other unwanted file.
The [readme](./readme.md) should not requires explanations, otherwise we would shift way to much on the right of the following axis: 


![credits go to http://xkcd.com/1343](http://imgs.xkcd.com/comics/manuals.png)


image taken from [http://xkcd.com/1343](http://xkcd.com/1343), shared accordingly with the author's [license](http://xkcd.com/license.html)
