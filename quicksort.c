// Quick sort in C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void print1(int a[]){
	int i;
	for(i = 0; i < 20; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}



void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) {
  
  int pivot = array[high];
  
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      i++;
      
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);
  
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    int pi = partition(array, low, high);
    
    quickSort(array, low, pi - 1);
    
    quickSort(array, pi + 1, high);
  }
}


void main(){
	
	int size = 20;
	int arr[size],i;
	for(i=0;i<size;i++){
		arr[i]=rand()%500;
	}
	print1(arr);

        clock_t t;
        t = clock();
    	
	quickSort(arr, 0, size - 1);
	printf("******ARRAY AFTER SORTING**********\n ");
	print1(arr);
	t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC; 	
	printf("ARRAY SIZE = %d\n", size);
	printf("Normal_quicksort() took %f seconds for sorting \n", time_taken);
	
}   
