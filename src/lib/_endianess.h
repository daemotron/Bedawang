/*-
 * Copyright (c) 2010, 2011 Daemotron <mail@daemotron.net>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */


#ifndef _BWG_ENDIANESS_H_
#define _BWG_ENDIANESS_H_

#include <stdint.h>


typedef enum
{
    LITTLEENDIAN,
    BIGENDIAN
} _bwg_endianess_t;


uint16_t _bwg_hton16(uint16_t host16);
uint32_t _bwg_hton32(uint32_t host32);
uint64_t _bwg_hton64(uint64_t host64);
uint16_t _bwg_ntoh16(uint16_t net16);
uint32_t _bwg_ntoh32(uint32_t net32);
uint64_t _bwg_ntoh64(uint64_t net64);

#endif /* _BWG_ENDIANESS_H_ */
