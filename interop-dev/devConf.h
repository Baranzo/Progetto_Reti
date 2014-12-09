#include "interop_dev.h"
#define MAXSTRING 100


typedef struct dnsServAdd{
    char address[MAXSTRING];
};

typedef struct dnsServSearch{
    char domain[MAXSTRING];
};


typedef struct routingProto{
    char name[MAXSTRING];
    char version[MAXSTRING];
    char routerId[MAXSTRING];  //?nemesis
};


typedef struct phyDev{
    char name[MAXSTRING];
    int  chan;
    int  chanWidth;
    int  txPower;
};


typedef struct address{
    char adress[MAXSTRING];
    int  mask;
    char family[MAXSTRING];
    char proto[MAXSTRING];
};



typedef struct wireless{
    char phyDev[MAXSTRING];
    long int bitrate;
    int  ackDist;
    int  rtsThreshold;
    int  fragThreshold;
    char mode[MAXSTRING];
    char essid[MAXSTRING];
    char encryption[MAXSTRING];
};

typedef struct interface{
    char type[MAXSTRING];
    char name[MAXSTRING];
    char mac[MAXSTRING];
    int  mtu;
    int  txqueuelen;
    char carrier[MAXSTRING];
    char autostart[MAXSTRING];
};



typedef struct devConf{
    char hostname[MAXSTRING];
    char mantainer[MAXSTRING];
    char description[MAXSTRING];
    char manufacturer[MAXSTRING];
    char model[MAXSTRING];
    char modelRev[MAXSTRING];
    long int ram;
    char cpu[MAXSTRING];
    long int cpuFreq;
    long int flashMem;
    char osName[MAXSTRING];
    char osKernel[MAXSTRING];
    char osVersion[MAXSTRING];
    char osRevision[MAXSTRING];
    char osDescription[MAXSTRING];

    interface *intPtr;
     

};
