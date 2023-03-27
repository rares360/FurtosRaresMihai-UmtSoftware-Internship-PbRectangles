#include <set>
#include <stdio.h>
using namespace std;

//am facut o structura cu 2 int uri , pentru coordonatele unui punct (x,y)
struct Point {
    int x, y;
};

//aceasta functie returneaza un int (numarul de dreptunghiuri)
int contor_rec(Point points[],int n)
{
    //un set care contine punctele
    set<pair<int, int> > setPoints;

    //am parcurs lista de puncte si am inserat fiecare punct in set
    for (int i = 0; i < n; i++) {
        setPoints.insert({points[i].x,points[i].y});
    }
    //contor pentru a numara dreptunghiurile
    int contor = 0;
    //doua for-uri pentru a parcurge elementele din lista de puncte (fiecare cu fiecare) dar neaparat sa nu fie egale (acelasi punct)
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            //primul if verifica sa nu fie pe aceeasi axa daca sunt diferite inseamna ca punctele pot reprezenta colturile opuse ale unui posibil dreptunghi
            if (points[i].x != points[j].x && points[i].y != points[j].y){
                //daca punctele i(x,y) si j(x,y) sunt diferite se verifica urmatorul lucru
                //daca se afla in set (punctul i care are coordonata x si punctul j care are coordonata y) si (punctul j care are coordonata x si punctul i care are coordonata y)
                //care reprezinta coltul opus al primului punct respectiv celui de al doilea
                //daca ambele perechi respecta conditiile atunci crestem contorul
                if (setPoints.count({ points[i].x, points[j].y }) && setPoints.count({ points[j].x, points[i].y })){
                    contor++;
                }
            }
        }
    }
    //la final impartim contorul la 4 deoarece fiecare dreptunghi este numarat de 4 ori
    return contor / 4;
}

int main()
{
    //Testul1
    //lista de elemente de tipul Point{ int x,int y};
    struct Point points[] = {{1, 1}, {1, 3}, {2, 1}, {2, 3}, {3, 1}, {3, 3}};
    //determinam nr elementelor din lista
    int n = sizeof(points) / sizeof(points[0]);
    //afisam nr de dreptunghiuri
    printf("rectangles: %d\n",contor_rec(points,n));

    //Testul2
    //lista de elemente de tipul Point{ int x,int y};
    struct Point points1[] = {{1, 1}, {1, 3}, {2, 1}, {3, 1}, {3, 3}};
    //determinam nr elementelor din lista
    int n1 = sizeof(points1) / sizeof(points1[0]);
    //afisam nr de dreptunghiuri
    printf("rectangles: %d\n",contor_rec(points1,n1));

    return 0;

}
