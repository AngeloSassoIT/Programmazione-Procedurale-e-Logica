/* File sorgente "lista_dc.c". */

/* Inclusione delle librerie standard. */
#include <stdlib.h>
#include <stdio.h>

/* Definizione dei tipi da esportare e interni. */

/* Viene definito il tipo "nodo" che sarà la struttura predisposta
 * alla gestione di ogni nodo della lista.
 * Contiene un campo intero che ospita l'informazione del nodo e
 * due puntatori che saranno rispettivamente il puntatore all'elemento successivo
 * e il puntatore all'elemento precedente della lista. */ 
typedef struct	nodo_t
{
	int		info;
	struct	nodo_t	*successivo;
	struct	nodo_t	*precedente;
}	nodo;


/* Viene inoltre definito il tipo "lista" che sarà una
 * struttura di sostegno utile alla definizione della lista.
 * Contiene un valore intero che terrà traccia della lunghezza della lista.
 * Vengono definiti quattro puntatori ad elementi particolari della lista
 * quali l'elemento di testa, quello di coda, un puntatore ausiliario
 * e uno temporaneo. */  
typedef struct	lista_t
{
	int		conto;
	struct	nodo_t	*testa;
	struct	nodo_t	*coda;
	struct	nodo_t	*aus;
	struct  nodo_t	*temp;
}	lista;

/* Dichiarazione delle variabili. */

/* Dichiarazione delle funzioni da esportare e interne. */
lista * inserisci_testa(lista *lista_t);
lista * inserisci_coda(lista *lista_t);
lista * inserisci_prima(lista *lista_t);
lista * inserisci_dopo(lista *lista_t);
void    stampa_avanti(lista *lista_t);
void	stampa_indietro(lista *lista_t);
lista * cancella_info(lista *lista_t);
lista * cancella_testa(lista *lista_t);
lista * cancella_coda(lista *lista_t);
lista * crea(lista *lista_t);
void	svuota_buffer();

/* Definizione delle funzioni da esportare e interne (no main). */

/* La funzione "inserisci_testa" prende in input la lista.
 * Inserisce un nuovo elemento in testa alla lista chiamando
 * la funzione "crea()" per poi ricollegare i puntatori.
 * Restituisce la lista modificata. */
lista * inserisci_testa(lista *lista_t)
{
	if(lista_t->testa == NULL)
	{
		lista_t = crea(lista_t);
		/* Il nuovo elemento è la testa della lista. */
		lista_t->testa = lista_t->temp;
		lista_t->coda = lista_t->testa;
	}
	else
	{
		lista_t = crea(lista_t);
		lista_t -> temp -> successivo = lista_t -> testa;
		lista_t -> temp -> precedente = lista_t -> temp;
		/* Il nuovo elemento è la testa della lista. */
		lista_t->testa = lista_t->temp;
	}
	return(lista_t);
}

/* La funzione "inserisci_coda" ha la lista in input. 
 * Inserisce un nuovo elemento in coda alla lista chiamando 
 * la funzione "crea()" per poi ricollegare i puntatori.
 * Restituisce la lista modificata. */
lista * inserisci_coda(lista *lista_t)
{
	/* Caso in cui la lista è vuota. */
	if(lista_t->testa == NULL)
	{
		/* Creo l'elemento. */
		lista_t = crea(lista_t);
		lista_t->testa = lista_t->temp;
		lista_t->testa->successivo = NULL;
		lista_t->testa->precedente = NULL;
		/* Il nuovo elemento sarà la coda e la testa della lista. */
		lista_t->coda = lista_t->testa;
	}

	else
	{
		/* Creo l'elemento. */
		lista_t = crea(lista_t);
		lista_t->aus = lista_t->coda;
		lista_t->coda->successivo = lista_t->temp;
		lista_t->temp->precedente = lista_t->coda;
		/* Il nuovo elemento è la coda della lista. */
		lista_t->coda = lista_t->temp;
		lista_t->coda->successivo = NULL;
	}
	return(lista_t);

}

