#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	if(argc < 2){
		printf("USAGE : ./A02_ALGORITM <unsorted data size>\n");
		exit(0);
	}

	unsigned int MAX_CNT = atoi(argv[1]);
	int a[MAX_CNT];
	int b[MAX_CNT];

	int min=0;
	int max=0; 
	int tmp=0;
	int k=MAX_CNT;

	srand( (unsigned)time(NULL) + (unsigned)getpid() );
	for(int i=0; i<MAX_CNT; i++){
		a[i] = rand()%150000;
		b[i] = a[i];
	}

	clock_t start, end;
	
	printf("Data size : %d\n", MAX_CNT); 
	

	// Original Select Sort Algorithm
	printf("Original select sort started. If the data size is too big, it can take long time...\n");
	start = clock();
	for (int i=0; i< MAX_CNT -1; i++){
		min = i;
		for(int j= i+1; j<MAX_CNT; j++){
			if(a[j] < a[min])
				min = j;
		}
		tmp = a[min];
		a[min] = a[i];
		a[i] = tmp;
	}
	end = clock();	
	printf("Original Algorithm : %.8lf sec\n", (double)(end-start)/CLOCKS_PER_SEC);
	

	// Improved Select Sort Algorithm
	printf("Improved select sort started. If data size is too big, it can take long time...\n");
	start = clock();
	for (int i=0; i<MAX_CNT -1; i++){
		min = i; max = MAX_CNT -1-i;
		for(int j= i+1; j<k; j++){
			if(b[j] < b[min])
				min = j;
			if(b[MAX_CNT-j] > b[max])
				max = MAX_CNT-j;
		}
		tmp = b[min];
		b[min] = b[i];
		b[i] = tmp;

		tmp = b[max]; 
		b[max] = b[MAX_CNT-1-i];
		b[MAX_CNT-1-i] = tmp;
		k--;
	}
	end = clock();

	printf("Improved Algorithm : %.8lf sec\n", (double)(end-start)/CLOCKS_PER_SEC);

	return 0;
}
