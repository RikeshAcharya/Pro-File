#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h>

#define PI 3.14159

struct Point3D {
    float x;
    float y;
    float z;
};

// Project 3D point to 2D (simple oblique projection)
void project(Point3D p, int *px, int *py) {
    int factor = 1;  // Oblique factor
    *px = (int)(p.x + 0.5 * p.z);
    *py = (int)(p.y - 0.5 * p.z);
}

// Draw cube using projected points
void drawCube(Point3D cube[], int color) {
    setcolor(color);
    int px[8], py[8];
    int i;

    for (i = 0; i < 8; i++)
        project(cube[i], &px[i], &py[i]);

    // Draw front face
    line(px[0], py[0], px[1], py[1]);
    line(px[1], py[1], px[2], py[2]);
    line(px[2], py[2], px[3], py[3]);
    line(px[3], py[3], px[0], py[0]);

    // Draw back face
    line(px[4], py[4], px[5], py[5]);
    line(px[5], py[5], px[6], py[6]);
    line(px[6], py[6], px[7], py[7]);
    line(px[7], py[7], px[4], py[4]);

    // Connect front and back faces
    line(px[0], py[0], px[4], py[4]);
    line(px[1], py[1], px[5], py[5]);
    line(px[2], py[2], px[6], py[6]);
    line(px[3], py[3], px[7], py[7]);
}

// Translate cube
void translate(Point3D cube[], int tx, int ty, int tz) {
    int i;
    for (i = 0; i < 8; i++) {
        cube[i].x += tx;
        cube[i].y += ty;
        cube[i].z += tz;
    }
}

// Scale cube about first point
void scale(Point3D cube[], float sx, float sy, float sz) {
    int i;
    float x0 = cube[0].x;
    float y0 = cube[0].y;
    float z0 = cube[0].z;

    for (i = 0; i < 8; i++) {
        cube[i].x = x0 + (cube[i].x - x0) * sx;
        cube[i].y = y0 + (cube[i].y - y0) * sy;
        cube[i].z = z0 + (cube[i].z - z0) * sz;
    }
}

// Rotate around Y-axis
void rotateY(Point3D cube[], float angle) {
    int i;
    float rad = angle * PI / 180;
    for (i = 0; i < 8; i++) {
        float x = cube[i].x;
        float z = cube[i].z;
        cube[i].x = x * cos(rad) + z * sin(rad);
        cube[i].z = -x * sin(rad) + z * cos(rad);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    Point3D cube[8] = {
        {100, 100, 0}, {200, 100, 0}, {200, 200, 0}, {100, 200, 0},
        {100, 100, 100}, {200, 100, 100}, {200, 200, 100}, {100, 200, 100}
    };

    // Original cube - WHITE
    drawCube(cube, WHITE);
    getch();
    cleardevice();

    // Translated cube - GREEN
    translate(cube, 50, 0, 0);
    drawCube(cube, GREEN);
    getch();
    cleardevice();

    // Scaled cube - BLUE
    scale(cube, 0.5, 1.2, 1.0);
    drawCube(cube, BLUE);
    getch();
    cleardevice();

    // Rotated cube around Y-axis - RED
    rotateY(cube, 45);
    drawCube(cube, RED);
    getch();

    closegraph();
    return 0;
}
