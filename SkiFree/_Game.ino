void game_init(){
  game.gameStatus = GAMEMAKERS;
  game.globalTimer = 0;
  game.pause=0;
  game.menuOption=1;
  game.menuPauseOption=0;
}

void game_initPlayer(){
  player.xPosition=20;       //in the world
  player.yPosition=100;      //in the world
  player.currentPosition=4;  //0.Left / 1.LeftBottom / 2.Bottom / 3.RightBottom / 4.Right / 5.Up
  player.xSpeed=0;
  player.ySpeed=0;
  player.speedTimer=0;
  player.anim=0;
}

void game_initJump(){
  jump.maxAlt=12;
  jump.currentAlt=0;
  jump.isGoingUp=true;
  jump.stuntCounter=0;
  jump.combo=0;
}


void game_initItems(){
  //Tree001
  Map[0].type=0;   Map[0].xPosition=1;  Map[0].yPosition=2;
  Map[1].type=0;   Map[1].xPosition=89;  Map[1].yPosition=62;
  Map[2].type=0;   Map[2].xPosition=244;  Map[2].yPosition=69;
  Map[3].type=0;   Map[3].xPosition=189;  Map[3].yPosition=187;
  Map[4].type=0;   Map[4].xPosition=45;  Map[4].yPosition=229;
  Map[5].type=0;   Map[5].xPosition=154;  Map[5].yPosition=255;
  Map[6].type=0;   Map[6].xPosition=194;  Map[6].yPosition=327;
  Map[7].type=0;   Map[7].xPosition=49;  Map[7].yPosition=385;
  Map[8].type=0;   Map[8].xPosition=161;  Map[8].yPosition=415;
  Map[9].type=0;   Map[9].xPosition=267;  Map[9].yPosition=444;
  Map[10].type=0;   Map[10].xPosition=19;  Map[10].yPosition=487;
  Map[11].type=0;   Map[11].xPosition=136;  Map[11].yPosition=555;
  
  //Tree002
  Map[12].type=1;   Map[12].xPosition=166;  Map[12].yPosition=9;
  Map[13].type=1;   Map[13].xPosition=38;  Map[13].yPosition=46;
  Map[14].type=1;   Map[14].xPosition=142;  Map[14].yPosition=127;
  Map[15].type=1;   Map[15].xPosition=55;  Map[15].yPosition=145;
  Map[16].type=1;   Map[16].xPosition=246;  Map[16].yPosition=156;
  Map[17].type=1;   Map[17].xPosition=100;  Map[17].yPosition=215;
  Map[18].type=1;   Map[18].xPosition=28;  Map[18].yPosition=290;
  Map[19].type=1;   Map[19].xPosition=254;  Map[19].yPosition=300;
  Map[20].type=1;   Map[20].xPosition=127;  Map[20].yPosition=324;
  Map[21].type=1;   Map[21].xPosition=247;  Map[21].yPosition=396;
  Map[22].type=1;   Map[22].xPosition=75;  Map[22].yPosition=422;
  Map[23].type=1;   Map[23].xPosition=203;  Map[23].yPosition=476;
  Map[24].type=1;   Map[24].xPosition=50;  Map[24].yPosition=504;
  Map[25].type=1;   Map[25].xPosition=246;  Map[25].yPosition=537;
  Map[26].type=1;   Map[26].xPosition=70;  Map[26].yPosition=550;
  
  //Rock
  Map[27].type=2;   Map[27].xPosition=70;  Map[27].yPosition=27;
  Map[28].type=2;   Map[28].xPosition=243;  Map[28].yPosition=39;
  Map[29].type=2;   Map[29].xPosition=16;  Map[29].yPosition=113;
  Map[30].type=2;   Map[30].xPosition=91;  Map[30].yPosition=152;
  Map[31].type=2;   Map[31].xPosition=253;  Map[31].yPosition=224;
  Map[32].type=2;   Map[32].xPosition=14;  Map[32].yPosition=250;
  Map[33].type=2;   Map[33].xPosition=162;  Map[33].yPosition=329;
  Map[34].type=2;   Map[34].xPosition=7;  Map[34].yPosition=385;
  Map[35].type=2;   Map[35].xPosition=219;  Map[35].yPosition=442;
  Map[36].type=2;   Map[36].xPosition=28;  Map[36].yPosition=450;
  Map[37].type=2;   Map[37].xPosition=177;  Map[37].yPosition=468;
  Map[38].type=2;   Map[38].xPosition=263;  Map[38].yPosition=507;
  Map[39].type=2;   Map[39].xPosition=36;  Map[39].yPosition=533;
  
  //Bush
  Map[40].type=3;   Map[40].xPosition=49;  Map[40].yPosition=73;
  Map[41].type=3;   Map[41].xPosition=277;  Map[41].yPosition=115;
  Map[42].type=3;   Map[42].xPosition=96;  Map[42].yPosition=118;
  Map[43].type=3;   Map[43].xPosition=7;  Map[43].yPosition=178;
  Map[44].type=3;   Map[44].xPosition=223;  Map[44].yPosition=232;
  Map[45].type=3;   Map[45].xPosition=70;  Map[45].yPosition=236;
  Map[46].type=3;   Map[46].xPosition=201;  Map[46].yPosition=296;
  Map[47].type=3;   Map[47].xPosition=14;  Map[47].yPosition=320;
  Map[48].type=3;   Map[48].xPosition=179;  Map[48].yPosition=354;
  Map[49].type=3;   Map[49].xPosition=17;  Map[49].yPosition=405;
  Map[50].type=3;   Map[50].xPosition=230;  Map[50].yPosition=420;
  Map[51].type=3;   Map[51].xPosition=95;  Map[51].yPosition=462;
  Map[52].type=3;   Map[52].xPosition=263;  Map[52].yPosition=482;
  Map[53].type=3;   Map[53].xPosition=105;  Map[53].yPosition=505;
  Map[54].type=3;   Map[54].xPosition=180;  Map[54].yPosition=514;
  Map[55].type=3;   Map[55].xPosition=10;  Map[55].yPosition=535;
  Map[56].type=3;   Map[56].xPosition=280;  Map[56].yPosition=544;
  Map[57].type=3;   Map[57].xPosition=224;  Map[57].yPosition=565;
  Map[58].type=3;   Map[58].xPosition=40;  Map[58].yPosition=573;
  Map[59].type=3;   Map[59].xPosition=121;  Map[59].yPosition=581;
  
  //Jumper
  Map[60].type=4;   Map[60].xPosition=145;  Map[60].yPosition=48;
  Map[61].type=4;   Map[61].xPosition=29;  Map[61].yPosition=167;
  Map[62].type=4;   Map[62].xPosition=220;  Map[62].yPosition=178;
  Map[63].type=4;   Map[63].xPosition=141;  Map[63].yPosition=299;
  Map[64].type=4;   Map[64].xPosition=224;  Map[64].yPosition=343;
  Map[65].type=4;   Map[65].xPosition=31;  Map[65].yPosition=345;
  Map[66].type=4;   Map[66].xPosition=103;  Map[66].yPosition=544;

  //PNJ
  Pnj[0].type=5;   Pnj[0].xPosition=203;  Pnj[0].yPosition=86;
  Pnj[1].type=5;   Pnj[1].xPosition=31;  Pnj[1].yPosition=113;
  Pnj[2].type=5;   Pnj[2].xPosition=243;  Pnj[2].yPosition=231;
  Pnj[3].type=5;   Pnj[3].xPosition=123;  Pnj[3].yPosition=408;
  Pnj[4].type=5;   Pnj[4].xPosition=214;  Pnj[4].yPosition=510;
  
  Pnj[5].type=6;   Pnj[5].xPosition=83;  Pnj[5].yPosition=3;
  Pnj[6].type=6;   Pnj[6].xPosition=285;  Pnj[6].yPosition=167;
  Pnj[7].type=6;   Pnj[7].xPosition=173;  Pnj[7].yPosition=319;
  Pnj[8].type=6;   Pnj[8].xPosition=19;  Pnj[8].yPosition=425;
  
  Pnj[9].type=7;   Pnj[9].xPosition=284;  Pnj[9].yPosition=72;
  Pnj[10].type=7;   Pnj[10].xPosition=160;  Pnj[10].yPosition=211;
  Pnj[11].type=7;   Pnj[11].xPosition=287;  Pnj[11].yPosition=383;
  Pnj[12].type=7;   Pnj[12].xPosition=18;  Pnj[12].yPosition=548;

  Pnj[13].type=8;   Pnj[13].xPosition=300;  Pnj[13].yPosition=600;
}

