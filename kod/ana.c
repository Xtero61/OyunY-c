#include <raylib.h>
#include <stdio.h>

#include "../kutup/ana.h"

char yazi_kutusu[120] = {0};

void oyun_yukle()
{
    
}

void oyun_guncelle(float dt)
{
    DrawFPS(5,5);
    sprintf(yazi_kutusu, "Ekran Yuksekligi: %d", EKRAN_YUKSEKLIGI);
}

void oyun_ciz()
{ 
    DrawText("Naber Dayi ben Ayi", 190, 200, 20, WHITE);
    DrawText(yazi_kutusu, 190, 300, 20, WHITE);
}
