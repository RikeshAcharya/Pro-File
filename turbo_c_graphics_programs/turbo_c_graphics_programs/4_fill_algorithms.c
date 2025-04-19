#include <graphics.h>
#include <conio.h>

void boundaryFill(int x, int y, int fill_color, int boundary_color) {
    int current;
    current = getpixel(x, y);
    if (current != boundary_color && current != fill_color) {
        putpixel(x, y, fill_color);
        boundaryFill(x + 1, y, fill_color, boundary_color);
        boundaryFill(x - 1, y, fill_color, boundary_color);
        boundaryFill(x, y + 1, fill_color, boundary_color);
        boundaryFill(x, y - 1, fill_color, boundary_color);
    }
}

void floodFill(int x, int y, int old_color, int new_color) {
    int current;
    current = getpixel(x, y);
    if (current == old_color) {
        putpixel(x, y, new_color);
        floodFill(x + 1, y, old_color, new_color);
        floodFill(x - 1, y, old_color, new_color);
        floodFill(x, y + 1, old_color, new_color);
        floodFill(x, y - 1, old_color, new_color);
    }
}

#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    rectangle(100, 100, 200, 200);

    setfillstyle(SOLID_FILL, GREEN);
    floodfill(150, 150, WHITE);  // 150,150 is inside the rectangle, WHITE is border color

    getch();
    closegraph();
    return 0;

}
