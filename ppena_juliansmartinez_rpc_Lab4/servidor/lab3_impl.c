
void limpiar_pantalla(){
    char *var;
    printf("\n\nPress any key + [ENTER] to continue.. \n");
    scanf("%s",&var);
    system("clear");
}
bool validar_birthday(int dia, int mes, int anio){
    printf("dia %d mes %d anio %d ",dia,mes,anio);
    if(dia < 01 || dia > 31){
        printf("dia");
        return false;
    }
    if(mes <1 || mes>12){
        printf("mes");
        return false;
    }
    if(anio<1800 || anio > 2022){
        printf("año");
        return false;
    }
    return true;
}