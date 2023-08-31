#include "raylib.h"
#include "autHolHeadFil.h"




int clientData(MaintenanceInfo* maDt,int numberClients,char word[10]){
	int i;
	for(i=0;i<numberClients;i++){
		if(TextIsEqual(maDt[i].cin,word)) return i;
	}
	return -1;
}