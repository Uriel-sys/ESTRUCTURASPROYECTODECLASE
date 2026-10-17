#include <stdio.h>
typedef struct {
    char nombre[30];
    int popularidad;
    int energia;
    int energia_max;
    int fans;
} Idol;
void mostrar(const Idol *id){
    if (id == NULL) return;
    printf("Nombre: %s\n", id->nombre);
    printf("Popularidad: %d\n", id->popularidad);
    printf("Energia: %d/%d\n", id->energia, id->energia_max);
    printf("Fans: %d\n", id->fans);
}
int esta_activa(const Idol *i) {
    if (i == NULL) return 0;
    return (i->energia > 0) ? 1 : 0;
}
int limitar(int valor, int minimo, int maximo) {
    if (valor < minimo) return minimo;
    if (valor > maximo) return maximo;
    return valor;
}
void ensayar(Idol *i) {
    if (i == NULL) return;
    i->popularidad += 5;
    i->energia = limitar(i->energia - 20, 0, i->energia_max);
}
void descansar(Idol *i) {
    if (i == NULL) return;
    i->energia = limitar(i->energia + 30, 0, i->energia_max);
}
int colaboracion(Idol *a, Idol *b){
    if(a == NULL || b == NULL || a == b){
        return 0;
    }
    a->popularidad += 10;
    a->energia = limitar(a->energia - 15, 0, a->energia_max);
    b->popularidad += 10;
    b->energia = limitar(b->energia - 15, 0, b->energia_max);
    printf("Colaboracion exitosa entre %s y %s\n", a->nombre, b->nombre);
    return 1;
}
void ensayar_por_valor(Idol i) {
    i.popularidad += 5;
    i.energia = limitar(i.energia - 20, 0, i.energia_max);
    printf("Popularidad: %d, Energia: %d\n", i.popularidad, i.energia);
}
int main(void) {
    Idol jennie = {"Jennie", 50, 100, 100, 12000};
    Idol rose = {"Rose", 40, 90, 100, 10000};
    Idol *p = &jennie;
    
    printf("--Memoria--\n");
    printf("Direccion de jennie: %p\n", (void*)&jennie);
    printf("Direccion de p: %p\n", (void*)p);

    printf("\n--Demostracion de paso de valor y apuntador--\n");
    printf("Estado inicial->Popularidad:%d,Energia:%d\n", jennie.popularidad, jennie.energia);
    printf("\n1.Demostracion de Paso por Valor:\n");
    ensayar_por_valor(jennie);
    printf("Popularidad:%d,Energia:%d\n", jennie.popularidad, jennie.energia);
    printf("\n2.Demostracion de Paso por Apuntador:\n");
    ensayar(&jennie);
    printf("Popularidad: %d, Energia: %d\n", jennie.popularidad, jennie.energia);

    printf(" --PRUEBA DE ENSAYO (20 veces)--\n");
    printf("Popularidad inicial: %d, Energia inicial: %d\n", jennie.popularidad, jennie.energia);

    for (int j = 0; j < 20; j++) {
        ensayar(&jennie);
    }
    
    printf("Despues de 20 ensayos -> Popularidad: %d, Energia: %d\n", jennie.popularidad, jennie.energia);

    printf(" --PRUEBA DESCANSAR--\n");
    printf("Energia antes de descansar: %d\n", jennie.energia);

    for (int j = 0; j < 20; j++) {
        descansar(&jennie);
    }

    printf("Energia despues de descansar 20 veces: %d\n", jennie.energia);

    printf(" --Registro de Integrante--\n");
    printf("Nombre: %s\n", jennie.nombre);
    printf("Popularidad: %d\n", jennie.popularidad);
    printf("Energia: %d/%d\n", jennie.energia, jennie.energia_max);
    printf("Fans: %d\n", jennie.fans + (*p).fans - p->fans);

    printf(" --Prueba de Limitar--\n");
    printf("limitar(50, 0, 100) = %d\n", limitar(50, 0, 100));
    printf("limitar(-5, 0, 100) = %d\n", limitar(-5, 0, 100));
    printf("limitar(150, 0, 100) = %d\n", limitar(150, 0, 100)); 

    printf("--ESTADO DE ACTIVIDAD--\n");
    printf("Energia: %d -> Estado activa: %d\n", jennie.energia, esta_activa(&jennie));
    jennie.energia = 1;
    printf("Energia: %d -> Estado activa: %d\n", jennie.energia, esta_activa(&jennie));
    jennie.energia = 0;
    printf("Energia: %d -> Estado activa: %d\n", jennie.energia, esta_activa(&jennie));

    printf("--Prueba de Colaboracion--\n");
    printf("1. Colaboracion jennie & jennie: %d\n", colaboracion(&jennie, &jennie));
    printf("2. Colaboracion NULL & rose: %d\n", colaboracion(NULL, &rose));
    printf("3. Colaboracion valida (&jennie, &rose):\n");
    int exito = colaboracion(&jennie, &rose);
    printf("Resultado retorno: %d\n", exito);
    
    printf("\n--Estado tras colaboracion--\n");
    mostrar(&jennie);
    mostrar(&rose);

    printf("\n--Duelo de Ensayos por Turnos--\n");
    jennie.energia = 100;
    rose.energia = 100;

    Idol *turno = &jennie;
    Idol *otra = &rose;
    Idol *temp = NULL;

    int ronda = 1;
    while (esta_activa(turno) && esta_activa(otra)) {
        printf("Ronda %d: Le toca ensayar a %s (Energia previa: %d)\n", ronda, turno->nombre, turno->energia);
        ensayar(turno);
        printf("  -> Energia despues de ensayar: %d\n", turno->energia);

        temp = turno;
        turno = otra;
        otra = temp;
        ronda++;
    }

    printf("\n---Resultado del duelo---\n");
    if (esta_activa(&jennie)) {
        printf("%s conserva energia (%d) y gana el duelo\n", jennie.nombre, jennie.energia);
    } else if (esta_activa(&rose)) {
        printf("%s conserva energia (%d) y gana el duelo\n", rose.nombre, rose.energia);
    } else {
        printf("Ambas integrantes se quedaron sin energia al mismo tiempo.\n");
    }

    return 0;
}