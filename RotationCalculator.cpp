// RotationCalculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "EulerAngles.h"

#define TAU (2*M_PI)

int _tmain(int argc, _TCHAR* argv[])
{
	while (1)
	{
		EulerAngles inAngs = {0,0,0,EulOrdXYZs};
		printf("X  Y  Z (degrees): ");
		float xx,yy,zz;
		scanf("%f %f %f",&xx, &yy, &zz); 
		float d2r = (float)((2 * M_PI) /360);
		inAngs.x = xx * d2r;
		inAngs.y = yy * d2r;
		inAngs.z = zz * d2r;

		Quat qconv;
		qconv = Eul_ToQuat(inAngs);
		printf("%6.3f %6.3f %6.3f %6.3f\n\n", qconv.x, qconv.y, qconv.z, qconv.w );

		printf("X Y Z W : ");
		scanf("%f %f %f %f",&qconv.x, &qconv.y, &qconv.z, &qconv.w );

		inAngs = Eul_FromQuat(qconv, EulOrdXYZs);
		float r2d = (float)(360.0 / (2 * M_PI));

        // x
        printf ("\n");
        printf("x = %6.3f", inAngs.x * r2d);

        if ( (inAngs.x + TAU) < (TAU-0.01) )
            printf(", %6.3f", (inAngs.x + TAU) * r2d );

        if ( (inAngs.x - TAU) >  (-TAU+0.01) )
            printf(", %6.3f", (inAngs.x - TAU) * r2d );

        // y
        printf ("\n");
        printf("y = %6.3f", inAngs.y * r2d);

        if ( (inAngs.y + TAU) < (TAU-0.01) )
            printf(", %6.3f", (inAngs.y + TAU) * r2d );

        if ( (inAngs.y - TAU) >  (-TAU+0.01) )
            printf(", %6.3f", (inAngs.y - TAU) * r2d );

        // z
        printf ("\n");
        printf("z = %6.3f", inAngs.z * r2d);

        if ( (inAngs.z + TAU) < (TAU-0.01) )
            printf(", %6.3f", (inAngs.z + TAU) * r2d );

        if ( (inAngs.z - TAU) >  (-TAU+0.01) )
            printf(", %6.3f", (inAngs.z - TAU) * r2d );

        printf ("\n");
        
        inAngs.x = fmod(M_PI + inAngs.x, TAU);
        inAngs.y = fmod(M_PI - inAngs.y, TAU);
        inAngs.z = fmod(M_PI + inAngs.z, TAU);

        // x
        printf ("\n");
        printf("x = %6.3f", inAngs.x * r2d);

        if ( (inAngs.x + TAU) < (TAU-0.01) )
            printf(", %6.3f", (inAngs.x + TAU) * r2d );

        if ( (inAngs.x - TAU) >  (-TAU+0.01) )
            printf(", %6.3f", (inAngs.x - TAU) * r2d );

        // y
        printf ("\n");
        printf("y = %6.3f", inAngs.y * r2d);

        if ( (inAngs.y + TAU) < (TAU-0.01) )
            printf(", %6.3f", (inAngs.y + TAU) * r2d );

        if ( (inAngs.y - TAU) >  (-TAU+0.01) )
            printf(", %6.3f", (inAngs.y - TAU) * r2d );

        // z
        printf ("\n");
        printf("z = %6.3f", inAngs.z * r2d);

        if ( (inAngs.z + TAU) < (TAU-0.01) )
            printf(", %6.3f", (inAngs.z + TAU) * r2d );

        if ( (inAngs.z - TAU) >  (-TAU+0.01) )
            printf(", %6.3f", (inAngs.z - TAU) * r2d );



        printf ("\n\n");
	}

	return 0;
}

