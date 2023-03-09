#ifndef OYUNCU_H_
#define OYUNCU_H_

#include <raylib.h>

typedef enum
{
    OYUNCU_DURUM_DURMA,
    OYUNCU_DURUM_KOSMA,
    OYUNCU_DURUM_SAYISI,
} OyuncuDurum;

typedef struct
{
    OyuncuDurum durum;
    Vector2 konum;
    Vector2 boyut;
    Vector2 hareket_yonu;
    float hiz;
    Color renk;
    float olcek;
} OyuncuTip;

void oyuncu_ayarla(OyuncuTip* oyuncu);
void oyuncu_ciz(OyuncuTip* o);
void oyuncu_guncelle(OyuncuTip* o, float dt);

#endif // OYUNCU_H_