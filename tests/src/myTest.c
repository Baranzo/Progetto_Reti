/*
 * myTest.c
 * 
 * Copyright 2014 baranzo <baranzo@Yuna>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


/*LEGGI QUI NON SONO LE MENATE INIZIALI!!!!!!!!!!!!!!!
 * ho buttato giù un semplice test che è ancora incompleto giusto per 
 * iniziare a familiarizzare con la libreria, appena riesco faccio le 
 * prove con i dati annidati, ma prima bisognerà scrivere le macro 
 * e io non sono molto capace con le macro anzi... ne ho scritte 
 * veramente poche quindi devo rivedere un po' di cose
*/
 

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



//dummy del piffero, intanto provo ste benedette funzioni
sys_info* fill_dummy(sys_info *pt)
{
	interface *intf;
	ipAddr *ip;
	
	pt=(sys_info*)malloc(sizeof(sys_info));
	intf=(interface*)malloc(sizeof(interface));
	ip=(ipAddr*)malloc(sizeof(ipAddr));
	
	strcpy(pt->hostname,"BaranzoDummy");
	strcpy(pt->os_name,"Baranzian");
	strcpy(pt->os_version,"0.0.0");
	strcpy(pt->manufacturer,"BaranzoCorp.");
	pt->memory=65536;
	
	
	strcpy(intf->type,"optical");
	strcpy(intf->ker_name,"opt0");
	strcpy(intf->mac_addr,"ab:cd:ef:00:11:22");
	strcpy(intf->dev, "optif0");
	
	strcpy(ip->addr,"192.168.0.1");
	strcpy(ip->scope,"link");
	strcpy(ip->version,"IPv4");
	
	pt->interfaces=intf;
	intf->ip=ip;
	
	return pt;
	
}

/* qua bisogna decidere se uno vuole fare il json tutto in una botta o 
 * se è preferibile farlo in maniera separata. Io lo farei separato
 * perchè poi con una funzione semplice sembra sia possibile fare il join
 * di più json e quindi se c'è un errore annidato o un bug è più facile 
 * tracciarlo
*/ 
void sys_json (json_t *json,sys_info *pt)
{
	char str[30];
	json_t *tmp;
	
	
	strcpy(str,pt->hostname);
	tmp=json_string(str);
	json_object_set_new(json,"name",tmp);
	
	strcpy(str,pt->os_name);
	tmp=json_string(str);
	json_object_set_new(json,"os",tmp);
	
	strcpy(str,pt->os_version);
	tmp=json_string(str);
	json_object_set_new(json,"os_version",tmp);
	
	strcpy(str,pt->manufacturer);
	tmp=json_string(str);
	json_object_set_new(json,"manufacturer",tmp);
	
	
	json_object_set_new(json,"memory",json_integer((json_int_t)pt->memory));
}

int main(int argc, char **argv)
{
	
	sys_info *dummy=NULL;
	
	dummy=fill_dummy(dummy);
	json_t *json;
	
	//inizializzo il json
	if(!(json=json_object()))
	{
		perror("inizializzazione json");
		return -1;
	}

	//inizializzo il json con i valori del dummy per vedere cosa combina
	sys_json(json,dummy);
	
	
	printf("%s \n",json_dumps(json,0));
	
	/* metti 0 in fondo a json_dumps per farlo iterare per tutto il json
	 * che gli passi
	*/
	
	/* c'è già la funzione per fare il dump su file se vogliamo 
	 * piazzarlo su file direttamente
	 *json_dump_file(...);
	*/ 
	return 0;
}

