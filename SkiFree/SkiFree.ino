#include <Gamebuino-Meta.h>
#define GAMEMAKERS 0
#define TITLESCREEN 1
#define MENU 2
#define GAME 3
#define COLLIDE 4
#define JUMP 5

#define CONTROLS 97
#define CREDITS 98
#define MENUPAUSE 99

#define SCREENHEIGHT 64
#define SCREENWIDTH 80

#define MIDDLESCREEN 40

#define NbOfItem 67
#define NbOfKindOfItem 8
#define NbOfPnj 14

#define PLAYER_Y_POS 5

//###########################
//##### INFO Global #########
//###########################
typedef struct{
  int gameStatus; 
  int globalTimer;
  int pause; //keep in memory what was the gameStatus before pause
  int menuOption;
  int menuPauseOption;
}GameInfo;
GameInfo game;

typedef struct{
  int xPosition;        //in the world
  int yPosition;        //in the world
  int currentPosition;  //0.Left / 1.LeftBottom / 2.Bottom / 3.RightBottom / 4.Right / 5.Up
  int xSpeed;
  int ySpeed;
  int speedTimer;  
  int anim;
}PlayerInfo;
PlayerInfo player;

typedef struct{
  int maxAlt;
  int currentAlt;
  bool isGoingUp;
  int stuntCounter;
  int combo;
}JumpInfo;
JumpInfo jump;

int score = 0;

typedef struct{
  int type;      //TreeA //TreeB 
  int xPosition; //in the world
  int yPosition; //frame counter
  bool check;    //Score check //PNJ direction //Dog direction
}ItemInfo;
ItemInfo Map[NbOfItem];
ItemInfo Pnj[NbOfPnj];

typedef struct{
  int type;      //TreeA //TreeB
  int xHitBox;
  int yHitBox;
  int widthHitBox;
  int heightHitBox;
  int collisionEffect; //collision //jump //addpoints //...
}ItemDetail;
ItemDetail Item[NbOfKindOfItem];

typedef struct {
  int8_t weapon;
  int8_t bonus;
  int8_t playerDamage;
  int8_t music;
}SoundInfo;
SoundInfo sounds;


//###########################
//##### Game Setup ##########
//###########################
void setup(){
  gb.begin();
  game_init();
  game_initPlayer();
  game_initJump();
  game_initItems();
  game_initItemTypes();
  loop();
}


//###########################
//##### Game Loop ###########
//###########################
void loop(){
  while(1){
    if(gb.update()){
      game_manageGlobalCounter();
      
      switch ( game.gameStatus )
      {
         //####################################
         case GAMEMAKERS:
            outputScreen_gamemakers();
            button_check(GAMEMAKERS);
            break;

         //#################################### 
         case TITLESCREEN:
            outputScreen_clear();
            outputScreen_title();
            button_check(TITLESCREEN);
            break;


         //#################################### 
         case CONTROLS:
            outputScreen_clear();
            outputScreen_controls();
            button_check(CONTROLS);
            break;

         //#################################### 
         case CREDITS:
            outputScreen_clear();
            outputScreen_credits();
            button_check(CREDITS);
            break;

         //####################################  
         case MENU:
            outputScreen_clear();
            outputScreen_menu();
            button_check(MENU);
            break;
            
         //####################################  
         case GAME:
            outputScreen_clear();
            outputScreen_game();
            button_check(GAME);
            game_checkHitBox();
            game_movePnj();
            game_moveBackground();
            break;
            
         //####################################  
         case COLLIDE:
            outputScreen_clear();
            outputScreen_collide();
            game_checkHitBoxCollide();
            button_check(COLLIDE);
            game_movePnj();
            game_moveBackground();
            //debug();
            //debug_hitbox();
            break;    

         //####################################  
         case JUMP:
            outputScreen_clear();
            outputScreen_jump();
            game_checkHitBoxJump();
            button_check(JUMP);
            game_moveAltitude();
            game_movePnj();
            game_moveBackground();
            break;
                    
         //####################################  
         case MENUPAUSE:
            outputScreen_clear();
            outputScreen_menu();
            button_check(MENUPAUSE);
            break;

         //####################################                     
         default:
            game.gameStatus = GAMEMAKERS;
            break;
      }
    }  
  }
}