/* "inserisci_prima_di_posizione()" è la funzione che si occupa di 
 * creare un nuovo elemento con l'utilizzo della funzione "crea()"
 * e successivamente posizionarlo prima della posizione scelta dall'utente
 * per poi ricollegare i puntatori ad operazioni concluse. */
lista * inserisci_prima(lista *lista_t)
{
	/* Dichiarazione delle variabili */
	int	posizione;	/* Variabile per acquisire da tastiera la posizione dove inserire l'elemento. */
	int	i = 2;		/* Variabile per il ciclo while. */
	int	esito;	/* Variabile per il controllo dei caratteri. */

	if(lista_t->testa==NULL)
	{
		printf("\nLa lista è vuota.\n");
		printf("E' possibile inserire un elemento in posizione 1 (Prima di posizione 1).\n");
		printf("\nPremere un tasto per continuare...");
		getchar();
		svuota_buffer();
	}
		
	/* Stampa per l'acquisizione della posizione. */
	do
	{
		printf("\nPrima di quale posizione inserire il nuovo nodo?\t");

		/* Controllo dei caratteri inseriti. */
		esito = scanf("%d", &posizione);
	
		if(esito != 1)
		{
			printf("\nPer favore, inserire una posizione valida (un intero):\t");
			svuota_buffer();
		}
	}	while(esito != 1 || posizione < 0);


	/* Il puntatore aus punta alla testa della lista. */
	lista_t->aus = lista_t->testa;

	/* Caso in cui la posizione è minore di 1 o al di fuori della grandezza della lista. */
	if((posizione < 1) || posizione >= (lista_t -> conto ))
	{
		printf("\nLa posizione è fuori portata.");
		printf("\nPremere un tasto per continuare...");
		getchar();
		svuota_buffer();
	}

	/* Caso in cui la lista è vuota e la posizione è diversa da 1. */
	else if((lista_t->testa == NULL) && (posizione != 1))
	{
		printf("\nE' possibile inserire un nuovo nodo solo in testa.");
		printf("\nLa lista è vuota.");
		printf("\nPremere un tasto per continuare...");
		getchar();
		svuota_buffer();
	}

	/* Caso in cui la lista non è vuota e la posizione è uguale ad 1. */
	else if((lista_t->testa != NULL) && (posizione ==1))
	{
		lista_t = inserisci_testa(lista_t);
	}

	/* Caso in cui la lista è vuota e la posizione è uguale ad 1. */
	else if((lista_t->testa == NULL) && (posizione == 1))
	{
		lista_t = crea(lista_t);
		lista_t->testa = lista_t->temp;
		lista_t->coda = lista_t->testa;
	}

	else
	{
		/* Ciclo per posizionare il puntatore ausiliario. */
		while (i < posizione)
		{
			lista_t->aus = lista_t->aus->successivo;
			i++;
		}

		/* Creo l'elemento. */
		lista_t = crea(lista_t);

		/* Organizzo i puntatori. */
		lista_t->temp->precedente = lista_t->aus;
		lista_t->temp->successivo = lista_t->aus->successivo;
		(lista_t->aus->successivo)->precedente = lista_t->temp;
		lista_t->aus->successivo = lista_t->temp;
	}

	return(lista_t);	
}

/* "inserisci_dopo_di_posizione()" è la funzione che si occupa di 
 * creare un nuovo elemento con l'utilizzo della funzione "crea()" 
 * e successivamente posizionarlo dopo la posizione scelta dall'utente
 * per poi ricollegare i puntatori ad operazioni concluse. */
