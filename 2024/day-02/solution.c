#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int attempt(char *line, int prev,int carry,int safe, int airbag,int direction,int skip, int index) {
		char* token;
		int val;
		int result = 0;
		if(skip == 0){
			token = strtok_r(line," \n",&line);
			
			if (token == NULL) {
				
				return safe+airbag;
			}
			val = atoi(token);
		}
		else{
			val = carry;
			carry = -1;
		}
		
		if( direction == 0){
			if(carry == -1){
				direction = (val - prev > 0) - (val - prev < 0);
			}
			else{
				direction = (prev - carry > 0) -  (prev - carry < 0);
			}
		}
		
		if( abs(val - prev) > 3 || abs(val - prev) == 0 || ( (val - prev > 0) - (val - prev < 0) != direction)){
			if(airbag == 0){
				
				
				return 0;
			}
			airbag = 0;
			if(carry == -1 || (carry != -1 && !( abs(carry - val) > 3 || abs(carry - val) == 0) && index == 2 )){	
			
				result = attempt(strdup(line),val,carry,safe,airbag,0,0,index+1);
				if(result == 1 ) return result;
			}
			if(carry != -1 && !( abs(carry - val) > 3 || abs(carry - val) == 0) && index != 2 && ( val - carry> 0) - ( val - carry< 0) == direction){
				
				result = attempt(strdup(line),val,carry,safe,airbag,direction,0,index+1);
				if(result == 1 ) return result;
				
				
			}
			if(index == 2){
				
				result = attempt(strdup(line),prev,val,safe,airbag,0,1,index);
				if(result == 1 ) return result;
			}
			
			result = attempt(strdup(line),prev,carry,safe,airbag,direction,0,index+1);
			return result;
			
		}
		
		return attempt(strdup(line),val,prev,safe,airbag,direction,0,index+1);
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
		
		if(result == 2){
			part1++;
			part2++;
		}
		else if(result == 1){
			part2++;
		}
	}
	
	printf("%d\n",part1);
	printf("%d\n",part2);
	return 0;
}