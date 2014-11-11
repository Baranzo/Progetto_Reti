#define PATH_SYS "/proc/meminfo"
#define DELIM " "
#define MAXBUF 100
int leggi (char *total, char *free)
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
	    if(strstr(free,"MemFree")){
		strtok_r(free,DELIM, &buf); 
		strcpy(free,strtok_r(NULL,DELIM, &buf)); 
	    }
	}
	return 0;
	


}



#define PATH_SYS "/proc/meminfo"
#define DELIM " "
#define MAXBUF 100
int leggi (char *total, char *free)
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
	    if(strstr(free,"MemFree")){
		strtok_r(free,DELIM, &buf); 
		strcpy(free,strtok_r(NULL,DELIM, &buf)); 
	    }
	}
	return 0;
	


}



