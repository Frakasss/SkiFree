void button_check(int typeCheck){
  switch(typeCheck){
     //####################################
     //########### Skip Logo ##############
     //####################################
     case GAMEMAKERS:
      if(gb.buttons.pressed(BUTTON_A)){
        game.globalTimer = 0;
        game.gameStatus=TITLESCREEN;
      }
     break;    
    
     //####################################
     //########### Skip title #############
     //####################################
     case TITLESCREEN:      
      if(gb.buttons.pressed(BUTTON_A)){
        game.globalTimer = 0;
        game.gameStatus=MENU;
      }
     break;   

     //####################################
     //########### Controls P1 ############
     //####################################
     case CONTROLS:      
      if(gb.buttons.pressed(BUTTON_A)){
        game.gameStatus=MENU;
      }
     break; 

     //####################################
     //########### Credits ################
     //####################################
     case CREDITS:      
      if(gb.buttons.pressed(BUTTON_A)){
        game.gameStatus=MENU;
      }
     break;
     
     //#######################################
     //############# Menu ####################
     //#######################################
     case MENU:      
      if(gb.buttons.pressed(BUTTON_A)){
        switch(game.menuOption){
          case 0:
          break;

          case 1:
            game.gameStatus=GAME;
          break;

          case 2:
            game.gameStatus=CONTROLS;
          break;

          case 3:
            game.gameStatus=CREDITS;
          break;
        }
      }

      if(gb.buttons.pressed(BUTTON_UP)){    
        game.menuOption = game.menuOption - 1;
        if(game.menuOption<=0){game.menuOption=3;}
      }

      if(gb.buttons.pressed(BUTTON_DOWN)){    
        game.menuOption = game.menuOption + 1;
        if(game.menuOption>=4){game.menuOption=1;}
      }


      
     //#################################
     //########### Game ################
     //#################################
     //Normal ==> 0.Left / 1.LeftBottom / 2.Bottom / 3.RightBottom / 4.Right
     //Shuss  ==> 5.Left / 6.LeftBottom / 7.Bottom / 8.RightBottom / 9.Right
     //Up     ==> 10. Left / 11. Right
     case GAME:
      if(gb.buttons.repeat(BUTTON_UP,3) || gb.buttons.pressed(BUTTON_UP)){
        if(player.currentPosition>=2 && player.currentPosition<4){player.currentPosition=player.currentPosition+1;}
        if(player.currentPosition<2 && player.currentPosition>0){player.currentPosition=player.currentPosition-1;}
        if(player.currentPosition==0 || player.currentPosition==10){player.currentPosition=10;game_playerAnimNext();}
        if(player.currentPosition==4 || player.currentPosition==11){player.currentPosition=11;game_playerAnimNext();}
      }else{    
        if(gb.buttons.repeat(BUTTON_B,0)){
          if(player.currentPosition==0){player.currentPosition=5;}
          if(player.currentPosition==1){player.currentPosition=6;}
          if(player.currentPosition==2){player.currentPosition=7;}
          if(player.currentPosition==3){player.currentPosition=8;}
          if(player.currentPosition==4){player.currentPosition=9;}
        }else{
          if(player.currentPosition==5){player.currentPosition=0;}
          if(player.currentPosition==6){player.currentPosition=1;}
          if(player.currentPosition==7){player.currentPosition=2;}
          if(player.currentPosition==8){player.currentPosition=3;}
          if(player.currentPosition==9){player.currentPosition=4;}
          if(gb.buttons.repeat(BUTTON_LEFT,6) || gb.buttons.pressed(BUTTON_LEFT)){
            player.currentPosition = player.currentPosition-1;
            if(player.currentPosition<0){
              player.currentPosition=0;
              game_playerAnimNext();
            }
          }else{
            if(gb.buttons.repeat(BUTTON_RIGHT,6) || gb.buttons.pressed(BUTTON_RIGHT)){
              player.currentPosition = player.currentPosition+1;
              if(player.currentPosition>4){
                player.currentPosition=4;
                game_playerAnimNext();
              }         
            }else{
              if(gb.buttons.repeat(BUTTON_DOWN,10) || gb.buttons.pressed(BUTTON_DOWN)){
                if(player.currentPosition>2){player.currentPosition=player.currentPosition-1;}
                if(player.currentPosition<2){player.currentPosition=player.currentPosition+1;}
              }
            }
          }        
        }
      }
      
      if(gb.buttons.released(BUTTON_UP) || gb.buttons.released(BUTTON_LEFT) || gb.buttons.released(BUTTON_RIGHT)){
        if(player.currentPosition==10){player.currentPosition=0;}
        if(player.currentPosition==11){player.currentPosition=4;}
        game_playerAnimReset();
      }

      
       switch(player.currentPosition){
        case 0: 
          player.xSpeed=player.xSpeed+1;
          if(player.xSpeed>0){player.xSpeed=0;}
          if(gb.buttons.repeat(BUTTON_LEFT,0)){player.xSpeed=-2;} 
          player.ySpeed=0; 
          break;
        
        case 1: player.xSpeed=-2; player.ySpeed=2; break;
        case 2: player.xSpeed=0;  player.ySpeed=3; break;
        case 3: player.xSpeed=2;  player.ySpeed=2; break;
        
        case 4: 
          player.xSpeed=player.xSpeed-1;
          if(player.xSpeed<0){player.xSpeed=0;}
          if(gb.buttons.repeat(BUTTON_RIGHT,0)){player.xSpeed=2;}  
          player.ySpeed=0; 
          break;

        case 5: 
          player.xSpeed=player.xSpeed+1;
          if(player.xSpeed>0){player.xSpeed=0;}
          if(gb.buttons.repeat(BUTTON_LEFT,0)){player.xSpeed=-3;} 
          player.ySpeed=0; 
          break;
        
        case 6: player.xSpeed=-3; player.ySpeed=3; break;
        case 7: player.xSpeed=0;  player.ySpeed=5; break;
        case 8: player.xSpeed=3;  player.ySpeed=3; break;
        
        case 9: 
          player.xSpeed=player.xSpeed-1;
          if(player.xSpeed<0){player.xSpeed=0;}
          if(gb.buttons.repeat(BUTTON_RIGHT,0)){player.xSpeed=3;}  
          player.ySpeed=0; 
          break;  

        case 10: player.xSpeed=0;  player.ySpeed=-1; break;
        case 11: player.xSpeed=0;  player.ySpeed=-1; break;        
      }     

      
     break;

     //##################################
     case COLLIDE:
        if(player.xSpeed==0 && player.ySpeed==0 && gb.buttons.pressed(BUTTON_A)){
          player.currentPosition=4;
          game.gameStatus = GAME;
        }
     break;

     //##################################
     case JUMP:
      if(gb.buttons.pressed(BUTTON_A)){
        jump.stuntCounter = jump.stuntCounter+1;
        if(jump.stuntCounter==4){
          jump.stuntCounter=0;
          jump.combo= jump.combo+1;
        }
      }
     break;

     //##################################
     case MENUPAUSE:
      if(gb.buttons.pressed(BUTTON_A)){
        if(game.menuPauseOption==0){
          game.gameStatus = game.pause;
        }else{
          game.globalTimer=0;
          game_init();
          gb.pickRandomSeed();
          game.gameStatus = TITLESCREEN;
        }
      }else{
        if(gb.buttons.pressed(BUTTON_UP)){    
          game.menuPauseOption = game.menuPauseOption - 1;
          if(game.menuPauseOption<0){game.menuPauseOption=1;}
        }
  
        if(gb.buttons.pressed(BUTTON_DOWN)){    
          game.menuPauseOption = game.menuPauseOption + 1;
          if(game.menuPauseOption>1){game.menuPauseOption=0;}
        } 
      }
     break; 
  }
}
