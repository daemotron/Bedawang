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

#ifndef __BEDAWANG_VERSION_H
#define __BEDAWANG_VERSION_H

/* Can be one of
	CURRENT
	STABLE
	RELEASE
	ALPHA
	BETA
	PRERELEASE
*/
#define BEDAWANG_VERSION_FLAVOUR "CURRENT"

#define BEDAWANG_VERSION_MAJOR 1
#define BEDAWANG_VERSION_MINOR 0
#define BEDAWANG_VERSION_PATCH 0
#define BEDAWANG_VERSION_SUFFX 0

/* The pattern for the numeric version follows this syntax:

       0xAABBCCDDEE

   AA is the major, BB the minor and CC the patch version,
   each of them always represented as two-digit hex number.

   DD represents the flavour and is set thus:
       CURRENT		00
       STABLE		22
       ALPHA		44
       BETA			66
       PRERELEASE	88
       RELEASE		FF

	EE is the suffix of the pre-release stages. It only applies
	to ALPHA, BETA and PRERELEASE. In all other cases, it has
	to be set to 00.
*/
#define BEDAWANG_VERSION_NUM 0x0100000000ULL

#endif /* __BEDAWANG_VERSION_H */
