#include "conversoes.h"

//função que converte inteiro sinalizado para string (-32768 a 32767)
void IntToStr(int num, char * str) {

	int ordem; //ordem de grandeza
	char j = 0; //controle para não inserir zeros a esqueda

	//tratamento se o numero for negativo
	if(num<0) {
		*str = '-';
		num *= -1;
		str++;
	}

	//iteracoes com os digitos, convertendo para o correspondente na tabela ascii (+48)
	for(ordem=10000; ordem>=10; ordem/=10){

		//somente insere zeros no 'meio' do número
		if(num/ordem==0 && j==1) {
			*str = '0';
			str++;
		}
		else if(num/ordem>0) {
			*str = 48+num/ordem;
			num = num%ordem;
			str++;
			j = 1;
		}
	}

	//ultimo digito
	*str = 48+num;

	//insere caractere null no final
	str++;
	*str = 0;
}


//função que converte string para inteiro sinalizado (-32768 a 32767)
void StrToInt(char * str, int * num) {
	
	int pos = 0, ordem, mult = 1;
	*num = 0;

	//tratamento se o numero for negativo
	if(*str == '-') {
		pos--;
		mult = -1;
	}

	//busca pelo fim da string contabilizando os digitos (null)
	while(*str!=0) {
		str++;
		pos++;
	}

	ordem = (int)(pow(10,(double)(pos-1))); //registra a ordem de grandeza do numero

	//iteracoes com a string, somando o valor de cada caractere convertido para o valor decimal correspondente e multiplicado pela sua ordemde grandeza
	while(pos>0) {
		str--;
		pos--;
		*num += (ordem/(int)(pow(10,(double)pos))) * (*str-48);
	}

	*num *= mult; //aplica fator para -1 caso negativo ou 1 caso positivo
	
}