void game_initItemTypes(){
  Item[0].type=0; Item[0].xHitBox=6; Item[0].yHitBox=16; Item[0].widthHitBox=7; Item[0].heightHitBox=8; Item[0].collisionEffect=0; //Tree
  Item[1].type=1; Item[1].xHitBox=6; Item[1].yHitBox=16; Item[1].widthHitBox=7; Item[1].heightHitBox=8; Item[1].collisionEffect=0; //Tree
  Item[2].type=2; Item[2].xHitBox=2; Item[2].yHitBox=2;  Item[2].widthHitBox=7; Item[2].heightHitBox=5; Item[2].collisionEffect=0; //Rock
  Item[3].type=3; Item[3].xHitBox=3; Item[3].yHitBox=6;  Item[3].widthHitBox=5; Item[3].heightHitBox=5; Item[3].collisionEffect=0; //Bush
  Item[4].type=4; Item[4].xHitBox=3; Item[4].yHitBox=3;  Item[4].widthHitBox=12;Item[4].heightHitBox=2; Item[4].collisionEffect=1; //Jump
  
  Item[5].type=5; Item[5].xHitBox=3; Item[5].yHitBox=5;  Item[5].widthHitBox=5 ;Item[5].heightHitBox=5; Item[5].collisionEffect=0; //Skier
  Item[6].type=6; Item[6].xHitBox=1; Item[6].yHitBox=6;  Item[6].widthHitBox=4 ;Item[6].heightHitBox=5; Item[6].collisionEffect=0; //Surfer
  Item[7].type=7; Item[7].xHitBox=1; Item[7].yHitBox=2;  Item[7].widthHitBox=5 ;Item[7].heightHitBox=3; Item[7].collisionEffect=0; //Dog
  Item[8].type=8; Item[8].xHitBox=5; Item[8].yHitBox=10; Item[8].widthHitBox=5 ;Item[8].heightHitBox=6; Item[8].collisionEffect=3; //Monster
  
}

