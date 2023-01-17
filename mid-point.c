#include <stdio.h>
#include <graphics.h>
int main()
{
    int gdriver = DETECT, gmode;
    float x, y, xc, yc, rx, ry, pk, pk1;
    printf("Mid point circle drawing Algorithm\n");
    printf("Enter center for circle : \n x : ");
    scanf("%f", &xc);
    printf(" y : ");
    scanf("%f", &yc);
    printf("Enter X-radius and y-radius:\n x-radius :");
    scanf("%f", &rx);
    printf(" y-radius : ");
    scanf("%f", &ry);
    initgraph(&gdriver, &gmode, " ");
    x = 0;
    y = ry;
    pk = (ry * ry) - (rx * rx * ry) + ((rx * rx) / 4);
    while ((2 * x * ry * ry) < (2 * y * rx * rx))
    {
        if (pk <= 0)
        {
            x = x + 1;
            pk1 = pk + (2 * ry * ry * x) + (ry * ry);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            pk1 = pk + (2 * ry * ry * x) - (2 * rx * rx * y) + (ry * ry);
        }
        pk = pk1;
        putpixel(xc + x, yc + y, 2);
        putpixel(xc - x, yc + y, 2);
        putpixel(xc + x, yc - y, 2);
        putpixel(xc - x, yc - y, 2);
    }

    pk = ((x + 0.5) * (x + 0.5) * ry * ry) + ((y - 1) * (y - 1) * rx * rx) - (rx * rx * ry * ry);
    while (y > 0)
    {
        if (pk > 0)
        {
            y = y - 1;
            pk1 = pk - (2 * rx * rx * y) + (rx * rx);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            pk1 = pk + (2 * ry * ry * x) - (2 * rx * rx * y) + (rx * rx);
        }
        pk = pk1;
        putpixel(xc + x, yc + y, 2);
        putpixel(xc - x, yc + y, 2);
        putpixel(xc + x, yc - y, 2);
        putpixel(xc - x, yc - y, 2);
    }

    line(xc + rx, yc, xc - rx, yc);
    line(xc, yc + ry, xc, yc - ry);
    outtextxy(xc + (1.2 * rx), yc - (1.2 * ry), "(x,-y)");
    outtextxy(xc - (1.2 * rx), yc + (1.2 * ry), "(-x,y)");
    outtextxy(xc + (1.2 * rx), yc + (1.2 * ry), "(x,y)");
    outtextxy(xc - (1.2 * rx), yc - (1.2 * ry), "(-x,-y)");
    // getch();
    delay(10000);
}