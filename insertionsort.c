//Tro Hovasapian
//Insertion Sort
//Lab 5
//Coen 12L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10000000

//insertion sort function. O(n^2)
void insertionSort(int arr[], int n, char **names)
{
	int i, key, j;
	char* temp; //creating temp array for chars
	
	for (i = 1; i < n; i++)
	{
		temp = names[i];
		key = arr[i];
		j = i - 1;
	

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			names[j + 1] = names[j];
			j = j - 1;
		}
		arr[j + 1] = key;
		names[j + 1] = temp;
	}
}


int main()
{
	//created file pointer and opens the text file
	FILE *fp;
	fp = fopen("test.txt", "r");
	//allocating size for the arrays
	int *arr = malloc(MAX_SIZE*sizeof(int));
	char **names = malloc(MAX_SIZE*sizeof(char*));

	int i;
	for(i = 0; i < MAX_SIZE; i++)
	{
		names[i] = malloc(sizeof(char*)*20);
	}
	i = 0;
	int n = 0; 
	//counter for amount of numbers and strings in the text file
	while(!feof(fp))
	{		
		fscanf(fp,"%d %s\n",&arr[i], names[i]);
		i++;
		n++;
	}
	int p;

	//calls  the insertion sort function with our unsorted numbers and strings
	insertionSort(arr, n, names);

	//prints sorted numbers and strings
	for(p = 0; p < n; p++) 
	{
		printf("%d %s\n", arr[p], names[p]);
	}
	free(arr);
	free(names);
	fclose(fp);

}


