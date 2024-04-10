/* Header file "lista_dc.h". */

/* Ridefinizione delle costanti simboliche esportate */
typedef struct	nodo_t
{

	int		info;		/* Campo contenente l'informazione. */
	struct	nodo_t	*successivo;	/* Puntatore all'elemento successivo. */
	struct	nodo_t	*precedente;	/* Puntatore all'elemento precedente. */
}	nodo;

typedef	struct	lista_t
{
	int		conto;
	struct	nodo_t	*testa;
	struct	nodo_t	*coda;
	struct	nodo_t	*aus;
	struct	nodo_t	*temp;
}	lista;

/* Ridichiarazione delle funzioni esportate (precedute da extern) */
extern	lista	*inserisci_testa(lista *lista_t);
extern	lista	*inserisci_coda(lista *lista_t);
extern	lista	*inserisci_prima(lista *lista_t);
extern	lista	*inserisci_dopo(lista *lista_t);
extern	lista	*stampa_avanti(lista *lista_t);
extern	lista	*stampa_indietro(lista *lista_t);
extern	lista	*cancella_info(lista *lista_t);
extern	lista  *cancella_testa(lista *lista_t);
extern	lista	*cancella_coda(lista *lista_t);
