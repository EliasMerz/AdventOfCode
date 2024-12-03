#include<stdio.h>
#include<String.h>
#include<stdlib.h>
#include<math.h>

int check(int val, int lastVal, int* direction){
	
			if( abs(val - lastVal) > 3 || abs(val - lastVal) == 0 || (*direction != 0 && (val - lastVal > 0) - (val - lastVal < 0) != *direction)){
					return 0;
			}
			if(*direction == 0) *direction = (val - lastVal > 0) - (val - lastVal < 0);
			return 1;
			
}

int attempt(char *line, int lastVal,int carry,int safe, int airbag,int direction ,int skip, int index) {
		char* token;
		int val;
		int resultA;
		int resultB;
		if(skip == 1){
			val = carry;
		}
		else{
			token = strtok_r(line," \n",&line);
			
			if (token == NULL) {
				return safe + airbag;
			}
			val = atoi(token);
		}
		if(check(val,lastVal,&direction) == 0){
			safe = 0;
			if(airbag == 0 && safe == 0) {
				return 0;
			}
			else if(safe == 0 && airbag == 1){
				airbag = 0;
				safe = 1;
				if(carry != -1){ 
				resultA = attempt(strdup(line),lastVal,carry,safe,airbag,direction,0,index+1);
				resultB = attempt(strdup(line),carry,val,safe,airbag,direction,1,index+1);
				if(resultA < resultB) return resultB;
				else return resultA;
				}
			}
			
		}
		
		return attempt(line,val,lastVal,safe,airbag,direction,0,index+1);
	}

int main(){
	int part1 = 0;
	int part2 = 0;
	
	char line[64];
	char* token;
	
	int result;
	
	while(fgets(line, sizeof(line), stdin)){
		
		char *line_copy = strdup(line);
		token = strtok_r(line_copy," \n",&line_copy);
		result = attempt(line_copy,atoi(token),-1,1,1,0,0,1);
		if(result == 2) part1++;
		else if(result > 0) part2++;
	}
	part2+=part1;
		
	
	printf("%d\n",part1);
	printf("%d\n",part2);
	return 0;
}