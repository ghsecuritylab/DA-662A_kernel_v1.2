/*
 * $Id: group.h,v 1.2 2003/03/12 19:46:54 janakj Exp $
 *
 * Group membership checking over Radius
 *
 * Copyright (C) 2001-2003 Fhg Fokus
 *
 * This file is part of ser, a free SIP server.
 *
 * ser is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * For a license to use the ser software under conditions
 * other than those described here, or to purchase support for this
 * software, please contact iptel.org by e-mail at the following addresses:
 *    info@iptel.org
 *
 * ser is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program; if not, write to the Free Software 
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * History:
 * --------
 * 2003-03-10 - created by janakj
 *
 */

#ifndef GROUP_H
#define GROUP_H

#include "../../parser/msg_parser.h"

/*
 * Check from Radius if a user belongs to a group. User-Name is digest
 * username or digest username@realm, SIP-Group is group, and Service-Type
 * is Group-Check.  SIP-Group is SER specific attribute and Group-Check is
 * SER specific service type value.
 */
int radius_is_user_in(struct sip_msg* _msg, char* _hf, char* _group);


#endif /* GROUP_H */
