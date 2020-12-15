/****************************************************************************
 *
 * Copyright (C) 2014-2020 Cisco and/or its affiliates. All rights reserved.
 * Copyright (C) 2003-2013 Sourcefire, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License Version 2 as
 * published by the Free Software Foundation.  You may not use, modify or
 * distribute this program under any other version of the GNU General
 * Public License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 ****************************************************************************/

/**
**  @file       smtp_buffer_dump.c
**
**  @author     Vishnu Sriram <visriram@cisco.com>
**
**  @brief      This file contains structures and functions for
**              dumping buffers used during SMTP inspection.
*/


#include "smtp_buffer_dump.h"

#ifdef DUMP_BUFFER

TraceBuffer buf[MAX_SMTP_BUFFER_DUMP] = {{"STATE_COMMAND_DUMP", "", 0},
                                         {"STATE_DATA_DUMP", "", 0},
                                         {"STATE_BDATA_DUMP", "", 0},
                                         {"STATE_XEXCH50_DUMP", "", 0},
                                         {"STATE_AUTH_DUMP", "", 0},
                                         {"STATE_UNKNOWN_DUMP", "", 0},
                                         {"STATE_RESP_DUMP", "", 0}};

void dumpBuffer(SMTP_BUFFER_DUMP type, const uint8_t *content, uint16_t len){
    buf[type].buf_content = (char *)content;
    buf[type].length = len;
}

void dumpBufferInit(void) {
    unsigned int i;
    for (i = 0; i < MAX_SMTP_BUFFER_DUMP; i++) {
        buf[i].buf_content = (char *)"";
        buf[i].length = 0;
    }
}

TraceBuffer *getSMTPBuffers()
{
    return buf;
}

#endif
