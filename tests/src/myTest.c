/*
 * myTest.c
 * 
 * Copyright 2014 thegamer <thegamer@littlewhite> baranzo <baranzo@Yuna>
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
 
#include "myTest.h"


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
	
	
	
	json_t *arr,*arr2;
	json_t *intf,*ip;
	

	size_t i=0;
	arr=json_array();

	//primo livello
	intf=json_object();
	json_object_set(intf,"type",json_string("wireless"));
	json_object_set(intf,"name",json_string("wifi0"));
	json_array_insert_new(arr,i,intf);
	
		//secondo livello
		arr2=json_array();
		ip=json_object();
		json_object_set(ip,"address",json_string("192.168.0.1"));
		json_object_set(ip,"scope",json_string("local"));
		json_array_insert_new(arr2,i,ip);
	
		//secondo livello
		ip=json_object();
		json_object_set(ip,"address",json_string("130.136.42.1"));
		json_object_set(ip,"scope",json_string("link"));
		json_array_insert_new(arr2,i,ip);


	json_object_set_new(intf,"ip",arr2);

	
	
	//primo livello
	intf=json_object();
	json_object_set(intf,"type",json_string("physical"));
	json_object_set(intf,"name",json_string("eth0"));
	json_array_insert_new(arr,i,intf);
	
	json_object_set_new(json,"interfaces",arr);
	
	
	
	
	printf("%s \n",json_dumps(json,0));
	
	/* metti 0 in fondo a json_dumps per farlo iterare per tutto il json
	 * che gli passi
	*/
	
	//stessa storia di sopra ma con output su file
	json_dump_file(json,"../test.json",0);
		
	return 0;
}

