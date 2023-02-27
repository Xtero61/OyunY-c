#include "oyuncu.h"

void oyuncu_ayarla(OyuncuTip* oyuncu)
{
    oyuncu->boyut.x = 32;
    oyuncu->boyut.y = 64;
    oyuncu->renk.r = 255;
    oyuncu->renk.a = 255;
    oyuncu->konum.x = 500;
    oyuncu->konum.y = 500;
    oyuncu->hiz = 100;
}

void oyuncu_ciz(OyuncuTip* o)
{
    DrawRectangleV(o->konum, o->boyut, o->renk);
}

void oyuncu_guncelle(OyuncuTip* o, float dt)
{
    o->hareket_yonu.y = IsKeyDown(KEY_S) - IsKeyDown(KEY_W);    
    o->hareket_yonu.x = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);    

    o->konum.x += o->hareket_yonu.x * o->hiz * dt;
    o->konum.y += o->hareket_yonu.y * o->hiz * dt;
}