#include<stdio.h>
#include<String.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<time.h>
int main(){
	clock_t begin = clock();
	struct number
	{
		int y;
		int x1;
		int x2;
		int val;
	};
	char *line = NULL;
	size_t len = 0;
	size_t lineSize = 0;
	char** schematic = NULL;
	char** schematicTemp = NULL;
	int lineCount = 0;
	int lineLength = 0;
	int numCount = 0;
	struct number** numbers = NULL;
	struct number** numbersTemp = NULL;
	struct number* numberTemp = NULL;
	char* numBuff = NULL;
	int partSum = 0;
	int gearRatioSum = 0;
	int yMin,yMax,xMin,xMax;
	int gearCount;
	int gearRatio;
	
	while((lineSize = getline(&line, &len, stdin) != -1)){
		lineCount++;
		//Increase schematic size to fit new line
		schematicTemp = (char**) malloc(lineCount * sizeof(char**));
		memcpy(schematicTemp,schematic,(lineCount -1) * sizeof(*schematicTemp));
		free(schematic);
		schematic = schematicTemp;
		//Clean and copy line to schematic
		line[strcspn(line, "\n")] = 0;
		schematic[lineCount-1] = strdup(line);
		//Parse numbers and increase size of number array to fit new number
		for(int i = 0; i < strlen(line); i++){
			if(numberTemp == NULL && isdigit(line[i])){
				numCount++;
				numberTemp = (struct number*)malloc(sizeof(struct number));
				numberTemp->y = lineCount - 1;
				numberTemp->x1 = i;
			}
			if(numberTemp != NULL && (!isdigit(line[i]) || i == strlen(line)-1 ) ){
				numberTemp->x2 = i == strlen(line)-1 ? i : i-1;
				numBuff = (char*) malloc((numberTemp->x2 - numberTemp->x1+1) * sizeof(char));
				memcpy(numBuff,&line[numberTemp->x1],(numberTemp->x2 - numberTemp->x1+1));
				numberTemp->val = atoi(numBuff);
				free(numBuff);
				numbersTemp = (struct number**) malloc(numCount * sizeof(struct number**));
				memcpy(numbersTemp,numbers,(numCount -1) * sizeof(*numbersTemp));
				free(numbers);
				numbers = numbersTemp;
				numbers[numCount-1] = numberTemp;
				numberTemp = NULL;
			}
		}
	}
	//check surrounding characters of each number and add symbol-adjacent ones to sum
	for(int i = 0; i < numCount; i++){
		yMin = numbers[i]->y == 0 ? numbers[i]->y : numbers[i]->y -1 ;
		yMax = numbers[i]->y == lineCount-1 ? numbers[i]->y : numbers[i]->y +1;
		xMin = numbers[i]->x1 == 0 ? numbers[i]->x1 : numbers[i]->x1 -1;
		xMax = numbers[i]->x2 == strlen(schematic[numbers[i]->y]) -1 ? numbers[i]->x2 : numbers[i]->x2+1;
		for(int y = yMin;y <= yMax;y++){
			for(int x = xMin; x <= xMax; x++){
				if(!isdigit(schematic[y][x]) && schematic[y][x] != 46){
					partSum += numbers[i]->val;
					y = yMax + 1;
					x = xMax + 1;
					break;
				}
			}	
		}
	}
	//Check each gear for adjacent numbers and add their sum (if only 2)
	for(int y = 0; y < lineCount; y++){
		for(int x = 0; x < strlen(schematic[y]);x++){
			if(schematic[y][x] == 42){
				gearRatio = 0;
				gearCount = 0;
				for(int i = 0; i < numCount; i++){
					if(numbers[i]->y <= y +1 &&  numbers[i]->y >= y-1 && numbers[i]->x1 <= x+1 && numbers[i]->x2 >= x-1){
						gearCount++;
						if(gearRatio == 0) gearRatio += numbers[i]->val;
						else gearRatio *= numbers[i]->val;
					}
				}
			if(gearCount == 2) gearRatioSum += gearRatio;
			} 
		}
	}
	 
	printf("Part 1 : %d\n",partSum);
	printf("Part 2 : %d\n",gearRatioSum);
	clock_t end = clock();
	printf("exec time : %f ms\n", (double)((end - begin) / CLOCKS_PER_SEC)*1000);
	return 0;
}