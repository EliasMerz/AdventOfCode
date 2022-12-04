#include<stdio.h>
#include<String.h>
#include<stdlib.h>
#include<math.h>

int main(){
	char *line =NULL;
	size_t len = 0;
	size_t lineSize = 0;
	char characters[312] = {0};
	int prioritySum = 0;
	int caseOffset = 0;
	int groupOffset = 0;
	int lineNumber = 1;
	int badgeSum = 0;
	while((lineSize = getline(&line, &len, stdin) != -1)){
		for(int i = 0; i < floor(strlen(line)/2)*2; i++) {
			caseOffset = (i < strlen(line)/2)? 0 : 52;
			characters[((line[i] < 97) ? line[i] -39: line[i] -97) + caseOffset + groupOffset]++;
			}
		for(int i = 0; i < 52; i++){
			if(characters[i+ groupOffset]!= 0 && characters[i+52+ groupOffset] != 0){
				prioritySum +=i+1;
				break;
			}
		}
		if(lineNumber%3 != 0) groupOffset += 104;
		else {
			for(int i = 0; i < 52; i++){
				if(characters[i]+characters[i+52] != 0 && characters[i +104]+characters[i+156] != 0 && characters[i+208]+characters[i+260] != 0 ){
					badgeSum +=i+1;
					break;
				}
			}
			groupOffset =0;
			memset(characters, 0, sizeof(characters));
		}
		lineNumber++;	
	}
	free(line);
	printf("Part 1 : %d\n",prioritySum);
	printf("Part 2 : %d\n",badgeSum);
	return 0;
}