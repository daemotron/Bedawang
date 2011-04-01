/**
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

extern uint64_t
buffer_free_bytes(buffer_t *buf)
{
	return (buf->size - buf->used);
}

extern uint64_t
buffer_read_append(int fd, buffer_t *buf)
{
	ssize_t rbytes;
	unsigned char *bf = (unsigned char *)buf->data;

	rbytes = read(fd, &bf[buf->used], (size_t)buffer_free_bytes(buf));
	buf->used += (uint64_t)rbytes;

	/* this works because the real size of buf->data is alway buf->size +1 */
	bf[buf->used] = '\0';
	return (uint64_t)rbytes;
}


extern uint64_t
buffer_read_insert(int fd, buffer_t *buf)
{
	ssize_t rbytes;
	char *bf = (char *)buf->data;

	memset(buf->data, '\0', buf->size + 1);
	buf->used = 0;

	rbytes = read(fd, buf->data, (size_t)buffer_free_bytes(buf));
	buf->used = (uint64_t)rbytes;

	/* this works because the real size of buf->data is alway buf->size +1 */
	bf[buf->used] = '\0';
	return (uint64_t)rbytes;
}


extern uint64_t
buffer_write_fd(int fd, const buffer_t *buf)
{
	ssize_t rbytes;

	rbytes = write(fd, buf->data, buf->used);
	return (uint64_t)rbytes;
}


extern uint64_t
buffer_insert(buffer_t *buffer, const char *string)
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


extern uint64_t
buffer_insert_0(buffer_t *buffer, const char *string)
{
	char *sptr = (char *)buffer->data;
	uint64_t rval = buffer_insert(buffer, string);
	if (buffer->used < buffer->size)
	{
		buffer->used += 1;
		sptr[buffer->used] = '\0';
	}
	return rval;
}


extern uint64_t
buffer_append(buffer_t *buffer, const char *string)
{
	char *sptr = (char *)buffer->data;
	uint64_t abytes;

	abytes = (strlen(string) < buffer_free_bytes(buffer) ? strlen(string) : buffer_free_bytes(buffer));
	strncpy(&sptr[buffer->used], string, abytes);
	buffer->used += abytes;
	sptr[buffer->used] = '\0';
	return abytes;
}


extern uint64_t
buffer_append_0(buffer_t *buffer, const char *string)
{
	char *sptr = (char *)buffer->data;
	uint64_t rval = buffer_append(buffer, string);
	if (buffer->used < buffer->size)
	{
		buffer->used += 1;
		sptr[buffer->used] = '\0';
	}
	return rval;
}


extern int
buffer_get_byte(buffer_t *buf, int64_t offset)
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
