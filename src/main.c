/*
 * main.c
 *
 *  Created on: 4 de abr de 2017
 *
 *   Copyright 2017 Bruno Manoel Dobrovolski
 *
 *     This file is part of TCC.
 *
 *
 *   TCC is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   TCC is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *

 *
 *
 *		MODELO PADRÃO DE FUNÇÃO
static int fn_S0_S0_S1_S1(unsigned char data, int e){
	if(e)
	{
		if(data ==  || data == || data == || data ==) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SEx_OFF)// SE DENTRO DO ALFABETO E DESABILITADO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if( data == )
		{
			sm.state = ;
		}

	}
	return sm.state;

}
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#include "../inc/sm.h"



//unsigned char data1[] = {};
//unsigned char data2[] = {};
unsigned int data1;
unsigned int data2;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;


void Handler(unsigned char *string)
{

	//printf("%c", string);
}


void *inc_x(void *x_void_ptr)
{
	while(1)
	{
		int rand_num = rand()%4;
		int rand_num2 = rand_num+8;
		//printf("\n %d - %d \n", rand_num, rand_num2);
		pthread_mutex_lock(&mtx);

		if( ExecSM_Linha(rand_num, 1) > NOK && ExecSM_Conflito_Dir(rand_num2, 1) > NOK  && ExecSM_Conflito_Esq(rand_num2, 1) > NOK &&  ExecSM_Expedicao(rand_num2,1) > NOK)
		{
				printf("INPUT: Random\n");			
				printf("Linha 1 -\t%d\n", ExecSM_Linha(rand_num,0));
				printf("Conflito Dir -\t%d \n", ExecSM_Conflito_Dir(rand_num2,0));
				printf("Conflito Esq -\t%d \n", ExecSM_Conflito_Esq(rand_num2,0));
				printf("Expedicao -\t%d \n", ExecSM_Expedicao(rand_num2,0));

		}	
//		else
	//		printf(" \tnok");	
		pthread_mutex_unlock(&mtx);
	sleep(1);
	}
	return NULL;
}


int main ()
{
	srand(time(NULL));
	/* this variable is our reference to the second thread */
	pthread_t inc_x_thread;
	int x =0;

	/* create a second thread which executes inc_x(&x) */
	if(pthread_create(&inc_x_thread, NULL, inc_x, &x)) {

		fprintf(stderr, "Error creating thread\n");
		return 1;

	}



	initSM_Linha((Handle_lin_t)Handler);
	initSM_Conflito_Dir((Handle_c_dir_t)Handler);
	initSM_Conflito_Esq((Handle_c_esq_t)Handler);
	initSM_Expedicao((Handle_exp_t)Handler);
	while(1)
	{

		puts("INPUT: ");
		fflush(stdin);
		scanf("%d", &data1);

		//QUANDO PASSADO O PARAMETRO 1 PARA A FUNCAO ExecSM_X A FUNCAO TESTA SE O EVENTO É HABILITADO PARA A EXECUCAO, CASO SEJA, RETORNA 1
		pthread_mutex_lock(&mtx);
		if( ExecSM_Linha(data1, 1) > NOK && ExecSM_Conflito_Dir(data1, 1) > NOK  && ExecSM_Conflito_Esq(data1, 1) > NOK &&  ExecSM_Expedicao(data1,1) > NOK)
		{

			printf("Linha 1 -\t%d\n", ExecSM_Linha(data1,0));
			printf("Conflito Dir -\t%d \n", ExecSM_Conflito_Dir(data1,0));
			printf("Conflito Esq -\t%d \n", ExecSM_Conflito_Esq(data1,0));
			printf("Expedicao -\t%d \n", ExecSM_Expedicao(data1,0));


		}
		pthread_mutex_unlock(&mtx);

	}
	/* wait for the second thread to finish */
	if(pthread_join(inc_x_thread, NULL)) 
	{
		fprintf(stderr, "Error joining thread\n");
		return 2;
	}

	return 0;
}
