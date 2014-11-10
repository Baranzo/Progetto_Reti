
#include <stdio.h>
#include <string.h>

#define PATH_SYS "/proc/meminfo"
#define DELIM " "
#define MAXBUF 100
int main (int args, char *argv)
{

        FILE *fp;
        char s[MAXBUF];
	char *buf;
        if((fp=fopen(PATH_SYS, "r"))==NULL){
	                perror("Cannot open file!\n");
	                return -1;
	}

        while(fgets(s,MAXBUF,fp)) {
	    if(strstr(s,"MemTotal")){
		strtok_r(s,DELIM, &buf); 
		strcpy(s,strtok_r(NULL,DELIM, &buf)); 

                printf("Ho letto la riga: %s \n", s);	
	    }
	    if(strstr(s,"MemFree")){
		strtok_r(s,DELIM, &buf); 
		strcpy(s,strtok_r(NULL,DELIM, &buf)); 

                printf("Ho letto la riga: %s \n", s);	
	    }
	}
	return 0;
	


}



