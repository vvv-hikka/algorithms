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

void tree(int * a, int n, int i){
	int tmp;
	if(2*i+2<n){
		if(a[i]>a[2*i+1]){
			tmp = a[i];
			a[i] = a[2*i+1];
			a[2*i+1] = tmp;
		}
		if(a[i]>a[2*i+2]){
			tmp = a[i];
			a[i] = a[2*i+2];
			a[2*i+2] = tmp;
		}
		tree(a, n, 2*i+1);
		tree(a, n, 2*i+2);
	} else if(2*i+1<n){
		if(a[i]>a[2*i+1]){
			tmp = a[i];
			a[i] = a[2*i+1];
			a[2*i+1] = tmp;
		}
	}
}

void sort(int*a, int n) {
	for (int i = n/2; i >= 0; i--){
		//for (int l= n/2-1- i/2; l >=0; l--){
			tree(a, n, i);
		//}
	}
	if(n!=0){
		sort(&a[1], n-1);
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