lista * inserisci_dopo(lista *lista_t)
{
	
	/* Dichiarazione delle variabili. */
	int	posizione = 0;		/* Variabile per acquisire da tastiera la posizione dove inserire l'elemento.  */
	int	i = 1;			/* Variabile per il ciclo while. */
	int	esito = 0;		/* Variabile per il controllo dei caratteri. */

	if(lista_t->testa==NULL)
	{
		printf("\nLa lista è vuota.\n");
		printf("E' possibile inserire un elemento in posizione 1.\n");
	}
		
	/* Stampa per l'acquisizione della posizione. */
	do
	{
		printf("\nDopo di quale posizione inserire il nuovo nodo?\t");

		/* Controllo dei caratteri inseriti. */
		esito = scanf("%d", &posizione);
	
		if(esito != 1)
		{
			printf("\nPer favore, inserire una posizione valida (un intero):\t");
			svuota_buffer();
		}
	}	while(esito != 1 || posizione < 0);
	
	/* Il puntatore "aus" tiene memoria della testa della lista. */
	lista_t->aus = lista_t -> testa;
	
	/* Caso in cui la posizione è minore di 0 o maggiore del numero di elementi della lista */
	if((posizione < 0) || (posizione > lista_t->conto))
	{
		printf("\nLa posizione è fuori portata.");
		printf("\nPremere un tasto per continuare...");
		getchar();
		svuota_buffer();
	}
	
	/* Caso in cui la lista è vuota e la posizione inserita è diversa dalla testa. */
	else if((lista_t->testa == NULL) && (posizione != 0))
	{
		printf("\nLa lista è vuota.");
		printf("\nPremere un tasto per continuare...");
		getchar();
		svuota_buffer();
	}
	
	/* Caso in cui la lista non è vuota e la posizione inserita è la testa. */
	else if((lista_t->testa != NULL) && (posizione == 0))
	{
		lista_t = inserisci_testa(lista_t);
	}
	
	/* Caso in cui la lista è vuota e la posizione inserita è la testa. */
	else if((lista_t->testa == NULL) && (posizione == 0))
	{
		lista_t = inserisci_testa(lista_t);
	}
	
	/* Caso in cui la lista non è vuota e la posizione è la coda. */
	else if(lista_t->testa != NULL && posizione == lista_t->conto)
	{
		lista_t = inserisci_coda(lista_t);
	}
	
	/* Caso in cui la lista non è vuota e la posizione è un intero
	   diverso dalla testa o dalla coda della lista. */
	else if((lista_t->testa != NULL) || (posizione != 0))
	{
		while(i < posizione)
		{
			lista_t->aus = lista_t->aus->successivo;
			i++;	
		}
	
		/* Creo l'elemento. */
		lista_t = crea(lista_t);

		/* Collego i puntatori. */
		lista_t->temp->precedente = lista_t->aus;

		/* Se l'elemento è la coda della lista. */
		if(lista_t->aus->successivo == NULL)
		{
			/* Collego i puntatori. */
			lista_t->temp->successivo = NULL;
			lista_t->aus->successivo = lista_t->temp;
		}

		else
		{
			/* Collego i puntatori. */
			lista_t->temp->successivo = lista_t->aus->successivo;
			lista_t->aus->successivo = lista_t->temp->successivo;
		}
	}
	
	return(lista_t);
}

/* La funzione "stampa_posizione_coda()"
 * visita la lista per poi stamparla
 * dalla posizione scelta dall'utente alla coda. */
