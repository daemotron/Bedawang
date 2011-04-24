/*-
 * Copyright (c) 2011 Daemotron <mail@daemotron.net>
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


#ifndef BEDAWANG_H_
#define BEDAWANG_H_


/**
 * Available protocol families
 */
typedef enum
{
    BWG_TCP,
    BWG_UDP
} bwg_socktype_t;


/**
 * Available SSL modes
 */
typedef enum
{
    BWG_SSL_NONE = 0,           /* no ssl */
    BWG_SSL_PERMA_NOAUTH,       /* permanent ssl (encryption initialized after connection has been established) without client authentification */
    BWG_SSL_PERMA_AUTH,         /* permanent ssl (encryption initialized after connection has been established) with client authentification */
    BWG_SSL_STARTTLS_NOAUTH,    /* ssl/tls connection upgrade on request without client authentification */
    BWG_SSL_STARTTLS_AUTH       /* ssl/tls connection upgrade on request with client authentification */
} bwg_ssl_t;


/**
 * The Bedawang Listener Object
 * 
 * A Bedawang Listener Object (BLO) describes all information required
 * to listen on a specific socket (such as port, address, inet family)
 */
typedef struct
{
    bwg_socktype_t type;        /* the socket type (TCP or UDP) */
    int socket;                 /* the socket file descriptor */
    char *node;                 /* the name of the node to bind to */
    char *port;                 /* the port to listen on */
    int backlog;                /* backlog setting for the connection */
    bwg_ssl_t ssl_mode;         /* the ssl mode for this listener */
    char *ssl_certfile;         /* the ssl certificate */
    char *ssl_keyfile;          /* the certificate's private key */
    char *ssl_cafile;           /* the certificate's CA certificate */
} bwg_listener_t;


/**
 * The Bedawang Server Object
 *
 * The Bedawang Server Object (BSO) is the core object containing all
 * information concerning the server's behaviour. These include (among 
 * others) network configuration, MPM capabilities, logging behaviour
 * and SSL/TLS configuration.
 */
typedef struct 
{
    char *user;                 /* the user as which to run the daemon process */
    char *group;                /* the group as which to run the daemon process */
    /* TODO: define structure */
} bwg_server_t;


#endif /*BEDAWANG_H_ */
