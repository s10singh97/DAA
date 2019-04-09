// Closest Pair Points

#include<iostream>
#include<math.h>
#include<float.h>
using namespace std;

class Point
{
    public:
    int x, y;
    Point(){};
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
};

int compareX(const void*a, const void*b)
{
    Point *p1 = (Point *)a,  *p2 = (Point *)b; 
    return (p1->x - p2->x); 
}

int compareY(const void*a, const void*b)
{
    Point *p1 = (Point *)a,   *p2 = (Point *)b; 
    return (p1->y - p2->y); 
}

float dis(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

float min(float a, float b)
{
    return (a < b) ? a : b;
}

float stripUtil(Point strip[], int s, float d)
{
    float min = d; 
    qsort(strip, s, sizeof(Point), compareY);   
    for (int i = 0; i < s; ++i) 
        for (int j = i+1; j < s && (strip[j].y - strip[i].y) < min; ++j) 
            if (dis(strip[i],strip[j]) < min) 
                min = dis(strip[i], strip[j]); 
  
    return min; 
}

float bf(Point P[], int n)
{
    float min = FLT_MAX;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(dis(P[i], P[j]) < min)
                min = dis(P[i], P[j]);
        }
    }
    return min;
}

float Util(Point P[], int n)
{
    if(n <= 3)
        return bf(P, n);
    int mid = n/2; 
    Point midp = P[mid]; 
 
    float dl = Util(P, mid); 
    float dr = Util(P + mid, n - mid); 
 
    float d = min(dl, dr); 
 
    Point strip[n]; 
    int j = 0; 
    for (int i = 0; i < n; i++) 
        if (abs(P[i].x - midp.x) < d) 
            strip[j] = P[i], j++; 

    return min(d, stripUtil(strip, j, d) );
}

float closest(Point P[], int n)
{
    qsort(P, n, sizeof(Point), compareX);
    return Util(P, n);
}

int main(int argc, char const *argv[])
{
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}}; 
    int n = sizeof(P) / sizeof(P[0]);
    cout<<"Minimum distance is: "<<closest(P, n)<<"\n";
    return 0;
}