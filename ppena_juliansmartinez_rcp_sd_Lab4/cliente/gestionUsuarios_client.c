
#include "gestionUsuarios.h"
#include "lab3.h"

void
gestion_usuario_1(char *host)
{
	CLIENT *clnt;
	bool_t  *result_1;
	nodo_usuario  registrarusuariosistema_1_arg;
	nodo_usuario  *result_2;
	int  consultarusuario_1_arg;
	bool_t  *result_3;
	int  generarrfc_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, gestion_usuario, gestion_usuario_version, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	nodo_usuario single_user;
	int op=0, aux;
	int dia=0,mes=0,anio=0;

	do{
	printf("***************************MENU********************\n");
    printf("| 1. Register an user |\n");
    printf("| 2. Generate RFC |\n");
    printf("| 3. Find User |\n");
    printf("| 4. Exit |\n");
    printf("***************************************************\n");
    printf("Chose an option : \n");
    scanf("%d",&op);

	switch (op)
	{
	case 1:

        printf("First name: ");
        scanf("%s",single_user.first_name);
        printf("Middle name: ");
        scanf("%s",single_user.second_name);
        printf("Last name: ");
        scanf("%s",single_user.first_last_name);
        printf("Second last name: ");
        scanf("%s",single_user.second_last_name);
        printf("Identification : ");
        scanf("%d",&single_user.cedula);
        printf("Birth Day : ");  
        scanf("%d",&dia);
        printf("Birth Month : "); 
        scanf("%d",&mes);
        printf("Birth Year : "); 
        scanf("%d",&anio);
		if ( validar_birthday(dia,mes,anio) ==false ){
            printf("\nError introducieno fecha de nacimiento valores esperados : \ndia[01 -31] \nmes[01 - 12] \naño[1800-2022] \n");
            limpiar_pantalla();
			break;
        }
        single_user.dia_nacimiento = dia;
        single_user.mes_nacimiento=mes;
        single_user.anio_nacimiento=anio;
        printf("Username: ");
        scanf("%s",single_user.username);
        printf("Password: ");
        scanf("%s",single_user.password);
        //limpiar_pantalla();
		result_1 = registrarusuariosistema_1(&single_user, clnt);
		if(*result_1 == TRUE){
			printf("\n:) Register succesfull ... \n");
		}else{
			printf("\n:( Fail register... \n");
		}
		limpiar_pantalla();
		break;
	case 2:
		printf("Generate RFC: \n");
        int cedula;
        printf("Type your ID to generate RFC: \n");
        scanf("%d",&cedula);
		result_3 = generarrfc_1(&cedula, clnt);
		if(*result_3 == TRUE){
			result_2 = consultarusuario_1(&cedula, clnt);
			printf("RFC Generado: [%s] \n", result_2->rfc);
		}else{
			printf("No se pudo generar el RFC. \n");
		}
		limpiar_pantalla();
		break;
	case 3:
		printf("Find User By Id: \n");
        printf("Type your ID to find user: \n");
        scanf("%d",&cedula);
		result_2 = consultarusuario_1(&cedula, clnt);
		if(result_2->cedula == 000){
			printf("User not found! \n");
		}else{
			printf("Name: [%s %s] \n", result_2->first_name, result_2->first_last_name);
			printf("Identification: [%d] \n", result_2->cedula);
			printf("RFC : [%s]\n",result_2->rfc);
			printf("Username: [%s]\n",result_2->username);
			printf("Birthday: [%d - %d - %d]\n", result_2->dia_nacimiento, result_2->mes_nacimiento, result_2->anio_nacimiento);  
			
		}
		limpiar_pantalla();
		break;
	case 4:break;
	default:
		printf("Type a valid option \n");
		break;
	}

	}while(op != 4);
	








	result_1 = registrarusuariosistema_1(&registrarusuariosistema_1_arg, clnt);
	if (result_1 == (bool_t *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_2 = consultarusuario_1(&consultarusuario_1_arg, clnt);
	if (result_2 == (nodo_usuario *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_3 = generarrfc_1(&generarrfc_1_arg, clnt);
	if (result_3 == (bool_t *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	gestion_usuario_1 (host);
exit (0);
}
