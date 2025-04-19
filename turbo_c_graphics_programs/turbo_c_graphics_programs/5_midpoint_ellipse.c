#include <graphics.h>
#include <conio.h>
#include <math.h>

void drawEllipse(int xc, int yc, int rx, int ry) {
    int x = 0, y = ry;
    float p1 = ry * ry - rx * rx * ry + 0.25 * rx * rx;
    int dx = 2 * ry * ry * x;
    int dy = 2 * rx * rx * y;

    while (dx < dy) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        if (p1 < 0) {
            x++;
            dx += 2 * ry * ry;
            p1 += dx + ry * ry;
        } else {
            x++;
            y--;
            dx += 2 * ry * ry;
            dy -= 2 * rx * rx;
            p1 += dx - dy + ry * ry;
        }
    }

    float p2 = ry * ry * (x + 0.5f) * (x + 0.5f) + rx * rx * (y - 1) * (y - 1) - rx * rx * ry * ry;
    while (y >= 0) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        if (p2 > 0) {
            y--;
            dy -= 2 * rx * rx;
            p2 += rx * rx - dy;
        } else {
            y--;
            x++;
            dx += 2 * ry * ry;
            dy -= 2 * rx * rx;
            p2 += dx - dy + rx * rx;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    drawEllipse(250, 250, 100, 50);
    getch();
    closegraph();
    return 0;
}
