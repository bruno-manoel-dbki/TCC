/*
 * sm_Lin1.c
 *
 *  Created on: Aug 22, 2017
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
#include <stdio.h>
#include "../inc/sm.h"

typedef enum{
	S0_S0_S0,
	S0_S1_S0,
	S0_S2_S1,
	S1_S0_S0,
	S1_S1_S0,
	S1_S2_S1,
	S2_S0_S2,
	S2_S1_S2,
	S2_S2_S3,
	ST_FINAL,
}states_t;


struct{
	states_t state;
	Handle_lin_t handle;
	Action_lin_t Action[ST_FINAL];
}sm_Lin;


static int fn_S0_S0_S0(unsigned char data, int e)
{
	if(e)
	{
		if(data == EC1_ON || data == EL1_ON) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> EC1_OFF && data<SL1_ON)// SE NÃO HABILITADO
			return NOK;
		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if( data ==EC1_ON)
		{
			sm_Lin.state = S1_S0_S0;
		}
		else if( data ==EL1_ON)
		{
			sm_Lin.state = S0_S1_S0;
		}

	}
	return sm_Lin.state;
}
static int fn_S0_S1_S0(unsigned char data, int e)
{
	if(e)
	{
		if(data == EC1_ON || data == SL1_ON || data == EL1_OFF) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> EC1_OFF && data<SL1_ON)// SE NÃO HABILITADO
			return NOK;
		return OUT; //SE FORA DO ALFABETO
	}
	else
	{

		if( data ==EC1_ON)
		{
			sm_Lin.state = S1_S1_S0;
		}
		else if( data ==SL1_ON)
		{
			sm_Lin.state = S0_S2_S1;
		}
		else if(data == EL1_OFF)
		{
			sm_Lin.state = S0_S0_S0;
		}
	}
	return sm_Lin.state;
}
static int fn_S0_S2_S1(unsigned char data, int e)
{

	if(e)
	{
		if(data == EC1_ON || data == SL1_OFF) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> EC1_OFF && data<SL1_ON)// SE NÃO HABILITADO
			return NOK;
		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if( data ==EC1_ON)
		{
			sm_Lin.state = S1_S2_S1;
		}
		else if( data ==SL1_OFF)
		{
			sm_Lin.state = S0_S1_S0;
		}
	}
	return sm_Lin.state;
}
static int fn_S1_S0_S0(unsigned char data, int e)
{
	if(e)
	{
		if(data == EC1_OFF || data == EL1_ON || data == SC1_ON) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> EC1_OFF && data<SL1_ON)// SE NÃO HABILITADO
			return NOK;
		return OUT; //SE FORA DO ALFABETO
	}
	else
	{

		if( data ==EC1_OFF)
		{
			sm_Lin.state = S0_S0_S0;
		}
		else if( data ==EL1_ON)
		{
			sm_Lin.state = S1_S1_S0;
		}
		else if( data ==SC1_ON)
		{
			sm_Lin.state = S2_S0_S2;
		}
	}
	return sm_Lin.state;
}
static int fn_S1_S1_S0(unsigned char data, int e)
{
	if(e)
	{
		if(data == EC1_OFF || data == SC1_ON || data == SL1_ON || data == EL1_OFF) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> EC1_OFF && data<SL1_ON)// SE NÃO HABILITADO
			return NOK;
		return OUT; //SE FORA DO ALFABETO
	}
	else
	{

		if( data ==EC1_OFF)
		{
			sm_Lin.state = S0_S1_S0;
		}
		else if( data ==SC1_ON)
		{
			sm_Lin.state = S2_S1_S2;
		}
		else if( data ==SL1_ON)
		{
			sm_Lin.state = S1_S2_S1;
		}
		else if(data == EL1_OFF)
		{
			sm_Lin.state = S1_S0_S0;
		}
	}
	return sm_Lin.state;
}
static int fn_S1_S2_S1(unsigned char data, int e)
{
	if(e)
	{
		if(data == SC1_ON || data == SL1_OFF) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> EC1_OFF && data<SL1_ON)// SE NÃO HABILITADO
			return NOK;
		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if( data ==SC1_ON)
		{
			sm_Lin.state = S2_S2_S3;
		}
		else if( data ==SL1_OFF)
		{
			sm_Lin.state = S1_S1_S0;
		}
	}
	return sm_Lin.state;
}
static int fn_S2_S0_S2(unsigned char data, int e)
{
	if(e)
	{
		if(data == EL1_ON || data == SC1_OFF) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> EC1_OFF && data<SL1_ON)// SE NÃO HABILITADO
			return NOK;
		return OUT; //SE FORA DO ALFABETO
	}
	else
	{

		if(data ==EL1_ON)
		{
			sm_Lin.state = S2_S1_S2;
		}
		else if(data ==SC1_OFF)
		{
			sm_Lin.state = S1_S0_S0;
		}
	}
	return sm_Lin.state;
}
static int fn_S2_S1_S2(unsigned char data, int e)
{
	if(e)
	{
		if(data == SC1_OFF || data == SL1_ON) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> EC1_OFF && data<SL1_ON)// SE NÃO HABILITADO
			return NOK;
		return OUT; //SE FORA DO ALFABETO
	}
	else
	{
		if( data ==SC1_OFF)
		{
			sm_Lin.state = S1_S1_S0;
		}
		else if( data ==SL1_ON)
		{
			sm_Lin.state = S2_S2_S3;
		}
	}
	return sm_Lin.state;
}
static int fn_S2_S2_S3(unsigned char data, int e)
{
	if(e)
	{
		if(data == EL1_OFF || data == SC1_OFF || data == SL1_OFF) //SE FOR EVENTO HABILITADO
			return OK;
		else if(data> EC1_OFF && data<SL1_ON)// SE DENTRO DO ALFABETO
			return NOK; //NÃO HABILITADO

		return OUT; //SE FORA DO ALFABETO
	}
	else
	{

		if( data ==EL1_OFF)
		{
			sm_Lin.state = S2_S0_S2;
		}
		else if( data ==SC1_OFF)
		{
			sm_Lin.state = S1_S2_S1;
		}
		else if( data ==SL1_OFF)
		{
			sm_Lin.state = S2_S1_S2;
		}
		return sm_Lin.state;
	}
}
void initSM_Linha(Handle_lin_t handle)
{
	sm_Lin.Action[S0_S0_S0] = fn_S0_S0_S0;
	sm_Lin.Action[S0_S1_S0] = fn_S0_S1_S0;
	sm_Lin.Action[S0_S2_S1] = fn_S0_S2_S1;
	sm_Lin.Action[S1_S0_S0] = fn_S1_S0_S0;
	sm_Lin.Action[S1_S1_S0] = fn_S1_S1_S0;
	sm_Lin.Action[S1_S2_S1] = fn_S1_S2_S1;
	sm_Lin.Action[S2_S0_S2] = fn_S2_S0_S2;
	sm_Lin.Action[S2_S1_S2] = fn_S2_S1_S2;
	sm_Lin.Action[S2_S2_S3] = fn_S2_S2_S3;
	sm_Lin.state = S0_S0_S0;
}

int ExecSM_Linha(unsigned char data, int e)
{
	return sm_Lin.Action[sm_Lin.state](data, e);
}
