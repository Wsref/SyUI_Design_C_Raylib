#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "autHolHeadFil.h"





void myEmployDataDraw(int hoverStat[3],texturAndPosit* allTex,mydataEmpl* informations,int whichOne,Font font,float show){

		DrawTexture(allTex[identform].myTextr,allTex[identform].myTextrPosit.x,allTex[identform].myTextrPosit.y,WHITE);
		if(hoverStat[0]) DrawTexture(allTex[goleftbtn].myTextr,allTex[goleftbtn].myTextrPosit.x,allTex[goleftbtn].myTextrPosit.y,LIGHTGRAY);
		else DrawTexture(allTex[goleftbtn].myTextr,allTex[goleftbtn].myTextrPosit.x,allTex[goleftbtn].myTextrPosit.y,WHITE);

		if(hoverStat[1]) DrawTexture(allTex[gorightbtn].myTextr,allTex[gorightbtn].myTextrPosit.x,allTex[gorightbtn].myTextrPosit.y,LIGHTGRAY);
		else DrawTexture(allTex[gorightbtn].myTextr,allTex[gorightbtn].myTextrPosit.x,allTex[gorightbtn].myTextrPosit.y,WHITE);

		if(hoverStat[2]) DrawTexture(allTex[backbtn].myTextr,allTex[backbtn].myTextrPosit.x,allTex[backbtn].myTextrPosit.y,LIGHTGRAY);
		else DrawTexture(allTex[backbtn].myTextr,allTex[backbtn].myTextrPosit.x,allTex[backbtn].myTextrPosit.y,WHITE);

		DrawTextEx(font,informations[whichOne].fullname,
			      (Vector2){allTex[identform].myTextrPosit.x+128,allTex[identform].myTextrPosit.y+112},
				   font.baseSize,1,WHITE);

		DrawTextEx(font,informations[whichOne].email,
				  (Vector2){allTex[identform].myTextrPosit.x+96,allTex[identform].myTextrPosit.y+112+30},
				   font.baseSize/1.2f,1,GRAY);

		DrawTextEx(font,TextFormat("Id \t %s", informations[whichOne].id),
				  (Vector2){allTex[identform].myTextrPosit.x+64,allTex[identform].myTextrPosit.y+208},
				   font.baseSize,1,WHITE);

		DrawTextEx(font,TextFormat("Statut d'emploi \t %s", informations[whichOne].statEmploi),
				   (Vector2){allTex[identform].myTextrPosit.x+64,allTex[identform].myTextrPosit.y+208+32},
				   font.baseSize,1,WHITE);

		DrawTextEx(font,TextFormat("Salaire \t %s", informations[whichOne].salr),
				  (Vector2){allTex[identform].myTextrPosit.x+64,allTex[identform].myTextrPosit.y+208+32*2},
				   font.baseSize,1,WHITE);

		DrawTextEx(font,TextFormat("Duree \t %s", informations[whichOne].duree),
				  (Vector2){allTex[identform].myTextrPosit.x+64,allTex[identform].myTextrPosit.y+208+32*3},
				   font.baseSize,1,WHITE);

		DrawRectangle(allTex[identform].myTextrPosit.x,allTex[identform].myTextrPosit.y,
					 allTex[identform].myTextr.width,allTex[identform].myTextr.height,Fade(WHITE,show));
			

}


