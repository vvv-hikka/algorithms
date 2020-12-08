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

void sort(int*a, int low, int high) {
	int tmp;
	if(low<high){
		int low_copy = low;
		int high_copy = high;
		int middle = (a[low]+a[high])/2;
		while(low<=high){
			while(a[high]>middle){
				high--;
			}
			while(a[low]<middle){
				low++;
			}
			if(low<=high){
				tmp = a[high];
				a[high] = a[low];
				a[low] = tmp;
				low++;
				high--;
			}
		}
		sort(a, low_copy, high);
		sort(a, low, high_copy);
	}
}

int main(int argc, char * argv[]) {
	
	FILE * fp;
	fp = fopen(argv[1], "r");
    
    int n;
    
    fscanf(fp, "%d", &n);
	
    int * a = malloc(sizeof(int)*n);

    for(int i = 0; i<n; i++){
        fscanf(fp, "%d", &a[i]);
    }
    
	int high = n-1;
	int low = 0;
    
    time_start();
    sort(a, low, high);
    
    printf("%ld\r", time_stop());
    for(int i = 0; i<n; i++){
        printf("%d ", a[i]);
    }
    free(a);
    return 0;
}
