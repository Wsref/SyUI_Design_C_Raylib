#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autHolHeadFil.h"

/*mast3mltx realloc because dart liya lot of problems
 so drt had funct "nombLingnData(void)" alternativ kathsab liya hiya 
 lawla x7al mn str kayn f l file*/
int nombLingnData(char* pathTofile){
    int nombre = 0;
    char* data;
    data = (char*)malloc(sizeof(char)*200);
    FILE *file;
    file = fopen(pathTofile,"r");
    while(fgets(data,200,file)!=NULL) nombre++;
    fclose(file);
    free(data);
    return nombre;
}

/*----------------------------------Employ get Data------------------------------------------------------------------------------------*/

mydataEmpl* getDataFromFileEmpl(int nomData,char* pathTofile){
    
	FILE *file;
	char data[200];
	char ins[100];
	int i = 0;
	int genre = 0;
	int nombreligne = 0;
	int k;
	mydataEmpl* dtemp;
    dtemp = (mydataEmpl*)malloc(sizeof(mydataEmpl)*(nomData+1));
    
	file = fopen(pathTofile,"r");
    
	while(fgets(data,200,file)!=NULL){
        /*printf("inside while fgets\n");*/
	 genre = 0;	
	 i = 0;
	 while(data[i]!='{')
        i++;
    
     do{
        k=0;
        i++;
        while(data[i]!=','&&data[i]!='}'){
            ins[k] = data[i];
            k++;
            i++;
        }
        ins[k] = '\0';

        switch(genre){
          case 0:{
          		strcpy(dtemp[nombreligne].fullname,ins);
          }
          case 1:{
          		strcpy(dtemp[nombreligne].statEmploi,ins);
          }
          case 2:{
          		strcpy(dtemp[nombreligne].salr,ins);
          }
          case 3:{
          		strcpy(dtemp[nombreligne].id,ins);
          } 
          case 4:{
                strcpy(dtemp[nombreligne].duree,ins);
          }
          case 5:{
            strcpy(dtemp[nombreligne].email,ins);
          }                  
        }
        

        genre++; 

    }while(data[i]==',');

    nombreligne++;
	}
	fclose(file);

    

	return dtemp;
}

/*---------------------------------------------Cars Get data--------------------------------------------------------------------------*/

info* getDataFromFileCars(int nomData,char* pathTofile){
    
  FILE *file;
  char data[200];
  char ins[100];
  int i = 0;
  int genre = 0;
  int nombreligne = 0;
  int k;
  info* dtemp;
    dtemp = (info*)malloc(sizeof(info)*(nomData+1));
    
  file = fopen(pathTofile,"r");
    
  while(fgets(data,200,file)!=NULL){
        /*printf("inside while fgets\n");*/
   genre = 0; 
   i = 0;
   while(data[i]!='{')
        i++;
    
     do{
        k=0;
        i++;
        while(data[i]!=','&&data[i]!='}'){
            ins[k] = data[i];
            k++;
            i++;
        }
        ins[k] = '\0';


        switch(genre){
          case 0:{
              TextCopy(dtemp[nombreligne].id,ins);
          }
          case 1:{
              TextCopy(dtemp[nombreligne].model,ins);
          }
          case 2:{
              TextCopy(dtemp[nombreligne].anne,ins);
          }
          case 3:{
              TextCopy(dtemp[nombreligne].prix,ins);
          } 
          case 4:{
                TextCopy(dtemp[nombreligne].stat,ins);
          }
          case 5:{
            TextCopy(dtemp[nombreligne].info1,ins);
          }  

          case 6:{
              TextCopy(dtemp[nombreligne].info2,ins);
          }
          case 7:{
              TextCopy(dtemp[nombreligne].info3,ins);
          } 
          case 8:{
                TextCopy(dtemp[nombreligne].info4,ins);
          }
          case 9:{
            TextCopy(dtemp[nombreligne].info5,ins);
          } 
          case 10:{
            TextCopy(dtemp[nombreligne].path,ins);
          } 
          case 11:{
            TextCopy(dtemp[nombreligne].pathDetails,ins);
          }                  
        }
        

        genre++; 

    }while(data[i]==',');

    nombreligne++;
  }
  fclose(file);

    

  return dtemp;
}

/*-----------------------------------------------Client maintence cars-------------------------------------------------------------------------------*/

MaintenanceInfo* getDataFromFileMaintence(int nomData,char* pathTofile){

   
  FILE *file;
  char data[200];
  char ins[100];
  int i = 0;
  int genre = 0;
  int nombreligne = 0;
  int k;
  MaintenanceInfo* dtemp;
    dtemp = (MaintenanceInfo*)malloc(sizeof(MaintenanceInfo)*(nomData+1));
    
  file = fopen(pathTofile,"r");
    
  while(fgets(data,200,file)!=NULL){
        /*printf("inside while fgets\n");*/
   genre = 0; 
   i = 0;
   while(data[i]!='{')
        i++;
    
     do{
        k=0;
        i++;
        while(data[i]!=','&&data[i]!='}'){
            ins[k] = data[i];
            k++;
            i++;
        }
        ins[k] = '\0';


        switch(genre){
          case 0:{
              TextCopy(dtemp[nombreligne].cin,ins);
          }
          case 1:{
              TextCopy(dtemp[nombreligne].prenom,ins);
          }
          case 2:{
              TextCopy(dtemp[nombreligne].nom,ins);
          }
          case 3:{
              TextCopy(dtemp[nombreligne].matric,ins);
          } 
          case 4:{
                TextCopy(dtemp[nombreligne].prixTo,ins);
          }
          case 5:{
            TextCopy(dtemp[nombreligne].datee,ins);
          }  

          case 6:{
              TextCopy(dtemp[nombreligne].problem,ins);
          }
                  
        }
        

        genre++; 

    }while(data[i]==',');

    nombreligne++;
  }
  fclose(file);

    

  return dtemp;
}



