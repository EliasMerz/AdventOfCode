#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int extractNumber(char* string, int index1,int index2) {
	int number = 0;
	for(int j = index1; j <= index2; j++){
		number = number * 10 +  (string[j]- '0');			
	}
	return number;
}
int main(){
	int part1 = 0;
	int part2 = 0;
	char* line = NULL;
	size_t bufSize = 0;
	size_t lineSize;
	int num1 = 0;
	int num2 = 0;
	int rules[100][32];
	int countNum = 0;
	int numbers[32];
	int orderedNumbers[32];
	int correct = 1;
	for(int i = 0; i < 100;i++){
		rules[i][0] = 0;
	}
	
	while( (lineSize = getline(&line, &bufSize, stdin)) == 6){
		
		sscanf(line,"%d|%d\n",&num1,&num2);
		rules[num2][0]++;
		rules[num2][rules[num2][0]] = num1;
	}

	while( (lineSize = getline(&line, &bufSize, stdin)) != -1){
		correct = 1;
		countNum = (lineSize+1+(lineSize%2)) / 3;
		
		for(int i = 0; i < countNum;i++){
			numbers[i] = 0;
			for(int j = (i*3); j <= (i*3)+1; j++){
				numbers[i] = numbers[i] * 10 +  (line[j]- '0');			
			}
		}
		
		for(int i = 0; i < countNum;i++){
			for(int j = 0; j < countNum - i ;j++){
			int isLeaf = 1;
				for(int k = 1; k <= rules[numbers[j]][0];k++){
					for(int l = j; l < countNum-i;l++){
						if (rules[numbers[j]][k] == numbers[l]) {
						correct = 0;
						isLeaf = 0;
						break;
						}
					}
					if(isLeaf == 0) break;
				}
				if(isLeaf == 1){
					orderedNumbers[i] = numbers[j];
					for(int k = j; j < countNum - i -1; j++){
						numbers[j] = numbers[j +1];
					}
					break;
				}
			}
		}
		orderedNumbers[countNum-1] = numbers[0];
		
		
		if(correct == 1){
			part1 += orderedNumbers[(countNum/2)];
		}
		else {
			part2 += orderedNumbers[(countNum/2)];
		}
		
	}
	
	
	free(line);
	printf("%d\n",part1);
	printf("%d\n",part2);
	return 0;
}