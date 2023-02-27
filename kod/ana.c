#include <raylib.h>
#include <stdio.h>
#include <string.h>

#include "ana.h"
#include "oyuncu.h"

OyuncuTip oyuncu = {0};

void oyun_yukle()
{
    oyuncu_ayarla(&oyuncu);
}

void oyun_guncelle(float dt)
{
    DrawFPS(5,5);
    oyuncu_guncelle(&oyuncu, dt);
}

void oyun_ciz()
{
    oyuncu_ciz(&oyuncu);
}
