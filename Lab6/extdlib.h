#ifndef EXTDLIB
#define EXTDLIB

#include <stdio.h>
#include <stdlib.h>

#define new(type)           (type*)malloc_s(sizeof(type))
#define make(type,len)      (type*)malloc_s(sizeof(type)*(len))
#define check(expr,error)   if(!(expr)){fprintf(stderr,"Error:%s\n",error);exit(1);}
#define mat_Del(ptr,len)    {for(int i=0;i<(len);i++)free((ptr)[i]);free((ptr));}
#define fgetln(file,buf)    (fgets(buf,sizeof(buf),file),buf[strlen(buf)-1]=0,buf)

void *malloc_s(size_t size);

#endif