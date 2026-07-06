#include <stdio.h>

// Muestra la clasificación cualitativa según la nota final
void calcNotaCualitativa(float nota){
    if(nota<2.5){
        printf(", REPROBADO");
    }else if(nota<7){
        printf(", SUPLETORIO");
    }else{
        printf(", APROBADO");
    }
}

// Calcula la nota del Examen de Síntesis (ES) a partir de ABP y Portafolio Digital
float calcES(){
    float ABP, PD, porcentajeABP, nota; 

    do{
    printf("Ingrese su nota del ABP, entre 0 y 10\n");
    scanf("%f", &ABP); // valida rango 0-10
    }while(ABP<0||ABP>10);

    do{
    printf("Ingrese su nota del Portafolio Digital, entre 0 y 10 \n");
    scanf("%f", &PD); // valida rango 0-10
    }while(PD<0||PD>10);

    do{
        printf("Ingrese el porcentaje del ponderado del ABP de 0 a 100\n");
        scanf("%f", &porcentajeABP); // valida rango 0-100
    }while(porcentajeABP<0||porcentajeABP>100);

    nota=((ABP*porcentajeABP)+(PD*(100-porcentajeABP)))/100; // promedio ponderado

    return nota;
}

// Calcula el promedio de un componente (ACD, APE o AA) según varias actividades
float porComponente(){
    float promedio=0, nota;
    int num, contador=1;

    printf("Ingrese el numero de actividades\n");
    scanf("%i", &num);

    while(num<1){ // valida que num sea mayor a 0
        printf("ERROR, el numero de actividades no puede ser menor o igual a 0\n");
        printf("Ingrese nuevamente el numero de actividades\n");
        scanf("%i", &num);
    }

    while(contador<=num){
        printf("Ingrese la nota de la actividad %i \n", contador);
        scanf("%f", &nota);

        while(nota<0||nota>10){ // valida rango 0-10
            printf("ERROR, la nota debe estar entre 0 y 10, ingrese la nota nuevamente");
            scanf("%f", &nota);
        }

        contador++;
        promedio += nota; // acumula nota
    }

    promedio=promedio/num; // promedio final
    
    return promedio;
}

// Calcula el promedio de una unidad combinando ACD, APE, AA y ES
float calculoPromedioUnidad(int i){
    float ACD, APE, AA, ES, promedio;
    printf("\n --- Unidad %i ---\n", i);
    
    printf("\n---ACD---\n");
    ACD=porComponente(); // Aprendizaje Colaborativo Dirigido

    printf("\n---APE---\n");
    APE=porComponente(); // Aprendizaje Práctico Experimental

    printf("\n---AA---\n");
    AA=porComponente(); // Aprendizaje Autónomo

    printf("\n---ES---\n");
    ES=calcES(); // Examen de Síntesis

    promedio=(2*ACD+2.5*APE+2*AA+3.5*ES)/10; // ponderación por créditos
    
    return promedio;
}


int main(){
    float promedio, FINAL=0;
    const int NUMEROUNIDAD=3; // número de unidades del curso
    
    printf("Bienvenido, en este algoritmo se calculara su promedio final\n");

    for(int i=1;i<=NUMEROUNIDAD;i++){    
        promedio=calculoPromedioUnidad(i); // promedio por unidad
        printf("EL PROMEDIO DE LA UNIDAD %i ES %.2f\n", i, promedio);
        FINAL += promedio; // acumula para el promedio final
    }

    FINAL=FINAL/NUMEROUNIDAD; // promedio final del curso

    printf("El promedio final de las 3 unidades es %.2f", FINAL);
    calcNotaCualitativa(FINAL); // clasificación cualitativa

    return 0;
}