void	stampa_avanti(lista *lista_t)
{
	/* Dichiarazione delle variabili. */
	int	i;		/* Variabile per il ciclo for. */
	int	n;		/* Posizione da acquisire da tastiera dal quale iniziare la visita. */
	int	esito;		/* Variabile per la validazione stretta dell'input. */
	lista_t->temp = lista_t->testa;		/* Il puntatore temp tiene memoria della testa della lista. */

	do
	{
		/* Stampa per l'acquisizione di un intero, la posizione dal quale iniziare la stampa. */
		printf("\nInserire la posizione dal quale iniziare la visita.");

		/* Ciclo while per il controllo dei caratteri. */
		esito = (scanf("%d", &n));
		if(esito!=1)
		{
			printf("\nErrore: posizione non valida.\n");
			printf("Inserire un intero compreso tra 1 e %d (inclusi).\t", lista_t->conto);
			getchar();
			svuota_buffer();
		}
	} while(esito!=1 && n>lista_t->conto);

	/* Caso in cui la lista è vuota e la posizione è diversa da 0. */
	if(lista_t->testa == NULL && n != 0)
	{
		printf("\nLa lista è vuota.");
		printf("\nPremere un tasto per continuare...");	
		getchar();
		svuota_buffer();
	}

	/* Caso in cui la posizione sia al di fuori della grandezza della lista. */
	else if(n > lista_t->conto)
	{
		printf("\nLa posizione è fuori portata.");
		printf("\nPremere un tasto per continuare...");
		getchar();
		svuota_buffer();
	}

	/* Caso in cui la posizione scelta è uguale a 0. */
	else if(n == 0)
	{
		printf("\nLa posizione 0 non è accettata, la testa della lista ha come indice '1'.");	
	}

	else
	{
		printf("\nLista dalla posizione '%d' in avanti :\n", n);
		printf(" [");

		/* Ciclo for per incrementare "i" scorrendo gli elementi. */
		for(i=0; i<=n-2; i++)
		{
			/* Il puntatore temp scorre gli elementi. */
			lista_t->temp = lista_t->temp->successivo;
		}

		while(lista_t->temp->successivo != NULL)
		{
			printf(" (Informazione: %d) ", lista_t->temp->info);
			lista_t->temp = lista_t->temp->successivo;
		}

		/* Stampa dell'elemento di coda. */
		printf(" (Informazione: %d) ] Coda", lista_t->temp->info);
		printf("\n\t\tLunghezza della lista: %d.\n", lista_t->conto);
		
		printf("\nPremere un tasto per continuare...");
		getchar();
		svuota_buffer();
	}
}

/* La funzione "stampa_posizione_testa()" 
 * visita la lista e la stampa
 * dalla posizione scelta dall'utente alla testa. */
void	stampa_indietro(lista *lista_t)
{
	/* Dichiarazione delle variabili. */
	int	i;		/* Variabile per per incrementare i puntatori nel ciclo for. */
	int	n;		/* Variabile per la posizione dal quale iniziare la visita. */
	int	esito;		/* Variabile per la validazione stretta dell'input. */
	/* Il puntatore temp tiene memoria della testa della lista. */
	lista_t->temp = lista_t->testa;

	do
	{
		/* Stampa per l'acquisizione di un intero, la posizione dal quale iniziare la stampa. */
		printf("\nInserire la posizione dal quale iniziare la visita.");

		/* Ciclo while per il controllo dei caratteri. */
		esito = (scanf("%d", &n));
		if(esito!=1)
		{
			printf("\nErrore: posizione non valida.\n");
			printf("Inserire un intero compreso tra 1 e %d (inclusi).\t", lista_t->conto);
			getchar();
			svuota_buffer();
		}
	} while(esito!=1 && n>lista_t->conto);

	/* Caso in cui la lista è vuota. */
	if(lista_t->testa == NULL)
	{
		printf("\nLa lista è vuota.");
		printf("\nPremere un tasto per continuare...");
		getchar();
		svuota_buffer();
	}

	/* Caso in cui la posizione sia al di fuori della grandezza della lista. */
	else if(n > lista_t->conto)
	{
		printf("\nLa posizione è fuori portata.");
		printf("\nPremere un tasto per continuare...");
		getchar();
		svuota_buffer();
	}

	/* Caso in cui la posizione è uguale a 0. */
	else if(n==0)
	{
		printf("\nLa posizione 0 non è accettata, \nla lista ha come inizio la testa con indice '1'.");
	}

	else
	{
		printf("\nLista dalla posizione '%d' indietro :\n", n);
		printf(" [");

		/* Ciclo for per incrementare "i" scorrendo gli elementi. */
		for(i=0; i<n-1; i++)
		{
			/* Il puntatore temp scorre gli elementi. */
			lista_t->temp = lista_t->temp->successivo;
		}

		while(lista_t->temp->precedente != NULL)
		{
			printf(" (Informazione: %d) ", lista_t->temp->info);
			lista_t->temp = lista_t->temp->precedente;
		}

		/* Stampa del primo elemento della lista. */
		printf(" (Informazione: %d) ] Testa ", lista_t->temp->info);
		printf("\n\t\tLunghezza della lista: %d.\n", lista_t->conto);

		printf("\nPremere un tasto per continuare...");
		getchar();
		svuota_buffer();
	}
}

