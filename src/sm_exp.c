/*
 * sm1.c
 *
 *  Created on: Aug 22, 2017
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

 */
#include "../inc/sm.h"
#include <stdio.h>



typedef enum{
	S0_S0_S1_S1,
	S0_S0_S2_S2,
	S0_S1_S1_S1,
	S0_S1_S2_S2,
	S0_S2_S1_S1,
	S0_S2_S2_S2,
	S1_S0_S1_S1,
	S1_S0_S2_S2,
	S1_S1_S1_S1,
	S1_S1_S2_S2,
	S1_S2_S1_S1,
	S1_S2_S2_S2,
	S2_S0_S1_S1,
	S2_S0_S2_S2,
	S2_S1_S1_S1,
	S2_S1_S2_S2,
	S2_S2_S1_S1,
	S2_S2_S2_S2,
	ST_FINAL
}states_t;

struct{
	states_t state;
	Handle_exp_t handle;
	Action_exp_t Action[ST_FINAL];
}sm_Exp;


static int fn_S0_S0_S1_S1(unsigned char data, int e){
	if(e)
	{
		if(data == SEx_ON || data == ECdir_ON|| data == ECesq_ON) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SEx_OFF)// SE DENTRO DO ALFABETO E DESABILITADO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if( data == SEx_ON)
		{
			sm_Exp.state =S0_S0_S2_S2 ;
		}
		else if( data == ECdir_ON)
		{
			sm_Exp.state =S0_S1_S1_S1 ;
		}
		else if( data == ECesq_ON)
		{
			sm_Exp.state =S1_S0_S1_S1 ;
		}



	}
	return sm_Exp.state;

}
static int fn_S0_S0_S2_S2(unsigned char data, int e){
	if(e)
	{
		if(data ==  SEx_OFF) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SEx_OFF)// SE DENTRO DO ALFABETO E DESABILITADO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if( data == SEx_OFF)
		{
			sm_Exp.state = S0_S0_S1_S1;
		}

	}
	return sm_Exp.state;

}
static int fn_S0_S1_S1_S1(unsigned char data, int e){
	if(e)
	{
		if(data == ECdir_OFF || data == SEx_ON|| data == SCdir_ON|| data == ECesq_ON) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SEx_OFF)// SE DENTRO DO ALFABETO E DESABILITADO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if( data == ECdir_OFF )
		{
			sm_Exp.state = S0_S0_S1_S1;
		}
		else if( data == SEx_ON)
		{
			sm_Exp.state = S0_S1_S2_S2 ;
		}
		else if( data == SCdir_ON)
		{
			sm_Exp.state = S0_S2_S1_S1;
		}
		else if( data == ECesq_ON)
		{
			sm_Exp.state = S1_S1_S1_S1;
		}
	}
	return sm_Exp.state;

}
static int fn_S0_S1_S2_S2(unsigned char data, int e){
	if(e)
	{
		if(data == ECdir_OFF || data == SEx_OFF|| data == SCdir_ON ) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SEx_OFF)// SE DENTRO DO ALFABETO E DESABILITADO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if( data == ECdir_OFF)
		{
			sm_Exp.state = S0_S0_S2_S2;
		}
		else if( data == SEx_OFF)
		{
			sm_Exp.state = S0_S1_S1_S1;
		}
		else if( data == SCdir_ON)
		{
			sm_Exp.state = S0_S2_S2_S2;
		}
	}
	return sm_Exp.state;

}
static int fn_S0_S2_S1_S1(unsigned char data, int e){
	if(e)
	{
		if(  data == ECdir_OFF || data == SCdir_OFF || data == SEx_ON|| data ==ECesq_ON) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SEx_OFF)// SE DENTRO DO ALFABETO E DESABILITADO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if( data == ECdir_OFF)
		{
			sm_Exp.state = S0_S0_S1_S1;
		}
		else if( data == SCdir_OFF)
		{
			sm_Exp.state = S0_S1_S1_S1;
		}
		else if( data == SEx_ON)
		{
			sm_Exp.state = S0_S2_S2_S2;
		}
		else if( data == ECesq_ON)
		{
			sm_Exp.state = S1_S2_S1_S1;
		}
	}
	return sm_Exp.state;

}
static int fn_S0_S2_S2_S2(unsigned char data, int e){
	if(e)
	{
		if(data == ECdir_OFF|| data == SCdir_OFF|| data ==SEx_OFF ) //SE FOR EVENTO HABILITADO

			return OK;
		else if(data> ECdir_OFF && data < SEx_OFF)// SE DENTRO DO ALFABETO E DESABILITADO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if( data == ECdir_OFF )
		{
			sm_Exp.state =S0_S0_S2_S2 ;
		}
		else if( data == SCdir_OFF )
		{
			sm_Exp.state = S0_S1_S2_S2;
		}
		else if( data == SEx_OFF)
		{
			sm_Exp.state = S0_S2_S1_S1;
		}
	}
	return sm_Exp.state;

}
static int fn_S1_S0_S1_S1(unsigned char data, int e){
	if(e)
	{
		if(data ==  ECesq_OFF|| data == SEx_ON|| data ==ECdir_ON || data ==SCesq_ON) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SEx_OFF)// SE DENTRO DO ALFABETO E DESABILITADO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if( data == ECesq_OFF)
		{
			sm_Exp.state = S0_S0_S1_S1;
		}
		else if( data == SEx_ON)
		{
			sm_Exp.state = S1_S0_S2_S2;
		}
		else if( data == ECdir_ON)
		{
			sm_Exp.state = S1_S1_S1_S1;
		}
		else if( data == SCesq_ON)
		{
			sm_Exp.state = S2_S0_S1_S1;
		}
	}
	return sm_Exp.state;

}
static int fn_S1_S0_S2_S2(unsigned char data, int e){
	if(e)
	{
		if(data ==  ECesq_OFF|| data == SEx_OFF|| data ==SCesq_ON) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SEx_OFF)// SE DENTRO DO ALFABETO E DESABILITADO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if( data == ECesq_OFF)
		{
			sm_Exp.state = S0_S0_S2_S2;
		}
		else if( data == SEx_OFF)
		{
			sm_Exp.state = S1_S0_S1_S1;
		}
		else if( data == SCesq_ON)
		{
			sm_Exp.state = S2_S0_S2_S2;
		}
	}
	return sm_Exp.state;

}
static int fn_S1_S1_S1_S1(unsigned char data, int e){
	if(e)
	{
		if(data == ECesq_OFF || data == ECdir_OFF || data == SEx_ON || data ==SCdir_ON || data == SCesq_ON) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SEx_OFF)// SE DENTRO DO ALFABETO E DESABILITADO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if( data == ECesq_OFF)
		{
			sm_Exp.state = S0_S1_S1_S1;
		}
		else if( data == ECdir_OFF)
		{
			sm_Exp.state = S1_S0_S1_S1;
		}
		else if( data == SEx_ON)
		{
			sm_Exp.state = S1_S1_S2_S2;
		}
		else if( data == SCdir_ON)
		{
			sm_Exp.state = S1_S2_S1_S1;
		}
		else if( data == SCesq_ON)
		{
			sm_Exp.state = S2_S1_S1_S1 ;
		}
	}
	return sm_Exp.state;

}
static int fn_S1_S1_S2_S2(unsigned char data, int e){
	if(e)
	{
		if(data == ECesq_OFF || data == ECdir_OFF|| data == SEx_OFF|| data == SCdir_ON || data == SCesq_ON) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SEx_OFF)// SE DENTRO DO ALFABETO E DESABILITADO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if( data == ECesq_OFF)
		{
			sm_Exp.state = S0_S1_S2_S2;
		}
		else if( data == ECdir_OFF)
		{
			sm_Exp.state =S1_S0_S2_S2;
		}
		else if( data == SEx_OFF)
		{
			sm_Exp.state = S1_S1_S1_S1;
		}
		else if( data == SCdir_ON)
		{
			sm_Exp.state =SCesq_ON;
		}

	}
	return sm_Exp.state;

}
static int fn_S1_S2_S1_S1(unsigned char data, int e){
	if(e)
	{
		if(data == ECesq_OFF || data == ECdir_OFF|| data ==SCdir_OFF || data == SEx_ON || data == SCesq_ON) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SEx_OFF)// SE DENTRO DO ALFABETO E DESABILITADO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if( data == ECesq_OFF)
		{
			sm_Exp.state = S0_S2_S1_S1;
		}
		else if( data == ECdir_OFF)
		{
			sm_Exp.state =S1_S0_S1_S1;
		}
		else if( data == SCdir_OFF)
		{
			sm_Exp.state =S1_S1_S1_S1;
		}
		else if( data == SEx_ON)
		{
			sm_Exp.state =S1_S2_S2_S2;
		}
		else if( data == SCesq_ON)
		{
			sm_Exp.state = S2_S2_S1_S1;
		}





	}
	return sm_Exp.state;

}
static int fn_S1_S2_S2_S2(unsigned char data, int e){
	if(e)
	{
		if(data == ECesq_OFF || data == ECdir_OFF|| data == SCdir_OFF|| data == SEx_OFF || data == SCesq_ON) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SEx_OFF)// SE DENTRO DO ALFABETO E DESABILITADO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if( data == ECesq_OFF)
		{
			sm_Exp.state = S0_S2_S2_S2;
		}
		else if( data == ECdir_OFF)
		{
			sm_Exp.state =S1_S0_S2_S2;
		}
		else if( data == SCdir_OFF)
		{
			sm_Exp.state = S1_S1_S2_S2;
		}
		else if( data == SEx_OFF)
		{
			sm_Exp.state = S1_S2_S1_S1;
		}
		else if( data == SCesq_ON)
		{
			sm_Exp.state = S2_S2_S2_S2;
		}





	}
	return sm_Exp.state;

}
static int fn_S2_S0_S1_S1(unsigned char data, int e){
	if(e)
	{
		if(data == ECesq_OFF || data == SCesq_OFF|| data == SEx_ON|| data == ECdir_ON) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SEx_OFF)			// SE DENTRO DO ALFABETO E DESABILITADO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if( data == ECesq_OFF )
		{
			sm_Exp.state = S0_S0_S1_S1;
		}
		else if( data == SCesq_OFF)
		{
			sm_Exp.state =S1_S0_S1_S1;
		}
		else if( data == SEx_ON)
		{
			sm_Exp.state = S2_S0_S2_S2;
		}
		else if( data == ECdir_ON)
		{
			sm_Exp.state =S2_S1_S1_S1;
		}
	}
	return sm_Exp.state;

}
static int fn_S2_S0_S2_S2(unsigned char data, int e){
	if(e)
		{
			if(data ==  ECesq_OFF|| data == SCesq_OFF|| data == SEx_OFF) //SE FOR EVENTO HABILITADO
				return OK;
			else if(data> ECdir_OFF && data < SEx_OFF)// SE DENTRO DO ALFABETO E DESABILITADO
				return NOK; //NÃO HABILITADO

			return OUT; //SE FORA DO ALFABETO
		}
		else
		{
			if( data == ECesq_OFF)
			{
				sm_Exp.state = S0_S0_S2_S2;
			}
			else if( data == SCesq_OFF)
			{
				sm_Exp.state = S1_S0_S2_S2;
			}
			else if( data == SEx_OFF)
			{
				sm_Exp.state =S2_S0_S1_S1;
			}
		}
		return sm_Exp.state;
}
static int fn_S2_S1_S1_S1(unsigned char data, int e){
	if(e)
	{
		if(data ==  ECesq_OFF|| data == SCesq_OFF|| data == ECdir_OFF|| data == SEx_ON || data == SCdir_ON) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SEx_OFF)// SE DENTRO DO ALFABETO E DESABILITADO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if( data == ECesq_OFF)
		{
			sm_Exp.state = S0_S1_S1_S1;
		}
		else if( data == SCesq_OFF)
		{
			sm_Exp.state = S1_S1_S1_S1;
		}
		else if( data == ECdir_OFF)
		{
			sm_Exp.state = S2_S0_S1_S1;
		}
		else if( data == SEx_ON)
		{
			sm_Exp.state = S2_S1_S2_S2;
		}
		else if( data == SCdir_ON)
		{
			sm_Exp.state = S2_S2_S1_S1;
		}
	}
	return sm_Exp.state;

}
static int fn_S2_S1_S2_S2(unsigned char data, int e){
	if(e)
	{
		if(data ==  ECesq_OFF|| data == SCesq_OFF|| data == ECdir_OFF|| data == SEx_OFF || data == SCdir_ON) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SEx_OFF)// SE DENTRO DO ALFABETO E DESABILITADO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if( data == ECesq_OFF)
		{
			sm_Exp.state = S0_S1_S2_S2;
		}
		else if( data == SCesq_OFF)
		{
			sm_Exp.state = S1_S1_S2_S2;
		}
		else if( data == ECdir_OFF)
		{
			sm_Exp.state = S2_S0_S2_S2;
		}
		else if( data == SEx_OFF)
		{
			sm_Exp.state = S2_S1_S1_S1;
		}
		else if( data == SCdir_ON)
		{
			sm_Exp.state = S2_S2_S2_S2;
		}
	}
	return sm_Exp.state;

}
static int fn_S2_S2_S1_S1(unsigned char data, int e){
	if(e)
	{
		if(data == ECesq_OFF || data == SCesq_OFF|| data == ECdir_OFF|| data == SCdir_OFF || data == SEx_ON) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SEx_OFF)// SE DENTRO DO ALFABETO E DESABILITADO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if( data == ECesq_OFF)
		{
			sm_Exp.state = S0_S2_S1_S1;
		}
		else if( data == SCesq_OFF)
		{
			sm_Exp.state = S1_S2_S1_S1;
		}
		else if( data == ECdir_OFF)
		{
			sm_Exp.state = S2_S0_S1_S1;
		}
		else if( data == SCdir_OFF)
		{
			sm_Exp.state = S2_S1_S1_S1;
		}
		else if( data == SEx_ON)
		{
			sm_Exp.state = S2_S2_S2_S2;
		}
	}
	return sm_Exp.state;

}
static int fn_S2_S2_S2_S2(unsigned char data, int e){
	if(e)
	{
		if(data ==  ECesq_OFF|| data == SCesq_OFF|| data == ECdir_OFF || data == SCdir_OFF || data == SEx_OFF) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SEx_OFF)// SE DENTRO DO ALFABETO E DESABILITADO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if( data == ECesq_OFF)
		{
			sm_Exp.state = S0_S2_S2_S2;
		}
		else if( data == SCesq_OFF)
		{
			sm_Exp.state = S2_S0_S2_S2;
		}
		else if( data == ECdir_OFF)
		{
			sm_Exp.state = S2_S0_S2_S2;
		}
		else if( data == SCdir_OFF)
		{
			sm_Exp.state = S2_S1_S2_S2;
		}
		else if( data == SEx_OFF)
		{
			sm_Exp.state =S2_S2_S1_S1;
		}



	}
	return sm_Exp.state;

}

