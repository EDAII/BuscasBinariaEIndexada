#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

double calcula_tempo(const struct rusage *b, const struct rusage *a) {
    if (b == NULL || a == NULL)
        return 0;
    else
        return ((((a->ru_utime.tv_sec * 1000000 + a->ru_utime.tv_usec) -
                 (b->ru_utime.tv_sec * 1000000 + b->ru_utime.tv_usec)) +
                ((a->ru_stime.tv_sec * 1000000 + a->ru_stime.tv_usec) -
                 (b->ru_stime.tv_sec * 1000000 + b->ru_stime.tv_usec)))
                / 1000000.0);
}


int funcao(int x, int y,int z){
int i,j;
for(i=0;i<x;i++){
	for(j=0;j<y;j++){
		z++;
}
}
return z;
}

int main(){

struct rusage tempo_inicial, tempo_final;
double tempo;
int z;

getrusage(RUSAGE_SELF, &tempo_inicial);
     z = funcao(10000,10000,z);
    getrusage(RUSAGE_SELF, &tempo_final);

tempo = calcula_tempo(&tempo_inicial, &tempo_final);
printf("%d\n",z);
printf("%lf\n",tempo);
return 0;
}