/* "cancella_info()" acquisisce da tastiera un intero 
 * e visita la lista in cerca dell'informazione inserita.
 * Se l'informazione viene trovata in testa alla lista
 * 	la funzione utilizza "cancella_testa()" per eliminare 
 * 	l'elemento dalla lista.
 * Se l'informazione viene trovata in coda alla lista
 * 	invece verra utilizzata "cancella_coda()" per eliminare
 * 	l'elemento dalla lista
 * Se l'informazione non corrisponde ai puntatori di testa e coda
 * 	la funzione provvederà a cancellare l'elemento tramite "free()"
 *  	per poi ricollegare i puntatori.
 * Se infine l'informazione non è presente nella lista
 * 	questo verrà stampato a video. */
lista *cancella_info(lista *lista_t)
{
	/* Dichiarazione delle variabili. */
	int	esito;
	int	valore;		/* Variabile che conterrà l'informazione da eliminare. */
	int	i;		/* Variabile per verificare l'eliminazione di uno o più elementi. */

	/* Questa variabile manterrà il valore della lunghezza
	 * della lista prima dell'eleminazione di uno o più elementi. */
	i = lista_t->conto;
	lista_t->temp = lista_t->testa;		/* Il puntatore temp punta alla testa della lista. */	

	/* Se la lista è vuota non è possibile cancellare un'informazione. */
	if(lista_t->temp == NULL)
	{
		printf("\nLa lista è vuota.");
		printf("\nPremere un tasto per continuare...");
		getchar();
		svuota_buffer();

	}

	else

	/* Stampa per l'acquisizione del valore da eliminare. */
	do
	{
		printf("\nInserire l'informazione da eliminare:\t");
		/* Controllo dei caratteri inseriti. */
		esito = scanf("%d", &valore);
	
		if(esito != 1)
		{
			printf("\nPer favore, inserire un'informazione valida (un intero):\t");
			getchar();
			svuota_buffer();
		}
	}	while(esito != 1);

	while(lista_t->temp != NULL)
	{
		if(lista_t->temp->info != valore)
		{
			lista_t->temp = lista_t->temp->successivo;
		}

		else if(lista_t->temp->info == valore)
		{
			if(lista_t->temp == lista_t->testa && lista_t->temp->info == valore)
			{
				lista_t = cancella_testa(lista_t);
				/* Stampa a video della lunghezza della lista. */
				printf("\n\tNumero di nodi: %d.\n", lista_t->conto);				
			}	

			else if(lista_t->temp == lista_t -> coda && lista_t->temp->info == valore)
			{
				lista_t = cancella_coda(lista_t);

				/* Stampa a video della lunghezza della lista. */
				printf("\n\tNumero di nodi: %d.\n", lista_t->conto);
			}
		
			else if(lista_t->temp->precedente != NULL && lista_t->temp->successivo != NULL && lista_t->temp->info == valore)
			{
				(lista_t->temp->precedente)->successivo = lista_t->temp->successivo;
				(lista_t->temp->successivo)->precedente = lista_t->temp->precedente;
				free(lista_t->temp);

				/* Aggiorno la lunghezza della lista. */
				lista_t->conto -=1;
				printf("\nInforazione eliminata.");

				/* Stampa a video della lunghezza della lista. */
				printf("\n\tNumero di nodi: %d.\n", lista_t->conto);
			}
		}
	}

	/* Con questo ciclo è possibile stampare a video l'esito della funzione. */
	/* Se la lunghezza della lista è minore della lunghezza in principio. */				
	if(i > lista_t->conto)
	{
		printf("\nInformazione '%d' cancellata dalla lista.\n", valore);
	}

	/* Se la lunghezza non è cambiata, l'informazione non era presente in lista. */
	if(i == lista_t->conto)
	{
		printf("\nInformazione '%d' non presente in lista.\n", valore);
		printf("\nPremere un tasto per continuare...");
		getchar();
		svuota_buffer();

	}

	return(lista_t);
}

