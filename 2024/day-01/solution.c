#include<stdio.h>
#include<String.h>
#include<stdlib.h>
#include<math.h>

#define MAX_LINES 1000
int compare(const void *a, const void *b) {
	return (*(int*)a - *(int*)b);
}

int main(){
	
	char *line =NULL;
	size_t len = 0;
	size_t lineSize = 0;
	
	
	int num1, num2;
	int col1[MAX_LINES], col2[MAX_LINES];
	
	int part1 = 0;
	int part2 = 0;
	
	int i = 0;
	int count= 0;
	
	while (scanf("%d   %d", &num1, &num2) == 2) {
		if (i < MAX_LINES) {
			col1[i] = num1; 
			col2[i] = num2;
			i++;
		}
	}
	
	qsort(col1, i, sizeof(int), compare);
    qsort(col2, i, sizeof(int), compare);
	
    for (int j=0; j<i; j++) {
		part1 += abs(col1[j] - col2[j]); 
		
		count=0;
		for(int k=0; k<i; k++){
			if (col1[j] == col2[k]){
				do{
					count++;
				}while(col1[j] == col2[k+count]);
				break;
			}
		}
		part2+= count*col1[j];
    }
	
	printf("%d\n",part1);
	printf("%d\n",part2);
	return 0;
}