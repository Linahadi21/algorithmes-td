#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* ===== STRUCTURE POINT ===== */
typedef struct {
    int x, y;
} Point;

Point saisirPoint() {
    Point p;
    printf("Entrer x y : ");
    scanf("%d %d", &p.x, &p.y);
    return p;
}

void afficherPoint(Point p) {
    printf("(%d,%d)\n", p.x, p.y);
}

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

/* ===== STRUCTURE HEURE ===== */
typedef struct {
    int h,m,s;
} Heure;

int enSecondes(Heure h) {
    return h.h*3600 + h.m*60 + h.s;
}

Heure depuisSecondes(int sec) {
    Heure h;
    h.h = sec/3600;
    sec%=3600;
    h.m = sec/60;
    h.s = sec%60;
    return h;
}

Heure addition(Heure h1, Heure h2) {
    return depuisSecondes(enSecondes(h1)+enSecondes(h2));
}

Heure difference(Heure h1, Heure h2) {
    return depuisSecondes(abs(enSecondes(h1)-enSecondes(h2)));
}

/* ===== MAIN TEST ===== */
int main() {
    int n=3;
    Point t[3];

    for(int i=0;i<n;i++)
        t[i]=saisirPoint();

    tri(t,n);

    printf("Points tries:\n");
    for(int i=0;i<n;i++)
        afficherPoint(t[i]);

    Heure h1={1,20,30}, h2={2,10,10};
    Heure h3=addition(h1,h2);

    printf("Addition: %d:%d:%d\n",h3.h,h3.m,h3.s);

    return 0;
}
