#include <stdio.h>
typedef struct {
    char nombre[30];
    int popularidad;
    int energia;
    int energia_max;
    int fans;
} Idol;

int main(void) {
    Idol jennie = {"Jennie", 50, 100, 100, 12000};
    printf(" Registro de Integrante\n");
    printf("Nombre: %s\n", jennie.nombre);
    printf("Popularidad: %d\n", jennie.popularidad);
    printf("Energia: %d/%d\n", jennie.energia, jennie.energia_max);
    printf("Fans: %d\n", jennie.fans);
    return 0;
}