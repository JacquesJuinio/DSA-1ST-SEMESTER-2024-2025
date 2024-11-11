#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
	char type[20];
	bool lane;  //true = main, false = diversion
	char direction[20];
	int time; 
} Traffic;

Traffic newTraffic(char type[], bool lane, char direction[], int time);
void displayTraffic(Traffic t);

int main(){
	
	Traffic list[20];
	Traffic t;
	
	FILE *fp;
	
	fp = fopen("traffic_result.dat", "rb");

	bool flag = false;
	int totalTime = 0;
	if(fp != NULL){
		while(fread(&t, sizeof(Traffic), 1, fp)){
			displayTraffic(t);
			
			if(strcmp(t.type, "Vehicle") == 0){
				totalTime += t.time;
				flag = false;
				
			}
			
			if(strcmp(t.type, "Pedestrian") == 0 && !flag){
				printf("\nTotal Time before a main pedestrian will be able to cross the road: %ds\n\n", totalTime);
				flag = true;
				totalTime = 0;
			}
		}
	}
	
	
	
	fclose(fp);
		
	return 0;
}

Traffic newTraffic(char type[], bool lane, char direction[], int time){
	Traffic t;
	strcpy(t.type, type);
	t.lane = lane;
	strcpy(t.direction, direction);
	t.time = time;
	return t;
}

void displayTraffic(Traffic t){
	if(t.lane == true){
		printf("Type: %s, Lane: Main, Direction: %s, Time: %ds\n", t.type, t.direction, t.time);
	}else{
		printf("Type: %s, Lane: Diversion, Direction: %s, Time: %ds\n", t.type, t.direction, t.time);
	}
}
