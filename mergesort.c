//Tro Hovasapian
//LAB 5
//COEN 12
//Merge Sort
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_SIZE 10000000

//merge function. O(n log n)
void merge(int *arr, char **names, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	

	//temp arrs
	int* L = malloc(n1*sizeof(int)); //left int
	int* R = malloc(n2*sizeof(int)); //right int
	char **namesL = malloc(n1*sizeof(char*)); //left str
	char **namesR = malloc(n2*sizeof(char*)); //right str

	//allocating space for string left and right
	int t;
	for(t = 0; t < n1; t++)
	{
	  namesL[t] = malloc(20*sizeof(char));
	}
	for(t = 0; t < n2; t++)
	  {
	    namesR[t] = malloc(20*sizeof(char));
	  }
	//copying data to temp arrs
	for(i = 0; i < n1; i++)
	{
		L[i] = arr[l + i];
		namesL[i] = names[l + i];
	}
	for(j = 0; j < n2; j++)
	{	
		R[j] = arr[m + 1 + j];
		namesR[j] = names[m + 1 + j];
	}
	//merge temp arrays
	i = 0;
	j = 0;
	k = l;
	while(i < n1 && j < n2)
	{
		if(L[i] <= R[j])
		{
			arr[k] = L[i];
			names[k] = namesL[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			names[k] = namesR[j];
			j++;
		}
		k++;

	}	
	//copy remaining elements of Left
	while(i < n1)
	{
		arr[k] = L[i];
		names[k] = namesL[i];
		i++;
		k++;
	}
	
	//copy remaining elemnts of Right
	while(j < n2)
	{
		arr[k] = R[j];
		names[k] = namesR[j];
		j++;
		k++;
	}

}

//sends args to the merge function
void mergeSort(int* arr, char **names, int l, int r)
{
	if(l < r)
	{
		int m = l + (r - l) / 2;

		mergeSort(arr, names, l, m);
		mergeSort(arr, names, m + 1, r);

		merge(arr, names, l, m, r);
	}

}

//main function that opens file and sends evreything to the merge and mergesort functions
int main()
{
	//file pointer that opens the text file
	FILE *fp;
	fp = fopen("test.txt", "r");	
	
	int *arr = malloc(MAX_SIZE*sizeof(int));
	char **names = malloc(MAX_SIZE*sizeof(char*));

	int c;
	for(c = 0; c < MAX_SIZE; c++)
		names[c] = malloc(20*sizeof(char));

	int i = 0;
	int n = 0;

	//scanning everything in text file
	while(!feof(fp))
	{
		fscanf(fp, "%d %s\n", &arr[i], names[i]);
		i++;
		n++;
	}

//sending everything to merge sort function unsorted

	mergeSort(arr, names, 0, n - 1);

//printing sorted list of numbs and strings
	int p;
	for(p = 0; p < n; p++)
	  {
		printf("%d %s\n", arr[p], names[p]);
	  }





}

