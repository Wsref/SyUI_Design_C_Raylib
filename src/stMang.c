#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "raylib.h"
#include "autHolHeadFil.h"
/*SetWindowState(FLAG_FULLSCREEN_MODE);*/
#define scren_wdt 800
#define screen_hght 500

systemAutHllScreen myCurrentScreen = homeScreen;

int main(){
	 Camera2D camera;

	 // homeScreen Declaration
	 texturAndPosit* loadTe;
	 loadTe = (texturAndPosit*)malloc(sizeof(texturAndPosit));

	 // eploDesi Declaration
	 texturAndPosit* loadTe1;
	 loadTe1 = (texturAndPosit*)malloc(sizeof(texturAndPosit));
	 employDesi* empDesVariables;
	 empDesVariables = (employDesi*)malloc(sizeof(employDesi));
	 empDesVariables->screenState = employeDesiScreen;
	 empDesVariables->hoversat[0] = 0;
	 empDesVariables->hoversat[1] = 0;
	 empDesVariables->hoversat[2] = 0;
	 empDesVariables->hoversat[3] = 0;
	 int hoverEmpDesi[4];


	 // eploData Declarartion
	 int hoverEmpData[3];
	 hoverEmpData[0] = 0;
	 hoverEmpData[1] = 0;
	 hoverEmpData[2] = 0;
	 float formDataBlckScr = 1.0f;
	 int toleft = 0;
	 int toright = 0;
	 float frameCounterEmploDat = 0.0f;

	 // carDesi declarartion
	 int hoverCar[3];
	 hoverCar[0] = 0;
	 hoverCar[1] = 0;
	 hoverCar[2] = 0;
	 int whichCar;
	 float scrollCarBlckScr = 1.0f;
	 float framesCounterCars = 0.0f;
	 int firstCar = 0;
	 int secondCar = 1;
	 int up = 0;
	 int down = 0;
	 texturAndPosit* loadTexCarDesiScr;
	 loadTexCarDesiScr = (texturAndPosit*)malloc(sizeof(texturAndPosit));
	 Texture2D* myCarImgs;
	 myCarImgs = (Texture2D*)malloc(sizeof(Texture2D));
	 info* myCarInformations;
	 myCarInformations = (info*)malloc(sizeof(info));
	 int nombreCars = nombLingnData("data/cars.dat");
	 myCarInformations = getDataFromFileCars(nombreCars,"data/cars.dat");

	 //carDetails Declaration
	 Texture2D* myDetailsCarImgs;
	 myDetailsCarImgs = (Texture2D*)malloc(sizeof(Texture2D));



	 /*get Data */
	 mydataEmpl* informationsStg;
	 informationsStg = (mydataEmpl*)malloc(sizeof(mydataEmpl));
	 int numberStg = nombLingnData("data/stagiare.dat");
	 informationsStg = getDataFromFileEmpl(numberStg,"data/stagiare.dat");

	 mydataEmpl* informationsTech;
	 informationsTech = (mydataEmpl*)malloc(sizeof(mydataEmpl));
	 int numberTech = nombLingnData("data/technicien.dat");
	 informationsTech = getDataFromFileEmpl(numberTech,"data/technicien.dat");

	 mydataEmpl* informationsComm;
	 informationsComm = (mydataEmpl*)malloc(sizeof(mydataEmpl));
	 int numberComm = nombLingnData("data/commr.dat");
	 informationsComm = getDataFromFileEmpl(numberComm,"data/commr.dat");

	 int numbers[3];
	 numbers[clickOnstagiair] = numberStg;
	 numbers[clickOntechnicien] = numberTech;
	 numbers[clickOncommerceant] = numberComm;

	 int whichOneInFile[3];
	 whichOneInFile[0] = 0;
	 whichOneInFile[1] = 0;
	 whichOneInFile[2] = 0;

	 /*maintenance Search declarations*/
	 MaintenanceInfo* clientInformation;
	 clientInformation = (MaintenanceInfo*)malloc(sizeof(MaintenanceInfo));
	 int numberClients = nombLingnData("data/maintenance.dat");
	 clientInformation = getDataFromFileMaintence(numberClients,"data/maintenance.dat");
	 int hoverSearch = 0;
	 char word[10];
	 int letters = 0;
	 int whichClient = -1;
	 int mouseOnSearchBar = 0;


	 
	 float blackScreenForDynamiqMov = 0.0f;
	InitWindow(scren_wdt,screen_hght,"autoHallManagementSystem");
	
		/*load background image */
		Texture2D myMainBackground = LoadTexture("photos/khalfiya.png");
		/*load Texture for every screen*/
		loadTe = loadAllTextrForHome(); //home textures loading
		loadTe1 = loadAllTextrForEmpl(); //employe texture loading
		loadTexCarDesiScr = loadAllTextrForCars();

		/*load cars images for CarDesiScreen*/
		myCarImgs = loadCarsPict(myCarInformations,nombreCars);
		/*a rectangle and vector are for putting two cars in a screen with exact size that why this rectangle and exact position that why this two vector2*/
		Rectangle imagesRec = {0,0,300,180}; 
		Vector2 img1 = { (loadTexCarDesiScr[backgrCars].myTextrPosit.x + 16) ,
						loadTexCarDesiScr[backgrCars].myTextrPosit.y+16+13};
		Vector2 img2 = { (loadTexCarDesiScr[backgrCars].myTextrPosit.x + 16) ,
						img1.y+13+imagesRec.height};

		/*load details car images for carDetailScreen*/
		myDetailsCarImgs = loadDeailsCarsPict(myCarInformations,nombreCars);
		Rectangle imgesDetailRec = {0,0,300,400};
		Vector2 imgDetail = {loadTexCarDesiScr[backgrCars].myTextrPosit.x+16,
		  					loadTexCarDesiScr[backgrCars].myTextrPosit.y +16};


		/*load search bar for maintenanceSearchScreen*/
		 Texture2D searchBar = LoadTexture("graphiqPict/search.png");
		 Vector2 searchBarPosition = {scren_wdt/2.0f - searchBar.width/2.0f,screen_hght/2.0f - searchBar.height/2.0f};
		 Rectangle textPlace = {scren_wdt/2.0f - searchBar.width/2.0f + (32),screen_hght/2.0f - searchBar.height/2.0f + (16),searchBar.width - searchBar.width*0.17 - 32,searchBar.height-16};
		 Rectangle searchIcone = {textPlace.x + textPlace.width,textPlace.y,64,32};

		 /*load client information for maintenanaceClientDetailsScreen*/
		 Texture2D tableClient = LoadTexture("graphiqPict/maintenance.png");
		 Vector2 tableClientPosition = {scren_wdt/2.0f - tableClient.width/2.0f,screen_hght/2.0f - tableClient.height/2.0f};


		// download fonts
		Font font = LoadFont("fonts/ArialNovaCond-Light.ttf");

		//this rectangles to use drawtexturepro() function
		Rectangle destTitle = {(scren_wdt/2.0f)-(loadTe[title].myTextr.width/2.0f),screen_hght*0.25f,0,0};
		Rectangle sourceTitle = {0,0,loadTe[title].myTextr.width,loadTe[title].myTextr.height};

		Rectangle hoverSurAutohall = {loadTe[menu].myTextrPosit.x,loadTe[menu].myTextrPosit.y+screen_hght*0.6 
								     ,128,80};
		Rectangle colavecmouseinmenu = {loadTe[menu].myTextrPosit.x ,loadTe[menu].myTextrPosit.y,
										loadTe[menu].myTextr.width/2.0f,loadTe[menu].myTextr.height};
		/*menu animation variables*/
		int allowsmalbuttogvusmenu = 1; 
		int mov = 0;
		int ret = 0;
		int hovlnmp = 0;
		Rectangle mantenanceField = {loadTe[menu].myTextrPosit.x + 64,32+loadTe[menu].myTextrPosit.y,80,80};
	 	Rectangle aVendreField = {loadTe[menu].myTextrPosit.x + 64,32*2+mantenanceField.width+loadTe[menu].myTextrPosit.y,80,80};
	 	Rectangle employesField = {loadTe[menu].myTextrPosit.x + 64,32*3+ mantenanceField.width + aVendreField.width +loadTe[menu].myTextrPosit.y,80,80};
		/*editing map variables*/
		int tomap = 0;
		/*Set camera and load map*/
		    RenderTmxMapToFramebuf("map/mymp.tmx", &mapFrameBuffer);
    		camera.target = (Vector2){1500.0f,900.0f};
    		camera.offset = (Vector2){scren_wdt/2,screen_hght/2};
    		camera.rotation = 0.0;
    		camera.zoom = 1.0f;

    	SetTargetFPS(60);
		while(!	WindowShouldClose()){
			//ici c'est l'update
		switch(myCurrentScreen){
			// -------------------------------------------------Home Screen--------------------------------------------------------------
			case homeScreen :{

			if(blackScreenForDynamiqMov>0.0) blackScreenForDynamiqMov-=0.3;

			/*AUTO HALL AGADIR ANIMATION*/
			if(destTitle.width<=loadTe[title].myTextr.width) destTitle.width+=8;	
			if(destTitle.height<=loadTe[title].myTextr.height) destTitle.height+=4;
			/*menu animation begin*/
			if(CheckCollisionPointRec(GetMousePosition(),hoverSurAutohall)&&allowsmalbuttogvusmenu){
				mov = 1;
			}
			if(mov){
				allowsmalbuttogvusmenu = 0;
				loadTe[menu].myTextrPosit.x-=4.0f;
				if(loadTe[menu].myTextrPosit.x<=(scren_wdt-loadTe[menu].myTextr.width)){ 
					mov = 0;
					ret = 1;
					
				}
			}

			if(CheckCollisionPointRec(GetMousePosition(),colavecmouseinmenu)&&ret){
				if(CheckCollisionPointRec(GetMousePosition(),mantenanceField)){
					SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
					if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
						blackScreenForDynamiqMov=1.0;
						myCurrentScreen = maintenSearchScreen;
						SetMouseCursor(MOUSE_CURSOR_DEFAULT);
					}
				}
				if(CheckCollisionPointRec(GetMousePosition(),aVendreField)){
					SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
					if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
						blackScreenForDynamiqMov=1.0;
						myCurrentScreen = carsDesiScreen;
						SetMouseCursor(MOUSE_CURSOR_DEFAULT);
					}
				}
				if(CheckCollisionPointRec(GetMousePosition(),employesField)){
					SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
					if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
						empDesVariables->blckScr = 0.0f;
						blackScreenForDynamiqMov=1.0;
						myCurrentScreen = employeDesiScreen;
						empDesVariables->screenState = employeDesiScreen;
						SetMouseCursor(MOUSE_CURSOR_DEFAULT);	
					} 

				}
			}
			if(!CheckCollisionPointRec(GetMousePosition(),colavecmouseinmenu)&&ret){
				SetMouseCursor(MOUSE_CURSOR_DEFAULT);
				loadTe[menu].myTextrPosit.x+=8.0f;
				if(loadTe[menu].myTextrPosit.x>=(scren_wdt-(loadTe[menu].myTextr.width/2.0f))){
					allowsmalbuttogvusmenu = 1;
					ret = 0;	
				} 
			}
			/*menu animation end*/
			/*linktomap editing begin*/
			if(CheckCollisionPointRec(GetMousePosition(),
				(Rectangle){loadTe[linktomap].myTextrPosit.x,loadTe[linktomap].myTextrPosit.y,
							loadTe[linktomap].myTextr.width,loadTe[linktomap].myTextr.height})){
					hovlnmp=1;
					if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){tomap = 1;}
					}
			else{hovlnmp=0;}
			/*linktomap editing end*/
			/*map editing begin*/
			    if (IsKeyDown(KEY_RIGHT)&&camera.target.x<=1900) camera.target.x += 4;
        		if (IsKeyDown(KEY_LEFT)&&camera.target.x>=700) camera.target.x -= 4;
        		if (IsKeyDown(KEY_DOWN)&&camera.target.y<=1100) camera.target.y += 4;  
        		if (IsKeyDown(KEY_UP)&&camera.target.y>=300) camera.target.y -= 4;
        		if(IsKeyPressed(KEY_BACKSPACE)) tomap = 0;
        	/*map editing end*/

        	}break;
			// -------------------------------------------------Employe Design Screen--------------------------------------------------------------
        	case employeDesiScreen : {
        		if(blackScreenForDynamiqMov>0.0) blackScreenForDynamiqMov-=0.3;
        		empDesVariables = myEmployDesiVariables(empDesVariables,loadTe1);
        		hoverEmpDesi[0] = empDesVariables->hoversat[0];
        		hoverEmpDesi[1] = empDesVariables->hoversat[1];
        		hoverEmpDesi[2] = empDesVariables->hoversat[2];
        		hoverEmpDesi[3] = empDesVariables->hoversat[3];

        		myCurrentScreen = empDesVariables->screenState;
        		blackScreenForDynamiqMov = empDesVariables->blckScr;

        	}break;
        	// -------------------------------------------------Employe Data Screen--------------------------------------------------------------
        	case employeDataScreen : {
        	frameCounterEmploDat+=2;
        	if(blackScreenForDynamiqMov>0.0) blackScreenForDynamiqMov-=0.3;
        	if(formDataBlckScr>0.0) formDataBlckScr-=0.04;

        	if(CheckCollisionPointRec(GetMousePosition(),
        	(Rectangle){loadTe1[gorightbtn].myTextrPosit.x,loadTe1[gorightbtn].myTextrPosit.y,
						loadTe1[gorightbtn].myTextr.width,loadTe1[gorightbtn].myTextr.height}) ){
        		hoverEmpData[1] = true;
        		if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&
        								whichOneInFile[empDesVariables->whichEmploy]<numbers[empDesVariables->whichEmploy]-1){
        			whichOneInFile[empDesVariables->whichEmploy]++;
        			formDataBlckScr = 1.0f;
        			frameCounterEmploDat = 0.0f;
        			toright = 1;
        			toleft = 0;
        		}

        			   					

        	}else hoverEmpData[1] = false;	

        	if(CheckCollisionPointRec(GetMousePosition(),
        	(Rectangle){loadTe1[goleftbtn].myTextrPosit.x,loadTe1[goleftbtn].myTextrPosit.y,
						loadTe1[goleftbtn].myTextr.width,loadTe1[goleftbtn].myTextr.height}) ){
        		hoverEmpData[0] = true;
        		if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)
        								&&whichOneInFile[empDesVariables->whichEmploy]>0){
        		   whichOneInFile[empDesVariables->whichEmploy]--;
        		   formDataBlckScr = 1.0f;
        		   frameCounterEmploDat = 0.0f;
        		   toleft = 1;
        		   toright = 0;
        		}

        			 					

        	}else hoverEmpData[0] = false;	

        	if(toleft){
        		loadTe1[identform].myTextrPosit.x = scrollingUp(frameCounterEmploDat,loadTe1[identform].myTextrPosit.x,
        											(scren_wdt/2.0f)-(loadTe1[3].myTextr.width/2.0f),30);
        	}
        	if(toright){
        		loadTe1[identform].myTextrPosit.x = scrollingDown(frameCounterEmploDat,loadTe1[identform].myTextrPosit.x,
        											(scren_wdt/2.0f)-(loadTe1[3].myTextr.width/2.0f),30);
        	}

			if(CheckCollisionPointRec(GetMousePosition(),
			(Rectangle){loadTe1[backbtn].myTextrPosit.x,loadTe1[backbtn].myTextrPosit.y,
						loadTe1[backbtn].myTextr.width,loadTe1[backbtn].myTextr.height}) ){
				hoverEmpData[2] = true;
				if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
					empDesVariables->blckScr = 0.0f;
					blackScreenForDynamiqMov=1.0;
					empDesVariables->screenState = employeDesiScreen;
					myCurrentScreen  = employeDesiScreen;
				}
		    }else hoverEmpData[2] = false;	

        		

        	}break; 
        	// -------------------------------------------------Car Design Screen--------------------------------------------------------------
        	case carsDesiScreen :{
        		if(blackScreenForDynamiqMov>0.0) blackScreenForDynamiqMov-=0.3;
        	 	if(CheckCollisionPointRec( GetMousePosition(),(Rectangle){loadTexCarDesiScr[scrolldown].myTextrPosit.x,loadTexCarDesiScr[scrolldown].myTextrPosit.y,
        	 		loadTexCarDesiScr[scrolldown].myTextr.width,loadTexCarDesiScr[scrolldown].myTextr.height} ) ){
        	 		hoverCar[0] = 1;
		 	    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
		 		     if((firstCar<nombreCars)&&(secondCar<nombreCars-1)){	 		 
		 		       firstCar+=2;
		 		       secondCar+=2;
		 		       framesCounterCars = 0.0f;
		 		       scrollCarBlckScr = 1.0f;
		 		       up = 0;
		 		       down = 1;
		 			}	
		 		  }
		 		}else hoverCar[0] = 0;

		 	    if(CheckCollisionPointRec( GetMousePosition(),(Rectangle){loadTexCarDesiScr[scrollup].myTextrPosit.x,loadTexCarDesiScr[scrollup].myTextrPosit.y,
		 	    	loadTexCarDesiScr[scrollup].myTextr.width,loadTexCarDesiScr[scrollup].myTextr.height} ) ){
		 	    	hoverCar[1] = 1;
		 		if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
		 			 if((firstCar>0)&&(secondCar>1)) {
		 				firstCar-=2;
		 				secondCar-=2;
		 				framesCounterCars = 0.0f;
		 				scrollCarBlckScr = 1.0f;
		 				up = 1;
		 				down = 0;
		 			}
		 		  }
		 		}else hoverCar[1] = 0;

		 		if(scrollCarBlckScr>0) scrollCarBlckScr-=0.02;

		 		framesCounterCars+=2;
		 		if(up){
				loadTexCarDesiScr[backgrCars].myTextrPosit.y = scrollingUp(framesCounterCars,loadTexCarDesiScr[backgrCars].myTextrPosit.y,
															   (screen_hght/2.0f)-(loadTexCarDesiScr[backgrCars].myTextr.height/2.0f),60);
				img1.y = scrollingUp(framesCounterCars,img1.y,loadTexCarDesiScr[backgrCars].myTextrPosit.y+16+13,60);
				img2.y = scrollingUp(framesCounterCars,img2.y,img1.y+13+imagesRec.height,60);
				loadTexCarDesiScr[viewdetails1].myTextrPosit.y = scrollingUp(framesCounterCars,loadTexCarDesiScr[viewdetails1].myTextrPosit.y,
					 											 img1.y+imagesRec.height-loadTexCarDesiScr[viewdetails1].myTextr.height,60);
				loadTexCarDesiScr[viewdetails2].myTextrPosit.y = scrollingUp(framesCounterCars,loadTexCarDesiScr[viewdetails2].myTextrPosit.y,
															     img2.y+imagesRec.height-loadTexCarDesiScr[viewdetails1].myTextr.height,60);
				}
				if(down){
				loadTexCarDesiScr[backgrCars].myTextrPosit.y = scrollingDown(framesCounterCars,loadTexCarDesiScr[backgrCars].myTextrPosit.y,
															   (screen_hght/2.0f)-(loadTexCarDesiScr[backgrCars].myTextr.height/2.0f),60);
				img1.y = scrollingDown(framesCounterCars,img1.y,loadTexCarDesiScr[backgrCars].myTextrPosit.y+16+13,60);
				img2.y = scrollingDown(framesCounterCars,img2.y,img1.y+13+imagesRec.height,60);
				loadTexCarDesiScr[viewdetails1].myTextrPosit.y = scrollingDown(framesCounterCars,loadTexCarDesiScr[viewdetails1].myTextrPosit.y,
					 											 img1.y+imagesRec.height-loadTexCarDesiScr[viewdetails1].myTextr.height,60);
				loadTexCarDesiScr[viewdetails2].myTextrPosit.y = scrollingDown(framesCounterCars,loadTexCarDesiScr[viewdetails2].myTextrPosit.y,
															     img2.y+imagesRec.height-loadTexCarDesiScr[viewdetails1].myTextr.height,60);					
				}

		 	    if(CheckCollisionPointRec( GetMousePosition(),(Rectangle){loadTexCarDesiScr[backbtnCar].myTextrPosit.x,loadTexCarDesiScr[backbtnCar].myTextrPosit.y,
		 	    	loadTexCarDesiScr[backbtnCar].myTextr.width,loadTexCarDesiScr[backbtnCar].myTextr.height} ) ){
		 	    	hoverCar[2] = 1;
		 	    	if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
		 	    		blackScreenForDynamiqMov=1.0;
		 	    		myCurrentScreen  = homeScreen;
		 	    	}
		 	    }
		 	    /*click on voir details*/
		 	    if(CheckCollisionPointRec( GetMousePosition(),(Rectangle){loadTexCarDesiScr[viewdetails1].myTextrPosit.x,loadTexCarDesiScr[viewdetails1].myTextrPosit.y,
		 									loadTexCarDesiScr[viewdetails1].myTextr.width,loadTexCarDesiScr[viewdetails1].myTextr.height} ) ){
		 	    	SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
		 	    	if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
		 	    		SetMouseCursor(MOUSE_CURSOR_DEFAULT);
		 	    		blackScreenForDynamiqMov=1.0;
		 	    		myCurrentScreen = carsDetailsScreen;
		 	    		whichCar = firstCar;
		 	    	}
		 	    }

		 	    if(CheckCollisionPointRec( GetMousePosition(),(Rectangle){loadTexCarDesiScr[viewdetails1].myTextrPosit.x,loadTexCarDesiScr[viewdetails2].myTextrPosit.y,
		 									loadTexCarDesiScr[viewdetails1].myTextr.width,loadTexCarDesiScr[viewdetails1].myTextr.height} ) ){
		 	    	SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
		 	    	if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
		 	    		SetMouseCursor(MOUSE_CURSOR_DEFAULT);
		 	    		blackScreenForDynamiqMov=1.0;
		 	    		myCurrentScreen = carsDetailsScreen;
		 	    		whichCar = secondCar;
		 	    	}
		 	    }
		 	    if(!CheckCollisionPointRec( GetMousePosition(),(Rectangle){loadTexCarDesiScr[viewdetails1].myTextrPosit.x,loadTexCarDesiScr[viewdetails2].myTextrPosit.y,
		 									loadTexCarDesiScr[viewdetails1].myTextr.width,loadTexCarDesiScr[viewdetails1].myTextr.height} )&&
		 	    	!CheckCollisionPointRec( GetMousePosition(),(Rectangle){loadTexCarDesiScr[viewdetails1].myTextrPosit.x,loadTexCarDesiScr[viewdetails1].myTextrPosit.y,
		 									loadTexCarDesiScr[viewdetails1].myTextr.width,loadTexCarDesiScr[viewdetails1].myTextr.height} ) ){
		 	    	SetMouseCursor(MOUSE_CURSOR_DEFAULT);
		 	    }

        	}break;
        	// -------------------------------------------------Car details Screen--------------------------------------------------------------
        	case carsDetailsScreen : {
        		if(blackScreenForDynamiqMov>0.0) blackScreenForDynamiqMov-=0.3;
		 	    if(CheckCollisionPointRec( GetMousePosition(),(Rectangle){loadTexCarDesiScr[backbtnCar].myTextrPosit.x,loadTexCarDesiScr[backbtnCar].myTextrPosit.y,
		 	    	loadTexCarDesiScr[backbtnCar].myTextr.width,loadTexCarDesiScr[backbtnCar].myTextr.height} ) ){
		 	    	hoverCar[2] = 1;
		 	    	if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
		 	    		blackScreenForDynamiqMov=1.0;
		 	    		myCurrentScreen  = carsDesiScreen;
		 	    	}
		 	    }else hoverCar[2] = 0;



        	}break;
        	// -------------------------------------------------Maintenance search Screen--------------------------------------------------------------
        	case maintenSearchScreen : {
        		if(blackScreenForDynamiqMov>0.0) blackScreenForDynamiqMov-=0.3;
		 	    if(CheckCollisionPointRec( GetMousePosition(),(Rectangle){loadTexCarDesiScr[backbtnCar].myTextrPosit.x,loadTexCarDesiScr[backbtnCar].myTextrPosit.y,
		 	    	loadTexCarDesiScr[backbtnCar].myTextr.width,loadTexCarDesiScr[backbtnCar].myTextr.height} ) ){
		 	    	hoverSearch = 1;
		 	    	if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
						letters = 0;
						word[letters] = '\0';
		 	    		blackScreenForDynamiqMov=1.0;
		 	    		myCurrentScreen  = homeScreen;
		 	    	}
		 	    }else hoverSearch = 0;	

			if(CheckCollisionPointRec(GetMousePosition(),textPlace)) mouseOnSearchBar = 1;
			else mouseOnSearchBar=0;

			if(mouseOnSearchBar){

				SetMouseCursor(MOUSE_CURSOR_IBEAM);
				int key = GetCharPressed();
				while(key > 0){
					if((key >= 32) && (key <= 125) && (letters < 8)){
						word[letters] = (char)key;
						word[letters+1] = '\0';
						letters++;
					}
					key = GetCharPressed();
				}
				if(IsKeyPressed(KEY_BACKSPACE)){
					letters--;
					if(letters < 0) letters = 0;
					word[letters] = '\0';
				}

			}else SetMouseCursor(MOUSE_CURSOR_DEFAULT); 

			if(CheckCollisionPointRec(GetMousePosition(),searchIcone)){
				if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
					blackScreenForDynamiqMov=1.0;
					letters = 0;
					whichClient = clientData(clientInformation,numberClients,word);
					word[letters] = '\0';
					myCurrentScreen = maintenanceClientDetScreen;
				} 
				
			}

        	}break;
        	// -------------------------------------------------Maintenance client details Screen--------------------------------------------------------------
        	case maintenanceClientDetScreen : {
        		if(blackScreenForDynamiqMov>0.0) blackScreenForDynamiqMov-=0.3;
		 	    if(CheckCollisionPointRec( GetMousePosition(),(Rectangle){loadTexCarDesiScr[backbtnCar].myTextrPosit.x,loadTexCarDesiScr[backbtnCar].myTextrPosit.y,
		 	    	loadTexCarDesiScr[backbtnCar].myTextr.width,loadTexCarDesiScr[backbtnCar].myTextr.height} ) ){
		 	    	hoverSearch = 1;
		 	    	if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
		 	    		blackScreenForDynamiqMov=1.0;
		 	    		myCurrentScreen  = maintenSearchScreen;
		 	    	}
		 	    }else hoverSearch = 0;	

        	}break;

        }

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

			//ici c'est drawing                        
			BeginDrawing();
				ClearBackground(RAYWHITE);
				switch(myCurrentScreen){
			// -------------------------------------------------Home Screen--------------------------------------------------------------
				case homeScreen : {

				DrawTexture(loadTe[home].myTextr,loadTe[home].myTextrPosit.x,loadTe[home].myTextrPosit.y,WHITE);
				DrawTexturePro(loadTe[title].myTextr,sourceTitle,destTitle,(Vector2){0,0},0,WHITE);
				if(!hovlnmp) DrawTexture(loadTe[linktomap].myTextr,loadTe[linktomap].myTextrPosit.x,loadTe[linktomap].myTextrPosit.y,WHITE);
				else DrawTexture(loadTe[linktomap].myTextr,loadTe[linktomap].myTextrPosit.x,loadTe[linktomap].myTextrPosit.y,LIGHTGRAY); //LIGHTGRAY
				DrawTexture(loadTe[menu].myTextr,loadTe[menu].myTextrPosit.x,loadTe[menu].myTextrPosit.y,WHITE);
				// DrawText(TextFormat("%d",number),200,300,20,BLACK);
				DrawRectangle(0,0,scren_wdt,screen_hght,Fade(BLACK,blackScreenForDynamiqMov));
				
				if(tomap){
            	BeginMode2D(camera);
               		 DrawTextureRec(
                    	mapFrameBuffer.texture,                  
                    	(Rectangle){0, 0, mapFrameBuffer.texture.width, -mapFrameBuffer.texture.height},
                    	(Vector2){0.0, 0.0},
                    	WHITE);
            	EndMode2D();

				}


				}break;
			// -------------------------------------------------Employe Design Screen--------------------------------------------------------------
				case employeDesiScreen : {
					DrawTexture(myMainBackground,0,0,WHITE);
					myEmployDesiDraw(hoverEmpDesi,loadTe1);
					DrawRectangle(0,0,scren_wdt,screen_hght,Fade(BLACK,blackScreenForDynamiqMov));

				}break;
        	// -------------------------------------------------Employe Data Screen--------------------------------------------------------------				
				case employeDataScreen : {
					DrawTexture(myMainBackground,0,0,WHITE);
					switch(empDesVariables->whichEmploy){
						case clickOnstagiair :{
							myEmployDataDraw(hoverEmpData,loadTe1,informationsStg,whichOneInFile[clickOnstagiair],font,formDataBlckScr);
						}break;
						case clickOntechnicien :{
							myEmployDataDraw(hoverEmpData,loadTe1,informationsTech,whichOneInFile[clickOntechnicien],font,formDataBlckScr);
						}break;
						case clickOncommerceant :{
							myEmployDataDraw(hoverEmpData,loadTe1,informationsComm,whichOneInFile[clickOncommerceant],font,formDataBlckScr);
						}break;

					} //end switch
					DrawRectangle(0,0,scren_wdt,screen_hght,Fade(BLACK,blackScreenForDynamiqMov));
					
				}break;
				// -------------------------------------------------Car Design Screen--------------------------------------------------------------
				case carsDesiScreen : {
					DrawTexture(myMainBackground,0,0,WHITE);
					DrawTexture(loadTexCarDesiScr[backgrCars].myTextr,loadTexCarDesiScr[backgrCars].myTextrPosit.x,loadTexCarDesiScr[backgrCars].myTextrPosit.y,WHITE);
					DrawTextureRec(myCarImgs[firstCar],imagesRec,img1,WHITE);
					DrawTextEx(font,myCarInformations[firstCar].model,(Vector2){loadTexCarDesiScr[viewdetails1].myTextrPosit.x,img1.y},font.baseSize,1,DARKGRAY);
					DrawTextEx(font,myCarInformations[firstCar].anne,(Vector2){loadTexCarDesiScr[viewdetails1].myTextrPosit.x,img1.y+25},font.baseSize,1,DARKGRAY);
					DrawTextEx(font,myCarInformations[firstCar].stat,(Vector2){loadTexCarDesiScr[viewdetails1].myTextrPosit.x,img1.y+50},font.baseSize,1,DARKGRAY);
					DrawTexture(loadTexCarDesiScr[viewdetails1].myTextr,loadTexCarDesiScr[viewdetails1].myTextrPosit.x,loadTexCarDesiScr[viewdetails1].myTextrPosit.y,WHITE);

					if(secondCar<=nombreCars-1){ // nombreCars-1 hitax secondCar badi b 0
					DrawTextureRec(myCarImgs[secondCar],imagesRec,img2,WHITE);	
					DrawTextEx(font,myCarInformations[secondCar].model,(Vector2){loadTexCarDesiScr[viewdetails1].myTextrPosit.x ,img2.y},font.baseSize,1,DARKGRAY);
					DrawTextEx(font,myCarInformations[secondCar].anne,(Vector2){loadTexCarDesiScr[viewdetails1].myTextrPosit.x ,img2.y+25},font.baseSize,1,DARKGRAY);
					DrawTextEx(font,myCarInformations[secondCar].stat,(Vector2){loadTexCarDesiScr[viewdetails1].myTextrPosit.x ,img2.y+50},font.baseSize,1,DARKGRAY);
					DrawTexture(loadTexCarDesiScr[viewdetails2].myTextr,loadTexCarDesiScr[viewdetails1].myTextrPosit.x,loadTexCarDesiScr[viewdetails2].myTextrPosit.y,WHITE);
					}
					if(hoverCar[0]) DrawTexture(loadTexCarDesiScr[scrolldown].myTextr,loadTexCarDesiScr[scrolldown].myTextrPosit.x,
								    loadTexCarDesiScr[scrolldown].myTextrPosit.y,LIGHTGRAY);
					else 		DrawTexture(loadTexCarDesiScr[scrolldown].myTextr,loadTexCarDesiScr[scrolldown].myTextrPosit.x,
								loadTexCarDesiScr[scrolldown].myTextrPosit.y,WHITE);

					if(hoverCar[1]) DrawTexture(loadTexCarDesiScr[scrollup].myTextr,loadTexCarDesiScr[scrollup].myTextrPosit.x,
									loadTexCarDesiScr[scrollup].myTextrPosit.y,LIGHTGRAY);
					else 		DrawTexture(loadTexCarDesiScr[scrollup].myTextr,loadTexCarDesiScr[scrollup].myTextrPosit.x,
								loadTexCarDesiScr[scrollup].myTextrPosit.y,WHITE);

					if(hoverCar[2])  DrawTexture(loadTexCarDesiScr[backbtnCar].myTextr,loadTexCarDesiScr[backbtnCar].myTextrPosit.x,
									 loadTexCarDesiScr[backbtnCar].myTextrPosit.y,LIGHTGRAY);
					else        DrawTexture(loadTexCarDesiScr[backbtnCar].myTextr,loadTexCarDesiScr[backbtnCar].myTextrPosit.x,
								loadTexCarDesiScr[backbtnCar].myTextrPosit.y,WHITE);

					DrawRectangle(loadTexCarDesiScr[backgrCars].myTextrPosit.x,loadTexCarDesiScr[backgrCars].myTextrPosit.y,
						loadTexCarDesiScr[backgrCars].myTextr.width,loadTexCarDesiScr[backgrCars].myTextr.height,Fade(BLACK,scrollCarBlckScr));

					DrawRectangle(0,0,scren_wdt,screen_hght,Fade(BLACK,blackScreenForDynamiqMov));

				}break;
				// -------------------------------------------------Car details Screen--------------------------------------------------------------
        		case carsDetailsScreen : {
        			DrawTexture(myMainBackground,0,0,WHITE);
        			DrawTexture(loadTexCarDesiScr[backgrDetailCars].myTextr,loadTexCarDesiScr[backgrDetailCars].myTextrPosit.x,loadTexCarDesiScr[backgrDetailCars].myTextrPosit.y,WHITE);
					DrawTextureRec(myDetailsCarImgs[whichCar],imgesDetailRec,imgDetail,WHITE);
					DrawTextEx(font,"Fiche Standard",(Vector2){imgDetail.x +imgesDetailRec.width+16,imgDetail.y + 10},font.baseSize,0.5,GRAY);	
					DrawTextEx(font,"Modele: ",(Vector2){imgDetail.x +imgesDetailRec.width+16,imgDetail.y + 50},font.baseSize,0.5,WHITE);
					DrawTextEx(font,myCarInformations[whichCar].model,(Vector2){imgDetail.x+imgesDetailRec.width+120,imgDetail.y + 50},font.baseSize,0.5,WHITE);
					DrawTextEx(font,"Annee: ",(Vector2){imgDetail.x +imgesDetailRec.width+16,imgDetail.y + 50+32},font.baseSize,0.5,WHITE);
					DrawTextEx(font,myCarInformations[whichCar].anne,(Vector2){imgDetail.x+imgesDetailRec.width+120,imgDetail.y + 50+32},font.baseSize,0.5,WHITE);
					DrawTextEx(font,"Prix: ",(Vector2){imgDetail.x +imgesDetailRec.width+16,imgDetail.y + 50+32*2},font.baseSize,0.5,WHITE);
					DrawTextEx(font,myCarInformations[whichCar].prix,(Vector2){imgDetail.x+imgesDetailRec.width+120,imgDetail.y + 50+32*2},font.baseSize,0.5,WHITE);
					DrawTextEx(font,"Etat : ",(Vector2){imgDetail.x +imgesDetailRec.width+16,imgDetail.y + 50+32*3},font.baseSize,0.5,WHITE);
					DrawTextEx(font,myCarInformations[whichCar].stat,(Vector2){imgDetail.x+imgesDetailRec.width+120,imgDetail.y + 50+32*3},font.baseSize,0.5,WHITE);		
					DrawTextEx(font,"Fiche Technique",(Vector2){imgDetail.x +imgesDetailRec.width+16,imgDetail.y + 50+32*4},font.baseSize,0.5,GRAY);	
					
					DrawTextEx(font,"Motor: ",(Vector2){imgDetail.x +imgesDetailRec.width+16,imgDetail.y + 50+32*5},font.baseSize,0.5,WHITE);
					DrawTextEx(font,myCarInformations[whichCar].info1,(Vector2){imgDetail.x+imgesDetailRec.width+120,imgDetail.y + 50+32*5},font.baseSize,0.5,WHITE);
					DrawTextEx(font,"P Max: ",(Vector2){imgDetail.x +imgesDetailRec.width+16,imgDetail.y + 50+32*6},font.baseSize,0.5,WHITE);
					DrawTextEx(font,myCarInformations[whichCar].info2,(Vector2){imgDetail.x+imgesDetailRec.width+120,imgDetail.y + 50+32*6},font.baseSize,0.5,WHITE);
					DrawTextEx(font,"P fiscale: ",(Vector2){imgDetail.x +imgesDetailRec.width+16,imgDetail.y + 50+32*7},font.baseSize,0.5,WHITE);
					DrawTextEx(font,myCarInformations[whichCar].info3,(Vector2){imgDetail.x+imgesDetailRec.width+120,imgDetail.y + 50+32*7},font.baseSize,0.5,WHITE);
					DrawTextEx(font,"B vitesses: ",(Vector2){imgDetail.x +imgesDetailRec.width+16,imgDetail.y + 50+32*8},font.baseSize,0.5,WHITE);
					DrawTextEx(font,myCarInformations[whichCar].info4,(Vector2){imgDetail.x+imgesDetailRec.width+120,imgDetail.y + 50+32*8},font.baseSize,0.5,WHITE);
					DrawTextEx(font,"G(ans): ",(Vector2){imgDetail.x +imgesDetailRec.width+16,imgDetail.y + 50+32*9},font.baseSize,0.5,WHITE);
					DrawTextEx(font,myCarInformations[whichCar].info5,(Vector2){imgDetail.x+imgesDetailRec.width+120,imgDetail.y + 50+32*9},font.baseSize,0.5,WHITE);					
					
					if(hoverCar[2])  DrawTexture(loadTexCarDesiScr[backbtnCar].myTextr,loadTexCarDesiScr[backbtnCar].myTextrPosit.x,
									 loadTexCarDesiScr[backbtnCar].myTextrPosit.y,LIGHTGRAY);
					else        DrawTexture(loadTexCarDesiScr[backbtnCar].myTextr,loadTexCarDesiScr[backbtnCar].myTextrPosit.x,
								loadTexCarDesiScr[backbtnCar].myTextrPosit.y,WHITE);

					
					DrawRectangle(loadTexCarDesiScr[backgrCars].myTextrPosit.x,loadTexCarDesiScr[backgrCars].myTextrPosit.y,
						loadTexCarDesiScr[backgrCars].myTextr.width,loadTexCarDesiScr[backgrCars].myTextr.height,Fade(BLACK,scrollCarBlckScr));

					DrawRectangle(0,0,scren_wdt,screen_hght,Fade(BLACK,blackScreenForDynamiqMov));
        		}break;
        		// -------------------------------------------------Maintenance search Screen--------------------------------------------------------------
        		case maintenSearchScreen : {
        			DrawTexture(myMainBackground,0,0,WHITE);
 					if(hoverSearch)  DrawTexture(loadTexCarDesiScr[backbtnCar].myTextr,loadTexCarDesiScr[backbtnCar].myTextrPosit.x,
									 loadTexCarDesiScr[backbtnCar].myTextrPosit.y,LIGHTGRAY);
					else        DrawTexture(loadTexCarDesiScr[backbtnCar].myTextr,loadTexCarDesiScr[backbtnCar].myTextrPosit.x,
								loadTexCarDesiScr[backbtnCar].myTextrPosit.y,WHITE); 
								
					DrawTexture(searchBar,searchBarPosition.x,searchBarPosition.y,LIGHTGRAY);
					DrawTextEx(font,word,(Vector2){textPlace.x,textPlace.y},font.baseSize,0.5,DARKGRAY);      			

        			DrawRectangle(0,0,scren_wdt,screen_hght,Fade(BLACK,blackScreenForDynamiqMov));
        		}break;
        		// -------------------------------------------------Maintenance client details Screen--------------------------------------------------------------
        		case maintenanceClientDetScreen : {
         			DrawTexture(myMainBackground,0,0,WHITE);
 					if(hoverSearch)  DrawTexture(loadTexCarDesiScr[backbtnCar].myTextr,loadTexCarDesiScr[backbtnCar].myTextrPosit.x,
									 loadTexCarDesiScr[backbtnCar].myTextrPosit.y,LIGHTGRAY);
					else        DrawTexture(loadTexCarDesiScr[backbtnCar].myTextr,loadTexCarDesiScr[backbtnCar].myTextrPosit.x,
								loadTexCarDesiScr[backbtnCar].myTextrPosit.y,WHITE); 
								
					DrawTexture(tableClient,tableClientPosition.x,tableClientPosition.y,WHITE);
					DrawTextEx(font,clientInformation[whichClient].prenom,(Vector2){tableClientPosition.x+16,tableClientPosition.y+60},font.baseSize,0.5,DARKGRAY);
					DrawTextEx(font,clientInformation[whichClient].nom,(Vector2){tableClientPosition.x+16+170,tableClientPosition.y+60},font.baseSize,0.5,DARKGRAY);
					DrawTextEx(font,clientInformation[whichClient].matric,(Vector2){tableClientPosition.x+16*2+170*2,tableClientPosition.y+60},font.baseSize,0.5,DARKGRAY);
					DrawTextEx(font,clientInformation[whichClient].prixTo,(Vector2){tableClientPosition.x+16,tableClientPosition.y+60+110},font.baseSize,0.5,DARKGRAY);
					DrawTextEx(font,clientInformation[whichClient].datee,(Vector2){tableClientPosition.x+16+170,tableClientPosition.y+60+110},font.baseSize,0.5,DARKGRAY);
					DrawTextEx(font,clientInformation[whichClient].problem,(Vector2){tableClientPosition.x+16*2+170*2,tableClientPosition.y+60+110},font.baseSize,0.5,DARKGRAY);
					DrawRectangle(0,0,scren_wdt,screen_hght,Fade(BLACK,blackScreenForDynamiqMov));
       			
        		}break;
			}	

			EndDrawing();
		}


	CloseWindow();
	return 0;
}




