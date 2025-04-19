#include <graphics.h>
#include <conio.h>
#include <stdlib.h>  // for abs()

void bresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int p = 2 * dy - dx;
    int x = x1, y = y1;

    int incx = (x2 > x1) ? 1 : -1;
    int incy = (y2 > y1) ? 1 : -1;

    // Determine if the slope is steep
    if (dx > dy) {
        while (x != x2) {
            putpixel(x, y, WHITE);
            x += incx;
            if (p < 0) {
                p += 2 * dy;
            } else {
                y += incy;
                p += 2 * (dy - dx);
            }
        }
    } else {
        // For steep slopes (dy > dx), we iterate over y
        p = 2 * dx - dy;
        while (y != y2) {
            putpixel(x, y, WHITE);
            y += incy;
            if (p < 0) {
                p += 2 * dx;
            } else {
                x += incx;
                p += 2 * (dx - dy);
            }
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI"); // make sure this path is correct
    bresenham(100, 100, 300, 200);
    getch();
    closegraph();
    return 0;
}
