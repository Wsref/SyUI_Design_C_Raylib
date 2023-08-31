#include "raylib.h"
#include "autHolHeadFil.h"







float scrollingUp(float framecoonter,float recAbsolutPosition,float recOriginPosition,float movingDistance){ // buttonLfo9

	float t = (movingDistance/=framecoonter);
	if(t>1) return recAbsolutPosition+=1;
	if(t<=1&&recAbsolutPosition>recOriginPosition) return recAbsolutPosition-=1;
	return recAbsolutPosition;

}
float scrollingDown(float framecoonter,float recAbsolutPosition,float recOriginPosition,float movingDistance){ // button lta7t

	float t = (movingDistance/=framecoonter);
	if(t>1) return recAbsolutPosition-1;
	if(t<=1&&recAbsolutPosition<recOriginPosition) return recAbsolutPosition+=1;
	return recAbsolutPosition;

}