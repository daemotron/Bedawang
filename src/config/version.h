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

#ifndef __BEDAWANG_VERSION_H
#define __BEDAWANG_VERSION_H

#include <stdint.h>

/*
 * Do not change these definitions!
 */

#define BWG_CURRENT     0x00
#define BWG_STABLE      0x22
#define BWG_ALPHA       0x44
#define BWG_BETA        0x66
#define BWG_PRERELEASE  0x88
#define BWG_RELEASE     0xFF

/*
 * Configure release information here 
 */

#define BWG_VERSION_MAJOR          1
#define BWG_VERSION_MINOR          0
#define BWG_VERSION_PATCH          0
#define BWG_VERSION_FLAVOUR        BWG_CURRENT
#define BWG_VERSION_SUFFX          0

/* 
 * The pattern for the numeric version follows this syntax:
 *
 *   0xAABBCCDDEE
 *
 * AA is the major, BB the minor and CC the patch version.
 * DD represents the flavour and EE the suffix (only applicable
 * to ALPHA, BETA and PRERELEASE flavours; otherwise it will
 * be ignored and should be set to 0).
 * Each of them always represented as two-digit hex number.
 */
#define BWG_VERSION_NUM \
      (((uint64_t) BWG_VERSION_MAJOR)   << 32) \
    | (((uint64_t) BWG_VERSION_MINOR)   << 24) \
    | (((uint64_t) BWG_VERSION_PATCH)   << 16) \
    | (((uint64_t) BWG_VERSION_FLAVOUR) << 8) \
    | ((uint64_t)  BWG_VERSION_SUFFX)

#endif /* __BEDAWANG_VERSION_H */
