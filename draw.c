#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {

  if (x0>x1) {
    draw_line(x1, y1, x0, y0, s, c);
    return;
  }

  int x = x0;
  int y = y0;
  int dy = y1 - y0;
  int dx = x1 - x0;

  if(y1>y0){
    int counter = 2*dy - dx;
    if (dy>dx) {
      for (y=y0; y<=y1; y++) {
        plot(s,c,x,y);
        if (counter<0) {
          x++;
          counter += dy;
        }
        counter -= dx;
      } 
    }
    else{
      for(x=x0; x<=x1; x++){
        plot(s,c,x,y);
        if(counter>0){
          y++;
          counter -= dx;
        }
        counter += dy;
      }
    }
  }
  else{
    int counter = 2*dy + dx;
    if(-1*dy>dx){
      for(y=y0; y>=y1; y--){
        plot(s,c,x,y);
        if(counter>0){
          x++;
          counter += dy;
        }
        counter += dx;
      } 
    }
    else{
      for(x=x0; x<=x1; x++){
        plot(s,c,x,y);
        if(counter>0){
          y--;
          counter -= dx;
        }
        counter -= dy;
      }
    }
  }

}
