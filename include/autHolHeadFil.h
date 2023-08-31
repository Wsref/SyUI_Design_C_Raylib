#ifndef AUTHOLHEADFIL_H
#define AUTHOLHEADFIL_H

#include "raylib.h"
#include "tmx.h"

typedef enum{

	homeScreen,
	employeDesiScreen,
	employeDataScreen,
	carsDesiScreen,
	carsDetailsScreen,
	maintenSearchScreen,
	maintenanceClientDetScreen
/*	carsDesiScreen,
	carsDataScreen,
	*/

}systemAutHllScreen;

typedef enum{

	clickOncommerceant,
	clickOntechnicien,
	clickOnstagiair

}whichDataShoulIUse;

/*-------------------------------*/
typedef enum{
	commercant,
	technicien,
	stagiar,
	identform,
	gorightbtn,
	goleftbtn,
	backbtn
}myTextrEmplNames;
/*-------------------------------*/
typedef enum{
	home,
	menu,
	title,
	linktomap
}myTextrHomeNames; 
/*-------------------------------*/
typedef enum{
	backgrCars,
	scrollup,
	scrolldown,
	viewdetails1,
	viewdetails2,
	backbtnCar,
	backgrDetailCars
}myTextrCarsNames;

/*-------------------------------*/
typedef struct{
	char id[10];
	char model[30];
	char anne[5];
	char prix[10];
	char stat[20];
	char info1[20];
	char info2[20];
	char info3[20];
	char info4[20];
	char info5[20];
	char path[20];
	char pathDetails[20];	
}info;
/*-------------------------------*/
typedef struct{
	char fullname[100];
	char statEmploi[50];
	char salr[10];
	char id[10];
	char duree[50];
	char email[100];
}mydataEmpl;
/*-------------------------------*/
typedef struct {
	char cin[10];
	char prenom[20];
	char nom[20];
	char matric[10];
	char prixTo[10];
	char datee[10];
	char problem[20];
}MaintenanceInfo;
/*-------------------------------*/
typedef struct{
	Texture2D myTextr;
	Vector2 myTextrPosit;
}texturAndPosit;
/*-------------------------------*/
typedef struct{
	int hoversat[4];
	int screenState;
	int whichEmploy;
	float blckScr;
}employDesi;
/*-------------------------------*/
typedef struct{
	int hoversat[3];
	int screenState;
	float dynamFormul;
	int whichPerson[3];
	mydataEmpl information;
}emploData;




/*getData functions declar*/
MaintenanceInfo* getDataFromFileMaintence(int nomData,char* pathTofile);
info* getDataFromFileCars(int nomData,char* pathTofile);
mydataEmpl* getDataFromFileEmpl(int nomData,char* pathTofile);
int nombLingnData(char* pathTofile);

/*loadTextur functions declar*/
texturAndPosit* loadAllTextrForHome(void);
texturAndPosit* loadAllTextrForEmpl(void);
texturAndPosit* loadAllTextrForCars(void);
Texture2D* loadCarsPict(info* picInfo,int howManyCars);
Texture2D* loadDeailsCarsPict(info* picInfo,int howManyCars);

/*emploDesi functions declar*/
employDesi* myEmployDesiVariables(employDesi* empDesVariables,texturAndPosit* allTex);
void myEmployDesiDraw(int hoversata[4],texturAndPosit* allTex);
void myEmployDataDraw(int hoverStat[3],texturAndPosit* allTex,mydataEmpl* informations,int whichOne,Font font,float show);

/*scrolling functions declaration*/
float scrollingUp(float framecoonter,float recAbsolutPosition,float recOriginPosition,float movingDistance);
float scrollingDown(float framecoonter,float recAbsolutPosition,float recOriginPosition,float movingDistance);

/*searchMaintenance functions declarations*/
int clientData(MaintenanceInfo* maDt,int numberClients,char word[10]);

Texture2D *LoadMapTexture(const char *fileName);
void UnloadMapTexture(Texture2D *tex);
void RenderTmxMapToFramebuf(const char *mapFileName, RenderTexture2D *buf);
extern RenderTexture2D mapFrameBuffer;




#endif 