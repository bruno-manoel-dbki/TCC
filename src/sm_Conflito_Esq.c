/*
 * sm_Conflito_Esq.c
 *
 *  Created on: Aug 22, 2017
 *
 *    Copyright 2017 Bruno Manoel Dobrovolski
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
	S0_S0_S0,
	S0_S0_S2,
	S0_S1_S0,
	S0_S1_S2,
	S0_S2_S0,
	S0_S2_S2,
	S0_S2_S3,
	S1_S0_S0,
	S1_S0_S2,
	S1_S1_S0,
	S1_S1_S2,
	S1_S2_S0,
	S1_S2_S2,
	S1_S2_S3,
	S2_S0_S2,
	S2_S1_S2,
	S2_S2_S2,
	S2_S2_S3,
	ST_FINAL,

}states_t;

struct{
	states_t state;
	Handle_c_dir_t handle;
	Action_c_dir_t Action[ST_FINAL];
}sm_C_Esq;

static int fn_S0_S0_S0(unsigned char data, int e)
{
	if(e)
	{
		if(data == ECdir_ON || data == ECesq_ON) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SCesq_ON)// SE DENTRO DO ALFABETO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{

		if(data == ECdir_ON)
		{
			sm_C_Esq.state = S0_S1_S0;
		}
		else if(data == ECesq_ON)
		{
			sm_C_Esq.state = S1_S0_S0;
		}

	}
	return sm_C_Esq.state;
}
static int fn_S0_S0_S2(unsigned char data, int e)
{
	if(e)
	{
		if(data == ECdir_ON || data == ECesq_ON) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SCesq_ON)// SE DENTRO DO ALFABETO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if(data == ECdir_ON)
		{
			sm_C_Esq.state = S0_S1_S2;
		}
		else if(data == ECesq_ON)
		{
			sm_C_Esq.state = S1_S0_S2;
		}
	}
	return sm_C_Esq.state;
}
static int fn_S0_S1_S0(unsigned char data, int e)
{
	if(e)
	{
		if(data == ECdir_OFF || data == SCdir_ON ||data == ECesq_ON) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SCesq_ON)// SE DENTRO DO ALFABETO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if(data == ECdir_OFF)
		{
			sm_C_Esq.state = S0_S0_S0;
		}
		else if(data == SCdir_ON)
		{
			sm_C_Esq.state = S0_S2_S0;
		}
		else if(data == ECesq_ON)
		{
			sm_C_Esq.state = S1_S1_S0;
		}
	}
	return sm_C_Esq.state;

}
static int fn_S0_S1_S2(unsigned char data, int e)
{
	if(e)
	{
		if(data == ECdir_OFF ||data == SCdir_ON || data == ECesq_ON) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SCesq_ON)// SE DENTRO DO ALFABETO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{

		if(data == ECdir_OFF)
		{
			sm_C_Esq.state = S0_S0_S2;
		}
		else if(data == SCdir_ON)
		{
			sm_C_Esq.state = S0_S2_S3;
		}
		else if(data == ECesq_ON)
		{
			sm_C_Esq.state = S1_S1_S2;
		}
	}
	return sm_C_Esq.state;
}
static int fn_S0_S2_S0(unsigned char data, int e)
{
	if(e)
	{
		if(data == ECdir_OFF||data == SCdir_ON || data == ECesq_ON) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SCesq_ON)// SE DENTRO DO ALFABETO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if(data == ECdir_OFF)
		{
			sm_C_Esq.state = S0_S0_S0;
		}
		else if(data == SCdir_OFF)
		{
			sm_C_Esq.state = S0_S1_S0;
		}
		else if( data == ECesq_ON)
		{
			sm_C_Esq.state = S1_S2_S0;
		}
	}
	return sm_C_Esq.state;
}
static int fn_S0_S2_S2(unsigned char data, int e)
{
	if(e)
	{
		if(data == ECdir_OFF || data == SCdir_OFF || data == ECesq_ON ) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SCesq_ON)// SE DENTRO DO ALFABETO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if(data == ECdir_OFF)
		{
			sm_C_Esq.state = S0_S0_S2;
		}
		else if(data == SCdir_OFF)
		{
			sm_C_Esq.state = S0_S1_S2;
		}
		else if(data == ECesq_ON)
		{
			sm_C_Esq.state = S1_S2_S2;
		}
	}
	return sm_C_Esq.state;
}
static int fn_S0_S2_S3(unsigned char data, int e)
{
	if(e)
	{
		if(data == ECdir_OFF || data == SCdir_OFF || data == ECesq_ON) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SCesq_ON)// SE DENTRO DO ALFABETO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if(data == ECdir_OFF)
		{
			sm_C_Esq.state = S0_S0_S2;
		}
		else if(data == SCdir_OFF)
		{
			sm_C_Esq.state = S0_S1_S2;
		}
		else if(data == ECesq_ON)
		{
			sm_C_Esq.state = S1_S2_S3;
		}
	}
	return sm_C_Esq.state;
}
static int fn_S1_S0_S0(unsigned char data, int e)
{
	if(e)
	{
		if(data == ECesq_OFF || data == ECdir_ON || data == SCesq_ON) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SCesq_ON)// SE DENTRO DO ALFABETO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if(data == ECesq_OFF)
		{
			sm_C_Esq.state = S0_S0_S0;
		}
		else if(data == ECdir_ON)
		{
			sm_C_Esq.state = S1_S1_S0;
		}
		else if(data == SCesq_ON)
		{
			sm_C_Esq.state = S2_S0_S2;
		}
	}
	return sm_C_Esq.state;
}
static int fn_S1_S0_S2(unsigned char data, int e)
{
	if(e)
	{
		if(data == ECesq_OFF || data == ECdir_ON || data == SCesq_ON) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SCesq_ON)// SE DENTRO DO ALFABETO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{

		if(data == ECesq_OFF)
		{
			sm_C_Esq.state = S0_S0_S2;
		}
		else if(data == ECdir_ON)
		{
			sm_C_Esq.state = S1_S1_S2;
		}
		else if(data == SCesq_ON )
		{
			sm_C_Esq.state = S2_S0_S2;
		}
	}
	return sm_C_Esq.state;
}
static int fn_S1_S1_S0(unsigned char data, int e)
{
	if(e)
	{
		if(data == ECesq_OFF || data == ECdir_OFF || data == SCdir_ON ||data == SCesq_ON) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SCesq_ON)// SE DENTRO DO ALFABETO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if(data == ECesq_OFF)
		{
			sm_C_Esq.state = S0_S1_S0;
		}
		else if(data == ECdir_OFF )
		{
			sm_C_Esq.state = S1_S0_S0;
		}
		else if(data == SCdir_ON)
		{
			sm_C_Esq.state =S1_S2_S0;
		}
		else if(data == SCesq_ON)
		{
			sm_C_Esq.state = S2_S1_S2;
		}
	}
	return sm_C_Esq.state;
}
static int fn_S1_S1_S2(unsigned char data, int e)
{
	if(e)
	{
		if(data == ECesq_OFF || data == ECdir_OFF || data == SCdir_ON || data == SCesq_ON) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SCesq_ON)// SE DENTRO DO ALFABETO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if(data == ECesq_OFF )
		{
			sm_C_Esq.state = S0_S1_S2;
		}
		else if(data == ECdir_OFF)
		{
			sm_C_Esq.state = S1_S0_S2;
		}
		else if(data ==SCdir_ON)
		{
			sm_C_Esq.state = S1_S2_S3;
		}
		else if(data ==SCesq_ON)
		{
			sm_C_Esq.state = S2_S1_S2;
		}
	}
	return sm_C_Esq.state;
}
static int fn_S1_S2_S0(unsigned char data, int e)
{
	if(e)
	{
		if(data == ECesq_OFF || data == ECdir_OFF || data == SCdir_OFF || data == SCesq_ON ) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SCesq_ON)// SE DENTRO DO ALFABETO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if(data == ECesq_OFF)
		{
			sm_C_Esq.state = S0_S2_S0;
		}
		else if(data == ECdir_OFF)
		{
			sm_C_Esq.state = S1_S0_S0;
		}
		else if(data ==SCdir_OFF)
		{
			sm_C_Esq.state = S1_S1_S0;
		}
		else if(data == SCesq_ON)
		{
			sm_C_Esq.state = S2_S2_S2;
		}
	}
	return sm_C_Esq.state;
}
static int fn_S1_S2_S2(unsigned char data, int e)
{
	if(e)
	{
		if(data == ECesq_OFF || data == ECdir_OFF || data == SCdir_OFF || data == SCesq_ON) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SCesq_ON)// SE DENTRO DO ALFABETO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if(data == ECesq_OFF)
		{
			sm_C_Esq.state = S0_S2_S2;
		}
		else if(data == ECdir_OFF)
		{
			sm_C_Esq.state = S1_S0_S2;
		}
		else if(data == SCdir_OFF)
		{
			sm_C_Esq.state = S1_S1_S2;
		}
		else if(data == SCesq_ON)
		{
			sm_C_Esq.state = S2_S2_S2;
		}
	}
	return sm_C_Esq.state;
}
static int fn_S1_S2_S3(unsigned char data, int e)
{
	if(e)
	{
		if(data == ECdir_OFF || data == SCdir_OFF || data == SCesq_ON ) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SCesq_ON)// SE DENTRO DO ALFABETO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if(data == ECdir_OFF)
		{
			sm_C_Esq.state = S1_S0_S2;
		}
		else if(data == SCdir_OFF)
		{
			sm_C_Esq.state = S1_S1_S2;
		}
		else if(data == SCesq_ON)
		{
			sm_C_Esq.state = S2_S2_S3;
		}
	}
	return sm_C_Esq.state;
}
static int fn_S2_S0_S2(unsigned char data, int e)
{
	if(e)
	{
		if(data == ECesq_OFF || data == SCesq_OFF || data == ECdir_ON) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SCesq_ON)// SE DENTRO DO ALFABETO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if(data == ECesq_OFF)
		{
			sm_C_Esq.state = S0_S0_S2;
		}
		else if(data == SCesq_OFF)
		{
			sm_C_Esq.state = S1_S0_S0;
		}
		else if(data == ECdir_ON)
		{
			sm_C_Esq.state = S2_S1_S2;
		}

	}
	return sm_C_Esq.state;
}
static int fn_S2_S1_S2(unsigned char data, int e)
{
	if(e)
	{
		if(data == ECesq_OFF || data == SCesq_OFF || data == ECdir_OFF || data == SCdir_ON ) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SCesq_ON)// SE DENTRO DO ALFABETO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{

		if(data == ECesq_OFF)
		{
			sm_C_Esq.state = S0_S1_S2;
		}
		else if(data == SCesq_OFF)
		{
			sm_C_Esq.state = S1_S1_S0;
		}
		else if(data == ECdir_OFF)
		{
			sm_C_Esq.state = S2_S0_S2;
		}
		else if(data == SCdir_ON)
		{
			sm_C_Esq.state = S2_S2_S3;
		}
	}
	return sm_C_Esq.state;
}
static int fn_S2_S2_S2(unsigned char data, int e)
{
	if(e)
	{
		if(data == ECesq_OFF || data == SCesq_OFF || data == ECdir_OFF || data == SCdir_OFF ) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SCesq_ON)// SE DENTRO DO ALFABETO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if(data == ECesq_OFF)
		{
			sm_C_Esq.state = S0_S2_S2;
		}
		else if(data == SCesq_OFF)
		{
			sm_C_Esq.state = S1_S2_S0;
		}
		else if(data == ECdir_OFF)
		{
			sm_C_Esq.state = S2_S0_S2;
		}
		else if(data == SCdir_OFF)
		{
			sm_C_Esq.state = S2_S1_S2;
		}
	}
	return sm_C_Esq.state;
}
static int fn_S2_S2_S3(unsigned char data, int e)
{
	if(e)
	{
		if( data == SCesq_OFF || data == ECdir_OFF || data == SCdir_OFF ) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> ECdir_OFF && data < SCesq_ON)// SE DENTRO DO ALFABETO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if(data == SCesq_OFF)
		{
			sm_C_Esq.state = S1_S2_S3;
		}
		else if(data == ECdir_OFF)
		{
			sm_C_Esq.state = S2_S0_S2;
		}
		else if(data == SCdir_OFF)
		{
			sm_C_Esq.state = S2_S1_S2;
		}
	}
	return sm_C_Esq.state;
}
void initSM_Conflito_Esq(Handle_c_dir_t handle)
{
	sm_C_Esq.Action[S0_S0_S0] = fn_S0_S0_S0;
	sm_C_Esq.Action[S0_S0_S2] = fn_S0_S0_S2;
	sm_C_Esq.Action[S0_S1_S0] = fn_S0_S1_S0;
	sm_C_Esq.Action[S0_S1_S2] = fn_S0_S1_S2;
	sm_C_Esq.Action[S0_S2_S0] = fn_S0_S2_S0;
	sm_C_Esq.Action[S0_S2_S2] = fn_S0_S2_S2;
	sm_C_Esq.Action[S0_S2_S3] = fn_S0_S2_S3;
	sm_C_Esq.Action[S1_S0_S0] = fn_S1_S0_S0;
	sm_C_Esq.Action[S1_S0_S2] = fn_S1_S0_S2;
	sm_C_Esq.Action[S1_S1_S0] = fn_S1_S1_S0;
	sm_C_Esq.Action[S1_S1_S2] = fn_S1_S1_S2;
	sm_C_Esq.Action[S1_S2_S0] = fn_S1_S2_S0;
	sm_C_Esq.Action[S1_S2_S2] = fn_S1_S2_S2;
	sm_C_Esq.Action[S1_S2_S3] = fn_S1_S2_S3;
	sm_C_Esq.Action[S2_S0_S2] = fn_S2_S0_S2;
	sm_C_Esq.Action[S2_S1_S2] = fn_S2_S1_S2;
	sm_C_Esq.Action[S2_S2_S2] = fn_S2_S2_S2;
	sm_C_Esq.Action[S2_S2_S3] = fn_S2_S2_S3;
	sm_C_Esq.state = S0_S0_S0;
	sm_C_Esq.handle = handle;

}

int ExecSM_Conflito_Esq(unsigned char data, int e)
{
	return sm_C_Esq.Action[sm_C_Esq.state](data, e);
}
