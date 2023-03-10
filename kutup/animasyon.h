#ifndef ANIMASYON_H_
#define ANIMASYON_H_

#include <raylib.h>

typedef struct
{
    float olcek; // resmin olcegi
    Vector2 kare_boyut; // bir karenin boyutlari
    Vector2 kare_sayisi; // resimde yatay ve dikeyde bulunan kare sayilari
    Vector2 son_animasyon_aralik; // secili son animasyon resimde hangi kare araliginda olduguyla ayrilir
    Texture2D resim; // resim nesnesi
    bool dondur; // resim terse doner
    bool degisimde_sifirla; // bir animasyondan digerine gecince animasyon sifirlanir
} AnimasyonVeri;

typedef struct
{
    AnimasyonVeri* veri;
    Vector2 kare_aralik;
    Rectangle secili_kare;
    float sure_katsayisi;
    int toplam_kare_sayisi;
    float sayac;
} Animasyon;

void animasyon_guncelle(Animasyon* anim, float dt);
void animasyon_ciz(Animasyon* anim, Vector2 konum);
Animasyon animasyon_uret(AnimasyonVeri* veri, Vector2 baslangic_bitis_kare, float sure);
AnimasyonVeri animasyon_veri_uret(char const* resim, float olcek, Vector2 kare_sayisi);

#endif // ANIMASYON_H_
