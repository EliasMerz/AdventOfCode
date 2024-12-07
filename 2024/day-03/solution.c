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
	int enabled = 1;
	while( (lineSize = getline(&line, &bufSize, stdin)) != -1){
		
		for(int i = 0; i < lineSize; i++ ){
			if((enabled == 0 && line[i] == 'd' &&  line[i+1] == 'o'&& line[i+2] == '(' &&line[i+3] == ')') ||(enabled == 1 && line[i] == 'd' &&  line[i+1] == 'o'&& line[i+2] == 'n' &&line[i+3] == '\''  && line[i+4] == 't'  &&line[i+5] == '(')  &&line[i+6] == ')' ){
				i = i+2+(enabled * 3);
				enabled = (enabled != 1);
				continue;
			}
			if(line[i] == 'm' &&  line[i+1] == 'u' && line[i+2] == 'l' && line[i+3] == '('){
				i = i +4;
				num1 = i;
				while( '0' <= line[i] && line[i] <= '9'){
					i++;	
				}
				if(num1 == i || line[i] != ',') continue;
				i++;
				num2 = i;
				while( '0' <= line[i] && line[i] <= '9'){
					i++;
				}
				if(num2 == i || line[i] != ')') continue;
				num1 = extractNumber(line,num1,num2-2);
				num2 = extractNumber(line,num2,i-1);
				if(enabled == 0){
					part1 += num1 * num2;
					continue;
				}
				part1 += num1 * num2;
				part2 += num1 * num2;
				
				
			}
		}
		
	}
	free(line);
	printf("%d\n",part1);
	printf("%d\n",part2);
	return 0;
}