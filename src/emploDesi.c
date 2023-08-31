#include "raylib.h"
#include <stdlib.h>
#include <string.h>
#include "autHolHeadFil.h"


employDesi* myEmployDesiVariables(employDesi* empDesVariables,texturAndPosit* allTex){
		
		if(CheckCollisionPointRec(GetMousePosition(),
			(Rectangle){allTex[commercant].myTextrPosit.x,allTex[commercant].myTextrPosit.y,
								allTex[commercant].myTextr.width,allTex[commercant].myTextr.height}) ){
			empDesVariables->hoversat[0] = true;
			if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
				empDesVariables->blckScr = 1.0f;
				empDesVariables->whichEmploy = clickOncommerceant;
				empDesVariables->screenState = employeDataScreen;
			}
		}else empDesVariables->hoversat[0] = false;

		if(CheckCollisionPointRec(GetMousePosition(),
			(Rectangle){allTex[technicien].myTextrPosit.x,allTex[technicien].myTextrPosit.y,
						allTex[technicien].myTextr.width,allTex[technicien].myTextr.height}) ){
			empDesVariables->hoversat[1] = true;
			if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
				empDesVariables->blckScr = 1.0f;
				empDesVariables->whichEmploy = clickOntechnicien;
				empDesVariables->screenState = employeDataScreen;
			}
		}else empDesVariables->hoversat[1] = false;

		if(CheckCollisionPointRec(GetMousePosition(),
			(Rectangle){allTex[stagiar].myTextrPosit.x,allTex[stagiar].myTextrPosit.y,
						allTex[stagiar].myTextr.width,allTex[stagiar].myTextr.height}) ){
			empDesVariables->hoversat[2] = true;
			if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
				empDesVariables->blckScr = 1.0f;
				empDesVariables->whichEmploy = clickOnstagiair;
				empDesVariables->screenState = employeDataScreen;
			}
		}else empDesVariables->hoversat[2] = false;

		if(CheckCollisionPointRec(GetMousePosition(),
			(Rectangle){allTex[backbtn].myTextrPosit.x,allTex[backbtn].myTextrPosit.y,
					   allTex[backbtn].myTextr.width,allTex[backbtn].myTextr.height}) ){
			empDesVariables->hoversat[3] = true;
			if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
				empDesVariables->screenState = homeScreen;
			}
		}else empDesVariables->hoversat[3] = false;

	
	return empDesVariables;
}

void myEmployDesiDraw(int hoversata[4],texturAndPosit* allTex){

		if(hoversata[0]) DrawTexture(allTex[commercant].myTextr,allTex[commercant].myTextrPosit.x,allTex[commercant].myTextrPosit.y,LIGHTGRAY);
		else DrawTexture(allTex[commercant].myTextr,allTex[commercant].myTextrPosit.x,allTex[commercant].myTextrPosit.y,WHITE);

		if(hoversata[1]) DrawTexture(allTex[technicien].myTextr,allTex[technicien].myTextrPosit.x,allTex[technicien].myTextrPosit.y,LIGHTGRAY);
		else DrawTexture(allTex[technicien].myTextr,allTex[technicien].myTextrPosit.x,allTex[technicien].myTextrPosit.y,WHITE); 

		if(hoversata[2]) DrawTexture(allTex[stagiar].myTextr,allTex[stagiar].myTextrPosit.x,allTex[stagiar].myTextrPosit.y,LIGHTGRAY);
		else DrawTexture(allTex[stagiar].myTextr,allTex[stagiar].myTextrPosit.x,allTex[stagiar].myTextrPosit.y,WHITE); 

		if(hoversata[3]) DrawTexture(allTex[backbtn].myTextr,allTex[backbtn].myTextrPosit.x,allTex[backbtn].myTextrPosit.y,LIGHTGRAY);
		else DrawTexture(allTex[backbtn].myTextr,allTex[backbtn].myTextrPosit.x,allTex[backbtn].myTextrPosit.y,WHITE);

}
