#include <iostream>
#include <ctime>
#include <intrin.h>
#include <sys/time.h>

struct timeval tv1,tv2,dtv;
struct timezone tz;
void time_start() 
{ 
	gettimeofday(&tv1, &tz); 
}

long time_stop()
{ 
	gettimeofday(&tv2, &tz);
  	dtv.tv_sec= tv2.tv_sec -tv1.tv_sec;
  	dtv.tv_usec=tv2.tv_usec-tv1.tv_usec;
  	if(dtv.tv_usec<0) 
	{ 
		dtv.tv_sec--; 
		dtv.tv_usec+=1000000; 
	}
 	return dtv.tv_sec*1000+dtv.tv_usec/1000;
}

using namespace std;

unsigned long long pow(unsigned long long x, unsigned long long n)
{
    unsigned long long p = 1;
    for(int i = 0; i < n; i++)
    {
    	p *= x;	
	}
    return p;
}

unsigned long long factorial(unsigned long long n)
{
    unsigned long long p = 1;
    for(int i = 1; i <= n; i++)
	{
        p *= i;
    }
    return p;
}

int main()
{
	unsigned long long a = 20, c = 6000000;
	unsigned __int64 i, j, sum = 0;
	while(a--)
	{
		//int start_time =  clock();
		i = __rdtsc();
		//time_start();
 	 	factorial(c);
 	 	/*j = time_stop();
 	 	printf("%ld\n", j);*/
 	 	j = __rdtsc();
 	 	printf("%I64d\n", j - i);
 	 	/*sum += j - i;
 		int end_time = clock();
 		printf("%f\n", ((end_time - start_time) / 1000.0) * 1000);*/
	}
}
