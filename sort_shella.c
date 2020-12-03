#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

double pow(double x, double y){
	double result = 1;
	for(int i = 0; i<y; i++){
		result*=x;
	}
	return result;
}

void sort(int *a, int n){
	int i = 1;
	while(3*i <= n){
    	for(int j = i; j<n; j++){
        	for(int k = j-i; (k>=0)&&(a[k]>a[k+i]); k-=i){
	            int m = a[k];
	            a[k] = a[k+i];
				a[k+i] = m;
        	}
        }
        if(i%2==0){
			i = 9*pow(2, i)-9*pow(2, i/2)+1;
		} else {
			i = 8*pow(2, i)-6*pow(2, i/2)+1;
		}
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
    
    for(int i = 0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n%ld", time_stop());
    free(a);
    return 0;
}
