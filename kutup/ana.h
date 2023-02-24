#ifndef KUTUP_ANA_H__
#define KUTUP_ANA_H__
 
#include <raylib.h>

#define EKRAN_GENISLIGI 800
#define EKRAN_YUKSEKLIGI 600
#define FARUKGRISI (Color){ 34, 34, 34, 255 }
#define PENCERE_BASLIK_ISMI "OyunY"
#define FPS_SINIRI 60

void oyun_yukle();
void oyun_guncelle(float dt);
void oyun_ciz();

#endif // KUTUP_ANA_H__