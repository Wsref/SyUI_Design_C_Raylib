#include "raylib.h"
#include <stdlib.h>
#include "autHolHeadFil.h"

texturAndPosit* loadAllTextrForHome(void){
	int scren_wdt = 800;
	int screen_hght = 500;
	texturAndPosit* allTex;
	allTex = (texturAndPosit*)malloc(sizeof(texturAndPosit)*4);

	allTex[home].myTextr =  LoadTexture("photos/home.png");
	allTex[home].myTextrPosit = (Vector2) {0,0};

	allTex[menu].myTextr = LoadTexture("graphiqPict/menadv3.png");
	allTex[menu].myTextrPosit = (Vector2)  {scren_wdt-(allTex[menu].myTextr.width/2.0f),
								(screen_hght-allTex[menu].myTextr.height)-((screen_hght-allTex[menu].myTextr.height)/2.0f)};
    
    allTex[title].myTextr =  LoadTexture("graphiqPict/title.png");
    allTex[title].myTextrPosit = (Vector2)  {(scren_wdt/2.0f)-(allTex[title].myTextr.width/2.0f),screen_hght*0.25f};

    allTex[linktomap].myTextr = LoadTexture("graphiqPict/linktom.png");
    allTex[linktomap].myTextrPosit = (Vector2)  {(scren_wdt/2.0f)-(allTex[linktomap].myTextr.width/2.0f),screen_hght*0.45f};

    return allTex;
}





texturAndPosit* loadAllTextrForEmpl(void){
	int scren_wdt = 800;
	int screen_hght = 500;
	float screresize = scren_wdt/3.0f;
	texturAndPosit* allTex;
	allTex = (texturAndPosit*)malloc(sizeof(texturAndPosit)*7);

	allTex[commercant].myTextr = LoadTexture("graphiqPict/commercants.png");
	allTex[commercant].myTextrPosit = (Vector2)  {(screresize/2.0f)-(allTex[0].myTextr.width/2.0f),
							  (screen_hght/2.0f)-(allTex[0].myTextr.height/2.0f)};

	allTex[technicien].myTextr = LoadTexture("graphiqPict/techniciens.png");
	allTex[technicien].myTextrPosit = (Vector2)  {screresize + (screresize/2.0f)-(allTex[1].myTextr.width/2.0f),
							 (screen_hght/2.0f)-(allTex[1].myTextr.height/2.0f)};

	allTex[stagiar].myTextr = LoadTexture("graphiqPict/stagiares.png");
	allTex[stagiar].myTextrPosit = (Vector2)  {screresize*2 + (screresize/2.0f)-(allTex[2].myTextr.width/2.0f),
							 (screen_hght/2.0f)-(allTex[2].myTextr.height/2.0f)};

	allTex[identform].myTextr = LoadTexture("graphiqPict/emplDta.png");
	allTex[identform].myTextrPosit = (Vector2)  {(scren_wdt/2.0f)-(allTex[3].myTextr.width/2.0f),
							  (screen_hght/2.0f)-(allTex[3].myTextr.height/2.0f)};

	allTex[gorightbtn].myTextr = LoadTexture("graphiqPict/gorght.png");
	allTex[gorightbtn].myTextrPosit = (Vector2)  {((allTex[3].myTextrPosit.x+allTex[3].myTextr.width)+scren_wdt)/2.0f-allTex[4].myTextr.width,
								(screen_hght/2.0f)-(allTex[4].myTextr.height/2.0f)};

	allTex[goleftbtn].myTextr = LoadTexture("graphiqPict/goleftt.png");
	allTex[goleftbtn].myTextrPosit = (Vector2)  {(allTex[3].myTextrPosit.x/2.0f),
							  (screen_hght/2.0f)-(allTex[5].myTextr.height/2.0f)};

	allTex[backbtn].myTextr = LoadTexture("graphiqPict/mybck.png");
	allTex[backbtn].myTextrPosit = (Vector2)  {scren_wdt*0.03,screen_hght*0.08};

	return allTex;
}


