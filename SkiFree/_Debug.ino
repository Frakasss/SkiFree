void debug(){
  gb.display.setColor(BLACK);
  gb.display.setCursor(0,0);
  gb.display.println(player.xSpeed);
  gb.display.println(player.ySpeed);
}

void debug_hitbox(){

  //player
  gb.display.setColor(LIGHTGREEN);
  gb.display.fillRect(MIDDLESCREEN-6+6,1+8,3,5);
  
  
  for(int i=0; i<NbOfItem; i++){
    for(int j=0; j<NbOfKindOfItem; j++){
      if(Item[j].type==Map[i].type){
        if(Item[j].collisionEffect==0){gb.display.setColor(RED);} //Fall
        if(Item[j].collisionEffect==1){gb.display.setColor(BLUE);} //Jump
        if(Item[j].collisionEffect==2){gb.display.setColor(ORANGE);} //Score

        gb.display.fillRect(Map[i].xPosition+Item[j].xHitBox, Map[i].yPosition+Item[j].yHitBox,Item[j].widthHitBox,Item[j].heightHitBox);
      }
    }
  }

}
