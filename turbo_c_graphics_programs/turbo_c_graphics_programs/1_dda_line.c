#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>  // for abs()

// Turbo C++ doesn't have round(), so define our own
int round_off(float num) {
    return (int)(num + 0.5);
}

void DDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
    float x_inc = dx / (float)steps;
    float y_inc = dy / (float)steps;
    float x = x1, y = y1;
    int i;

    for (i = 0; i <= steps; i++) {
        putpixel(round_off(x), round_off(y), WHITE);
        x += x_inc;
        y += y_inc;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI"); // Use your actual BGI path
    DDA(100, 100, 300, 300);
    getch();
    closegraph();
    return 0;
}
