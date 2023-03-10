#include "araclar.h"

bool yeterince_esit_mi(float v1, float v2, float hassasiyet)
{
    return v1 < (v2 + hassasiyet) && v1 > (v2 - hassasiyet);
}

bool vektorler_ayni_mi(Vector2* v1, Vector2* v2, float hassasiyet)
{
    if(hassasiyet == 0.0f)
    {
        return (int)v1->x == (int)v2->x && (int)v1->y == (int)v2->y;
    }
    
    return yeterince_esit_mi(v1->x, v2->x, hassasiyet) && yeterince_esit_mi(v1->y, v2->y, hassasiyet);
}