void game_manageGlobalCounter(){
  switch ( game.gameStatus ){
     //#################################### 
     case GAMEMAKERS:
        if(game.globalTimer<30){
          game.globalTimer = game.globalTimer +1;
        }else{
          game.globalTimer = 0;
          game.gameStatus = TITLESCREEN;
        }
        break;

     //####################################  
     case TITLESCREEN:
        if(game.globalTimer<30){
          game.globalTimer = game.globalTimer +1;
        }else{
          game.globalTimer = 0;
          game.gameStatus = MENU;
        }
        break;
     //####################################  
     case MENU:
        break;
        
     //####################################  
     case CONTROLS:
        break;
        
     //####################################  
     case CREDITS:
        break;


     //####################################  
     case GAME:
        game.globalTimer = game.globalTimer +1;
        if(game.globalTimer>29){game.globalTimer=0;}
        break;
     //####################################  
     case COLLIDE:
        break;
     //####################################  
     case JUMP:
        break;        
     //####################################  
     case MENUPAUSE:
        break;

                          
     default:
        game.gameStatus = GAMEMAKERS;
        break;
  }
}


//##################
//## HitBox ########
//##################
void game_checkHitBox(){
  // Player Hitbox: MIDDLESCREEN-6+6, 1+8,  MIDDLESCREEN-6+6+3, 1+8+5
  for(int i=0; i<NbOfItem; i++){
    for(int j=0; j<NbOfKindOfItem; j++){
      if(Item[j].type==Map[i].type){
        if(checkCollide(MIDDLESCREEN-6+6,PLAYER_Y_POS+8,3,5, Map[i].xPosition+Item[j].xHitBox, Map[i].yPosition+Item[j].yHitBox,Item[j].widthHitBox,Item[j].heightHitBox)){
          gb.display.setCursor(0,0);
          if(Item[j].collisionEffect==0){game.gameStatus=COLLIDE;} //Fall
          if(Item[j].collisionEffect==1){game.gameStatus=JUMP; player.xSpeed=0; player.ySpeed=3; player.currentPosition=2;} //Jump
          if(Item[j].collisionEffect==2){gb.display.setColor(ORANGE);gb.display.println("Yeah!");} //Score     
        }
      }
    }
  }

  for(int i=0; i<NbOfPnj; i++){
    for(int j=0; j<NbOfKindOfItem; j++){
      if(Item[j].type==Pnj[i].type){
        if(checkCollide(MIDDLESCREEN-6+6,PLAYER_Y_POS+8,3,5, Pnj[i].xPosition+Item[j].xHitBox, Pnj[i].yPosition+Item[j].yHitBox,Item[j].widthHitBox,Item[j].heightHitBox)){
          gb.display.setCursor(0,0);
          if(Item[j].collisionEffect==0){game.gameStatus=COLLIDE;} //Fall
          if(Item[j].collisionEffect==3){gb.display.setColor(ORANGE);gb.display.println("Game Over!");} //Score     
        }
      }
    }
  }
}

