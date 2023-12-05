#include<stdio.h>
#include<String.h>
#include<stdlib.h>
#include<math.h>

int main(){
	
	char *line =NULL;
	size_t len = 0;
	size_t lineSize = 0;
	char *set,*draw,*setRemainder,*drawRemainder;
	
	char color[10];
	int gameId;
	int gameSum = 0;
	int powerSum = 0;
	int validGame;
	int drawAmount;
	//red,green,blue
	int draws[3];
	int limits[] = {12,13,14};
	int powers[3];
	while((lineSize = getline(&line, &len, stdin) != -1)){
		validGame = 1;
		powers[0] = 0;
		powers[1] = 0;
		powers[2] = 0;
		//Read Game ID
		sscanf(strtok(line, ":"),"Game %d",&gameId);
		//First Set
		set = strtok_r(strtok(NULL, ":"), ";",&setRemainder);
		while(set != NULL){
			draws[0] = 0;
			draws[1] = 0;
			draws[2] = 0;
			
			//First draw
			draw = strtok_r(set, ",",&drawRemainder);
			while(draw != NULL){
				//Read amount and color
				sscanf(draw,"%d %s",&drawAmount,&color);
				//Add amount to color-counter
				
				if(strcmp(color,"red") == 0 ) draws[0] += drawAmount;
				else if(strcmp(color,"green") == 0 ) draws[1] += drawAmount;
				else if(strcmp(color,"blue") == 0 ) draws[2] += drawAmount;
				
				//Next draw
				draw = strtok_r(NULL, ",",&drawRemainder);
			}
			
			// Add gameId to sum if game is possible
			if( !(draws[0] <= limits[0] && draws[1] <= limits[1] && draws[2] <= limits[2])) validGame = 0 ;
			
			powers[0] = draws[0] > powers[0] ? draws[0] : powers[0];
			powers[1] = draws[1] > powers[1] ? draws[1] : powers[1];
			powers[2] = draws[2] > powers[2] ? draws[2] : powers[2];
			//Next set
			set = strtok_r(NULL, ";",&setRemainder);
		}
		
		if(validGame) gameSum += gameId;
		powerSum += powers[0] * powers[1] * powers[2];
	}
	free(line);
	printf("Part 1 : %d\n",gameSum);
	printf("Part 2 : %d\n",powerSum);
	return 0;
}