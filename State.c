/*
 * State.c
 *
 *  Created on: Nov 5, 2018
 *      Author: LuisFernando
 */

#include "State.h"

void (*fptr_State[3])() =
{
	show_menu,
	show_set_hour,
	show_set_date
};
