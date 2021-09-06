#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main(int argc,char *argv[])
{
int num; //number of iterations for which mento carlo method run
printf("enter the number of iterations you want the loop to run");
scanf("%d",&num);

double x,y,z,pi;
int i;
int count=0;
int num_thread;
printf("enter the number of threads you wish to parallize the process");
scanf("%d",&num_thread);
printf("\n");
#pragma omp parallel firstprivate(x,y,z,i) shared(count)num_threads(num_thread)
{

    srand((int)time(NULL)^omp_get_thread_num()); //this gives random value through random()
    for(i=0;i<num;i++)
    {

        x=(double)rand()/(double)RAND_MAX;
        y=(double)rand()/(double)RAND_MAX;
        z=pow(((x*x)+(y*y)),0.5);
        if(z<=1)
        {
            count++;
        }


    }

}
pi=((double)count/(double)(num*num_thread))*4;
printf("The value of pie obtained is:%f\n",pi);
}
