/*
 * Copyright (C) 2001-2003 FhG Fokus
 *
 * This file is part of opensips, a free SIP server.
 *
 * opensips is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * opensips is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 */

/*!
 * \file
 * \brief Generic fixup functions for module function parameter.
 */

#ifndef _mod_fix_h_
#define _mod_fix_h_

#include <regex.h>
#include "mem/mem.h"
#include "pvar.h"

#define GPARAM_TYPE_INT		0
#define GPARAM_TYPE_STR		1
#define GPARAM_TYPE_PVS		2
#define GPARAM_TYPE_PVE		3
#define GPARAM_TYPE_REGEX	4
#define GPARAM_TYPE_FIXUP	5

typedef struct _gparam
{
	int type;
	union {
		int ival;
		str sval;
		pv_spec_t *pvs;
		pv_elem_t *pve;
		regex_t *re;
		void *val;
	} v;
} gparam_t, *gparam_p;


struct cmd_param;

int fix_cmd(struct cmd_param *params, action_elem_t *elems);
int get_cmd_fixups(struct sip_msg* msg, struct cmd_param *params,
				action_elem_t *elems, void **cmdp, pv_value_t *tmp_val);
int free_cmd_fixups(struct cmd_param *params, action_elem_t *elems, void **cmdp);

static inline int fixup_free_pkg(void **param)
{
	pkg_free(*param);
	return 0;
}

#endif
