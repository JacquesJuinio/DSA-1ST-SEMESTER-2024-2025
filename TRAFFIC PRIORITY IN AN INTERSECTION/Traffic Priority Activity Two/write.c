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
	
	list[0] = newTraffic("Vehicle", false, "Going Straight", 5);
	list[1] = newTraffic("Vehicle", true, "Going Straight", 3);
	
	list[2] = newTraffic("Vehicle", false, "Going Left", 2);
	list[3] = newTraffic("Vehicle", true, "Going Left", 1);
	
	list[4] = newTraffic("Vehicle", false, "Going Right", 4);
	list[5] = newTraffic("Vehicle", true, "Going Right", 6);
	
	list[6] = newTraffic("Pedestrian", false, "Going Left", 7);
	list[7] = newTraffic("Pedestrian", true, "Going Right", 8);
	
	list[8] = newTraffic("Pedestrian", true, "Going Left", 10);
	list[9] = newTraffic("Pedestrian", false, "Going Right", 9);
	
	
	list[10] = newTraffic("Vehicle", true, "Going Straight", 5);
	list[11] = newTraffic("Vehicle", false, "Going Straight", 7);
	
	list[12] = newTraffic("Vehicle", false, "Going Left", 9);
	list[13] = newTraffic("Vehicle", true, "Going Left", 11);
	
	list[14] = newTraffic("Vehicle", true, "Going Right", 20);
	list[15] = newTraffic("Vehicle", false, "Going Right", 6);
	
	list[16] = newTraffic("Pedestrian", true, "Going Left", 7);
	list[17] = newTraffic("Pedestrian", false, "Going Right", 8);
	
	list[18] = newTraffic("Pedestrian", false, "Going Left", 12);
	list[19] = newTraffic("Pedestrian", true, "Going Right", 10);
	
	FILE *fp;
	
	fp = fopen("traffic_result.dat", "wb");
	
	if(fp != NULL){
		fwrite(list, sizeof(Traffic), 20, fp);
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
		printf("Lane: Main, Direction: %s, Time: %d\n", t.direction, t.time);
	}else{
		printf("Lane: Diversion, Time: %d\n", t.direction, t.time);
	}
}
