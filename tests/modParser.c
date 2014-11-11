#include "parser.h"

#define PATH_SYS "/proc/modules"
#define DELIM " "
int leggi (char *mod)
{

        FILE *fp;
	char *buf;
        if((fp=fopen(PATH_SYS, "r"))==NULL){
	                perror("Cannot open file!\n");
	                return -1;
	}

        while(fgets(s,MAXBUF,fp)) {
	    if(strstr(total,"MemTotal")){
		strtok_r(total,DELIM, &buf); 
		strcpy(total,strtok_r(NULL,DELIM, &buf)); 
	    }
	/*    if(strstr(free,"MemFree")){
		strtok_r(free,DELIM, &buf); 
		strcpy(free,strtok_r(NULL,DELIM, &buf)); 
	    }
	}
	*/
	return 0;
	
}

void main(){
	char modulo[MAXBUF]; 
	leggi(modulo);
}
