
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>


#include <jansson.h>


/* allora qui ci va una premessa, le strutture dati le ho buttate giù 
 * senza pensarci più di troppo e non sono sicuro sia il modo migliore di
 * impostare il lavoro, intanto faccio i test così poi vediamo. 
 * Sicuramente bisognerà fare degli enum per controllare che tutta la 
 * baracca vada per dove deve andare
*/ 
 

typedef struct ipAddr {
	
	char version[30];
	char addr[30];
	char scope[20];
	struct ipAddr *next;
	
}ipAddr;

typedef struct interface {
	
	char type[20];
	char ker_name[10];
	char mac_addr[20];
	char dev[30];
	struct interface *next;
	ipAddr *ip;
	
}interface;

typedef struct sys_info{
	
	char hostname[20];
	char os_name [20];
	char os_version [10];
	char manufacturer[30];
	int memory;
	interface *interfaces;
}sys_info;


sys_info* fill_dummy(sys_info *pt);