/* La funzione "crea()" viene chiamata per creare un nuovo elemento della lista.
 * L'utente digita un intero che sarà associato all'informazione del nuovo nodo.
 * Verrà allocato dello spazio in memoria della dimensione della struttura nodo.
 * La funzione inoltre inizializza i puntatori a NULL,
 * questi verranno poi rielaborati in base alla posizione del nodo. */
lista *crea(lista *lista_t)
{
	/* Dichiarazione delle variabili. */
	int	valore;		/* Variabile che conterrà l'intero da inserire nell'elemento. */
	int	risultato;	/* Variabile utile al controllo dei caratteri inseriti. */

	/* Alloco lo spazio per il nuovo elemento di tipo "nodo". */
 	lista_t->temp = (struct nodo_t *)malloc(sizeof(struct nodo_t));

	do
	{
		printf("\nInserisci informazione al nodo (intero) :");
		
		/* Controllo dei caratteri inseriti. */
		risultato = scanf("%d", &valore);
	
		if(risultato != 1)
		{
			printf("\nPer favore, inserire un intero:\t");
			getchar();
			svuota_buffer();
		}
	}	while(risultato != 1);

	{
	/* Viene riempito il campo "info" dell'elemento con la nuova informazione. */
		lista_t->temp->info = valore;

		/* Aggiorna la lunghezza della lista. */
		lista_t->conto +=1;
	}

	return(lista_t);
}

/* La funzione "cancella_testa()"si occupa di ricollegare i puntatori della lista
 * e di cancellare l'informazione in testa alla lista liberando lo spazio di memoria 
 * da essa occupato. */
lista *cancella_testa(lista *lista_t)
{
	/* Puntatore temp punta alla testa della lista. */
	lista_t->temp = lista_t->testa;

	/* Verifica che la lista non sia vuota. */
	if(lista_t->temp==NULL)
	{
		printf("\nLa lista è vuota.");
	}

	else
	{
		/* Verifico che la testa non sia anche la coda della lista. */
		if(lista_t->testa->successivo != NULL)
		{
			lista_t->testa = lista_t->temp->successivo;
			lista_t->temp->successivo->precedente = NULL;
			lista_t->testa = lista_t->temp->successivo;
			lista_t->conto -=1;
		}

		else
		{
			lista_t->testa = NULL;
			lista_t->conto-=1;
		}
	}

	/* Libero la memoria occupata da temp. */
	free(lista_t->temp);

	/* Stampa a video della avvenuta cancellazione. */
	printf("\nInformazione in testa cancellata dalla lista.");

	return(lista_t);
}

/* La funzione "cancella_coda()" si occupa di ricollegare i puntatori della lista
 * e di cancellare l'informazione in coda alla lista. */
lista * cancella_coda(lista *lista_t)
{

	/* Puntatore temp punta alla coda della lista. */
	lista_t->temp = lista_t->coda;

	/* Verifica che la lista non sia vuota. */
	if(lista_t->temp == NULL)
	{
		printf("\nLa lista è vuota.");
		printf("\nPremere un tasto per continuare...");
		getchar();
		svuota_buffer();
	}

	else
	{
		/* Verifica che l'elemento non sia anche la testa della lista. */
		if(lista_t->coda->precedente != NULL)
		{
			lista_t->coda =	lista_t->temp -> precedente;
			(lista_t->temp->precedente)->successivo = NULL;

			/* Aggiorno la lunghezza della lista. */
			lista_t->conto-=1;
		}

		else
		{
			lista_t->coda = lista_t -> temp -> precedente = NULL;
			lista_t->temp->successivo = NULL;
			lista_t->testa = lista_t->coda;

			/* Aggiorno la lunghezza della lista. */
			lista_t->conto-=1;
		}
	}

	/* Libero la memoria occupata da temp. */
	free(lista_t->temp);

	/* Stampa a video della avvenuta cancellazione. */
	printf("\nInformazione in coda cancellata dalla lista.");
	printf("\nPremere un tasto per continuare...");
	getchar();
	svuota_buffer();

	return(lista_t);
}
