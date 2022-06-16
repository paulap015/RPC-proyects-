/*Declaracion de datos a transferir entre el cliente y el servidor*/

/*Declaracion de constantes*/
const MAXNOM = 30;
const MAXTIPO = 20;


/*Declaracion de la estructura que permite almacenar los datos de un usuario*/
struct nodo_usuario{
    char first_name[MAXNOM];
    char second_name[MAXNOM];
    char first_last_name[MAXNOM];
    char second_last_name[MAXNOM];
    int dia_nacimiento;
    int mes_nacimiento;
    int anio_nacimiento;
    int  cedula;
    char username[MAXNOM];
    char password[MAXNOM];
    char rfc[MAXNOM];
};

/*Definicion de las operaciones que se pueden realizar*/
program gestion_usuario{
	version gestion_usuario_version{
		bool registrarUsuarioSistema(nodo_usuario objUsuario)=1;
		nodo_usuario consultarUsuario(int cedula)=2;		
        bool generarRfc(int cedula) = 3;   
	}=1;
}=0x20000001;

