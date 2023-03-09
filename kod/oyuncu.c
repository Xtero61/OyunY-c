#include "oyuncu.h"
#include "animasyon.h"

#include <raylib.h>
#include <stdio.h>

AnimasyonVeri v = {0};
Animasyon a[OYUNCU_DURUM_SAYISI] = {0};

void oyuncu_ayarla(OyuncuTip* oyuncu)
{
    oyuncu->olcek = 2.0f;
    v = animasyon_veri_uret("cizimler/ast.png", oyuncu->olcek, (Vector2){8, 2});
    a[OYUNCU_DURUM_DURMA] = animasyon_uret(&v, (Vector2){0, 8}, 0.8);
    a[OYUNCU_DURUM_KOSMA] = animasyon_uret(&v, (Vector2){8, 16}, 0.8);
    oyuncu->boyut.x = v.kare_boyut.x * oyuncu->olcek;
    oyuncu->boyut.y = v.kare_boyut.y * oyuncu->olcek;
    oyuncu->renk.r = 255;
    oyuncu->renk.a = 255;
    oyuncu->konum.x = 500;
    oyuncu->konum.y = 500;
    oyuncu->hiz = 100;
    oyuncu->durum = OYUNCU_DURUM_DURMA;
}

void oyuncu_ciz(OyuncuTip* o)
{
    DrawRectangleV(o->konum, o->boyut, o->renk);
    animasyon_ciz(&a[o->durum], o->konum);
}

void oyuncu_guncelle(OyuncuTip* o, float dt)
{
    o->hareket_yonu.y = IsKeyDown(KEY_S) - IsKeyDown(KEY_W);    
    o->hareket_yonu.x = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);    
    
    o->konum.x += o->hareket_yonu.x * o->hiz * dt;
    o->konum.y += o->hareket_yonu.y * o->hiz * dt;

    if(o->hareket_yonu.x == 0 && o->hareket_yonu.y == 0)
    {
        o->durum = OYUNCU_DURUM_DURMA;
    }
    else
    {
        o->durum = OYUNCU_DURUM_KOSMA;
    }
    
    if(o->hareket_yonu.x < 0)
    {
        a[o->durum].veri->dondur = true;
    }
    else if (o->hareket_yonu.x > 0)
    {
        a[o->durum].veri->dondur = false;
    }

    animasyon_guncelle(&a[o->durum], dt);
}