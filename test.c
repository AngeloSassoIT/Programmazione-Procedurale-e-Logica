/* File sorgente "test.c". */

/* Inclusione delle librerie standard. */
#include <stdio.h>
#include <stdlib.h>

/* Inclusione della libreria per la gestione di una lista 
 * doppiamente concatenata. */
#include "lista_dc.h"

/* Dichiarazione delle funzioni. */
void	svuota_buffer();
lista	*inizializza(lista *);

/* Funzione principale "main()". */
int main()
{
	/* Dichiarazione delle variabili. */
	/* Variabile per la selezione della funzione. */
	int 	scelta;
	/* Variabile per la validazione stretta degli input. */
	int	esito;
	
	lista *elemento;
	elemento = (struct lista_t *)malloc(sizeof(struct lista_t));

	elemento -> temp = NULL;
	elemento -> testa = NULL;
	elemento -> aus = NULL;
	elemento -> coda = NULL;
	elemento -> conto = 0;


	elemento = inizializza(elemento);
	
	do
	{
			
       		/* Si procede alla stampa del menù di selezione. */
		printf("\n\n------MENÙ DI SELEZIONE------\n"); 
		printf(" 0) Esci.");
		printf("\n\t**INSERIMENTO**");
    		printf("\n 1) Inserisci in testa.");
    		printf("\n 2) Inserisci in coda.");
    		printf("\n 3) Inserisci prima di posizione 'i'.");
		printf("\n 4) Inserisci dopo di posizione 'i'.");
		printf("\n\t**RIMOZIONE**");
    		printf("\n 5) Cancella informazione.");
    		printf("\n 6) Cancella informazione in testa.");
    		printf("\n 7) Cancella informazione in coda.");
		printf("\n\t**VISITA**");
		printf("\n 8) Stampa da posizione a coda.");
		printf("\n 9) Stampa da posizione a testa.");

		printf("\n\nScelta:\t");

		do
		{
			esito = scanf("%d", &scelta);
		
			if(esito != 1 || scelta > 9 || scelta < 0)
			{
				printf("\nOperazione non consentita, ripetere la scelta.\n");
				printf("Inserire un intero compreso tra 0 e 9 (inclusi).\n");

				svuota_buffer();
			}

	       		switch (scelta)
       			{        		
				case 1:
					printf("\t- Inserimento in testa");
            				elemento = inserisci_testa(elemento);
            				break;
        			
				case 2:
					printf("\t- Inserimento in coda");
            				elemento = inserisci_coda(elemento);
            				break;
        			
				case 3:
					printf("\t- Inserimento prima di posizione");
            				elemento = inserisci_prima(elemento);
            				break;
			
				case 4:
					printf("\t- Inserimento dopo di posizione");
					elemento = inserisci_dopo(elemento);
					break;
        			
				case 5:
					printf("\t- Cancella informazione");
            				elemento = cancella_info(elemento);
            				break;
        		
				case 6:
					printf("\t- Cancella testa");
					elemento = cancella_testa(elemento);
            				break;
				
        			case 7: 
					printf("\t- Cancella coda");
					elemento = cancella_coda(elemento);
        	    			break;
        		
				case 8:
					printf("\t- Stampa da posizione a coda");
					stampa_avanti(elemento);
        				break;
					
				case 9:
					printf("\t- Stampa da posizione a testa"); 
					stampa_indietro(elemento);
            				break;
       			
				case 0:
					printf("\t- Chiusura");
					break;
			
				default:
					printf("\nRipetere la scelta:\t");
					break;
                  	
			}
		}	while (esito != 1 || scelta > 9 || scelta < 0);
	}	while (scelta != 0);

	printf("\nFine del programma di test.\n");
	return 0;
}

void	svuota_buffer()
{
	/* Variabile utile allo svuotamento del buffer. */
	char	carattere;

	do
	{
		carattere = getchar();
	}	while (carattere != '\n');
}

lista * inizializza(lista *lista_t)
{
	lista_t->temp = (struct nodo_t *)malloc(sizeof(struct nodo_t));
	lista_t-> temp -> precedente =  NULL;
	lista_t-> temp -> successivo = NULL;
	lista_t -> testa = lista_t -> coda = lista_t -> aus; /*= lista_t -> temp;*/

	return(lista_t);
}

