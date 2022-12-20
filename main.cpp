#include<graphics.h>
#include<time.h>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

int endofunc(int e, int a);

int main(){

    int gd,gm,fx=200,fy=200 ,x[200] = {},y[200] = {},d;

    //Food eaten
    int score=1;
    int chk = 700;
    //directions
    int dir=1;


    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"");

    x[0]=200,y[0]=200;
    d=1;
    int length = 1;

for(;;){
    setfillstyle(1,0);
    bar(0,0,640,480);
    setfillstyle(1,YELLOW);
    bar(0,0,640,10);
    bar(0,0,10,480);
    bar(0,480,640,470);
    bar(630,10,640,480);
       // food taken?

    setfillstyle(1,15);
   if(x[0]==fx && y[0]==fy ){
    length += 1;
    score += 1;

    //setfillstyle(1,15);
    bar(fx,fy,fx+10,fy+10);


    //make food
    do{
	fx = (1+rand()%630);
	fy = (1+rand()%470);
    }while(getpixel(fx,fy)!=0 && fx > 10 && fy > 10);

    fx=fx/10;
    fx=fx*10;
    fy=fy/10;
    fy=fy*10;
   }
    bar(fx,fy,fx+10,fy+10);



    if(GetAsyncKeyState(VK_RIGHT)){d=1;}
    else if(GetAsyncKeyState(VK_LEFT)){ d=2;}
    else if(GetAsyncKeyState(VK_UP)){ d=3;}
    else if(GetAsyncKeyState(VK_DOWN)) {d=4;}
    else{d=0;}
    switch(d){
    case 0:
      if(dir==1){x[0]=x[0]+10;}
      else if(dir==2){x[0]=x[0]-10;}
      else if(dir==3){ y[0]=y[0]-10;}
      else if(dir==4) {y[0]=y[0]+10;}
      else{d=0;}
      break;
    case 1:
           x[0]=x[0]+10;
           dir=1;
           break;
    case 2:
         x[0]= x[0]-10;
         dir=2;
          break;
    case 3:
        dir=3;
        y[0]=y[0]-10;
        break;
    case 4:
        dir=4;
       y[0]= y[0]+10;
        break;
    }
    for(int i = 0; i < length;i++){

        if(i%4 == 0 || i % 4 == 3)setfillstyle(1, 15);

        else setfillstyle(1, 7);

        bar(x[i],y[i],x[i]+10,y[i]+10);
    }
    for(int i= 199; i >0;i--){
        x[i] = x[i-1];
        y[i] = y[i -1];
    }
    delay(100);
    if(x[0] >= 640 || x[0]<=0|| y[0]<=0 || y[0]>=480){
    endofunc(score,0);
    break;
    }

    for(int i = 2; i < length;i++){
        if(x[0] == x[i] && y[0] == y[i]){
            chk = i;
            break;
            }
    }
    if(x[0] == x[chk] && y[0] == y[chk]){
    endofunc(score,1);
    break;
    }
}
}

int endofunc(int e,int a){
    setfillstyle(1,0);
    e=e-2;
    bar(0,0,640,480);
    system("cls");
    if(a == 0){
        printf("You died outside the boundary!!!\n");
    }
    else if(a== 1){
        printf("You died into yourself!!!\n");
    }
    printf("Your score is : %d\n", e);
    getch();
    return 0;
}

