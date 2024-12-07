#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int part1 = 0;
	int part2 = 0;
	char** lines;
	char* line = NULL;
	size_t bufSize = 0;
	size_t lineSize;
	size_t columns	=0;
	size_t rows= 0;
	
	lines = (char**) malloc(sizeof(char*)*140);
	
	while( (lineSize = getline(&line, &bufSize, stdin)) != -1){
		if(columns == 0){
			columns = lineSize -1; 
		}
		lines[rows] = (char*) malloc( sizeof(char) * columns);
		memcpy(lines[rows],line, columns);
		rows++;
	}
	
	for(int i = 0; i  < rows;i++){
		for(int j = 0; j < rows;j++){
			if(lines[i][j] == 'X'){
				if(j < rows - 3){
					if(lines[i][j+1] == 'M'&& lines[i][j+2] == 'A'&& lines[i][j+3] == 'S') part1++;
				}
				if(2 < j ){
					if(lines[i][j-1] == 'M'&& lines[i][j-2] == 'A'&& lines[i][j-3] == 'S') part1++;
					
				}
				if(i < rows -3){
					if(lines[i+1][j] == 'M'&& lines[i+2][j] == 'A'&& lines[i+3][j] == 'S') part1++;
				}
				if(2 < i ){
					if(lines[i-1][j] == 'M'&& lines[i-2][j] == 'A'&& lines[i-3][j] == 'S') part1++;
				}
				if(j < rows - 3 && i < rows -3){
					if(lines[i+1][j+1] == 'M'&& lines[i+2][j+2] == 'A'&& lines[i+3][j+3] == 'S') part1++;
				}
				if(2 < j  && 2 < i ){
					if(lines[i-1][j-1] == 'M'&& lines[i-2][j-2] == 'A'&& lines[i-3][j-3] == 'S') part1++;
				}
				if(j < rows - 3  && 2 < i ){
					if(lines[i-1][j+1] == 'M'&& lines[i-2][j+2] == 'A'&& lines[i-3][j+3] == 'S') part1++;
				}
				if(2 < j  && i < rows -3){
					if(lines[i+1][j-1] == 'M'&& lines[i+2][j-2] == 'A'&& lines[i+3][j-3] == 'S') part1++;
				} 
			}
			if(0 < j  && j < rows-1 && 0 < i  && i < rows-1){
				if(lines[i][j] == 'A'){ 
				if(lines[i-1][j-1] + lines[i+1][j+1] ==  lines[i-1][j+1] + lines[i+1][j-1] && lines[i-1][j-1] + lines[i+1][j+1] == 'S' + 'M') part2++;
				}
			}
		}
		
	}
	free(lines);
	free(line);
	printf("%d\n",part1);
	printf("%d\n",part2);
	return 0;
}