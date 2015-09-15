#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI      3.14159265
#define EPS     0.01    //float equality tolerance

#define XMIN    -5
#define XMAX    5
#define YMIN    -5
#define YMAX    5

#define EMPTY   '.'
#define FILL    '#'

typedef struct verts{
    double x, y;
} vertice;

typedef struct shape{
    size_t numVerts;
    vertice* points;
} shape;

int feq(double a, double b){
//comparing floats
    return (fabs(a-b) < EPS);
}

shape* shapeConstructor(const size_t n){
    shape* a = malloc(sizeof(shape));
    a->numVerts = n;
    a->points = malloc(sizeof(vertice)*n);
    return a;
}

shape* shapeDefiner(void){
    size_t n, i;
    printf("Enter number of vertices(>=3): ");
    do{
        scanf("%lu", &n);
    }while(n<3);
    shape* a = shapeConstructor(n);
    for(i=0; i<n; i++){
        printf("Enter x coord of vertice %lu: ", i+1);
        scanf("%lf", &(a->points[i].x));
        printf("Enter y coord of vertice %lu: ", i+1);
        scanf("%lf", &(a->points[i].y));
    }
    return a;
}

void shapeTranslator(shape* a, vertice vect){
    //using vertice struct as a 2d vector (vect)
    int i;
    for(i=0; i<(a->numVerts); i++){
        a->points[i].x += vect.x;
        a->points[i].y += vect.y;
    }
}

void shapeRotator(shape* a, double rads){
    double px, py;
    unsigned i;
    for(i=0; i<a->numVerts;  i++){
        px = a->points[i].x*cos(rads) - a->points[i].y*sin(rads);
        py = a->points[i].x*sin(rads) + a->points[i].y*cos(rads);
        a->points[i].x = px;
        a->points[i].y = py;
    }
}

void shapeScaler(shape* a, double factor){
    unsigned i;
    for(i=0; i<a->numVerts;  i++){
        a->points[i].x *= factor;
        a->points[i].y *= factor;
    }
}

void shapeDeconstructor(shape* a){
    free(a->points);
    free(a);
}

void printShape(shape* a){
    int x, y, i, ch = EMPTY;
    for(y = YMAX; y>=YMIN; y--){
        for(x = XMIN; x<=XMAX; x++){
            for(i=0; i<a->numVerts; i++){
                if(feq(a->points[i].x, x) && feq(a->points[i].y, y)){
                    putchar(ch = FILL);
                }
            }
            if(ch!=FILL){
                putchar(EMPTY);
            }else ch = EMPTY;
        }
        putchar('\n');
    }
    putchar('\n');
}

int main(void){
    //creating the shape
    shape* a = shapeDefiner();
    printShape(a);

    //translation
    vertice translation = {1, -1};
    shapeTranslator(a, translation);
    printShape(a);

    //rotation
    shapeRotator(a, PI/2.0);
    printShape(a);

    //scaling
    shapeScaler(a, 1.5);
    printShape(a);

    shapeDeconstructor(a);
}
