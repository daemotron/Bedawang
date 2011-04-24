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

#ifndef _BWG_BUFFER_H_
#define _BWG_BUFFER_H_

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef struct
{
    void *data;
    uint64_t size;
    uint64_t used;
    uint64_t limit;
} _bwg_buffer_t;

#define _BWG_BUFFER_init(__buf) { \
    (__buf)->data = NULL;         \
    (__buf)->size = 0;            \
    (__buf)->used = 0;            \
    (__buf)->limit = 0;           \
}

#define _BWG_BUFFER_set_limit(__buf, __limit) { \
    (__buf)->limit = (__limit);                 \
}

#define _BWG_BUFFER_grow(__buf, __size, __status) {                                                          \
    uint64_t __sz;                                                                                           \
    if ((__buf)->size < (__buf)->limit) {                                                                    \
        __sz = (((__buf)->limit - (__buf)->size) >= (__size) ? (__size) : ((__buf)->limit - (__buf)->size)); \
        (__buf)->data = realloc((__buf)->data, (__buf)->size + __sz + 1);                                    \
        if (NULL == (__buf)->data) {                                                                         \
            *(__status) = ENOMEM;                                                                            \
            (__buf)->size = 0;                                                                               \
        } else {                                                                                             \
            (__buf)->size += __sz;                                                                           \
            *(__status) = 0;                                                                                 \
        }                                                                                                    \
    } else {                                                                                                 \
        *(__status) = ERANGE;                                                                                \
    }                                                                                                        \
}


#define _BWG_BUFFER_copy(__src, __dest, __status) {               \
    _BWG_BUFFER_set_limit((__dest), (__src)->limit);              \
    _BWG_BUFFER_grow((__dest), (__src)->size, (__status));        \
    if (*(__status) == 0) {                                       \
        memcpy((__dest)->data, (__src)->data, (__src)->size + 1); \
        (__dest)->size = (__src)->size;                           \
        (__dest)->used = (__src)->used;                           \
    }                                                             \
}


#define _BWG_BUFFER_destroy(__buf) {       \
    if (NULL != (__buf)->data) {           \
        free((__buf)->data);               \
        (__buf)->data = NULL;              \
    }                                      \
    (__buf)->size = 0;                     \
    (__buf)->used = 0;                     \
    (__buf)->limit = 0;                    \
}


uint64_t _bwg_buffer_read_append(int fd, _bwg_buffer_t *buf);
uint64_t _bwg_buffer_read_insert(int fd, _bwg_buffer_t *buf);
uint64_t _bwg_buffer_write_fd(int fd, const _bwg_buffer_t *buf);
uint64_t _bwg_buffer_free_bytes(_bwg_buffer_t *buf);
int      _bwg_buffer_get_byte(_bwg_buffer_t *buf, int64_t offset);
uint64_t _bwg_buffer_insert(_bwg_buffer_t *buffer, const char *string);
uint64_t _bwg_buffer_insert_0(_bwg_buffer_t *buffer, const char *string);
uint64_t _bwg_buffer_append(_bwg_buffer_t *buffer, const char *string);
uint64_t _bwg_buffer_append_0(_bwg_buffer_t *buffer, const char *string);

#endif /* _BWG_BUFFER_H_ */
