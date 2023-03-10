#include "araclar.h"
#include "animasyon.h"

AnimasyonVeri animasyon_veri_uret(char const* resim, float olcek, Vector2 kare_sayisi)
{
    AnimasyonVeri s;
    s.kare_sayisi = kare_sayisi;    
    s.olcek = olcek;
    s.resim = LoadTexture(resim);

    s.kare_boyut.x = s.resim.width / kare_sayisi.x;
    s.kare_boyut.y = s.resim.height / kare_sayisi.y;

    s.degisimde_sifirla = true;

    return s;
}

Animasyon animasyon_uret(AnimasyonVeri* veri, Vector2 baslangic_bitis_kare, float sure)
{
    Animasyon s = {0};
    s.veri = veri;
    s.kare_aralik = baslangic_bitis_kare;
    s.sure_katsayisi = sure / (baslangic_bitis_kare.y - baslangic_bitis_kare.x);
    s.toplam_kare_sayisi = baslangic_bitis_kare.y - baslangic_bitis_kare.x;

    return s;
}

void animasyon_guncelle(Animasyon* anim, float dt)
{
    if(anim->veri->degisimde_sifirla && 
        !(vektorler_ayni_mi(&anim->veri->son_animasyon_aralik, &anim->kare_aralik, 0)))
    {
        anim->sayac = 0;
        anim->veri->son_animasyon_aralik = anim->kare_aralik;
    }

    // Animasyon kare guncelle
    anim->sayac += dt / anim->sure_katsayisi;
    if(anim->sayac >= anim->toplam_kare_sayisi)
    {
        anim->sayac = 0;
    }

    // hangi karedeyiz
    int kare_sira = anim->kare_aralik.x + (int)anim->sayac;

    // karenin x, y koordinatlarini bul
    int x = kare_sira % ((int)anim->veri->kare_sayisi.x);
    int y = kare_sira / anim->veri->kare_sayisi.x;

    anim->secili_kare = (Rectangle){x * anim->veri->kare_boyut.x, 
                                    y * anim->veri->kare_boyut.y, 
                                    anim->veri->kare_boyut.x, 
                                    anim->veri->kare_boyut.y};
}

void animasyon_ciz(Animasyon* anim, Vector2 konum)
{
    if(anim->veri->dondur)
    {
        anim->secili_kare.width = anim->veri->kare_boyut.x * -1;
    }
    else
    {
        anim->secili_kare.width = anim->veri->kare_boyut.x;
    }

    DrawTexturePro(anim->veri->resim,
                   anim->secili_kare,
                   (Rectangle){konum.x, konum.y, 
                               anim->veri->kare_boyut.x * anim->veri->olcek, 
                               anim->veri->kare_boyut.y * anim->veri->olcek
                               },
                   (Vector2){0, 0},
                   0,
                   WHITE);
}