void initSM_Expedicao(Handle_exp_t handle)
{
	sm_Exp.Action[S0_S0_S1_S1] = fn_S0_S0_S1_S1;
	sm_Exp.Action[S0_S0_S2_S2] = fn_S0_S0_S2_S2;
	sm_Exp.Action[S0_S1_S1_S1] = fn_S0_S1_S1_S1;
	sm_Exp.Action[S0_S1_S2_S2] = fn_S0_S1_S2_S2;
	sm_Exp.Action[S0_S2_S1_S1] = fn_S0_S2_S1_S1;
	sm_Exp.Action[S0_S2_S2_S2] = fn_S0_S2_S2_S2;
	sm_Exp.Action[S1_S0_S1_S1] = fn_S1_S0_S1_S1;
	sm_Exp.Action[S1_S0_S2_S2] = fn_S1_S0_S2_S2;
	sm_Exp.Action[S1_S1_S1_S1] = fn_S1_S1_S1_S1;
	sm_Exp.Action[S1_S1_S2_S2] = fn_S1_S1_S2_S2;
	sm_Exp.Action[S1_S2_S1_S1] = fn_S1_S2_S1_S1;
	sm_Exp.Action[S1_S2_S2_S2] = fn_S1_S2_S2_S2;
	sm_Exp.Action[S2_S0_S1_S1] = fn_S2_S0_S1_S1;
	sm_Exp.Action[S2_S0_S2_S2] = fn_S2_S0_S2_S2;
	sm_Exp.Action[S2_S1_S1_S1] = fn_S2_S1_S1_S1;
	sm_Exp.Action[S2_S1_S2_S2] = fn_S2_S1_S2_S2;
	sm_Exp.Action[S2_S2_S1_S1] = fn_S2_S2_S1_S1;
	sm_Exp.Action[S2_S2_S2_S2] = fn_S2_S2_S2_S2;
	sm_Exp.state = S0_S0_S1_S1;
	sm_Exp.handle = handle;

}

int ExecSM_Expedicao(unsigned char data, int e)
{
	return sm_Exp.Action[sm_Exp.state](data, e);
}
