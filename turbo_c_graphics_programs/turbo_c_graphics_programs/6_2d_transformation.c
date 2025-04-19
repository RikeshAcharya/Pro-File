#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h>

#define PI 3.14159

// Function to draw a triangle
void drawTriangle(int x[], int y[], int color) {
    setcolor(color);
    line(x[0], y[0], x[1], y[1]);
    line(x[1], y[1], x[2], y[2]);
    line(x[2], y[2], x[0], y[0]);
}

// Function to translate a triangle
void translate(int x[], int y[], int tx, int ty, int xt[], int yt[]) {
    int i;
    for (i = 0; i < 3; i++) {
        xt[i] = x[i] + tx;
        yt[i] = y[i] + ty;
    }
}

// Function to scale a triangle about the origin
void scale(int x[], int y[], float sx, float sy, int xs[], int ys[]) {
    int i;
    for (i = 0; i < 3; i++) {
        xs[i] = x[i] * sx;
        ys[i] = y[i] * sy;
    }
}

// Function to rotate a triangle about the origin
void rotate(int x[], int y[], float angle, int xr[], int yr[]) {
    int i;
    for (i = 0; i < 3; i++) {
        // Rotate each point by angle (in radians)
        xr[i] = x[i] * cos(angle) - y[i] * sin(angle);
        yr[i] = x[i] * sin(angle) + y[i] * cos(angle);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");  // Initialize graphics mode with BGI path

    // Original triangle coordinates
    int x[3] = {100, 150, 200};
    int y[3] = {150, 100, 150};

    // Draw the original triangle (white)
    drawTriangle(x, y, WHITE);

    // 1. Translate the triangle by (100, 50)
    int xt[3], yt[3];
    translate(x, y, 100, 50, xt, yt);
    drawTriangle(xt, yt, GREEN);  // Draw translated triangle (green)

    // 2. Scale the triangle by a factor of 1.5 (scaling about the origin)
    int xs[3], ys[3];
    scale(x, y, 1.5, 1.5, xs, ys);
    drawTriangle(xs, ys, BLUE);  // Draw scaled triangle (blue)

    // 3. Rotate the triangle by 45 degrees (in radians)
    int xr[3], yr[3];
    float angle = 45.0 * PI / 180.0;  // Convert angle to radians
    rotate(x, y, angle, xr, yr);
    drawTriangle(xr, yr, RED);  // Draw rotated triangle (red)

    getch();  // Wait for user input
    closegraph();  // Close graphics mode
    return 0;
}
