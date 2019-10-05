#inlcude "hash.h"
#DEFINE TAM 32

enum estado { VACIO , OCUPADO , BORRADO };// VACIO=0,OCUPADO=1,BORRADO=2;


typedef campo campo_t{
	char* clave;
	void* valor;
	int estado;
};

struct hash hash_t{
	size_t capacidad; 
	size_t cantidad;
	campo_t* campo;
	size_t borrados;
	
};

struct hash_iter hash_iter_t{
	hash_t* hash;
	campo_t* actual;
	campo_t* anterior;
};
	
typedef void (*hash_destruir_dato_t)(void *);

hash_t *hash_crear(hash_destruir_dato_t destruir_dato){
	hash_t* hash = malloc(sizeof(hash_t));
	if(hash==NULL){
		return NULL;
	}
	
	hash->campo =
	hash->cantidad = 0;
	hash->capacidad = TAM;
	hash->borrados = 0;
}

bool hash_guardar(hash_t *hash, const char *clave, void *dato){
}
void *hash_borrar(hash_t *hash, const char *clave){
}
void *hash_obtener(const hash_t *hash, const char *clave);
bool hash_pertenece(const hash_t *hash, const char *clave);
size_t hash_cantidad(const hash_t *hash);
void hash_destruir(hash_t *hash);

hash_iter_t *hash_iter_crear(const hash_t *hash);
bool hash_iter_avanzar(hash_iter_t *iter);
const char *hash_iter_ver_actual(const hash_iter_t *iter);
bool hash_iter_al_final(const hash_iter_t *iter);
void hash_iter_destruir(hash_iter_t* iter);