//#########################
//## HitBoxCollide ########
//#########################
void game_checkHitBoxCollide(){
  // Player Hitbox: MIDDLESCREEN-6+6, 1+8,  MIDDLESCREEN-6+6+3, 1+8+5
  bool isCollide = false;
  for(int i=0; i<NbOfItem; i++){
    for(int j=0; j<NbOfKindOfItem; j++){
      if(Item[j].type==Map[i].type){
        if(checkCollide(MIDDLESCREEN-6+5,PLAYER_Y_POS+8,5,5, Map[i].xPosition+Item[j].xHitBox, Map[i].yPosition+Item[j].yHitBox,Item[j].widthHitBox,Item[j].heightHitBox)){
          if(Item[j].collisionEffect==0){
            if(player.ySpeed<0){player.ySpeed = player.ySpeed*-1;}
            isCollide=true;
            game_playerAnimNext();
          }
        }
      }
    }
  }
  if(isCollide==false){
    player.xSpeed=0;
    player.ySpeed=0;
    game_playerAnimReset();
  }
}

//#########################
//## HitBoxJump ###########
//#########################
void game_checkHitBoxJump(){
  if(jump.currentAlt<=0 && jump.isGoingUp==false){
    if(jump.stuntCounter==0){
      score = score + (jump.combo*150);
      game.gameStatus = GAME;
    }else{
      game.gameStatus = COLLIDE;
      score = score - 100;
    }
    game_initJump();
  }
}

//#########################
//## JumpAltitude #########
//#########################
void game_moveAltitude(){
  if(jump.isGoingUp==true){
    if(jump.currentAlt==jump.maxAlt){jump.isGoingUp=false;}
    else if(jump.currentAlt>=jump.maxAlt-2){jump.currentAlt=jump.currentAlt+1;}
    else if(jump.currentAlt>=jump.maxAlt-6){jump.currentAlt=jump.currentAlt+2;}
    else {jump.currentAlt=jump.currentAlt+3;}
  }else{
    if(jump.currentAlt>=jump.maxAlt){jump.currentAlt=jump.currentAlt-1;}
    else if(jump.currentAlt>=jump.maxAlt-2){jump.currentAlt=jump.currentAlt-1;}
    else if(jump.currentAlt>=jump.maxAlt-6){jump.currentAlt=jump.currentAlt-2;}
    else {jump.currentAlt=jump.currentAlt-2;}    
  }
}

