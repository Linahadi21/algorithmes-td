#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x, y;
} Point;

float distance(Point p) {
    return sqrt(p.x*p.x + p.y*p.y);
}

void tri(Point t[], int n) {
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(distance(t[i]) > distance(t[j])) {
                Point tmp = t[i];
                t[i] = t[j];
                t[j] = tmp;
            }
}

typedef struct {
    int h, m, s;
} Heure;

int enSecondes(Heure h) {
    return h.h*3600 + h.m*60 + h.s;
}

Heure depuisSecondes(int sec) {
    Heure h;
    h.h = sec/3600;
    sec %= 3600;
    h.m = sec/60;
    h.s = sec%60;
    return h;
}

int main() {
    Point t[3] = {{1,2},{3,4},{0,1}};
    tri(t,3);

    Heure h = {1,2,3};
    printf("Secondes = %d\n", enSecondes(h));
}
