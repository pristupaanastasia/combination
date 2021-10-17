
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *copystr( char* s, int n, char* d){
    int i = 0;
    int j = 0;
    while(s[i] != '\0'){
        if (i != n){
            d[j] = s[i];
            j++;
        }
        i++;
    }
    d[j] = '\0';
    return d;
}

char *appendstr(char* s, int n, char* d){
    int i = 0;
    while (d[i] != '\0' && d[i] != 0){
         i++;
    }
    d[i] = s[n];
    d[i+1] = '\0';


    return d;
}

int recurs(char* s,  char* f){
    int i = 0;
    char *buf;
    char *p;

    if (f == NULL){
        f = (char*)malloc(strlen(s)+1);
        f[0] = 0;
        f[strlen(s)] = '\0';
    }


    if (strlen(s) == 0){
        printf("num : %s\n",f);
        free(s);
        free(f);
        return 1;
    }
    while( s[i]!='\0' && strlen(s) >i){

        buf = (char*)malloc(strlen(f)+1);
        buf = strcpy(buf,f);
        p = (char*) malloc(strlen(s) -1);
        buf = appendstr(s,i,buf);
        p = copystr(s,i,p);
        recurs(p,buf);
        i++;
    }

    return 0;
}

int main(int arc, char **argv)
{
    int		num;
    char *s;
    if (arc > 1){
        recurs(argv[1],NULL);

    }
    return (0);
}