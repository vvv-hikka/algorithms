#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct timeval tv1,tv2,dtv;

struct timezone tz;

void time_start(){ 
	mingw_gettimeofday(&tv1, &tz); 
}

long time_stop(){ 
	mingw_gettimeofday(&tv2, &tz);

	dtv.tv_sec= tv2.tv_sec -tv1.tv_sec;

	dtv.tv_usec=tv2.tv_usec-tv1.tv_usec;

	if(dtv.tv_usec<0){ 
		dtv.tv_sec--; dtv.tv_usec+=1000000; 
	}

	return dtv.tv_sec*1000+dtv.tv_usec/1000;
}

void swap(int * a, int * b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


void tree(int * a, int n, int l){
    int min;
	while(2*l+2<n){
		if(a[2*l+1]<a[2*l+2]){
			min = 2*l+2;
		} else {
            min = 2*l+1;
        }
		if(a[min]>a[l]){
            swap(&a[min], &a[l]);
		}
		l = min;
	}
}

void sort(int*a, int n) {
    int tmp;
    for (int l = n/2-1; l>=0; l--){
        tree(a, n, l);
    }
    for (int i = n - 1; i > 0; --i){
        swap(&a[0], &a[i]);
        tree(a, i, 0);
    }
}

int main(int argc, char * argv[]){
	
	FILE * fp;
	fp = fopen(argv[1], "r");
    
    int n;
    
    fscanf(fp, "%d", &n);
	
    int * a = malloc(sizeof(int)*n);

    for(int i = 0; i<n; i++){
        fscanf(fp, "%d", &a[i]);
    }
    
    time_start();
    sort(a, n);
    
    printf("%ld\r", time_stop());
    for(int i = 0; i<n; i++){
        printf("%d ", a[i]);
    }
    free(a);
    return 0;
}
