#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int main() 
{
	int i, j, n, l, r;
	time_t t;
	FILE *fp;
	fp=fopen("test.txt","w+");
	printf("enter number\n"); //asks user to enter number of 
	scanf("%d", &n);
	srand((unsigned) time(&t));
	char names[5][10] = {"Jay", "Marcus", "Ariana", "Alex", "Chris"};

	for(i=0;i<n;i++){
		r=rand()%n+1;
		//write the word to the file in a format of "00 name"
		fprintf(fp, "%d %s\n",r,names[i%5]);
	}
	fclose(fp);
	exit(EXIT_SUCCESS);
}
