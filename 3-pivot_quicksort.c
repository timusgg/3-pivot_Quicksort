/* THIS IS THE SAMPLE PROGRAM OF 3-PIVOT QUICKSORT WITH AN SAMPLE ARRAY OF 2O ITEMS*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void print1(int a[]){
	int i;
	for(i = 0; i < 20; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}


void swap(int a[], int x, int y) {
	int temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}


void insertionsort(int a[], int lo, int hi) {
	for (int i = lo + 1; i <= hi; i++) {
            for (int j = i; j > lo && a[j] < a[j - 1]; j--) {
                swap(a, j, j - 1);
            }
    }
}

// the QUICKSORT algorithm

void quicksort(int arr[], int left, int right){



//This part acts a termination condition for recursive calls
        
//if length is less than 3, that is only two elements in the sub-array 
//then put the smaller one first and the greater one second
//if the array part is bigger then we can set some minimum threshold value
//for the sub-arrays so that we can sort those smaller sub-arrays
//using insertion sort but in our case we have not used it


int length = right - left + 1;

if (length < 3) {
		if(arr[0] > arr[1] && length > 0){
			int temp = arr[1];
			arr[1] = arr[0];
			arr[0] = temp;	
		}
	    return;
	}

//termination condition ends



/*Pivot Selection and Pointer Intialization part*/

//this part selects three pivots and sorts them
//then it takes the middle pivot to 
//the [left + 1] index 
int mid = (left + right)/2;

    if (arr[mid] < arr[left]){ 
    	int t = arr[mid]; 
    	arr[mid] = arr[left]; 
   	arr[left] = t; 
    }
    if (arr[right] < arr[mid]){ 
    	int t = arr[right]; 
    	arr[right] = arr[mid]; 
    	arr[mid] = t;
            	if (t < arr[left]){ 
            		arr[mid] = arr[left]; 
            		arr[left] = t; 
            	}
     }
     //printf("ARRAY AFTER PIVOT SELECTION\n");
     //print1(arr);
      
      
    int p = arr[left];
    int q = arr[mid];
    int r = arr[right];
    swap(arr, left + 1, mid);
    //printf("Array after reordering pivots\n");
    //print1(arr);
     
    //check only for first five lines of output for checking pivot selection
    
    int a = left + 2;
    int b = left + 2;
    int c = right - 1;
    int d = right - 1;
    
// pivot seletion and pointer initialization part ends here.   
    
    
/* The  Partitioning Part begins.*/
    
    while (b <= c){
    	while (arr[b] < q && b <= c){
    		if (arr[b] < p){
    			swap(arr, a, b);
    			a++;		
    		}
    		b++;
    	
    	}
    	while (arr[c] > q && b <= c){
		if (arr[c] > r){
			swap(arr, c, d);
			d--;
		}    	
		c--;
	}
    	if (b <= c){
    		if (arr[b] > r){
    			if (arr[c] < p){
    				int temp;
    				swap(arr, b, a);
    				swap(arr, a, c);
    				a++;
    			}
    			else{
    				swap(arr, b, c);
    			}
    			swap(arr, c, d);
    			b++;
    			c--;
    			d--;
    		}else{
    		if(arr[c] < p){
    			swap(arr, b, a);
    			swap(arr, a, c);
    			a++;
    		}
    		else{
    			swap(arr, b, c);
    		}
    		b++;
    		c--;
    	
             }	
    	}
    }
    a--;
    b--;
    c++;
    d++;
    swap(arr, left + 1, a);
    swap(arr, a, b);
    a--;
    swap(arr, left, a);
    swap(arr, right, d);
   
   /*The partitioning part ends here.*/
   
   
   /*Recursion part starts here.*/
    
    quicksort(arr, left, a - 1);//sort the sub-array from left i.e, 0 to a - 1
    quicksort(arr, a + 1, b - 1);//sort the sub-array from a + 1 to b - 1 
    quicksort(arr, b + 1, d - 1);//sort the sub-array from b + 1 directly to d-1
                                 //ignore c it is included in the sub-array
    quicksort(arr, d + 1, right);//then at last from d+1 to right
    
    /*Recursion part ends here.*/
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
    	
	quicksort(arr, 0, size - 1);
	printf("******ARRAY AFTER SORTING**********\n ");
	print1(arr);
	t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC; 	
	printf("ARRAY SIZE = %d\n", size);
	printf("3_pivot_quicksort() took %f seconds for sorting \n", time_taken);
	
}   


