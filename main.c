#include <raylib.h>
#include "kutup/ana.h"

int main()
{
	InitWindow(EKRAN_GENISLIGI, EKRAN_YUKSEKLIGI, PENCERE_BASLIK_ISMI);
	oyun_yukle();
	while(!WindowShouldClose())
	{
		float dt = GetFrameTime();
		oyun_guncelle(dt);

		BeginDrawing();
    	oyun_ciz();
    	EndDrawing();
  	}
 	
	return 0;
}
