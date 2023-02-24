#include <raylib.h>
#include "ana.h"

int main()
{
	InitWindow(EKRAN_GENISLIGI, EKRAN_YUKSEKLIGI, PENCERE_BASLIK_ISMI);
	SetTargetFPS(FPS_SINIRI);
	oyun_yukle();
	while(!WindowShouldClose())
	{
		float dt = GetFrameTime();
		oyun_guncelle(dt);

		BeginDrawing();
		ClearBackground(FARUKGRISI);
    	oyun_ciz();
    	EndDrawing();
  	}
 	
	return 0;
}
