#include "SDGF.h"

int main(void)
{
 long int x,y,screen_width,screen_height;
 unsigned long int fps;
 unsigned char frame;
 char perfomance[8];
 SDGF_Screen screen;
 SDGF_Gamepad gamepad;
 SDGF_Timer timer;
 SDGF_Image image;
 SDGF_Background space;
 SDGF_Sprite ship,font;
 SDGF_Text text;
 screen_width=screen.get_width();
 screen_height=screen.get_height();
 x=screen_width/2;
 y=screen_height/2;
 image.load_tga("space.tga");
 space.load_image(image);
 image.load_tga("ship.tga");
 ship.load_image(image);
 image.load_tga("font.tga");
 font.load_image(image);
 text.load_font(font.get_handle());
 gamepad.initialize();
 space.initialize(screen.get_handle());
 ship.initialize(screen.get_handle());
 font.initialize(screen.get_handle());
 space.resize_image(screen_width,screen_height);
 screen.clear_screen();
 frame=1;
 ship.set_frames(2);
 text.set_position(font.get_sprite_width(),font.get_sprite_height());
 timer.set_timer(1);
 fps=0;
 memset(perfomance,0,8);
 while(1)
 {
  screen.refresh();
  fps++;
  gamepad.update();
  if(gamepad.get_press()==SDGF_KEY_X) break;
  if(gamepad.get_press()==SDGF_KEY_A) ship.mirror_image(0);
  if(gamepad.get_press()==SDGF_KEY_B) ship.mirror_image(1);
  if(gamepad.get_hold()==SDGF_KEY_UP) y-=4;
  if(gamepad.get_hold()==SDGF_KEY_DOWN) y+=4;
  if(gamepad.get_hold()==SDGF_KEY_LEFT) x-=4;
  if(gamepad.get_hold()==SDGF_KEY_RIGHT) x+=4;
  if((x<=0)||(x>=screen_width)) x=screen_width/2;
  if((y<=0)||(y>=screen_height)) y=screen_height/2;
  space.draw_background();
  text.draw_text(perfomance);
  ship.draw_sprite_frame(x,y,frame);
  if (timer.check_timer()==true)
  {
   sprintf(perfomance,"%ld",fps);
   fps=0;
   frame++;
   if (frame>2) frame=1;
  }

 }
 return 0;
}