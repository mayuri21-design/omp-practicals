#include <stdlib.h>  
#include <stdio.h>    
#include <omp.h>      
#define ARRAY_SIZE 8     
#define NUM_THREADS 4    

int main (int argc, char *argv[]) 
{
	int * p;
	int * q; 
	int * r;  
    int n = ARRAY_SIZE;                                   
	int total_threads = NUM_THREADS;    
	int i;       
    p = (int *) malloc(sizeof(int)*n);
	q = (int *) malloc(sizeof(int)*n);
    for(i=0; i<n; i++) {
        p[i] = i;
    }
    for(i=0; i<n; i++) {
        q[i] = i;
    }   
	omp_set_num_threads(total_threads);
	#pragma omp parallel
	{
		int id,i,Nthrds,istart,iend;
		id=omp_get_thread_num();
		Nthrds=omp_get_num_threads();
		istart=id*n/Nthrds;
		iend=(id+1)*n/Nthrds;
		if(id==Nthrds-1)iend=n;
		for(i=istart;i<iend;i++)
		{
			p[i]=p[i]+5;
		}
	} 
	printf("i\ta[i]\t+\tX\t=\ta[i]\n");
        for(i=0; i<n; i++) {
		printf("%d\t%d\t\t%d\t\t%d\n", i,q[i],5,p[i]);
        }
    free(p);  free(q);
	
	return 0;
}