//#########################
//## MoveBackground #######
//#########################
void game_moveBackground(){
  for(int i=0; i<NbOfItem; i++){
    Map[i].yPosition = Map[i].yPosition - player.ySpeed;
    if(Map[i].yPosition>300){Map[i].yPosition=Map[i].yPosition-600;}
    if(Map[i].yPosition<=-300){Map[i].yPosition=Map[i].yPosition+600;}
    
    Map[i].xPosition = Map[i].xPosition - player.xSpeed;
    if(Map[i].xPosition>150){Map[i].xPosition=Map[i].xPosition-300;}
    if(Map[i].xPosition<=-150){Map[i].xPosition=Map[i].xPosition+300;}
  }
  for(int i=0; i<NbOfPnj; i++){
    Pnj[i].yPosition = Pnj[i].yPosition - player.ySpeed;
    if(Pnj[i].yPosition>300){Pnj[i].yPosition=Pnj[i].yPosition-600;}
    if(Pnj[i].yPosition<=-300){Pnj[i].yPosition=Pnj[i].yPosition+600;}
    
    Pnj[i].xPosition = Pnj[i].xPosition - player.xSpeed;
    if(Pnj[i].xPosition>150){Pnj[i].xPosition=Pnj[i].xPosition-300;}
    if(Pnj[i].xPosition<=-150){Pnj[i].xPosition=Pnj[i].xPosition+300;}
  }
}

//#########################
//## MovePnj #######
//#########################
void game_movePnj(){
  for(int i=0; i<NbOfPnj; i++){
    int randomDir = (Pnj[i].yPosition+Pnj[i].xPosition+player.xSpeed+player.ySpeed+player.currentPosition)%3;
    /*srand(gb.pickRandomSeed());*/
    gb.pickRandomSeed();
    randomDir = rand()%3;
    switch(Pnj[i].type){
      case 5: //beginner skier
        if(randomDir==0){
          Pnj[i].xPosition = Pnj[i].xPosition-2;
          Pnj[i].yPosition = Pnj[i].yPosition+1;
        }        
        if(randomDir==1){
          Pnj[i].yPosition = Pnj[i].yPosition+1;
        }
        if(randomDir==2){
          Pnj[i].xPosition = Pnj[i].xPosition+2;
          Pnj[i].yPosition = Pnj[i].yPosition+1;
        }
        //check collisions
        break;

      case 6: //mad surfer
        if(randomDir==0){
          Pnj[i].xPosition = Pnj[i].xPosition-2;
          Pnj[i].yPosition = Pnj[i].yPosition+3;
          Pnj[i].check=0;
        }        
        if(randomDir==1){
          Pnj[i].yPosition = Pnj[i].yPosition+3;
        }
        if(randomDir==2){
          Pnj[i].xPosition = Pnj[i].xPosition+2;
          Pnj[i].yPosition = Pnj[i].yPosition+3;
          Pnj[i].check=1;
        }
        //check collisions
        break;

      case 7: //dog
        //always going left or right
        if(Pnj[i].check==0){
          Pnj[i].xPosition = Pnj[i].xPosition-1;
        }else{
          Pnj[i].xPosition = Pnj[i].xPosition+1;
        }
        break;

      case 8: //monster
        //follow player
        //check collisions
        break;
    }
  }
}

void game_playerAnimReset(){
  player.anim=0;
}

void game_playerAnimNext(){
  player.anim=player.anim+1;
  if(player.anim>3){player.anim=0;}
}

bool checkCollide(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2){
  return (x2<x1+w1 && x2+w2>x1 && y2<y1+h1 && y2+h2>y1);
}
