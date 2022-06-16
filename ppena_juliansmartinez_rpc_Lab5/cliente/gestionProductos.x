/*Declaracion de datos a transferir entre el cliente y el servidor*/
/*Declaracion de constantes*/
const MAXCHAR = 30;
const MAXTIPO = 20;

/*Declaracion de la estructura que permite almacenar los datos de un producto*/
struct nodo_producto{
    int id;
    char name[MAXCHAR];
    char description[MAXCHAR];
    double vat;
    double price;
    nodo_producto * siguiente;
};

/*Declaracion de la estructura que permite registrar usuarios*/
struct nodo_usuario{
    char username[MAXCHAR];
    char password[MAXCHAR];
};


/*Declaracion de la estructura que permite generar una factura*/
struct nodo_factura{
    int id_factura;
    char fecha[MAXCHAR];
    char username[MAXCHAR];
    double precio_bruto;
    double descuento;
    double precio_neto;
    nodo_producto product;
};

/*Definicion de las operaciones que se pueden realizar*/
program gestion_producto{
	version gestion_usuario_version{
		nodo_usuario saveUser(nodo_usuario objUsuario)=1;
        bool isValidUser(nodo_usuario objUsuario)= 2;
		nodo_producto findProductById(int id)=3;		
        nodo_producto findAllProducts() = 4;
        bool addProductInvoice(int id)=5;
        nodo_factura finishInvoice() = 6;
	}=1;
}=0x20000001;

