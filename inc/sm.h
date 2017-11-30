/*
 * sm1.h
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

#ifndef SRC_SM_H_
#define SRC_SM_H_


#define EC1_OFF 		0	//CONTROLLABEL
#define EC1_ON 			1	//CONTROLLABEL
#define	EL1_OFF 		2	//CONTROLLABEL
#define EL1_ON			3	//CONTROLLABEL
#define SC1_OFF			4
#define SC1_ON			5
#define SL1_OFF			6
#define SL1_ON			7

#define ECdir_OFF 		8	//CONTROLLABEL
#define ECdir_ON 		9	//CONTROLLABEL
#define	ECesq_OFF 		10	//CONTROLLABEL
#define ECesq_ON		11	//CONTROLLABEL
#define SCdir_OFF		12
#define SCdir_ON		13
#define SCesq_OFF		14
#define SCesq_ON		15
#define SEx_ON			16
#define SEx_OFF			17


#define OUT			0
#define OK			1
#define NOK			-1



typedef void (*Handle_lin_t)(unsigned char *data);
typedef int (*Action_lin_t) (unsigned char data, int e);
int ExecSM_Linha( unsigned char data, int e);
void initSM_Linha(Handle_lin_t handle);


typedef void (*Handle_exp_t)(unsigned char *data);
typedef int (*Action_exp_t) (unsigned char data, int e);
int ExecSM_Expedicao( unsigned char data, int e);
void initSM_Expedicao(Handle_exp_t handle);


typedef void (*Handle_c_dir_t)(unsigned char *data);
typedef int (*Action_c_dir_t) (unsigned char data, int e);

int ExecSM_Conflito_Dir( unsigned char data, int e);
void initSM_Conflito_Dir(Handle_c_dir_t handle);

typedef void (*Handle_c_esq_t)(unsigned char *data);
typedef int (*Action_c_esq_t) (unsigned char data, int e);

int ExecSM_Conflito_Esq( unsigned char data, int e);
void initSM_Conflito_Esq(Handle_c_esq_t handle);




#endif /* SRC_SM_H_ */
