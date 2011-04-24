/*-
 * Copyright (c) 2010 Daemotron <mail@daemotron.net>
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


#include <fcntl.h>
#include <inttypes.h>
#include <unistd.h>
#include <string.h>

#include "_buffer.h"


/**
 * @brief calculate free buffer size
 */
uint64_t
_bwg_buffer_free_bytes(_bwg_buffer_t *buf)
{
    return (buf->size - buf->used);
}


/**
 * @brief read from file pointer and append read bytes to buffer
 */
uint64_t
_bwg_buffer_read_append(int fd, _bwg_buffer_t *buf)
{
    ssize_t rbytes;
    unsigned char *bf = (unsigned char *)buf->data;

    rbytes = read(fd, &bf[buf->used], (size_t)_bwg_buffer_free_bytes(buf));
    buf->used += (uint64_t)rbytes;

    /* this works because the real size of buf->data is alway buf->size +1 */
    bf[buf->used] = '\0';
    return (uint64_t)rbytes;
}


/**
 * @brief read from file pointer and insert read bytes at beginning of buffer
 */
uint64_t
_bwg_buffer_read_insert(int fd, _bwg_buffer_t *buf)
{
    ssize_t rbytes;
    char *bf = (char *)buf->data;

    memset(buf->data, '\0', buf->size + 1);
    buf->used = 0;

    rbytes = read(fd, buf->data, (size_t)_bwg_buffer_free_bytes(buf));
    buf->used = (uint64_t)rbytes;

    /* this works because the real size of buf->data is alway buf->size +1 */
    bf[buf->used] = '\0';
    return (uint64_t)rbytes;
}


/**
 * @brief write entire buffer content to a file pointer
 */
uint64_t
_bwg_buffer_write_fd(int fd, const _bwg_buffer_t *buf)
{
    ssize_t rbytes;

    rbytes = write(fd, buf->data, buf->used);
    return (uint64_t)rbytes;
}


/**
 * @brief insert string at beginning of buffer without incorporating a terminator symbol in the buffer content
 */
uint64_t
_bwg_buffer_insert(_bwg_buffer_t *buffer, const char *string)
{
    char *sptr = (char *)buffer->data;
    uint64_t abytes;

    memset(buffer->data, '\0', buffer->size + 1);
    buffer->used = 0;

    abytes = (strlen(string) < buffer->size) ? strlen(string) : buffer->size;
    strncpy(sptr, string, abytes);
    buffer->used = abytes;
    sptr[buffer->used] = '\0';
    return abytes;
}


/**
 * @brief insert string at beginning of buffer and append a terminator symbol within the buffer content range
 */
uint64_t
_bwg_buffer_insert_0(_bwg_buffer_t *buffer, const char *string)
{
    char *sptr = (char *)buffer->data;
    uint64_t rval = _bwg_buffer_insert(buffer, string);
    if (buffer->used < buffer->size)
    {
        buffer->used += 1;
        sptr[buffer->used] = '\0';
    }
    return rval;
}


/**
 * @brief append string to buffer content without incorporating a terminator symbol in the buffer content
 */
uint64_t
_bwg_buffer_append(_bwg_buffer_t *buffer, const char *string)
{
    char *sptr = (char *)buffer->data;
    uint64_t abytes;

    abytes = (strlen(string) < _bwg_buffer_free_bytes(buffer) ? strlen(string) : _bwg_buffer_free_bytes(buffer));
    strncpy(&sptr[buffer->used], string, abytes);
    buffer->used += abytes;
    sptr[buffer->used] = '\0';
    return abytes;
}


/**
 * @brief append string to buffer content and append a terminator symbol within the buffer content range
 */
uint64_t
_bwg_buffer_append_0(_bwg_buffer_t *buffer, const char *string)
{
    char *sptr = (char *)buffer->data;
    uint64_t rval = _bwg_buffer_append(buffer, string);
    if (buffer->used < buffer->size)
    {
        buffer->used += 1;
        sptr[buffer->used] = '\0';
    }
    return rval;
}


/**
 * @brief get a specific byte from the buffer's content
 * @return int
 */
int
_bwg_buffer_get_byte(_bwg_buffer_t *buf, int64_t offset)
{
    int64_t ofs;
    unsigned char *bf = (unsigned char *)buf->data;

    if (offset < 0)
        ofs = (int64_t)buf->used + offset;
    else
        ofs = offset;

    if (ofs >= buf->used)
        return 0;

    return (int)bf[ofs];
}
