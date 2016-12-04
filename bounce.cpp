// Andrea Augustin
// Andrea Augustin
// bounce.cpp

#include <iostream>
#include "gfx.h"
#include <unistd.h>
#include <cstdlib>
#include <cmath>
using namespace std;


int main() {
  int win_wd = 600, win_ht = 500;  // window width and height
  int rad = 20;                    // ball radius
  float vx =rand()% 35 + 1, vy = rand()% 35 + 1;            // velocity vector
  float dt = 3;                    // mult. factor (here, same for both x&y; needn't be)
  char c = ' ';

  gfx_open (win_wd, win_ht, "Moving Ball");
  gfx_wait();
  float xc = gfx_xpos();
  float yc = gfx_ypos();
  
  while(c != 'q') {
    gfx_clear();
    gfx_color(255,255,255);

    gfx_circle(xc, yc, rad);
    gfx_flush();
    xc = xc + vx*dt;
    yc = yc + vy*dt;

    if(xc >= win_wd-rad){       // right wall
       vx = -vx;
       xc = win_wd-rad-1;
    }
    else if(xc <= rad){         // left wall
       vx = -vx;
       xc = rad + 1;
    }
    else if(yc >= win_ht-rad){  // bottom wall
       vy = -vy;
       yc = win_ht -rad-1;
    }
    else if(yc <= rad){         // top wall
       vy = -vy;
       yc = rad + 1;
    }
    gfx_flush();
    usleep(10000);
    if(gfx_event_waiting()){
       c = gfx_wait();
       if(c == 1) {
	 xc = gfx_xpos();
	 yc = gfx_ypos();
       }
    }
  }

  return 0;
}
