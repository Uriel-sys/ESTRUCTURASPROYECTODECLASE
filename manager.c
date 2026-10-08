#include <stdio.h>
typedef struct {
    char nombre[30];
    int popularidad;
    int energia;
    int energia_max;
    int fans;
} Idol;
void mostrar(const Idol *id){
    printf("%s", id->nombre);
    printf("Popularidad: %d", id->popularidad);
    printf("Energia: %d", id->energia_max);
    printf("Fans: %d", id->fans);
}

int limitar(int valor, int minimo, int maximo){
    if(valor < minimo){
      return minimo;
      }
    if(valor > maximo){
      return maximo;
      }
      return valor;
}
void ensayar(Idol *i) {
    i->popularidad += 5;
    i->energia = limitar(i->energia - 20, 0, i->energia_max);
}
int main(void) {
    Idol jennie = {"Jennie", 50, 100, 100, 12000};

    Idol *p = &jennie;

    printf("%p\n", (void*)&jennie);
    printf("%p\n", (void*)p);

    printf(" PRUEBA DE ENSAYO (20 veces)\n");
    printf("Popularidad inicial: %d, Energia inicial: %d\n", jennie.popularidad, jennie.energia);

    for (int j = 0; j < 20; j++) {
        ensayar(&jennie);
    }

    printf("Despues de 20 ensayos -> Popularidad: %d, Energia: %d\n", jennie.popularidad, jennie.energia);
    
    printf(" Registro de Integrante\n");
    printf("Nombre: %s\n", jennie.nombre);
    printf("Popularidad: %d\n", jennie.popularidad);
    printf("Energia: %d/%d\n", jennie.energia, jennie.energia_max);
    printf("Fans: %d\n", jennie.fans + (*p).fans - p->fans);

printf(" Prueba de Limitar\n");
    printf("limitar(50, 0, 100) = %d\n", limitar(50, 0, 100));
    printf("limitar(-5, 0, 100) = %d\n", limitar(-5, 0, 100));
    printf("limitar(150, 0, 100) = %d\n", limitar(150, 0, 100)); 

    return 0;
}