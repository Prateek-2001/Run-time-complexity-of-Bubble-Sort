/**
 * Program to check Bubble_sort runtime analysis
 *
 * Compilation : gcc bubblesort.c
 * Execution : ./Bubble_sort
 */
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

//Bubble Sorting
void bubblesort(int array[], int size, int type){
	
	// Loop to traverse through the array 
	for (int i = 0; i < size - 1 ; ++i){

		for (int j = 0; j < size - i - 1; ++j){
			
		//Comparing the elements in Ascending order
			if (type == 1){
		       if (array[j] > array[j + 1]){
				
			       //Swapping of elements
		       		int temp = array[j];
		 		array[j] = array[j + 1];
				array[j + 1] = temp;
		       
		       }
		}
			//Comparing the elements in Descending order
				if (type == 2){
				if (array[j] < array[j+1]){
					
					//Swapping of elements
					int temp = array[j];
		 			array[j] = array[j + 1];
					array[j + 1] = temp;
				}
			
		       }
		}
	}
}	

/*
* type 1-> Sort Numbers in Ascending Order
* type 2-> Sort Numbers in Descending Order
*/

int main(){
	
	int sample_size, data, type;

	struct timeval start, end;

	printf("Enter Sample Size:");
	
	scanf("%d", &sample_size);
	
	printf("Enter Ascending (1) or Descending Order (2):");

	scanf("%d", &type);

	int array[sample_size];

	for (int i = 0; i < sample_size; i++){
		
		array[i] = rand();
	}
	
	gettimeofday(&start, NULL);
	
	bubblesort(array, sample_size, type);
	
	gettimeofday(&end, NULL);
 
    	long seconds = (end.tv_sec - start.tv_sec);

    	long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
 	
	// Output in Seconds and Microseconds
    	printf("The elapsed time is %ld seconds and %ld micros\n", seconds, micros);

	return 0;
} 