texturAndPosit* loadAllTextrForCars(void){
	int scren_wdt = 800;
	int screen_hght = 500;

	texturAndPosit* allTex;
	allTex = (texturAndPosit*)malloc(sizeof(texturAndPosit)*7);

	allTex[backgrCars].myTextr = LoadTexture("graphiqPict/cardescrp.png");
	allTex[backgrCars].myTextrPosit = (Vector2) {(scren_wdt/2.0f)-(allTex[backgrCars].myTextr.width/2.0f),(screen_hght/2.0f)-(allTex[backgrCars].myTextr.height/2.0f)};

	allTex[scrollup].myTextr = LoadTexture("graphiqPict/scrolUp.png");
	allTex[scrollup].myTextrPosit = (Vector2) { (allTex[backgrCars].myTextrPosit.x + allTex[backgrCars].myTextr.width) , allTex[backgrCars].myTextrPosit.y-10};

	allTex[scrolldown].myTextr = LoadTexture("graphiqPict/scrolDwn.png");
	allTex[scrolldown].myTextrPosit = (Vector2) { (allTex[backgrCars].myTextrPosit.x + allTex[backgrCars].myTextr.width) ,
												   allTex[backgrCars].myTextrPosit.y+allTex[backgrCars].myTextr.height-28};

	Rectangle imagesRec = {0,0,300,180};
	Vector2 img1 = { (allTex[backgrCars].myTextrPosit.x + 16) ,allTex[backgrCars].myTextrPosit.y+16+13};
	Vector2 img2 = { (allTex[backgrCars].myTextrPosit.x+16) ,img1.y+13+imagesRec.height};


	allTex[viewdetails1].myTextr = LoadTexture("graphiqPict/view.png");
	allTex[viewdetails1].myTextrPosit = (Vector2) { (allTex[backgrCars].myTextrPosit.x + allTex[backgrCars].myTextr.width/2.0f + 
								allTex[backgrCars].myTextr.width*0.07) , (img1.y+imagesRec.height-allTex[viewdetails1].myTextr.height) };

	allTex[viewdetails2].myTextr = LoadTexture("graphiqPict/view.png");
	allTex[viewdetails2].myTextrPosit = (Vector2) { (allTex[backgrCars].myTextrPosit.x + allTex[viewdetails1].myTextr.width/2.0f + 
								allTex[viewdetails1].myTextr.width*0.07) , (img2.y+imagesRec.height-allTex[viewdetails1].myTextr.height) };

	allTex[backbtnCar].myTextr = LoadTexture("graphiqPict/mybck.png");
	allTex[backbtnCar].myTextrPosit = (Vector2)  {scren_wdt*0.03,screen_hght*0.08};

	allTex[backgrDetailCars].myTextr = LoadTexture("graphiqPict/cardescrpDet.png");
	allTex[backgrDetailCars].myTextrPosit = (Vector2) {(scren_wdt/2.0f)-(allTex[backgrCars].myTextr.width/2.0f),(screen_hght/2.0f)-(allTex[backgrCars].myTextr.height/2.0f)};

	return allTex;
}

Texture2D* loadCarsPict(info* picInfo,int howManyCars){
	int i;
	Texture2D* myCarImgs;
	myCarImgs = (Texture2D*)malloc(sizeof(Texture2D)*howManyCars);

	for(i=0;i<howManyCars;i++){
		myCarImgs[i] = LoadTexture(picInfo[i].path);
	}

	return myCarImgs;
}

Texture2D* loadDeailsCarsPict(info* picInfo,int howManyCars){
	int i;
	Texture2D* myCarImgs;
	myCarImgs = (Texture2D*)malloc(sizeof(Texture2D)*howManyCars);

	for(i=0;i<howManyCars;i++){
		myCarImgs[i] = LoadTexture(picInfo[i].pathDetails);
	}

	return myCarImgs;
}